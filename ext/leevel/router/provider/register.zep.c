
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
ZEPHIR_INIT_CLASS(Leevel_Router_Provider_Register) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Router\\Provider, Register, leevel, router_provider_register, leevel_di_provider_ce, leevel_router_provider_register_method_entry, 0);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Router_Provider_Register, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_CALL_PARENT(NULL, leevel_router_provider_register_ce, getThis(), "__construct", &_0, 0, container);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Provider_Register, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "router", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "url", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "redirect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "response", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cookieresolver", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Provider_Register, providers) {

	zval _0;
	zval tmp, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Router\\Router");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("router"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Router\\Url");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("url"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Router\\Redirect");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("redirect"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Router\\IResponseFactory");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Router\\ResponseFactory");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("response"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&tmp);

}

/**
 * 注册 router 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Provider_Register, router) {

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
	zephir_create_closure_ex(&_1, NULL, leevel_20__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "router");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 url 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Provider_Register, url) {

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
	zephir_create_closure_ex(&_1, NULL, leevel_21__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "url");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 redirect 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Provider_Register, redirect) {

	zval _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_create_closure_ex(&_3, NULL, leevel_22__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_METHOD(&_2, &_1, "share", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "redirect");
	ZEPHIR_CALL_METHOD(NULL, &_0, "bind", NULL, 0, &_4, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 response 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Provider_Register, response) {

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
	zephir_create_closure_ex(&_1, NULL, leevel_23__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "response");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置 COOKIE Resolver
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Provider_Register, cookieResolver) {

	zval _3;
	zend_class_entry *_2;
	zval _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "makeCookieResolverClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(NULL, leevel_http_response_ce, "setcookieresolver", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 生成 COOKIE
 *
 * @return \Leevel\Cookie\ICookie
 */
PHP_METHOD(Leevel_Router_Provider_Register, makeCookieResolverClosure) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cookie");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "make", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

