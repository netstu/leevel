
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_closures.h"


/**
 * IOC 容器
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.24
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Di_Container) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Di, Container, leevel, di_container, leevel_di_container_method_entry, 0);

	/**
	 * 注册服务
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_di_container_ce, SL("services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 注册的实例
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_di_container_ce, SL("instances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 单一实例
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_di_container_ce, SL("singletons"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 别名支持
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_di_container_ce, SL("alias"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * share 静态变量值
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_di_container_ce, SL("shareClosure"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * share 传递闭包参数
	 *
	 * @var \Closure
	 */
	zend_declare_property_null(leevel_di_container_ce, SL("shareUseClosures"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_di_container_ce->create_object = zephir_init_properties_Leevel_Di_Container;

	zend_class_implements(leevel_di_container_ce TSRMLS_CC, 1, leevel_di_icontainer_ce);
	zend_class_implements(leevel_di_container_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * 注册到容器
 *
 * @param mixed $name
 * @param mixed $service
 * @param boolean $share
 * @return $this
 */
PHP_METHOD(Leevel_Di_Container, bind) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool share;
	zval *name = NULL, name_sub, *service = NULL, service_sub, *share_param = NULL, __$null, alias, templist$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&service_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&templist$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name, &service, &share_param);

	ZEPHIR_SEPARATE_PARAM(name);
	if (!service) {
		service = &service_sub;
		ZEPHIR_CPY_WRT(service, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(service);
	}
	if (!share_param) {
		share = 0;
	} else {
		share = zephir_get_boolval(share_param);
	}


	if (Z_TYPE_P(name) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&templist$$3, this_ptr, "parsealias", NULL, 0, name);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&templist$$3);
		ZEPHIR_CALL_FUNCTION(name, "array_shift", &_0, 6, &templist$$3);
		ZEPHIR_UNREF(&templist$$3);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&templist$$3);
		ZEPHIR_CALL_FUNCTION(&alias, "array_shift", &_0, 6, &templist$$3);
		ZEPHIR_UNREF(&templist$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", NULL, 0, name, &alias);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(service) == IS_NULL) {
		ZEPHIR_CPY_WRT(service, name);
	}
	zephir_update_property_array(this_ptr, SL("services"), name, service TSRMLS_CC);
	if (share) {
		zephir_update_property_array_append(this_ptr, SL("singletons"), name TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * 注册为实例
 *
 * @param mixed $name
 * @param mixed $service
 * @return $this
 */
PHP_METHOD(Leevel_Di_Container, instance) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, *service = NULL, service_sub, __$null, alias, templist$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&service_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&templist$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &service);

	ZEPHIR_SEPARATE_PARAM(name);
	if (!service) {
		service = &service_sub;
		ZEPHIR_CPY_WRT(service, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(service);
	}


	if (Z_TYPE_P(name) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&templist$$3, this_ptr, "parsealias", NULL, 0, name);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&templist$$3);
		ZEPHIR_CALL_FUNCTION(name, "array_shift", &_0, 6, &templist$$3);
		ZEPHIR_UNREF(&templist$$3);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&templist$$3);
		ZEPHIR_CALL_FUNCTION(&alias, "array_shift", &_0, 6, &templist$$3);
		ZEPHIR_UNREF(&templist$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", NULL, 0, name, &alias);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(service) == IS_NULL) {
		ZEPHIR_CPY_WRT(service, name);
	}
	zephir_update_property_array(this_ptr, SL("instances"), name, service TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 注册单一实例
 *
 * @param scalar|array $name
 * @param mixed $service
 * @return $this
 */
PHP_METHOD(Leevel_Di_Container, singleton) {

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


	ZVAL_BOOL(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "bind", NULL, 0, name, service, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建共享的闭包
 *
 * @param \Closure $closures
 * @return \Closure
 */
PHP_METHOD(Leevel_Di_Container, share) {

	zval _1;
	zend_class_entry *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *closures, closures_sub, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&closures_sub);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &closures);



	zephir_update_property_zval(this_ptr, SL("shareUseClosures"), closures);
	_0 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "shareClosure");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_RETURN_CALL_CE_STATIC(_0, "fromcallable", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 share 闭包
 * 
 * @param \Leevel\Di\IContainer $container
 * @return mixed
 */
PHP_METHOD(Leevel_Di_Container, shareClosure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, hash, obj, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	zephir_read_property(&_0, this_ptr, SL("shareUseClosures"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&hash, "spl_object_hash", NULL, 30, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&obj);
	zephir_read_property(&_1, this_ptr, SL("shareClosure"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&obj, &_1, &hash, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&obj);
	}
	zephir_read_property(&_2, this_ptr, SL("shareUseClosures"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&obj, "call_user_func", NULL, 8, &_2, container);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("shareClosure"), &hash, &obj TSRMLS_CC);
	RETURN_CCTOR(&obj);

}

/**
 * 设置别名
 *
 * @param array|string $alias
 * @param string|null|array $value
 * @return $this
 */
PHP_METHOD(Leevel_Di_Container, alias) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub, *value = NULL, value_sub, __$null, key, item, tmp, *_0$$3, *_4$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&tmp);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias, &value);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	if (Z_TYPE_P(alias) == IS_ARRAY) {
		zephir_is_iterable(alias, 0, "leevel/di/container.zep", 206);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(alias), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0$$3);
			if (Z_TYPE_P(&key) == IS_LONG) {
				continue;
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", &_3, 31, &key, &item);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(&tmp, value);
		} else {
			ZEPHIR_INIT_NVAR(&tmp);
			zephir_create_array(&tmp, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&tmp, value);
		}
		zephir_is_iterable(&tmp, 0, "leevel/di/container.zep", 212);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmp), _4$$6)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _4$$6);
			zephir_update_property_array(this_ptr, SL("alias"), &item, alias TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
	}
	RETURN_THIS();

}

