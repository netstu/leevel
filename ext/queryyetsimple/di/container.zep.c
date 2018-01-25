
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
 * @package $$
 * @since 2018.01.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Di_Container) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Di, Container, queryyetsimple, di_container, queryyetsimple_di_container_method_entry, 0);

	/**
	 * 注册服务
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_di_container_ce, SL("services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 注册的实例
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_di_container_ce, SL("instances"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 单一实例
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_di_container_ce, SL("singletons"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 别名支持
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_di_container_ce, SL("alias"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 分组
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_di_container_ce, SL("groups"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * share 静态变量值
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_di_container_ce, SL("shareClosure"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	queryyetsimple_di_container_ce->create_object = zephir_init_properties_Queryyetsimple_Di_Container;

	zend_class_implements(queryyetsimple_di_container_ce TSRMLS_CC, 1, queryyetsimple_di_icontainer_ce);
	zend_class_implements(queryyetsimple_di_container_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
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
PHP_METHOD(Queryyetsimple_Di_Container, bind) {

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
		ZEPHIR_CALL_FUNCTION(name, "array_shift", &_0, 4, &templist$$3);
		ZEPHIR_UNREF(&templist$$3);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&templist$$3);
		ZEPHIR_CALL_FUNCTION(&alias, "array_shift", &_0, 4, &templist$$3);
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
PHP_METHOD(Queryyetsimple_Di_Container, instance) {

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
		ZEPHIR_CALL_FUNCTION(name, "array_shift", &_0, 4, &templist$$3);
		ZEPHIR_UNREF(&templist$$3);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&templist$$3);
		ZEPHIR_CALL_FUNCTION(&alias, "array_shift", &_0, 4, &templist$$3);
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
PHP_METHOD(Queryyetsimple_Di_Container, singleton) {

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
PHP_METHOD(Queryyetsimple_Di_Container, share) {

	zval _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *closures, closures_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&closures_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &closures);



	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, queryyetsimple_5__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, closures);
	ZEPHIR_RETURN_CALL_CE_STATIC(queryyetsimple_support_closureuse_ce, "make", &_0, 0, &_1, &_2);
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
PHP_METHOD(Queryyetsimple_Di_Container, alias) {

	zval _4$$6;
	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias, alias_sub, *value = NULL, value_sub, __$null, key, item, *_0$$3, *_5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias, &value);

	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	if (Z_TYPE_P(alias) == IS_ARRAY) {
		zephir_is_iterable(alias, 0, "queryyetsimple/di/container.zep", 201);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", &_3, 23, &key, &item);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		zephir_get_arrval(&_4$$6, value);
		ZEPHIR_CPY_WRT(value, &_4$$6);
		zephir_is_iterable(value, 0, "queryyetsimple/di/container.zep", 206);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(value), _5$$6)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _5$$6);
			zephir_update_property_array(this_ptr, SL("alias"), &item, alias TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
	}
	RETURN_THIS();

}

/**
 * 分组注册
 *
 * @param string $group
 * @param mixed $data
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Di_Container, group) {

	zval *group, group_sub, *data, data_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &group, &data);



	zephir_read_property(&_0, this_ptr, SL("groups"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, group))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_array(this_ptr, SL("groups"), group, &_1$$3 TSRMLS_CC);
	}
	zephir_update_property_array(this_ptr, SL("groups"), group, data TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 分组制造
 *
 * @param string $group
 * @param array $args
 * @return array
 */
PHP_METHOD(Queryyetsimple_Di_Container, groupMake) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args, _3;
	zval *group, group_sub, *args_param = NULL, result, instance, item, _0, _1, _2, *_4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &group, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	zephir_read_property(&_0, this_ptr, SL("groups"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, group))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_1, this_ptr, SL("groups"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_array_fetch(&_2, &_1, group, PH_NOISY, "queryyetsimple/di/container.zep", 244 TSRMLS_CC);
	zephir_get_arrval(&_3, &_2);
	ZEPHIR_CPY_WRT(&instance, &_3);
	zephir_is_iterable(&instance, 0, "queryyetsimple/di/container.zep", 249);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&instance), _4)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _4);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "make", &_6, 0, &item, &args);
		zephir_check_call_status();
		zephir_array_update_zval(&result, &item, &_5$$4, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&result);

}

