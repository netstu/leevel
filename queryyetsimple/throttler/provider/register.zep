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
namespace Queryyetsimple\Throttler\Provider;

use Queryyetsimple\Di\Provider;
use Queryyetsimple\Di\IContainer;

/**
 * throttler 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.28
 * @version 1.0
 */
class Register extends Provider
{

    /**
     * 是否延迟载入
     *
     * @var boolean
     */
    public static defer = true;

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
        this->throttler();
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
            "throttler" : [
                "Queryyetsimple\\Throttler\\Throttler", 
                "Queryyetsimple\\Throttler\\IThrottler", 
                "Qys\\Throttler\\Throttler", 
                "Qys\\Throttler\\IThrottler"
            ], 
            "Queryyetsimple\\Throttler\\Middleware\\Throttler"
        ];
        return tmp;
    }
    
    /**
     * 注册 throttler 服务
     *
     * @return void
     */
    protected function throttler()
    {
        this->singleton("throttler", function (project) {
            var throttler, cache;

            let cache = project->make("cache")->connect(project->make("option")->get("throttler\\driver"));
            let throttler = new \Queryyetsimple\Throttler\Throttler(cache);
            throttler->setRequest(project->make("request"));

            return throttler;
        });
    }
    
    /**
     * 注册 middleware 服务
     *
     * @return void
     */
    protected function middleware()
    {
        this->singleton("Queryyetsimple\\Throttler\\Middleware\\Throttler");
    }
}
