
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
#include "kernel/array.h"
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
ZEPHIR_INIT_CLASS(Queryyetsimple_Di_Provider) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Di, Provider, queryyetsimple, di_provider, queryyetsimple_di_provider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 是否延迟载入
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(queryyetsimple_di_provider_ce, SL("defer"), 0, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * IOC 容器
	 *
	 * @var \Queryyetsimple\Di\IContainer
	 */
	zend_declare_property_null(queryyetsimple_di_provider_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Queryyetsimple\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Queryyetsimple_Di_Provider, __construct) {

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
PHP_METHOD(Queryyetsimple_Di_Provider, register) {

}

/**
 * 注册服务别名
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Di_Provider, registerAlias) {

	zend_bool _1;
	zval _0, _2, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

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
		ZEPHIR_CALL_STATIC(&_3$$3, "providers", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", NULL, 0, &_3$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Di_Provider, providers) {

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
PHP_METHOD(Queryyetsimple_Di_Provider, isDeferred) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, queryyetsimple_di_provider_ce, SL("defer"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

/**
 * 返回 IOC 容器
 *
 * @return \Queryyetsimple\Di\IContainer
 */
PHP_METHOD(Queryyetsimple_Di_Provider, container) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * 注册到容器
 *
 * @param mixed $name
 * @param mixed $service
 * @param boolean $share
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Di_Provider, bind) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool share;
	zval *name, name_sub, *service = NULL, service_sub, *share_param = NULL, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&service_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name, &service, &share_param);

	if (!service) {
		service = &service_sub;
		service = &__$null;
	}
	if (!share_param) {
		share = 0;
	} else {
		share = zephir_get_boolval(share_param);
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	if (share) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "bind", NULL, 0, name, service, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 注册为实例
 *
 * @param mixed $name
 * @param mixed $service
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Di_Provider, instance) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *service = NULL, service_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&service_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &service);

	if (!service) {
		service = &service_sub;
		service = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "instance", NULL, 0, name, service);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 注册单一实例
 *
 * @param scalar|array $name
 * @param mixed $service
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Di_Provider, singleton) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *service = NULL, service_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&service_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &service);

	if (!service) {
		service = &service_sub;
		service = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, name, service);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 创建共享的闭包
 *
 * @param \Closure $closures
 * @return \Closure
 */
PHP_METHOD(Queryyetsimple_Di_Provider, share) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *closures, closures_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&closures_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &closures);



	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "share", NULL, 0, closures);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置别名
 *
 * @param array|string $alias
 * @param string|null|array $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Di_Provider, alias) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub, *value = NULL, value_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias, &value);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "alias", NULL, 0, alias, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 添加语言包目录
 *
 * @param mixed $dir
 * @return void
 */
PHP_METHOD(Queryyetsimple_Di_Provider, loadI18nDir) {

	zval _5$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dir = NULL, dir_sub, option, load, _0, _1, _2, _3, _4, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir_sub);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&load);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir);

	ZEPHIR_SEPARATE_PARAM(dir);


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&option, &_0, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "i18n\\on");
	ZEPHIR_CALL_METHOD(&_2, &option, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "i18n\\develop");
	ZEPHIR_CALL_METHOD(&_3, &option, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "i18n\\default");
	ZEPHIR_CALL_METHOD(&_4, &option, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_EQUAL(&_3, &_4)) {
		RETURN_MM_NULL();
	}
	if (!(Z_TYPE_P(dir) == IS_ARRAY)) {
		zephir_get_arrval(&_5$$5, dir);
		ZEPHIR_CPY_WRT(dir, &_5$$5);
	}
	zephir_read_property(&_6, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "i18n.load");
	ZEPHIR_CALL_METHOD(&load, &_6, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &load, "adddir", NULL, 0, dir);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 添加命令包命名空间
 *
 * @param mixed $namespaces
 * @return void
 */
PHP_METHOD(Queryyetsimple_Di_Provider, loadCommandNamespace) {

	zval _2$$4;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespaces = NULL, namespaces_sub, result, item, psr4, load, _0, _1, _3, _4, _5, *_6, _7$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&psr4);
	ZVAL_UNDEF(&load);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaces);

	ZEPHIR_SEPARATE_PARAM(namespaces);


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "console", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	if (!(Z_TYPE_P(namespaces) == IS_ARRAY)) {
		zephir_get_arrval(&_2$$4, namespaces);
		ZEPHIR_CPY_WRT(namespaces, &_2$$4);
	}
	zephir_read_property(&_3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "psr4");
	ZEPHIR_CALL_METHOD(&psr4, &_3, "make", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "console.load");
	ZEPHIR_CALL_METHOD(&load, &_5, "make", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_is_iterable(namespaces, 0, "queryyetsimple/di/provider.zep", 229);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(namespaces), _6)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _6);
		ZEPHIR_CALL_METHOD(&_7$$5, &psr4, "namespaces", &_8, 0, &item);
		zephir_check_call_status();
		zephir_array_update_zval(&result, &item, &_7$$5, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_CALL_METHOD(NULL, &load, "addnamespace", NULL, 0, &result);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Di_Provider, __call) {

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
	zephir_throw_exception_debug(&_0, "queryyetsimple/di/provider.zep", 244 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

