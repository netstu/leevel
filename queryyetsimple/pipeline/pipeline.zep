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
use Queryyetsimple\Di\IContainer;
use Queryyetsimple\Pipeline\IPipeline;
use Queryyetsimple\Collection\Collection;

/**
 * 管道实现类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.05
 * @version 1.0
 */
class Pipeline implements IPipeline
{

	/**
	 * 容器
	 *
	 * @var \Queryyetsimple\Di\IContainer
	 */
	protected container;

	/**
	 * 管道传递的对象
	 *
	 * @var array
	 */
	protected passed = [];

	/**
	 * 管道中所有执行工序
	 *
	 * @var array
	 */
	protected stage = [];

	/**
	 * 迭代器
	 *
	 * @var \Queryyetsimple\Collection\Collection
	 */
	protected generator;

	/**
	 * 创建一个管道
	 *
	 * @param \Queryyetsimple\Di\IContainer $container
	 * @return void
	 */
	public function __construct(<IContainer> container)
	{
		let this->container = container;
	}

	/**
	 * 将传输对象传入管道
	 *
	 * @param mixed $passed
	 * @return $this
	 */
	public function send(var passed)
	{
		var item;

		let passed = typeof passed == "array" ? passed : func_get_args();
		for item in passed {
			let this->passed[] = item;
		}

		return this;
	}

	/**
	 * 设置管道中的执行工序
	 *
	 * @param dynamic|array $stage
	 * @return $this
	 */
	public function through(var stage)
	{
		var item;

		let stage = typeof stage == "array" ? stage : func_get_args();
		for item in stage {
			let this->stage[] = item;
		}

		return this;
	}

	/**
	 * 执行管道工序响应结果
	 *
	 * @param callable $end
	 * @since 2018.01.03
	 * @return mixed
	 */
	public function then(var end = null)
	{
		var stage;

		let stage = this->stage;
		if (end) {
			if ! is_callable(end) {
				throw new InvalidArgumentException("Pipeline then must be a callable.");
			}
			let stage[] = end;
		} 
		let this->generator = this->stageGenerator(stage);

		return call_user_func_array([this, "traverseGenerator"], this->passed);
	}

	/**
	 * 遍历迭代器
	 *
	 * @since 2018.01.03
	 * @return mixed
	 */
	public function traverseGenerator() {
		var args, current, next;

		if ! this->generator->valid() || this->generator->next() || ! this->generator->valid() {
		   return;
		}

		let args = func_get_args();

		let next = Closure::fromCallable([this, "makeNextClosure"]);

		array_unshift(args, next);

		let current = this->generator->current();
		return call_user_func_array(current, args);
	}

	/**
	 * 下一次迭代执行回调
	 *
	 * @since 2018.01.12
	 * @return mixed
	 */
	protected function makeNextClosure() {
		return call_user_func_array([this, "traverseGenerator"], func_get_args());
	}

	/**
	 * 工序迭代器
	 * 添加一个空的迭代器，第一次迭代 next 自动移除
	 * zephir 不支持 yield，用集合替代
	 *
	 * @param array $stage
	 * @return \Queryyetsimple\Collection\Collection
	 */
	protected function stageGenerator(array stage) {
		var item;

		array temp = [];
		array_unshift(stage, null);
		for item in stage {
			let temp[] = this->stageCallback(item);
		}

		return new Collection(temp);
	}

	/**
	 * 工序回调
	 *
	 * @param mixed $stages
	 * @return null|callable
	 */
	protected function stageCallback(var stages)
	{   
		var stage, params, method, temp;

		if is_null(stages) {
			return;
		}

		if is_callable(stages) {
			return stages;
		} else {
			let temp = this->parse(stages);
			let stage = temp[0];
			let params = temp[1];

			if strpos(stage, "@") !== false {
				let temp = explode("@", stage);
				let stage = temp[0];
				let method = temp[1];
			} else {
				let method = "handle";
			}

			let stage = this->container->make(stage);
			if (stage === false) {
				throw new InvalidArgumentException("Stage is invalid.");
			}

			return [
				stage,
				method
			];
		}
	}

	/**
	 * 解析工序
	 *
	 * @param string $stage
	 * @return array
	 */
	protected function parse(string stage)
	{
		var name, args, temp;

		let temp = array_pad(explode(":", stage, 2), 2, []);
		let name = temp[0];
		let args = temp[1];

		if typeof args == "string" {
			let args = explode(",", args);
		}

		return [
			name,
			args
		];
	}
}
