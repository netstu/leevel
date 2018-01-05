/*
 * This file is part of the ************************ package.
 * ##########################################################
 * #   ____                          ______  _   _ ______   #
 * #  /     \       ___  _ __  _   _ | ___ \| | | || ___ \  #
 * # |   (  ||(_)| / _ \| '__|| | | || |_/ /| |_| || |_/ /  #
 * #  \____/ |___||  __/| |   | |_| ||  __/ |  _  ||  __/   #
 * #       \__   | \___ |_|    \__  || |    | | | || |      #
 * #     Query Yet Simple      __/  |\_|    |_| |_|\_|      #
 * #                          |___ /  Since 2010.10.03      #
 * ##########################################################
 *
 * The PHP Framework For Code Poem As Free As Wind. <Query Yet Simple>
 * (c) 2010-2018 http://queryphp.com All rights reserved.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
namespace Queryyetsimple\View;

use RuntimeException;
use InvalidArgumentException;
use Queryyetsimple\View\Itheme;

/**
 * 模板处理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.02
 * @version 1.0
 */
class Theme implements Itheme
{

	/**
	 * 视图分析器
	 *
	 * @var \queryyetsimple\view\iparser
	 */
	protected objParse;

	/**
	 * 解析 parse
	 *
	 * @var callable
	 */
	protected static calParseResolver;

	/**
	 * 变量值
	 *
	 * @var array
	 */
	protected arrVar = [];

	/**
	 * 配置
	 *
	 * @var array
	 */
	protected arrOption = [
		"app_development" : false,
		"controller_name" : "index",
		"action_name" : "index",
		"controlleraction_depr" : "_",
		"theme_name" : "default",
		"theme_path" : "",
		"theme_path_default" : "",
		"suffix" : ".html",
		"theme_cache_path" : "",
		"cache_children" : false
	];

	/**
	 * 构造函数
	 *
	 * @param array arrOption
	 * @return void
	 */
	public function __construct(array arrOption = [])
	{
		this->options(arrOption);
	}

	/**
	 * 设置 parse 解析回调
	 *
	 * @param callable $calParseResolver
	 * @return void
	 */
	public static function setParseResolver(calParseResolver)
	{
		let self::calParseResolver = calParseResolver;
	}

	/**
	 * 解析 parse
	 *
	 * @return \queryyetsimple\view\iparser
	 */
	public function resolverParse()
	{
		if ! self::calParseResolver {
			throw new RuntimeException("Theme not set parse resolver");
		}
		return call_user_func(self::calParseResolver);
	}

	/**
	 * 获取分析器
	 *
	 * @return \queryyetsimple\view\iparser
	 */
	public function parser()
	{
		if typeof this->objParse != "null" {
			return this->objParse;
		}

		let this->objParse = this->resolverParse();
		return this->objParse;
	}

	/**
	 * 加载视图文件
	 *
	 * @param string $sFile 视图文件地址
	 * @param boolean $bDisplay 是否显示
	 * @param string $strExt 后缀
	 * @param string $sTargetCache 主模板缓存路径
	 * @param string $sMd5 源文件地址 md5 标记
	 * @return string
	 */
	public function display(string sFile, boolean bDisplay = true, string strExt = "", string sTargetCache = "", string sMd5 = "")
	{
		var sCachePath, sTargetContent, sChildCache, sReturn, strVarKey, mixVarValue;

		// 加载视图文件
		let sFile = this->parseDisplayFile(sFile, strExt);

		// 变量赋值
		if ! empty this->arrVar {
			for strVarKey, mixVarValue in this->arrVar {
				let {strVarKey} = mixVarValue;
			}
		}

		let sCachePath = this->getCachePath(sFile); // 编译文件路径
		if this->isCacheExpired(sFile, sCachePath) { // 重新编译
			this->parser()->doCombile(sFile, sCachePath);
		}

		// 逐步将子模板缓存写入父模板至到最后
		if sTargetCache {
			if is_file(sFile) && is_file(sTargetCache) {
				// 源码
				let sTargetContent = file_get_contents(sTargetCache);
				let sChildCache = file_get_contents(sCachePath);

				// 替换
				let sTargetContent = preg_replace("/<!--<\#\#\#\#incl\*" . sMd5 . "\*ude\#\#\#\#>-->(.*?)<!--<\/\#\#\#\#incl\*" . sMd5 . "\*ude\#\#\#\#\/>-->/s", substr(sChildCache, strpos(sChildCache, PHP_EOL)), sTargetContent);
				file_put_contents(sTargetCache, sTargetContent);
			} else {
				throw new InvalidArgumentException(sprintf("Source %s and target cache %s is not a valid path", sFile, sTargetCache));
			}
		}

		// 返回类型
		if bDisplay === false {
			ob_start();
			require sCachePath;
			let sReturn = ob_get_contents();
			ob_end_clean();
			this->fixIe(sReturn);
			return sReturn;
		} else {
			require sCachePath;
		}
	}

