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
        this->singleton("router", function (project) {
            var option, options, item, tmp;
            
            let option = project->make("option");
            let options = option->get("url\\");
            let tmp = [
                "~apps~", 
                "default_app", 
                "default_controller", 
                "default_action", 
                "middleware_group", 
                "middleware_alias"
            ];

            for item in tmp {
                let options[item] = option->get(item);
            }

            return new \Queryyetsimple\Router\Router(project, project->make("pipeline"), project->make("request"), options);
        });
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
            ]
        ];
        return tmp;
    }
}