/**
 * 服务容器返回对象
 *
 * @param string $name
 * @param array $args
 * @return object|false
 */
PHP_METHOD(Queryyetsimple_Di_Container, make) {

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
		zephir_array_fetch(&_3$$3, &_2$$3, name, PH_NOISY | PH_READONLY, "queryyetsimple/di/container.zep", 268 TSRMLS_CC);
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
	zephir_array_fetch(&_7, &_6, name, PH_NOISY, "queryyetsimple/di/container.zep", 276 TSRMLS_CC);
	_8 = Z_TYPE_P(&_7) != IS_STRING;
	if (_8) {
		zephir_read_property(&_9, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_10, &_9, name, PH_NOISY | PH_READONLY, "queryyetsimple/di/container.zep", 276 TSRMLS_CC);
		_8 = zephir_is_callable(&_10 TSRMLS_CC);
	}
	if (_8) {
		if (ZEPHIR_IS_EMPTY(&args)) {
			ZEPHIR_INIT_NVAR(&args);
			array_init(&args);
		}
		ZEPHIR_MAKE_REF(&args);
		ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 24, &args, this_ptr);
		ZEPHIR_UNREF(&args);
		zephir_check_call_status();
		zephir_read_property(&_11$$5, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_12$$5, &_11$$5, name, PH_NOISY | PH_READONLY, "queryyetsimple/di/container.zep", 282 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&instance);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&instance, &_12$$5, &args);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_13$$7, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_14$$7);
		zephir_array_fetch(&_14$$7, &_13$$7, name, PH_NOISY, "queryyetsimple/di/container.zep", 284 TSRMLS_CC);
		if (Z_TYPE_P(&_14$$7) == IS_STRING) {
			zephir_read_property(&_15$$8, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_16$$8, &_15$$8, name, PH_NOISY | PH_READONLY, "queryyetsimple/di/container.zep", 285 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&instance, this_ptr, "getinjectionobject", &_5, 0, &_16$$8, &args);
			zephir_check_call_status();
		} else {
			zephir_read_property(&_17$$9, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&instance);
			zephir_array_fetch(&instance, &_17$$9, name, PH_NOISY, "queryyetsimple/di/container.zep", 287 TSRMLS_CC);
		}
	}
	zephir_read_property(&_18, this_ptr, SL("singletons"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_in_array(name, &_18 TSRMLS_CC)) {
		zephir_update_property_array(this_ptr, SL("instances"), name, &instance TSRMLS_CC);
		zephir_read_property(&_19$$10, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_20$$10, &_19$$10, name, PH_NOISY | PH_READONLY, "queryyetsimple/di/container.zep", 294 TSRMLS_CC);
		RETURN_CTOR(&_20$$10);
	} else {
		RETURN_CCTOR(&instance);
	}

}

/**
 * 实例回调自动注入
 *
 * @param callable $callback
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Di_Container, call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *callback, callback_sub, *args_param = NULL, temp;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &callback, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	ZEPHIR_INIT_VAR(&temp);
	array_init(&temp);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_CALL_METHOD(&temp, this_ptr, "parseinjection", NULL, 0, callback);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&temp, &args);
	}
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, callback, &temp);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 统一去掉前面的斜杠
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Di_Container, normalize) {

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
PHP_METHOD(Queryyetsimple_Di_Container, getAlias) {

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
		zephir_array_fetch(&_0, &_2, name, PH_NOISY, "queryyetsimple/di/container.zep", 342 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Di_Container, getInjectionObject) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *classname, classname_sub, *args_param = NULL, temp;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classname_sub);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &classname, &args_param);

	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	ZEPHIR_INIT_VAR(&temp);
	array_init(&temp);
	if (!(zephir_class_exists(classname, 1 TSRMLS_CC))) {
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_CALL_METHOD(&temp, this_ptr, "parseinjection", NULL, 0, classname);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&temp, &args);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstanceargs", NULL, 0, classname, &temp);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 分析自动依赖注入
 *
 * @param mixed $injection
 * @return array
 */
