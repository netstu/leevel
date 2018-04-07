
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * Session 中间件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.11.14
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Session_Middleware_Session) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Session\\Middleware, Session, leevel, session_middleware_session, leevel_session_middleware_session_method_entry, 0);

	/**
	 * session 管理
	 *
	 * @var \Leevel\Session\Manager
	 */
	zend_declare_property_null(leevel_session_middleware_session_ce, SL("manager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Leevel\Session\Manager $manager
 * @return void
 */
PHP_METHOD(Leevel_Session_Middleware_Session, __construct) {

	zval *manager, manager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);

	zephir_fetch_params(0, 1, 0, &manager);



	zephir_update_property_zval(this_ptr, SL("manager"), manager);

}

/**
 * 请求
 *
 * @param \Closure $next
 * @param \Leevel\Http\Request $request
 * @return void
 */
PHP_METHOD(Leevel_Session_Middleware_Session, handle) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *next, next_sub, *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&next_sub);
	ZVAL_UNDEF(&request_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &next, &request);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "startsession", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_ZVAL_FUNCTION(NULL, next, NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 响应
 *
 * @param \Closure $next
 * @param \Leevel\Http\Request $request
 * @param \Leevel\Http\Response $response
 * @return void
 */
PHP_METHOD(Leevel_Session_Middleware_Session, terminate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *next, next_sub, *request, request_sub, *response, response_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&next_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &next, &request, &response);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "unregisterflash", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprevurl", NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_CALL_ZVAL_FUNCTION(NULL, next, NULL, 0, request, response);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 启动 session
 *
 * @return void
 */
PHP_METHOD(Leevel_Session_Middleware_Session, startSession) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清理闪存
 *
 * @return void
 */
PHP_METHOD(Leevel_Session_Middleware_Session, unregisterFlash) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "unregisterflash", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 保存当期请求 URL
 *
 * @param \Leevel\Http\Request $request
 * @return void
 */
PHP_METHOD(Leevel_Session_Middleware_Session, setPrevUrl) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	zephir_read_property(&_0, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "setprevurl", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

