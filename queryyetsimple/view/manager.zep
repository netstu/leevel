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

use Closure;
use Queryyetsimple\View\View;
use Queryyetsimple\View\Html;
use Queryyetsimple\View\Twig;
use Queryyetsimple\View\Phpui;
use Queryyetsimple\View\V8 as V8s;
use Queryyetsimple\Support\Manager as SupportManager;

/**
 * view 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.12
 * @version 1.0
 */
class Manager extends SupportManager
{

    /**
     * 取得配置命名空间
     *
     * @return string
     */
	protected function getOptionNamespace()
	{
		return "view";
	}

    /**
     * 创建连接对象
     *
     * @param object $connect
     * @return object
     */
	protected function createConnect(var connect)
	{
		return new View(connect);
	}

    /**
     * 创建 html 模板驱动
     *
     * @param array $options
     * @return \Queryyetsimple\View\Html
     */
	protected function makeConnectHtml(array options = [])
	{
		var parser, html;

		let options = this->getOption("html", options);
		let options = array_merge(options, this->viewOptionCommon());

		let parser = Closure::fromCallable([this, "makeParserClosure"]);

		let html = new Html(options);
		html->setParseResolver(parser);

		return html;
	}

	/**
     * 创建 twig 模板驱动
     *
     * @param array $options
     * @return \Queryyetsimple\View\Twig
     */
	protected function makeConnectTwig(array options = [])
	{
		var parser, twig;

		let options = this->getOption("twig", options);
		let options = array_merge(options, this->viewOptionCommon());

		let parser = Closure::fromCallable([this, "makeTwigParserClosure"]);

		let twig = new Twig(options);
		twig->setParseResolver(parser);

		return twig;
	}

    /**
     * 创建 phpui 模板驱动
     *
     * @param array $options
     * @return \Queryyetsimple\View\Phpui
     */
	protected function makeConnectPhpui(array options = [])
	{
		let options = this->getOption("phpui", options);
		let options = array_merge(options, this->viewOptionCommon());

		return new Phpui(options);
	}

    /**
     * 创建 v8 模板驱动
     *
     * @param array $options
     * @return \Queryyetsimple\View\Vue
     */
	protected function makeConnectV8(array options = [])
	{
		let options = this->getOption("v8", options);
		let options = array_merge(options, this->viewOptionCommon());
		return new V8s(options);
	}

    /**
     * 视图公共配置
     *
     * @return array
     */
	protected function viewOptionCommon()
	{
		var options;

		let options =  [
			"development" : this->container->development(),
			"controller_name" : this->container->make("controller_name"),
			"action_name" : this->container->make("action_name"),
			"theme_path" : this->container->pathApplicationDir("theme") . "/" . this->container->make("option")->get("view\\theme_name"),

			// 仅 html 模板需要缓存路径
			"theme_cache_path" : this->container->pathApplicationCache("theme") . "/" . this->container->make("app_name")
		];

		return options;
	}

	/**
	 * 创建分析器回调
	 *
	 * @since 2018.01.12
	 * @return void
	 */
	protected function makeParserClosure() {
		return this->container->make("view.parser");
	}

	/**
	 * 创建 twig 分析器回调
	 *
	 * @since 2018.01.15
	 * @return void
	 */
	protected function makeTwigParserClosure() {
		return this->container->make("view.twig.parser");
	}
}
