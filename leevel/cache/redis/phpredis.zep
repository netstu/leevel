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

namespace Leevel\Cache\Redis;

use Redis;
use RuntimeException;

/**
 * php redis 扩展缓存.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.07.29
 *
 * @version 1.0
 */
class PhpRedis implements IConnect
{
    /**
     * redis 句柄.
     *
     * @var handle
     */
    protected handle;

    /**
     * 配置.
     *
     * @var array
     */
    protected option = [
        "host" : "127.0.0.1",
        "port" : 6379,
        "password" : "",
        "select" : 0,
        "timeout" : 0,
        "persistent" : false
    ];
    
    /**
     * 构造函数.
     *
     * @param array $option
     */
    public function __construct(array option = []) -> void
    {
        var method;

        if ! (extension_loaded("redis")) {
            throw new RuntimeException("Redis extension must be loaded before use.");
        }

        let this->option = array_merge(this->option, option);

        let this->handle = this->createRedis();

        let method = this->option["persistent"] ? "pconnect" : "connect";

        call_user_func(
            [this->handle, method],
            this->option["host"],
            (int) this->option["port"],
            this->option["timeout"]
        );

        if this->option["password"] {
            this->handle->auth(this->option["password"]);
        }

        if this->option["select"] {
            this->handle->select(this->option["select"]);
        }
    }
    
    /**
     * 返回缓存句柄.
     *
     * @return mixed
     */
    public function handle()
    {
        return this->handle;
    }
    
    /**
     * 获取缓存.
     *
     * @param string $name
     *
     * @return mixed
     */
    public function get(string name)
    {
        return this->handle->get(name);
    }
    
    /**
     * 设置缓存.
     *
     * @param string $name
     * @param mixed  $data
     * @param int    $expire
     */
    public function set(string name, data, var expire = null) -> void
    {
        if expire {
            this->handle->setex(name, expire, data);
        } else {
            this->handle->set(name, data);
        }
    }
    
    /**
     * 清除缓存.
     *
     * @param string $name
     */
    public function delete(string name) -> void
    {
        this->handle->delete(name);
    }
    
    /**
     * 关闭 redis.
     */
    public function close() -> void
    {
        this->handle->close();
        let this->handle = null;
    }
    
    /**
     * 返回 redis 对象
     *
     * @return \Redis
     */
    protected function createRedis() -> <Redis>
    {
        return new Redis();
    }
}