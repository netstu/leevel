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
namespace Queryyetsimple\Event;

use RuntimeException;
use Queryyetsimple\Di\IContainer;

/**
 * 事件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.31
 * @version 1.0
 */
class Dispatch implements IDispatch
{

	/**
	 * 项目容器
	 *
	 * @var \Queryyetsimple\Di\IContainer
	 */
	protected container;
	
	/**
	 * 注册的监听器
	 *
	 * @var array
	 */
	protected listeners = [];
	
	/**
	 * 通配符的监听器
	 *
	 * @var array
	 */
	protected wildcards = [];
	
	/**
	 * 通配符是否严格匹配
	 *
	 * @var boolean
	 */
	protected strict = false;
	
	/**
	 * 创建一个事件解析器
	 *
	 * @param \Queryyetsimple\Di\IContainer $container
	 * @param bool $event
	 * @return void
	 */
	public function __construct(<IContainer> container, boolean strict = false)
	{
		let this->container = container;
		let this->strict = strict;
	}
	
	/**
	 * 执行一个事件
	 *
	 * @return void
	 */
	public function run()
	{
		var event, objects, listeners, items, params = [];

		let params = func_get_args();
		let event = array_shift(params);
	
		if is_object(event) {
			let objects = event;
			let event = get_class(event);
		} else {
			let objects = this->container->make(event);
			if ! (is_object(objects)) {
				throw new RuntimeException(sprintf("Event %s is invalid.", event));
			}
		}

		array_unshift(params, objects);

		if ! (this->hasListeners(event)) {
			return;
		}

		let listeners = this->getListeners(event);
		ksort(listeners);

		for items in listeners {
			let items = this->makeSubject(items);
			call_user_func_array([items, "notify"], params);
		}
	}
	
	/**
	 * 注册监听器
	 *
	 * @param string|array $event
	 * @param mixed $listener
	 * @param int $priority
	 * @return void
	 */
	public function listeners(var event, var listener, int priority = 500)
	{
		var item, temp = [];

		if typeof event != "array" {
			let temp[] = event;
			let event = temp;
		}
		let priority = intval(priority);

		for item in event {
			if strpos(item, "*") !== false {
				let this->wildcards[item][priority][] = listener;
			} else {
				let this->listeners[item][priority][] = listener;
			}
		}
	}
	
	/**
	 * 获取一个事件监听器
	 *
	 * @param string $event
	 * @return array
	 */
	public function getListeners(string event) -> array
	{
		var listeners, key, item, priority, value, res;
	
		let listeners = [];

		if isset this->listeners[event] {
			let listeners = this->listeners[event];
		}

		for key, item in this->wildcards {
			let key = this->prepareRegexForWildcard(key, this->strict);
			let event = str_replace("\\", "\\\\", event);

			let res = null;
			if preg_match(key, event, res) {
				for priority, value in item {
					if ! (isset listeners[priority]) {
						let listeners[priority] = [];
					}

					let listeners[priority] = array_merge(listeners[priority], value);
				}
			}
		}

		return listeners;
	}
	
	/**
	 * 判断事件监听器是否存在
	 *
	 * @param string $event
	 * @return bool
	 */
	public function hasListeners(string event) -> bool
	{
		return isset this->listeners[event] || isset this->wildcards[event];
	}
	
	/**
	 * 删除一个事件所有监听器
	 *
	 * @param string $event
	 * @return void
	 */
	public function deleteListeners(string event)
	{
		if isset this->listeners[event] {
			unset this->listeners[event];
		}

		if isset this->wildcards[event] {
			unset this->wildcards[event];
		}
	}
	
	/**
	 * 设置是否严格匹配事件
	 *
	 * @param bool $event
	 * @return $this
	 */
	public function strict(boolean strict)
	{
		let this->strict = strict;
		return this;
	}
	
	/**
	 * 创建监听器观察者角色主体
	 *
	 * @param string $listeners
	 * @return \Queryyetsimple\Event\Subject
	 */
	protected function makeSubject(array listeners)
	{
		var subject, item;
	
		let subject = new Subject(this->container);

		for item in listeners {
			subject->attachs(item);
		}

		return subject;
	}
	
	/**
	 * 通配符正则
	 *
	 * @param string $strFoo
	 * @param bool $strict
	 * @return string
	 */
	protected function prepareRegexForWildcard(regex, boolean strict = true) -> string
	{
		return "/^" . str_replace("6084fef57e91a6ecb13fff498f9275a7", "(\\S+)", this->escapeRegexCharacter(str_replace("*", "6084fef57e91a6ecb13fff498f9275a7", regex))) . ( strict ? "$" : "") . "/";
	}
	
	/**
	 * 转移正则表达式特殊字符
	 *
	 * @param string $txt
	 * @return string
	 */
	protected function escapeRegexCharacter(string txt) -> string
	{
		var tmp, tmp1;
	
		let tmp = [
			"$", 
			"/", 
			"?", 
			"*", 
			".", 
			"!", 
			"-", 
			"+", 
			"(", 
			")", 
			"[", 
			"]", 
			",", 
			"{", 
			"}", 
			"|", 
			"\\"
		];

		let tmp1 = [
			"\\$", 
			"\\/", 
			"\\?", 
			"\\*", 
			"\\.", 
			"\\!", 
			"\\-", 
			"\\+", 
			"\\(", 
			"\\)", 
			"\\[", 
			"\\]", 
			"\\,", 
			"\\{", 
			"\\}", 
			"\\|", 
			"\\\\\\\\"
		];

		let txt = str_replace(tmp, tmp1, txt);

		return txt;
	}
}
