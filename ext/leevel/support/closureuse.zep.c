
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/main.h"


/**
 * zephir 不支持 Closure use 替代解决方案
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Support_ClosureUse) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Support, ClosureUse, leevel, support_closureuse, leevel_support_closureuse_method_entry, 0);

	/**
	 * 待处理的闭包
	 *
	 * @var \Closure
	 */
	zend_declare_property_null(leevel_support_closureuse_ce, SL("closures"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * use 参数
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_support_closureuse_ce, SL("args"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_support_closureuse_ce->create_object = zephir_init_properties_Leevel_Support_ClosureUse;
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Closure $closures
 * @param array $args
 * @return void
 */
PHP_METHOD(Leevel_Support_ClosureUse, __construct) {

	zval args;
	zval *closures, closures_sub, *args_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&closures_sub);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &closures, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	zephir_update_property_zval(this_ptr, SL("closures"), closures);
	zephir_update_property_zval(this_ptr, SL("args"), &args);
	ZEPHIR_MM_RESTORE();

}

/**
 * 生成仿 use 闭包
 * 
 * @param \Closure $closures
 * @param array $args
 * @return \Closure
 */
PHP_METHOD(Leevel_Support_ClosureUse, make) {

	zend_class_entry *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args, _1;
	zval *closures, closures_sub, *args_param = NULL, newclosure, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&closures_sub);
	ZVAL_UNDEF(&newclosure);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &closures, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	ZEPHIR_INIT_VAR(&newclosure);
	object_init_ex(&newclosure, leevel_support_closureuse_ce);
	ZEPHIR_CALL_METHOD(NULL, &newclosure, "__construct", NULL, 119, closures, &args);
	zephir_check_call_status();
	_0 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &newclosure);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "invoke");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_RETURN_CALL_CE_STATIC(_0, "fromcallable", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * __invoke 魔术方法不支持
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Support_ClosureUse, invoke) {

	zval args, item, _0, _3, _1$$3, *_2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	zephir_read_property(&_0, this_ptr, SL("args"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("args"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "leevel/support/closureuse.zep", 86);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _2$$3);
			zephir_array_append(&args, &item, PH_SEPARATE, "leevel/support/closureuse.zep", 84);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
	}
	zephir_read_property(&_3, this_ptr, SL("closures"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_3, &args);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Support_ClosureUse(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("args"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("args"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

