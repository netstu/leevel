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

use RuntimeException;
use BadMethodCallException;
use SessionHandlerInterface;
use Queryyetsimple\Session\Isession;

/**
 * session 仓储
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.09
 * @version 1.0
 */
class Session implements Isession
{

	/**
     * session handler 
     *
     * @var \SessionHandlerInterface|null
     */
    protected objConnect;

    /**
     * session 是否开启
     *
     * @var boolean
     */
    protected booStarted = false;

    /**
     * 配置
     *
     * @var array
     */
    protected arrOption = [
        "default" : null,
        "prefix" : "q_",
        "id" : null,
        "name" : null,
        "cookie_domain" : null,
        "cache_limiter" : null,
        "expire" : 86400,
        "cookie_lifetime" : null,
        "gc_maxlifetime" : null,
        "save_path" : null,
        "use_trans_sid" : null,
        "gc_probability" : null
    ];

    /**
     * session 状态启用
     *
     * @var int
     */
    const SESSION_ACTIVE = 2;

    /**
     * session 状态未运行
     *
     * @var int
     */
    const SESSION_NONE = 1;

    /**
     * session 状态关闭
     *
     * @var int
     */
    const SESSION_DISABLED = 0;

    /**
     * 构造函数
     *
     * @param \SessionHandlerInterface|null $objConnect
     * @param array $arrOption
     * @return void
     */
    public function __construct(<SessionHandlerInterface> objConnect = null, array arrOption = [])
    {
        let this->objConnect =  objConnect;
        this->options(arrOption);
    }

    /**
     * 启动 session
     *
     * @return $this
     */
    public function start()
    {
        if headers_sent() || this->isStart() || this->status() === self::SESSION_ACTIVE {
            return this;
        }

        // 设置 session 不自动启动
        ini_set("session.auto_start", 0);

        // 设置 session id
        if this->getOption("id") {
            session_id(this->getOption("id"));
        } else {
            if ! this->parseSessionId() {
                this->sessionId(uniqid(dechex(mt_rand())));
            }
        }

        // cookie domain
        if this->getOption("cookie_domain") {
            this->cookieDomain(this->getOption("cookie_domain"));
        }

        // session name
        if this->getOption("name") {
            this->sessionName(this->getOption("name"));
        }

        // cache expire
        if this->getOption("expire") {
            this->cacheExpire(this->getOption("expire"));
        }

        // gc maxlifetime
        if this->getOption("gc_maxlifetime") {
            this->gcMaxlifetime(this->getOption("gc_maxlifetime"));
        }

        // cookie lifetime
        if this->getOption("cookie_lifetime") {
            this->cookieLifetime(this->getOption("cookie_lifetime"));
        }

        // cache limiter
        if this->getOption("cache_limiter") {
            this->cacheLimiter(this->getOption("cache_limiter"));
        }

        // save path
        if this->getOption("save_path") {
            this->savePath(this->getOption("save_path"));
        }

        // use_trans_sid
        if this->getOption("use_trans_sid") {
            this->useTransSid(this->getOption("use_trans_sid"));
        }

        // gc_probability
        if this->getOption("gc_probability") {
            this->gcProbability(this->getOption("gc_probability"));
        }

        // 驱动
        if this->objConnect && ! session_set_save_handler(this->objConnect) {
            throw new RuntimeException(sprintf("Session drive %s settings failed.", get_class(this->objConnect)));
        }

        // 启动 session
        if ! session_start() {
            throw new RuntimeException("Session start failed");
        }

        let this->booStarted = true;

        return this;
    }

    /**
     * 设置 session
     *
     * @param string $sName
     * @param mxied $mixValue
     * @return void
     */
    public function set(string sName, var mixValue)
    {
        this->checkStart();

        let sName = this->getName(sName);
        let _SESSION[sName] = mixValue;
    }

    /**
     * 批量插入
     *
     * @param string|array $mixKey
     * @param mixed $mixValue
     * @return void
     */
    public function put(var mixKey, var mixValue = null)
    {
        var strKey;

        this->checkStart();

        if typeof mixKey != "array" {
            let mixKey = [
                mixKey : mixValue
            ];
        }

        for strKey, mixValue in mixKey {
            this->set(strKey, mixValue);
        }
    }

    /**
     * 数组插入数据
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @return void
     */
    public function push(string strKey, var mixValue)
    {
        var arr;
        let arr = this->get(strKey, []);
        let arr[] = mixValue;
        this->set(strKey, arr);
    }

