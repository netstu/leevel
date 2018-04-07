
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ICookie 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.06
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cookie_ICookie) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Cookie, ICookie, leevel, cookie_icookie, leevel_cookie_icookie_method_entry);

	return SUCCESS;

}

/**
 * 设置 COOKIE
 *
 * @param string $name
 * @param string $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, set);

/**
 * 批量插入
 *
 * @param string|array $keys
 * @param mixed $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, put);

/**
 * 数组插入数据
 *
 * @param string $key
 * @param mixed $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, push);

/**
 * 合并元素
 *
 * @param string $key
 * @param array $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, merge);

/**
 * 弹出元素
 *
 * @param string $key
 * @param mixed $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, pop);

/**
 * 数组插入键值对数据
 *
 * @param string $key
 * @param mixed $keys
 * @param mixed $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, arrays);

/**
 * 数组键值删除数据
 *
 * @param string $key
 * @param mixed $keys
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, arraysDelete);

/**
 * 获取 cookie
 *
 * @param string $name
 * @param mixed $defaults
 * @param array $option
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, get);

/**
 * 删除 cookie
 *
 * @param string $name
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, delete);

/**
 * 清空 cookie
 *
 * @param boolean $deletePrefix
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Cookie_ICookie, clear);