/**
 * 服务容器返回对象
 *
 * @param string $name
 * @param array $args
 * @return object|false
 */
PHP_METHOD(Leevel_Di_Container, make) {

	zend_bool _8;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *name = NULL, name_sub, *args_param = NULL, instance, _0, _1, _4, _6, _7, _9, _10, _18, _2$$3, _3$$3, _11$$5, _12$$5, _13$$7, _14$$7, _15$$8, _16$$8, _17$$9, _19$$10, _20$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &args_param);

	ZEPHIR_SEPARATE_PARAM(name);
	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getalias", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property(&_1, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, name)) {
		zephir_read_property(&_2$$3, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, name, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 233 TSRMLS_CC);
		RETURN_CTOR(&_3$$3);
	}
	zephir_read_property(&_4, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_4, name))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getinjectionobject", &_5, 0, name, &args);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_6, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_7);
	zephir_array_fetch(&_7, &_6, name, PH_NOISY, "leevel/di/container.zep", 241 TSRMLS_CC);
	_8 = Z_TYPE_P(&_7) != IS_STRING;
	if (_8) {
		zephir_read_property(&_9, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_10, &_9, name, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 241 TSRMLS_CC);
		_8 = zephir_is_callable(&_10 TSRMLS_CC);
	}
	if (_8) {
		if (ZEPHIR_IS_EMPTY(&args)) {
			ZEPHIR_INIT_NVAR(&args);
			array_init(&args);
		}
		ZEPHIR_MAKE_REF(&args);
		ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 32, &args, this_ptr);
		ZEPHIR_UNREF(&args);
		zephir_check_call_status();
		zephir_read_property(&_11$$5, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_12$$5, &_11$$5, name, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 247 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&instance);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&instance, &_12$$5, &args);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_13$$7, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_14$$7);
		zephir_array_fetch(&_14$$7, &_13$$7, name, PH_NOISY, "leevel/di/container.zep", 249 TSRMLS_CC);
		if (Z_TYPE_P(&_14$$7) == IS_STRING) {
			zephir_read_property(&_15$$8, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_16$$8, &_15$$8, name, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 250 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&instance, this_ptr, "getinjectionobject", &_5, 0, &_16$$8, &args);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_17$$9, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&instance);
			zephir_array_fetch(&instance, &_17$$9, name, PH_NOISY, "leevel/di/container.zep", 252 TSRMLS_CC);
		}
	}
	zephir_read_property(&_18, this_ptr, SL("singletons"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_in_array(name, &_18 TSRMLS_CC)) {
		zephir_update_property_array(this_ptr, SL("instances"), name, &instance TSRMLS_CC);
		zephir_read_property(&_19$$10, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_20$$10, &_19$$10, name, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 259 TSRMLS_CC);
		RETURN_CTOR(&_20$$10);
	} else {
		RETURN_CCTOR(&instance);
	}

}

