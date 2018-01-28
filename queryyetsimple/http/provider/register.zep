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
namespace Queryyetsimple\Http\Provider;

use Queryyetsimple\Di\Provider;
use Queryyetsimple\Di\IContainer;

/**
 * http 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.27
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
        this->request();
        this->response();
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
            "request" : [
                "Queryyetsimple\\Http\\Request", 
                "Qys\\Http\\Request"
            ], 
            "response" : [
                "Queryyetsimple\\Http\\Response", 
                "Qys\\Http\\Response"
            ]
        ];
        return tmp;
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
                "var_pjax" : option->get("var_pjax")
            ];

            return new \Queryyetsimple\Http\Request(project->make("session"), project->make("cookie"), tmp);
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
            var option, tmp;
        
            let option = project->make("option");
            let tmp = [
                "action_fail" : option->get("view\\action_fail"), 
                "action_success" : option->get("view\\action_success"), 
                "default_response" : option->get("default_response")
            ];

            return new \Queryyetsimple\Http\Response(project->make("router"), project->make("view"), project->make("session"), project->make("cookie"), tmp);
        });
    }
}
