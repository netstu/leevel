
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "ext/date/php_date.h"
#include "Zend/zend_closures.h"
#include "ext/spl/spl_array.h"


/**
 * HTTP 响应
 * This class borrows heavily from the Symfony2 Framework and is part of the symfony package
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.05
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Http_Response) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Http, Response, queryyetsimple, http_response, queryyetsimple_http_response_method_entry, 0);

	/**
	 * 响应头
	 * 
	 * @var \Queryyetsimple\Http\ResponseHeaderBag
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("headers"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 原生响应内容
	 *
	 * @var mixed
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("original"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 响应内容
	 * 
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * HTTP 协议版本
	 * 
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("protocolVersion"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 状态码
	 * 
	 * @var int
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("statusCode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 状态码内容
	 * 
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("statusText"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 字符编码
	 * 
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("charset"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 是否为 JSON
	 * 
	 * @var boolean
	 */
	zend_declare_property_bool(queryyetsimple_http_response_ce, SL("isJson"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * COOKIE Resolver
	 * 
	 * @var \Closure
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("cookieResolver"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 状态码
	 *
	 * @see http://www.iana.org/assignments/http-status-codes/
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("statusTexts"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 注册的动态扩展
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_http_response_ce, SL("macro"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 逻辑代码是否处于条件表达式中
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(queryyetsimple_http_response_ce, SL("inFlowControl"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 条件表达式是否为真
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(queryyetsimple_http_response_ce, SL("isFlowControlTrue"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(queryyetsimple_http_response_ce TSRMLS_CC, 1, queryyetsimple_flow_icontrol_ce);
	zend_class_implements(queryyetsimple_http_response_ce TSRMLS_CC, 1, queryyetsimple_support_imacro_ce);
	zend_class_implements(queryyetsimple_http_response_ce TSRMLS_CC, 1, queryyetsimple_http_iresponse_ce);
	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param string $content
 * @param integer $status
 * @param array $headers
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_Response, __construct) {

	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, *status_param = NULL, *headers_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &content, &status_param, &headers_param);

	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, queryyetsimple_http_responseheaderbag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 18, &headers);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("headers"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcontent", NULL, 0, content);
	zephir_check_call_status();
	ZVAL_LONG(&_1, status);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "1.0");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprotocolversion", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建一个响应
 * 
 * @param string $content
 * @param integer $status
 * @param array $headers
 * @return static
 */
PHP_METHOD(Queryyetsimple_Http_Response, create) {

	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, *status_param = NULL, *headers_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &content, &status_param, &headers_param);

	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	object_init_ex(return_value, queryyetsimple_http_response_ce);
	ZVAL_LONG(&_0, status);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 19, content, &_0, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置 COOKIE Resolver
 * 
 * @param \Closure $cookieResolver
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_Response, setCookieResolver) {

	zval *cookieResolver, cookieResolver_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookieResolver_sub);

	zephir_fetch_params(0, 1, 0, &cookieResolver);



	zend_update_static_property(queryyetsimple_http_response_ce, ZEND_STRL("cookieResolver"), cookieResolver);

}

/**
 * 发送 HTTP 响应
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, send) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sendcontent", NULL, 0);
	zephir_check_call_status();
	if ((zephir_function_exists_ex(SL("fastcgi_finish_request") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(NULL, "fastcgi_finish_request", NULL, 20);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 发送响应头
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, sendHeaders) {

	zend_string *_6;
	zend_ulong _5;
	zephir_fcall_cache_entry *_9 = NULL;
	zval __$false, __$true, name, value, _0, _1, _2, _3, *_4, _10, _11, _12, _13, _14, _15, _7$$5, _8$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "headers_sent", NULL, 21);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_THIS();
	}
	zephir_read_property(&_2, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "all", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "queryyetsimple/http/response.zep", 281);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&name, _6);
		} else {
			ZVAL_LONG(&name, _5);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _4);
		ZEPHIR_INIT_LNVAR(_7$$5);
		ZEPHIR_CONCAT_VSV(&_7$$5, &name, ": ", &value);
		zephir_read_property(&_8$$5, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 22, &_7$$5, &__$false, &_8$$5);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	zephir_read_property(&_10, this_ptr, SL("protocolVersion"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_12, this_ptr, SL("statusText"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "HTTP/%s %s %s");
	ZEPHIR_CALL_FUNCTION(&_14, "sprintf", NULL, 1, &_13, &_10, &_11, &_12);
	zephir_check_call_status();
	zephir_read_property(&_15, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_9, 22, &_14, &__$true, &_15);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 发送响应内容
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, sendContent) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_read_property(&_1, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
	zend_print_zval(&_1, 0);
	RETURN_THIS();

}

/**
 * 设置内容
 *
 * @param mixed $content
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setContent) {

	zval _12;
	zend_bool _6, _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, __$true, __$false, tmp, _0, _1, _5, _2$$4, _3$$4, _4$$4, _8$$5, _9$$5, _10$$5, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);

	ZEPHIR_SEPARATE_PARAM(content);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_update_property_zval(this_ptr, SL("original"), content);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "contentshouldjson", NULL, 0, content);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Content-Type");
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "application/json");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_2$$4, &_3$$4);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, SL("isJson"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("isJson"), &__$false);
		}
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "contenttojson", NULL, 0, content);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(content, &_4$$4);
	}
	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&tmp, content);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "__toString");
	zephir_array_fast_append(&tmp, &_5);
	_6 = Z_TYPE_P(content) != IS_NULL;
	if (_6) {
		_6 = !(zephir_is_scalar(content));
	}
	_7 = _6;
	if (_7) {
		_7 = !((zephir_is_callable(&tmp TSRMLS_CC)));
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_8$$5);
		object_init_ex(&_8$$5, spl_ce_UnexpectedValueException);
		ZEPHIR_INIT_VAR(&_9$$5);
		zephir_gettype(&_9$$5, content TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "The Response content must be a scalar or object implementing __toString(), %s given.");
		ZEPHIR_CALL_FUNCTION(&_11$$5, "sprintf", NULL, 1, &_10$$5, &_9$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 23, &_11$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$5, "queryyetsimple/http/response.zep", 332 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&_12, content);
	zephir_update_property_zval(this_ptr, SL("content"), &_12);
	RETURN_THIS();

}

/**
 * 附加内容
 *
 * @param string $content
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, appendContent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content_param = NULL, _0, _1, _2;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &content_param);

	if (!content_param) {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_STRING(&content, "");
	} else {
		zephir_get_strval(&content, content_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_1, &content);
	zephir_update_property_zval(this_ptr, SL("content"), &_2);
	RETURN_THIS();

}

/**
 * 设置响应头
 *
 * @param string $key
 * @param string $value
 * @param bool $replace
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool replace, _1;
	zval *key_param = NULL, *value_param = NULL, *replace_param = NULL, _0, _2, _3, _4$$4;
	zval key, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value_param, &replace_param);

	zephir_get_strval(&key, key_param);
	zephir_get_strval(&value, value_param);
	if (!replace_param) {
		replace = 1;
	} else {
		replace = zephir_get_boolval(replace_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	_1 = replace == 1;
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3, &_2, "has", NULL, 0, &key);
		zephir_check_call_status();
		_1 = !zephir_is_true(&_3);
	}
	if (_1) {
		zephir_read_property(&_4$$4, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "set", NULL, 0, &key, &value);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 批量设置响应头
 *
 * @param array $headers
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, withHeaders) {

	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, key, value, _0, *_1, _4$$4;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_is_iterable(&headers, 0, "queryyetsimple/http/response.zep", 396);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		zephir_read_property(&_4$$4, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "set", NULL, 0, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

/**
 * 设置 COOKIE
 *
 * @param string $name
 * @param string $value
 * @param array $option
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setCookie) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *value_param = NULL, *option_param = NULL, cookie, _0, _1, _2;
	zval name, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &value_param, &option_param);

	zephir_get_strval(&name, name_param);
	if (!value_param) {
		ZEPHIR_INIT_VAR(&value);
		ZVAL_STRING(&value, "");
	} else {
		zephir_get_strval(&value, value_param);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_read_static_property_ce(&_1, queryyetsimple_http_response_ce, SL("cookieResolver"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_1))) {
		RETURN_THIS();
	}
	zephir_read_static_property_ce(&_2, queryyetsimple_http_response_ce, SL("cookieResolver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&cookie);
	ZEPHIR_CALL_USER_FUNC(&cookie, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &cookie, "set", NULL, 0, &name, &value, &option);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 批量设置 COOKIE
 *
 * @param array $cookies
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, withCookies) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cookies_param = NULL, value, tmp, _0, *_1, _2$$4;
	zval cookies;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cookies_param);

	zephir_get_arrval(&cookies, cookies_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_is_iterable(&cookies, 0, "queryyetsimple/http/response.zep", 444);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&cookies), _1)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_INIT_NVAR(&tmp);
		zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&tmp, this_ptr);
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "setCookie");
		zephir_array_fast_append(&tmp, &_2$$4);
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_2$$4, &tmp, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	RETURN_THIS();

}

/**
 * 取回 JSON 数据
 *
 * @param bool $assoc
 * @param int $depth
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Response, getData) {

	zend_long depth;
	zval *assoc_param = NULL, *depth_param = NULL, _0, _1$$3, _2$$3, _3$$3;
	zend_bool assoc;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	zephir_fetch_params(0, 0, 2, &assoc_param, &depth_param);

	if (!assoc_param) {
		assoc = 1;
	} else {
		assoc = zephir_get_boolval(assoc_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}


	zephir_read_property(&_0, this_ptr, SL("isJson"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_2$$3, (assoc ? 1 : 0));
		ZVAL_LONG(&_3$$3, depth);
		zephir_json_decode(return_value, &_1$$3, zephir_get_intval(&_2$$3) );
		return;
	}
	RETURN_MEMBER(getThis(), "content");

}

/**
 * 设置 JSON 数据
 *
 * @param mixed $data
 * @param int $encodingOptions
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setData) {

	zval _15;
	zend_bool _1, _2, _3;
	zend_long encodingOptions, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *encodingOptions_param = NULL, _0, _12, _4$$5, _5$$5, _6$$6, _7$$6, _8$$7, _9$$7, _10$$8, _11$$8, _13$$9, _14$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &encodingOptions_param);

	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
	}
	if (!encodingOptions_param) {
		encodingOptions = 0;
	} else {
		encodingOptions = zephir_get_intval(encodingOptions_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_update_property_zval(this_ptr, SL("original"), data);
	if (1 == 0) {
		encodingOptions = 256;
	}
	_1 = Z_TYPE_P(data) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(data, queryyetsimple_support_iarray_ce TSRMLS_CC);
	}
	_2 = Z_TYPE_P(data) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(data, queryyetsimple_support_ijson_ce TSRMLS_CC);
	}
	_3 = Z_TYPE_P(data) == IS_OBJECT;
	if (_3) {
		_3 = zephir_is_instance_of(data, SL("JsonSerializable") TSRMLS_CC);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_4$$5, data, "toarray", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$5, encodingOptions);
		ZEPHIR_INIT_NVAR(data);
		zephir_json_encode(data, &_4$$5, zephir_get_intval(&_5$$5) );
	} else if (_2) {
		ZVAL_LONG(&_7$$6, encodingOptions);
		ZEPHIR_CALL_METHOD(&_6$$6, data, "tojson", NULL, 0, &_7$$6);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(data, &_6$$6);
	} else if (_3) {
		ZEPHIR_CALL_METHOD(&_8$$7, data, "jsonserialize", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_9$$7, encodingOptions);
		ZEPHIR_INIT_NVAR(data);
		zephir_json_encode(data, &_8$$7, zephir_get_intval(&_9$$7) );
	} else {
		ZEPHIR_INIT_VAR(&_10$$8);
		ZVAL_LONG(&_11$$8, encodingOptions);
		zephir_json_encode(&_10$$8, data, zephir_get_intval(&_11$$8) );
		ZEPHIR_CPY_WRT(data, &_10$$8);
	}
	ZEPHIR_CALL_FUNCTION(&_12, "json_last_error", NULL, 24);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_12, 0)) {
		ZEPHIR_INIT_VAR(&_13$$9);
		object_init_ex(&_13$$9, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_14$$9, "json_last_error_msg", NULL, 25);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_13$$9, "__construct", NULL, 26, &_14$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_13$$9, "queryyetsimple/http/response.zep", 493 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&_15, data);
	zephir_update_property_zval(this_ptr, SL("content"), &_15);
	RETURN_THIS();

}

/**
 * 获取内容
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Response, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

/**
 * 获取内容
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Response, content) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取原始内容
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Response, getOriginal) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "original");

}

/**
 * 设置 HTTP 协议版本 (1.0 or 1.1).
 *
 * @param string $protocolVersion
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setProtocolVersion) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *protocolVersion_param = NULL, _0;
	zval protocolVersion;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&protocolVersion);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &protocolVersion_param);

	zephir_get_strval(&protocolVersion, protocolVersion_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_update_property_zval(this_ptr, SL("protocolVersion"), &protocolVersion);
	RETURN_THIS();

}

/**
 * 获取 HTTP 协议版本
 *
 * @final
 */
PHP_METHOD(Queryyetsimple_Http_Response, getProtocolVersion) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "protocolVersion");

}

/**
 * 设置相应状态码
 * 
 * @param int $code
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setStatusCode) {

	zval *code_param = NULL, *text = NULL, text_sub, __$null, _0, _1, _2, _3$$4, _4$$4, _5$$4, _6$$4, _7$$5, _8$$5, _9$$5, _10$$6;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code_param, &text);

	code = zephir_get_intval(code_param);
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, code);
	zephir_update_property_zval(this_ptr, SL("statusCode"), &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "isinvalid", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "The HTTP status code %s is not valid.");
		ZVAL_LONG(&_5$$4, code);
		ZEPHIR_CALL_FUNCTION(&_6$$4, "sprintf", NULL, 1, &_4$$4, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 26, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "queryyetsimple/http/response.zep", 574 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(text) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_read_static_property_ce(&_8$$5, queryyetsimple_http_response_ce, SL("statusTexts"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_long(&_8$$5, code)) {
			zephir_read_static_property_ce(&_9$$5, queryyetsimple_http_response_ce, SL("statusTexts"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_7$$5);
			zephir_array_fetch_long(&_7$$5, &_9$$5, code, PH_NOISY, "queryyetsimple/http/response.zep", 578 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "unknown status");
		}
		zephir_update_property_zval(this_ptr, SL("statusText"), &_7$$5);
		RETURN_THIS();
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(text)) {
		ZEPHIR_INIT_VAR(&_10$$6);
		ZEPHIR_INIT_NVAR(&_10$$6);
		ZVAL_STRING(&_10$$6, "");
		zephir_update_property_zval(this_ptr, SL("statusText"), &_10$$6);
		RETURN_THIS();
	}
	zephir_update_property_zval(this_ptr, SL("statusText"), text);
	RETURN_THIS();

}

/**
 * 获取状态码
 *
 * @return int
 */
PHP_METHOD(Queryyetsimple_Http_Response, status) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getstatuscode", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取状态码
 *
 * @final
 */
PHP_METHOD(Queryyetsimple_Http_Response, getStatusCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "statusCode");

}

/**
 * 编码设置
 *
 * @param string $charset
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, charset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *charset_param = NULL, _0;
	zval charset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &charset_param);

	zephir_get_strval(&charset, charset_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_update_property_zval(this_ptr, SL("charset"), &charset);
	RETURN_THIS();

}

/**
 * 获取编码
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Response, getrCharset) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "charset");

}

/**
 * 设置过期时间
 *
 * @param \DateTime $datetime
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setExpires) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *datetime, datetime_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&datetime_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datetime);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "normalizedatetime", NULL, 0, datetime);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Expires");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 设置最后修改时间
 *
 * @param \DateTime $datetime
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setLastModified) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *datetime, datetime_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&datetime_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datetime);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "normalizedatetime", NULL, 0, datetime);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Last-Modified");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 设置缓存
 *
 * @param int $minutes
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setCache) {

	zval _2, _4;
	zval *minutes_param = NULL, date, _0, _1, _3, _5;
	zend_long minutes, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &minutes_param);

	minutes = zephir_get_intval(minutes_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&date);
	object_init_ex(&date, php_date_get_date_ce());
	ZEPHIR_CALL_METHOD(NULL, &date, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, minutes);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "+", &_1, "minutes");
	ZEPHIR_CALL_METHOD(NULL, &date, "modify", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setexpires", NULL, 0, &date);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, (minutes * 60));
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SV(&_4, "max-age=", &_3);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Cache-Control");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_5, &_4);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 设置响应未修改
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setNotModified) {

	zval _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_read_static_property_ce(&_1, queryyetsimple_http_response_ce, SL("statusTexts"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_2, &_1, 304, PH_NOISY | PH_READONLY, "queryyetsimple/http/response.zep", 707 TSRMLS_CC);
	ZVAL_LONG(&_3, 304);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 设置响应内容类型
 *
 * @param string $contentType
 * @param string $charset
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setContentType) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *contentType_param = NULL, *charset_param = NULL, _0, _1$$4, _4$$5;
	zval contentType, charset, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &contentType_param, &charset_param);

	zephir_get_strval(&contentType, contentType_param);
	if (!charset_param) {
		ZEPHIR_INIT_VAR(&charset);
		ZVAL_STRING(&charset, "");
	} else {
		zephir_get_strval(&charset, charset_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&charset, "")) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "Content-Type");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_2, 0, &_1$$4, &contentType);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_VSV(&_3$$5, &contentType, "; charset=", &charset);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "Content-Type");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_2, 0, &_4$$5, &_3$$5);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 设置响应内容长度
 *
 * @param int $contentLength
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setContentLength) {

	zval *contentLength_param = NULL, _0, _1, _2;
	zend_long contentLength, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &contentLength_param);

	contentLength = zephir_get_intval(contentLength_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Content-Length");
	ZVAL_LONG(&_2, contentLength);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 设置自定义标识符
 *
 * @param string $etag
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setEtag) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *etag_param = NULL, _0, _1;
	zval etag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&etag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &etag_param);

	zephir_get_strval(&etag, etag_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Etag");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_1, &etag);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 响应是否为 JSON
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isJson) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isJson");

}

/**
 * 响应是否正确
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isInvalid) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_LT_LONG(&_0, 100);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_GE_LONG(&_2, 600);
	}
	RETURN_BOOL(_1);

}

/**
 * 是否为信息性响应
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isInformational) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 100);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 200);
	}
	RETURN_BOOL(_1);

}

/**
 * 是否为正确响应
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isSuccessful) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 200);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 300);
	}
	RETURN_BOOL(_1);

}

/**
 * 是否为重定向响应
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isRedirection) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 300);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 400);
	}
	RETURN_BOOL(_1);

}

/**
 * 是否为客户端错误响应
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isClientError) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 400);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 500);
	}
	RETURN_BOOL(_1);

}

/**
 * 是否为服务端错误响应
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isServerError) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_GE_LONG(&_0, 500);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LT_LONG(&_2, 600);
	}
	RETURN_BOOL(_1);

}

/**
 * 是否为正常响应
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isOk) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 200));

}

/**
 * 是否为受限响应
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isForbidden) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 403));

}

/**
 * 是否为 404 NOT FOUND
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isNotFound) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 404));

}

/**
 * 是否为表单重定向响应
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isRedirect) {

	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *location_param = NULL, tmp, _0, _1, _3, _4, _5;
	zval location;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &location_param);

	if (!location_param) {
		ZEPHIR_INIT_VAR(&location);
		ZVAL_STRING(&location, "");
	} else {
		zephir_get_strval(&location, location_param);
	}


	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 201);
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 301);
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 302);
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 303);
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 307);
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 308);
	zephir_array_fast_append(&tmp, &_0);
	zephir_read_property(&_1, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fast_in_array(&_1, &tmp TSRMLS_CC);
	if (_2) {
		ZEPHIR_INIT_VAR(&_3);
		if (ZEPHIR_IS_STRING_IDENTICAL(&location, "")) {
			ZEPHIR_INIT_NVAR(&_3);
			ZVAL_BOOL(&_3, ZEPHIR_IS_STRING_IDENTICAL(&location, ""));
		} else {
			zephir_read_property(&_4, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_NVAR(&_0);
			ZVAL_STRING(&_0, "Location");
			ZEPHIR_CALL_METHOD(&_5, &_4, "get", NULL, 0, &_0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_3);
			ZVAL_BOOL(&_3, ZEPHIR_IS_EQUAL(&location, &_5));
		}
		_2 = zephir_is_true(&_3);
	}
	RETURN_MM_BOOL(_2);

}

/**
 * 是否为空响应
 *
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, isEmpty) {

	zval tmp, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, 204);
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, 304);
	zephir_array_fast_append(&tmp, &_0);
	zephir_read_property(&_1, this_ptr, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_fast_in_array(&_1, &tmp TSRMLS_CC));

}

/**
 * 条件语句 ifs
 *
 * @param boolean $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, ifs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _0, _1;
	zend_bool value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &value_param);

	if (!value_param) {
		value = 0;
	} else {
		value = zephir_get_boolval(value_param);
	}


	ZVAL_BOOL(&_0, 1);
	if (value) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "settcontrol", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 条件语句 elseIfs
 *
 * @param boolean $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, elseIfs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _0, _1;
	zend_bool value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &value_param);

	if (!value_param) {
		value = 0;
	} else {
		value = zephir_get_boolval(value_param);
	}


	ZVAL_BOOL(&_0, 1);
	if (value) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "settcontrol", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 条件语句 elses
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, elses) {

	zval _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettcontrol", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch_long(&_1, &_0, 1, PH_NOISY, "queryyetsimple/http/response.zep", 936 TSRMLS_CC);
	ZVAL_BOOL(&_2, 1);
	ZVAL_BOOL(&_3, !zephir_is_true(&_1));
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "settcontrol", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 条件语句 endIfs
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, endIfs) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZVAL_BOOL(&_0, 0);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "settcontrol", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置当前条件表达式状态
 *
 * @param boolean $inFlowControl
 * @param boolean $isFlowControlTrue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Response, setTControl) {

	zval *inFlowControl_param = NULL, *isFlowControlTrue_param = NULL, __$true, __$false;
	zend_bool inFlowControl, isFlowControlTrue;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 2, 0, &inFlowControl_param, &isFlowControlTrue_param);

	inFlowControl = zephir_get_boolval(inFlowControl_param);
	isFlowControlTrue = zephir_get_boolval(isFlowControlTrue_param);


	if (inFlowControl) {
		zephir_update_property_zval(this_ptr, SL("inFlowControl"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("inFlowControl"), &__$false);
	}
	if (isFlowControlTrue) {
		zephir_update_property_zval(this_ptr, SL("isFlowControlTrue"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("isFlowControlTrue"), &__$false);
	}
	RETURN_THISW();

}

/**
 * 获取当前条件表达式状态
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Http_Response, getTControl) {

	zval tmp, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("inFlowControl"), PH_NOISY_CC);
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("isFlowControlTrue"), PH_NOISY_CC);
	zephir_array_fast_append(&tmp, &_0);
	RETURN_CCTOR(&tmp);

}

/**
 * 验证一下条件表达式是否通过
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Response, checkTControl) {

	zend_bool _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("inFlowControl"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_OBS_VAR(&_2);
		zephir_read_property(&_2, this_ptr, SL("isFlowControlTrue"), PH_NOISY_CC);
		_1 = !zephir_is_true(&_2);
	}
	RETURN_MM_BOOL(_1);

}

/**
 * 占位符
 *
 * @param string $method
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Response, placeholderTControl) {

	zval *method_param = NULL, tmp, _0;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "placeholder");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "foobar");
	zephir_array_fast_append(&tmp, &_0);
	RETURN_MM_BOOL(zephir_fast_in_array(&method, &tmp TSRMLS_CC));

}

/**
 * 注册一个扩展
 *
 * @param string $name
 * @param callable $macro
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_Response, macro) {

	zval *name_param = NULL, *macro, macro_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&macro_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &macro);

	zephir_get_strval(&name, name_param);


	zephir_update_static_property_array_multi_ce(queryyetsimple_http_response_ce, SL("macro"), macro TSRMLS_CC, SL("z"), 1, &name);
	ZEPHIR_MM_RESTORE();

}

/**
 * 判断一个扩展是否注册
 *
 * @param string $name
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, hasMacro) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_static_property_ce(&_0, queryyetsimple_http_response_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

/**
 * __callStatic 魔术方法隐射
 * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
 * 即 Closure::bind($closures, null, get_called_class())
 * 为保持功能一致，所以取消 PHP 版本的静态闭包绑定功能
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Response, callStaticMacro) {

	zend_class_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _3, _5, _6, _1$$3, _2$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&_0, "hasmacro", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_static_property_ce(&_1$$3, queryyetsimple_http_response_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY | PH_READONLY, "queryyetsimple/http/response.zep", 1045 TSRMLS_CC);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_2$$3, &args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	if (!_4) {
	_4 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Http\\BadMethodCallException"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_3, _4);
	if (zephir_has_constructor(&_3 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "Method %s is not exits.");
		ZEPHIR_CALL_FUNCTION(&_6, "sprintf", NULL, 1, &_5, &method);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0, &_6);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(&_3, "queryyetsimple/http/response.zep", 1048 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * __call 魔术方法隐射
 * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
 * 即 Closure::bind($closures, null, get_called_class())
 * 为保持功能一致，所以绑定对象但是不绑定作用域，即可以使用 $this,只能访问 public 属性
 * 
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Response, callMacro) {

	zend_class_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _8, _10, _11, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4, _6$$5, _7$$5;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&_0, "hasmacro", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_static_property_ce(&_1$$3, queryyetsimple_http_response_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY, "queryyetsimple/http/response.zep", 1064 TSRMLS_CC);
		if (zephir_instance_of_ev(&_2$$3, zend_ce_closure TSRMLS_CC)) {
			zephir_read_static_property_ce(&_3$$4, queryyetsimple_http_response_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_4$$4, &_3$$4, &method, PH_NOISY | PH_READONLY, "queryyetsimple/http/response.zep", 1065 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "bindto", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_5$$4, &args);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			zephir_read_static_property_ce(&_6$$5, queryyetsimple_http_response_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_7$$5, &_6$$5, &method, PH_NOISY | PH_READONLY, "queryyetsimple/http/response.zep", 1067 TSRMLS_CC);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_7$$5, &args);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(&_8);
	if (!_9) {
	_9 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Http\\BadMethodCallException"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_8, _9);
	if (zephir_has_constructor(&_8 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_10);
		ZVAL_STRING(&_10, "Method %s is not exits.");
		ZEPHIR_CALL_FUNCTION(&_11, "sprintf", NULL, 1, &_10, &method);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_8, "__construct", NULL, 0, &_11);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(&_8, "queryyetsimple/http/response.zep", 1071 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 格式化响应时间
 *
 * @param \DateTime $datetime
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Response, normalizeDateTime) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *datetime, datetime_sub, date, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&datetime_sub);
	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datetime);



	ZEPHIR_INIT_VAR(&date);
	if (zephir_clone(&date, datetime TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_date_get_timezone_ce());
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UTC");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &date, "settimezone", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "D, d M Y H:i:s");
	ZEPHIR_CALL_METHOD(&_2, &date, "format", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VS(return_value, &_2, " GMT");
	RETURN_MM();

}

/**
 * 内容转换为 JSON
 *
 * @param mixed $content
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Response, contentToJson) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	_0 = Z_TYPE_P(content) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(content, queryyetsimple_support_ijson_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(content, "tojson", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_LONG(&_1, 256);
	zephir_json_encode(return_value, content, zephir_get_intval(&_1) );
	RETURN_MM();

}

/**
 * 可以转换为 JSON
 *
 * @param mixed $content
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Response, contentShouldJson) {

	zend_bool _0, _1, _2, _3, _4, _5;
	zval *content, content_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);

	zephir_fetch_params(0, 1, 0, &content);



	_0 = Z_TYPE_P(content) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(content, queryyetsimple_support_ijson_ce TSRMLS_CC);
	}
	_1 = _0;
	if (!(_1)) {
		_2 = Z_TYPE_P(content) == IS_OBJECT;
		if (_2) {
			_2 = zephir_instance_of_ev(content, spl_ce_ArrayObject TSRMLS_CC);
		}
		_1 = _2;
	}
	_3 = _1;
	if (!(_3)) {
		_4 = Z_TYPE_P(content) == IS_OBJECT;
		if (_4) {
			_4 = zephir_is_instance_of(content, SL("JsonSerializable") TSRMLS_CC);
		}
		_3 = _4;
	}
	_5 = _3;
	if (!(_5)) {
		_5 = Z_TYPE_P(content) == IS_ARRAY;
	}
	RETURN_BOOL(_5);

}

/**
 * __callStatic 魔术方法
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Response, __callStatic) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_RETURN_CALL_SELF("callstaticmacro", NULL, 0, &method, &args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * __call 魔术方法
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Response, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callmacro", NULL, 0, &method, &args);
	zephir_check_call_status();
	RETURN_MM();

}

void zephir_init_static_properties_Queryyetsimple_Http_Response(TSRMLS_D) {

	zval _1;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(queryyetsimple_http_response_ce, ZEND_STRL("macro"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 62, 0 TSRMLS_CC);
	add_index_stringl(&_1, 100, SL("Continue"));
	add_index_stringl(&_1, 101, SL("Switching Protocols"));
	add_index_stringl(&_1, 102, SL("Processing"));
	add_index_stringl(&_1, 103, SL("Early Hints"));
	add_index_stringl(&_1, 200, SL("OK"));
	add_index_stringl(&_1, 201, SL("Created"));
	add_index_stringl(&_1, 202, SL("Accepted"));
	add_index_stringl(&_1, 203, SL("Non-Authoritative Information"));
	add_index_stringl(&_1, 204, SL("No Content"));
	add_index_stringl(&_1, 205, SL("Reset Content"));
	add_index_stringl(&_1, 206, SL("Partial Content"));
	add_index_stringl(&_1, 207, SL("Multi-Status"));
	add_index_stringl(&_1, 208, SL("Already Reported"));
	add_index_stringl(&_1, 226, SL("IM Used"));
	add_index_stringl(&_1, 300, SL("Multiple Choices"));
	add_index_stringl(&_1, 301, SL("Moved Permanently"));
	add_index_stringl(&_1, 302, SL("Found"));
	add_index_stringl(&_1, 303, SL("See Other"));
	add_index_stringl(&_1, 304, SL("Not Modified"));
	add_index_stringl(&_1, 305, SL("Use Proxy"));
	add_index_stringl(&_1, 307, SL("Temporary Redirect"));
	add_index_stringl(&_1, 308, SL("Permanent Redirect"));
	add_index_stringl(&_1, 400, SL("Bad Request"));
	add_index_stringl(&_1, 401, SL("Unauthorized"));
	add_index_stringl(&_1, 402, SL("Payment Required"));
	add_index_stringl(&_1, 403, SL("Forbidden"));
	add_index_stringl(&_1, 404, SL("Not Found"));
	add_index_stringl(&_1, 405, SL("Method Not Allowed"));
	add_index_stringl(&_1, 406, SL("Not Acceptable"));
	add_index_stringl(&_1, 407, SL("Proxy Authentication Required"));
	add_index_stringl(&_1, 408, SL("Request Timeout"));
	add_index_stringl(&_1, 409, SL("Conflict"));
	add_index_stringl(&_1, 410, SL("Gone"));
	add_index_stringl(&_1, 411, SL("Length Required"));
	add_index_stringl(&_1, 412, SL("Precondition Failed"));
	add_index_stringl(&_1, 413, SL("Payload Too Large"));
	add_index_stringl(&_1, 414, SL("URI Too Long"));
	add_index_stringl(&_1, 415, SL("Unsupported Media Type"));
	add_index_stringl(&_1, 416, SL("Range Not Satisfiable"));
	add_index_stringl(&_1, 417, SL("Expectation Failed"));
	add_index_stringl(&_1, 418, SL("I'm a teapot"));
	add_index_stringl(&_1, 421, SL("Misdirected Request"));
	add_index_stringl(&_1, 422, SL("Unprocessable Entity"));
	add_index_stringl(&_1, 423, SL("Locked"));
	add_index_stringl(&_1, 424, SL("Failed Dependency"));
	add_index_stringl(&_1, 425, SL("Reserved for WebDAV advanced collections expired proposal"));
	add_index_stringl(&_1, 426, SL("Upgrade Required"));
	add_index_stringl(&_1, 428, SL("Precondition Required"));
	add_index_stringl(&_1, 429, SL("Too Many Requests"));
	add_index_stringl(&_1, 431, SL("Request Header Fields Too Large"));
	add_index_stringl(&_1, 451, SL("Unavailable For Legal Reasons"));
	add_index_stringl(&_1, 500, SL("Internal Server Error"));
	add_index_stringl(&_1, 501, SL("Not Implemented"));
	add_index_stringl(&_1, 502, SL("Bad Gateway"));
	add_index_stringl(&_1, 503, SL("Service Unavailable"));
	add_index_stringl(&_1, 504, SL("Gateway Timeout"));
	add_index_stringl(&_1, 505, SL("HTTP Version Not Supported"));
	add_index_stringl(&_1, 506, SL("Variant Also Negotiates"));
	add_index_stringl(&_1, 507, SL("Insufficient Storage"));
	add_index_stringl(&_1, 508, SL("Loop Detected"));
	add_index_stringl(&_1, 510, SL("Not Extended"));
	add_index_stringl(&_1, 511, SL("Network Authentication Required"));
	zend_update_static_property(queryyetsimple_http_response_ce, ZEND_STRL("statusTexts"), &_1);
	ZEPHIR_MM_RESTORE();

}
