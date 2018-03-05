
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
 * router 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.28
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Router_Provider_Register) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Router\\Provider, Register, queryyetsimple, router_provider_register, queryyetsimple_di_provider_ce, queryyetsimple_router_provider_register_method_entry, 0);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Queryyetsimple\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Queryyetsimple_Router_Provider_Register, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_CALL_PARENT(NULL, queryyetsimple_router_provider_register_ce, getThis(), "__construct", &_0, 0, container);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Router_Provider_Register, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "url", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "request", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "response", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Router_Provider_Register, providers) {

	zval _0;
	zval tmp, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\Router\\Router");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\Router\\Router");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("router"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\Router\\Url");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\Router\\Url");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("url"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\Router\\Redirect");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\Router\\Redirect");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("redirect"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\Http\\Request");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\Http\\Request");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("request"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\Router\\IResponseFactory");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\Router\\ResponseFactory");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\Router\\IResponseFactory");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\Router\\ResponseFactory");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("response"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&tmp);

}

/**
 * 注册 router 服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Router_Provider_Register, router) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_24__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "router");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 url 服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Router_Provider_Register, url) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_25__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "url");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 redirect 服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Router_Provider_Register, redirect) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_create_closure_ex(&_1, NULL, queryyetsimple_26__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "share", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "redirect");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "bind", NULL, 0, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 request 服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Router_Provider_Register, request) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_27__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 response 服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Router_Provider_Register, response) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_28__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "response");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

