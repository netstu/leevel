
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
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * log.monolog
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.08
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Log_Monolog) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Log, Monolog, leevel, log_monolog, leevel_log_connect_ce, leevel_log_monolog_method_entry, 0);

	/**
	 * Monolog
	 *
	 * @var \Monolog\Logger
	 */
	zend_declare_property_null(leevel_log_monolog_ce, SL("monolog"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_log_monolog_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Monolog 支持日志级别
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_log_monolog_ce, SL("supportLevel"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_log_monolog_ce->create_object = zephir_init_properties_Leevel_Log_Monolog;

	zend_class_implements(leevel_log_monolog_ce TSRMLS_CC, 1, leevel_log_iconnect_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Log_Monolog, __construct) {

	zend_class_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_9 = NULL, *_11 = NULL;
	zval *option_param = NULL, type, make, _1, _3, _4, _5, _6, *_7, _8$$3, _10$$3;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&make);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_PARENT(NULL, leevel_log_monolog_ce, getThis(), "__construct", &_0, 0, &option);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (!_2) {
	_2 = zephir_fetch_class_str_ex(SL("Monolog\\Logger"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_1, _2);
	if (zephir_has_constructor(&_1 TSRMLS_CC)) {
		zephir_read_property(&_3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4, &_3, SL("channel"), PH_NOISY | PH_READONLY, "leevel/log/monolog.zep", 90 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &_4);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("monolog"), &_1);
	zephir_read_property(&_5, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_6, &_5, SL("type"), PH_NOISY | PH_READONLY, "leevel/log/monolog.zep", 92 TSRMLS_CC);
	zephir_is_iterable(&_6, 0, "leevel/log/monolog.zep", 96);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_6), _7)
	{
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_COPY(&type, _7);
		ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "camelize", &_9, 0, &type);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_10$$3, "ucwords", &_11, 23, &_8$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&make);
		ZEPHIR_CONCAT_SVS(&make, "make", &_10$$3, "Handler");
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &make, NULL, 0);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&type);
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册文件 handler
 *
 * @param string $path
 * @param string $level
 * @return void
 */
PHP_METHOD(Leevel_Log_Monolog, file) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *level_param = NULL, handler, _1, _2, _3;
	zval path, level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &level_param);

	zephir_get_strval(&path, path_param);
	if (!level_param) {
		ZEPHIR_INIT_VAR(&level);
		ZVAL_STRING(&level, "debug");
	} else {
		zephir_get_strval(&level, level_param);
	}


	ZEPHIR_INIT_VAR(&handler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Handler\\StreamHandler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&handler, _0);
	if (zephir_has_constructor(&handler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "parsemonologlevel", NULL, 0, &level);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0, &path, &_1);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("monolog"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "pushhandler", NULL, 0, &handler);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdefaultformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &handler, "setformatter", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册每日文件 handler
 *
 * @param string $path
 * @param int $days
 * @param string $level
 * @return void
 */
PHP_METHOD(Leevel_Log_Monolog, dailyFile) {

	zend_class_entry *_0 = NULL;
	zend_long days, ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *days_param = NULL, *level_param = NULL, handler, _1, _2, _3;
	zval path, level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path_param, &days_param, &level_param);

	zephir_get_strval(&path, path_param);
	if (!days_param) {
		days = 0;
	} else {
		days = zephir_get_intval(days_param);
	}
	if (!level_param) {
		ZEPHIR_INIT_VAR(&level);
		ZVAL_STRING(&level, "debug");
	} else {
		zephir_get_strval(&level, level_param);
	}


	ZEPHIR_INIT_VAR(&handler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Handler\\RotatingFileHandler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&handler, _0);
	if (zephir_has_constructor(&handler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "parsemonologlevel", NULL, 0, &level);
		zephir_check_call_status();
		ZVAL_LONG(&_2, days);
		ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0, &path, &_2, &_1);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("monolog"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "pushhandler", NULL, 0, &handler);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdefaultformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &handler, "setformatter", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册系统 handler
 *
 * @param string $name
 * @param string $level
 * @return \Psr\Log\LoggerInterface
 */