/**
 * 实例回调自动注入
 *
 * @param callable|array|string $callback
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Di_Container, call) {

	zend_bool isStatic, _6, _11$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *callback = NULL, callback_sub, *args_param = NULL, _15, _0$$3, _1$$3, _2$$3, _3$$3, _4$$4, _5$$5, _7$$6, _12$$6, _8$$7, _9$$7, _10$$7, _13$$9, _14$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &args_param);

	ZEPHIR_SEPARATE_PARAM(callback);
	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	isStatic = 0;
	if (Z_TYPE_P(callback) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "@");
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strpos(&_1$$3, callback, &_0$$3, 0 );
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "::");
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_fast_strpos(&_3$$3, callback, &_2$$3, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_fast_explode_str(&_4$$4, SL("@"), callback, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(callback, &_4$$4);
		} else if (!ZEPHIR_IS_FALSE_IDENTICAL(&_3$$3)) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_fast_explode_str(&_5$$5, SL("::"), callback, LONG_MAX TSRMLS_CC);
			ZEPHIR_CPY_WRT(callback, &_5$$5);
			isStatic = 1;
		}
	}
	_6 = isStatic == 0;
	if (_6) {
		_6 = Z_TYPE_P(callback) == IS_ARRAY;
	}
	if (_6) {
		zephir_array_fetch_long(&_7$$6, callback, 0, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 289 TSRMLS_CC);
		if (!(Z_TYPE_P(&_7$$6) == IS_OBJECT)) {
			zephir_array_fetch_long(&_8$$7, callback, 0, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 290 TSRMLS_CC);
			if (!(Z_TYPE_P(&_8$$7) == IS_STRING)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The classname must be string.", "leevel/di/container.zep", 291);
				return;
			}
			zephir_array_fetch_long(&_10$$7, callback, 0, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 294 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "getinjectionobject", NULL, 0, &_10$$7);
			zephir_check_call_status();
			zephir_array_update_long(callback, 0, &_9$$7, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		_11$$6 = !(zephir_array_isset_long(callback, 1));
		if (!(_11$$6)) {
			zephir_array_fetch_long(&_12$$6, callback, 1, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 297 TSRMLS_CC);
			_11$$6 = ZEPHIR_IS_EMPTY(&_12$$6);
		}
		if (_11$$6) {
			ZEPHIR_INIT_VAR(&_13$$9);
			zephir_array_fetch_long(&_14$$9, callback, 0, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 298 TSRMLS_CC);
			if ((zephir_method_exists_ex(&_14$$9, SL("handle") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_INIT_NVAR(&_13$$9);
				ZVAL_STRING(&_13$$9, "handle");
			} else {
				ZEPHIR_INIT_NVAR(&_13$$9);
				ZVAL_STRING(&_13$$9, "run");
			}
			zephir_array_update_long(callback, 1, &_13$$9, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
	}
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "normalizeinjectionargs", NULL, 0, callback, &args);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, callback, &_15);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除服务和实例
 *
 * @param string $name
 * @return void
 */
