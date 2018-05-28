
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/main.h"
#include "kernel/time.h"
#include "kernel/concat.h"


/**
 * session 仓储
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.09
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Session_Session) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Session, Session, leevel, session_session, leevel_session_session_method_entry, 0);

	/**
	 * session handler 
	 *
	 * @var \SessionHandlerInterface|null
	 */
	zend_declare_property_null(leevel_session_session_ce, SL("connect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * session 是否开启
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(leevel_session_session_ce, SL("started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_session_session_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_session_session_ce->create_object = zephir_init_properties_Leevel_Session_Session;
	/**
	 * session 状态启用
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_session_session_ce, SL("SESSION_ACTIVE"), 2);

	/**
	 * session 状态未运行
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_session_session_ce, SL("SESSION_NONE"), 1);

	/**
	 * session 状态关闭
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_session_session_ce, SL("SESSION_DISABLED"), 0);

	zend_class_implements(leevel_session_session_ce TSRMLS_CC, 1, leevel_session_isession_ce);
	zend_class_implements(leevel_session_session_ce TSRMLS_CC, 1, leevel_option_iclass_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \SessionHandlerInterface|null $connect
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *connect = NULL, connect_sub, *option_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &connect, &option_param);

	if (!connect) {
		connect = &connect_sub;
		connect = &__$null;
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	zephir_update_property_zval(this_ptr, SL("connect"), connect);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "options", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 启动 session
 *
 * @return $this
 */
PHP_METHOD(Leevel_Session_Session, start) {

	zend_bool _1, _3, _30;
	zval __$true, __$false, _0, _2, _4, _5, _6, _7, _11, _14, _17, _20, _23, _26, _29, _31, _32, _38, _9$$4, _10$$4, _12$$5, _13$$5, _15$$6, _16$$6, _18$$7, _19$$7, _21$$8, _22$$8, _24$$9, _25$$9, _27$$10, _28$$10, _33$$11, _34$$11, _35$$11, _36$$11, _37$$11;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_34$$11);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&_36$$11);
	ZVAL_UNDEF(&_37$$11);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 16);
	zephir_check_call_status();
	_1 = zephir_is_true(&_0);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "isstart", NULL, 0);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	_3 = _1;
	if (!(_3)) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "status", NULL, 0);
		zephir_check_call_status();
		_3 = ZEPHIR_IS_LONG_IDENTICAL(&_4, 2);
	}
	if (_3) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "session.auto_start");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "0");
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 68, &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "id");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "id");
		ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "getoption", &_8, 0, &_10$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setid", NULL, 0, &_9$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "name");
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_11)) {
		ZEPHIR_INIT_VAR(&_13$$5);
		ZVAL_STRING(&_13$$5, "name");
		ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getoption", &_8, 0, &_13$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setname", NULL, 0, &_12$$5);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setusecookies", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "save_path");
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		ZEPHIR_INIT_VAR(&_16$$6);
		ZVAL_STRING(&_16$$6, "save_path");
		ZEPHIR_CALL_METHOD(&_15$$6, this_ptr, "getoption", &_8, 0, &_16$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsavepath", NULL, 0, &_15$$6);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "cookie_domain");
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		ZEPHIR_INIT_VAR(&_19$$7);
		ZVAL_STRING(&_19$$7, "cookie_domain");
		ZEPHIR_CALL_METHOD(&_18$$7, this_ptr, "getoption", &_8, 0, &_19$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcookiedomain", NULL, 0, &_18$$7);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "expire");
	ZEPHIR_CALL_METHOD(&_20, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		ZEPHIR_INIT_VAR(&_22$$8);
		ZVAL_STRING(&_22$$8, "expire");
		ZEPHIR_CALL_METHOD(&_21$$8, this_ptr, "getoption", &_8, 0, &_22$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcacheexpire", NULL, 0, &_21$$8);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "cache_limiter");
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_23)) {
		ZEPHIR_INIT_VAR(&_25$$9);
		ZVAL_STRING(&_25$$9, "cache_limiter");
		ZEPHIR_CALL_METHOD(&_24$$9, this_ptr, "getoption", &_8, 0, &_25$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcachelimiter", NULL, 0, &_24$$9);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "gc_probability");
	ZEPHIR_CALL_METHOD(&_26, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_26)) {
		ZEPHIR_INIT_VAR(&_28$$10);
		ZVAL_STRING(&_28$$10, "gc_probability");
		ZEPHIR_CALL_METHOD(&_27$$10, this_ptr, "getoption", &_8, 0, &_28$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setgcprobability", NULL, 0, &_27$$10);
		zephir_check_call_status();
	}
	zephir_read_property(&_29, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
	_30 = zephir_is_true(&_29);
	if (_30) {
		zephir_read_property(&_31, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_32, "session_set_save_handler", NULL, 136, &_31);
		zephir_check_call_status();
		_30 = !zephir_is_true(&_32);
	}
	if (_30) {
		ZEPHIR_INIT_VAR(&_33$$11);
		object_init_ex(&_33$$11, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_34$$11);
		zephir_read_property(&_35$$11, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
		zephir_get_class(&_34$$11, &_35$$11, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_36$$11);
		ZVAL_STRING(&_36$$11, "Session drive %s settings failed.");
		ZEPHIR_CALL_FUNCTION(&_37$$11, "sprintf", NULL, 1, &_36$$11, &_34$$11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_33$$11, "__construct", NULL, 2, &_37$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_33$$11, "leevel/session/session.zep", 154 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_38, "session_start", NULL, 137);
	zephir_check_call_status();
	if (!(zephir_is_true(&_38))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Session start failed", "leevel/session/session.zep", 159);
		return;
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("started"), &__$false);
	}
	RETURN_THIS();

}

/**
 * 设置 session
 *
 * @param string $name
 * @param mxied $value
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, *_SESSION, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getnormalizename", NULL, 0, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	zephir_array_update_zval(_SESSION, &name, value, PH_COPY | PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * 批量插入
 *
 * @param string|array $keys
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, put) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL, keys_sub, *value = NULL, value_sub, __$null, item, *_0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&item);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keys, &value);

	ZEPHIR_SEPARATE_PARAM(keys);
	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(keys);
		zephir_create_array(keys, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(keys, keys, value, PH_COPY);
	}
	zephir_is_iterable(keys, 0, "leevel/session/session.zep", 204);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(keys), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&item, _2);
		} else {
			ZVAL_LONG(&item, _1);
		}
		ZEPHIR_INIT_NVAR(value);
		ZVAL_COPY(value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, &item, value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(value);
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组插入数据
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, push) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, arr, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &key, &_0);
	zephir_check_call_status();
	zephir_array_append(&arr, value, PH_SEPARATE, "leevel/session/session.zep", 218);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &arr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并元素
 *
 * @param string $key
 * @param array $value
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, merge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *key_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value_param);

	zephir_get_strval(&key, key_param);
	zephir_get_arrval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &key, &_2);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &value TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "array_unique", NULL, 84, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出元素
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, pop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *key_param = NULL, *value_param = NULL, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value_param);

	zephir_get_strval(&key, key_param);
	zephir_get_arrval(&value, value_param);


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &key, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "array_diff", NULL, 85, &_0, &value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组插入键值对数据
 *
 * @param string $key
 * @param mixed $keys
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, arr) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *keys, keys_sub, *value = NULL, value_sub, __$null, arr, _0, _1$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &keys, &value);

	zephir_get_strval(&key, key_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &key, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_STRING) {
		zephir_array_update_zval(&arr, keys, value, PH_COPY | PH_SEPARATE);
	} else if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_array_merge(&_1$$4, &arr, keys TSRMLS_CC);
		ZEPHIR_CPY_WRT(&arr, &_1$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &arr);
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
PHP_METHOD(Leevel_Session_Session, arrDelete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *keys, keys_sub, arr, item, deleteKey, _0, *_1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&deleteKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &keys);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &key, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&deleteKey);
		zephir_create_array(&deleteKey, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&deleteKey, keys);
	} else {
		ZEPHIR_CPY_WRT(&deleteKey, keys);
	}
	zephir_is_iterable(&deleteKey, 0, "leevel/session/session.zep", 297);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&deleteKey), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		if (zephir_array_isset(&arr, &item)) {
			zephir_array_unset(&arr, &item, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &arr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 取回 session
 *
 * @param string $name
 * @param mixed $value
 * @return mxied
 */
PHP_METHOD(Leevel_Session_Session, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, value_sub, *_SESSION, __$null, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 1, &name_param, &value);

	zephir_get_strval(&name, name_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getnormalizename", NULL, 0, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_array_isset(_SESSION, &name)) {
		zephir_array_fetch(&_1, _SESSION, &name, PH_NOISY, "leevel/session/session.zep", 313 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_1, value);
	}
	RETURN_CCTOR(&_1);

}

/**
 * 返回数组部分数据
 *
 * @param string $name
 * @param mixed $value
 * @return mixed
 */
PHP_METHOD(Leevel_Session_Session, getPart) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, value_sub, __$null;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &value);

	zephir_get_strval(&name, name_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getpartdata", NULL, 0, &name, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除 session
 *
 * @param string $name
 * @param boolean $prefix
 * @return bool
 */
PHP_METHOD(Leevel_Session_Session, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool prefix;
	zval *name_param = NULL, *prefix_param = NULL, *_SESSION, _0$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 1, &name_param, &prefix_param);

	zephir_get_strval(&name, name_param);
	if (!prefix_param) {
		prefix = 1;
	} else {
		prefix = zephir_get_boolval(prefix_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	if (prefix) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getnormalizename", NULL, 0, &name);
		zephir_check_call_status();
		zephir_get_strval(&name, &_0$$3);
	}
	if (zephir_array_isset(_SESSION, &name)) {
		zephir_array_unset(_SESSION, &name, PH_SEPARATE);
	}
	RETURN_MM_BOOL(1);

}

/**
 * 是否存在 session
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Leevel_Session_Session, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_SESSION, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getnormalizename", NULL, 0, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	RETURN_MM_BOOL(zephir_array_isset(_SESSION, &name));

}

/**
 * 删除 session
 *
 * @param boolean $prefix
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, clear) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *_SESSION, strPrefix, sKey, _0, *_1, _6$$3, _7$$4, _9$$5;
	zend_bool prefix, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strPrefix);
	ZVAL_UNDEF(&sKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		prefix = 1;
	} else {
		prefix = zephir_get_boolval(prefix_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "prefix");
	ZEPHIR_CALL_METHOD(&strPrefix, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	zephir_is_iterable(_SESSION, 0, "leevel/session/session.zep", 385);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_SESSION), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&sKey);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&sKey, _3);
		} else {
			ZVAL_LONG(&sKey, _2);
		}
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_COPY(&_0, _1);
		_4$$3 = prefix == 1;
		if (_4$$3) {
			_4$$3 = zephir_is_true(&strPrefix);
		}
		_5$$3 = _4$$3;
		if (_5$$3) {
			ZEPHIR_INIT_NVAR(&_6$$3);
			zephir_fast_strpos(&_6$$3, &sKey, &strPrefix, 0 );
			_5$$3 = ZEPHIR_IS_LONG_IDENTICAL(&_6$$3, 0);
		}
		if (_5$$3) {
			ZVAL_BOOL(&_7$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_8, 0, &sKey, &_7$$4);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(&_9$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_8, 0, &sKey, &_9$$5);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&sKey);
	ZEPHIR_MM_RESTORE();

}

/**
 * 闪存一个数据，当前请求和下一个请求可用
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, flash) {

	zval _1$$4, _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value = NULL, value_sub, __$null, _0$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value);

	zephir_get_strval(&key, key_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getflash", NULL, 0, &key);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "flashdatakey", NULL, 0, &key);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_0$$4, value);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$4, &key);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergenewflash", NULL, 0, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_2$$4, &key);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "popoldflash", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 批量闪存数据，当前请求和下一个请求可用
 *
 * @param array $flash
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, flashs) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *flash_param = NULL, item, value, *_0;
	zval flash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flash);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &flash_param);

	zephir_get_arrval(&flash, flash_param);


	zephir_is_iterable(&flash, 0, "leevel/session/session.zep", 424);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&flash), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&item, _2);
		} else {
			ZVAL_LONG(&item, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flash", &_3, 0, &item, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 闪存一个 flash 用于当前请求使用，下一个请求将无法获取
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, nowFlash) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashdatakey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_0, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &key);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergeoldflash", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 保持所有闪存数据
 *
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, rebuildFlash) {

	zval _0, _1, _3, _4, _5;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_1, this_ptr, "flasholdkey", &_2, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergenewflash", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "flasholdkey", &_2, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 保持闪存数据
 *
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, keepFlash) {

	zval keys, args, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_BadMethodCallException, "Wrong number of parameters", "leevel/session/session.zep", 465);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_long(&_1, &args, 0, PH_NOISY, "leevel/session/session.zep", 468 TSRMLS_CC);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, &keys);
	} else {
		ZEPHIR_CPY_WRT(&_0, &args);
	}
	ZEPHIR_CPY_WRT(&keys, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergenewflash", NULL, 0, &keys);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "popoldflash", NULL, 0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回闪存数据
 *
 * @param string $key
 * @param mixed $defaults
 * @return mixed
 */
PHP_METHOD(Leevel_Session_Session, getFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, _0, _1, _2$$3, _3$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaults);

	zephir_get_strval(&key, key_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &key, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "flash");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getpartdata", NULL, 0, &key, defaults, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "flashdatakey", NULL, 0, &key);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_3$$4, defaults);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * 删除闪存数据
 *
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, deleteFlash) {

	zval item, keys, args, _0, _1, *_2, _3$$4;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_BadMethodCallException, "Wrong number of parameters", "leevel/session/session.zep", 502);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_long(&_1, &args, 0, PH_NOISY, "leevel/session/session.zep", 505 TSRMLS_CC);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, &keys);
	} else {
		ZEPHIR_CPY_WRT(&_0, &args);
	}
	ZEPHIR_CPY_WRT(&keys, &_0);
	zephir_is_iterable(&keys, 0, "leevel/session/session.zep", 511);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _2)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _2);
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "flashdatakey", &_4, 0, &item);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_5, 0, &_3$$4);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergeoldflash", NULL, 0, &keys);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "popnewflash", NULL, 0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清理所有闪存数据
 *
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, clearFlash) {

	zval _6$$3;
	zend_string *_5;
	zend_ulong _4;
	zval item, newKey, _0, _1, _2, *_3, _7$$3;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&newKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_METHOD(&newKey, this_ptr, "get", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_is_iterable(&newKey, 0, "leevel/session/session.zep", 529);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&newKey), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&item);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&item, _5);
		} else {
			ZVAL_LONG(&item, _4);
		}
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_COPY(&_2, _3);
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_create_array(&_6$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_6$$3, this_ptr);
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "deleteFlash");
		zephir_array_fast_append(&_6$$3, &_7$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_8, 8, &_6$$3, &item);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 程序执行结束清理 flash
 *
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, unregisterFlash) {

	zval arr, old, item, _0, _1$$3, _3$$3, _5$$3, _7$$3, *_8$$3, _12$$3, _13$$3, _9$$4;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_6 = NULL, *_10 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&old);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstart", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "flashnewkey", &_2, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		array_init(&_3$$3);
		ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", &_4, 0, &_1$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "flasholdkey", &_6, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$3);
		array_init(&_7$$3);
		ZEPHIR_CALL_METHOD(&old, this_ptr, "get", &_4, 0, &_5$$3, &_7$$3);
		zephir_check_call_status();
		zephir_is_iterable(&old, 0, "leevel/session/session.zep", 548);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&old), _8$$3)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _8$$3);
			ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "flashdatakey", &_10, 0, &item);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_11, 0, &_9$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
		ZEPHIR_CALL_METHOD(&_12$$3, this_ptr, "flashnewkey", &_2, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_11, 0, &_12$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13$$3, this_ptr, "flasholdkey", &_6, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_13$$3, &arr);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取前一个请求地址
 *
 * @return string|null
 */
