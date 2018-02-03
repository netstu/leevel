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
namespace Queryyetsimple\Collection;

use Iterator;
use Countable;
use ArrayAccess;
use JsonSerializable;
use RuntimeException;
use BadMethodCallException;
use InvalidArgumentException;
use Queryyetsimple\Support\Type;
use Queryyetsimple\Support\IJson;
use Queryyetsimple\Support\IArray;

/**
 * 集合
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.02.03
 * @version 1.0
 */
class Collection implements IArray, IJson, Iterator, ArrayAccess, Countable, JsonSerializable
{

    /**
     * 元素合集
     *
     * @var array
     */
    protected elements = [];
    
    /**
     * 验证
     *
     * @var boolean
     */
    protected valid = true;
    
    /**
     * 类型
     *
     * @var mixed
     */
    protected type = [];
    
    /**
     * 构造函数
     *
     * @param mixed $elements
     * @param array $type
     * @return void
     */
    public function __construct(elements = [], array type = null)
    {
        var key, value;
    
        if ! empty type {
            let this->type = type;
        }

        let elements = this->getArrayElements(elements);

        if this->type {
            for key, value in elements {
                this->offsetSet(key, value);
            }
        } else {
            let this->elements = elements;
        }
    }
    
    /**
     * 创建一个集合
     *
     * @param mixed $elements
     * @param mixed $type
     * @return void
     */
    public static function make(elements = [], type = null)
    {
        return new self(elements, type);
    }
    
    /**
     * 当前元素
     *
     * @return mixed
     */
    public function current()
    {
        return current(this->elements);
    }
    
    /**
     * 当前 key
     *
     * @return mixed
     */
    public function key()
    {
        return key(this->elements);
    }
    
    /**
     * 下一个元素
     *
     * @return void
     */
    public function next()
    {
        var next;
    
        let next = next(this->elements);
        let this->valid = next !== false;
    }
    
    /**
     * 指针重置
     *
     * @return void
     */
    public function rewind()
    {
        reset(this->elements);
        let this->valid = true;
    }
    
    /**
     * 验证
     *
     * @return boolean
     */
    public function valid() -> boolean
    {
        return this->valid;
    }
    
    /**
     * 实现 ArrayAccess::offsetExists
     *
     * @param string $key
     * @return mixed
     */
    public function offsetExists(string key)
    {
        return isset this->elements[key];
    }
    
    /**
     * 实现 ArrayAccess::offsetGet
     *
     * @param string $key
     * @return mixed
     */
    public function offsetGet(string key)
    {
        return  isset this->elements[key] ? this->elements[key] : null;
    }
    
    /**
     * 实现 ArrayAccess::offsetSet
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function offsetSet(string key, value)
    {
        this->checkType(value);
        let this->elements[key] = value;
    }
    
    /**
     * 实现 ArrayAccess::offsetUnset
     *
     * @param string $key
     * @return void
     */
    public function offsetUnset(string key)
    {
        if isset this->elements[key] {
            unset this->elements[key];
        }
    }
    
    /**
     * 统计元素数量 count($obj)
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->elements);
    }
    
    /**
     * 返回所有元素
     *
     * @return array
     */
    public function all() -> array
    {
        return this->elements;
    }
    
    /**
     * 对象转数组
     *
     * @return array
     */
    public function toArray() -> array
    {
        return array_map(function (value) {
            return value instanceof \Queryyetsimple\Support\IArray ? value->toArray() : value;
        }, this->elements);
    }
    
    /**
     * 实现 JsonSerializable::jsonSerialize
     *
     * @return array
     */
    public function jsonSerialize() -> array
    {
        return array_map(function (value) {
            if value instanceof \JsonSerializable {
                return value->jsonSerialize();
            } elseif value instanceof \Queryyetsimple\Support\IJson {
                return json_decode(value->toJson(), true);
            } elseif value instanceof \Queryyetsimple\Support\IArray {
                return value->toArray();
            } else {
                return value;
            }
        }, this->elements);
    }
    
    /**
     * 对象转 JSON
     *
     * @param integer $option
     * @return string
     */
    public function toJson(int option = 256) -> string
    {
        return json_encode(this->jsonSerialize(), option);
    }
    
    /**
     * __toString 魔术方法
     *
     * @return string
     */
    public function __toString() -> string
    {
        return this->toJson();
    }
    
    /**
     * JQuery.each
     * 
     * @param callable $callback
     * @return $this
     */
    public function each(callback)
    {
        var key, item;

        if !is_callable(callback) {
            throw new RuntimeException("Each need a callback.");
        }
    
        for key, item in this->elements {
            if {callback}(item, key) === false {
                break;
            }
        }

        return this;
    }
    
    /**
     * JQuery.prev
     *
     * @return mixed
     */
    public function prev()
    {
        var prev;
    
        let prev = prev(this->elements);
        let this->valid = true;

        return prev;
    }
    
    /**
     * JQuery.end
     *
     * @return mixed
     */
    public function end()
    {
        var end;
    
        let end = end(this->elements);
        let this->valid = false;

        return end;
    }
    
