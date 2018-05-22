
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
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * cookie 封装
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.06
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cookie_Cookie) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Cookie, Cookie, leevel, cookie_cookie, leevel_cookie_cookie_method_entry, 0);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_cookie_cookie_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Cookie 设置数据
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_cookie_cookie_ce, SL("cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_cookie_cookie_ce->create_object = zephir_init_properties_Leevel_Cookie_Cookie;

	zend_class_implements(leevel_cookie_cookie_ce TSRMLS_CC, 1, leevel_cookie_icookie_ce);
	zend_class_implements(leevel_cookie_cookie_ce TSRMLS_CC, 1, leevel_option_iclass_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "options", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置 COOKIE
 *
 * @param string $name
 * @param string $value
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, set) {

	zend_bool isHttpSecure, _2, _13;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option, _16;
	zval *name_param = NULL, *value = NULL, value_sub, *option_param = NULL, *_SERVER, _0, _3, _4, _5, _6, _14, _15, _17, _18, _1$$3, _7$$5, _8$$5, _9$$5, _10$$6, _11$$6, _12$$7;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_16);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	if (!_SERVER) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 2, &name_param, &value, &option_param);

	zephir_get_strval(&name, name_param);
	if (!value) {
		value = &value_sub;
		ZEPHIR_INIT_VAR(value);
		ZVAL_STRING(value, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	isHttpSecure = 0;
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptions", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&option, &_0);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_json_encode(&_1$$3, value, 0 );
		ZEPHIR_CPY_WRT(value, &_1$$3);
	}
	_2 = !(zephir_is_scalar(value));
	if (_2) {
		_2 = !(Z_TYPE_P(value) == IS_NULL);
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Cookie value must be scalar or null", "leevel/cookie/cookie.zep", 84);
		return;
	}
	zephir_array_fetch_string(&_3, &option, SL("prefix"), PH_NOISY | PH_READONLY, "leevel/cookie/cookie.zep", 87 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_3, &name);
	zephir_get_strval(&name, &_4);
	zephir_array_fetch_string(&_5, &option, SL("expire"), PH_NOISY | PH_READONLY, "leevel/cookie/cookie.zep", 89 TSRMLS_CC);
	zephir_array_fetch_string(&_6, &option, SL("expire"), PH_NOISY | PH_READONLY, "leevel/cookie/cookie.zep", 91 TSRMLS_CC);
	if (ZEPHIR_GT_LONG(&_5, 0)) {
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_time(&_7$$5);
		zephir_array_fetch_string(&_8$$5, &option, SL("expire"), PH_NOISY | PH_READONLY, "leevel/cookie/cookie.zep", 90 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_9$$5);
		zephir_add_function(&_9$$5, &_7$$5, &_8$$5);
		zephir_array_update_string(&option, SL("expire"), &_9$$5, PH_COPY | PH_SEPARATE);
	} else if (ZEPHIR_LT_LONG(&_6, 0)) {
		ZEPHIR_INIT_VAR(&_10$$6);
		zephir_time(&_10$$6);
		ZEPHIR_INIT_VAR(&_11$$6);
		ZVAL_LONG(&_11$$6, (zephir_get_numberval(&_10$$6) - 31536000));
		zephir_array_update_string(&option, SL("expire"), &_11$$6, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&_12$$7);
		ZVAL_LONG(&_12$$7, 0);
		zephir_array_update_string(&option, SL("expire"), &_12$$7, PH_COPY | PH_SEPARATE);
	}
	_13 = zephir_array_isset_string(_SERVER, SL("HTTPS"));
	if (_13) {
		ZEPHIR_INIT_VAR(&_14);
		zephir_array_fetch_string(&_15, _SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY, "leevel/cookie/cookie.zep", 97 TSRMLS_CC);
		zephir_fast_strtoupper(&_14, &_15);
		_13 = ZEPHIR_IS_STRING_IDENTICAL(&_14, "ON");
	}
	if (_13) {
		isHttpSecure = 1;
	}
	ZEPHIR_INIT_VAR(&_16);
	zephir_create_array(&_16, 7, 0 TSRMLS_CC);
	zephir_array_fast_append(&_16, &name);
	zephir_array_fast_append(&_16, value);
	ZEPHIR_OBS_VAR(&_17);
	zephir_array_fetch_string(&_17, &option, SL("expire"), PH_NOISY, "leevel/cookie/cookie.zep", 105 TSRMLS_CC);
	zephir_array_fast_append(&_16, &_17);
	ZEPHIR_OBS_NVAR(&_17);
	zephir_array_fetch_string(&_17, &option, SL("path"), PH_NOISY, "leevel/cookie/cookie.zep", 106 TSRMLS_CC);
	zephir_array_fast_append(&_16, &_17);
	ZEPHIR_OBS_NVAR(&_17);
	zephir_array_fetch_string(&_17, &option, SL("domain"), PH_NOISY, "leevel/cookie/cookie.zep", 107 TSRMLS_CC);
	zephir_array_fast_append(&_16, &_17);
	ZEPHIR_INIT_VAR(&_18);
	ZVAL_BOOL(&_18, isHttpSecure);
	zephir_array_fast_append(&_16, &_18);
	ZEPHIR_OBS_NVAR(&_17);
	zephir_array_fetch_string(&_17, &option, SL("httponly"), PH_NOISY, "leevel/cookie/cookie.zep", 110 TSRMLS_CC);
	zephir_array_fast_append(&_16, &_17);
	zephir_update_property_array(this_ptr, SL("cookies"), &name, &_16 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 批量插入
 *
 * @param string|array $keys
 * @param mixed $value
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, put) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *keys = NULL, keys_sub, *value = NULL, value_sub, *option_param = NULL, __$null, key, *_0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &keys, &value, &option_param);

	ZEPHIR_SEPARATE_PARAM(keys);
	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (Z_TYPE_P(keys) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(keys);
		zephir_create_array(keys, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(keys, keys, value, PH_COPY);
	}
	zephir_is_iterable(keys, 0, "leevel/cookie/cookie.zep", 133);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(keys), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(value);
		ZVAL_COPY(value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, &key, value, &option);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组插入数据
 *
 * @param string $key
 * @param mixed $value
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, push) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *key_param = NULL, *value, value_sub, *option_param = NULL, arr, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &option_param);

	zephir_get_strval(&key, key_param);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &key, &_0, &option);
	zephir_check_call_status();
	zephir_array_append(&arr, value, PH_SEPARATE, "leevel/cookie/cookie.zep", 147);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &arr, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并元素
 *
 * @param string $key
 * @param array $value
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, merge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value, option;
	zval *key_param = NULL, *value_param = NULL, *option_param = NULL, _0, _1, _2, _3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value_param, &option_param);

	zephir_get_strval(&key, key_param);
	zephir_get_arrval(&value, value_param);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &key, &_2, &option);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &value TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "array_unique", NULL, 61, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &_3, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出元素
 *
 * @param string $key
 * @param mixed $value
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, pop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value, option;
	zval *key_param = NULL, *value_param = NULL, *option_param = NULL, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value_param, &option_param);

	zephir_get_strval(&key, key_param);
	zephir_get_arrval(&value, value_param);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &key, &_1, &option);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "array_diff", NULL, 62, &_0, &value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &_2, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组插入键值对数据
 *
 * @param string $key
 * @param mixed $keys
 * @param mixed $value
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, arrays) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *key_param = NULL, *keys, keys_sub, *value = NULL, value_sub, *option_param = NULL, __$null, arr, _0, _1$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &key_param, &keys, &value, &option_param);

	zephir_get_strval(&key, key_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &key, &_0, &option);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_STRING) {
		zephir_array_update_zval(&arr, keys, value, PH_COPY | PH_SEPARATE);
	} else if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_array_merge(&_1$$4, &arr, keys TSRMLS_CC);
		ZEPHIR_CPY_WRT(&arr, &_1$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &arr, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组键值删除数据
 *
 * @param string $key
 * @param mixed $keys
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, arraysDelete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *key_param = NULL, *keys, keys_sub, *option_param = NULL, arr, tempKey, arrDeleteKey, _0, *_1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&tempKey);
	ZVAL_UNDEF(&arrDeleteKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &keys, &option_param);

	zephir_get_strval(&key, key_param);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &key, &_0, &option);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&arrDeleteKey);
		zephir_create_array(&arrDeleteKey, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&arrDeleteKey, keys);
	} else {
		ZEPHIR_CPY_WRT(&arrDeleteKey, keys);
	}
	zephir_is_iterable(&arrDeleteKey, 0, "leevel/cookie/cookie.zep", 228);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrDeleteKey), _1)
	{
		ZEPHIR_INIT_NVAR(&tempKey);
		ZVAL_COPY(&tempKey, _1);
		if (zephir_array_isset(&arr, &tempKey)) {
			zephir_array_unset(&arr, &tempKey, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&tempKey);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &arr, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取 cookie
 *
 * @param string $name
 * @param mixed $defaults
 * @param array $option
 * @return mixed
 */
PHP_METHOD(Leevel_Cookie_Cookie, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *defaults = NULL, defaults_sub, *option_param = NULL, __$true, __$null, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3, _9$$3, _10$$3, _7$$4, _8$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &defaults, &option_param);

	zephir_get_strval(&name, name_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptions", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&option, &_0);
	zephir_array_fetch_string(&_1, &option, SL("prefix"), PH_NOISY | PH_READONLY, "leevel/cookie/cookie.zep", 242 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &name);
	zephir_get_strval(&name, &_2);
	zephir_read_property(&_3, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_3, &name)) {
		zephir_read_property(&_5$$3, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6$$3, &_5$$3, &name, PH_NOISY | PH_READONLY, "leevel/cookie/cookie.zep", 245 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "isjson", NULL, 0, &_6$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$3)) {
			zephir_read_property(&_7$$4, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$4, &_7$$4, &name, PH_NOISY | PH_READONLY, "leevel/cookie/cookie.zep", 246 TSRMLS_CC);
			zephir_json_decode(return_value, &_8$$4, zephir_get_intval(&__$true) );
			RETURN_MM();
		}
		zephir_read_property(&_9$$3, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_10$$3, &_9$$3, &name, PH_NOISY | PH_READONLY, "leevel/cookie/cookie.zep", 248 TSRMLS_CC);
		RETURN_CTOR(&_10$$3);
	} else {
		RETVAL_ZVAL(defaults, 1, 0);
		RETURN_MM();
	}

}

