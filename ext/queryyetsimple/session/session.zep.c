
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
ZEPHIR_INIT_CLASS(Queryyetsimple_Session_Session) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Session, Session, queryyetsimple, session_session, queryyetsimple_session_session_method_entry, 0);

	/**
	 * session handler 
	 *
	 * @var \SessionHandlerInterface|null
	 */
	zend_declare_property_null(queryyetsimple_session_session_ce, SL("connect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * session 是否开启
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(queryyetsimple_session_session_ce, SL("started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_session_session_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_session_session_ce->create_object = zephir_init_properties_Queryyetsimple_Session_Session;
	/**
	 * session 状态启用
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(queryyetsimple_session_session_ce, SL("SESSION_ACTIVE"), 2);

	/**
	 * session 状态未运行
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(queryyetsimple_session_session_ce, SL("SESSION_NONE"), 1);

	/**
	 * session 状态关闭
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(queryyetsimple_session_session_ce, SL("SESSION_DISABLED"), 0);

	zend_class_implements(queryyetsimple_session_session_ce TSRMLS_CC, 1, queryyetsimple_session_isession_ce);
	zend_class_implements(queryyetsimple_session_session_ce TSRMLS_CC, 1, queryyetsimple_option_iclass_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \SessionHandlerInterface|null $connect
 * @param array $option
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, __construct) {

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
PHP_METHOD(Queryyetsimple_Session_Session, start) {

	zend_bool _1, _3, _42;
	zval __$true, __$false, _0, _2, _4, _5, _6, _7, _15, _18, _21, _24, _27, _30, _33, _36, _39, _43, _44, _50, _9$$4, _10$$4, _11$$5, _12$$6, _13$$6, _14$$6, _16$$7, _17$$7, _19$$8, _20$$8, _22$$9, _23$$9, _25$$10, _26$$10, _28$$11, _29$$11, _31$$12, _32$$12, _34$$13, _35$$13, _37$$14, _38$$14, _40$$15, _41$$15, _45$$16, _46$$16, _47$$16, _48$$16, _49$$16;
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
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_50);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_45$$16);
	ZVAL_UNDEF(&_46$$16);
	ZVAL_UNDEF(&_47$$16);
	ZVAL_UNDEF(&_48$$16);
	ZVAL_UNDEF(&_49$$16);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 46);
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
	ZVAL_LONG(&_6, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 47, &_5, &_6);
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
		ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 48, &_9$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "parsesessionid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_11$$5))) {
			ZEPHIR_CALL_FUNCTION(&_12$$6, "mt_rand", NULL, 49);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_13$$6, "dechex", NULL, 50, &_12$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_14$$6, "uniqid", NULL, 51, &_13$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "sessionid", NULL, 0, &_14$$6);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "cookie_domain");
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		ZEPHIR_INIT_VAR(&_17$$7);
		ZVAL_STRING(&_17$$7, "cookie_domain");
		ZEPHIR_CALL_METHOD(&_16$$7, this_ptr, "getoption", &_8, 0, &_17$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cookiedomain", NULL, 0, &_16$$7);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "name");
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_18)) {
		ZEPHIR_INIT_VAR(&_20$$8);
		ZVAL_STRING(&_20$$8, "name");
		ZEPHIR_CALL_METHOD(&_19$$8, this_ptr, "getoption", &_8, 0, &_20$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "sessionname", NULL, 0, &_19$$8);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "expire");
	ZEPHIR_CALL_METHOD(&_21, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_21)) {
		ZEPHIR_INIT_VAR(&_23$$9);
		ZVAL_STRING(&_23$$9, "expire");
		ZEPHIR_CALL_METHOD(&_22$$9, this_ptr, "getoption", &_8, 0, &_23$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cacheexpire", NULL, 0, &_22$$9);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "gc_maxlifetime");
	ZEPHIR_CALL_METHOD(&_24, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_24)) {
		ZEPHIR_INIT_VAR(&_26$$10);
		ZVAL_STRING(&_26$$10, "gc_maxlifetime");
		ZEPHIR_CALL_METHOD(&_25$$10, this_ptr, "getoption", &_8, 0, &_26$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "gcmaxlifetime", NULL, 0, &_25$$10);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "cookie_lifetime");
	ZEPHIR_CALL_METHOD(&_27, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_27)) {
		ZEPHIR_INIT_VAR(&_29$$11);
		ZVAL_STRING(&_29$$11, "cookie_lifetime");
		ZEPHIR_CALL_METHOD(&_28$$11, this_ptr, "getoption", &_8, 0, &_29$$11);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cookielifetime", NULL, 0, &_28$$11);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "cache_limiter");
	ZEPHIR_CALL_METHOD(&_30, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_30)) {
		ZEPHIR_INIT_VAR(&_32$$12);
		ZVAL_STRING(&_32$$12, "cache_limiter");
		ZEPHIR_CALL_METHOD(&_31$$12, this_ptr, "getoption", &_8, 0, &_32$$12);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cachelimiter", NULL, 0, &_31$$12);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "save_path");
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_33)) {
		ZEPHIR_INIT_VAR(&_35$$13);
		ZVAL_STRING(&_35$$13, "save_path");
		ZEPHIR_CALL_METHOD(&_34$$13, this_ptr, "getoption", &_8, 0, &_35$$13);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "savepath", NULL, 0, &_34$$13);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "use_trans_sid");
	ZEPHIR_CALL_METHOD(&_36, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_36)) {
		ZEPHIR_INIT_VAR(&_38$$14);
		ZVAL_STRING(&_38$$14, "use_trans_sid");
		ZEPHIR_CALL_METHOD(&_37$$14, this_ptr, "getoption", &_8, 0, &_38$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "usetranssid", NULL, 0, &_37$$14);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "gc_probability");
	ZEPHIR_CALL_METHOD(&_39, this_ptr, "getoption", &_8, 0, &_5);
	zephir_check_call_status();
	if (zephir_is_true(&_39)) {
		ZEPHIR_INIT_VAR(&_41$$15);
		ZVAL_STRING(&_41$$15, "gc_probability");
		ZEPHIR_CALL_METHOD(&_40$$15, this_ptr, "getoption", &_8, 0, &_41$$15);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "gcprobability", NULL, 0, &_40$$15);
		zephir_check_call_status();
	}
	zephir_read_property(&_6, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
	_42 = zephir_is_true(&_6);
	if (_42) {
		zephir_read_property(&_43, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_44, "session_set_save_handler", NULL, 52, &_43);
		zephir_check_call_status();
		_42 = !zephir_is_true(&_44);
	}
	if (_42) {
		ZEPHIR_INIT_VAR(&_45$$16);
		object_init_ex(&_45$$16, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_46$$16);
		zephir_read_property(&_47$$16, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
		zephir_get_class(&_46$$16, &_47$$16, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_48$$16);
		ZVAL_STRING(&_48$$16, "Session drive %s settings failed.");
		ZEPHIR_CALL_FUNCTION(&_49$$16, "sprintf", NULL, 1, &_48$$16, &_46$$16);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_45$$16, "__construct", NULL, 2, &_49$$16);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_45$$16, "queryyetsimple/session/session.zep", 176 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_50, "session_start", NULL, 53);
	zephir_check_call_status();
	if (!(zephir_is_true(&_50))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Session start failed", "queryyetsimple/session/session.zep", 181);
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
PHP_METHOD(Queryyetsimple_Session_Session, set) {

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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getname", NULL, 0, &name);
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
PHP_METHOD(Queryyetsimple_Session_Session, put) {

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
	zephir_is_iterable(keys, 0, "queryyetsimple/session/session.zep", 226);
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
PHP_METHOD(Queryyetsimple_Session_Session, push) {

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
	zephir_array_append(&arr, value, PH_SEPARATE, "queryyetsimple/session/session.zep", 239);
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
PHP_METHOD(Queryyetsimple_Session_Session, merge) {

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
	ZEPHIR_CALL_FUNCTION(&_3, "array_unique", NULL, 20, &_0);
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
PHP_METHOD(Queryyetsimple_Session_Session, pop) {

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
	ZEPHIR_CALL_FUNCTION(&_2, "array_diff", NULL, 21, &_0, &value);
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
PHP_METHOD(Queryyetsimple_Session_Session, arr) {

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
PHP_METHOD(Queryyetsimple_Session_Session, arrDelete) {

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
	zephir_is_iterable(&deleteKey, 0, "queryyetsimple/session/session.zep", 311);
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
PHP_METHOD(Queryyetsimple_Session_Session, get) {

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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getname", NULL, 0, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_array_isset(_SESSION, &name)) {
		zephir_array_fetch(&_1, _SESSION, &name, PH_NOISY, "queryyetsimple/session/session.zep", 326 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Session_Session, getPart) {

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
PHP_METHOD(Queryyetsimple_Session_Session, delete) {

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
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getname", NULL, 0, &name);
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
PHP_METHOD(Queryyetsimple_Session_Session, has) {

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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getname", NULL, 0, &name);
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
PHP_METHOD(Queryyetsimple_Session_Session, clear) {

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
	zephir_is_iterable(_SESSION, 0, "queryyetsimple/session/session.zep", 396);
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
PHP_METHOD(Queryyetsimple_Session_Session, flash) {

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
PHP_METHOD(Queryyetsimple_Session_Session, flashs) {

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


	zephir_is_iterable(&flash, 0, "queryyetsimple/session/session.zep", 433);
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
PHP_METHOD(Queryyetsimple_Session_Session, nowFlash) {

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
PHP_METHOD(Queryyetsimple_Session_Session, rebuildFlash) {

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
 * @param mixed $keys
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, keepFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL, keys_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys);

	ZEPHIR_SEPARATE_PARAM(keys);


	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, keys);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_get_args(&_0);
	}
	ZEPHIR_CPY_WRT(keys, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergenewflash", NULL, 0, keys);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "popoldflash", NULL, 0, keys);
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
PHP_METHOD(Queryyetsimple_Session_Session, getFlash) {

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
 * @param mixed $keys
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, deleteFlash) {

	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL, keys_sub, item, _0, *_1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys);

	ZEPHIR_SEPARATE_PARAM(keys);


	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, keys);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_get_args(&_0);
	}
	ZEPHIR_CPY_WRT(keys, &_0);
	zephir_is_iterable(keys, 0, "queryyetsimple/session/session.zep", 505);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "flashdatakey", &_3, 0, &item);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_4, 0, &_2$$3);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergeoldflash", NULL, 0, keys);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "popnewflash", NULL, 0, keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清理所有闪存数据
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, clearFlash) {

	zend_string *_5;
	zend_ulong _4;
	zval item, newKey, _0, _1, _2, *_3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&newKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_METHOD(&newKey, this_ptr, "get", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_is_iterable(&newKey, 0, "queryyetsimple/session/session.zep", 523);
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteflash", &_6, 0, &item);
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
PHP_METHOD(Queryyetsimple_Session_Session, unregisterFlash) {

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
		zephir_is_iterable(&old, 0, "queryyetsimple/session/session.zep", 542);
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
PHP_METHOD(Queryyetsimple_Session_Session, prevUrl) {

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
PHP_METHOD(Queryyetsimple_Session_Session, setPrevUrl) {

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
PHP_METHOD(Queryyetsimple_Session_Session, pause) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 54);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 终止会话
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Session_Session, destroy) {

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
	ZEPHIR_CALL_METHOD(&name, this_ptr, "sessionname", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset(_COOKIE, &name)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_time(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "");
		ZVAL_LONG(&_3$$3, (zephir_get_numberval(&_1$$3) - 42000));
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "/");
		ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 19, &name, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "session_destroy", NULL, 55);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * session 是否已经启动
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Session_Session, isStart) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "started");

}

/**
 * session 状态
 *
 * @return int
 */
PHP_METHOD(Queryyetsimple_Session_Session, status) {

	zval status;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&status, "session_status", NULL, 56);
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
 * 获取解析 session_id
 *
 * @param string $id
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, parseSessionId) {

	zval *_COOKIE, *_GET, *_POST, id, name, _0, _1$$5, _2$$7, _3$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	if (!_POST) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_GET, SL("_GET"));
	if (!_GET) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	if (!_COOKIE) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}

	ZEPHIR_CALL_METHOD(&id, this_ptr, "sessionid", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&id)) {
		RETURN_CCTOR(&id);
	}
	ZEPHIR_CALL_METHOD(&name, this_ptr, "sessionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "usecookies", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		if (zephir_array_isset(_COOKIE, &name)) {
			zephir_array_fetch(&_1$$5, _COOKIE, &name, PH_NOISY | PH_READONLY, "queryyetsimple/session/session.zep", 650 TSRMLS_CC);
			RETURN_CTOR(&_1$$5);
		}
	} else {
		if (zephir_array_isset(_GET, &name)) {
			zephir_array_fetch(&_2$$7, _GET, &name, PH_NOISY | PH_READONLY, "queryyetsimple/session/session.zep", 654 TSRMLS_CC);
			RETURN_CTOR(&_2$$7);
		}
		if (zephir_array_isset(_POST, &name)) {
			zephir_array_fetch(&_3$$8, _POST, &name, PH_NOISY | PH_READONLY, "queryyetsimple/session/session.zep", 657 TSRMLS_CC);
			RETURN_CTOR(&_3$$8);
		}
	}
	RETURN_MM_NULL();

}