    /**
     * 合并元素
     *
     * @param string $strKey
     * @param array $arrValue
     * @return void
     */
    public function merge(string strKey, array arrValue)
    {
        this->set(strKey, array_unique(array_merge(this->get(strKey, []), arrValue)));
    }

    /**
     * 弹出元素
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @return void
     */
    public function pop(string strKey, array arrValue)
    {
        this->set(strKey, array_diff(this->get(strKey, []), arrValue));
    }

    /**
     * 数组插入键值对数据
     *
     * @param string $strKey
     * @param mixed $mixKey
     * @param mixed $mixValue
     * @return void
     */
    public function arrays(string strKey, var mixKey, var mixValue = null)
    {
        var arr;
        let arr = this->get(strKey, []);
        if typeof mixKey == "string" {
            let arr[mixKey] = mixValue;
        } elseif typeof mixKey == "array" {
            let arr = array_merge(arr, mixKey);
        }
        this->set(strKey, arr);
    }

    /**
     * 数组键值删除数据
     *
     * @param string $strKey
     * @param mixed $mixKey
     * @return void
     */
    public function arraysDelete(string strKey, var mixKey)
    {
        var arr, strFoo, arrDeleteKey;
        let arr = this->get(strKey, []);
        if typeof mixKey != "array" {
            let arrDeleteKey = [
                mixKey
            ];
        } else {
        	let arrDeleteKey = mixKey;
        }

        for strFoo in arrDeleteKey {
            if isset arr[strFoo] {
                unset arr[strFoo];
            }
        }
        this->set(strKey, arr);
    }

    /**
     * 取回 session
     *
     * @param string $sName
     * @param mixed $mixValue
     * @return mxied
     */
    public function get(string sName, var mixValue = null)
    {
        this->checkStart();

        let sName = this->getName(sName);
        return isset _SESSION[sName] ? _SESSION[sName] : mixValue;
    }

    /**
     * 返回数组部分数据
     *
     * @param string $sName
     * @param mixed $mixValue
     * @return mixed
     */
    public function getPart(string sName, var mixValue = null) {
    	return this->getPartData(sName, mixValue);
    }

    /**
     * 删除 session
     *
     * @param string $sName
     * @param boolean $bPrefix
     * @return bool
     */
    public function delete(string sName, boolean bPrefix = true)
    {
        this->checkStart();

        if bPrefix {
            let sName = this->getName(sName);
        }

        if isset _SESSION[sName] {
            unset _SESSION[sName];
        }

        return true;
    }

    /**
     * 是否存在 session
     *
     * @param string $sName
     * @return boolean
     */
    public function has(string sName)
    {
        this->checkStart();

        let sName = this->getName(sName);
        return isset _SESSION[sName];
    }

    /**
     * 删除 session
     *
     * @param boolean $bPrefix
     * @return void
     */
    public function clear(boolean bPrefix = true)
    {
        var strPrefix, sKey;

        this->checkStart();

        let strPrefix = this->getOption("prefix");
        for sKey, _ in _SESSION {
            if bPrefix === true && strPrefix && strpos(sKey, strPrefix) === 0 {
                this->delete(sKey, false);
            } else {
                this->delete(sKey, false);
            }
        }
    }

    /**
     * 闪存一个数据，当前请求和下一个请求可用
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @return void
     */
    public function flash(string strKey, var mixValue = null)
    {
        if typeof mixValue == "null" {
            return this->getFlash(strKey);
        } else {
            this->set(this->flashDataKey(strKey), mixValue);
            this->mergeNewFlash([
                strKey
            ]);
            this->popOldFlash([
                strKey
            ]);
        }
    }

    /**
     * 批量闪存数据，当前请求和下一个请求可用
     *
     * @param array $arrFlash
     * @return void
     */
    public function flashs(array arrFlash)
    {
        var strKey, mixValue;

        for strKey, mixValue in arrFlash {
            this->flash(strKey, mixValue);
        }
    }

    /**
     * 闪存一个 flash 用于当前请求使用，下一个请求将无法获取
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @return void
     */
    public function nowFlash(string strKey, var mixValue)
    {
        this->set(this->flashDataKey(strKey), mixValue);
        this->mergeOldFlash([
            strKey
        ]);
    }