/**
 * 删除 cookie
 *
 * @param string $name
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *option_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &option_param);

	zephir_get_strval(&name, name_param);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &name, &_0, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清空 cookie
 *
 * @param boolean $deletePrefix
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Cookie_Cookie, clear) {

	zend_string *_6;
	zend_ulong _5;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *deletePrefix_param = NULL, *option_param = NULL, prefix, key, _0, _1, _2, _3, *_4, _8$$4;
	zend_bool deletePrefix, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &deletePrefix_param, &option_param);

	if (!deletePrefix_param) {
		deletePrefix = 1;
	} else {
		deletePrefix = zephir_get_boolval(deletePrefix_param);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptions", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&option, &_0);
	ZEPHIR_OBS_VAR(&prefix);
	zephir_array_fetch_string(&prefix, &option, SL("prefix"), PH_NOISY, "leevel/cookie/cookie.zep", 277 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_array_update_string(&option, SL("prefix"), &_1, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_2, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	zephir_is_iterable(&_2, 0, "leevel/cookie/cookie.zep", 289);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&key, _6);
		} else {
			ZVAL_LONG(&key, _5);
		}
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_COPY(&_3, _4);
		_7$$3 = deletePrefix == 1;
		if (_7$$3) {
			_7$$3 = zephir_is_true(&prefix);
		}
		if (_7$$3) {
			ZEPHIR_INIT_NVAR(&_8$$4);
			zephir_fast_strpos(&_8$$4, &key, &prefix, 0 );
			if (ZEPHIR_IS_LONG_IDENTICAL(&_8$$4, 0)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_9, 0, &key, &option);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_9, 0, &key, &option);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_3);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Leevel_Cookie_Cookie, option) {

	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	if (!(Z_TYPE_P(&name) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Option set name must be a string.", "leevel/cookie/cookie.zep", 301);
		return;
	}
	zephir_update_property_array(this_ptr, SL("option"), &name, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 修改数组配置
 *
 * @param string $name
 * @param array $value
 * @return $this
 */