PHP_METHOD(Leevel_Log_Monolog, syslog) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *level_param = NULL, handler, _1;
	zval name, level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &level_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "queryphp");
	} else {
		zephir_get_strval(&name, name_param);
	}
	if (!level_param) {
		ZEPHIR_INIT_VAR(&level);
		ZVAL_STRING(&level, "debug");
	} else {
		zephir_get_strval(&level, level_param);
	}


	ZEPHIR_INIT_VAR(&handler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Handler\\SyslogHandler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&handler, _0);
	if (zephir_has_constructor(&handler TSRMLS_CC)) {
		ZVAL_LONG(&_1, 8);
		ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0, &name, &_1, &level);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("monolog"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "pushhandler", NULL, 0, &handler);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 注册 error_log handler
 *
 * @param string $level
 * @param int $messageType
 * @return void
 */
PHP_METHOD(Leevel_Log_Monolog, errorLog) {

	zend_class_entry *_0 = NULL;
	zend_long messageType, ZEPHIR_LAST_CALL_STATUS;
	zval *level_param = NULL, *messageType_param = NULL, handler, _1, _2, _3;
	zval level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &level_param, &messageType_param);

	if (!level_param) {
		ZEPHIR_INIT_VAR(&level);
		ZVAL_STRING(&level, "debug");
	} else {
		zephir_get_strval(&level, level_param);
	}
	if (!messageType_param) {
		messageType = 0;
	} else {
		messageType = zephir_get_intval(messageType_param);
	}


	ZEPHIR_INIT_VAR(&handler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Handler\\ErrorLogHandler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&handler, _0);
	if (zephir_has_constructor(&handler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "parsemonologlevel", NULL, 0, &level);
		zephir_check_call_status();
		ZVAL_LONG(&_2, messageType);
		ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0, &_2, &_1);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("monolog"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "pushhandler", NULL, 0, &handler);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdefaultformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &handler, "setformatter", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * monolog 回调
 *
 * @param callable|null $callback
 * @return $this
 */
PHP_METHOD(Leevel_Log_Monolog, monolog) {

	zval _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback = NULL, callback_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &callback);

	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	if (zephir_is_callable(callback TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_0$$3, callback, &_1$$3);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 取得 Monolog
 *
 * @return \Monolog\Logger
 */
PHP_METHOD(Leevel_Log_Monolog, getMonolog) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "monolog");

}

/**
 * 日志写入接口
 *
 * @param array $data
 * @return void
 */
