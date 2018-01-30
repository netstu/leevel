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
namespace Queryyetsimple\Log\Provider;

use Queryyetsimple\Di\Provider;
use Queryyetsimple\Di\IContainer;

/**
 * log 服务提供者
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
        this->logs();
        this->log();
        this->middleware();
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
            "logs" : [
                "Queryyetsimple\\Log\\Manager", 
                "Qys\\Log\\Manager"
            ], 
            "log" : [
                "Queryyetsimple\\Log\\Log", 
                "Queryyetsimple\\Log\\ILog", 
                "Qys\\Log\\Log", 
                "Qys\\Log\\ILog"
            ], 
            "Queryyetsimple\\Log\\Middleware\\Log"
        ];
        return tmp;
    }
    
    /**
     * 注册 logs 服务
     *
     * @return void
     */
    protected function logs()
    {
        this->singleton("logs", function (project) {
            return new \Queryyetsimple\Log\Manager(project);
        });
    }
    
    /**
     * 注册 log 服务
     *
     * @return void
     */
    protected function log()
    {
        this->singleton("log", function (project) {
            return project->make("logs")->connect();
        });
    }
    
    /**
     * 注册 middleware 服务
     *
     * @return void
     */
    protected function middleware()
    {
        this->singleton("Queryyetsimple\\Log\\Middleware\\Log");
    }
}