PHP_METHOD(Leevel_Session_Session, prevUrl) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "prevurlkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置前一个请求地址
 *
 * @param string $url
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, setPrevUrl) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, _0;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "prevurlkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &_0, &url);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 暂停 session
 *
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, pause) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 138);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 终止会话
 *
 * @return bool
 */
PHP_METHOD(Leevel_Session_Session, destroy) {

	zval *_COOKIE, name, _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	if (!_COOKIE) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&name, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset(_COOKIE, &name)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_time(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "");
		ZVAL_LONG(&_3$$3, (zephir_get_numberval(&_1$$3) - 42000));
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "/");
		ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 139, &name, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "session_destroy", NULL, 140);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * session 是否已经启动
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Session_Session, isStart) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "started");

}

/**
 * session 状态
 *
 * @return int
 */
PHP_METHOD(Leevel_Session_Session, status) {

	zval status;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&status, "session_status", NULL, 141);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(&status, 0)) {
			RETURN_MM_LONG(0);
		}
		if (ZEPHIR_IS_LONG(&status, 2)) {
			RETURN_MM_LONG(2);
		}
	} while(0);

	RETURN_MM_LONG(1);

}

/**
 * 设置 SESSION 名字
 *
 * @param string $name
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, setName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_name", NULL, 142, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得 SESSION 名字
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, getName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_name", NULL, 142);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置 SESSION ID
 *
 * @param string $name
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, setId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 143, &id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得 SESSION ID
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, getId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_id", NULL, 143);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 重新生成 SESSION ID
 * 
 * @param bool $deleteOldSession
 * @return $this
 */
