
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * 实现类的静态访问门面
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.23
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Face) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Support, Face, queryyetsimple, support_face, queryyetsimple_support_face_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 项目容器
	 *
	 * @var \Queryyetsimple\Support\IContainer
	 */
	zend_declare_property_null(queryyetsimple_support_face_ce, SL("container"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 注入容器实例
	 *
	 * @var object
	 */
	zend_declare_property_null(queryyetsimple_support_face_ce, SL("instances"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * 获取注册容器的实例
 *
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Support_Face, faces) {

	zval unique, instance, _0, _1, _2$$4, _3$$4, _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&unique);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_STATIC(&unique, "name", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&instance);
	zephir_read_static_property_ce(&_0, queryyetsimple_support_face_ce, SL("instances"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&instance, &_0, &unique, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&instance);
	}
	ZEPHIR_CALL_SELF(&_1, "container", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&instance, &_1, "make", NULL, 0, &unique);
	zephir_check_call_status();
	if (Z_TYPE_P(&instance) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "Services %s was not found in the IOC container.");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "sprintf", NULL, 1, &_3$$4, &unique);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 2, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "queryyetsimple/support/face.zep", 69 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&instance);

}

/**
 * 返回服务容器
 *
 * @return \Queryyetsimple\Support\IContainer
 */
PHP_METHOD(Queryyetsimple_Support_Face, container) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, queryyetsimple_support_face_ce, SL("container"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

/**
 * 设置服务容器
 *
 * @param \Queryyetsimple\Support\IContainer $container
 * @return void
 */
PHP_METHOD(Queryyetsimple_Support_Face, setContainer) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zend_update_static_property(queryyetsimple_support_face_ce, ZEND_STRL("container"), container);

}

/**
 * 门面名字
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Support_Face, name) {

	zval *this_ptr = getThis();


	RETURN_STRING("");

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Support_Face, __callStatic) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, instance, callback, _0$$4, _1$$4, _2$$4;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&instance, "faces", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&instance))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Can not find instance from container.", "queryyetsimple/support/face.zep", 118);
		return;
	}
	ZEPHIR_INIT_VAR(&callback);
	zephir_create_array(&callback, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&callback, &instance);
	zephir_array_fast_append(&callback, &method);
	if (!(zephir_is_callable(&callback TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, spl_ce_BadMethodCallException);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "Method %s is not exits.");
		ZEPHIR_CALL_FUNCTION(&_2$$4, "sprintf", NULL, 1, &_1$$4, &method);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 3, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "queryyetsimple/support/face.zep", 126 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &callback, &args);
	zephir_check_call_status();
	RETURN_MM();

}

void zephir_init_static_properties_Queryyetsimple_Support_Face(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(queryyetsimple_support_face_ce, ZEND_STRL("instances"), &_0);
	ZEPHIR_MM_RESTORE();

}

