
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
	zend_declare_property_null(queryyetsimple_session_session_ce, SL("objConnect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * session 是否开启
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(queryyetsimple_session_session_ce, SL("booStarted"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_session_session_ce, SL("arrOption"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \SessionHandlerInterface|null $objConnect
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *objConnect = NULL, objConnect_sub, *arrOption_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objConnect_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &objConnect, &arrOption_param);

	if (!objConnect) {
		objConnect = &objConnect_sub;
		objConnect = &__$null;
	}
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	zephir_update_property_zval(this_ptr, SL("objConnect"), objConnect);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "options", NULL, 0, &arrOption);
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

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 35);
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
	ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 36, &_5, &_6);
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
		ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 37, &_9$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "parsesessionid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_11$$5))) {
			ZEPHIR_CALL_FUNCTION(&_12$$6, "mt_rand", NULL, 38);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_13$$6, "dechex", NULL, 39, &_12$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_14$$6, "uniqid", NULL, 40, &_13$$6);
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
	zephir_read_property(&_6, this_ptr, SL("objConnect"), PH_NOISY_CC | PH_READONLY);
	_42 = zephir_is_true(&_6);
	if (_42) {
		zephir_read_property(&_43, this_ptr, SL("objConnect"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_44, "session_set_save_handler", NULL, 41, &_43);
		zephir_check_call_status();
		_42 = !zephir_is_true(&_44);
	}
	if (_42) {
		ZEPHIR_INIT_VAR(&_45$$16);
		object_init_ex(&_45$$16, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_46$$16);
		zephir_read_property(&_47$$16, this_ptr, SL("objConnect"), PH_NOISY_CC | PH_READONLY);
		zephir_get_class(&_46$$16, &_47$$16, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_48$$16);
		ZVAL_STRING(&_48$$16, "Session drive %s settings failed.");
		ZEPHIR_CALL_FUNCTION(&_49$$16, "sprintf", NULL, 1, &_48$$16, &_46$$16);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_45$$16, "__construct", NULL, 2, &_49$$16);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_45$$16, "queryyetsimple/session/session.zep", 175 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_50, "session_start", NULL, 42);
	zephir_check_call_status();
	if (!(zephir_is_true(&_50))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Session start failed", "queryyetsimple/session/session.zep", 180);
		return;
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("booStarted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("booStarted"), &__$false);
	}
	RETURN_THIS();

}