PHP_METHOD(Leevel_Session_Session, regenerateId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *deleteOldSession_param = NULL, _0;
	zend_bool deleteOldSession;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &deleteOldSession_param);

	if (!deleteOldSession_param) {
		deleteOldSession = 1;
	} else {
		deleteOldSession = zephir_get_boolval(deleteOldSession_param);
	}


	ZVAL_BOOL(&_0, (deleteOldSession ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(NULL, "session_regenerate_id", NULL, 144, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 设置 save path
 *
 * @param string $savepath
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, setSavePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *savepath_param = NULL;
	zval savepath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savepath);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepath_param);

	zephir_get_strval(&savepath, savepath_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_save_path", NULL, 145, &savepath);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取 save path
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, getSavePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_save_path", NULL, 145);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置 cookie_domain
 *
 * @param string $domain
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, setCookieDomain) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *domain_param = NULL, _0;
	zval domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain_param);

	zephir_get_strval(&domain, domain_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.cookie_domain");
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 68, &_0, &domain);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取 cookie_domain
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, getCookieDomain) {

	zval result, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.cookie_domain");
	ZEPHIR_CALL_FUNCTION(&result, "ini_get", NULL, 113, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&result);

}

/**
 * 设置 cache expire
 *
 * @param int $second
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, setCacheExpire) {

	zephir_fcall_cache_entry *_3 = NULL;
	zval *second_param = NULL, _0, _1, _2;
	zend_long second, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &second_param);

	second = zephir_get_intval(second_param);


	ZVAL_LONG(&_0, second);
	ZEPHIR_CALL_FUNCTION(&_1, "strval", NULL, 11, &_0);
	zephir_check_call_status();
	second = zephir_get_numberval(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "session.gc_maxlifetime");
	ZVAL_LONG(&_0, second);
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_3, 68, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "session.cookie_lifetime");
	ZVAL_LONG(&_0, second);
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_3, 68, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * session 使用 cookie
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Session_Session, setUseCookies) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.use_cookies");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "1");
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 68, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "session.use_trans_sid");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "0");
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", &_2, 68, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置 cache limiter
 *
 * @param string $limiter
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, setCacheLimiter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *limiter_param = NULL;
	zval limiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limiter);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &limiter_param);

	zephir_get_strval(&limiter, limiter_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_cache_limiter", NULL, 146, &limiter);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取 cache limiter
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, getCacheLimiter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_cache_limiter", NULL, 146);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置 session 垃圾回收概率分子
 * 分母为 session.gc_divisor
 *
 * @param int $probability
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, setGcProbability) {

	zend_bool _2;
	zval *probability_param = NULL, _0, _1, _3$$3, _4$$3;
	zend_long probability, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &probability_param);

	probability = zephir_get_intval(probability_param);


	ZVAL_LONG(&_0, probability);
	ZEPHIR_CALL_FUNCTION(&_1, "strval", NULL, 11, &_0);
	zephir_check_call_status();
	probability = zephir_get_numberval(&_1);
	_2 = probability >= 1;
	if (_2) {
		_2 = probability <= 100;
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "session.gc_probability");
		ZVAL_LONG(&_4$$3, probability);
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 68, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取 session 垃圾回收概率分子
 * 分母为 session.gc_divisor
 *
 * @return int
 */
