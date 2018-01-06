
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


/**
 * cookie 封装
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.06
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Cookie_Cookie) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Cookie, Cookie, queryyetsimple, cookie_cookie, queryyetsimple_cookie_cookie_method_entry, 0);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_cookie_cookie_ce, SL("arrOption"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_cookie_cookie_ce->create_object = zephir_init_properties_Queryyetsimple_Cookie_Cookie;

	zend_class_implements(queryyetsimple_cookie_cookie_ce TSRMLS_CC, 1, queryyetsimple_cookie_icookie_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "options", NULL, 0, &arrOption);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置 COOKIE
 *
 * @param string $sName
 * @param string $mixValue
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, set) {

	zend_bool booHttp, _2, _5, _15;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *sName_param = NULL, *mixValue = NULL, mixValue_sub, *arrOption_param = NULL, *_COOKIE, *_SERVER, _0, _3, _4, _6, _7, _8, _16, _17, _18, _19, _20, _21, _22, _1$$3, _9$$8, _10$$8, _11$$8, _12$$9, _13$$9, _14$$10;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	if (!_SERVER) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	if (!_COOKIE) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 2, &sName_param, &mixValue, &arrOption_param);

	zephir_get_strval(&sName, sName_param);
	if (!mixValue) {
		mixValue = &mixValue_sub;
		ZEPHIR_INIT_VAR(mixValue);
		ZVAL_STRING(mixValue, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(mixValue);
	}
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	booHttp = 0;
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptions", NULL, 0, &arrOption);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&arrOption, &_0);
	if (Z_TYPE_P(mixValue) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_json_encode(&_1$$3, mixValue, 0 );
		ZEPHIR_CPY_WRT(mixValue, &_1$$3);
	}
	_2 = !(zephir_is_scalar(mixValue));
	if (_2) {
		_2 = !(Z_TYPE_P(mixValue) == IS_NULL);
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Cookie value must be scalar or null", "queryyetsimple/cookie/cookie.zep", 78);
		return;
	}
	zephir_array_fetch_string(&_3, &arrOption, SL("prefix"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 81 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_3, &sName);
	zephir_get_strval(&sName, &_4);
	_5 = Z_TYPE_P(mixValue) == IS_NULL;
	if (!(_5)) {
		zephir_array_fetch_string(&_6, &arrOption, SL("expire"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 83 TSRMLS_CC);
		_5 = ZEPHIR_LT_LONG(&_6, 0);
	}
	if (_5) {
		if (zephir_array_isset(_COOKIE, &sName)) {
			zephir_array_unset(_COOKIE, &sName, PH_SEPARATE);
		}
	} else {
		zephir_array_update_zval(_COOKIE, &sName, mixValue, PH_COPY | PH_SEPARATE);
	}
	zephir_array_fetch_string(&_7, &arrOption, SL("expire"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 91 TSRMLS_CC);
	zephir_array_fetch_string(&_8, &arrOption, SL("expire"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 93 TSRMLS_CC);
	if (ZEPHIR_GT_LONG(&_7, 0)) {
		ZEPHIR_INIT_VAR(&_9$$8);
		zephir_time(&_9$$8);
		zephir_array_fetch_string(&_10$$8, &arrOption, SL("expire"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 92 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_11$$8);
		zephir_add_function(&_11$$8, &_9$$8, &_10$$8);
		zephir_array_update_string(&arrOption, SL("expire"), &_11$$8, PH_COPY | PH_SEPARATE);
	} else if (ZEPHIR_LT_LONG(&_8, 0)) {
		ZEPHIR_INIT_VAR(&_12$$9);
		zephir_time(&_12$$9);
		ZEPHIR_INIT_VAR(&_13$$9);
		ZVAL_LONG(&_13$$9, (zephir_get_numberval(&_12$$9) - 31536000));
		zephir_array_update_string(&arrOption, SL("expire"), &_13$$9, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&_14$$10);
		ZVAL_LONG(&_14$$10, 0);
		zephir_array_update_string(&arrOption, SL("expire"), &_14$$10, PH_COPY | PH_SEPARATE);
	}
	_15 = zephir_array_isset_string(_SERVER, SL("HTTPS"));
	if (_15) {
		ZEPHIR_INIT_VAR(&_16);
		zephir_array_fetch_string(&_17, _SERVER, SL("HTTPS"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 99 TSRMLS_CC);
		zephir_fast_strtoupper(&_16, &_17);
		_15 = ZEPHIR_IS_STRING_IDENTICAL(&_16, "ON");
	}
	if (_15) {
		booHttp = 1;
	}
	zephir_array_fetch_string(&_18, &arrOption, SL("expire"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 103 TSRMLS_CC);
	zephir_array_fetch_string(&_19, &arrOption, SL("path"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 103 TSRMLS_CC);
	zephir_array_fetch_string(&_20, &arrOption, SL("domain"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 103 TSRMLS_CC);
	zephir_array_fetch_string(&_21, &arrOption, SL("httponly"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 103 TSRMLS_CC);
	ZVAL_BOOL(&_22, (booHttp ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 4, &sName, mixValue, &_18, &_19, &_20, &_22, &_21);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 批量插入
 *
 * @param string|array $mixKey
 * @param mixed $mixValue
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, put) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *mixKey = NULL, mixKey_sub, *mixValue = NULL, mixValue_sub, *arrOption_param = NULL, __$null, strKey, *_0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixKey_sub);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &mixKey, &mixValue, &arrOption_param);

	ZEPHIR_SEPARATE_PARAM(mixKey);
	if (!mixValue) {
		mixValue = &mixValue_sub;
		ZEPHIR_CPY_WRT(mixValue, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(mixValue);
	}
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	if (Z_TYPE_P(mixKey) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(mixKey);
		zephir_create_array(mixKey, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(mixKey, mixKey, mixValue, PH_COPY);
	}
	zephir_is_iterable(mixKey, 0, "queryyetsimple/cookie/cookie.zep", 126);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(mixKey), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&strKey);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&strKey, _2);
		} else {
			ZVAL_LONG(&strKey, _1);
		}
		ZEPHIR_INIT_NVAR(mixValue);
		ZVAL_COPY(mixValue, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, &strKey, mixValue, &arrOption);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(mixValue);
	ZEPHIR_INIT_NVAR(&strKey);
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组插入数据
 *
 * @param string $strKey
 * @param mixed $mixValue
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, push) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *strKey_param = NULL, *mixValue, mixValue_sub, *arrOption_param = NULL, arr, _0;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &strKey_param, &mixValue, &arrOption_param);

	zephir_get_strval(&strKey, strKey_param);
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &strKey, &_0, &arrOption);
	zephir_check_call_status();
	zephir_array_append(&arr, mixValue, PH_SEPARATE, "queryyetsimple/cookie/cookie.zep", 140);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &arr, &arrOption);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并元素
 *
 * @param string $strKey
 * @param array $arrValue
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, merge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrValue, arrOption;
	zval *strKey_param = NULL, *arrValue_param = NULL, *arrOption_param = NULL, _0, _1, _2, _3;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&arrValue);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &strKey_param, &arrValue_param, &arrOption_param);

	zephir_get_strval(&strKey, strKey_param);
	zephir_get_arrval(&arrValue, arrValue_param);
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &strKey, &_2, &arrOption);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &arrValue TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "array_unique", NULL, 5, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &_3, &arrOption);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出元素
 *
 * @param string $strKey
 * @param mixed $mixValue
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, pop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrValue, arrOption;
	zval *strKey_param = NULL, *arrValue_param = NULL, *arrOption_param = NULL, _0, _1, _2;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&arrValue);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &strKey_param, &arrValue_param, &arrOption_param);

	zephir_get_strval(&strKey, strKey_param);
	zephir_get_arrval(&arrValue, arrValue_param);
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &strKey, &_1, &arrOption);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "array_diff", NULL, 6, &_0, &arrValue);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &_2, &arrOption);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组插入键值对数据
 *
 * @param string $strKey
 * @param mixed $mixKey
 * @param mixed $mixValue
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, arrays) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *strKey_param = NULL, *mixKey, mixKey_sub, *mixValue = NULL, mixValue_sub, *arrOption_param = NULL, __$null, arr, _0, _1$$4;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixKey_sub);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &strKey_param, &mixKey, &mixValue, &arrOption_param);

	zephir_get_strval(&strKey, strKey_param);
	if (!mixValue) {
		mixValue = &mixValue_sub;
		mixValue = &__$null;
	}
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &strKey, &_0, &arrOption);
	zephir_check_call_status();
	if (Z_TYPE_P(mixKey) == IS_STRING) {
		zephir_array_update_zval(&arr, mixKey, mixValue, PH_COPY | PH_SEPARATE);
	} else if (Z_TYPE_P(mixKey) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_array_merge(&_1$$4, &arr, mixKey TSRMLS_CC);
		ZEPHIR_CPY_WRT(&arr, &_1$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &arr, &arrOption);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组键值删除数据
 *
 * @param string $strKey
 * @param mixed $mixKey
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, arraysDelete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *strKey_param = NULL, *mixKey, mixKey_sub, *arrOption_param = NULL, arr, strFoo, arrDeleteKey, _0, *_1;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixKey_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&strFoo);
	ZVAL_UNDEF(&arrDeleteKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &strKey_param, &mixKey, &arrOption_param);

	zephir_get_strval(&strKey, strKey_param);
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &strKey, &_0, &arrOption);
	zephir_check_call_status();
	if (Z_TYPE_P(mixKey) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&arrDeleteKey);
		zephir_create_array(&arrDeleteKey, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&arrDeleteKey, mixKey);
	} else {
		ZEPHIR_CPY_WRT(&arrDeleteKey, mixKey);
	}
	zephir_is_iterable(&arrDeleteKey, 0, "queryyetsimple/cookie/cookie.zep", 216);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrDeleteKey), _1)
	{
		ZEPHIR_INIT_NVAR(&strFoo);
		ZVAL_COPY(&strFoo, _1);
		if (zephir_array_isset(&arr, &strFoo)) {
			zephir_array_unset(&arr, &strFoo, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&strFoo);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &arr, &arrOption);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取 cookie
 *
 * @param string $sName
 * @param mixed $mixDefault
 * @param array $arrOption
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *sName_param = NULL, *mixDefault = NULL, mixDefault_sub, *arrOption_param = NULL, *_COOKIE, __$true, __$null, _0, _1, _2, _3$$3, _4$$3, _6$$3, _5$$4;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&mixDefault_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	if (!_COOKIE) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 2, &sName_param, &mixDefault, &arrOption_param);

	zephir_get_strval(&sName, sName_param);
	if (!mixDefault) {
		mixDefault = &mixDefault_sub;
		mixDefault = &__$null;
	}
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptions", NULL, 0, &arrOption);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&arrOption, &_0);
	zephir_array_fetch_string(&_1, &arrOption, SL("prefix"), PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 230 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &sName);
	zephir_get_strval(&sName, &_2);
	if (zephir_array_isset(_COOKIE, &sName)) {
		zephir_array_fetch(&_4$$3, _COOKIE, &sName, PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 233 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "isjson", NULL, 0, &_4$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			zephir_array_fetch(&_5$$4, _COOKIE, &sName, PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 234 TSRMLS_CC);
			zephir_json_decode(return_value, &_5$$4, zephir_get_intval(&__$true) );
			RETURN_MM();
		}
		zephir_array_fetch(&_6$$3, _COOKIE, &sName, PH_NOISY | PH_READONLY, "queryyetsimple/cookie/cookie.zep", 236 TSRMLS_CC);
		RETURN_CTOR(&_6$$3);
	} else {
		RETVAL_ZVAL(mixDefault, 1, 0);
		RETURN_MM();
	}

}

/**
 * 删除 cookie
 *
 * @param string $sName
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *sName_param = NULL, *arrOption_param = NULL, _0;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sName_param, &arrOption_param);

	zephir_get_strval(&sName, sName_param);
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &sName, &_0, &arrOption);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清空 cookie
 *
 * @param boolean $bOnlyPrefix
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, clear) {

	zend_string *_5;
	zend_ulong _4;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *bOnlyPrefix_param = NULL, *arrOption_param = NULL, *_COOKIE, strPrefix, sKey, _0, _1, _2, *_3, _7$$4;
	zend_bool bOnlyPrefix, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strPrefix);
	ZVAL_UNDEF(&sKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	if (!_COOKIE) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 0, 2, &bOnlyPrefix_param, &arrOption_param);

	if (!bOnlyPrefix_param) {
		bOnlyPrefix = 1;
	} else {
		bOnlyPrefix = zephir_get_boolval(bOnlyPrefix_param);
	}
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptions", NULL, 0, &arrOption);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&arrOption, &_0);
	ZEPHIR_OBS_VAR(&strPrefix);
	zephir_array_fetch_string(&strPrefix, &arrOption, SL("prefix"), PH_NOISY, "queryyetsimple/cookie/cookie.zep", 265 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_array_update_string(&arrOption, SL("prefix"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	zephir_is_iterable(_COOKIE, 0, "queryyetsimple/cookie/cookie.zep", 277);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_COOKIE), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&sKey);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&sKey, _5);
		} else {
			ZVAL_LONG(&sKey, _4);
		}
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_COPY(&_2, _3);
		_6$$3 = bOnlyPrefix == 1;
		if (_6$$3) {
			_6$$3 = zephir_is_true(&strPrefix);
		}
		if (_6$$3) {
			ZEPHIR_INIT_NVAR(&_7$$4);
			zephir_fast_strpos(&_7$$4, &sKey, &strPrefix, 0 );
			if (ZEPHIR_IS_LONG_IDENTICAL(&_7$$4, 0)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_8, 0, &sKey, &arrOption);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_8, 0, &sKey, &arrOption);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_INIT_NVAR(&sKey);
	ZEPHIR_MM_RESTORE();

}

/**
 * 修改单个配置
 *
 * @param string $strName
 * @param mixed $mixValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, option) {

	zend_class_entry *_1$$3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strName_param = NULL, *mixValue, mixValue_sub, _0$$3, _2$$3;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strName_param, &mixValue);

	zephir_get_strval(&strName, strName_param);


	if (!(Z_TYPE_P(&strName) == IS_STRING)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (!_1$$3) {
		_1$$3 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Cookie\\InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_0$$3, _1$$3);
		if (zephir_has_constructor(&_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Option set name must be a string.");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_2$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_0$$3, "queryyetsimple/cookie/cookie.zep", 289 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("arrOption"), &strName, mixValue TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 修改数组配置
 *
 * @param string $strName
 * @param array $arrValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, optionArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrValue;
	zval *strName_param = NULL, *arrValue_param = NULL, _0, _1;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arrValue);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strName_param, &arrValue_param);

	zephir_get_strval(&strName, strName_param);
	zephir_get_arrval(&arrValue, arrValue_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &strName);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &arrValue TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "option", NULL, 0, &strName, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 修改多个配置
 *
 * @param string $strName
 * @param mixed $mixValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, options) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, strName, mixValue, *_0;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&mixValue);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	if (ZEPHIR_IS_EMPTY(&arrOption)) {
		RETURN_THIS();
	}
	zephir_is_iterable(&arrOption, 0, "queryyetsimple/cookie/cookie.zep", 326);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arrOption), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&strName);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&strName, _2);
		} else {
			ZVAL_LONG(&strName, _1);
		}
		ZEPHIR_INIT_NVAR(&mixValue);
		ZVAL_COPY(&mixValue, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "option", &_3, 0, &strName, &mixValue);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&mixValue);
	ZEPHIR_INIT_NVAR(&strName);
	RETURN_THIS();

}

/**
 * 获取单个配置
 *
 * @param string $strName
 * @param mixed $mixDefault
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, getOption) {

	zval *strName_param = NULL, *mixDefault = NULL, mixDefault_sub, __$null, _0, _1, _2;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&mixDefault_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strName_param, &mixDefault);

	zephir_get_strval(&strName, strName_param);
	if (!mixDefault) {
		mixDefault = &mixDefault_sub;
		mixDefault = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &strName)) {
		zephir_read_property(&_2, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &strName, PH_NOISY, "queryyetsimple/cookie/cookie.zep", 338 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, mixDefault);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 获取所有配置
 *
 * @param array $arrOption
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, getOptions) {

	zval *arrOption_param = NULL, _0$$3;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&arrOption))) {
		zephir_read_property(&_0$$3, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(return_value, &_0$$3, &arrOption TSRMLS_CC);
		RETURN_MM();
	} else {
		RETURN_MM_MEMBER(getThis(), "arrOption");
	}

}

/**
 * 删除单个配置
 *
 * @param string $strName
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, deleteOption) {

	zval *strName_param = NULL, _0, _1$$3;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strName_param);

	zephir_get_strval(&strName, strName_param);


	zephir_read_property(&_0, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &strName)) {
		zephir_read_property(&_1$$3, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &strName, PH_SEPARATE);
	}
	RETURN_THIS();

}

/**
 * 删除多个配置
 *
 * @param array $arrOption
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, deleteOptions) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, strOption, *_0;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&strOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&arrOption))) {
		RETURN_THIS();
	}
	zephir_is_iterable(&arrOption, 0, "queryyetsimple/cookie/cookie.zep", 389);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrOption), _0)
	{
		ZEPHIR_INIT_NVAR(&strOption);
		ZVAL_COPY(&strOption, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteoption", &_1, 0, &strOption);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&strOption);
	RETURN_THIS();

}

/**
 * 验证是否为正常的 JSON 字符串
 *
 * @param mixed $mixData
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Cookie_Cookie, isJson) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixData, mixData_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixData_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixData);



	_0 = !(zephir_is_scalar(mixData));
	if (_0) {
		_0 = !((zephir_method_exists_ex(mixData, SL("__tostring") TSRMLS_CC) == SUCCESS));
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_json_decode(&_1, mixData, 0 );
	ZEPHIR_CALL_FUNCTION(&_2, "json_last_error", NULL, 7);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_2, 0));

}

zend_object *zephir_init_properties_Queryyetsimple_Cookie_Cookie(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval __$false, _0;
		ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 5, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("prefix"), SL("q_"));
			add_assoc_long_ex(&_1$$3, SL("expire"), 86400);
			add_assoc_stringl_ex(&_1$$3, SL("domain"), SL(""));
			add_assoc_stringl_ex(&_1$$3, SL("path"), SL("/"));
			zephir_array_update_string(&_1$$3, SL("httponly"), &__$false, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("arrOption"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