    /**
     * JQuery.siblings
     *
     * @param mixed $key
     * @return array
     */
    public function siblings(key = null) -> array
    {
        var result, k, value;
    
        let result = [];
        let key = this->parseKey(key);

        for k, value in this->elements {
            if k === key {
                continue;
            }
            let result[k] = value;
        }

        return result;
    }
    
    /**
     * JQuery.nextAll
     *
     * @param mixed $key
     * @return array
     */
    public function nextAll(key = null) -> array
    {
        var result, current, k, value;
    
        let result = [];
        let key = this->parseKey(key);
        let current = false;

        for k, value in this->elements {
            if current === false {
                if k === key {
                    let current = true;
                }
                continue;
            }

            let result[k] = value;
        }

        return result;
    }
    
    /**
     * JQuery.prevAll
     *
     * @param mixed $key
     * @return array
     */
    public function prevAll(key = null) -> array
    {
        var result, current, k, value;
    
        let result = [];
        let key = this->parseKey(key);
        let current = false;

        for k, value in this->elements {
            if k === key {
                let current = true;
                break;
            }

            let result[k] = value;
        }

        return result;
    }
    
    /**
     * JQuery.attr
     *
     * @param string $key
     * @param mixed $value
     * @return void|mixed
     */
    public function attr(string key, value = null)
    {
        if value === null {
            return this->offsetGet(key);
        } else {
            this->offsetSet(key, value);
        }
    }
    
    /**
     * JQuery.eq
     *
     * @param string $key
     * @return mixed
     */
    public function eq(string key)
    {
        return this->offsetGet(key);
    }
    
    /**
     * JQuery.get
     *
     * @param string $key
     * @return mixed
     */
    public function get(string key)
    {
        return this->offsetGet(key);
    }
    
    /**
     * JQuery.index
     *
     * @param mixed $value
     * @param boolean $strict
     * @return mixed
     */
    public function index(value = null, boolean strict = true)
    {
        var key;
    
        if value === null {
            return this->key();
        } else {
            let key = array_search(value, this->elements, strict);
            if key === false {
                return null;
            }

            return key;
        }
    }
    
    /**
     * JQuery.find
     *
     * @param string $key
     * @return mixed
     */
    public function find(string key)
    {
        return this->offsetGet(key);
    }
    
    /**
     * JQuery.first
     *
     * @return mixed
     */
    public function first()
    {
        this->rewind();
        return this->current();
    }
    
    /**
     * JQuery.last
     *
     * @return mixed
     */
    public function last()
    {
        return this->end();
    }
    
    /**
     * JQuery.is
     *
     * @param string $key
     * @return boolean
     */
    public function is(string key) -> boolean
    {
        return this->offsetExists(key);
    }
    
    /**
     * JQuery.slice
     *
     * @param int $selector
     * @param string $length
     * @return array
     */
    public function slice(int selector, string length = null) -> array
    {
        return array_slice(this->elements, selector, length);
    }
    
    /**
     * JQuery.not
     *
     * @param string $key
     * @return array
     */
    public function not(string key) -> array
    {
        return this->siblings(key);
    }
    
    /**
     * JQuery.filter
     *
     * @param string $key
     * @return array
     */
    public function filter(string key) -> array
    {
        return this->siblings(key);
    }
    
    /**
     * jquer.size
     *
     * @return int
     */
    public function size() -> int
    {
        return this->count();
    }
    
    /**
     * 是否为空
     *
     * @return boolean
     */
    public function isEmpty() -> boolean
    {
        return empty(this->elements);
    }
    
    /**
     * 数据 map
     *
     * @param mixed $key
     * @param mixed $value
     * @return array
     */
    public function map(key, value = null) -> array
    {
        return array_column(this->elements, key, value);
    }
    
    /**
     * 验证类型
     *
     * @param mixed $value
     * @return void
     */
    protected function checkType(value)
    {
        if ! (this->type) {
            return;
        }

        if Type::these(value, this->type) {
            return;
        }

        throw new InvalidArgumentException(sprintf("Collection type %s validation failed", implode(",", this->type)));
    }
    
    /**
     * 转换数据到数组
     *
     * @param mixed $elements
     * @return array
     */
    protected function getArrayElements(elements) -> array
    {
        var temp = [];

        if is_array(elements) {
            return elements;
        } elseif elements instanceof self {
            return elements->all();
        } elseif elements instanceof IArray {
            return elements->toArray();
        } elseif elements instanceof IJson {
            return json_decode(elements->toJson(), true);
        } elseif elements instanceof JsonSerializable {
            return elements->jsonSerialize();
        }

        if typeof elements != "array" {
            let temp[] = elements;
            let elements = temp;
        }

        return elements;
    }
    
    /**
     * 分析 key
     *
     * @param mixed $key
     * @return mixed
     */
    protected function parseKey(key = null)
    {
        if is_null(key) {
            let key = this->key();
        }
        return key;
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
        throw new BadMethodCallException(sprintf("Collection method %s is not defined.", method));
    }
    
    /**
     * __get 魔术方法
     *
     * @param string $key
     * @return mixed
     */
    public function __get(string key)
    {
        return this->offsetGet(key);
    }
    
    /**
     * __set 魔术方法
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function __set(string key, value)
    {
        this->offsetSet(key, value);
    }
}
