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

/**
 * 模板处理抽象类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.02
 * @version 1.0
 */
abstract class Aconnect
{

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
	protected option = [];

	/**
	 * 构造函数
	 *
	 * @param array option
	 * @return void
	 */
	public function __construct(array option = [])
	{
		this->options(option);
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
     * 修改单个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function option(string name, var value)
    {
        if ! is_string(name) {
            throw new InvalidArgumentException("Option set name must be a string.");
        }
        let this->option[name] = value;
        return this;
    }

    /**
     * 修改数组配置
     *
     * @param string $name
     * @param array $value
     * @return $this
     */
    public function optionArray(string name, array value)
    {
        return this->option(name, array_merge(this->getOption(name), value));
    }

    /**
     * 修改多个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function options(array option = [])
    {
    	var name, value;

        if empty option {
            return this;
        }

        for name, value in option {
        	this->option(name, value);
        }

        return this;
    }

    /**
     * 获取单个配置
     *
     * @param string $name
     * @param mixed $defaults
     * @return mixed
     */
    public function getOption(string name, var defaults = null)
    {
        return isset(this->option[name]) ? this->option[name] : defaults;
    }

    /**
     * 获取所有配置
     *
     * @param array $option
     * @return mixed
     */
    public function getOptions(array option = [])
    {
    	if ! empty option {
    		return array_merge(this->option, option);
    	} else {
    		return this->option;
    	}
    }

    /**
     * 删除单个配置
     *
     * @param string $name
     * @return $this
     */
    public function deleteOption(string name)
    {
        if isset this->option[name] {
            unset(this->option[name]);
        }

        return this;
    }

    /**
     * 删除多个配置
     *
     * @param array $option
     * @return $this
     */
    public function deleteOptions(array option = [])
    {
    	var key;

        if ! empty option {
            return this;
        }

        for key in option {
        	this->deleteOption(key);
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
}
