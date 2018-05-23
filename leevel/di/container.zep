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
namespace Leevel\Di;

use Closure;
use ArrayAccess;
use ReflectionClass;
use ReflectionMethod;
use ReflectionFunction;
use ReflectionException;
use ReflectionParameter;
use BadMethodCallException;
use InvalidArgumentException;
use Leevel\Support\ClosureUse;

/**
 * IOC 容器
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.24
 * @version 1.0
 */
class Container implements IContainer, ArrayAccess {
	
	/**
	 * 注册服务
	 *
	 * @var array
	 */
	protected services = [];

	/**
	 * 注册的实例
	 *
	 * @var array
	 */
	protected instances = [];

	/**
	 * 单一实例
	 *
	 * @var array
	 */
	protected singletons = [];

	/**
	 * 别名支持
	 *
	 * @var array
	 */
	protected alias = [];

	/**
	 * share 静态变量值
	 *
	 * @var array
	 */
	protected shareClosure = [];

	/**
	 * share 传递闭包参数
	 *
	 * @var \Closure
	 */
	protected shareUseClosures;

	/**
	 * 注册到容器
	 *
	 * @param mixed $name
	 * @param mixed $service
	 * @param boolean $share
	 * @return $this
	 */
	public function bind(var name, var service = null, boolean share = false)
	{
		var alias;

		if typeof name == "array" {
			var templist = this->parseAlias(name);
			let name = array_shift(templist);
			let alias = array_shift(templist);
			this->alias(name, alias);
		}

		if is_null(service) {
			let service = name;
		}

		let this->services[name] = service;

		if share {
			let this->singletons[] = name;
		}

		return this;
	}

	/**
	 * 注册为实例
	 *
	 * @param mixed $name
	 * @param mixed $service
	 * @return $this
	 */
	public function instance(var name, var service = null)
	{
		var alias;

		if typeof name == "array" {
			var templist = this->parseAlias(name);
			let name = array_shift(templist);
			let alias = array_shift(templist);
			this->alias(name, alias);
		}

		if is_null(service) {
			let service = name;
		}
		let this->instances[name] = service;

		return this;
	}

	/**
	 * 注册单一实例
	 *
	 * @param scalar|array $name
	 * @param mixed $service
	 * @return $this
	 */
	public function singleton(var name, var service = null)
	{
		return this->bind(name, service, true);
	}

	/**
	 * 创建共享的闭包
	 *
	 * @param \Closure $closures
	 * @return \Closure
	 */
	public function share(<Closure> closures)
	{
		let this->shareUseClosures = closures;

		return Closure::fromCallable([this, "shareClosure"]);
	}

	/**
     * 创建 share 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return mixed
     */
    protected function shareClosure(var container)
    {
    	var hash, obj;

    	let hash = spl_object_hash(this->shareUseClosures);

		if fetch obj, this->shareClosure[hash] {
			return obj;
		}

		let obj = call_user_func(this->shareUseClosures, container);
		let this->shareClosure[hash] = obj;

		return obj;
    }

	/**
	 * 设置别名
	 *
	 * @param array|string $alias
	 * @param string|null|array $value
	 * @return $this
	 */
	public function alias(var alias, var value = null)
	{
		var key, item;

		if typeof alias == "array" {
			for key,item in alias {
				if typeof key == "integer" {
					continue;
				}
				this->alias(key, item);
			}
		} else {
			let value = (array) value;
			for item in value {
				let this->alias[item] = alias;
			}
		}

		return this;
	}

	/**
	 * 服务容器返回对象
	 *
	 * @param string $name
	 * @param array $args
	 * @return object|false
	 */
	public function make(var name, array args = [])
	{
		var instance;

		// 别名
		let name = this->getAlias(name);

		// 存在直接返回
		if (isset this->instances[name]) {
			return this->instances[name];
		}

		// 生成实例
		if ! isset this->services[name] {
			return this->getInjectionObject(name, args);
		}
 
		if typeof this->services[name] != "string" && is_callable(this->services[name]) {
			if empty args {
				let args = [];
			}
			array_unshift(args, this);

			let instance = call_user_func_array(this->services[name], args);
		} else {
			if typeof this->services[name] == "string" {
				let instance = this->getInjectionObject(this->services[name], args);
			} else {
				let instance = this->services[name];
			}
		}

		// 单一实例
		if in_array(name, this->singletons) {
			let this->instances[name] = instance;
			return this->instances[name] ;
		}

		// 多个实例
		else {
			return instance;
		}
	}