/**
 * 设置 session
 *
 * @param string $sName
 * @param mxied $mixValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL, *mixValue, mixValue_sub, *_SESSION, _0;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 2, 0, &sName_param, &mixValue);

	zephir_get_strval(&sName, sName_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getname", NULL, 0, &sName);
	zephir_check_call_status();
	zephir_get_strval(&sName, &_0);
	zephir_array_update_zval(_SESSION, &sName, mixValue, PH_COPY | PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * 批量插入
 *
 * @param string|array $mixKey
 * @param mixed $mixValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, put) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixKey = NULL, mixKey_sub, *mixValue = NULL, mixValue_sub, __$null, strKey, *_0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixKey_sub);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&strKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &mixKey, &mixValue);

	ZEPHIR_SEPARATE_PARAM(mixKey);
	if (!mixValue) {
		mixValue = &mixValue_sub;
		ZEPHIR_CPY_WRT(mixValue, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(mixValue);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(mixKey) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(mixKey);
		zephir_create_array(mixKey, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(mixKey, mixKey, mixValue, PH_COPY);
	}
	zephir_is_iterable(mixKey, 0, "queryyetsimple/session/session.zep", 225);
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, &strKey, mixValue);
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
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, push) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strKey_param = NULL, *mixValue, mixValue_sub, arr, _0;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strKey_param, &mixValue);

	zephir_get_strval(&strKey, strKey_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &strKey, &_0);
	zephir_check_call_status();
	zephir_array_append(&arr, mixValue, PH_SEPARATE, "queryyetsimple/session/session.zep", 238);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &arr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并元素
 *
 * @param string $strKey
 * @param array $arrValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, merge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrValue;
	zval *strKey_param = NULL, *arrValue_param = NULL, _0, _1, _2, _3;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&arrValue);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strKey_param, &arrValue_param);

	zephir_get_strval(&strKey, strKey_param);
	zephir_get_arrval(&arrValue, arrValue_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &strKey, &_2);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &arrValue TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "array_unique", NULL, 18, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出元素
 *
 * @param string $strKey
 * @param mixed $mixValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, pop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrValue;
	zval *strKey_param = NULL, *arrValue_param = NULL, _0, _1, _2;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&arrValue);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strKey_param, &arrValue_param);

	zephir_get_strval(&strKey, strKey_param);
	zephir_get_arrval(&arrValue, arrValue_param);


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &strKey, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "array_diff", NULL, 19, &_0, &arrValue);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组插入键值对数据
 *
 * @param string $strKey
 * @param mixed $mixKey
 * @param mixed $mixValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, arrays) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strKey_param = NULL, *mixKey, mixKey_sub, *mixValue = NULL, mixValue_sub, __$null, arr, _0, _1$$4;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixKey_sub);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &strKey_param, &mixKey, &mixValue);

	zephir_get_strval(&strKey, strKey_param);
	if (!mixValue) {
		mixValue = &mixValue_sub;
		mixValue = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &strKey, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(mixKey) == IS_STRING) {
		zephir_array_update_zval(&arr, mixKey, mixValue, PH_COPY | PH_SEPARATE);
	} else if (Z_TYPE_P(mixKey) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_array_merge(&_1$$4, &arr, mixKey TSRMLS_CC);
		ZEPHIR_CPY_WRT(&arr, &_1$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &arr);
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
PHP_METHOD(Queryyetsimple_Session_Session, arraysDelete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strKey_param = NULL, *mixKey, mixKey_sub, arr, strFoo, arrDeleteKey, _0, *_1;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixKey_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&strFoo);
	ZVAL_UNDEF(&arrDeleteKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strKey_param, &mixKey);

	zephir_get_strval(&strKey, strKey_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &strKey, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(mixKey) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&arrDeleteKey);
		zephir_create_array(&arrDeleteKey, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&arrDeleteKey, mixKey);
	} else {
		ZEPHIR_CPY_WRT(&arrDeleteKey, mixKey);
	}
	zephir_is_iterable(&arrDeleteKey, 0, "queryyetsimple/session/session.zep", 310);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrDeleteKey), _1)
	{
		ZEPHIR_INIT_NVAR(&strFoo);
		ZVAL_COPY(&strFoo, _1);
		if (zephir_array_isset(&arr, &strFoo)) {
			zephir_array_unset(&arr, &strFoo, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&strFoo);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &strKey, &arr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 取回 session
 *
 * @param string $sName
 * @param mixed $mixValue
 * @return mxied
 */
PHP_METHOD(Queryyetsimple_Session_Session, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL, *mixValue = NULL, mixValue_sub, *_SESSION, __$null, _0, _1;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 1, &sName_param, &mixValue);

	zephir_get_strval(&sName, sName_param);
	if (!mixValue) {
		mixValue = &mixValue_sub;
		mixValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getname", NULL, 0, &sName);
	zephir_check_call_status();
	zephir_get_strval(&sName, &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_array_isset(_SESSION, &sName)) {
		zephir_array_fetch(&_1, _SESSION, &sName, PH_NOISY, "queryyetsimple/session/session.zep", 325 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_1, mixValue);
	}
	RETURN_CCTOR(&_1);

}