PHP_METHOD(Queryyetsimple_Di_Container, parseInjection) {

	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *injection, injection_sub, result, param, item, argsclass, data, e, *_0, _2$$4, _4$$4, _5$$3, _6$$8, _7$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&injection_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&argsclass);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &injection);



	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_CALL_METHOD(&param, this_ptr, "parsereflection", NULL, 0, injection);
	zephir_check_call_status();
	zephir_is_iterable(&param, 0, "queryyetsimple/di/container.zep", 401);
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
				ZEPHIR_CALL_METHOD(&data, this_ptr, "parseclassinstance", &_3, 0, &argsclass);
				zephir_check_call_status_or_jump(try_end_1);
			} else if (zephir_is_true(&_2$$4)) {
				ZEPHIR_CALL_METHOD(&data, this_ptr, "parseclassinstance", &_3, 0, &argsclass);
				zephir_check_call_status_or_jump(try_end_1);
			} else {
				ZEPHIR_INIT_NVAR(&data);
				ZVAL_NULL(&data);
			}
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_read_property(&_4$$4, &item, SL("name"), PH_NOISY_CC);
			zephir_array_update_zval(&result, &_4$$4, &data, PH_COPY | PH_SEPARATE);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_OBJ(&_5$$3, EG(exception));
			Z_ADDREF_P(&_5$$3);
			if (zephir_instance_of_ev(&_5$$3, zephir_get_internal_ce(SL("reflectionexception")) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_5$$3);
				ZEPHIR_INIT_NVAR(&_6$$8);
				object_init_ex(&_6$$8, spl_ce_InvalidArgumentException);
				ZEPHIR_CALL_METHOD(&_7$$8, &e, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_6$$8, "__construct", &_8, 17, &_7$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$8, "queryyetsimple/di/container.zep", 397 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&result);

}

/**
 * 分析反射参数的类
 * 
 * @param \ReflectionParameter $param
 * @return boolean|string
 */
