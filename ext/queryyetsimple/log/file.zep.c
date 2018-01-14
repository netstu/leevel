
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"


/**
 * log.file
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.08
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Log_File) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Log, File, queryyetsimple, log_file, queryyetsimple_log_aconnect_ce, queryyetsimple_log_file_method_entry, 0);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_log_file_ce, SL("arrOption"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_log_file_ce->create_object = zephir_init_properties_Queryyetsimple_Log_File;

	zend_class_implements(queryyetsimple_log_file_ce TSRMLS_CC, 1, queryyetsimple_log_iconnect_ce);
	return SUCCESS;

}

/**
 * 日志写入接口
 *
 * @param array $arrData
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_File, save) {

	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrData_param = NULL, strDestination, arrItem, _0, _1, *_2, _3$$3, _4$$3, _5$$3, _7$$3, _8$$3, _9$$3;
	zval arrData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrData);
	ZVAL_UNDEF(&strDestination);
	ZVAL_UNDEF(&arrItem);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrData_param);

	zephir_get_arrval(&arrData, arrData_param);


	zephir_array_fetch_long(&_0, &arrData, 0, PH_NOISY | PH_READONLY, "queryyetsimple/log/file.zep", 58 TSRMLS_CC);
	zephir_array_fetch_long(&_1, &_0, 0, PH_NOISY | PH_READONLY, "queryyetsimple/log/file.zep", 58 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&strDestination, this_ptr, "getpath", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checksize", NULL, 0, &strDestination);
	zephir_check_call_status();
	zephir_is_iterable(&arrData, 0, "queryyetsimple/log/file.zep", 65);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrData), _2)
	{
		ZEPHIR_INIT_NVAR(&arrItem);
		ZVAL_COPY(&arrItem, _2);
		zephir_array_fetch_long(&_4$$3, &arrItem, 1, PH_NOISY | PH_READONLY, "queryyetsimple/log/file.zep", 63 TSRMLS_CC);
		zephir_array_fetch_long(&_5$$3, &arrItem, 2, PH_NOISY | PH_READONLY, "queryyetsimple/log/file.zep", 63 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "formatmessage", &_6, 0, &_4$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZEPHIR_GET_CONSTANT(&_7$$3, "PHP_EOL");
		ZEPHIR_INIT_LNVAR(_8$$3);
		ZEPHIR_CONCAT_VV(&_8$$3, &_3$$3, &_7$$3);
		ZVAL_LONG(&_9$$3, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_10, 23, &_8$$3, &_9$$3, &strDestination);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrItem);
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化日志信息
 *
 * @param string $strMessage 应该被记录的错误信息
 * @param array $arrContext
 * @return string
 */
PHP_METHOD(Queryyetsimple_Log_File, formatMessage) {

	zval arrContext;
	zval *strMessage_param = NULL, *arrContext_param = NULL, _0, _1;
	zval strMessage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strMessage);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strMessage_param, &arrContext_param);

	zephir_get_strval(&strMessage, strMessage_param);
	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_1, 256);
	zephir_json_encode(&_0, &arrContext, zephir_get_intval(&_1) );
	ZEPHIR_CONCAT_VSV(return_value, &strMessage, " ", &_0);
	RETURN_MM();

}

zend_object *zephir_init_properties_Queryyetsimple_Log_File(zend_class_entry *class_type TSRMLS_DC) {

		zval _3$$4;
	zval _0, _2, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_3$$4, SL("name"), SL("Y-m-d H"));
			add_assoc_long_ex(&_3$$4, SL("size"), 2097152);
			add_assoc_stringl_ex(&_3$$4, SL("path"), SL(""));
			zephir_update_property_zval(this_ptr, SL("arrOption"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