/**
 * 返回数组部分数据
 *
 * @param string $sName
 * @param mixed $mixValue
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Session_Session, getPart) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL, *mixValue = NULL, mixValue_sub, __$null;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sName_param, &mixValue);

	zephir_get_strval(&sName, sName_param);
	if (!mixValue) {
		mixValue = &mixValue_sub;
		mixValue = &__$null;
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getpartdata", NULL, 0, &sName, mixValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除 session
 *
 * @param string $sName
 * @param boolean $bPrefix
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Session_Session, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool bPrefix;
	zval *sName_param = NULL, *bPrefix_param = NULL, *_SESSION, _0$$3;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 1, &sName_param, &bPrefix_param);

	zephir_get_strval(&sName, sName_param);
	if (!bPrefix_param) {
		bPrefix = 1;
	} else {
		bPrefix = zephir_get_boolval(bPrefix_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	if (bPrefix) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getname", NULL, 0, &sName);
		zephir_check_call_status();
		zephir_get_strval(&sName, &_0$$3);
	}
	if (zephir_array_isset(_SESSION, &sName)) {
		zephir_array_unset(_SESSION, &sName, PH_SEPARATE);
	}
	RETURN_MM_BOOL(1);

}

/**
 * 是否存在 session
 *
 * @param string $sName
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Session_Session, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL, *_SESSION, _0;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 0, &sName_param);

	zephir_get_strval(&sName, sName_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getname", NULL, 0, &sName);
	zephir_check_call_status();
	zephir_get_strval(&sName, &_0);
	RETURN_MM_BOOL(zephir_array_isset(_SESSION, &sName));

}

/**
 * 删除 session
 *
 * @param boolean $bPrefix
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, clear) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bPrefix_param = NULL, *_SESSION, strPrefix, sKey, _0, *_1, _6$$3, _7$$4, _9$$5;
	zend_bool bPrefix, _4$$3, _5$$3;
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
	zephir_fetch_params(1, 0, 1, &bPrefix_param);

	if (!bPrefix_param) {
		bPrefix = 1;
	} else {
		bPrefix = zephir_get_boolval(bPrefix_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "prefix");
	ZEPHIR_CALL_METHOD(&strPrefix, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	zephir_is_iterable(_SESSION, 0, "queryyetsimple/session/session.zep", 395);
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
		_4$$3 = bPrefix == 1;
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
 * @param string $strKey
 * @param mixed $mixValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, flash) {

	zval _1$$4, _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strKey_param = NULL, *mixValue = NULL, mixValue_sub, __$null, _0$$4;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strKey_param, &mixValue);

	zephir_get_strval(&strKey, strKey_param);
	if (!mixValue) {
		mixValue = &mixValue_sub;
		mixValue = &__$null;
	}


	if (Z_TYPE_P(mixValue) == IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getflash", NULL, 0, &strKey);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "flashdatakey", NULL, 0, &strKey);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_0$$4, mixValue);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$4, &strKey);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergenewflash", NULL, 0, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_2$$4, &strKey);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "popoldflash", NULL, 0, &_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 批量闪存数据，当前请求和下一个请求可用
 *
 * @param array $arrFlash
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, flashs) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrFlash_param = NULL, strKey, mixValue, *_0;
	zval arrFlash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrFlash);
	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixValue);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrFlash_param);

	zephir_get_arrval(&arrFlash, arrFlash_param);


	zephir_is_iterable(&arrFlash, 0, "queryyetsimple/session/session.zep", 432);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arrFlash), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&strKey);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&strKey, _2);
		} else {
			ZVAL_LONG(&strKey, _1);
		}
		ZEPHIR_INIT_NVAR(&mixValue);
		ZVAL_COPY(&mixValue, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flash", &_3, 0, &strKey, &mixValue);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&mixValue);
	ZEPHIR_INIT_NVAR(&strKey);
	ZEPHIR_MM_RESTORE();

}

/**
 * 闪存一个 flash 用于当前请求使用，下一个请求将无法获取
 *
 * @param string $strKey
 * @param mixed $mixValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, nowFlash) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strKey_param = NULL, *mixValue, mixValue_sub, _0;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strKey_param, &mixValue);

	zephir_get_strval(&strKey, strKey_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashdatakey", NULL, 0, &strKey);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_0, mixValue);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &strKey);
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
 * @param mixed $mixKey
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, keepFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixKey = NULL, mixKey_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixKey_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixKey);

	ZEPHIR_SEPARATE_PARAM(mixKey);


	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(mixKey) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, mixKey);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_get_args(&_0);
	}
	ZEPHIR_CPY_WRT(mixKey, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergenewflash", NULL, 0, mixKey);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "popoldflash", NULL, 0, mixKey);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回闪存数据
 *
 * @param string $strKey
 * @param mixed $mixDefault
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Session_Session, getFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strKey_param = NULL, *mixDefault = NULL, mixDefault_sub, __$null, _0, _1, _2$$3, _3$$4;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&mixDefault_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strKey_param, &mixDefault);

	zephir_get_strval(&strKey, strKey_param);
	if (!mixDefault) {
		mixDefault = &mixDefault_sub;
		mixDefault = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &strKey, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "flash");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getpartdata", NULL, 0, &strKey, mixDefault, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "flashdatakey", NULL, 0, &strKey);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_3$$4, mixDefault);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * 删除闪存数据
 *
 * @param mixed $mixKey
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, deleteFlash) {

	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixKey = NULL, mixKey_sub, strKey, _0, *_1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixKey_sub);
	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixKey);

	ZEPHIR_SEPARATE_PARAM(mixKey);


	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(mixKey) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, mixKey);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_get_args(&_0);
	}
	ZEPHIR_CPY_WRT(mixKey, &_0);
	zephir_is_iterable(mixKey, 0, "queryyetsimple/session/session.zep", 504);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(mixKey), _1)
	{
		ZEPHIR_INIT_NVAR(&strKey);
		ZVAL_COPY(&strKey, _1);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "flashdatakey", &_3, 0, &strKey);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_4, 0, &_2$$3);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&strKey);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergeoldflash", NULL, 0, mixKey);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "popnewflash", NULL, 0, mixKey);
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
	zval strNew, arrNewKey, _0, _1, _2, *_3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strNew);
	ZVAL_UNDEF(&arrNewKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_METHOD(&arrNewKey, this_ptr, "get", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_is_iterable(&arrNewKey, 0, "queryyetsimple/session/session.zep", 522);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arrNewKey), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&strNew);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&strNew, _5);
		} else {
			ZVAL_LONG(&strNew, _4);
		}
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_COPY(&_2, _3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteflash", &_6, 0, &strNew);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_INIT_NVAR(&strNew);
	ZEPHIR_MM_RESTORE();

}

/**
 * 程序执行结束清理 flash
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, unregisterFlash) {

	zval arr, arrOld, strOld, _0, _1$$3, _3$$3, _5$$3, _7$$3, *_8$$3, _12$$3, _13$$3, _9$$4;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_6 = NULL, *_10 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&arrOld);
	ZVAL_UNDEF(&strOld);
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
		ZEPHIR_CALL_METHOD(&arrOld, this_ptr, "get", &_4, 0, &_5$$3, &_7$$3);
		zephir_check_call_status();
		zephir_is_iterable(&arrOld, 0, "queryyetsimple/session/session.zep", 541);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrOld), _8$$3)
		{
			ZEPHIR_INIT_NVAR(&strOld);
			ZVAL_COPY(&strOld, _8$$3);
			ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "flashdatakey", &_10, 0, &strOld);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_11, 0, &_9$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&strOld);
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
 * @param string $strUrl
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, setPrevUrl) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strUrl_param = NULL, _0;
	zval strUrl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strUrl);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strUrl_param);

	zephir_get_strval(&strUrl, strUrl_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "prevurlkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &_0, &strUrl);
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
	ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 43);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 终止会话
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Session_Session, destroy) {

	zval *_COOKIE, strName, _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
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
	ZEPHIR_CALL_METHOD(&strName, this_ptr, "sessionname", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset(_COOKIE, &strName)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_time(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "");
		ZVAL_LONG(&_3$$3, (zephir_get_numberval(&_1$$3) - 42000));
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "/");
		ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 17, &strName, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "session_destroy", NULL, 44);
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


	RETURN_MEMBER(getThis(), "booStarted");

}

/**
 * session 状态
 *
 * @return int
 */