    /**
     * 保持所有闪存数据
     *
     * @return void
     */
    public function rebuildFlash()
    {
        this->mergeNewFlash(this->get(this->flashOldKey(), []));
        this->set(this->flashOldKey(), []);
    }

    /**
     * 保持闪存数据
     *
     * @param mixed $mixKey
     * @return void
     */
    public function keepFlash(var mixKey)
    {
        let mixKey = typeof mixKey == "array" ? mixKey : func_get_args();
        this->mergeNewFlash(mixKey);
        this->popOldFlash(mixKey);
    }

    /**
     * 返回闪存数据
     *
     * @param string $strKey
     * @param mixed $mixDefault
     * @return mixed
     */
    public function getFlash(string strKey, var mixDefault = null)
    {
        if strpos(strKey, "\\") !== false {
            return this->getPartData(strKey, mixDefault, "flash");
        } else {
            return this->get(this->flashDataKey(strKey), mixDefault);
        }
    }

    /**
     * 删除闪存数据
     *
     * @param mixed $mixKey
     * @return void
     */
    public function deleteFlash(var mixKey)
    {
        var strKey;
        let mixKey = typeof mixKey == "array" ? mixKey : func_get_args();

        for strKey in mixKey {
            this->delete(this->flashDataKey(strKey));
        }

        this->mergeOldFlash(mixKey);
        this->popNewFlash(mixKey);
    }

    /**
     * 清理所有闪存数据
     *
     * @return void
     */
    public function clearFlash()
    {
        var strNew, arrNewKey;

        let arrNewKey = this->get(this->flashNewKey(), []);

        for strNew, _ in arrNewKey {
            this->deleteFlash(strNew);
        }
    }

    /**
     * 程序执行结束清理 flash
     *
     * @return void
     */
    public function unregisterFlash()
    {
        var arr, arrOld, strOld;

        if this->isStart() {
            let arr = this->get(this->flashNewKey(), []);
            let arrOld = this->get(this->flashOldKey(), []);

            for strOld in arrOld {
                this->delete(this->flashDataKey(strOld));
            }

            this->delete(this->flashNewKey());
            this->set(this->flashOldKey(), arr);
        }
    }

    /**
     * 获取前一个请求地址
     *
     * @return string|null
     */
    public function prevUrl()
    {
        return this->get(this->prevUrlKey());
    }

    /**
     * 设置前一个请求地址
     *
     * @param string $strUrl
     * @return void
     */
    public function setPrevUrl(string strUrl)
    {
        return this->set(this->prevUrlKey(), strUrl);
    }

    /**
     * 暂停 session
     *
     * @return void
     */
    public function pause()
    {
        this->checkStart();
        session_write_close();
    }

    /**
     * 终止会话
     *
     * @return bool
     */
    public function destroy()
    {
    	var strName;

        this->checkStart();

        this->clear(false);

        let strName = this->sessionName();
        if isset _COOKIE[strName] {
            setcookie(strName, "", time() - 42000, "/");
        }

        session_destroy();
    }

    /**
     * session 是否已经启动
     *
     * @return boolean
     */
    public function isStart()
    {
    	return this->booStarted;
    }

    /**
     * session 状态
     *
     * @return int
     */
    public function status(){
    	var intStatus;

        let intStatus = session_status();

        switch intStatus {
            case PHP_SESSION_DISABLED:
                return self::SESSION_DISABLED;

            case PHP_SESSION_ACTIVE:
                return self::SESSION_ACTIVE;
        }

        return self::SESSION_NONE;
    }

    /**
     * 获取解析 session_id
     *
     * @param string $sId
     * @return string
     */
    public function parseSessionId()
    {
        var sId, strName;

        let sId = this->sessionId();
        if sId {
            return sId;
        }

        let strName = this->sessionName();

        if this->useCookies() {
            if isset _COOKIE[strName] {
                return _COOKIE[strName];
            }
        } else {
            if isset _GET[strName] {
                return _GET[strName];
            }
            if isset _POST[strName] {
                return _POST[strName];
            }
        }

        return null;
    }

    /**
     * 设置 save path
     *
     * @param string $sSavePath
     * @return string
     */
    public function savePath(string sSavePath = null)
    {
        return sSavePath ? session_save_path(sSavePath) : session_save_path();
    }

    /**
     * 设置 cache limiter
     *
     * @param string $strCacheLimiter
     * @return string
     */
    public function cacheLimiter(string strCacheLimiter = null)
    {
        return strCacheLimiter ? session_cache_limiter(strCacheLimiter) : session_cache_limiter();
    }