/**
 * 设置 save path
 *
 * @param string $savepath
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, savePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *savepath_param = NULL, _0;
	zval savepath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savepath);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &savepath_param);

	if (!savepath_param) {
		ZEPHIR_INIT_VAR(&savepath);
		ZVAL_STRING(&savepath, "");
	} else {
		zephir_get_strval(&savepath, savepath_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&savepath) == IS_UNDEF) && Z_STRLEN_P(&savepath)) {
		ZEPHIR_CALL_FUNCTION(&_0, "session_save_path", NULL, 57, &savepath);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_save_path", NULL, 57);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置 cache limiter
 *
 * @param string $limiter
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, cacheLimiter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *limiter_param = NULL, _0;
	zval limiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limiter);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &limiter_param);

	if (!limiter_param) {
		ZEPHIR_INIT_VAR(&limiter);
		ZVAL_STRING(&limiter, "");
	} else {
		zephir_get_strval(&limiter, limiter_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&limiter) == IS_UNDEF) && Z_STRLEN_P(&limiter)) {
		ZEPHIR_CALL_FUNCTION(&_0, "session_cache_limiter", NULL, 58, &limiter);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_cache_limiter", NULL, 58);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置 cache expire
 *
 * @param int $second
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, cacheExpire) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *second_param = NULL, _0, _1;
	zval second;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&second);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &second_param);

	if (!second_param) {
		ZEPHIR_INIT_VAR(&second);
		ZVAL_STRING(&second, "");
	} else {
		zephir_get_strval(&second, second_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&second) == IS_UNDEF) && Z_STRLEN_P(&second)) {
		ZVAL_LONG(&_1, zephir_get_intval(&second));
		ZEPHIR_CALL_FUNCTION(&_0, "session_cache_expire", NULL, 59, &_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_cache_expire", NULL, 59);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * session_name
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, sessionName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&name) == IS_UNDEF) && Z_STRLEN_P(&name)) {
		ZEPHIR_CALL_FUNCTION(&_0, "session_name", NULL, 60, &name);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_name", NULL, 60);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * session id
 *
 * @param string $id
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, sessionId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &id_param);

	if (!id_param) {
		ZEPHIR_INIT_VAR(&id);
		ZVAL_STRING(&id, "");
	} else {
		zephir_get_strval(&id, id_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&id) == IS_UNDEF) && Z_STRLEN_P(&id)) {
		ZEPHIR_CALL_FUNCTION(&_0, "session_id", NULL, 48, &id);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_id", NULL, 48);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * session 的 cookie_domain 设置
 *
 * @param string $domain
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, cookieDomain) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *domain_param = NULL, result, _0, _1$$3;
	zval domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &domain_param);

	if (!domain_param) {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_STRING(&domain, "");
	} else {
		zephir_get_strval(&domain, domain_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.cookie_domain");
	ZEPHIR_CALL_FUNCTION(&result, "ini_get", NULL, 61, &_0);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&domain) == IS_UNDEF) && Z_STRLEN_P(&domain)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "session.cookie_domain");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 47, &_1$$3, &domain);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * session 是否使用 cookie
 *
 * @param boolean $cookies
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Session_Session, useCookies) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cookies_param = NULL, result, _0, _1, _2$$3, _3$$3;
	zend_bool cookies;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &cookies_param);

	if (!cookies_param) {
		cookies = 0;
	} else {
		cookies = zephir_get_boolval(cookies_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.use_cookies");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 61, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&result);
		ZVAL_BOOL(&result, 1);
	} else {
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_BOOL(&result, 0);
	}
	if (1 != 0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		if (cookies) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, 1);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, 0);
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "session.use_cookies");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 47, &_3$$3, &_2$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * 客户端禁用 cookie 可以开启这个项
 *
 * @param string $id
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Session_Session, useTransSid) {

	zval *id_param = NULL, result, _0, _1, _2$$3, _3$$3;
	zend_long id, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &id_param);

	if (!id_param) {
		id = 0;
	} else {
		id = zephir_get_intval(id_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.use_trans_sid");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 61, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&result);
		ZVAL_BOOL(&result, 1);
	} else {
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_BOOL(&result, 0);
	}
	if (id) {
		ZEPHIR_INIT_VAR(&_2$$3);
		if (id) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, 1);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, 0);
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "session.use_trans_sid");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 47, &_3$$3, &_2$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * 设置过期 cookie lifetime
 *
 * @param int $lifetime
 * @return int
 */