PHP_METHOD(Leevel_Di_Container, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, _0, _1, _3, _5, _2$$3, _4$$4, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);

	ZEPHIR_SEPARATE_PARAM(name);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalize", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property(&_1, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, name)) {
		zephir_read_property(&_2$$3, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_2$$3, name, PH_SEPARATE);
	}
	zephir_read_property(&_3, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_3, name)) {
		zephir_read_property(&_4$$4, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_4$$4, name, PH_SEPARATE);
	}
	zephir_read_property(&_5, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_5, name)) {
		zephir_read_property(&_6$$5, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_6$$5, name, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 服务或者实例是否存在
 *
 * @param string $name
 * @return bool
 */
PHP_METHOD(Leevel_Di_Container, exists) {

	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);

	ZEPHIR_SEPARATE_PARAM(name);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalize", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(name, &_0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getalias", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property(&_1, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_array_isset(&_1, name);
	if (!(_2)) {
		zephir_read_property(&_3, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		_2 = zephir_array_isset(&_3, name);
	}
	RETURN_MM_BOOL(_2);

}

/**
 * 统一去掉前面的斜杠
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Leevel_Di_Container, normalize) {

	zval *name, name_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	zephir_fast_trim(return_value, name, &_0, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	RETURN_MM();

}

/**
 * 返回对象别名
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Leevel_Di_Container, getAlias) {

	zval *name, name_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("alias"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, name)) {
		zephir_read_property(&_2, this_ptr, SL("alias"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, name, PH_NOISY, "leevel/di/container.zep", 362 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, name);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 根据 class 名字创建实例
 *
 * @param string $classname
 * @param array $args
 * @return object
 */
PHP_METHOD(Leevel_Di_Container, getInjectionObject) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *classname, classname_sub, *args_param = NULL, _0$$3, _1$$3, _2$$3, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classname_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classname, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	if (zephir_interface_exists(classname, 1  TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, leevel_di_containerinvalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Interface %s can not be normalize because not binded.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", NULL, 1, &_1$$3, classname);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "leevel/di/container.zep", 380 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_class_exists(classname, 1 TSRMLS_CC))) {
		RETVAL_ZVAL(classname, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "normalizeinjectionargs", NULL, 0, classname, &args);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstanceargs", NULL, 0, classname, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 格式化依赖参数
 *
 * @param mixed $value
 * @param array $args
 * @return array|void
 */
PHP_METHOD(Leevel_Di_Container, normalizeInjectionArgs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *value, value_sub, *args_param = NULL, tmp, required, tmpArgs, validArgs, _0$$3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&required);
	ZVAL_UNDEF(&tmpArgs);
	ZVAL_UNDEF(&validArgs);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &args_param);

	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "parseinjection", NULL, 0, value, &args);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&tmpArgs);
	zephir_array_fetch_long(&tmpArgs, &tmp, 0, PH_NOISY, "leevel/di/container.zep", 405 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&required);
	zephir_array_fetch_long(&required, &tmp, 1, PH_NOISY, "leevel/di/container.zep", 406 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&validArgs);
	zephir_array_fetch_long(&validArgs, &tmp, 2, PH_NOISY, "leevel/di/container.zep", 407 TSRMLS_CC);
	if (ZEPHIR_LT(&validArgs, &required)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, leevel_di_containerinvalidargumentexception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "There are %d required args,but %d gived.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", NULL, 1, &_1$$3, &required, &validArgs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "leevel/di/container.zep", 416 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&tmpArgs);

}

/**
 * 分析自动依赖注入
 *
 * @param mixed $injection
 * @param array $args
 * @return array
 */
PHP_METHOD(Leevel_Di_Container, parseInjection) {

	zend_string *_17$$14;
	zend_ulong _16$$14;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, required;
	zval args;
	zval *injection, injection_sub, *args_param = NULL, result, param, item, argsclass, data, e, k, value, validArgs, *_0, _18, _2$$4, _9$$4, _3$$5, _5$$9, _6$$9, _7$$10, _8$$11, _10$$3, _11$$13, _12$$13, _14$$14, *_15$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&injection_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&argsclass);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&validArgs);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &injection, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	required = 0;
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_CALL_METHOD(&param, this_ptr, "parsereflection", NULL, 0, injection);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&validArgs);
	ZVAL_LONG(&validArgs, zephir_fast_count_int(&param TSRMLS_CC));
	zephir_is_iterable(&param, 0, "leevel/di/container.zep", 474);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&param), _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _0);

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&argsclass, this_ptr, "parseparameterclass", &_1, 0, &item);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_2$$4, &item, "isdefaultvalueavailable", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (zephir_is_true(&argsclass)) {
				ZEPHIR_CALL_METHOD(&_3$$5, &item, "isdefaultvalueavailable", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				if (zephir_array_key_exists(&args, &argsclass TSRMLS_CC)) {
					ZEPHIR_OBS_NVAR(&data);
					zephir_array_fetch(&data, &args, &argsclass, PH_NOISY, "leevel/di/container.zep", 445 TSRMLS_CC);
				} else if (zephir_is_true(&_3$$5)) {
					ZEPHIR_CALL_METHOD(&data, &item, "getdefaultvalue", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
				} else {
					ZEPHIR_CALL_METHOD(&data, this_ptr, "parseclassinstance", &_4, 0, &argsclass);
					zephir_check_call_status_or_jump(try_end_1);
				}
				required++;
				ZEPHIR_SEPARATE(&validArgs);
				zephir_increment(&validArgs);
			} else if (zephir_is_true(&_2$$4)) {
				zephir_read_property(&_5$$9, &item, SL("name"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_key_exists(&args, &_5$$9 TSRMLS_CC)) {
					ZEPHIR_OBS_NVAR(&data);
					ZEPHIR_OBS_NVAR(&_6$$9);
					zephir_read_property(&_6$$9, &item, SL("name"), PH_NOISY_CC);
					zephir_array_fetch(&data, &args, &_6$$9, PH_NOISY, "leevel/di/container.zep", 455 TSRMLS_CC);
				} else {
					ZEPHIR_CALL_METHOD(&data, &item, "getdefaultvalue", NULL, 0);
					zephir_check_call_status_or_jump(try_end_1);
				}
			} else {
				required++;
				zephir_read_property(&_7$$10, &item, SL("name"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_key_exists(&args, &_7$$10 TSRMLS_CC)) {
					ZEPHIR_OBS_NVAR(&data);
					ZEPHIR_OBS_NVAR(&_8$$11);
					zephir_read_property(&_8$$11, &item, SL("name"), PH_NOISY_CC);
					zephir_array_fetch(&data, &args, &_8$$11, PH_NOISY, "leevel/di/container.zep", 460 TSRMLS_CC);
					ZEPHIR_SEPARATE(&validArgs);
					zephir_increment(&validArgs);
				} else {
					ZEPHIR_SEPARATE(&validArgs);
					zephir_decrement(&validArgs);
					ZEPHIR_INIT_NVAR(&data);
					ZVAL_NULL(&data);
				}
			}
			ZEPHIR_OBS_NVAR(&_9$$4);
			zephir_read_property(&_9$$4, &item, SL("name"), PH_NOISY_CC);
			zephir_array_update_zval(&result, &_9$$4, &data, PH_COPY | PH_SEPARATE);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_10$$3);
			ZVAL_OBJ(&_10$$3, EG(exception));
			Z_ADDREF_P(&_10$$3);
			if (zephir_instance_of_ev(&_10$$3, zephir_get_internal_ce(SL("reflectionexception")) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_10$$3);
				ZEPHIR_INIT_NVAR(&_11$$13);
				object_init_ex(&_11$$13, spl_ce_InvalidArgumentException);
				ZEPHIR_CALL_METHOD(&_12$$13, &e, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_11$$13, "__construct", &_13, 21, &_12$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$13, "leevel/di/container.zep", 470 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	if (!(ZEPHIR_IS_EMPTY(&args))) {
		ZEPHIR_CALL_FUNCTION(&_14$$14, "array_values", NULL, 33, &result);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&result, &_14$$14);
		zephir_is_iterable(&args, 0, "leevel/di/container.zep", 483);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&args), _16$$14, _17$$14, _15$$14)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_17$$14 != NULL) { 
				ZVAL_STR_COPY(&k, _17$$14);
			} else {
				ZVAL_LONG(&k, _16$$14);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _15$$14);
			if (Z_TYPE_P(&k) == IS_LONG) {
				zephir_array_update_zval(&result, &k, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_SEPARATE(&validArgs);
				zephir_increment(&validArgs);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&k);
	}
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &result);
	ZEPHIR_INIT_VAR(&_18);
	ZVAL_LONG(&_18, required);
	zephir_array_fast_append(return_value, &_18);
	zephir_array_fast_append(return_value, &validArgs);
	RETURN_MM();

}

