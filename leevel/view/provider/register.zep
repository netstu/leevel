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
namespace Leevel\View\Provider;

use Leevel\Di\Provider;
use Leevel\Di\IContainer;

/**
 * view 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.05.12
 * @version 1.0
 */
class Register extends Provider
{

    /**
     * 创建一个服务容器提供者实例
     *
     * @param \Leevel\Di\IContainer $container
     * @return void
     */
    public function __construct(<IContainer> container)
    {
        parent::__construct(container);
    }

    /**
     * 注册服务
     *
     * @return void
     */
    public function register()
    {
        this->viewViews();
        this->viewView();
        this->viewCompiler();
        this->viewParser();
        this->viewTwigParser();
    }
    
    /**
     * 可用服务提供者
     *
     * @return array
     */
    public static function providers() -> array
    {
        var tmp;
    
        let tmp = [
            "view.views" : [
                "Leevel\\View\\Manager"
            ], 
            "view.view" : [
                "Leevel\\View\\View", 
                "Leevel\\View\\IView"
            ], 
            "view.compiler" : [
                "Leevel\\View\\Compiler", 
                "Leevel\\View\\ICompiler"
            ], 
            "view.parser" : [
                "Leevel\\View\\Parser", 
                "Leevel\\View\\IParser"
            ], 
            "view.twig.parser"
        ];
        return tmp;
    }
    
    /**
     * 注册 view.views 服务
     *
     * @return void
     */
    protected function viewViews()
    {
        this->container->singleton("view.views", function (project) {
            return new \Leevel\View\Manager(project);
        });
    }
    
    /**
     * 注册 view.view 服务
     *
     * @return void
     */
    protected function viewView()
    {
        this->container->singleton("view.view", function (project) {
            return project->make("view.views")->connect();
        });
    }
    
    /**
     * 注册 view.compiler 服务
     *
     * @return void
     */
    protected function viewCompiler()
    {
        this->container->singleton("view.compiler", function (project) {
            return new \Leevel\View\Compiler();
        });
    }
    
    /**
     * 注册 view.parser 服务
     *
     * @return void
     */
    protected function viewParser()
    {
        this->container->singleton("view.parser", function (project) {
            var parser;

            let parser = new \Leevel\View\Parser(project->make("view.compiler"));
            return parser->registerCompilers()->registerParsers();
        });
    }
    
    /**
     * 注册 view.twig.parser 服务
     *
     * @return void
     */
    protected function viewTwigParser()
    {
        this->container->singleton("view.twig.parser", function (project) {
            var tmp;
        
            let tmp = [
                "auto_reload" : true, 
                "debug" : project->development(), 
                "cache" : project->pathApplicationCache("theme") . "/" . project->make("request")->app()
            ];
            return new \Twig_Environment(new \Twig_Loader_Filesystem(), tmp);
        });
    }
}
