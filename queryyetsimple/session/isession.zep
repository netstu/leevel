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
namespace Queryyetsimple\Session;

/**
 * isession 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.09
 * @version 1.0
 */
interface Isession
{

    /**
     * 启动 session
     *
     * @return void
     */
    public function start();

    /**
     * 设置 session
     *
     * @param string $sName
     * @param mxied $mixValue
     * @return void
     */
    public function set(string sName, var mixValue);

    /**
     * 批量插入
     *
     * @param string|array $mixKey
     * @param mixed $mixValue
     * @return void
     */
    public function put(var mixKey, var mixValue = null);

    /**
     * 数组插入数据
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @return void
     */
    public function push(string strKey, var mixValue);

    /**
     * 合并元素
     *
     * @param string $strKey
     * @param array $arrValue
     * @return void
     */
    public function merge(string strKey, array arrValue);

    /**
     * 弹出元素
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @return void
     */
    public function pop(string strKey, array arrValue);

    /**
     * 数组插入键值对数据
     *
     * @param string $strKey
     * @param mixed $mixKey
     * @param mixed $mixValue
     * @return void
     */
    public function arrays(string strKey, var mixKey, var mixValue = null);

    /**
     * 数组键值删除数据
     *
     * @param string $strKey
     * @param mixed $mixKey
     * @return void
     */
    public function arraysDelete(string strKey, var mixKey);

    /**
     * 取回 session
     *
     * @param string $sName
     * @param mixed $mixValue
     * @return mxied
     */
    public function get(string sName, var mixValue = null);

    /**
     * 返回数组部分数据
     *
     * @param string $sName
     * @param mixed $mixValue
     * @return mixed
     */
    public function getPart(string sName, var mixValue = null);

    /**
     * 删除 session
     *
     * @param string $sName
     * @param boolean $bPrefix
     * @return bool
     */
    public function delete(string sName, var bPrefix = true);

    /**
     * 是否存在 session
     *
     * @param string $sName
     * @return boolean
     */
    public function has(string sName);

    /**
     * 删除 session
     *
     * @param boolean $bPrefix
     * @return void
     */
    public function clear(boolean bPrefix = true);

    /**
     * 闪存一个数据，当前请求和下一个请求可用
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @return void
     */
    public function flash(string strKey, var mixValue = null);

    /**
     * 批量闪存数据，当前请求和下一个请求可用
     *
     * @param array $arrFlash
     * @return void
     */
    public function flashs(array arrFlash);

    /**
     * 闪存一个 flash 用于当前请求使用，下一个请求将无法获取
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @return void
     */
    public function nowFlash(string strKey, var mixValue);

    /**
     * 保持所有闪存数据
     *
     * @return void
     */
    public function rebuildFlash();

    /**
     * 保持闪存数据
     *
     * @param mixed $mixKey
     * @return void
     */
    public function keepFlash(var mixKey);

    /**
     * 返回闪存数据
     *
     * @param string $strKey
     * @param mixed $mixDefault
     * @return mixed
     */
    public function getFlash(string strKey, var mixDefault = null);

    /**
     * 删除闪存数据
     *
     * @param mixed $mixKey
     * @return void
     */
    public function deleteFlash(var mixKey);

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
     * @param string $strUrl
     * @return void
     */
    public function setPrevUrl(string strUrl);

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
     * 获取解析 session_id
     *
     * @param string $sId
     * @return string
     */
    public function parseSessionId();

    /**
     * 设置 save path
     *
     * @param string $sSavePath
     * @return string
     */
    public function savePath(string sSavePath = null);

    /**
     * 设置 cache limiter
     *
     * @param string $strCacheLimiter
     * @return string
     */
    public function cacheLimiter(string strCacheLimiter = null);

    /**
     * 设置 cache expire
     *
     * @param int $nExpireSecond
     * @return void
     */
    public function cacheExpire(int nExpireSecond = null);

    /**
     * session_name
     *
     * @param string $sName
     * @return string
     */
    public function sessionName(string sName = null);

    /**
     * session id
     *
     * @param string $sId
     * @return string
     */
    public function sessionId(string sId = null);

    /**
     * session 的 cookie_domain 设置
     *
     * @param string $sSessionDomain
     * @return string
     */
    public function cookieDomain(string sSessionDomain = null);

    /**
     * session 是否使用 cookie
     *
     * @param boolean $bUseCookies
     * @return boolean
     */
    public function useCookies(boolean bUseCookies = null);

    /**
     * 客户端禁用 cookie 可以开启这个项
     *
     * @param string $nUseTransSid
     * @return boolean
     */
    public function useTransSid(int nUseTransSid = null);

    /**
     * 设置过期 cookie lifetime
     *
     * @param int $nCookieLifeTime
     * @return int
     */
    public function cookieLifetime(int nCookieLifeTime);

    /**
     * gc maxlifetime
     *
     * @param int $nGcMaxlifetime
     * @return int
     */
    public function gcMaxlifetime(int nGcMaxlifetime = null);

    /**
     * session 垃圾回收概率分子 (分母为 session.gc_divisor)
     *
     * @param int $nGcProbability
     * @return int
     */
    public function gcProbability(int nGcProbability = null);
}