	/**
	 * 设置模板变量
	 *
	 * @param mixed $mixName
	 * @param mixed $mixValue
	 * @return void
	 */
	public function setVar(var mixName, var mixValue = null)
	{
		if is_array(mixName) {
			let this->arrVar = array_merge(this->arrVar, mixName);
		} else {
			let this->arrVar[mixName] = mixValue;
		}
	}

	/**
	 * 获取变量值
	 *
	 * @param string|null $sName
	 * @return mixed
	 */
	public function getVar(string sName = null)
	{
		if typeof sName == "null" {
			return this->arrVar;
		}
		return isset(this->arrVar[sName]) ? this->arrVar[sName] : null;
	}

	/**
	 * 删除变量值
	 *
	 * @param mixed $mixName
	 * @return $this
	 */
	public function deleteVar(var mixName)
	{
		var strName;

		let mixName = is_array(mixName) ? mixName : func_get_args();

		for strName in mixName {
			if isset this->arrVar[strName] {
				unset(this->arrVar[strName]);
			}
		}

		return this;
	}

	/**
	 * 清空变量值
	 *
	 * @param string|null $sName
	 * @return $this
	 */
	public function clearVar()
	{
		let this->arrVar = [];
		return this;
	}

	/**
	 * 获取编译路径
	 *
	 * @param string $sFile
	 * @return string
	 */
	public function getCachePath(string sFile)
	{
		if ! this->getOption("theme_cache_path") {
			throw new RuntimeException("Theme cache path must be set");
		}

		// 统一斜线
		let sFile = str_replace("//", "/", str_replace("\\", "/", sFile));

		// 统一缓存文件
		let sFile = basename(sFile, "." . pathinfo(sFile, PATHINFO_EXTENSION)) . "." . md5(sFile) . ".php";

		// 返回真实路径
		return this->getOption("theme_cache_path") . "/" . sFile;
	}

	/**
     * 修改单个配置
     *
     * @param string $strName
     * @param mixed $mixValue
     * @return $this
     */
    public function option(string strName, var mixValue)
    {
        if ! is_string(strName) {
            throw new InvalidArgumentException("Option set name must be a string.");
        }
        let this->arrOption[strName] = mixValue;
        return this;
    }

    /**
     * 修改数组配置
     *
     * @param string $strName
     * @param array $arrValue
     * @return $this
     */
    public function optionArray(string $strName, array $arrValue)
    {
        return this->option(strName, array_merge(this->getOption(strName), arrValue));
    }

    /**
     * 修改多个配置
     *
     * @param string $strName
     * @param mixed $mixValue
     * @return $this
     */
    public function options(array $arrOption = [])
    {
    	var strName, mixValue;

        if empty arrOption {
            return this;
        }

        for strName, mixValue in arrOption {
        	this->option(strName, mixValue);
        }

        return this;
    }

    /**
     * 获取单个配置
     *
     * @param string $strName
     * @param mixed $mixDefault
     * @return mixed
     */
    public function getOption(string strName, var mixDefault = null)
    {
        return isset(this->arrOption[strName]) ? this->arrOption[strName] : mixDefault;
    }

    /**
     * 获取所有配置
     *
     * @param array $arrOption
     * @return mixed
     */
    public function getOptions(array arrOption = [])
    {
    	if ! empty arrOption {
    		return array_merge(this->arrOption, arrOption);
    	} else {
    		return this->arrOption;
    	}
    }

    /**
     * 删除单个配置
     *
     * @param string $strName
     * @return $this
     */
    public function deleteOption(string strName)
    {
        if isset this->arrOption[strName] {
            unset(this->arrOption[strName]);
        }

        return this;
    }

    /**
     * 删除多个配置
     *
     * @param array $arrOption
     * @return $this
     */
    public function deleteOptions(array arrOption = [])
    {
    	var strOption;

        if ! empty arrOption {
            return this;
        }

        for strOption in arrOption {
        	this->deleteOption(strOption);
        }

        return this;
    }

	/**
	 * 分析展示的视图文件
	 *
	 * @param string $sFile 视图文件地址
	 * @param string $strExt 后缀
	 * @return string|void
	 */
	protected function parseDisplayFile(string sFile, string strExt = "")
	{
		// 加载视图文件
		if ! is_file(sFile) {
			let sFile = this->parseFile(sFile, strExt);
		}

		// 分析默认视图文件
		if ! is_file(sFile) {
			let sFile = this->parseDefaultFile(sFile);
		}

		if ! is_file(sFile) {
			throw new InvalidArgumentException(sprintf("Template file %s does not exist.", sFile));
		}

		return sFile;
	}