PHP_METHOD(Leevel_Cookie_Cookie, optionArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *name_param = NULL, *value_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &name);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &value TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "option", NULL, 0, &name, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 修改多个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Leevel_Cookie_Cookie, options) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, name, value, *_0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (ZEPHIR_IS_EMPTY(&option)) {
		RETURN_THIS();
	}
	zephir_is_iterable(&option, 0, "leevel/cookie/cookie.zep", 340);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&option), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "option", &_3, 0, &name, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();

}

/**
 * 获取单个配置
 *
 * @param string $name
 * @param mixed $defaults
 * @return mixed
 */
PHP_METHOD(Leevel_Cookie_Cookie, getOption) {

	zval *name_param = NULL, *defaults = NULL, defaults_sub, __$null, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaults);

	zephir_get_strval(&name, name_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &name)) {
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &name, PH_NOISY, "leevel/cookie/cookie.zep", 352 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, defaults);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 获取所有配置
 *
 * @param array $option
 * @return mixed
 */
PHP_METHOD(Leevel_Cookie_Cookie, getOptions) {

	zval *option_param = NULL, _0$$3;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&option))) {
		zephir_read_property(&_0$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(return_value, &_0$$3, &option TSRMLS_CC);
		RETURN_MM();
	} else {
		RETURN_MM_MEMBER(getThis(), "option");
	}

}