/**
 * 分析反射参数的类
 * 
 * @param \ReflectionParameter $param
 * @return boolean|string
 */
PHP_METHOD(Leevel_Di_Container, parseParameterClass) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *param, param_sub, classObject;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&param_sub);
	ZVAL_UNDEF(&classObject);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &param);



	ZEPHIR_CALL_METHOD(&classObject, param, "getclass", NULL, 0);
	zephir_check_call_status();
	_0 = !zephir_is_true(&classObject);
	if (!(_0)) {
		_1 = Z_TYPE_P(&classObject) == IS_OBJECT;
		if (_1) {
			_1 = zephir_instance_of_ev(&classObject, zephir_get_internal_ce(SL("reflectionclass")) TSRMLS_CC);
		}
		_0 = !(_1);
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(&classObject, "getname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 解析反射参数类实例
 * 
 * @param string $argsclass
 * @return array
 */
PHP_METHOD(Leevel_Di_Container, parseClassInstance) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argsclass_param = NULL, result, _0, _1, _2;
	zval argsclass;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argsclass);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argsclass_param);

	zephir_get_strval(&argsclass, argsclass_param);


	ZEPHIR_CALL_METHOD(&result, this_ptr, "parseclassfromcontainer", NULL, 0, &argsclass);
	zephir_check_call_status();
	if (zephir_is_true(&result)) {
		RETURN_CCTOR(&result);
	}
	ZEPHIR_CALL_METHOD(&result, this_ptr, "parseclassnotexists", NULL, 0, &argsclass);
	zephir_check_call_status();
	if (zephir_is_true(&result)) {
		RETURN_CCTOR(&result);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, spl_ce_InvalidArgumentException);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Class or interface %s is not register in container");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 1, &_1, &argsclass);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 21, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "leevel/di/container.zep", 531 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 从服务容器中获取解析反射参数类实例
 * 
 * @param string $argsclass
 * @return boolean|object
 */
