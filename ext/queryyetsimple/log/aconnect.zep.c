
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * aconnect 驱动抽象类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Aconnect) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Log, Aconnect, queryyetsimple, log_aconnect, queryyetsimple_log_aconnect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_log_aconnect_ce, SL("arrOption"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_log_aconnect_ce->create_object = zephir_init_properties_Queryyetsimple_Log_Aconnect;
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array $arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Aconnect, __construct) {

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
 * 修改单个配置
 *
 * @param string $strName
 * @param mixed $mixValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Log_Aconnect, option) {

	zval *strName_param = NULL, *mixValue, mixValue_sub;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&mixValue_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strName_param, &mixValue);

	zephir_get_strval(&strName, strName_param);


	if (!(Z_TYPE_P(&strName) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Option set name must be a string.", "queryyetsimple/log/aconnect.zep", 63);
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
PHP_METHOD(Queryyetsimple_Log_Aconnect, optionArray) {

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
PHP_METHOD(Queryyetsimple_Log_Aconnect, options) {

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
	zephir_is_iterable(&arrOption, 0, "queryyetsimple/log/aconnect.zep", 100);
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
PHP_METHOD(Queryyetsimple_Log_Aconnect, getOption) {

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
		zephir_array_fetch(&_0, &_2, &strName, PH_NOISY, "queryyetsimple/log/aconnect.zep", 112 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Log_Aconnect, getOptions) {

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
PHP_METHOD(Queryyetsimple_Log_Aconnect, deleteOption) {

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
PHP_METHOD(Queryyetsimple_Log_Aconnect, deleteOptions) {

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
	zephir_is_iterable(&arrOption, 0, "queryyetsimple/log/aconnect.zep", 163);
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
 * 验证日志文件大小
 *
 * @param string $sFilePath
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Aconnect, checkSize) {

	zend_bool _2, _4, _11;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sFilePath_param = NULL, __$true, sFileDir, _0, _3, _5, _6, _10, _12, _13, _14, _7$$3, _8$$3, _9$$3, _15$$4, _16$$4, _17$$4;
	zval sFilePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sFilePath);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&sFileDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sFilePath_param);

	zephir_get_strval(&sFilePath, sFilePath_param);


	ZEPHIR_CALL_FUNCTION(&sFileDir, "dirname", NULL, 4, &sFilePath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 5, &sFilePath);
	zephir_check_call_status();
	_2 = !zephir_is_true(&_0);
	if (_2) {
		ZEPHIR_CALL_FUNCTION(&_3, "is_dir", NULL, 6, &sFileDir);
		zephir_check_call_status();
		_2 = !zephir_is_true(&_3);
	}
	_4 = _2;
	if (_4) {
		ZVAL_LONG(&_5, 0777);
		ZEPHIR_CALL_FUNCTION(&_6, "mkdir", NULL, 7, &sFileDir, &_5, &__$true);
		zephir_check_call_status();
		_4 = !zephir_is_true(&_6);
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_7$$3);
		object_init_ex(&_7$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "Unable to create log file：%s.");
		ZEPHIR_CALL_FUNCTION(&_9$$3, "sprintf", NULL, 1, &_8$$3, &sFilePath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$3, "__construct", NULL, 2, &_9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "queryyetsimple/log/aconnect.zep", 180 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_10, "is_file", &_1, 5, &sFilePath);
	zephir_check_call_status();
	_11 = zephir_is_true(&_10);
	if (_11) {
		ZEPHIR_INIT_VAR(&_13);
		ZVAL_STRING(&_13, "size");
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "getoption", NULL, 0, &_13);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_14, "filesize", NULL, 8, &sFilePath);
		zephir_check_call_status();
		_11 = ZEPHIR_GE_LONG(&_14, zephir_floor(&_12 TSRMLS_CC));
	}
	if (_11) {
		ZEPHIR_INIT_VAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "Y-m-d H.i.s");
		ZEPHIR_CALL_FUNCTION(&_16$$4, "date", NULL, 9, &_15$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_15$$4);
		zephir_basename(&_15$$4, &sFilePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_17$$4);
		ZEPHIR_CONCAT_VSVSV(&_17$$4, &sFileDir, "/", &_16$$4, "~@", &_15$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "rename", NULL, 10, &sFilePath, &_17$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取日志路径
 *
 * @param string $strLevel
 * @param string $sFilePath
 * @return string
 */
PHP_METHOD(Queryyetsimple_Log_Aconnect, getPath) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strLevel_param = NULL, sFilePath, _0$$3, _1$$3, _3$$3, _4$$3, _6$$3, _7$$3;
	zval strLevel, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&sFilePath);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &strLevel_param);

	if (!strLevel_param) {
		ZEPHIR_INIT_VAR(&strLevel);
		ZVAL_STRING(&strLevel, "");
	} else {
		zephir_get_strval(&strLevel, strLevel_param);
	}


	if (ZEPHIR_IS_EMPTY(&sFilePath)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "path");
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getoption", &_2, 0, &_1$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0$$3))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Default path for log has not specified.", "queryyetsimple/log/aconnect.zep", 203);
			return;
		}
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "path");
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getoption", &_2, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		if (!(Z_TYPE_P(&strLevel) == IS_UNDEF) && Z_STRLEN_P(&strLevel)) {
			ZEPHIR_INIT_VAR(&_5$$3);
			ZEPHIR_CONCAT_VS(&_5$$3, &strLevel, "/");
			ZEPHIR_CPY_WRT(&_4$$3, &_5$$3);
		} else {
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "");
		}
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "name");
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "getoption", &_2, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_7$$3, "date", NULL, 9, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&sFilePath);
		ZEPHIR_CONCAT_VSVVS(&sFilePath, &_3$$3, "/", &_4$$3, &_7$$3, ".log");
	}
	RETURN_CCTOR(&sFilePath);

}

zend_object *zephir_init_properties_Queryyetsimple_Log_Aconnect(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("arrOption"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