PHP_METHOD(Leevel_Session_Session, getGcProbability) {

	zval result, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.gc_probability");
	ZEPHIR_CALL_FUNCTION(&result, "ini_get", NULL, 113, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&result);

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Leevel_Session_Session, option) {

	zend_class_entry *_1$$3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, _0$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	if (!(Z_TYPE_P(&name) == IS_STRING)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (!_1$$3) {
		_1$$3 = zephir_fetch_class_str_ex(SL("Leevel\\Session\\InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_0$$3, _1$$3);
		if (zephir_has_constructor(&_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Option set name must be a string.");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_2$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_0$$3, "leevel/session/session.zep", 826 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
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
PHP_METHOD(Leevel_Session_Session, optionArray) {

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
PHP_METHOD(Leevel_Session_Session, options) {

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
	zephir_is_iterable(&option, 0, "leevel/session/session.zep", 865);
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
PHP_METHOD(Leevel_Session_Session, getOption) {

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
		zephir_array_fetch(&_0, &_2, &name, PH_NOISY, "leevel/session/session.zep", 877 TSRMLS_CC);
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
PHP_METHOD(Leevel_Session_Session, getOptions) {

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
PHP_METHOD(Leevel_Session_Session, deleteOption) {

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
PHP_METHOD(Leevel_Session_Session, deleteOptions) {

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
	zephir_is_iterable(&option, 0, "leevel/session/session.zep", 928);
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
 * 返回 session 名字
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, getNormalizeName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "prefix");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &name);
	RETURN_MM();

}

/**
 * 验证 session 是否开启
 *
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, checkStart) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstart", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Session is not start yet", "leevel/session/session.zep", 950);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出旧闪存 KEY
 *
 * @param array $keys
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, popOldFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flasholdkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pop", NULL, 0, &_0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并旧闪存 KEY
 *
 * @param array $keys
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, mergeOldFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flasholdkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", NULL, 0, &_0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出新闪存 KEY
 *
 * @param array $keys
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, popNewFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pop", NULL, 0, &_0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并新闪存 KEY
 *
 * @param array $keys
 * @return void
 */
PHP_METHOD(Leevel_Session_Session, mergeNewFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", NULL, 0, &_0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回部分闪存数据
 *
 * @param string $key
 * @param mixed $defaults
 * @param string $type
 * @return mixed
 */
PHP_METHOD(Leevel_Session_Session, getPartData) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key = NULL, key_sub, *defaults = NULL, defaults_sub, *type = NULL, type_sub, __$null, name, value, parts, part, tempkeys, tempkey, _1$$3, _2$$4, _3$$4, *_5$$4, _4$$5, _6$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&tempkeys);
	ZVAL_UNDEF(&tempkey);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &key, &defaults, &type);

	ZEPHIR_SEPARATE_PARAM(key);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}


	ZEPHIR_INIT_VAR(&tempkeys);
	zephir_fast_explode_str(&tempkeys, SL("\\"), key, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(&tempkeys);
	ZEPHIR_CALL_FUNCTION(&tempkey, "array_shift", &_0, 6, &tempkeys);
	ZEPHIR_UNREF(&tempkeys);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, &tempkey);
	ZEPHIR_MAKE_REF(&tempkeys);
	ZEPHIR_CALL_FUNCTION(&name, "array_shift", &_0, 6, &tempkeys);
	ZEPHIR_UNREF(&tempkeys);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(type, "flash")) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "flashdatakey", NULL, 0, key);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(key, &_1$$3);
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "get", NULL, 0, key);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, ".");
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_fast_strpos(&_3$$4, &name, &_2$$4, 0 );
		if (!(zephir_is_true(&_3$$4))) {
			ZEPHIR_INIT_VAR(&_4$$5);
			if (zephir_array_key_exists(&value, &name TSRMLS_CC)) {
				zephir_array_fetch(&_4$$5, &value, &name, PH_NOISY, "leevel/session/session.zep", 1021 TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(&_4$$5, defaults);
			}
			RETURN_CCTOR(&_4$$5);
		}
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("."), &name, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(&parts, 0, "leevel/session/session.zep", 1032);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _5$$4)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _5$$4);
			if (!(zephir_array_isset(&value, &part))) {
				RETVAL_ZVAL(defaults, 1, 0);
				RETURN_MM();
			}
			zephir_array_fetch(&_6$$6, &value, &part, PH_NOISY | PH_READONLY, "leevel/session/session.zep", 1029 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&value, &_6$$6);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&part);
		RETURN_CCTOR(&value);
	} else {
		RETVAL_ZVAL(defaults, 1, 0);
		RETURN_MM();
	}

}