/**
 * 删除单个配置
 *
 * @param string $name
 * @return $this
 */
PHP_METHOD(Leevel_Cookie_Cookie, deleteOption) {

	zval *name_param = NULL, _0, _1$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		zephir_read_property(&_1$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &name, PH_SEPARATE);
	}
	RETURN_THIS();

}

/**
 * 删除多个配置
 *
 * @param array $option
 * @return $this
 */
PHP_METHOD(Leevel_Cookie_Cookie, deleteOptions) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, key, *_0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&option))) {
		RETURN_THIS();
	}
	zephir_is_iterable(&option, 0, "leevel/cookie/cookie.zep", 403);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&option), _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteoption", &_1, 0, &key);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

/**
 * 返回所有 cookie
 *
 * @return array
 */
PHP_METHOD(Leevel_Cookie_Cookie, all) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookies");

}

/**
 * 验证是否为正常的 JSON 字符串
 *
 * @param mixed $data
 * @return boolean
 */
PHP_METHOD(Leevel_Cookie_Cookie, isJson) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_0 = !(zephir_is_scalar(data));
	if (_0) {
		_0 = !((zephir_method_exists_ex(data, SL("__tostring") TSRMLS_CC) == SUCCESS));
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_json_decode(&_1, data, 0 );
	ZEPHIR_CALL_FUNCTION(&_2, "json_last_error", NULL, 19);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_2, 0));

}

zend_object *zephir_init_properties_Leevel_Cookie_Cookie(zend_class_entry *class_type TSRMLS_DC) {

		zval _3$$4;
	zval __$false, _0, _2, _1$$3;
		ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("cookies"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 5, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_3$$4, SL("prefix"), SL("q_"));
			add_assoc_long_ex(&_3$$4, SL("expire"), 86400);
			add_assoc_stringl_ex(&_3$$4, SL("domain"), SL(""));
			add_assoc_stringl_ex(&_3$$4, SL("path"), SL("/"));
			zephir_array_update_string(&_3$$4, SL("httponly"), &__$false, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("option"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