	/**
	 * 实例回调自动注入
	 *
	 * @param callable $callback
	 * @param array $args
	 * @return mixed
	 */
	public function call(var callback, array args = [])
	{
		var temp = [];

		if empty args {
			let temp = this->parseInjection(callback);
		} else {
			let temp = args;
		}

		return call_user_func_array(callback, temp);
	}

	/**
	 * 统一去掉前面的斜杠
	 *
	 * @param string $name
	 * @return mixed
	 */
	protected function normalize(var name)
	{
		return ltrim(name, "\\");
	}

	/**
	 * 返回对象别名
	 *
	 * @param string $name
	 * @return string
	 */
	protected function getAlias(var name)
	{
		return (isset this->alias[name]) ? this->alias[name] : name;
	}

	/**
	 * 根据 class 名字创建实例
	 *
	 * @param string $classname
	 * @param array $args
	 * @return object
	 */
	protected function getInjectionObject(var classname, array args = [])
	{
		var temp = [];

		if ! class_exists(classname) {
			return false;
		}

		if empty args {
			let temp = this->parseInjection(classname);
		} else {
			let temp = args;
		}

		return this->newInstanceArgs(classname, temp);
	}

	/**
	 * 分析自动依赖注入
	 *
	 * @param mixed $injection
	 * @return array
	 */
	protected function parseInjection(var injection)
	{
		var result, param, item, argsclass, data, e;

		let result = [];

		let param = this->parseReflection(injection);

		for item in param {
			try {
				let argsclass = this->parseParameterClass(item);

				if (argsclass) {
					let data = this->parseClassInstance(argsclass);
				} elseif (item->isDefaultValueAvailable()) {
					let data = item->getDefaultValue();
				} else {
					let data = null;
				}

				let result[item->name] = data;
			} catch ReflectionException, e {
				throw new InvalidArgumentException(e->getMessage());
			}
		}

		return result;
	}

	/**
	 * 分析反射参数的类
	 * 
	 * @param \ReflectionParameter $param
	 * @return boolean|string
	 */
	protected function parseParameterClass(<ReflectionParameter> param)
	{
		var classObject;

		let classObject = param->getClass();
		if ! classObject || ! (typeof classObject == "object" && classObject instanceof ReflectionClass) {
			return false;
		}

		return classObject->getName();
	}

	/**
	 * 解析反射参数类实例
	 * 
	 * @param string $argsclass
	 * @return array
	 */
	protected function parseClassInstance(string argsclass)
	{
		var result;

		let result = this->parseClassFromContainer(argsclass);
		if (result) {
			return result;
		}

		let result = this->parseClassNotExists(argsclass);
		if (result) {
			return result;
		}

		throw new InvalidArgumentException(sprintf("Class or interface %s is not register in container", argsclass));
	}

	/**
	 * 从服务容器中获取解析反射参数类实例
	 * 
	 * @param string $argsclass
	 * @return boolean|object
	 */
	protected function parseClassFromContainer(string argsclass)
	{
		var itemMake, result;

		let itemMake = this->make(argsclass);
		if itemMake === false {
			return false;
		}

		// 实例对象
		if typeof itemMake == "object" {
			return itemMake;
		}

		// 接口绑定实现
		if class_exists(itemMake) {
			let result = this->make(itemMake);
			if typeof result != "object" {
				throw new InvalidArgumentException(sprintf("Class or interface %s is register in container is not object.", argsclass));
			}

			return result;
		}

		throw new InvalidArgumentException(sprintf("Class or interface %s is not register in container", argsclass));
	}

