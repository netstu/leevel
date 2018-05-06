
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
 * @package $$
 * @since 2017.06.03
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_Provider_Register) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Cache\\Provider, Register, leevel, cache_provider_register, leevel_di_provider_ce, leevel_cache_provider_register_method_entry, 0);

	/**
	 * 是否延迟载入
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(leevel_cache_provider_register_ce, SL("defer"), 1, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

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

	zval _0;
	zval tem, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tem);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tem);
	zephir_create_array(&tem, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Cache\\Manager");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tem, SL("caches"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Cache\\Cache");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Cache\\ICache");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tem, SL("cache"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Cache\\Load");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tem, SL("cache.load"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&tem);

}

/**
 * 注册 caches 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Cache_Provider_Register, caches) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, leevel_3__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "caches");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 cache 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Cache_Provider_Register, cache) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, leevel_4__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "cache");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 cache.load 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Cache_Provider_Register, cacheLoad) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, leevel_5__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "cache.load");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

