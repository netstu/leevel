
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Api 响应请求
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.06
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Http_ApiResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Http, ApiResponse, queryyetsimple, http_apiresponse, queryyetsimple_http_jsonresponse_ce, queryyetsimple_http_apiresponse_method_entry, 0);

	return SUCCESS;

}

/**
 * 请求成功
 * 一般用于GET与POST请求： 200
 * 
 * @param mixed $content
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, ok) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text;
	zval *content = NULL, content_sub, *text_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&text);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &content, &text_param);

	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZVAL_LONG(&_1, 200);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_1, &text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setdata", NULL, 0, content);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 已创建
 * 成功请求并创建了新的资源: 201
 *
 * @param null|string $location
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, created) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *location = NULL, location_sub, *content = NULL, content_sub, _0, _1, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &location, &content);

	if (!location) {
		location = &location_sub;
		ZEPHIR_INIT_VAR(location);
		ZVAL_STRING(location, "");
	}
	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, content);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 201);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(location) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Location");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_2$$4, location);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 已接受
 * 已经接受请求，但未处理完成: 202
 *
 * @param null|string $location
 * @param mixed $content
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, accepted) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *location = NULL, location_sub, *content = NULL, content_sub, __$null, _0, _1, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &location, &content);

	if (!location) {
		location = &location_sub;
		location = &__$null;
	}
	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, content);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 202);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(location) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Location");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_2$$4, location);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 无内容
 * 服务器成功处理，但未返回内容: 204
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, noContent) {

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
	ZVAL_LONG(&_1, 204);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setstatuscode", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 无法处理的实体
 * 请求格式正确，但是由于含有语义错误，无法响应: 422
 * 
 * @param array $errors
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, unprocessableEntity) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message, text;
	zval *errors_param = NULL, *message_param = NULL, *text_param = NULL, tmp, tmpArr, _0, _1, _2;
	zval errors;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tmpArr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &errors_param, &message_param, &text_param);

	if (!errors_param) {
		ZEPHIR_INIT_VAR(&errors);
		array_init(&errors);
	} else {
		zephir_get_arrval(&errors, errors_param);
	}
	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZVAL_LONG(&_1, 422);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_1, &text);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&errors))) {
		ZEPHIR_CPY_WRT(&tmpArr, &errors);
	} else {
		ZEPHIR_INIT_NVAR(&tmpArr);
		array_init(&tmpArr);
	}
	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "parseerrormessage", NULL, 0, &message);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("message"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&tmp, SL("errors"), &tmpArr, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, &tmp);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 错误请求
 * 服务器不理解请求的语法: 400
 * 
 * @param string $message
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *statusCode, statusCode_sub, *text_param = NULL, _0;
	zval message, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&statusCode_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &message_param, &statusCode, &text_param);

	zephir_get_strval(&message, message_param);
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, statusCode, &text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "normalizeerrormessage", NULL, 0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 错误请求
 * 服务器不理解请求的语法: 400
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, badRequest) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *text_param = NULL, _0;
	zval message, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message_param, &text_param);

	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZVAL_LONG(&_0, 400);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, &message, &_0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 未授权
 * 对于需要登录的网页，服务器可能返回此响应: 401
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, unauthorized) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *text_param = NULL, _0;
	zval message, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message_param, &text_param);

	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZVAL_LONG(&_0, 401);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, &message, &_0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 禁止
 * 服务器拒绝请求: 403
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, forbidden) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *text_param = NULL, _0;
	zval message, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message_param, &text_param);

	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZVAL_LONG(&_0, 403);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, &message, &_0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 未找到
 * 用户发出的请求针对的是不存在的记录: 404
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, notFound) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *text_param = NULL, _0;
	zval message, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message_param, &text_param);

	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZVAL_LONG(&_0, 404);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, &message, &_0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 方法禁用
 * 禁用请求中指定的方法: 405
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, methodNotAllowed) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *text_param = NULL, _0;
	zval message, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message_param, &text_param);

	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZVAL_LONG(&_0, 405);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, &message, &_0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 太多请求
 * 用户在给定的时间内发送了太多的请求: 429
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, tooManyRequests) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *text_param = NULL, _0;
	zval message, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message_param, &text_param);

	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZVAL_LONG(&_0, 429);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, &message, &_0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 服务器内部错误
 * 服务器遇到错误，无法完成请求: 500
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, internalServerError) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *text_param = NULL, _0;
	zval message, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message_param, &text_param);

	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}


	ZVAL_LONG(&_0, 500);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, &message, &_0, &text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 格式化错误消息
 *  
 * @param string $message
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, normalizeErrorMessage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *text = NULL, text_sub, __$null, tmp, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message_param, &text);

	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseerrormessage", NULL, 0, &message);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("message"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setdata", NULL, 0, &tmp);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 分析错误消息
 *  
 * @param string $message
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_ApiResponse, parseErrorMessage) {

	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &message_param);

	if (!message_param) {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_STRING(&message, "");
	} else {
		zephir_get_strval(&message, message_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&message) == IS_UNDEF) && Z_STRLEN_P(&message)) {
		ZEPHIR_CPY_WRT(&_0, &message);
	} else {
		zephir_read_property(&_0, this_ptr, SL("statusText"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