PHP_METHOD(Queryyetsimple_Session_Session, status) {

	zval intStatus;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intStatus);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&intStatus, "session_status", NULL, 45);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(&intStatus, 0)) {
			RETURN_MM_LONG(0);
		}
		if (ZEPHIR_IS_LONG(&intStatus, 2)) {
			RETURN_MM_LONG(2);
		}
	} while(0);

	RETURN_MM_LONG(1);

}

/**
 * 获取解析 session_id
 *
 * @param string $sId
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, parseSessionId) {

	zval *_COOKIE, *_GET, *_POST, sId, strName, _0, _1$$5, _2$$7, _3$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sId);
	ZVAL_UNDEF(&strName);
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

	ZEPHIR_CALL_METHOD(&sId, this_ptr, "sessionid", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&sId)) {
		RETURN_CCTOR(&sId);
	}
	ZEPHIR_CALL_METHOD(&strName, this_ptr, "sessionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "usecookies", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		if (zephir_array_isset(_COOKIE, &strName)) {
			zephir_array_fetch(&_1$$5, _COOKIE, &strName, PH_NOISY | PH_READONLY, "queryyetsimple/session/session.zep", 649 TSRMLS_CC);
			RETURN_CTOR(&_1$$5);
		}
	} else {
		if (zephir_array_isset(_GET, &strName)) {
			zephir_array_fetch(&_2$$7, _GET, &strName, PH_NOISY | PH_READONLY, "queryyetsimple/session/session.zep", 653 TSRMLS_CC);
			RETURN_CTOR(&_2$$7);
		}
		if (zephir_array_isset(_POST, &strName)) {
			zephir_array_fetch(&_3$$8, _POST, &strName, PH_NOISY | PH_READONLY, "queryyetsimple/session/session.zep", 656 TSRMLS_CC);
			RETURN_CTOR(&_3$$8);
		}
	}
	RETURN_MM_NULL();

}

/**
 * 设置 save path
 *
 * @param string $sSavePath
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, savePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sSavePath_param = NULL, _0;
	zval sSavePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sSavePath);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sSavePath_param);

	if (!sSavePath_param) {
		ZEPHIR_INIT_VAR(&sSavePath);
		ZVAL_STRING(&sSavePath, "");
	} else {
		zephir_get_strval(&sSavePath, sSavePath_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&sSavePath) == IS_UNDEF) && Z_STRLEN_P(&sSavePath)) {
		ZEPHIR_CALL_FUNCTION(&_0, "session_save_path", NULL, 46, &sSavePath);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_save_path", NULL, 46);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置 cache limiter
 *
 * @param string $strCacheLimiter
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, cacheLimiter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strCacheLimiter_param = NULL, _0;
	zval strCacheLimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strCacheLimiter);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &strCacheLimiter_param);

	if (!strCacheLimiter_param) {
		ZEPHIR_INIT_VAR(&strCacheLimiter);
		ZVAL_STRING(&strCacheLimiter, "");
	} else {
		zephir_get_strval(&strCacheLimiter, strCacheLimiter_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&strCacheLimiter) == IS_UNDEF) && Z_STRLEN_P(&strCacheLimiter)) {
		ZEPHIR_CALL_FUNCTION(&_0, "session_cache_limiter", NULL, 47, &strCacheLimiter);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_cache_limiter", NULL, 47);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置 cache expire
 *
 * @param int $nExpireSecond
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, cacheExpire) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *nExpireSecond_param = NULL, _0, _1;
	zval nExpireSecond;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nExpireSecond);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nExpireSecond_param);

	if (!nExpireSecond_param) {
		ZEPHIR_INIT_VAR(&nExpireSecond);
		ZVAL_STRING(&nExpireSecond, "");
	} else {
		zephir_get_strval(&nExpireSecond, nExpireSecond_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&nExpireSecond) == IS_UNDEF) && Z_STRLEN_P(&nExpireSecond)) {
		ZVAL_LONG(&_1, zephir_get_intval(&nExpireSecond));
		ZEPHIR_CALL_FUNCTION(&_0, "session_cache_expire", NULL, 48, &_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_cache_expire", NULL, 48);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * session_name
 *
 * @param string $sName
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, sessionName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL, _0;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sName_param);

	if (!sName_param) {
		ZEPHIR_INIT_VAR(&sName);
		ZVAL_STRING(&sName, "");
	} else {
		zephir_get_strval(&sName, sName_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&sName) == IS_UNDEF) && Z_STRLEN_P(&sName)) {
		ZEPHIR_CALL_FUNCTION(&_0, "session_name", NULL, 49, &sName);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_name", NULL, 49);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * session id
 *
 * @param string $sId
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, sessionId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sId_param = NULL, _0;
	zval sId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sId);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sId_param);

	if (!sId_param) {
		ZEPHIR_INIT_VAR(&sId);
		ZVAL_STRING(&sId, "");
	} else {
		zephir_get_strval(&sId, sId_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&sId) == IS_UNDEF) && Z_STRLEN_P(&sId)) {
		ZEPHIR_CALL_FUNCTION(&_0, "session_id", NULL, 37, &sId);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "session_id", NULL, 37);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * session 的 cookie_domain 设置
 *
 * @param string $sSessionDomain
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, cookieDomain) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sSessionDomain_param = NULL, sReturn, _0, _1$$3;
	zval sSessionDomain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sSessionDomain);
	ZVAL_UNDEF(&sReturn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sSessionDomain_param);

	if (!sSessionDomain_param) {
		ZEPHIR_INIT_VAR(&sSessionDomain);
		ZVAL_STRING(&sSessionDomain, "");
	} else {
		zephir_get_strval(&sSessionDomain, sSessionDomain_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.cookie_domain");
	ZEPHIR_CALL_FUNCTION(&sReturn, "ini_get", NULL, 50, &_0);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&sSessionDomain) == IS_UNDEF) && Z_STRLEN_P(&sSessionDomain)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "session.cookie_domain");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 36, &_1$$3, &sSessionDomain);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&sReturn);

}

/**
 * session 是否使用 cookie
 *
 * @param boolean $bUseCookies
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Session_Session, useCookies) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bUseCookies_param = NULL, booReturn, _0, _1, _2$$3, _3$$3;
	zend_bool bUseCookies;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&booReturn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &bUseCookies_param);

	if (!bUseCookies_param) {
		bUseCookies = 0;
	} else {
		bUseCookies = zephir_get_boolval(bUseCookies_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.use_cookies");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 50, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&booReturn);
		ZVAL_BOOL(&booReturn, 1);
	} else {
		ZEPHIR_INIT_NVAR(&booReturn);
		ZVAL_BOOL(&booReturn, 0);
	}
	if (1 != 0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		if (bUseCookies) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, 1);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, 0);
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "session.use_cookies");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 36, &_3$$3, &_2$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&booReturn);

}

/**
 * 客户端禁用 cookie 可以开启这个项
 *
 * @param string $nUseTransSid
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Session_Session, useTransSid) {

	zval *nUseTransSid_param = NULL, booReturn, _0, _1, _2$$3, _3$$3;
	zend_long nUseTransSid, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&booReturn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nUseTransSid_param);

	if (!nUseTransSid_param) {
		nUseTransSid = 0;
	} else {
		nUseTransSid = zephir_get_intval(nUseTransSid_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.use_trans_sid");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 50, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&booReturn);
		ZVAL_BOOL(&booReturn, 1);
	} else {
		ZEPHIR_INIT_NVAR(&booReturn);
		ZVAL_BOOL(&booReturn, 0);
	}
	if (nUseTransSid) {
		ZEPHIR_INIT_VAR(&_2$$3);
		if (nUseTransSid) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, 1);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, 0);
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "session.use_trans_sid");
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 36, &_3$$3, &_2$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&booReturn);

}

/**
 * 设置过期 cookie lifetime
 *
 * @param int $nCookieLifeTime
 * @return int
 */
