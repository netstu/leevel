
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
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * log.monolog
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.08
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Monolog) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Log, Monolog, queryyetsimple, log_monolog, queryyetsimple_log_aconnect_ce, queryyetsimple_log_monolog_method_entry, 0);

	/**
	 * Monolog
	 *
	 * @var \Monolog\Logger
	 */
	zend_declare_property_null(queryyetsimple_log_monolog_ce, SL("objMonolog"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_log_monolog_ce, SL("arrOption"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Monolog 支持日志级别
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_log_monolog_ce, SL("arrSupportLevel"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_log_monolog_ce->create_object = zephir_init_properties_Queryyetsimple_Log_Monolog;

	zend_class_implements(queryyetsimple_log_monolog_ce TSRMLS_CC, 1, queryyetsimple_log_iconnect_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, __construct) {

	zend_class_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL, *_10 = NULL;
	zval *arrOption_param = NULL, strType, strMake, _1, _3, _4, _5, *_6, _7$$3, _9$$3;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&strType);
	ZVAL_UNDEF(&strMake);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_CALL_PARENT(NULL, queryyetsimple_log_monolog_ce, getThis(), "__construct", &_0, 0, &arrOption);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (!_2) {
	_2 = zephir_fetch_class_str_ex(SL("Monolog\\Logger"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_1, _2);
	if (zephir_has_constructor(&_1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "channel");
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", NULL, 0, &_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &_3);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("objMonolog"), &_1);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "type");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getoption", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_is_iterable(&_5, 0, "queryyetsimple/log/monolog.zep", 107);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
	{
		ZEPHIR_INIT_NVAR(&strType);
		ZVAL_COPY(&strType, _6);
		ZEPHIR_CALL_METHOD(&_7$$3, this_ptr, "camelize", &_8, 0, &strType);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_9$$3, "ucwords", &_10, 6, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&strMake);
		ZEPHIR_CONCAT_SVS(&strMake, "make", &_9$$3, "Handler");
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &strMake, NULL, 0);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&strType);
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册文件 handler
 *
 * @param string $strPath
 * @param string $strLevel
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, file) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strPath_param = NULL, *strLevel_param = NULL, objHandler, _1, _2, _3;
	zval strPath, strLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strPath);
	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&objHandler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strPath_param, &strLevel_param);

	zephir_get_strval(&strPath, strPath_param);
	if (!strLevel_param) {
		ZEPHIR_INIT_VAR(&strLevel);
		ZVAL_STRING(&strLevel, "debug");
	} else {
		zephir_get_strval(&strLevel, strLevel_param);
	}


	ZEPHIR_INIT_VAR(&objHandler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Handler\\StreamHandler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&objHandler, _0);
	if (zephir_has_constructor(&objHandler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "parsemonologlevel", NULL, 0, &strLevel);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &objHandler, "__construct", NULL, 0, &strPath, &_1);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("objMonolog"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "pushhandler", NULL, 0, &objHandler);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdefaultformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &objHandler, "setformatter", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册每日文件 handler
 *
 * @param string $strPath
 * @param int $intDays
 * @param string $level
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, dailyFile) {

	zend_class_entry *_0 = NULL;
	zend_long intDays, ZEPHIR_LAST_CALL_STATUS;
	zval *strPath_param = NULL, *intDays_param = NULL, *strLevel_param = NULL, objHandler, _1, _2, _3;
	zval strPath, strLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strPath);
	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&objHandler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &strPath_param, &intDays_param, &strLevel_param);

	zephir_get_strval(&strPath, strPath_param);
	if (!intDays_param) {
		intDays = 0;
	} else {
		intDays = zephir_get_intval(intDays_param);
	}
	if (!strLevel_param) {
		ZEPHIR_INIT_VAR(&strLevel);
		ZVAL_STRING(&strLevel, "debug");
	} else {
		zephir_get_strval(&strLevel, strLevel_param);
	}


	ZEPHIR_INIT_VAR(&objHandler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Handler\\RotatingFileHandler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&objHandler, _0);
	if (zephir_has_constructor(&objHandler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "parsemonologlevel", NULL, 0, &strLevel);
		zephir_check_call_status();
		ZVAL_LONG(&_2, intDays);
		ZEPHIR_CALL_METHOD(NULL, &objHandler, "__construct", NULL, 0, &strPath, &_2, &_1);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("objMonolog"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "pushhandler", NULL, 0, &objHandler);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdefaultformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &objHandler, "setformatter", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册系统 handler
 *
 * @param string $strName
 * @param string $strLevel
 * @return \Psr\Log\LoggerInterface
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, syslog) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strName_param = NULL, *strLevel_param = NULL, objHandler, _1;
	zval strName, strLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&objHandler);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &strName_param, &strLevel_param);

	if (!strName_param) {
		ZEPHIR_INIT_VAR(&strName);
		ZVAL_STRING(&strName, "queryphp");
	} else {
		zephir_get_strval(&strName, strName_param);
	}
	if (!strLevel_param) {
		ZEPHIR_INIT_VAR(&strLevel);
		ZVAL_STRING(&strLevel, "debug");
	} else {
		zephir_get_strval(&strLevel, strLevel_param);
	}


	ZEPHIR_INIT_VAR(&objHandler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Handler\\SyslogHandler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&objHandler, _0);
	if (zephir_has_constructor(&objHandler TSRMLS_CC)) {
		ZVAL_LONG(&_1, 8);
		ZEPHIR_CALL_METHOD(NULL, &objHandler, "__construct", NULL, 0, &strName, &_1, &strLevel);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("objMonolog"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "pushhandler", NULL, 0, &objHandler);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 注册 error_log handler
 *
 * @param string $strLevel
 * @param int $intMessageType
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, errorLog) {

	zend_class_entry *_0 = NULL;
	zend_long intMessageType, ZEPHIR_LAST_CALL_STATUS;
	zval *strLevel_param = NULL, *intMessageType_param = NULL, objHandler, _1, _2, _3;
	zval strLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&objHandler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &strLevel_param, &intMessageType_param);

	if (!strLevel_param) {
		ZEPHIR_INIT_VAR(&strLevel);
		ZVAL_STRING(&strLevel, "debug");
	} else {
		zephir_get_strval(&strLevel, strLevel_param);
	}
	if (!intMessageType_param) {
		intMessageType = 0;
	} else {
		intMessageType = zephir_get_intval(intMessageType_param);
	}


	ZEPHIR_INIT_VAR(&objHandler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Handler\\ErrorLogHandler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&objHandler, _0);
	if (zephir_has_constructor(&objHandler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "parsemonologlevel", NULL, 0, &strLevel);
		zephir_check_call_status();
		ZVAL_LONG(&_2, intMessageType);
		ZEPHIR_CALL_METHOD(NULL, &objHandler, "__construct", NULL, 0, &_2, &_1);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("objMonolog"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "pushhandler", NULL, 0, &objHandler);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdefaultformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &objHandler, "setformatter", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * monolog 回调
 *
 * @param callable|null $mixCallback
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, monolog) {

	zval _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixCallback = NULL, mixCallback_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixCallback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mixCallback);

	if (!mixCallback) {
		mixCallback = &mixCallback_sub;
		mixCallback = &__$null;
	}


	if (zephir_is_callable(mixCallback TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_0$$3, mixCallback, &_1$$3);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 取得 Monolog
 *
 * @return \Monolog\Logger
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, getMonolog) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "objMonolog");

}

