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
namespace Queryyetsimple\Router\Provider;

use Queryyetsimple\Di\Provider;
use Queryyetsimple\Di\IContainer;

/**
 * router 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.28
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
        this->router();
        this->url();
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
            "router" : [
                "Queryyetsimple\\Router\\Router", 
                "Qys\\Router\\Router"
            ],
            "url" : [
                "Queryyetsimple\\Router\\Url", 
                "Qys\\Router\\Url"
            ]
        ];
        return tmp;
    }

    /**
     * 注册 router 服务
     *
     * @return void
     */
    protected function router()
    {
        this->singleton("router", function (project) {
            var option, options = [], item, tmp;
            
            let option = project->make("option");
            let tmp = [
                "default_app", 
                "default_controller", 
                "default_action", 
                "middleware_group", 
                "middleware_alias",
                "model",
                "rewrite",
                "pathinfo_depr",
                "html_suffix",
                "router_cache",
                "router_strict",
                "router_domain_on",
                "router_domain_top",
                "public",
                "pathinfo_restful",
                "args_protected",
                "args_regex",
                "args_strict",
                "middleware_strict",
                "method_strict",
                "controller_dir"
            ];

            for item in tmp {
                let options[item] = option->get(item);
            }

            let options["apps"] = project->apps();

            return new \Queryyetsimple\Router\Router(project, project->make("pipeline"), project->make("request"), options);
        });
    }

    /**
     * 注册 url 服务
     *
     * @return void
     */
    protected function url()
    {
        this->singleton("url", function (project) {
            var option, router, url, options = [], item, tmp;
            
            let option = project->make("option");
            let router = project->make("router");
            let tmp = [
                "default_app", 
                "default_controller", 
                "default_action", 
                "model",
				"html_suffix",
				"router_domain_top",
				"make_subdomain_on"
            ];

            for item in tmp {
                let options[item] = option->get(item);
            }

			let url = new \Queryyetsimple\Router\Url(options);

			url->setApp(router->app())->

            setController(router->controller())->

            setAction(router->action())->

            setUrlEnter(project->make("url_enter"));

			return url;
        });
    }
}
