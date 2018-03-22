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
namespace Queryyetsimple\Cache\Provider;

use Queryyetsimple\Di\Provider;
use Queryyetsimple\Di\IContainer;

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
        		"Queryyetsimple\\Cache\\Manager", 
        		"Qys\\Cache\\Manager"
        	], 
        	"cache" : [
        		"Queryyetsimple\\Cache\\Cache", 
        		"Queryyetsimple\\Cache\\ICache", 
        		"Qys\\Cache\\Cache", 
        		"Qys\\Cache\\ICache"
        	], 
        	"cache.load" : [
        		"Queryyetsimple\\Cache\\Load", 
        		"Qys\\Cache\\Load"
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
        this->singleton("caches", function (project) {
            return new \Queryyetsimple\Cache\Manager(project);
        });
    }
    
    /**
     * 注册 cache 服务
     *
     * @return void
     */
    protected function cache()
    {
        this->singleton("cache", function (project) {
        	var caches;

        	let caches = project->make("caches");
            return caches->connect();
        });
    }
    
    /**
     * 注册 cache.load 服务
     *
     * @return void
     */
    protected function cacheLoad()
    {
        this->singleton("cache.load", function (project) {
        	var cache;

        	let cache = project->make("cache");
            return new \Queryyetsimple\Cache\Load(project, cache);
        });
    }
}