PHP_METHOD(Leevel_Di_Container, parseClassFromContainer) {

	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argsclass_param = NULL, itemMake, result, _5, _6, _7, _1$$6, _2$$6, _3$$6;
	zval argsclass;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argsclass);
	ZVAL_UNDEF(&itemMake);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argsclass_param);

	zephir_get_strval(&argsclass, argsclass_param);


	ZEPHIR_CALL_METHOD(&itemMake, this_ptr, "make", &_0, 0, &argsclass);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&itemMake)) {
		RETURN_MM_BOOL(0);
	}
	if (Z_TYPE_P(&itemMake) == IS_OBJECT) {
		RETURN_CCTOR(&itemMake);
	}
	if (zephir_class_exists(&itemMake, 1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&result, this_ptr, "make", &_0, 0, &itemMake);
		zephir_check_call_status();
		if (Z_TYPE_P(&result) != IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_1$$6);
			object_init_ex(&_1$$6, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_2$$6);
			ZVAL_STRING(&_2$$6, "Class or interface %s is register in container is not object.");
			ZEPHIR_CALL_FUNCTION(&_3$$6, "sprintf", &_4, 1, &_2$$6, &argsclass);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_1$$6, "__construct", NULL, 21, &_3$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$6, "leevel/di/container.zep", 558 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&result);
	}
	ZEPHIR_INIT_VAR(&_5);
	object_init_ex(&_5, spl_ce_InvalidArgumentException);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "Class or interface %s is not register in container");
	ZEPHIR_CALL_FUNCTION(&_7, "sprintf", &_4, 1, &_6, &argsclass);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 21, &_7);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_5, "leevel/di/container.zep", 564 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 独立类作为解析反射参数类实例
 * 
 * @param string $argsclass
 * @return boolean|object
 */
PHP_METHOD(Leevel_Di_Container, parseClassNotExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argsclass_param = NULL, result, _0$$4, _1$$4, _2$$4;
	zval argsclass;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argsclass);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argsclass_param);

	zephir_get_strval(&argsclass, argsclass_param);


	if (!(zephir_class_exists(&argsclass, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&result, this_ptr, "make", NULL, 0, &argsclass);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$4);
		object_init_ex(&_0$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "Class or interface %s is register in container is not object.");
		ZEPHIR_CALL_FUNCTION(&_2$$4, "sprintf", NULL, 1, &_1$$4, &argsclass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 21, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "leevel/di/container.zep", 583 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&result);

}

/**
 * 不同的类型不同的反射
 * 
 * @param mixed $injection
 * @return array
 */
PHP_METHOD(Leevel_Di_Container, parseReflection) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *injection, injection_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&injection_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &injection);



	_0 = Z_TYPE_P(injection) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(injection, zend_ce_closure TSRMLS_CC);
	}
	_1 = Z_TYPE_P(injection) != IS_STRING;
	if (_1) {
		_1 = zephir_is_callable(injection TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseclosurereflection", NULL, 0, injection);
		zephir_check_call_status();
		RETURN_MM();
	} else if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsemethodreflection", NULL, 0, injection);
		zephir_check_call_status();
		RETURN_MM();
	} else if (Z_TYPE_P(injection) == IS_STRING) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseclassreflection", NULL, 0, injection);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Unsupported callback types.", "leevel/di/container.zep", 605);
	return;

}

