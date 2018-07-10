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

use RuntimeException;
use BadMethodCallException;
use SessionHandlerInterface;
use Leevel\Session\ISession;

/**
 * session 仓储
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.09
 * @version 1.0
 */
class Session implements ISession
{

	/**
     * session handler 
     *
     * @var \SessionHandlerInterface|null
     */
    protected connect;

    /**
     * session 是否开启
     *
     * @var boolean
     */
    protected started = false;

    /**
     * 配置
     *
     * @var array
     */
    protected option = [
        "default" : null,
        "prefix" : "q_",
        "id" : null,
        "name" : null,
        "cookie_domain" : null,
        "cache_limiter" : null,
        "expire" : 86400,
        "save_path" : null,
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
     * @param \SessionHandlerInterface|null $connect
     * @param array $option
     * @return void
     */
    public function __construct(<SessionHandlerInterface> connect = null, array option = [])
    {
        let this->connect = connect;

        let this->option = array_merge(this->option, option);
    }

    /**
     * 修改单个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function setOption(string name, var value)
    {
        let this->option[name] = value;
        
        return this;
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
        ini_set("session.auto_start", "0");

        // 设置 session id
        if this->option["id"] {
        	this->setId(this->option["id"]);
        }

        // session name
        if this->option["name"] {
            this->setName(this->option["name"]);
        }

        // cookie set
        this->setUseCookies(); 

        // save path
        if this->option["save_path"] {
            this->setSavePath(this->option["save_path"]);
        }
        
        // cookie domain
        if this->option["cookie_domain"] {
            this->setCookieDomain(this->option["cookie_domain"]);
        }

        // session expire
        if this->option["expire"] {
            this->setCacheExpire(this->option["expire"]);
        }

        // cache limiter
        if this->option["cache_limiter"] {
            this->setCacheLimiter(this->option["cache_limiter"]);
        }

        // gc_probability
        if this->option["gc_probability"] {
            this->setGcProbability(this->option["gc_probability"]);
        }

        // 驱动
        if this->connect && ! session_set_save_handler(this->connect) {
            throw new RuntimeException(
                sprintf("Session drive %s settings failed.", get_class(this->connect))
            );
        }

        // 启动 session
        if ! session_start() {
            throw new RuntimeException("Session start failed");
        }

        let this->started = true;

		return this;
    }

    /**
     * 设置 session
     *
     * @param string $name
     * @param mxied $value
     * @return void
     */
    public function set(string name, var value)
    {
        this->checkStart();

        let name = this->getNormalizeName(name);
        let _SESSION[name] = value;
    }

    /**
     * 批量插入
     *
     * @param string|array $keys
     * @param mixed $value
     * @return void
     */
    public function put(var keys, var value = null)
    {
        var item;

        this->checkStart();

        if typeof keys != "array" {
            let keys = [
                keys : value
            ];
        }

        for item, value in keys {
            this->set(item, value);
        }
    }

    /**
     * 数组插入数据
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function push(string key, var value)
    {
        var arr;

        let arr = this->get(key, []);
        let arr[] = value;

        this->set(key, arr);
    }

    /**
     * 合并元素
     *
     * @param string $key
     * @param array $value
     * @return void
     */
    public function merge(string key, array value)
    {
        this->set(key, array_unique(array_merge(this->get(key, []), value)));
    }

    /**
     * 弹出元素
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function pop(string key, array value)
    {
        this->set(key, array_diff(this->get(key, []), value));
    }

    /**
     * 数组插入键值对数据
     *
     * @param string $key
     * @param mixed $keys
     * @param mixed $value
     * @return void
     */
    public function arr(string key, var keys, var value = null)
    {
        var arr;

        let arr = this->get(key, []);

        if typeof keys == "string" {
            let arr[keys] = value;
        } elseif typeof keys == "array" {
            let arr = array_merge(arr, keys);
        }

        this->set(key, arr);
    }

    /**
     * 数组键值删除数据
     *
     * @param string $key
     * @param mixed $keys
     * @return void
     */
    public function arrDelete(string key, var keys)
    {
        var arr, item, deleteKey;

        let arr = this->get(key, []);

        if typeof keys != "array" {
            let deleteKey = [
                keys
            ];
        } else {
        	let deleteKey = keys;
        }

        for item in deleteKey {
            if isset arr[item] {
                unset arr[item];
            }
        }

        this->set(key, arr);
    }

    /**
     * 取回 session
     *
     * @param string $name
     * @param mixed $value
     * @return mxied
     */
    public function get(string name, var value = null)
    {
        this->checkStart();

        let name = this->getNormalizeName(name);

        return isset _SESSION[name] ? _SESSION[name] : value;
    }

    /**
     * 返回数组部分数据
     *
     * @param string $name
     * @param mixed $value
     * @return mixed
     */
    public function getPart(string name, var value = null) {
    	return this->getPartData(name, value);
    }

    /**
     * 删除 session
     *
     * @param string $name
     * @param boolean $prefix
     * @return bool
     */
    public function delete(string name, boolean prefix = true)
    {
        this->checkStart();

        if prefix {
            let name = this->getNormalizeName(name);
        }

        if isset _SESSION[name] {
            unset _SESSION[name];
        }

        return true;
    }

    /**
     * 是否存在 session
     *
     * @param string $name
     * @return boolean
     */
    public function has(string name)
    {
        this->checkStart();

        let name = this->getNormalizeName(name);

        return isset _SESSION[name];
    }

    /**
     * 删除 session
     *
     * @param boolean $prefix
     * @return void
     */
    public function clear(boolean prefix = true)
    {
        var strPrefix, sKey;

        this->checkStart();

        let strPrefix = this->option["prefix"];

        for sKey, _ in _SESSION {
            if prefix === true && strPrefix && strpos(sKey, strPrefix) === 0 {
                this->delete(sKey, false);
            } else {
                this->delete(sKey, false);
            }
        }
    }

    /**
     * 闪存一个数据，当前请求和下一个请求可用
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function flash(string key, var value = null)
    {
        if typeof value == "null" {
            return this->getFlash(key);
        } else {
            this->set(this->flashDataKey(key), value);

            this->mergeNewFlash([
                key
            ]);

            this->popOldFlash([
                key
            ]);
        }
    }

    /**
     * 批量闪存数据，当前请求和下一个请求可用
     *
     * @param array $flash
     * @return void
     */
    public function flashs(array flash)
    {
        var item, value;

        for item, value in flash {
            this->flash(item, value);
        }
    }

    /**
     * 闪存一个 flash 用于当前请求使用，下一个请求将无法获取
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function nowFlash(string key, var value)
    {
        this->set(this->flashDataKey(key), value);

        this->mergeOldFlash([
            key
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
     * @return void
     */
    public function keepFlash()
    {
    	var keys, args = [];

		let args = func_get_args();

		if empty args {
			throw new BadMethodCallException("Wrong number of parameters");
		}

        let keys = typeof args[0] === "array" ? keys : args;

        this->mergeNewFlash(keys);
        this->popOldFlash(keys);
    }

    /**
     * 返回闪存数据
     *
     * @param string $key
     * @param mixed $defaults
     * @return mixed
     */
    public function getFlash(string key, var defaults = null)
    {
        if strpos(key, "\\") !== false {
            return this->getPartData(key, defaults, "flash");
        } else {
            return this->get(this->flashDataKey(key), defaults);
        }
    }

    /**
     * 删除闪存数据
     *
     * @return void
     */
    public function deleteFlash()
    {
        var item, keys, args = [];

		let args = func_get_args();

		if empty args {
			throw new BadMethodCallException("Wrong number of parameters");
		}

        let keys = typeof args[0] === "array" ? keys : args;

        for item in keys {
            this->delete(this->flashDataKey(item));
        }

        this->mergeOldFlash(keys);
        this->popNewFlash(keys);
    }

    /**
     * 清理所有闪存数据
     *
     * @return void
     */
    public function clearFlash()
    {
        var item, newKey;

        let newKey = this->get(this->flashNewKey(), []);

        for item, _ in newKey {
            call_user_func([this, "deleteFlash"], item);
        }
    }

    /**
     * 程序执行结束清理 flash
     *
     * @return void
     */
    public function unregisterFlash()
    {
        var arr, old, item;

        if this->isStart() {
            let arr = this->get(this->flashNewKey(), []);
            let old = this->get(this->flashOldKey(), []);

            for item in old {
                this->delete(this->flashDataKey(item));
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
     * @param string $url
     * @return void
     */
    public function setPrevUrl(string url)
    {
        return this->set(this->prevUrlKey(), url);
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
    	var name;

        this->checkStart();

        this->clear(false);

        let name = this->getName();

        if isset _COOKIE[name] {
            setcookie(name, "", time() - 42000, "/");
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
    	return this->started;
    }

    /**
     * session 状态
     *
     * @return int
     */
    public function status(){
    	var status;

        let status = session_status();

        switch status {
            case PHP_SESSION_DISABLED:
                return self::SESSION_DISABLED;

            case PHP_SESSION_ACTIVE:
                return self::SESSION_ACTIVE;
        }

        return self::SESSION_NONE;
    }

    /**
	 * 设置 SESSION 名字
	 *
	 * @param string $name
	 * @return void
	 */
	public function setName(string name)
	{
	    session_name(name);
	}

	/**
	 * 取得 SESSION 名字
	 *
	 * @return string
	 */
	public function getName() -> string
	{
	    return session_name();
	}

	/**
	 * 设置 SESSION ID
	 *
	 * @param string $name
	 * @return void
	 */
	public function setId(string id)
	{
		session_id(id);
	}

	/**
	 * 取得 SESSION ID
	 *
	 * @return string
	 */
	public function getId() -> string
	{
		return session_id();
	}

	/**
     * 重新生成 SESSION ID
     * 
     * @param bool $deleteOldSession
     * @return $this
     */
    public function regenerateId(bool deleteOldSession = true)
    {
        session_regenerate_id(deleteOldSession);

        return this;
    }

    /**
     * 设置 save path
     *
     * @param string $savepath
     * @return void
     */
    public function setSavePath(string savepath)
    {
        session_save_path(savepath);
    }

    /**
     * 获取 save path
     *
     * @return string
     */
    public function getSavePath()
    {
        return session_save_path();
    }

    /**
     * 设置 cookie_domain
     *
     * @param string $domain
     * @return void
     */
    public function setCookieDomain(string domain)
    {
        ini_set("session.cookie_domain", domain);
    }

    /**
     * 获取 cookie_domain
     *
     * @return string
     */
    public function getCookieDomain()
    {
        var result;

        let result = ini_get("session.cookie_domain");

        return result;
    }

    /**
     * 设置 cache expire
     *
     * @param int $second
     * @return void
     */
    public function setCacheExpire(int second)
    {
    	let second = strval(second);

		ini_set("session.gc_maxlifetime", second);
        ini_set("session.cookie_lifetime", second);
    }

    /**
     * session 使用 cookie
     *
     * @return boolean
     */
    public function setUseCookies()
    {
        ini_set("session.use_cookies", "1");
	    ini_set("session.use_trans_sid", "0");
    }

    /**
     * 设置 cache limiter
     *
     * @param string $limiter
     * @return void
     */
    public function setCacheLimiter(string limiter)
    {
        session_cache_limiter(limiter);
    }

    /**
     * 获取 cache limiter
     *
     * @return string
     */
    public function getCacheLimiter()
    {
        return session_cache_limiter();
    }

    /**
     * 设置 session 垃圾回收概率分子
     * 分母为 session.gc_divisor
     *
     * @param int $probability
     * @return void
     */
    public function setGcProbability(int probability)
    {
    	let probability = strval(probability);

        if probability >= 1 && probability <= 100 {
            ini_set("session.gc_probability", probability);
        }
    }

    /**
     * 获取 session 垃圾回收概率分子
     * 分母为 session.gc_divisor
     *
     * @return int
     */
    public function getGcProbability()
    {
        var result;

        let result = ini_get("session.gc_probability");

        return result;
    }

    /**
     * 返回 session 名字
     *
     * @param string $name
     * @return string
     */
    protected function getNormalizeName(string name)
    {
        return this->option["prefix"] . name;
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
     * @param array $keys
     * @return void
     */
    protected function popOldFlash(array keys)
    {
        this->pop(this->flashOldKey(), keys);
    }

    /**
     * 合并旧闪存 KEY
     *
     * @param array $keys
     * @return void
     */
    protected function mergeOldFlash(array keys)
    {
        this->merge(this->flashOldKey(), keys);
    }

    /**
     * 弹出新闪存 KEY
     *
     * @param array $keys
     * @return void
     */
    protected function popNewFlash(array keys)
    {
        this->pop(this->flashNewKey(), keys);
    }

    /**
     * 合并新闪存 KEY
     *
     * @param array $keys
     * @return void
     */
    protected function mergeNewFlash(array keys)
    {
        this->merge(this->flashNewKey(), keys);
    }

    /**
     * 返回部分闪存数据
     *
     * @param string $key
     * @param mixed $defaults
     * @param string $type
     * @return mixed
     */
    protected function getPartData(var key, var defaults = null, var type = null)
    {
        var name, value, parts, part, tempkeys, tempkey;

        let tempkeys = explode("\\", key);
        let tempkey = array_shift(tempkeys);
        let key = tempkey;
        let name = array_shift(tempkeys);
        if type == "flash" {
			let key = this->flashDataKey(key);
        }
        let value = this->get(key);
        
        if typeof value == "array" {
	        if ! strpos(name, ".") {
				return array_key_exists(name, value) ? value[name] : defaults;
			}

            let parts = explode(".", name);
            for part in parts {
                if ! isset value[part] {
                    return defaults;
                }
                let value = value[part];
            }
            
            return value;
        } else {
            return defaults;
        }
    }

    /**
     * 闪存值 KEY
     *
     * @param string $key
     * @return string
     */
    protected function flashDataKey(string key)
    {
        return "flash.data." . key;
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
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function __call(string method, array args)
    {
        if typeof this->connect == "null" {
            throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
        }

        return call_user_func_array([this->connect, method], args);
    }
}
