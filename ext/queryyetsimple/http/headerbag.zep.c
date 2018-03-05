
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * header bag
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.04
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Http_HeaderBag) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Http, HeaderBag, queryyetsimple, http_headerbag, queryyetsimple_http_bag_ce, queryyetsimple_http_headerbag_method_entry, 0);

	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param array $elements
 * @return void 
 */
PHP_METHOD(Queryyetsimple_Http_HeaderBag, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements_param = NULL;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
	} else {
		zephir_get_arrval(&elements, elements_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &elements);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Http_HeaderBag, replace) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements_param = NULL, _0;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
	} else {
		zephir_get_arrval(&elements, elements_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("elements"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &elements);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Http_HeaderBag, add) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements_param = NULL, key, value, *_0;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
	} else {
		zephir_get_arrval(&elements, elements_param);
	}


	zephir_is_iterable(&elements, 0, "queryyetsimple/http/headerbag.zep", 62);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&elements), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Http_HeaderBag, normalize) {

	zval *key = NULL, key_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, key);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "-");
	ZEPHIR_INIT_NVAR(key);
	zephir_fast_str_replace(key, &_1, &_2, &_0 TSRMLS_CC);
	RETVAL_ZVAL(key, 1, 0);
	RETURN_MM();

}

