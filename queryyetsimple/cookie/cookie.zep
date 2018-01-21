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
namespace Queryyetsimple\Cookie;

use Exception;
use InvalidArgumentException;
use Queryyetsimple\Cookie\ICookie;

/**
 * cookie 封装
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.06
 * @version 1.0
 */
class Cookie implements ICookie
{

    /**
     * 配置
     *
     * @var array
     */
    protected option = [
        "prefix" : "q_",
        "expire" : 86400,
        "domain" : "",
        "path" : "/",
        "httponly" : false
    ];

    /**
     * 构造函数
     *
     * @param array $option
     * @return void
     */
    public function __construct(array option = [])
    {
        this->options(option);
    }

    /**
     * 设置 COOKIE
     *
     * @param string $name
     * @param string $value
     * @param array $option
     * @return void
     */
    public function set(string name, var value = "", array option = [])
    {
    	boolean isHttpSecure = false;

        let option = this->getOptions(option);

        if typeof value == "array" {
            let value = json_encode(value);
        }

        if ! is_scalar(value) && ! is_null(value) {
            throw new Exception("Cookie value must be scalar or null");
        }

        let name = option["prefix"] . name;

        if typeof value == "null" || option["expire"] < 0 {
            if isset _COOKIE[name] {
                unset _COOKIE[name];
            }
        } else {
            let _COOKIE[name] = value;
        }

        if option["expire"] > 0 {
        	let option["expire"] = time() + option["expire"];
        } elseif option["expire"] < 0 {
        	let option["expire"] = time() - 31536000;
        } else {
        	let option["expire"] = 0;
        }

        if isset _SERVER["HTTPS"] && strtoupper(_SERVER["HTTPS"]) === "ON" {
        	let isHttpSecure = true;
        }
       
     	setcookie(name, value, option["expire"], option["path"], option["domain"], isHttpSecure, option["httponly"]);
    }

    /**
     * 批量插入
     *
     * @param string|array $keys
     * @param mixed $value
     * @param array $option
     * @return void
     */
    public function put(var keys, var value = null, array option = [])
    {
        var key;
        if typeof keys != "array" {
            let keys = [
                keys : value
            ];
        }

        for key, value in keys {
            this->set(key, value, option);
        }
    }

    /**
     * 数组插入数据
     *
     * @param string $key
     * @param mixed $value
     * @param array $option
     * @return void
     */
    public function push(string key, var value, array option = [])
    {
        var arr;
        let arr = this->get(key, [], option);
        let arr[] = value;
        this->set(key, arr, option);
    }

    /**
     * 合并元素
     *
     * @param string $key
     * @param array $value
     * @param array $option
     * @return void
     */
    public function merge(string key, array value, array option = [])
    {
        this->set(key, array_unique(array_merge(this->get(key, [], option), value)), option);
    }

    /**
     * 弹出元素
     *
     * @param string $key
     * @param mixed $value
     * @param array $option
     * @return void
     */
    public function pop(string key, array value, array option = [])
    {
        this->set(key, array_diff(this->get(key, [], option), value), option);
    }

    /**
     * 数组插入键值对数据
     *
     * @param string $key
     * @param mixed $keys
     * @param mixed $value
     * @param array $option
     * @return void
     */
    public function arrays(string key, var keys, var value = null, array option = [])
    {
        var arr;

        let arr = this->get(key, [], option);

        if typeof keys == "string" {
            let arr[keys] = value;
        } elseif typeof keys == "array" {
            let arr = array_merge(arr, keys);
        }

        this->set(key, arr, option);
    }

    /**
     * 数组键值删除数据
     *
     * @param string $key
     * @param mixed $keys
     * @return void
     */
    public function arraysDelete(string key, var keys, array option = [])
    {
        var arr, tempKey, arrDeleteKey;

        let arr =  this->get(key, [], option);

        if typeof keys != "array" {
            let arrDeleteKey = [
                keys
            ];
        } else {
        	let arrDeleteKey = keys;
        }

        for tempKey in arrDeleteKey {
            if isset arr[tempKey] {
                unset arr[tempKey];
            }
        }

        this->set(key, arr, option);
    }

    /**
     * 获取 cookie
     *
     * @param string $name
     * @param mixed $defaults
     * @param array $option
     * @return mixed
     */
    public function get(string name, var defaults = null, array option = [])
    {
        let option = this->getOptions(option);
        let name = option["prefix"] . name;

        if isset _COOKIE[name] {
            if this->isJson(_COOKIE[name]) {
                return json_decode(_COOKIE[name], true);
            }
            return _COOKIE[name];
        } else {
            return defaults;
        }
    }

    /**
     * 删除 cookie
     *
     * @param string $name
     * @param array $option
     * @return void
     */
    public function delete(string name, array option = [])
    {
        this->set(name, null, option);
    }

    /**
     * 清空 cookie
     *
     * @param boolean $deletePrefix
     * @param array $option
     * @return void
     */
    public function clear(boolean deletePrefix = true, array option = [])
    {
        var prefix, key;
        let option = this->getOptions(option);
        let prefix = option["prefix"];
        let option["prefix"] = "";

        for key, _ in _COOKIE {
            if deletePrefix === true && prefix {
                if strpos(key, prefix) === 0 {
                    this->delete(key, option);
                }
            } else {
                this->delete(key, option);
            }
        }
    }

    /**
     * 修改单个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function option(string name, var value)
    {
        if ! is_string(name) {
            throw new InvalidArgumentException("Option set name must be a string.");
        }
        let this->option[name] = value;
        return this;
    }

    /**
     * 修改数组配置
     *
     * @param string $name
     * @param array $value
     * @return $this
     */
    public function optionArray(string name, array value)
    {
        return this->option(name, array_merge(this->getOption(name), value));
    }

    /**
     * 修改多个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function options(array option = [])
    {
    	var name, value;

        if empty option {
            return this;
        }

        for name, value in option {
        	this->option(name, value);
        }

        return this;
    }

    /**
     * 获取单个配置
     *
     * @param string $name
     * @param mixed $defaults
     * @return mixed
     */
    public function getOption(string name, var defaults = null)
    {
        return isset(this->option[name]) ? this->option[name] : defaults;
    }

    /**
     * 获取所有配置
     *
     * @param array $option
     * @return mixed
     */
    public function getOptions(array option = [])
    {
    	if ! empty option {
    		return array_merge(this->option, option);
    	} else {
    		return this->option;
    	}
    }

    /**
     * 删除单个配置
     *
     * @param string $name
     * @return $this
     */
    public function deleteOption(string name)
    {
        if isset this->option[name] {
            unset(this->option[name]);
        }

        return this;
    }

    /**
     * 删除多个配置
     *
     * @param array $option
     * @return $this
     */
    public function deleteOptions(array option = [])
    {
    	var key;

        if ! empty option {
            return this;
        }

        for key in option {
        	this->deleteOption(key);
        }

        return this;
    }

    /**
     * 验证是否为正常的 JSON 字符串
     *
     * @param mixed $data
     * @return boolean
     */
    protected function isJson(var data)
    {
        if ! is_scalar(data) && ! method_exists(data, "__toString") {
            return false;
        }

        json_decode(data);

        return json_last_error() === JSON_ERROR_NONE;
    }
}
