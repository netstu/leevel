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
namespace Queryyetsimple\Di;

use Closure;

/**
 * IContainer 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.04.13
 * @version 1.0
 */
interface IContainer
{

    /**
     * 注册到容器
     *
     * @param mixed $name
     * @param mixed $service
     * @param boolean $share
     * @return $this
     */
    public function bind(var name, var service = null, bool share = false);

    /**
     * 注册为实例
     *
     * @param mixed $name
     * @param mixed $service
     * @return void
     */
    public function instance(var name, var service);

    /**
     * 注册单一实例
     *
     * @param string $name
     * @param mixed $service
     * @return void
     */
    public function singleton(var name, var service = null);

    /**
     * 创建共享的闭包
     *
     * @param \Closure $closure
     * @return \Closure
     */
    public function share(<Closure> closure);

    /**
     * 设置别名
     *
     * @param array|string $alias
     * @param string|null|array $value
     * @return void
     */
    public function alias(var alias, var value = null);

    /**
     * 分组注册
     *
     * @param string $group
     * @param mixed $data
     * @return void
     */
    public function group(var group, var data);

    /**
     * 分组制造
     *
     * @param string $group
     * @param array $args
     * @return array
     */
    public function groupMake(var group, array args = []);

    /**
     * 服务容器返回对象
     *
     * @param string $name
     * @param array $args
     * @return object|false
     */
    public function make(var name, array args = []);

    /**
     * 实例回调自动注入
     *
     * @param callable $callback
     * @param array $args
     * @return mixed
     */
    public function call(var callback, array args = []);
}