/**
 * 日志写入接口
 *
 * @param array $arrData
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrData_param = NULL, arrItem, arrLevel, strLevel, _0, *_1, _2$$3, _3$$3, _4$$3, _5$$3;
	zval arrData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrData);
	ZVAL_UNDEF(&arrItem);
	ZVAL_UNDEF(&arrLevel);
	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrData_param);

	zephir_get_arrval(&arrData, arrData_param);


	zephir_read_property(&_0, this_ptr, SL("arrSupportLevel"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&arrLevel);
	zephir_array_keys(&arrLevel, &_0 TSRMLS_CC);
	zephir_is_iterable(&arrData, 0, "queryyetsimple/log/monolog.zep", 217);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrData), _1)
	{
		ZEPHIR_INIT_NVAR(&arrItem);
		ZVAL_COPY(&arrItem, _1);
		zephir_array_fetch_long(&_2$$3, &arrItem, 0, PH_NOISY | PH_READONLY, "queryyetsimple/log/monolog.zep", 209 TSRMLS_CC);
		if (!(zephir_fast_in_array(&_2$$3, &arrLevel TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(&strLevel);
			ZVAL_STRING(&strLevel, "debug");
		} else {
			ZEPHIR_OBS_NVAR(&strLevel);
			zephir_array_fetch_long(&strLevel, &arrItem, 0, PH_NOISY, "queryyetsimple/log/monolog.zep", 212 TSRMLS_CC);
		}
		zephir_read_property(&_3$$3, this_ptr, SL("objMonolog"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_4$$3, &arrItem, 1, PH_NOISY | PH_READONLY, "queryyetsimple/log/monolog.zep", 215 TSRMLS_CC);
		zephir_array_fetch_long(&_5$$3, &arrItem, 2, PH_NOISY | PH_READONLY, "queryyetsimple/log/monolog.zep", 215 TSRMLS_CC);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, &_3$$3, &strLevel, NULL, 0, &_4$$3, &_5$$3);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrItem);
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化文件 handler
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, makeFileHandler) {

	zval strPath;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strPath);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&strPath, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checksize", NULL, 0, &strPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "file", NULL, 0, &strPath);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化每日文件 handler
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, makeDailyFileHandler) {

	zval strPath, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strPath);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&strPath, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdailyfilepath", NULL, 0, &strPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checksize", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "dailyfile", NULL, 0, &strPath);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化系统 handler
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, makeSyslogHandler) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "syslog", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化 error_log handler
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, makeErrorLogHandler) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "errorlog", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 每日文件真实路径
 *
 * @param string $strPath
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, getDailyFilePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strPath_param = NULL, strExt, _0, _5, _6, _7, _1$$3, _2$$3, _3$$3, _4$$3;
	zval strPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strPath);
	ZVAL_UNDEF(&strExt);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strPath_param);

	zephir_get_strval(&strPath, strPath_param);


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&strExt, "pathinfo", NULL, 18, &strPath, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&strExt)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SV(&_1$$3, ".", &strExt);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strrpos", NULL, 27, &strPath, &_1$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_substr(&_4$$3, &strPath, 0 , zephir_get_intval(&_2$$3), 0);
		zephir_get_strval(&strPath, &_4$$3);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "-Y-m-d");
	ZEPHIR_CALL_FUNCTION(&_6, "date", NULL, 15, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	if (zephir_is_true(&strExt)) {
		ZEPHIR_INIT_NVAR(&_7);
		ZEPHIR_CONCAT_SV(&_7, ".", &strExt);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "");
	}
	ZEPHIR_CONCAT_VVV(return_value, &strPath, &_6, &_7);
	RETURN_MM();

}

/**
 * 默认格式化
 *
 * @return \Monolog\Formatter\LineFormatter
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, getDefaultFormatter) {

	zval _1, _2, _3, _4;
	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Formatter\\LineFormatter"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZVAL_NULL(&_1);
		ZVAL_NULL(&_2);
		ZVAL_BOOL(&_3, 1);
		ZVAL_BOOL(&_4, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1, &_2, &_3, &_4);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 获取 Monolog 级别
 * 不支持级别归并到 DEBUG
 *
 * @param string $strLevel
 * @return int
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, parseMonologLevel) {

	zval *strLevel_param = NULL, _0, _3, _4, _1$$3, _2$$3;
	zval strLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strLevel_param);

	zephir_get_strval(&strLevel, strLevel_param);


	zephir_read_property(&_0, this_ptr, SL("arrSupportLevel"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &strLevel)) {
		zephir_read_property(&_1$$3, this_ptr, SL("arrSupportLevel"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &strLevel, PH_NOISY | PH_READONLY, "queryyetsimple/log/monolog.zep", 301 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("arrSupportLevel"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_4, &_3, SL("debug"), PH_NOISY | PH_READONLY, "queryyetsimple/log/monolog.zep", 303 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

/**
 * 下划线转驼峰
 *
 * @param string $strValue
 * @param string $strSeparator
 * @return string
 */
