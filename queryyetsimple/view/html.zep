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
use Queryyetsimple\View\Connect;
use Queryyetsimple\View\IConnect;

/**
 * html 模板处理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2016.11.18
 * @version 1.0
 */
class Html extends Connect implements IConnect
{

	/**
	 * 视图分析器
	 *
	 * @var \Queryyetsimple\View\IParserr
	 */
	protected parser;

	/**
	 * 解析 parser
	 *
	 * @var callable
	 */
	protected parserResolver;

	/**
	 * 配置
	 *
	 * @var array
	 */
	protected option = [
		"development" : false,
		"controller_name" : "index",
		"action_name" : "index",
		"controlleraction_depr" : "_",
		"theme_name" : "default",
		"theme_path" : "",
		"theme_path_default" : "",
		"suffix" : ".html",
		"theme_cache_path" : "",
		"cache_children" : false,
		"cache_lifetime" : 2592000
	];

	/**
	 * 加载视图文件
	 *
	 * @param string $file 视图文件地址
	 * @param array $vars
	 * @param string $ext 后缀
	 * @param boolean $display 是否显示
	 * @return string
	 */
	public function display(string file, array! vars = [], string ext = "", boolean display = true)
	{
		var cachepath, result, key, value;

		// 加载视图文件
		let file = this->parseDisplayFile(file, ext);

		// 变量赋值
		if typeof vars == "array" {
            this->setVar(vars);
        }

		if ! empty this->vars {
			for key, value in this->vars {
				let {key} = value;
			}
		}

		let cachepath = this->getCachePath(file); // 编译文件路径

		if this->isCacheExpired(file, cachepath) { // 重新编译
			this->parser()->doCombile(file, cachepath);
		}

		// 返回类型
		if display === false {
			ob_start();
			require cachepath;
			let result = ob_get_contents();
			ob_end_clean();

			return result;
		} else {
			require cachepath;
		}
	}

	/**
	 * 设置 parser 解析回调
	 *
	 * @param callable $parserResolver
	 * @return void
	 */
	public function setParseResolver(parserResolver)
	{
		let this->parserResolver = parserResolver;
	}

	/**
	 * 解析 parser
	 *
	 * @return \Queryyetsimple\View\IParserr
	 */
	public function resolverParser()
	{
		if ! this->parserResolver {
			throw new RuntimeException("Html theme not set parser resolver");
		}
		return call_user_func(this->parserResolver);
	}

	/**
	 * 获取分析器
	 *
	 * @return \Queryyetsimple\View\IParserr
	 */
	public function parser()
	{
		if typeof this->parser != "null" {
			return this->parser;
		}

		let this->parser = this->resolverParser();
		return this->parser;
	}

	/**
	 * 获取编译路径
	 *
	 * @param string $file
	 * @return string
	 */
	protected function getCachePath(string file)
	{
		if ! this->getOption("theme_cache_path") {
			throw new RuntimeException("Theme cache path must be set");
		}

		// 统一斜线
		let file = str_replace("//", "/", str_replace("\\", "/", file));

		// 统一缓存文件
		let file = basename(file, "." . pathinfo(file, PATHINFO_EXTENSION)) . "." . md5(file) . ".php";

		// 返回真实路径
		return this->getOption("theme_cache_path") . "/" . file;
	}

	/**
	 * 判断缓存是否过期
	 *
	 * @param string $file
	 * @param string $cachepath
	 * @return boolean
	 */
	protected function isCacheExpired(string file, string cachepath)
	{
		// 开启调试
		if this->getOption("app_development") {
			return true;
		}

		// 缓存文件不存在过期
		if ! is_file(cachepath) {
			return true;
		}

		// 编译过期时间为 <= 0 表示永不过期
		if this->getOption("cache_lifetime") <= 0 {
			return false;
		}

		// 缓存时间到期
		if filemtime(cachepath) + intval(this->getOption("cache_lifetime")) < time() {
			return true;
		}

		// 文件有更新
		if filemtime(file) >= filemtime(cachepath) {
			return true;
		}

		return false;
	}
}
