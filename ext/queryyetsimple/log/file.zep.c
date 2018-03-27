
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

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Log, File, queryyetsimple, log_file, queryyetsimple_log_connect_ce, queryyetsimple_log_file_method_entry, 0);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_log_file_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_log_file_ce->create_object = zephir_init_properties_Queryyetsimple_Log_File;

	zend_class_implements(queryyetsimple_log_file_ce TSRMLS_CC, 1, queryyetsimple_log_iconnect_ce);
	return SUCCESS;

}

/**
 * 日志写入接口
 *
 * @param array $datas
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_File, save) {

	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *datas_param = NULL, filepath, item, _0, _1, *_2, _3$$3, _4$$3, _5$$3, _7$$3, _8$$3, _9$$3;
	zval datas;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&datas);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datas_param);

	zephir_get_arrval(&datas, datas_param);


	zephir_array_fetch_long(&_0, &datas, 0, PH_NOISY | PH_READONLY, "queryyetsimple/log/file.zep", 55 TSRMLS_CC);
	zephir_array_fetch_long(&_1, &_0, 0, PH_NOISY | PH_READONLY, "queryyetsimple/log/file.zep", 55 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getpath", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checksize", NULL, 0, &filepath);
	zephir_check_call_status();
	zephir_is_iterable(&datas, 0, "queryyetsimple/log/file.zep", 62);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&datas), _2)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _2);
		zephir_array_fetch_long(&_4$$3, &item, 1, PH_NOISY | PH_READONLY, "queryyetsimple/log/file.zep", 60 TSRMLS_CC);
		zephir_array_fetch_long(&_5$$3, &item, 2, PH_NOISY | PH_READONLY, "queryyetsimple/log/file.zep", 60 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "formatmessage", &_6, 0, &_4$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZEPHIR_GET_CONSTANT(&_7$$3, "PHP_EOL");
		ZEPHIR_INIT_LNVAR(_8$$3);
		ZEPHIR_CONCAT_VV(&_8$$3, &_3$$3, &_7$$3);
		ZVAL_LONG(&_9$$3, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_10, 95, &_8$$3, &_9$$3, &filepath);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化日志信息
 *
 * @param string $message 应该被记录的错误信息
 * @param array $contexts
 * @return string
 */
PHP_METHOD(Queryyetsimple_Log_File, formatMessage) {

	zval contexts;
	zval *message_param = NULL, *contexts_param = NULL, _0, _1;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&contexts);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &contexts_param);

	zephir_get_strval(&message, message_param);
	if (!contexts_param) {
		ZEPHIR_INIT_VAR(&contexts);
		array_init(&contexts);
	} else {
		zephir_get_arrval(&contexts, contexts_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_1, 256);
	zephir_json_encode(&_0, &contexts, zephir_get_intval(&_1) );
	ZEPHIR_CONCAT_VSV(return_value, &message, " ", &_0);
	RETURN_MM();

}

zend_object *zephir_init_properties_Queryyetsimple_Log_File(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("name"), SL("Y-m-d H"));
			add_assoc_long_ex(&_1$$3, SL("size"), 2097152);
			add_assoc_stringl_ex(&_1$$3, SL("path"), SL(""));
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