PHP_METHOD(Queryyetsimple_Session_Session, cookieLifetime) {

	zval *nCookieLifeTime_param = NULL, nReturn, _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long nCookieLifeTime, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nReturn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &nCookieLifeTime_param);

	nCookieLifeTime = zephir_get_intval(nCookieLifeTime_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.cookie_lifetime");
	ZEPHIR_CALL_FUNCTION(&nReturn, "ini_get", NULL, 50, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, nCookieLifeTime);
	if (zephir_get_intval(&_1) >= 1) {
		ZVAL_LONG(&_2$$3, nCookieLifeTime);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "session.cookie_lifetime");
		ZVAL_LONG(&_4$$3, zephir_get_intval(&_2$$3));
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 36, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&nReturn);

}

/**
 * gc maxlifetime
 *
 * @param int $nGcMaxlifetime
 * @return int
 */
PHP_METHOD(Queryyetsimple_Session_Session, gcMaxlifetime) {

	zval *nGcMaxlifetime_param = NULL, nReturn, _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long nGcMaxlifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nReturn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nGcMaxlifetime_param);

	if (!nGcMaxlifetime_param) {
		nGcMaxlifetime = 0;
	} else {
		nGcMaxlifetime = zephir_get_intval(nGcMaxlifetime_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.gc_maxlifetime");
	ZEPHIR_CALL_FUNCTION(&nReturn, "ini_get", NULL, 50, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, nGcMaxlifetime);
	if (zephir_get_intval(&_1) >= 1) {
		ZVAL_LONG(&_2$$3, nGcMaxlifetime);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "session.gc_maxlifetime");
		ZVAL_LONG(&_4$$3, zephir_get_intval(&_2$$3));
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 36, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&nReturn);

}

