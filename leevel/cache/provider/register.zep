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
namespace Leevel\Cache\Provider;

use Closure;
use Leevel\Cache\Load;
use Leevel\Di\Provider;
use Leevel\Cache\Manager;
use Leevel\Di\IContainer;

/**
 * cache 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.06.03
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
        this->caches();
        this->cache();
        this->cacheLoad();
    }
    
    /**
     * 可用服务提供者
     *
     * @return array
     */
    public static function providers() -> array
    {
        var tem;
    
        let tem = [
            "caches" : [
                "Leevel\\Cache\\Manager"
            ], 
            "cache" : [
                "Leevel\\Cache\\Cache", 
                "Leevel\\Cache\\ICache"
            ], 
            "cache.load" : [
                "Leevel\\Cache\\Load"
            ]
        ];
        
        return tem;
    }
    
    /**
     * 注册 caches 服务
     *
     * @return void
     */
    protected function caches()
    {
        this->container->singleton("caches", Closure::fromCallable([this, "cachesClosure"]));
    }

    /**
     * 创建 auths 闭包
     * 
     * @param \Leevel\Project\IProject $project
     * @return \Leevel\Cache\Manager
     */
    protected function cachesClosure(var project)
    {
        return new Manager(project);
    }
    
    /**
     * 注册 cache 服务
     *
     * @return void
     */
    protected function cache()
    {
        this->container->singleton("cache", Closure::fromCallable([this, "cacheClosure"]));
    }

    /**
     * 创建 cache 闭包
     * 
     * @param \Leevel\Project\IProject $project
     * @return object
     */
    protected function cacheClosure(var project)
    {
        return project->make("caches")->connect();
    }
    
    /**
     * 注册 cache.load 服务
     *
     * @return void
     */
    protected function cacheLoad()
    {
        this->container->singleton("cache.load", Closure::fromCallable([this, "cacheLoadClosure"]));
    }

    /**
     * 创建 cache.load 闭包
     * 
     * @param \Leevel\Project\IProject $project
     * @return \Leevel\Cache\Load
     */
    protected function cacheLoadClosure(var project)
    {
        return new Load(project, project->make("cache"));
    }
}
