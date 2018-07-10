/*
 * This file is part of the ************************ package.
 * _____________                           _______________
 *  ______/     \__  _____  ____  ______  / /_  _________
 *   ____/ __   / / / / _ \/ __`\/ / __ \/ __ \/ __ \___
 *    __/ / /  / /_/ /  __/ /  \  / /_/ / / / / /_/ /__
 *      \_\ \_/\____/\___/_/   / / .___/_/ /_/ .___/
 *         \_\                /_/_/         /_/
 *
 * The PHP Framework For Code Poem As Free As Wind. <Query Yet Simple>
 * (c) 2010-2018 http://queryphp.com All rights reserved.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
namespace Leevel\View;

use Closure;
use Leevel\View\View;
use Leevel\View\Html;
use Leevel\View\Twig;
use Leevel\View\Phpui;
use Leevel\View\V8 as V8s;
use Leevel\Manager\Manager as Managers;

/**
 * view 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.12
 * @version 1.0
 */
class Manager extends Managers
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
     * @return \Leevel\View\Html
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
     * @return \Leevel\View\Twig
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
     * @return \Leevel\View\Phpui
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
     * @return \Leevel\View\Vue
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
        var options, request;

        let request = this->container->make("request");

        let options =  [
            "development" : this->container->development(),
            "controller_name" : request->controller(),
            "action_name" : request->action(),
            "theme_path" : this->container->pathApplicationTheme(),

            // 仅 html 模板需要缓存路径
            "theme_cache_path" : this->container->pathApplicationCache("theme") . "/" . strtolower(request->app())
        ];

        return options;
    }

    /**
     * 创建分析器回调
     *
     * @since 2018.01.12
     * @return void
     */
    protected function makeParserClosure()
    {
        return this->container->make("view.parser");
    }

    /**
     * 创建 twig 分析器回调
     *
     * @since 2018.01.15
     * @return void
     */
    protected function makeTwigParserClosure()
    {
        return this->container->make("view.twig.parser");
    }
}
