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
namespace Queryyetsimple\Pipeline;

use Closure;
use Generator;
use InvalidArgumentException;
use Queryyetsimple\Support\Icontainer;
use Queryyetsimple\Pipeline\Ipipeline;
use queryyetsimple\support\collection;

/**
 * 管道实现类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.05
 * @version 1.0
 */
class Pipeline implements Ipipeline
{

	/**
	 * 容器
	 *
	 * @var \queryyetsimple\support\icontainer
	 */
	protected objContainer;

	/**
	 * 管道传递的对象
	 *
	 * @var array
	 */
	protected arrPassed = [];

	/**
	 * 管道中所有执行工序
	 *
	 * @var array
	 */
	protected arrStage = [];

	/**
	 * 迭代器
	 *
	 * @var \queryyetsimple\support\collection
	 */
	protected objGenerator;

	/**
	 * 创建一个管道
	 *
	 * @param \queryyetsimple\support\icontainer $objContainer
	 * @return void
	 */
	public function __construct(<Icontainer> objContainer)
	{
		let this->objContainer = objContainer;
	}

	/**
	 * 将传输对象传入管道
	 *
	 * @param mixed $mixPassed
	 * @return $this
	 */
	public function send(var mixPassed)
	{
		var mixItem;

		let mixPassed = typeof mixPassed == "array" ? mixPassed : func_get_args();
		for mixItem in mixPassed {
			let this->arrPassed[] = mixItem;
		}

		return this;
	}

	/**
	 * 设置管道中的执行工序
	 *
	 * @param dynamic|array $mixStage
	 * @return $this
	 */
	public function through(var mixStage)
	{
		var mixItem;

		let mixStage = typeof mixStage == "array" ? mixStage : func_get_args();
		for mixItem in mixStage {
			let this->arrStage[] = mixItem;
		}

		return this;
	}

	/**
	 * 执行管道工序响应结果
	 *
	 * @param callable $calEnd
	 * @since 2018.01.03
	 * @return void
	 */
	public function then(var calEnd)
	{
		var arrStage; 

		if ! is_callable(calEnd) {
			throw new InvalidArgumentException("Pipeline then must be a callable.");
		}

		let arrStage = this->arrStage;
		let arrStage[] = calEnd;
		let this->objGenerator = this->stageGenerator(arrStage);

		call_user_func_array([this, "traverseGenerator"], this->arrPassed);
	}

	/**
	 * 遍历迭代器
	 *
	 * @since 2018.01.03
	 * @return void
	 */
	protected function traverseGenerator() {
		var aArgs, calCurrent;

		if ! this->objGenerator->valid() || this->objGenerator->next() || ! this->objGenerator->valid() {
		   return;
		}

		let aArgs = func_get_args();
		array_unshift(aArgs, function() {
			call_user_func_array([this, "traverseGenerator"], func_get_args());
		});

		let calCurrent = this->objGenerator->current();
		call_user_func_array(calCurrent, aArgs);
	}

	/**
	 * 工序迭代器
	 * 添加一个空的迭代器，第一次迭代 next 自动移除
	 * zephir 不支持 yield，用集合替代
	 *
	 * @param array $arrStage
	 * @return \queryyetsimple\support\collection
	 */
	protected function stageGenerator(array arrStage) {
		array_unshift(arrStage, null);
		return new collection(arrStage);
	}

	/**
	 * 工序回调
	 *
	 * @param mixed $mixStage
	 * @return null|callable
	 */
	protected function stageCallback(var mixStage)
	{   
		var strStage, arrParams, strMethod, objStage, tempArray;

		if is_null(mixStage) {
			return;
		}

		if is_callable(mixStage) {
			return mixStage;
		} else {
			let tempArray = this->parse(mixStage);
			let strStage = tempArray[0];
			let arrParams = tempArray[1];

			if strpos(strStage, "@") !== false {
				let tempArray = explode("@", strStage);
				let strStage = tempArray[0];
				let strMethod = tempArray[1];
			} else {
				let strMethod = "handle";
			}

			let objStage = this->objContainer->make(strStage);
			if (objStage === false) {
				throw new InvalidArgumentException(sprintf("Stage %s is not valid.", strStage));
			}

			return [
				objStage,
				strMethod
			];
		}
	}

	/**
	 * 解析工序
	 *
	 * @param string $strStage
	 * @return array
	 */
	protected function parse(string strStage)
	{
		var strName, arrArgs, tempArray;

		let tempArray = array_pad(explode(":", strStage, 2), 2, []);
		let strName = tempArray[0];
		let arrArgs = tempArray[1];

		if typeof arrArgs == "string" {
			let arrArgs = explode(",", arrArgs);
		}

		return [
			strName,
			arrArgs
		];
	}
}
