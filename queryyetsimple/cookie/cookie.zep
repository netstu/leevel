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
use Queryyetsimple\Cookie\Icookie;

/**
 * cookie 封装
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.06
 * @version 1.0
 */
class Cookie implements Icookie
{

    /**
     * 配置
     *
     * @var array
     */
    protected arrOption = [
        "prefix" : "q_",
        "expire" : 86400,
        "domain" : "",
        "path" : "/",
        "httponly" : false
    ];

    /**
     * 构造函数
     *
     * @param array $arrOption
     * @return void
     */
    public function __construct(array arrOption = [])
    {
        this->options(arrOption);
    }

    /**
     * 设置 COOKIE
     *
     * @param string $sName
     * @param string $mixValue
     * @param array $arrOption
     * @return void
     */
    public function set(string sName, var mixValue = "", array arrOption = [])
    {
    	boolean booHttp = false;

        let arrOption = this->getOptions(arrOption);

        if typeof mixValue == "array" {
            let mixValue = json_encode(mixValue);
        }

        if ! is_scalar(mixValue) && ! is_null(mixValue) {
            throw new Exception("Cookie value must be scalar or null");
        }

        let sName = arrOption["prefix"] . sName;

        if typeof mixValue == "null" || arrOption["expire"] < 0 {
            if isset _COOKIE[sName] {
                unset _COOKIE[sName];
            }
        } else {
            let _COOKIE[sName] = mixValue;
        }

        if arrOption["expire"] > 0 {
        	let arrOption["expire"] = time() + arrOption["expire"];
        } elseif arrOption["expire"] < 0 {
        	let arrOption["expire"] = time() - 31536000;
        } else {
        	let arrOption["expire"] = 0;
        }

        if isset _SERVER["HTTPS"] && strtoupper(_SERVER["HTTPS"]) === "ON" {
        	let booHttp = true;
        }
       
     	setcookie(sName, mixValue, arrOption["expire"], arrOption["path"], arrOption["domain"], booHttp, arrOption["httponly"]);
    }

    /**
     * 批量插入
     *
     * @param string|array $mixKey
     * @param mixed $mixValue
     * @param array $arrOption
     * @return void
     */
    public function put(var mixKey, var mixValue = null, array arrOption = [])
    {
        var strKey;
        if typeof mixKey != "array" {
            let mixKey = [
                mixKey : mixValue
            ];
        }

        for strKey, mixValue in mixKey {
            this->set(strKey, mixValue, arrOption);
        }
    }

    /**
     * 数组插入数据
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @param array $arrOption
     * @return void
     */
    public function push(string strKey, var mixValue, array arrOption = [])
    {
        var arr;
        let arr = this->get(strKey, [], arrOption);
        let arr[] = mixValue;
        this->set(strKey, arr, arrOption);
    }

    /**
     * 合并元素
     *
     * @param string $strKey
     * @param array $arrValue
     * @param array $arrOption
     * @return void
     */
    public function merge(string strKey, array arrValue, array arrOption = [])
    {
        this->set(strKey, array_unique(array_merge(this->get(strKey, [], arrOption), arrValue)), arrOption);
    }

    /**
     * 弹出元素
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @param array $arrOption
     * @return void
     */
    public function pop(string strKey, array arrValue, array arrOption = [])
    {
        this->set(strKey, array_diff(this->get(strKey, [], arrOption), arrValue), arrOption);
    }

    /**
     * 数组插入键值对数据
     *
     * @param string $strKey
     * @param mixed $mixKey
     * @param mixed $mixValue
     * @param array $arrOption
     * @return void
     */
    public function arrays(string strKey, var mixKey, var mixValue = null, array arrOption = [])
    {
        var arr;
        let arr = this->get(strKey, [], arrOption);
        if typeof mixKey == "string" {
            let arr[mixKey] = mixValue;
        } elseif typeof mixKey == "array" {
            let arr = array_merge(arr, mixKey);
        }
        this->set(strKey, arr, arrOption);
    }

    /**
     * 数组键值删除数据
     *
     * @param string $strKey
     * @param mixed $mixKey
     * @return void
     */
    public function arraysDelete(string strKey, var mixKey, array arrOption = [])
    {
        var arr, strFoo, arrDeleteKey;
        let arr =  this->get(strKey, [], arrOption);
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

        this->set(strKey, arr, arrOption);
    }

    /**
     * 获取 cookie
     *
     * @param string $sName
     * @param mixed $mixDefault
     * @param array $arrOption
     * @return mixed
     */
    public function get(string sName, var mixDefault = null, array arrOption = [])
    {
        let arrOption = this->getOptions(arrOption);
        let sName = arrOption["prefix"] . sName;

        if isset _COOKIE[sName] {
            if this->isJson(_COOKIE[sName]) {
                return json_decode(_COOKIE[sName], true);
            }
            return _COOKIE[sName];
        } else {
            return mixDefault;
        }
    }

    /**
     * 删除 cookie
     *
     * @param string $sName
     * @param array $arrOption
     * @return void
     */
    public function delete(string sName, array arrOption = [])
    {
        this->set(sName, null, arrOption);
    }

    /**
     * 清空 cookie
     *
     * @param boolean $bOnlyPrefix
     * @param array $arrOption
     * @return void
     */
    public function clear(boolean bOnlyPrefix = true, array arrOption = [])
    {
        var strPrefix, sKey;
        let arrOption = this->getOptions(arrOption);
        let strPrefix = arrOption["prefix"];
        let arrOption["prefix"] = "";

        for sKey, _ in _COOKIE {
            if bOnlyPrefix === true && strPrefix {
                if strpos(sKey, strPrefix) === 0 {
                    this->delete(sKey, arrOption);
                }
            } else {
                this->delete(sKey, arrOption);
            }
        }
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
     * 验证是否为正常的 JSON 字符串
     *
     * @param mixed $mixData
     * @return boolean
     */
    protected function isJson(var mixData)
    {
        if ! is_scalar(mixData) && ! method_exists(mixData, "__toString") {
            return false;
        }

        json_decode(mixData);

        return json_last_error() === JSON_ERROR_NONE;
    }
}
