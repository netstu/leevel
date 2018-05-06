
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.25
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Di_Provider) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Di, Provider, leevel, di_provider, leevel_di_provider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 是否延迟载入
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(leevel_di_provider_ce, SL("defer"), 0, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * IOC 容器
	 *
	 * @var \Leevel\Di\IContainer
	 */
	zend_declare_property_null(leevel_di_provider_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Di_Provider, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);
	ZEPHIR_CALL_STATIC(&_0, "isdeferred", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registeralias", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Di_Provider, register) {

}

/**
 * 注册服务别名
 *
 * @return void
 */
PHP_METHOD(Leevel_Di_Provider, registerAlias) {

	zend_bool _1;
	zval _0, _2, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_STATIC(&_0, "isdeferred", NULL, 0);
	zephir_check_call_status();
	_1 = !zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_CALL_STATIC(&_2, "providers", NULL, 0);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		zephir_read_property(&_3$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_STATIC(&_4$$3, "providers", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "alias", NULL, 0, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Leevel_Di_Provider, providers) {

	zval tmparr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmparr);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmparr);
	array_init(&tmparr);
	RETURN_CCTOR(&tmparr);

}

/**
 * 是否延迟载入
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Di_Provider, isDeferred) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, leevel_di_provider_ce, SL("defer"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

/**
 * 返回 IOC 容器
 *
 * @return \Leevel\Di\IContainer
 */
PHP_METHOD(Leevel_Di_Provider, container) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Di_Provider, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _1, _2;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	if (ZEPHIR_IS_STRING(&method, "bootstrap")) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Method %s is not exits.");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 1, &_1, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "leevel/di/provider.zep", 123 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

