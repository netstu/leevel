
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Redirect 响应请求
 * This class borrows heavily from the Symfony2 Framework and is part of the symfony package
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.06
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Http_RedirectResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Http, RedirectResponse, queryyetsimple, http_redirectresponse, queryyetsimple_http_response_ce, queryyetsimple_http_redirectresponse_method_entry, 0);

	/**
	 * 目标 URL 地址
	 * 
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_redirectresponse_ce, SL("targetUrl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * HTTP 请求
	 *
	 * @var \Queryyetsimple\Http\IRequest
	 */
	zend_declare_property_null(queryyetsimple_http_redirectresponse_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * SESSION 仓储
	 *
	 * @var \Queryyetsimple\Session\ISession
	 */
	zend_declare_property_null(queryyetsimple_http_redirectresponse_ce, SL("session"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param string $url
 * @param int $status
 * @param array $headers
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, __construct) {

	zend_bool _8;
	zephir_fcall_cache_entry *_0 = NULL;
	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *status_param = NULL, *headers_param = NULL, _1, _2, _3, _4$$3, _5$$3, _6$$3, _7$$3, _9$$4, _10$$4;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &url_param, &status_param, &headers_param);

	if (UNEXPECTED(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(&url, url_param);
	} else {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_EMPTY_STRING(&url);
	}
	if (!status_param) {
		status = 302;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZVAL_LONG(&_2, status);
	ZEPHIR_CALL_PARENT(NULL, queryyetsimple_http_redirectresponse_ce, getThis(), "__construct", &_0, 0, &_1, &_2, &headers);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "settargeturl", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "isredirect", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "The HTTP status code is not a redirect (%s given).");
		ZVAL_LONG(&_6$$3, status);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "sprintf", NULL, 1, &_5$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 21, &_7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "queryyetsimple/http/redirectresponse.zep", 73 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_8 = 301 == status;
	if (_8) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "cache-control");
		_8 = !(zephir_array_key_exists(&headers, &_1 TSRMLS_CC));
	}
	if (_8) {
		zephir_read_property(&_9$$4, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "cache-control");
		ZEPHIR_CALL_METHOD(NULL, &_9$$4, "remove", NULL, 0, &_10$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 URL 跳转响应
 *
 * @param string $url
 * @param int $status
 * @param array $headers
 * @return static
 */
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, create) {

	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *status_param = NULL, *headers_param = NULL, _0;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &url_param, &status_param, &headers_param);

	if (!url_param) {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_STRING(&url, "");
	} else {
		zephir_get_strval(&url, url_param);
	}
	if (!status_param) {
		status = 302;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	object_init_ex(return_value, queryyetsimple_http_redirectresponse_ce);
	ZVAL_LONG(&_0, status);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 78, &url, &_0, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 闪存一个数据片段到 SESSION
 *
 * @param string|array $key
 * @param mixed  $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, with) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *value = NULL, value_sub, __$null, k, v, tmp, *_0, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &value);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	if (Z_TYPE_P(key) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&tmp, key);
	} else {
		ZEPHIR_INIT_NVAR(&tmp);
		zephir_create_array(&tmp, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(&tmp, key, value, PH_COPY);
	}
	zephir_is_iterable(&tmp, 0, "queryyetsimple/http/redirectresponse.zep", 111);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&tmp), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&k, _2);
		} else {
			ZVAL_LONG(&k, _1);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _0);
		zephir_read_property(&_3$$3, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "flash", NULL, 0, &k, &v);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	RETURN_THIS();

}

/**
 * 获取目标 URL 地址
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, getTargetUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "targetUrl");

}

/**
 * 设置目标 URL 地址
 *
 * @param string $url
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, setTargetUrl) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, _0, _1, _2, _3, _4;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	if (ZEPHIR_IS_EMPTY(&url)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Cannot redirect to an empty URL.", "queryyetsimple/http/redirectresponse.zep", 137);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("targetUrl"), &url);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "UTF-8");
	ZEPHIR_CALL_FUNCTION(&_3, "htmlspecialchars", NULL, 79, &url, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "<!DOCTYPE html>\n<html>\n    <head>\n        <meta charset=\"UTF-8\" />\n        <meta http-equiv=\"refresh\" content=\"0;url=%1$s\" />\n        <title>Redirecting to %1$s</title>\n    </head>\n    <body>\n        Redirecting to <a href=\"%1$s\">%1$s</a>.\n    </body>\n</html>");
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcontent", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Location");
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, &url);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 获取 HTTP 请求
 *
 * @return \Queryyetsimple\Http\IRequest|null
 */
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, getRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "request");

}

/**
 * 设置 HTTP 请求
 *
 * @param \Queryyetsimple\Http\IRequest $request
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, setRequest) {

	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);

	zephir_fetch_params(0, 1, 0, &request);



	zephir_update_property_zval(this_ptr, SL("request"), request);

}

/**
 * 获取 SESSION 仓储
 *
 * @return \Queryyetsimple\Session\ISession|null
 */
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, getSession) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "session");

}

/**
 * 设置 SESSION 仓储
 *
 * @param \Queryyetsimple\Session\ISession $session
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, setSession) {

	zval *session, session_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session_sub);

	zephir_fetch_params(0, 1, 0, &session);



	zephir_update_property_zval(this_ptr, SL("session"), session);

}