/**
 * session 垃圾回收概率分子 (分母为 session.gc_divisor)
 *
 * @param int $nGcProbability
 * @return int
 */
PHP_METHOD(Queryyetsimple_Session_Session, gcProbability) {

	zend_bool _2;
	zval *nGcProbability_param = NULL, nReturn, _0, _1, _3, _4$$3, _5$$3, _6$$3;
	zend_long nGcProbability, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nReturn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nGcProbability_param);

	if (!nGcProbability_param) {
		nGcProbability = 0;
	} else {
		nGcProbability = zephir_get_intval(nGcProbability_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "session.gc_probability");
	ZEPHIR_CALL_FUNCTION(&nReturn, "ini_get", NULL, 50, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, nGcProbability);
	_2 = zephir_get_intval(&_1) >= 1;
	if (_2) {
		ZVAL_LONG(&_3, nGcProbability);
		_2 = zephir_get_intval(&_3) <= 100;
	}
	if (_2) {
		ZVAL_LONG(&_4$$3, nGcProbability);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "session.gc_probability");
		ZVAL_LONG(&_6$$3, zephir_get_intval(&_4$$3));
		ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 36, &_5$$3, &_6$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&nReturn);

}

/**
 * 修改单个配置
 *
 * @param string $strName
 * @param mixed $mixValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Session_Session, option) {

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
		_1$$3 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Session\\InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_0$$3, _1$$3);
		if (zephir_has_constructor(&_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Option set name must be a string.");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_2$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_0$$3, "queryyetsimple/session/session.zep", 842 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Session_Session, optionArray) {

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
PHP_METHOD(Queryyetsimple_Session_Session, options) {

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
	zephir_is_iterable(&arrOption, 0, "queryyetsimple/session/session.zep", 879);
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
PHP_METHOD(Queryyetsimple_Session_Session, getOption) {

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
		zephir_array_fetch(&_0, &_2, &strName, PH_NOISY, "queryyetsimple/session/session.zep", 891 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Session_Session, getOptions) {

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
PHP_METHOD(Queryyetsimple_Session_Session, deleteOption) {

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
PHP_METHOD(Queryyetsimple_Session_Session, deleteOptions) {

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
	zephir_is_iterable(&arrOption, 0, "queryyetsimple/session/session.zep", 942);
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
 * 返回 session 名字
 *
 * @param string $sName
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, getName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL, _0, _1;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sName_param);

	zephir_get_strval(&sName, sName_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "prefix");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &sName);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Session is not start yet", "queryyetsimple/session/session.zep", 964);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出旧闪存 KEY
 *
 * @param array $arrKey
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, popOldFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrKey_param = NULL, _0;
	zval arrKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrKey_param);

	zephir_get_arrval(&arrKey, arrKey_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flasholdkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pop", NULL, 0, &_0, &arrKey);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并旧闪存 KEY
 *
 * @param array $arrKey
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, mergeOldFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrKey_param = NULL, _0;
	zval arrKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrKey_param);

	zephir_get_arrval(&arrKey, arrKey_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flasholdkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", NULL, 0, &_0, &arrKey);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出新闪存 KEY
 *
 * @param array $arrKey
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, popNewFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrKey_param = NULL, _0;
	zval arrKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrKey_param);

	zephir_get_arrval(&arrKey, arrKey_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pop", NULL, 0, &_0, &arrKey);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并新闪存 KEY
 *
 * @param array $arrKey
 * @return void
 */