PHP_METHOD(Queryyetsimple_Session_Session, cookieLifetime) {

	zval *lifetime_param = NULL, result, _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &lifetime_param);

	lifetime = zephir_get_intval(lifetime_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.cookie_lifetime");
	ZEPHIR_CALL_FUNCTION(&result, "ini_get", NULL, 61, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, lifetime);
	if (zephir_get_intval(&_1) >= 1) {
		ZVAL_LONG(&_2$$3, lifetime);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "session.cookie_lifetime");
		ZVAL_LONG(&_4$$3, zephir_get_intval(&_2$$3));
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 47, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * gc maxlifetime
 *
 * @param int $lifetime
 * @return int
 */
PHP_METHOD(Queryyetsimple_Session_Session, gcMaxlifetime) {

	zval *lifetime_param = NULL, result, _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &lifetime_param);

	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.gc_maxlifetime");
	ZEPHIR_CALL_FUNCTION(&result, "ini_get", NULL, 61, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, lifetime);
	if (zephir_get_intval(&_1) >= 1) {
		ZVAL_LONG(&_2$$3, lifetime);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "session.gc_maxlifetime");
		ZVAL_LONG(&_4$$3, zephir_get_intval(&_2$$3));
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 47, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * session 垃圾回收概率分子 (分母为 session.gc_divisor)
 *
 * @param int $probability
 * @return int
 */
PHP_METHOD(Queryyetsimple_Session_Session, gcProbability) {

	zend_bool _2;
	zval *probability_param = NULL, result, _0, _1, _3, _4$$3, _5$$3, _6$$3;
	zend_long probability, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &probability_param);

	if (!probability_param) {
		probability = 0;
	} else {
		probability = zephir_get_intval(probability_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.gc_probability");
	ZEPHIR_CALL_FUNCTION(&result, "ini_get", NULL, 61, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, probability);
	_2 = zephir_get_intval(&_1) >= 1;
	if (_2) {
		ZVAL_LONG(&_3, probability);
		_2 = zephir_get_intval(&_3) <= 100;
	}
	if (_2) {
		ZVAL_LONG(&_4$$3, probability);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "session.gc_probability");
		ZVAL_LONG(&_6$$3, zephir_get_intval(&_4$$3));
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 47, &_5$$3, &_6$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Session_Session, option) {

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
		_1$$3 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Session\\InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_0$$3, _1$$3);
		if (zephir_has_constructor(&_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Option set name must be a string.");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_2$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_0$$3, "queryyetsimple/session/session.zep", 843 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Session_Session, optionArray) {

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
PHP_METHOD(Queryyetsimple_Session_Session, options) {

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
	zephir_is_iterable(&option, 0, "queryyetsimple/session/session.zep", 880);
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
PHP_METHOD(Queryyetsimple_Session_Session, getOption) {

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
		zephir_array_fetch(&_0, &_2, &name, PH_NOISY, "queryyetsimple/session/session.zep", 892 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Session_Session, getOptions) {

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
PHP_METHOD(Queryyetsimple_Session_Session, deleteOption) {

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
PHP_METHOD(Queryyetsimple_Session_Session, deleteOptions) {

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
	zephir_is_iterable(&option, 0, "queryyetsimple/session/session.zep", 943);
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
PHP_METHOD(Queryyetsimple_Session_Session, getName) {

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
PHP_METHOD(Queryyetsimple_Session_Session, checkStart) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstart", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Session is not start yet", "queryyetsimple/session/session.zep", 965);
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
PHP_METHOD(Queryyetsimple_Session_Session, popOldFlash) {

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
PHP_METHOD(Queryyetsimple_Session_Session, mergeOldFlash) {

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
PHP_METHOD(Queryyetsimple_Session_Session, popNewFlash) {

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
PHP_METHOD(Queryyetsimple_Session_Session, mergeNewFlash) {

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
PHP_METHOD(Queryyetsimple_Session_Session, getPartData) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, *type_param = NULL, __$null, name, value, parts, part, tempkeys, tempkey, _1$$3, _2$$4, _3$$4, *_5$$4, _4$$5, _6$$6;
	zval key, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&defaults_sub);
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
	zephir_fetch_params(1, 1, 2, &key_param, &defaults, &type_param);

	zephir_get_strval(&key, key_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZEPHIR_INIT_VAR(&tempkeys);
	zephir_fast_explode_str(&tempkeys, SL("\\"), &key, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(&tempkeys);
	ZEPHIR_CALL_FUNCTION(&tempkey, "array_shift", &_0, 4, &tempkeys);
	ZEPHIR_UNREF(&tempkeys);
	zephir_check_call_status();
	zephir_get_strval(&key, &tempkey);
	ZEPHIR_MAKE_REF(&tempkeys);
	ZEPHIR_CALL_FUNCTION(&name, "array_shift", &_0, 4, &tempkeys);
	ZEPHIR_UNREF(&tempkeys);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&type, "flash")) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "flashdatakey", NULL, 0, &key);
		zephir_check_call_status();
		zephir_get_strval(&key, &_1$$3);
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "get", NULL, 0, &key);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, ".");
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_fast_strpos(&_3$$4, &name, &_2$$4, 0 );
		if (!(zephir_is_true(&_3$$4))) {
			ZEPHIR_INIT_VAR(&_4$$5);
			if (zephir_array_key_exists(&value, &name TSRMLS_CC)) {
				zephir_array_fetch(&_4$$5, &value, &name, PH_NOISY, "queryyetsimple/session/session.zep", 1036 TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(&_4$$5, defaults);
			}
			RETURN_CCTOR(&_4$$5);
		}
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("."), &name, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(&parts, 0, "queryyetsimple/session/session.zep", 1046);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _5$$4)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _5$$4);
			if (!(zephir_array_isset(&value, &part))) {
				RETVAL_ZVAL(defaults, 1, 0);
				RETURN_MM();
			}
			zephir_array_fetch(&_6$$6, &value, &part, PH_NOISY | PH_READONLY, "queryyetsimple/session/session.zep", 1044 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Session_Session, flashDataKey) {

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
PHP_METHOD(Queryyetsimple_Session_Session, flashNewKey) {

	zval *this_ptr = getThis();


	RETURN_STRING("flash.new.key");

}

/**
 * 旧值闪存 KEY
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, flashOldKey) {

	zval *this_ptr = getThis();


	RETURN_STRING("flash.old.key");

}

/**
 * 前一个页面 KEY
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, prevUrlKey) {

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
PHP_METHOD(Queryyetsimple_Session_Session, __call) {

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
		zephir_throw_exception_debug(&_1$$3, "queryyetsimple/session/session.zep", 1103 TSRMLS_CC);
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

zend_object *zephir_init_properties_Queryyetsimple_Session_Session(zend_class_entry *class_type TSRMLS_DC) {

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
			zephir_create_array(&_1$$3, 12, 0 TSRMLS_CC);
			zephir_array_update_string(&_1$$3, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_1$$3, SL("prefix"), SL("q_"));
			zephir_array_update_string(&_1$$3, SL("id"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("name"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("cookie_domain"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("cache_limiter"), &__$null, PH_COPY | PH_SEPARATE);
			add_assoc_long_ex(&_1$$3, SL("expire"), 86400);
			zephir_array_update_string(&_1$$3, SL("cookie_lifetime"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("gc_maxlifetime"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("save_path"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("use_trans_sid"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("gc_probability"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}