	/**
	 * 独立类作为解析反射参数类实例
	 * 
	 * @param string $argsclass
	 * @return boolean|object
	 */
	protected function parseClassNotExists(string argsclass)
	{
		var result;

		if ! class_exists(argsclass) {
			return false;
		}

		let result = this->make(argsclass);
		if typeof result != "object" {
			throw new InvalidArgumentException(sprintf("Class or interface %s is register in container is not object.", argsclass));
		}

		return result;
	}

	/**
	 * 不同的类型不同的反射
	 * 
	 * @param mixed $injection
	 * @return array
	 */
	protected function parseReflection(var injection)
	{
		if typeof injection == "object" && injection instanceof Closure {
			return this->parseClosureReflection(injection);
		} elseif typeof injection != "string" && is_callable(injection) {
			return this->parseMethodReflection(injection);
		} elseif typeof injection == "string" {
			return this->parseClassReflection(injection);
		}

		throw new InvalidArgumentException("Unsupported callback types.");
	}

	/**
	 * 解析闭包反射参数
	 * 
	 * @param Closure $injection
	 * @return array
	 */
	protected function parseClosureReflection(<Closure> injection)
	{
		var reflection, param;

		let reflection = new ReflectionFunction(injection);
		let param = reflection->getParameters();
		if empty param {
			let param = [];
		}

		return param;
	}

	/**
	 * 解析数组回调反射参数
	 * 
	 * @param array&callback $injection
	 * @return array
	 */
	protected function parseMethodReflection(var injection)
	{
		var reflection, param;

		let reflection = new ReflectionMethod(injection[0], injection[1]);
		let param = reflection->getParameters();
		if empty param {
			let param = [];
		}

		return param;
	}

	/**
	 * 解析类反射参数
	 * 
	 * @param string $injection
	 * @return array
	 */
	protected function parseClassReflection(string injection)
	{
		var reflection, constructor, param;

		let reflection = new ReflectionClass(injection);
		if ! reflection->isInstantiable() {
			throw new InvalidArgumentException(sprintf("Class %s is not instantiable.", injection));
		}

		let constructor = reflection->getConstructor();
		if (constructor) {
			let param = constructor->getParameters();
		}

		if ! param {
			let param = [];
		}

		return param;
	}

	/**
	 * 动态创建实例对象
	 *
	 * @param string $classname
	 * @param array $args
	 * @return mixed
	 */
	protected function newInstanceArgs(var classname, var args)
	{
		try {
            return (new ReflectionClass(classname))->newInstanceArgs(args);
        } catch ReflectionException {
            return (new ReflectionClass(classname))->newInstanceWithoutConstructor();
        }
	}

	/**
	 * 解析注册容器对象别名
	 *
	 * @param array $name
	 * @return array
	 */
	protected function parseAlias(array name)
	{
		return [
			key(name),
			current(name)
		];
	}

	/**
	 * 实现 ArrayAccess::offsetExists
	 *
	 * @param string $offset
	 * @return bool
	 */
	public function offsetExists(var offset)
	{
		return isset this->services[this->normalize(offset)];
	}

	/**
	 * 实现 ArrayAccess::offsetGet
	 *
	 * @param string $offset
	 * @return mixed
	 */
	public function offsetGet(var offset)
	{
		return this->make(offset);
	}

	/**
	 * 实现 ArrayAccess::offsetSet
	 *
	 * @param string $name
	 * @param mixed $value
	 * @return void
	 */
	public function offsetSet(var name, var value)
	{
		return this->bind(name, value);
	}

	/**
	 * 实现 ArrayAccess::offsetUnset
	 *
	 * @param string $name
	 * @return void
	 */
	public function offsetUnset(var name)
	{
		var prop, item;

		let name = this->normalize(name);

		let prop = [
			"services",
			"instances",
			"singletons"
		];

		for item in prop {
			if isset this->{item}[name] {
				unset this->{item}[name];
			}
		}
	}

	/**
	 * 捕捉支持属性参数
	 *
	 * @param string $key
	 * @return 设置项
	 */
	public function __get(var key)
	{
		return this->offsetGet(key);
	}

	/**
	 * 设置支持属性参数
	 *
	 * @param string $key
	 * @param mixed $service
	 * @return void
	 */
	public function __set(var key, var service)
	{
		this->offsetSet(key, service);
		return this;
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
		throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
	}
}
