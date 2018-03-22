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
namespace Queryyetsimple\View\Provider;

use Queryyetsimple\Di\Provider;
use Queryyetsimple\Di\IContainer;

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
     * @param \Queryyetsimple\Di\IContainer $container
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
                "Queryyetsimple\\View\\Manager", 
                "Qys\\View\\Manager"
            ], 
            "view.view" : [
                "Queryyetsimple\\View\\View", 
                "Queryyetsimple\\View\\IView", 
                "Qys\\View\\View", 
                "Qys\\View\\IView"
            ], 
            "view.compiler" : [
                "Queryyetsimple\\View\\Compiler", 
                "Queryyetsimple\\View\\ICompiler", 
                "Qys\\View\\Compiler", 
                "Qys\\View\\ICompiler"
            ], 
            "view.parser" : [
                "Queryyetsimple\\View\\Parser", 
                "Queryyetsimple\\View\\IParser", 
                "Qys\\View\\Parser", 
                "Qys\\View\\IParser"
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
        this->singleton("view.views", function (project) {
            return new \Queryyetsimple\View\Manager(project);
        });
    }
    
    /**
     * 注册 view.view 服务
     *
     * @return void
     */
    protected function viewView()
    {
        this->singleton("view.view", function (project) {
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
        this->singleton("view.compiler", function (project) {
            return new \Queryyetsimple\View\Compiler();
        });
    }
    
    /**
     * 注册 view.parser 服务
     *
     * @return void
     */
    protected function viewParser()
    {
        this->singleton("view.parser", function (project) {
            var parser;

            let parser = new \Queryyetsimple\View\Parser(project->make("view.compiler"));
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
        this->singleton("view.twig.parser", function (project) {
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
