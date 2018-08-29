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
use Leevel\Router\Url;
use Leevel\Di\Provider;
use Leevel\Di\IContainer;
use Leevel\Http\Response;
use Leevel\Router\Router;
use Leevel\Router\Redirect;
use Leevel\Router\ResponseFactory;

/**
 * router 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
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
        return [
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
    }

    /**
     * 注册 router 服务
     *
     * @return void
     */
    protected function router()
    {
        this->container->singleton("router", Closure::fromCallable([this, "routerClosure"]));
    }

    /**
     * 创建 router 闭包
     * 
     * @param \Leevel\Project\IProject $project
     * @return \Leevel\Router\Router
     */
    protected function routerClosure(var project)
    {
        return new Router(project);
    }

    /**
     * 注册 url 服务
     *
     * @return void
     */
    protected function url()
    {
        this->container->singleton("url", Closure::fromCallable([this, "urlClosure"]));
    }

    /**
     * 创建 url 闭包
     * 
     * @param \Leevel\Project\IProject $project
     * @return \Leevel\Router\Url
     */
    protected function urlClosure(var project)
    {
        var option, request, options = [], item;
        
        let option = project->make("option");
        let request = project->make("request");

        for item in [
            "with_suffix",
            "html_suffix",
            "domain_top",
            "subdomain_on"
        ] {
            let options[item] = option->get(item);
        }

        return new Url(request, options);
    }

    /**
     * 注册 redirect 服务
     *
     * @return void
     */
    protected function redirect()
    {
        this->container->bind("redirect", this->container->share(Closure::fromCallable([this, "redirectClosure"])));
    }

    /**
     * 创建 redirect 闭包
     * 
     * @param \Leevel\Project\IProject $project
     * @return \Leevel\Router\Redirect
     */
    protected function redirectClosure(var project)
    {
        var redirect, session;

        let redirect = new Redirect(project->make("url"));
        let session = project->make("session");

        if (session !== false) {
            redirect->setSession(session);
        }

        return redirect;
    }

    /**
     * 注册 response 服务
     *
     * @return void
     */
    protected function response()
    {
        this->container->singleton("response", Closure::fromCallable([this, "responseClosure"]));
    }

    /**
     * 创建 response 闭包
     * 
     * @param \Leevel\Project\IProject $project
     * @return \Leevel\Router\ResponseFactory
     */
    protected function responseClosure(var project)
    {
        var option, response;

        let option = project->make("option");
        let response = new ResponseFactory(project->make("view"), project->make("redirect"));

        return response->

        setViewSuccessTemplate(option->get("view\\action_success"))->

        setViewFailTemplate(option->get("view\\action_fail"));
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
    protected function makeCookieResolverClosure()
    {
        return this->container->make("cookie");
    }
}