PHP_METHOD(Queryyetsimple_Session_Session, mergeNewFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrKey_param = NULL, _0;
	zval arrKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrKey_param);

	zephir_get_arrval(&arrKey, arrKey_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", NULL, 0, &_0, &arrKey);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回部分闪存数据
 *
 * @param string $strKey
 * @param mixed $mixDefault
 * @param string $strType
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Session_Session, getPartData) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *strKey_param = NULL, *mixDefault = NULL, mixDefault_sub, *strType_param = NULL, __$null, strName, mixValue, arrParts, sPart, arrTempKey, strTempKey, _1$$3, _2$$4, _3$$4, *_5$$4, _4$$5, _6$$6;
	zval strKey, strType;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);
	ZVAL_UNDEF(&strType);
	ZVAL_UNDEF(&mixDefault_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&mixValue);
	ZVAL_UNDEF(&arrParts);
	ZVAL_UNDEF(&sPart);
	ZVAL_UNDEF(&arrTempKey);
	ZVAL_UNDEF(&strTempKey);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &strKey_param, &mixDefault, &strType_param);

	zephir_get_strval(&strKey, strKey_param);
	if (!mixDefault) {
		mixDefault = &mixDefault_sub;
		mixDefault = &__$null;
	}
	if (!strType_param) {
		ZEPHIR_INIT_VAR(&strType);
		ZVAL_STRING(&strType, "");
	} else {
		zephir_get_strval(&strType, strType_param);
	}


	ZEPHIR_INIT_VAR(&arrTempKey);
	zephir_fast_explode_str(&arrTempKey, SL("\\"), &strKey, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(&arrTempKey);
	ZEPHIR_CALL_FUNCTION(&strTempKey, "array_shift", &_0, 11, &arrTempKey);
	ZEPHIR_UNREF(&arrTempKey);
	zephir_check_call_status();
	zephir_get_strval(&strKey, &strTempKey);
	ZEPHIR_MAKE_REF(&arrTempKey);
	ZEPHIR_CALL_FUNCTION(&strName, "array_shift", &_0, 11, &arrTempKey);
	ZEPHIR_UNREF(&arrTempKey);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&strType, "flash")) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "flashdatakey", NULL, 0, &strKey);
		zephir_check_call_status();
		zephir_get_strval(&strKey, &_1$$3);
	}
	ZEPHIR_CALL_METHOD(&mixValue, this_ptr, "get", NULL, 0, &strKey);
	zephir_check_call_status();
	if (Z_TYPE_P(&mixValue) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, ".");
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_fast_strpos(&_3$$4, &strName, &_2$$4, 0 );
		if (!(zephir_is_true(&_3$$4))) {
			ZEPHIR_INIT_VAR(&_4$$5);
			if (zephir_array_key_exists(&mixValue, &strName TSRMLS_CC)) {
				zephir_array_fetch(&_4$$5, &mixValue, &strName, PH_NOISY, "queryyetsimple/session/session.zep", 1035 TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(&_4$$5, mixDefault);
			}
			RETURN_CCTOR(&_4$$5);
		}
		ZEPHIR_INIT_VAR(&arrParts);
		zephir_fast_explode_str(&arrParts, SL("."), &strName, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(&arrParts, 0, "queryyetsimple/session/session.zep", 1045);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrParts), _5$$4)
		{
			ZEPHIR_INIT_NVAR(&sPart);
			ZVAL_COPY(&sPart, _5$$4);
			if (!(zephir_array_isset(&mixValue, &sPart))) {
				RETVAL_ZVAL(mixDefault, 1, 0);
				RETURN_MM();
			}
			zephir_array_fetch(&_6$$6, &mixValue, &sPart, PH_NOISY | PH_READONLY, "queryyetsimple/session/session.zep", 1043 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&mixValue, &_6$$6);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&sPart);
		RETURN_CCTOR(&mixValue);
	} else {
		RETVAL_ZVAL(mixDefault, 1, 0);
		RETURN_MM();
	}

}

/**
 * 闪存值 KEY
 *
 * @param string $strKey
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Session, flashDataKey) {

	zval *strKey_param = NULL;
	zval strKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strKey_param);

	zephir_get_strval(&strKey, strKey_param);


	ZEPHIR_CONCAT_SV(return_value, "flash.data.", &strKey);
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
 * @param string $sMethod
 * @param array $arrArgs
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Session_Session, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrArgs, _4;
	zval *sMethod_param = NULL, *arrArgs_param = NULL, _0, _5, _1$$3, _2$$3, _3$$3;
	zval sMethod;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sMethod);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&arrArgs);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sMethod_param, &arrArgs_param);

	zephir_get_strval(&sMethod, sMethod_param);
	zephir_get_arrval(&arrArgs, arrArgs_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("objConnect"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_BadMethodCallException);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Method %s is not exits.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, &sMethod);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "queryyetsimple/session/session.zep", 1102 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("objConnect"), PH_NOISY_CC);
	zephir_array_fast_append(&_4, &_5);
	zephir_array_fast_append(&_4, &sMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_4, &arrArgs);
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
		zephir_read_property(&_0, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
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
			zephir_update_property_zval(this_ptr, SL("arrOption"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