/**
 * 解析闭包反射参数
 * 
 * @param Closure $injection
 * @return array
 */
PHP_METHOD(Leevel_Di_Container, parseClosureReflection) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *injection, injection_sub, reflection, param;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&injection_sub);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&param);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &injection);



	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 34, injection);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&param, &reflection, "getparameters", NULL, 35);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&param)) {
		ZEPHIR_INIT_NVAR(&param);
		array_init(&param);
	}
	RETURN_CCTOR(&param);

}

/**
 * 解析数组回调反射参数
 * 
 * @param array&callback $injection
 * @return array
 */
PHP_METHOD(Leevel_Di_Container, parseMethodReflection) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *injection, injection_sub, reflection, param, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&injection_sub);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &injection);



	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionmethod")));
	zephir_array_fetch_long(&_0, injection, 0, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 637 TSRMLS_CC);
	zephir_array_fetch_long(&_1, injection, 1, PH_NOISY | PH_READONLY, "leevel/di/container.zep", 637 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 36, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&param, &reflection, "getparameters", NULL, 37);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&param)) {
		ZEPHIR_INIT_NVAR(&param);
		array_init(&param);
	}
	RETURN_CCTOR(&param);

}

/**
 * 解析类反射参数
 * 
 * @param string $injection
 * @return array
 */
PHP_METHOD(Leevel_Di_Container, parseClassReflection) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *injection_param = NULL, reflection, constructor, param, _0, _1$$3, _2$$3, _3$$3;
	zval injection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&injection);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&constructor);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &injection_param);

	zephir_get_strval(&injection, injection_param);


	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 38, &injection);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &reflection, "isinstantiable", NULL, 39);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Class %s is not instantiable.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, &injection);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 21, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "leevel/di/container.zep", 659 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&constructor, &reflection, "getconstructor", NULL, 40);
	zephir_check_call_status();
	if (zephir_is_true(&constructor)) {
		ZEPHIR_CALL_METHOD(&param, &constructor, "getparameters", NULL, 0);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(&param))) {
		ZEPHIR_INIT_NVAR(&param);
		array_init(&param);
	}
	RETURN_CCTOR(&param);

}

/**
 * 动态创建实例对象
 *
 * @param string $classname
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Di_Container, newInstanceArgs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classname, classname_sub, *args, args_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classname_sub);
	ZVAL_UNDEF(&args_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &classname, &args);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 38, classname);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "newinstanceargs", NULL, 41, args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 解析注册容器对象别名
 *
 * @param array $name
 * @return array
 */
PHP_METHOD(Leevel_Di_Container, parseAlias) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_arrval(&name, name_param);


	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_0, "key", NULL, 42, &name);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_CALL_FUNCTION(&_0, "current", NULL, 43, &name);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetExists
 *
 * @param string $offset
 * @return bool
 */
PHP_METHOD(Leevel_Di_Container, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "exists", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetGet
 *
 * @param string $offset
 * @return mixed
 */
PHP_METHOD(Leevel_Di_Container, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "make", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetSet
 *
 * @param string $offset
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Di_Container, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset, &value);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "bind", NULL, 0, offset, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetUnset
 *
 * @param string $offset
 * @return void
 */
PHP_METHOD(Leevel_Di_Container, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 捕捉支持属性参数
 *
 * @param string $key
 * @return 设置项
 */
PHP_METHOD(Leevel_Di_Container, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetget", NULL, 0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置支持属性参数
 *
 * @param string $key
 * @param mixed $service
 * @return void
 */
PHP_METHOD(Leevel_Di_Container, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *service, service_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&service_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &service);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, 0, key, service);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Di_Container, __call) {

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


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Method %s is not exits.");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 1, &_1, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 2, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "leevel/di/container.zep", 779 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object *zephir_init_properties_Leevel_Di_Container(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("shareClosure"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("shareClosure"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("alias"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("alias"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("singletons"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("singletons"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("instances"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("services"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