PHP_METHOD(Leevel_Log_Monolog, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, item, level, _0, *_1, _2$$3, _3$$3, _4$$3, _5$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_read_property(&_0, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&level);
	zephir_array_keys(&level, &_0 TSRMLS_CC);
	zephir_is_iterable(&data, 0, "leevel/log/monolog.zep", 231);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		zephir_array_fetch_long(&_2$$3, &item, 0, PH_NOISY | PH_READONLY, "leevel/log/monolog.zep", 223 TSRMLS_CC);
		if (!(zephir_fast_in_array(&_2$$3, &level TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(&level);
			ZVAL_STRING(&level, "debug");
		} else {
			ZEPHIR_OBS_NVAR(&level);
			zephir_array_fetch_long(&level, &item, 0, PH_NOISY, "leevel/log/monolog.zep", 226 TSRMLS_CC);
		}
		zephir_read_property(&_3$$3, this_ptr, SL("monolog"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_long(&_4$$3, &item, 1, PH_NOISY | PH_READONLY, "leevel/log/monolog.zep", 229 TSRMLS_CC);
		zephir_array_fetch_long(&_5$$3, &item, 2, PH_NOISY | PH_READONLY, "leevel/log/monolog.zep", 229 TSRMLS_CC);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, &_3$$3, &level, NULL, 0, &_4$$3, &_5$$3);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化文件 handler
 *
 * @return void
 */
PHP_METHOD(Leevel_Log_Monolog, makeFileHandler) {

	zval path;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checksize", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "file", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化每日文件 handler
 *
 * @return void
 */
PHP_METHOD(Leevel_Log_Monolog, makeDailyFileHandler) {

	zval path, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&path, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdailyfilepath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checksize", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "dailyfile", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化系统 handler
 *
 * @return void
 */
PHP_METHOD(Leevel_Log_Monolog, makeSyslogHandler) {

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
PHP_METHOD(Leevel_Log_Monolog, makeErrorLogHandler) {

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
 * @param string $path
 * @return void
 */
PHP_METHOD(Leevel_Log_Monolog, getDailyFilePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, ext, _0, _5, _6, _7, _1$$3, _2$$3, _3$$3, _4$$3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZVAL_LONG(&_0, 4);
	ZEPHIR_CALL_FUNCTION(&ext, "pathinfo", NULL, 55, &path, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&ext)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SV(&_1$$3, ".", &ext);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strrpos", NULL, 117, &path, &_1$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_substr(&_4$$3, &path, 0 , zephir_get_intval(&_2$$3), 0);
		zephir_get_strval(&path, &_4$$3);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "-Y-m-d");
	ZEPHIR_CALL_FUNCTION(&_6, "date", NULL, 31, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	if (zephir_is_true(&ext)) {
		ZEPHIR_INIT_NVAR(&_7);
		ZEPHIR_CONCAT_SV(&_7, ".", &ext);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "");
	}
	ZEPHIR_CONCAT_VVV(return_value, &path, &_6, &_7);
	RETURN_MM();

}

/**
 * 默认格式化
 *
 * @return \Monolog\Formatter\LineFormatter
 */
PHP_METHOD(Leevel_Log_Monolog, getDefaultFormatter) {

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
 * @param string $level
 * @return int
 */
PHP_METHOD(Leevel_Log_Monolog, parseMonologLevel) {

	zval *level_param = NULL, _0, _3, _4, _1$$3, _2$$3;
	zval level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	zephir_get_strval(&level, level_param);


	zephir_read_property(&_0, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &level)) {
		zephir_read_property(&_1$$3, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &level, PH_NOISY | PH_READONLY, "leevel/log/monolog.zep", 322 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_4, &_3, SL("debug"), PH_NOISY | PH_READONLY, "leevel/log/monolog.zep", 325 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

/**
 * 下划线转驼峰
 *
 * @param string $value
 * @param string $separator
 * @return string
 */
PHP_METHOD(Leevel_Log_Monolog, camelize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *separator_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zval value, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value_param, &separator_param);

	zephir_get_strval(&value, value_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "_");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &value);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, " ");
	zephir_fast_str_replace(&_0, &separator, &_2, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &separator, &_0);
	zephir_get_strval(&value, &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CALL_FUNCTION(&_5, "ucwords", NULL, 23, &value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, " ");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "");
	zephir_fast_str_replace(&_4, &_6, &_7, &_5 TSRMLS_CC);
	zephir_fast_trim(return_value, &_4, &separator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Log_Monolog(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _3$$4, _4$$4;
	zval _0, _2, _5$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
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
			zephir_update_property_zval(this_ptr, SL("supportLevel"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 5, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_create_array(&_4$$4, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "file");
			zephir_array_fast_append(&_4$$4, &_5$$4);
			zephir_array_update_string(&_3$$4, SL("type"), &_4$$4, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_3$$4, SL("channel"), SL("Q"));
			add_assoc_stringl_ex(&_3$$4, SL("name"), SL("Y-m-d H"));
			add_assoc_long_ex(&_3$$4, SL("size"), 2097152);
			add_assoc_stringl_ex(&_3$$4, SL("path"), SL(""));
			zephir_update_property_zval(this_ptr, SL("option"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

