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
namespace Leevel\Router\Provider;

use Closure;
use Leevel\Di\Provider;
use Leevel\Di\IContainer;
use Leevel\Http\Response;

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
        this->router();
        this->url();
        this->redirect();
        this->response();
        this->cookieResolver();
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
                "Leevel\\Router\\Router"
            ],
            "url" : [
                "Leevel\\Router\\Url"
            ],
            "redirect" : [
                "Leevel\\Router\\Redirect"
            ],
            "response" : [
                "Leevel\\Router\\IResponseFactory",
                "Leevel\\Router\\ResponseFactory"
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
        this->container->singleton("router", function (project) {
            return new \Leevel\Router\Router(project, project->make("request"));
        });
    }

    /**
     * 注册 url 服务
     *
     * @return void
     */
    protected function url()
    {
        this->container->singleton("url", function (project) {
            var option, request, options = [], item, tmp;
            
            let option = project->make("option");
            let request = project->make("request");
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

			return new \Leevel\Router\Url(request, options);
        });
    }

    /**
     * 注册 redirect 服务
     *
     * @return void
     */
    protected function redirect()
    {
        this->container->bind("redirect", this->container->share(function (project) {
        	var redirect, session;

            let redirect = new \Leevel\Router\Redirect(project->make("url"));
            let session = project->make("session");

            if (session !== false) {
                redirect->setSession(session);
            }

            return redirect;
        }));
    }

    /**
     * 注册 response 服务
     *
     * @return void
     */
    protected function response()
    {
        this->container->singleton("response", function (project) {
        	var option, response;

        	let option = project->make("option");
        	let response = new \Leevel\Router\ResponseFactory(project->make("view"), project->make("redirect"));

        	return response->

        	setViewSuccessTemplate(option->get("view\\action_success"))->

            setViewFailTemplate(option->get("view\\action_fail"));
        });
    }

    /**
     * 设置 COOKIE Resolver
     *
     * @return void
     */
    protected function cookieResolver()
    {
        Response::setCookieResolver(Closure::fromCallable([this, "makeCookieResolverClosure"]));
    }

   /**
	 * 生成 COOKIE
	 *
	 * @return \Leevel\Cookie\ICookie
	 */
	protected function makeCookieResolverClosure() {
		return this->container->make("cookie");
	}
}