PHP_METHOD(Queryyetsimple_Log_Monolog, camelize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strValue_param = NULL, *strSeparator_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zval strValue, strSeparator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&strSeparator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strValue_param, &strSeparator_param);

	zephir_get_strval(&strValue, strValue_param);
	if (!strSeparator_param) {
		ZEPHIR_INIT_VAR(&strSeparator);
		ZVAL_STRING(&strSeparator, "_");
	} else {
		zephir_get_strval(&strSeparator, strSeparator_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &strValue);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, " ");
	zephir_fast_str_replace(&_0, &strSeparator, &_2, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &strSeparator, &_0);
	zephir_get_strval(&strValue, &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CALL_FUNCTION(&_5, "ucwords", NULL, 6, &strValue);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, " ");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "");
	zephir_fast_str_replace(&_4, &_6, &_7, &_5 TSRMLS_CC);
	zephir_fast_trim(return_value, &_4, &strSeparator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	RETURN_MM();

}

zend_object *zephir_init_properties_Queryyetsimple_Log_Monolog(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _5$$5, _6$$5;
	zval _0, _2, _4, _3$$4, _7$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("arrSupportLevel"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 8, 0 TSRMLS_CC);
			add_assoc_long_ex(&_1$$3, SL("debug"), 100);
			add_assoc_long_ex(&_1$$3, SL("info"), 200);
			add_assoc_long_ex(&_1$$3, SL("notice"), 250);
			add_assoc_long_ex(&_1$$3, SL("warning"), 300);
			add_assoc_long_ex(&_1$$3, SL("error"), 400);
			add_assoc_long_ex(&_1$$3, SL("critical"), 500);
			add_assoc_long_ex(&_1$$3, SL("alert"), 550);
			add_assoc_long_ex(&_1$$3, SL("emergency"), 600);
			zephir_update_property_zval(this_ptr, SL("arrSupportLevel"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("option"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_create_array(&_5$$5, 5, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_6$$5);
			zephir_create_array(&_6$$5, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "file");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			zephir_array_update_string(&_5$$5, SL("type"), &_6$$5, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_5$$5, SL("channel"), SL("Q"));
			add_assoc_stringl_ex(&_5$$5, SL("name"), SL("Y-m-d H"));
			add_assoc_long_ex(&_5$$5, SL("size"), 2097152);
			add_assoc_stringl_ex(&_5$$5, SL("path"), SL(""));
			zephir_update_property_zval(this_ptr, SL("arrOption"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

