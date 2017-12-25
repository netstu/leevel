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
namespace Queryyetsimple\Option;

use ArrayAccess;
use Queryyetsimple\Option\Ioption;

/**
 * 配置管理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
class Option implements ArrayAccess, Ioption
{

	/**
	 * 配置数据
	 *
	 * @var array
	 */
	protected arrOption = [];

	/**
	 * 默认命名空间
	 *
	 * @var string
	 */
	const DEFAUTL_NAMESPACE = "app";

	/**
	 * 构造函数
	 *
	 * @param array $arrOptions
	 * @return void
	 */
	public function __construct(array arrOptions = [])
	{
		let this->arrOption = arrOptions;
	}

	/**
	 * 是否存在配置
	 *
	 * @param string $sName 配置键值
	 * @return string
	 */
	public function has(string sName = "app\\")
	{
		var sTempName, arrName, strNamespace, arrParts, sPart, arrOption;

		let arrName = this->parseNamespace(sName);
		let strNamespace = arrName[0];
		let sTempName = arrName[1];
		let sName = sTempName;

		if sName == "*" {
			return isset(this->arrOption[strNamespace]);
		}

		if ! strpos(sName, ".") {
			return array_key_exists(sName, this->arrOption[strNamespace]);
		}

		let arrParts = explode(".", sName);
		let arrOption = this->arrOption[strNamespace];
		for sPart in arrParts {
			if ! isset arrOption[sPart] {
				return false;
			}
			let arrOption = arrOption[sPart];
		}
		return true;
	}

	/**
	 * 获取配置
	 *
	 * @param string $sName 配置键值
	 * @param mixed $mixDefault 配置默认值
	 * @return string
	 */
	public function get(string sName = "app\\", var mixDefault = null)
	{
		var sTempName, arrName, strNamespace, arrParts, sPart, arrOption;

		let arrName = this->parseNamespace(sName);
		let strNamespace = arrName[0];
		let sTempName = arrName[1];
		let sName = sTempName;

		if sName == "*" {
			return this->arrOption[strNamespace];
		}

		if ! strpos(sName, ".") {
			return array_key_exists(sName, this->arrOption[strNamespace]) ? this->arrOption[strNamespace][sName] : mixDefault;
		}

		let arrParts = explode(".", sName);
		let arrOption = this->arrOption[strNamespace];
		for sPart in arrParts {
			if ! isset arrOption[sPart] {
				return mixDefault;
			}
			let arrOption = arrOption[sPart];
		}
		return arrOption;
	}

	/**
	 * 返回所有配置
	 *
	 * @return array
	 */
	public function all()
	{
		return this->arrOption;
	}

	/**
	 * 设置配置
	 *
	 * @param mixed $mixName 配置键值
	 * @param mixed $mixValue 配置值
	 * @return array
	 */
	public function set(var mixName, var mixValue = null)
	{
		var sTempName, sKey, mixValues, sName, arrName, strNamespace, arrParts, arrOption;

		if typeof mixName == "array" {
			for sKey,mixValues in mixName {
				this->set(sKey, mixValues);
			}
		} else {
			let arrName = this->parseNamespace(mixName);
			let strNamespace = arrName[0];
			let sTempName = arrName[1];
			let sName = sTempName;

			if sName == "*" {
				let this->arrOption[strNamespace] = mixValue;
				return;
			}

			if ! strpos(sName, ".") {
				let this->arrOption[strNamespace][mixName] = mixValue;
			} else {
				let arrParts = explode(".", sName);
				let arrOption = this->setRecursion(arrParts ,mixValue);
				let this->arrOption[strNamespace] = array_merge(this->arrOption[strNamespace], arrOption);
			}
		}
	}

	/**
	 * 删除配置
	 *
	 * @param string $sName 配置键值
	 * @return string
	 */
	public function delete(string sName)
	{
		var sTempName, sName, arrName, strNamespace, arrParts, arrOption;

		let arrName = this->parseNamespace(sName);
		let strNamespace = arrName[0];
		let sTempName = arrName[1];
		let sName = sTempName;

		if sName == "*" {
			let this->arrOption[strNamespace] = [];
			return;
		}

		if ! strpos(sName, ".") {
			if isset this->arrOption[strNamespace][sName] {
				unset(this->arrOption[strNamespace][sName]);
			}
		} else {
			let arrParts = explode(".", sName);
			let arrOption = this->deleteRecursion(arrParts, this->arrOption[strNamespace]);
			let this->arrOption[strNamespace] = arrOption;		
		}
	}

	/**
	 * 初始化配置参数
	 *
	 * @param mixed $mixNamespace
	 * @return boolean
	 */
	public function reset(var mixNamespace = null)
	{
		if typeof mixNamespace == "array" {
			let this->arrOption = mixNamespace;
		} elseif typeof mixNamespace == "string" {
			if isset this->arrOption[mixNamespace] {
				let this->arrOption[mixNamespace] = [];
			}
		} else {
			let this->arrOption = [];
		}

		return true;
	}

	/**
	 * 判断配置是否存在
	 *
	 * @param string $strName
	 * @return bool
	 */
	public function offsetExists(string strName)
	{
		return this->has(strName);
	}

	/**
	 * 获取配置
	 *
	 * @param string $strName
	 * @return mixed
	 */
	public function offsetGet(string strName)
	{
		return this->get(strName);
	}

	/**
	 * 设置配置
	 *
	 * @param string $strName
	 * @param mixed $mixValue
	 * @return void
	 */
	public function offsetSet(string strName, mixValue)
	{
		return this->set(strName, mixValue);
	}

	/**
	 * 删除配置
	 *
	 * @param string $strName
	 * @return void
	 */
	public function offsetUnset(string strName)
	{
		this->delete(strName);
	}

	/**
	 * 递归设置配置数据
	 *
	 * @param array $arrPart
	 * @param mixed $mixValue
	 * @return array
	 */
	protected function setRecursion(array! arrPart, var mixValue = null) -> array
	{
		var arrResult = [], sItem;

		let sItem = array_shift(arrPart);
        if ! isset arrResult[sItem] {
            let arrResult[sItem] = [];
        }

        if !empty arrPart {
            let arrResult[sItem] = this->setRecursion(arrPart, mixValue);
        } else {
            let arrResult[sItem] = mixValue;
        }

        return arrResult;
	}

	/**
	 * 递归删除配置数据
	 *
	 * @param array $arrPart
	 * @return array
	 */
	protected function deleteRecursion(array! arrPart, array! arrResult) -> array
	{
		var sItem;

		let sItem = array_shift(arrPart);
        if ! isset arrResult[sItem] {
            return arrResult;
        }

        if !empty arrPart {
            let arrResult[sItem] = this->deleteRecursion(arrPart, arrResult[sItem]);
        } else {
        	if isset arrResult[sItem] {
				unset(arrResult[sItem]);
        	}
        }

        return arrResult;
	}

	/**
	 * 分析命名空间
	 *
	 * @param string $strName
	 * @return array
	 */
	protected function parseNamespace(string strName)
	{
		var arrName, sTempName, strNamespace;

		if strpos(strName, "\\") {
			let arrName = explode("\\", strName);
			if empty arrName[1] {
				let arrName[1] = "*";
			}
			let sTempName = arrName[1];
			let strName = sTempName;
			let strNamespace = arrName[0];
		} else {
			let strNamespace = self::DEFAUTL_NAMESPACE;
		}

		if ! isset this->arrOption[strNamespace] {
			let this->arrOption[strNamespace] = [];
		}

		return [
			strNamespace,
			strName
		];
	}
}
