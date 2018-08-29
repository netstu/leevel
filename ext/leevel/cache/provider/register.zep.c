
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * cache 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.06.03
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_Provider_Register) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Cache\\Provider, Register, leevel, cache_provider_register, leevel_di_provider_ce, leevel_cache_provider_register_method_entry, 0);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Cache_Provider_Register, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_CALL_PARENT(NULL, leevel_cache_provider_register_ce, getThis(), "__construct", &_0, 0, container);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Cache_Provider_Register, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "caches", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cache", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cacheload", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Leevel_Cache_Provider_Register, providers) {

	zval _1;
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Cache\\Manager");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(return_value, SL("caches"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Cache\\Cache");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Cache\\ICache");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(return_value, SL("cache"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Cache\\Load");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(return_value, SL("cache.load"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Cache_Provider_Register, isDeferred) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * 注册 caches 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Cache_Provider_Register, caches) {

	zval _3;
	zend_class_entry *_2;
	zval _0, _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "cachesClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "caches");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 auths 闭包
 * 
 * @param \Leevel\Project\IProject $project
 * @return \Leevel\Cache\Manager
 */
PHP_METHOD(Leevel_Cache_Provider_Register, cachesClosure) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\Cache\\Manager"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, project);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 注册 cache 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Cache_Provider_Register, cache) {

	zval _3;
	zend_class_entry *_2;
	zval _0, _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "cacheClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cache");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 cache 闭包
 * 
 * @param \Leevel\Project\IProject $project
 * @return object
 */
PHP_METHOD(Leevel_Cache_Provider_Register, cacheClosure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "caches");
	ZEPHIR_CALL_METHOD(&_0, project, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "connect", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 注册 cache.load 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Cache_Provider_Register, cacheLoad) {

	zval _3;
	zend_class_entry *_2;
	zval _0, _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "cacheLoadClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "cache.load");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 cache.load 闭包
 * 
 * @param \Leevel\Project\IProject $project
 * @return \Leevel\Cache\Load
 */
PHP_METHOD(Leevel_Cache_Provider_Register, cacheLoadClosure) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\Cache\\Load"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "cache");
		ZEPHIR_CALL_METHOD(&_1, project, "make", NULL, 0, &_2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, project, &_1);
		zephir_check_call_status();
	}
	RETURN_MM();

}

