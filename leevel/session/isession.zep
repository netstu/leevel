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
namespace Leevel\Session;

/**
 * ISession 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.09
 * @version 1.0
 */
interface ISession
{
    /**
     * 修改单个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function setOption(string name, var value);

     /**
     * 启动 session
     *
     * @return $this
     */
    public function start();

    /**
     * 设置 session
     *
     * @param string $name
     * @param mxied $value
     * @return void
     */
    public function set(string name, var value);

    /**
     * 批量插入
     *
     * @param string|array $keys
     * @param mixed $value
     * @return void
     */
    public function put(var keys, var value = null);

    /**
     * 数组插入数据
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function push(string key, var value);

    /**
     * 合并元素
     *
     * @param string $key
     * @param array $value
     * @return void
     */
    public function merge(string key, array value);

    /**
     * 弹出元素
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function pop(string key, array value);

    /**
     * 数组插入键值对数据
     *
     * @param string $key
     * @param mixed $keys
     * @param mixed $value
     * @return void
     */
    public function arr(string key, var keys, var value = null);

    /**
     * 数组键值删除数据
     *
     * @param string $key
     * @param mixed $keys
     * @return void
     */
    public function arrDelete(string key, var keys);

    /**
     * 取回 session
     *
     * @param string $name
     * @param mixed $value
     * @return mxied
     */
    public function get(string name, var value = null);

    /**
     * 返回数组部分数据
     *
     * @param string $name
     * @param mixed $value
     * @return mixed
     */
    public function getPart(string name, var value = null);

    /**
     * 删除 session
     *
     * @param string $name
     * @param boolean $prefix
     * @return bool
     */
    public function delete(string name, boolean prefix = true);

    /**
     * 是否存在 session
     *
     * @param string $name
     * @return boolean
     */
    public function has(string name);

    /**
     * 删除 session
     *
     * @param boolean $prefix
     * @return void
     */
    public function clear(boolean prefix = true);

    /**
     * 闪存一个数据，当前请求和下一个请求可用
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function flash(string key, var value = null);

    /**
     * 批量闪存数据，当前请求和下一个请求可用
     *
     * @param array $flash
     * @return void
     */
    public function flashs(array flash);

    /**
     * 闪存一个 flash 用于当前请求使用，下一个请求将无法获取
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function nowFlash(string key, var value);

    /**
     * 保持所有闪存数据
     *
     * @return void
     */
    public function rebuildFlash();

    /**
     * 保持闪存数据
     *
     * @return void
     */
    public function keepFlash();

    /**
     * 返回闪存数据
     *
     * @param string $key
     * @param mixed $defaults
     * @return mixed
     */
    public function getFlash(string key, var defaults = null);

    /**
     * 删除闪存数据
     *
     * @return void
     */
    public function deleteFlash();

    /**
     * 清理所有闪存数据
     *
     * @return void
     */
    public function clearFlash();

    /**
     * 程序执行结束清理 flash
     *
     * @return void
     */
    public function unregisterFlash();

    /**
     * 获取前一个请求地址
     *
     * @return string|null
     */
    public function prevUrl();

    /**
     * 设置前一个请求地址
     *
     * @param string $url
     * @return void
     */
    public function setPrevUrl(string url);

    /**
     * 暂停 session
     *
     * @return void
     */
    public function pause();

    /**
     * 终止会话
     *
     * @return bool
     */
    public function destroy();

    /**
     * session 是否已经启动
     *
     * @return boolean
     */
    public function isStart();

    /**
     * session 状态
     *
     * @return int
     */
    public function status();

    /**
     * 设置 SESSION 名字
     *
     * @param string $name
     * @return void
     */
    public function setName(string name);

    /**
     * 取得 SESSION 名字
     *
     * @return string
     */
    public function getName() -> string;

    /**
     * 设置 SESSION ID
     *
     * @param string $name
     * @return void
     */
    public function setId(string id);

    /**
     * 取得 SESSION ID
     *
     * @return string
     */
    public function getId() -> string;

    /**
     * 设置 save path
     *
     * @param string $savepath
     * @return void
     */
    public function setSavePath(string savepath);

    /**
     * 获取 save path
     *
     * @return string
     */
    public function getSavePath();

    /**
     * 设置 cookie_domain
     *
     * @param string $domain
     * @return void
     */
    public function setCookieDomain(string domain);

    /**
     * 获取 cookie_domain
     *
     * @return string
     */
    public function getCookieDomain();

    /**
     * 设置 cache expire
     *
     * @param int $second
     * @return void
     */
    public function setCacheExpire(int second);

    /**
     * session 使用 cookie
     *
     * @return boolean
     */
    public function setUseCookies();

    /**
     * 设置 cache limiter
     *
     * @param string $limiter
     * @return void
     */
    public function setCacheLimiter(string limiter);

    /**
     * 获取 cache limiter
     *
     * @return string
     */
    public function getCacheLimiter();

    /**
     * 设置 session 垃圾回收概率分子
     * 分母为 session.gc_divisor
     *
     * @param int $probability
     * @return void
     */
    public function setGcProbability(int probability);

    /**
     * 获取 session 垃圾回收概率分子
     * 分母为 session.gc_divisor
     *
     * @return int
     */
    public function getGcProbability();
}