PHP_METHOD(Queryyetsimple_Di_Container, parseParameterClass) {

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
PHP_METHOD(Queryyetsimple_Di_Container, parseClassInstance) {

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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 17, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "queryyetsimple/di/container.zep", 442 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 从服务容器中获取解析反射参数类实例
 * 
 * @param string $argsclass
 * @return boolean|object
 */
PHP_METHOD(Queryyetsimple_Di_Container, parseClassFromContainer) {

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
			ZEPHIR_CALL_METHOD(NULL, &_1$$6, "__construct", NULL, 17, &_3$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$6, "queryyetsimple/di/container.zep", 469 TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 17, &_7);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_5, "queryyetsimple/di/container.zep", 475 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 独立类作为解析反射参数类实例
 * 
 * @param string $argsclass
 * @return boolean|object
 */
PHP_METHOD(Queryyetsimple_Di_Container, parseClassNotExists) {

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
		ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 17, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$4, "queryyetsimple/di/container.zep", 494 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Di_Container, parseReflection) {

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
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Unsupported callback types.", "queryyetsimple/di/container.zep", 516);
	return;

}

/**
 * 解析闭包反射参数
 * 
 * @param Closure $injection
 * @return array
 */
PHP_METHOD(Queryyetsimple_Di_Container, parseClosureReflection) {

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
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 25, injection);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&param, &reflection, "getparameters", NULL, 26);
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
PHP_METHOD(Queryyetsimple_Di_Container, parseMethodReflection) {

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
	zephir_array_fetch_long(&_0, injection, 0, PH_NOISY | PH_READONLY, "queryyetsimple/di/container.zep", 548 TSRMLS_CC);
	zephir_array_fetch_long(&_1, injection, 1, PH_NOISY | PH_READONLY, "queryyetsimple/di/container.zep", 548 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 27, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&param, &reflection, "getparameters", NULL, 28);
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
PHP_METHOD(Queryyetsimple_Di_Container, parseClassReflection) {

	zend_bool _4;
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
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 29, &injection);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &reflection, "isinstantiable", NULL, 30);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Class %s is not instantiable.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, &injection);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 17, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "queryyetsimple/di/container.zep", 569 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&constructor, &reflection, "getconstructor", NULL, 31);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&param, &constructor, "getparameters", NULL, 0);
	zephir_check_call_status();
	_4 = zephir_is_true(&constructor);
	if (_4) {
		_4 = !zephir_is_true(&param);
	}
	if (_4) {
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
PHP_METHOD(Queryyetsimple_Di_Container, newInstanceArgs) {

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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 29, classname);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "newinstanceargs", NULL, 32, args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 解析注册容器对象别名
 *
 * @param array $name
 * @return array
 */
PHP_METHOD(Queryyetsimple_Di_Container, parseAlias) {

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
	ZEPHIR_CALL_FUNCTION(&_0, "key", NULL, 33, &name);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_CALL_FUNCTION(&_0, "current", NULL, 34, &name);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * 判断容器对象是否存在
 *
 * @param string $name
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Di_Container, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "normalize", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(&_0, &_1));

}

/**
 * 获取一个容器对象
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Di_Container, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "make", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 注册容器对象
 *
 * @param string $name
 * @param mixed $service
 * @return void
 */
PHP_METHOD(Queryyetsimple_Di_Container, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *service, service_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&service_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &service);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "bind", NULL, 0, name, service);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除一个容器对象
 *
 * @param string $name
 * @return void
 */
PHP_METHOD(Queryyetsimple_Di_Container, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, prop, item, _0, _1, *_2, _3$$3, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&prop);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);

	ZEPHIR_SEPARATE_PARAM(name);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalize", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(name, &_0);
	ZEPHIR_INIT_VAR(&prop);
	zephir_create_array(&prop, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "services");
	zephir_array_fast_append(&prop, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "instances");
	zephir_array_fast_append(&prop, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "singletons");
	zephir_array_fast_append(&prop, &_1);
	zephir_is_iterable(&prop, 0, "queryyetsimple/di/container.zep", 664);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&prop), _2)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _2);
		ZEPHIR_OBS_NVAR(&_3$$3);
		zephir_read_property_zval(&_3$$3, this_ptr, &item, PH_NOISY_CC);
		if (zephir_array_isset(&_3$$3, name)) {
			ZEPHIR_OBS_NVAR(&_4$$4);
			zephir_read_property_zval(&_4$$4, this_ptr, &item, PH_NOISY_CC);
			zephir_array_unset(&_4$$4, name, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 捕捉支持属性参数
 *
 * @param string $name 支持的项
 * @return 设置项
 */
PHP_METHOD(Queryyetsimple_Di_Container, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetget", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置支持属性参数
 *
 * @param string $name 支持的项
 * @param mixed $service 支持的值
 * @return void
 */
PHP_METHOD(Queryyetsimple_Di_Container, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *service, service_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&service_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &service);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, 0, name, service);
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
PHP_METHOD(Queryyetsimple_Di_Container, __call) {

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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "queryyetsimple/di/container.zep", 699 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

zend_object *zephir_init_properties_Queryyetsimple_Di_Container(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property(&_0, this_ptr, SL("groups"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("groups"), &_1$$3);
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

void zephir_init_static_properties_Queryyetsimple_Di_Container(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(queryyetsimple_di_container_ce, ZEND_STRL("shareClosure"), &_0);
	ZEPHIR_MM_RESTORE();

}

