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

use Closure;
use Queryyetsimple\Di\Provider;
use Queryyetsimple\Di\IContainer;
use Queryyetsimple\Http\Response;

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
        this->redirect();
        this->request();
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
                "Queryyetsimple\\Router\\Router", 
                "Qys\\Router\\Router"
            ],
            "url" : [
                "Queryyetsimple\\Router\\Url", 
                "Qys\\Router\\Url"
            ],
            "redirect" : [
                "Queryyetsimple\\Router\\Redirect",
                "Qys\\Router\\Redirect"
            ],
            "request" : [
				"Queryyetsimple\\Http\\Request", 
				"Qys\\Http\\Request"
			],
            "response" : [
                "Queryyetsimple\\Router\\IResponseFactory",
                "Queryyetsimple\\Router\\ResponseFactory",
                "Qys\\Router\\IResponseFactory",
                "Qys\\Router\\ResponseFactory"
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
                "router_cache",
                "router_strict",
                "router_domain_on",
                "router_domain_top",
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

            return new \Queryyetsimple\Router\Router(project, project->make("request"), options);
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

			return new \Queryyetsimple\Router\Url(request, options);
        });
    }

    /**
     * 注册 redirect 服务
     *
     * @return void
     */
    protected function redirect()
    {
        this->bind("redirect", this->share(function (project) {
        	var redirect, session;

            let redirect = new \Queryyetsimple\Router\Redirect(project->make("url"));
            let session = project->make("session");

            if (session !== false) {
                redirect->setSession(session);
            }

            return redirect;
        }));
    }

    /**
	 * 注册 request 服务
	 *
	 * @return void
	 */
	protected function request()
	{
		this->singleton("request", function (project) {
			var option, tmp;

			let option = project->make("option");
			let tmp = [
				"var_method" : option->get("var_method"), 
				"var_ajax" : option->get("var_ajax"), 
				"var_pjax" : option->get("var_pjax"),
				"html_suffix" : option->get("html_suffix"),
				"rewrite" : option->get("rewrite"),
				"public" : option->get("public")
			];

			return new \Queryyetsimple\Http\Request(_GET, _POST, [], _COOKIE, _FILES, _SERVER, null, tmp);
		});
	}

    /**
     * 注册 response 服务
     *
     * @return void
     */
    protected function response()
    {
        this->singleton("response", function (project) {
        	var option, response;

        	let option = project->make("option");
        	let response = new \Queryyetsimple\Router\ResponseFactory(project->make("view"), project->make("redirect"));

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
	 * @return \Queryyetsimple\Cookie\ICookie
	 */
	protected function makeCookieResolverClosure() {
		return this->container->make("cookie");
	}
}
