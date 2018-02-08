
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * 沙盒 url
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.02.08
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Url) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple, Url, queryyetsimple, url, queryyetsimple_support_facade_ce, queryyetsimple_url_method_entry, 0);

	return SUCCESS;

}

/**
 * 返回门面名字
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Url, name) {

	zval *this_ptr = getThis();


	RETURN_STRING("url");

}