	/**
	 * 分析模板真实路径			
	 *
	 * @param string $sTpl 文件地址
	 * @param string $sExt 扩展名
	 * @return string
	 */
	protected function parseFile(string sTpl, string sExt = "")
	{
		var arrArray, sTheme, sTempTheme, sTempTpl, sReturnFile = "";

		let sTpl = trim(str_replace("->", ".", sTpl));

		// 完整路径或者变量
		if pathinfo(sTpl, PATHINFO_EXTENSION) || strpos(sTpl, "$") === 0 {
			return this->formatFile(sTpl);
		} elseif strpos(sTpl, "(") !== false { // 存在表达式
			return this->formatFile(sTpl);
		} else {
			if ! this->getOption("theme_path") {
				throw new RuntimeException("Theme path must be set");
			}

			// 空取默认控制器和方法
			if sTpl == "" {
				let sTpl = this->getOption("controller_name") . this->getOption("controlleraction_depr") . this->getOption("action_name");
			}

			if strpos(sTpl, "@") !== false { // 分析主题
				let arrArray = explode("@", sTpl);
				let sTempTheme = array_shift(arrArray);
				let sTheme = sTempTheme;
				let sTempTpl = array_shift(arrArray);
				let sTpl = sTempTpl; 
			}

			let sTpl = str_replace([
				"+",
				":"
			], this->getOption("controlleraction_depr"), sTpl);

			let sReturnFile = dirname(this->getOption("theme_path")) . "/";
			if sTheme {
				let sReturnFile .= sTheme . "/";
			} else {
				let sReturnFile .= this->getOption("theme_name") . "/";
			}

			let sReturnFile .= sTpl;

			if ! empty sExt {
				let sReturnFile .= sExt;
			} else {
				let sReturnFile .= this->getOption("suffix");
			}

			return sReturnFile;
		}
	}

	/**
	 * 格式化文件名
	 *
	 * @param string $sContent
	 * @return string
	 */
	protected function formatFile(string sContent)
	{
		return str_replace([
			":",
			"+"
		], [
			"->",
			"::"
		], sContent);
	}

	/**
	 * 匹配默认地址（文件不存在）
	 *
	 * @param string $sTpl 文件地址
	 * @return string
	 */
	protected function parseDefaultFile(string sTpl)
	{
		var sBakTpl, sTempTpl;

		if is_file(sTpl) {
			return sTpl;
		}

		if ! $this->getOption("theme_path") {
			throw new RuntimeException("Theme path must be set");
		}

		let sBakTpl = sTpl;

		// 物理路径
		if strpos(sTpl, ":") !== false || strpos(sTpl, "/") === 0 || strpos(sTpl, "\\") === 0 {
			let sTpl = str_replace(str_replace("\\", "/", this->getOption("theme_path") . "/"), "", str_replace("\\", "/", sTpl));
		}

		// 备用地址
		let sTempTpl = this->getOption("theme_path_default") . "/" . sTpl;
		if this->getOption("theme_path_default") && is_file(sTempTpl) {
			return sTempTpl;
		}

		// default 主题
		let sTempTpl = dirname(this->getOption("theme_path")) . "/default/" . sTpl;
		if this->getOption("theme_name") != "default" && is_file(sTempTpl) {
			return sTempTpl;
		}

		return sBakTpl;
	}

	/**
	 * 判断缓存是否过期
	 *
	 * @param string $sFile
	 * @param string $sCachePath
	 * @return boolean
	 */
	protected function isCacheExpired(string sFile, string sCachePath)
	{
		// 开启调试
		if this->getOption("app_development") {
			return true;
		}

		// 缓存文件不存在过期
		if ! is_file(sCachePath) {
			return true;
		}

		// 编译过期时间为 <= 0 表示永不过期
		if this->getOption("cache_lifetime") <= 0 {
			return false;
		}

		// 缓存时间到期
		if filemtime(sCachePath) + intval(this->getOption("cache_lifetime")) < time() {
			return true;
		}

		// 文件有更新
		if filemtime(sFile) >= filemtime(sCachePath) {
			return true;
		}

		return false;
	}

	/**
	 * 修复 ie 显示问题
	 * 过滤编译文件子模板定位注释标签，防止在网页头部出现注释，导致 IE 浏览器不居中
	 *
	 * @param string $sContent
	 * @return string
	 */
	protected function fixIe(string sContent)
	{
		if this->getOption("cache_children") === true {
			let sContent = preg_replace("/<!--<\#\#\#\#incl\*(.*?)\*ude\#\#\#\#>-->/", "", sContent);
			let sContent = preg_replace("/<!--<\/\#\#\#\#incl\*(.*?)\*ude\#\#\#\#\/>-->/", "", sContent);
		}
		return sContent;
	}
}
