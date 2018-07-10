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
namespace Leevel\Support;

use Closure;
use Exception;
use RuntimeException;
use BadMethodCallException;
use Leevel\Di\IContainer;

/**
 * 实现类的静态访问门面
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.23
 * @version 1.0
 */
abstract class Facade
{

    /**
     * 项目容器
     *
     * @var \Leevel\Di\IContainer
     */
    protected static container;

    /**
     * 注入容器实例
     *
     * @var object
     */
    protected static instances = [];

    /**
     * 获取注册容器的实例
     *
     * @return mixed
     */
    public static function facades()
    {
        var unique, instance;

        let unique = static::name();

        if fetch instance, self::instances[unique] {
            return instance;
        }

        let instance = self::container()->make(unique);
        if typeof instance != "object" {
            throw new RuntimeException(sprintf("Services %s was not found in the IOC container.", unique));
        }

        return instance;
    }

    /**
     * 返回服务容器
     *
     * @return \Leevel\Di\IContainer
     */
    public static function container() -> <IContainer>
    {
        return self::container;
    }

     /**
     * 设置服务容器
     *
     * @param \Leevel\Di\IContainer $container
     * @return void
     */
    public static function setContainer(<IContainer> container) -> void
    {
        let self::container = container;
    }

    /**
     * 门面名字
     *
     * @return string
     */
    protected static function name() -> string {
        return "";
    }

    /**
     * call 
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public static function __callStatic(string method, array args)
    {
        var instance, callback;

        let instance = self::facades();
        if ! instance {
            throw new RuntimeException(
                "Can not find instance from container."
            );
        }

        let callback = [
            instance,
            method
        ];
        if ! is_callable(callback) {
            throw new BadMethodCallException(
                sprintf("Method %s is not exits.", method)
            );
        }

        return call_user_func_array(callback, args);
    }
}
