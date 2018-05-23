
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * 路由 pathInfo 匹配
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.02.15
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_Match_PathInfo) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Router\\Match, PathInfo, leevel, router_match_pathinfo, leevel_router_match_pathinfo_method_entry, 0);

	/**
	 * Router
	 * 
	 * @var \Leevel\Router\Router
	 */
	zend_declare_property_null(leevel_router_match_pathinfo_ce, SL("router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/** 
	 * HTTP Request
	 * 
	 * @var \Leevel\Http\Request
	 */
	zend_declare_property_null(leevel_router_match_pathinfo_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(leevel_router_match_pathinfo_ce TSRMLS_CC, 1, leevel_router_match_imatch_ce);
	return SUCCESS;

}

/**
 * 匹配数据项
 *
 * @param \Leevel\Router\Router $router
 * @param \Leevel\Http\Request $request
 * @return array
 */
PHP_METHOD(Leevel_Router_Match_PathInfo, matche) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *router, router_sub, *request, request_sub, pathInfo, tmp, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&pathInfo);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &router, &request);



	ZEPHIR_CALL_METHOD(&pathInfo, request, "getpathinfo", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &pathInfo, &_1, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(&pathInfo, &_0);
	if (!(zephir_is_true(&pathInfo))) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&tmp, SL("_c"), SL("home"));
		add_assoc_stringl_ex(&tmp, SL("_a"), SL("handle"));
		RETURN_CCTOR(&tmp);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "/", &pathInfo);
	ZEPHIR_CPY_WRT(&pathInfo, &_2);
	ZEPHIR_RETURN_CALL_METHOD(router, "matchepath", NULL, 0, &pathInfo);
	zephir_check_call_status();
	RETURN_MM();

}