    /**
     * 设置 cache expire
     *
     * @param int $nExpireSecond
     * @return void
     */
    public function cacheExpire(string nExpireSecond = null)
    {
        return nExpireSecond ? session_cache_expire(intval(nExpireSecond)) : session_cache_expire();
    }

    /**
     * session_name
     *
     * @param string $sName
     * @return string
     */
    public function sessionName(string sName = null)
    {
        return sName ? session_name(sName) : session_name();
    }

    /**
     * session id
     *
     * @param string $sId
     * @return string
     */
    public function sessionId(string sId = null)
    {
        return sId ? session_id(sId) : session_id();
    }

    /**
     * session 的 cookie_domain 设置
     *
     * @param string $sSessionDomain
     * @return string
     */
    public function cookieDomain(string sSessionDomain = null)
    {
        var sReturn;

        let sReturn = ini_get("session.cookie_domain");

        if sSessionDomain {
            ini_set("session.cookie_domain", sSessionDomain); // 跨域访问 session
        }

        return sReturn;
    }

    /**
     * session 是否使用 cookie
     *
     * @param boolean $bUseCookies
     * @return boolean
     */
    public function useCookies(boolean bUseCookies = null)
    {
        var booReturn;

        let booReturn = ini_get("session.use_cookies") ? true : false;

        if typeof bUseCookies != "null" {
            ini_set("session.use_cookies", bUseCookies ? 1 : 0);
        }

        return booReturn;
    }

    /**
     * 客户端禁用 cookie 可以开启这个项
     *
     * @param string $nUseTransSid
     * @return boolean
     */
    public function useTransSid(int nUseTransSid = null)
    {
        var booReturn;

        let booReturn =  ini_get("session.use_trans_sid") ? true : false;

        if nUseTransSid {
            ini_set("session.use_trans_sid", nUseTransSid ? 1 : 0);
        }

        return booReturn;
    }

    /**
     * 设置过期 cookie lifetime
     *
     * @param int $nCookieLifeTime
     * @return int
     */
    public function cookieLifetime(int nCookieLifeTime)
    {
        var nReturn;

        let nReturn = ini_get("session.cookie_lifetime");

        if intval(nCookieLifeTime) >= 1 {
            ini_set("session.cookie_lifetime", intval(nCookieLifeTime));
        }

        return nReturn;
    }

    /**
     * gc maxlifetime
     *
     * @param int $nGcMaxlifetime
     * @return int
     */
    public function gcMaxlifetime(int nGcMaxlifetime = null)
    {
        var nReturn;

        let nReturn = ini_get("session.gc_maxlifetime");

        if intval(nGcMaxlifetime) >= 1 {
            ini_set("session.gc_maxlifetime", intval(nGcMaxlifetime));
        }

        return nReturn;
    }

    /**
     * session 垃圾回收概率分子 (分母为 session.gc_divisor)
     *
     * @param int $nGcProbability
     * @return int
     */
    public function gcProbability(int nGcProbability = null)
    {
        var nReturn;

        let nReturn =  ini_get("session.gc_probability");

        if intval(nGcProbability) >= 1 && intval(nGcProbability) <= 100 {
            ini_set("session.gc_probability", intval(nGcProbability));
        }

        return nReturn;
    }

    /**
     * 修改单个配置
     *
     * @param string $strName
     * @param mixed $mixValue
     * @return $this
     */
    public function option(string strName, var mixValue)
    {
        if ! is_string(strName) {
            throw new InvalidArgumentException("Option set name must be a string.");
        }
        let this->arrOption[strName] = mixValue;
        return this;
    }

    /**
     * 修改数组配置
     *
     * @param string $strName
     * @param array $arrValue
     * @return $this
     */
    public function optionArray(string $strName, array $arrValue)
    {
        return this->option(strName, array_merge(this->getOption(strName), arrValue));
    }

    /**
     * 修改多个配置
     *
     * @param string $strName
     * @param mixed $mixValue
     * @return $this
     */
    public function options(array $arrOption = [])
    {
    	var strName, mixValue;

        if empty arrOption {
            return this;
        }

        for strName, mixValue in arrOption {
        	this->option(strName, mixValue);
        }

        return this;
    }