/**
 * 闪存值 KEY
 *
 * @param string $key
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, flashDataKey) {

	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CONCAT_SV(return_value, "flash.data.", &key);
	RETURN_MM();

}

/**
 * 新值闪存 KEY
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, flashNewKey) {

	zval *this_ptr = getThis();


	RETURN_STRING("flash.new.key");

}

/**
 * 旧值闪存 KEY
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, flashOldKey) {

	zval *this_ptr = getThis();


	RETURN_STRING("flash.old.key");

}

/**
 * 前一个页面 KEY
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, prevUrlKey) {

	zval *this_ptr = getThis();


	RETURN_STRING("prev.url.key");

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Session_Session, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args, _4;
	zval *method_param = NULL, *args_param = NULL, _0, _5, _1$$3, _2$$3, _3$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("connect"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_BadMethodCallException);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Method %s is not exits.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, &method);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "leevel/session/session.zep", 1089 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("connect"), PH_NOISY_CC);
	zephir_array_fast_append(&_4, &_5);
	zephir_array_fast_append(&_4, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_4, &args);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Session_Session(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval __$null, _0;
		ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 9, 0 TSRMLS_CC);
			zephir_array_update_string(&_1$$3, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_1$$3, SL("prefix"), SL("q_"));
			zephir_array_update_string(&_1$$3, SL("id"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("name"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("cookie_domain"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("cache_limiter"), &__$null, PH_COPY | PH_SEPARATE);
			add_assoc_long_ex(&_1$$3, SL("expire"), 86400);
			zephir_array_update_string(&_1$$3, SL("save_path"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("gc_probability"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

