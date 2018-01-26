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
namespace Queryyetsimple\Session\Provider;

use Queryyetsimple\Di\Provider;
use Queryyetsimple\Di\IContainer;

/**
 * session 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.26
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
        this->sessions();
        this->session();
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
        	"sessions" : [
        		"Queryyetsimple\\Session\\Manager", 
        		"Qys\\Session\\Manager"
        	], 
        	"session" : [
        		"Queryyetsimple\\Session\\Session", 
        		"Queryyetsimple\\Session\\ISession", 
        		"Qys\\Session\\Session", 
        		"Qys\\Session\\ISession"
        	], 
        	"Queryyetsimple\\Session\\Middleware\\Session"
        ];
        return tmp;
    }
    
    /**
     * 注册 sessions 服务
     *
     * @return void
     */
    protected function sessions()
    {
        this->singleton("sessions", function (project) {
            return new \Queryyetsimple\Session\Manager(project);
        });
    }
    
    /**
     * 注册 session 服务
     *
     * @return void
     */
    protected function session()
    {
        this->singleton("session", function (project) {
            var sessions;

        	let sessions = project->make("sessions");
            return sessions->connect();
        });
    }
    
    /**
     * 注册 middleware 服务
     *
     * @return void
     */
    protected function middleware()
    {
        this->singleton("Queryyetsimple\\Session\\Middleware\\Session");
    }
}