    /**
     * 获取单个配置
     *
     * @param string $strName
     * @param mixed $mixDefault
     * @return mixed
     */
    public function getOption(string strName, var mixDefault = null)
    {
        return isset(this->arrOption[strName]) ? this->arrOption[strName] : mixDefault;
    }

    /**
     * 获取所有配置
     *
     * @param array $arrOption
     * @return mixed
     */
    public function getOptions(array arrOption = [])
    {
    	if ! empty arrOption {
    		return array_merge(this->arrOption, arrOption);
    	} else {
    		return this->arrOption;
    	}
    }

    /**
     * 删除单个配置
     *
     * @param string $strName
     * @return $this
     */
    public function deleteOption(string strName)
    {
        if isset this->arrOption[strName] {
            unset(this->arrOption[strName]);
        }

        return this;
    }

    /**
     * 删除多个配置
     *
     * @param array $arrOption
     * @return $this
     */
    public function deleteOptions(array arrOption = [])
    {
    	var strOption;

        if ! empty arrOption {
            return this;
        }

        for strOption in arrOption {
        	this->deleteOption(strOption);
        }

        return this;
    }

    /**
     * 返回 session 名字
     *
     * @param string $sName
     * @return string
     */
    protected function getName(string sName)
    {
        return this->getOption("prefix") . sName;
    }

    /**
     * 验证 session 是否开启
     *
     * @return void
     */
    protected function checkStart()
    {
        if ! this->isStart() {
            throw new RuntimeException("Session is not start yet");
        }
    }

    /**
     * 弹出旧闪存 KEY
     *
     * @param array $arrKey
     * @return void
     */
    protected function popOldFlash(array arrKey)
    {
        this->pop(this->flashOldKey(), arrKey);
    }

    /**
     * 合并旧闪存 KEY
     *
     * @param array $arrKey
     * @return void
     */
    protected function mergeOldFlash(array arrKey)
    {
        this->merge(this->flashOldKey(), arrKey);
    }

    /**
     * 弹出新闪存 KEY
     *
     * @param array $arrKey
     * @return void
     */
    protected function popNewFlash(array arrKey)
    {
        this->pop(this->flashNewKey(), arrKey);
    }

    /**
     * 合并新闪存 KEY
     *
     * @param array $arrKey
     * @return void
     */
    protected function mergeNewFlash(array arrKey)
    {
        this->merge(this->flashNewKey(), arrKey);
    }

    /**
     * 返回部分闪存数据
     *
     * @param string $strKey
     * @param mixed $mixDefault
     * @param string $strType
     * @return mixed
     */
    protected function getPartData(string strKey, var mixDefault = null, string strType = null)
    {
        var strName, mixValue, arrParts, sPart, arrTempKey, strTempKey;

        let arrTempKey = explode("\\", strKey);
        let strTempKey = array_shift(arrTempKey);
        let strKey = strTempKey;
        let strName = array_shift(arrTempKey);
        if strType == "flash" {
			let strKey = this->flashDataKey(strKey);
        }
        let mixValue = this->get(strKey);
        
        if typeof mixValue == "array" {
	        if ! strpos(strName, ".") {
				return array_key_exists(strName, mixValue) ? mixValue[strName] : mixDefault;
			}

            let arrParts = explode(".", strName);
            for sPart in arrParts {
                if ! isset mixValue[sPart] {
                    return mixDefault;
                }
                let mixValue = mixValue[sPart];
            }
            return mixValue;
        } else {
            return mixDefault;
        }
    }

    /**
     * 闪存值 KEY
     *
     * @param string $strKey
     * @return string
     */
    protected function flashDataKey(string strKey)
    {
        return "flash.data." . strKey;
    }

    /**
     * 新值闪存 KEY
     *
     * @return string
     */
    protected function flashNewKey()
    {
        return "flash.new.key";
    }

    /**
     * 旧值闪存 KEY
     *
     * @return string
     */
    protected function flashOldKey()
    {
        return "flash.old.key";
    }

    /**
     * 前一个页面 KEY
     *
     * @return string
     */
    protected function prevUrlKey()
    {
        return "prev.url.key";
    }

    /**
     * call 
     *
     * @param string $sMethod
     * @param array $arrArgs
     * @return mixed
     */
    public function __call(string sMethod, array arrArgs)
    {
        if typeof this->objConnect == "null" {
            throw new BadMethodCallException(sprintf("Method %s is not exits.", sMethod));
        }

        return call_user_func_array([this->objConnect, sMethod], arrArgs);
    }
}
