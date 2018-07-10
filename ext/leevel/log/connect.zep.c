
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
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
ZEPHIR_INIT_CLASS(Leevel_Log_Connect) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Log, Connect, leevel, log_connect, leevel_log_connect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_log_connect_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_log_connect_ce->create_object = zephir_init_properties_Leevel_Log_Connect;
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Log_Connect, __construct) {

	zval *option_param = NULL, _0, _1;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &option TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("option"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Leevel_Log_Connect, setOption) {

	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("option"), &name, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 验证日志文件大小
 *
 * @param string $filepath
 * @return void
 */
PHP_METHOD(Leevel_Log_Connect, checkSize) {

	zend_bool _2, _4, _11;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filepath_param = NULL, __$true, filedir, _0, _3, _5, _6, _10, _12, _13, _7$$3, _8$$3, _9$$3, _14$$4, _15$$4, _16$$4;
	zval filepath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filepath);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&filedir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filepath_param);

	zephir_get_strval(&filepath, filepath_param);


	ZEPHIR_CALL_FUNCTION(&filedir, "dirname", NULL, 26, &filepath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 27, &filepath);
	zephir_check_call_status();
	_2 = !zephir_is_true(&_0);
	if (_2) {
		ZEPHIR_CALL_FUNCTION(&_3, "is_dir", NULL, 28, &filedir);
		zephir_check_call_status();
		_2 = !zephir_is_true(&_3);
	}
	_4 = _2;
	if (_4) {
		ZVAL_LONG(&_5, 0777);
		ZEPHIR_CALL_FUNCTION(&_6, "mkdir", NULL, 29, &filedir, &_5, &__$true);
		zephir_check_call_status();
		_4 = !zephir_is_true(&_6);
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_7$$3);
		object_init_ex(&_7$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "Unable to create log file：%s.");
		ZEPHIR_CALL_FUNCTION(&_9$$3, "sprintf", NULL, 1, &_8$$3, &filepath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$3, "__construct", NULL, 2, &_9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "leevel/log/connect.zep", 81 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_10, "is_file", &_1, 27, &filepath);
	zephir_check_call_status();
	_11 = zephir_is_true(&_10);
	if (_11) {
		zephir_read_property(&_5, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_12, &_5, SL("size"), PH_NOISY | PH_READONLY, "leevel/log/connect.zep", 86 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_13, "filesize", NULL, 30, &filepath);
		zephir_check_call_status();
		_11 = ZEPHIR_GE_LONG(&_13, zephir_floor(&_12 TSRMLS_CC));
	}
	if (_11) {
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "Y-m-d H.i.s");
		ZEPHIR_CALL_FUNCTION(&_15$$4, "date", NULL, 31, &_14$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_14$$4);
		zephir_basename(&_14$$4, &filepath TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_16$$4);
		ZEPHIR_CONCAT_VSVSV(&_16$$4, &filedir, "/", &_15$$4, "_", &_14$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "rename", NULL, 32, &filepath, &_16$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取日志路径
 *
 * @param string $level
 * @param string $filepath
 * @return string
 */
PHP_METHOD(Leevel_Log_Connect, getPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *level_param = NULL, filepath, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _6$$3, _7$$3, _8$$3;
	zval level, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &level_param);

	if (!level_param) {
		ZEPHIR_INIT_VAR(&level);
		ZVAL_STRING(&level, "");
	} else {
		zephir_get_strval(&level, level_param);
	}


	if (ZEPHIR_IS_EMPTY(&filepath)) {
		zephir_read_property(&_0$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_1$$3, &_0$$3, SL("path"), PH_NOISY | PH_READONLY, "leevel/log/connect.zep", 108 TSRMLS_CC);
		if (!(zephir_is_true(&_1$$3))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Default path for log has not specified.", "leevel/log/connect.zep", 111);
			return;
		}
		zephir_read_property(&_2$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3$$3, &_2$$3, SL("path"), PH_NOISY | PH_READONLY, "leevel/log/connect.zep", 114 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4$$3);
		if (!(Z_TYPE_P(&level) == IS_UNDEF) && Z_STRLEN_P(&level)) {
			ZEPHIR_INIT_VAR(&_5$$3);
			ZEPHIR_CONCAT_VS(&_5$$3, &level, "/");
			ZEPHIR_CPY_WRT(&_4$$3, &_5$$3);
		} else {
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "");
		}
		zephir_read_property(&_6$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_7$$3, &_6$$3, SL("name"), PH_NOISY | PH_READONLY, "leevel/log/connect.zep", 116 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_8$$3, "date", NULL, 31, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&filepath);
		ZEPHIR_CONCAT_VSVVS(&filepath, &_3$$3, "/", &_4$$3, &_8$$3, ".log");
	}
	RETURN_CCTOR(&filepath);

}

zend_object *zephir_init_properties_Leevel_Log_Connect(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

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
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

