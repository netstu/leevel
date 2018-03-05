
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/main.h"
#include "ext/spl/spl_directory.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/exception.h"


/**
 * HTTP 请求
 * This class borrows heavily from the Symfony2 Framework and is part of the symfony package
 * 
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.05
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Http, Request, queryyetsimple, http_request, queryyetsimple_http_request_method_entry, 0);

	/**
	 * GET Bag
	 *
	 * @var \Queryyetsimple\Http\Bag
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("query"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * POST Bag
	 *
	 * @var \Queryyetsimple\Http\Bag
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("request"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 路由解析后的参数
	 *
	 * @var \Queryyetsimple\Http\Bag
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("params"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * COOKIE Bag
	 *
	 * @var \Queryyetsimple\Http\Bag
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("cookie"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * FILE Bag
	 *
	 * @var \Queryyetsimple\Http\FileBag
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("files"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * SERVER Bag
	 *
	 * @var \Queryyetsimple\Http\ServerBag
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("server"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * HEADER Bag
	 *
	 * @var \Queryyetsimple\Http\HeaderBag
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("headers"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 内容
	 * 
	 * @var string|resource|false|null
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 基础 url
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("baseUrl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 请求 url
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("requestUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 请求类型
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * public URL
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("publicUrl"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * pathInfo
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("pathInfo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 应用名字
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("app"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 控制器名字
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 方法名字
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 当前语言
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("language"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 注册的动态扩展
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("macro"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_http_request_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_http_request_ce->create_object = zephir_init_properties_Queryyetsimple_Http_Request;
	/**
	 * 服务器 url 重写支持 pathInfo
	 *
	 * Nginx
	 * location @rewrite {
	 *     rewrite ^/(.*)$ /index.php?_url=/$1;
	 * }
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_request_ce, SL("PATHINFO_URL"), "_url");

	zend_class_implements(queryyetsimple_http_request_ce TSRMLS_CC, 1, queryyetsimple_option_iclass_ce);
	zend_class_implements(queryyetsimple_http_request_ce TSRMLS_CC, 1, queryyetsimple_support_imacro_ce);
	zend_class_implements(queryyetsimple_http_request_ce TSRMLS_CC, 1, queryyetsimple_http_irequest_ce);
	zend_class_implements(queryyetsimple_http_request_ce TSRMLS_CC, 1, queryyetsimple_support_iarray_ce);
	zend_class_implements(queryyetsimple_http_request_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param array $query
 * @param array $request
 * @param array $params
 * @param array $cookie
 * @param array $files
 * @param array $server
 * @param string $content
 * @param array $option
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_Request, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval content;
	zval *query_param = NULL, *request_param = NULL, *params_param = NULL, *cookie_param = NULL, *files_param = NULL, *server_param = NULL, *content_param = NULL, *option_param = NULL;
	zval query, request, params, cookie, files, server, option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&content);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 8, &query_param, &request_param, &params_param, &cookie_param, &files_param, &server_param, &content_param, &option_param);

	if (!query_param) {
		ZEPHIR_INIT_VAR(&query);
		array_init(&query);
	} else {
		zephir_get_arrval(&query, query_param);
	}
	if (!request_param) {
		ZEPHIR_INIT_VAR(&request);
		array_init(&request);
	} else {
		zephir_get_arrval(&request, request_param);
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	if (!cookie_param) {
		ZEPHIR_INIT_VAR(&cookie);
		array_init(&cookie);
	} else {
		zephir_get_arrval(&cookie, cookie_param);
	}
	if (!files_param) {
		ZEPHIR_INIT_VAR(&files);
		array_init(&files);
	} else {
		zephir_get_arrval(&files, files_param);
	}
	if (!server_param) {
		ZEPHIR_INIT_VAR(&server);
		array_init(&server);
	} else {
		zephir_get_arrval(&server, server_param);
	}
	if (!content_param) {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_STRING(&content, "");
	} else {
		zephir_get_strval(&content, content_param);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reset", NULL, 0, &query, &request, &params, &cookie, &files, &server, &content);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "options", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 重置或者初始化
 * 
 * @param array $query
 * @param array $request
 * @param array $params
 * @param array $cookie
 * @param array $files
 * @param array $server
 * @param string $content
 * @param array $option
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_Request, reset) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval content;
	zval *query_param = NULL, *request_param = NULL, *params_param = NULL, *cookie_param = NULL, *files_param = NULL, *server_param = NULL, *content_param = NULL, __$null, _0, _2, _3, _4, _5, _6, _7, _8, _9;
	zval query, request, params, cookie, files, server;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&server);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&content);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 7, &query_param, &request_param, &params_param, &cookie_param, &files_param, &server_param, &content_param);

	if (!query_param) {
		ZEPHIR_INIT_VAR(&query);
		array_init(&query);
	} else {
		zephir_get_arrval(&query, query_param);
	}
	if (!request_param) {
		ZEPHIR_INIT_VAR(&request);
		array_init(&request);
	} else {
		zephir_get_arrval(&request, request_param);
	}
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	if (!cookie_param) {
		ZEPHIR_INIT_VAR(&cookie);
		array_init(&cookie);
	} else {
		zephir_get_arrval(&cookie, cookie_param);
	}
	if (!files_param) {
		ZEPHIR_INIT_VAR(&files);
		array_init(&files);
	} else {
		zephir_get_arrval(&files, files_param);
	}
	if (!server_param) {
		ZEPHIR_INIT_VAR(&server);
		array_init(&server);
	} else {
		zephir_get_arrval(&server, server_param);
	}
	if (!content_param) {
		ZEPHIR_INIT_VAR(&content);
		ZVAL_STRING(&content, "");
	} else {
		zephir_get_strval(&content, content_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, queryyetsimple_http_bag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", &_1, 63, &query);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("query"), &_0);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, queryyetsimple_http_bag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_1, 63, &request);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("request"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, queryyetsimple_http_bag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", &_1, 63, &params);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("params"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, queryyetsimple_http_bag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", &_1, 63, &cookie);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("cookie"), &_4);
	ZEPHIR_INIT_VAR(&_5);
	object_init_ex(&_5, queryyetsimple_http_filebag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 64, &files);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("files"), &_5);
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, queryyetsimple_http_serverbag_ce);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", &_1, 63, &server);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("server"), &_6);
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, queryyetsimple_http_headerbag_ce);
	zephir_read_property(&_8, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_9, &_8, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 65, &_9);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("headers"), &_7);
	zephir_update_property_zval(this_ptr, SL("content"), &content);
	zephir_update_property_zval(this_ptr, SL("baseUrl"), &__$null);
	zephir_update_property_zval(this_ptr, SL("requestUri"), &__$null);
	zephir_update_property_zval(this_ptr, SL("method"), &__$null);
	zephir_update_property_zval(this_ptr, SL("publicUrl"), &__$null);
	zephir_update_property_zval(this_ptr, SL("pathInfo"), &__$null);
	zephir_update_property_zval(this_ptr, SL("app"), &__$null);
	zephir_update_property_zval(this_ptr, SL("controller"), &__$null);
	zephir_update_property_zval(this_ptr, SL("action"), &__$null);
	zephir_update_property_zval(this_ptr, SL("language"), &__$null);
	ZEPHIR_MM_RESTORE();

}

/**
 * 全局变量创建一个 Request
 *
 * @param array $options
 * @return static
 */
PHP_METHOD(Queryyetsimple_Http_Request, createFromGlobals) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, *_GET, *_POST, *_COOKIE, *_FILES, *_SERVER, request, _0, _1, _2;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	if (!_SERVER) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_FILES, SL("_FILES"));
	if (!_FILES) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	if (!_COOKIE) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_POST, SL("_POST"));
	if (!_POST) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_GET, SL("_GET"));
	if (!_GET) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&request);
	object_init_ex(&request, queryyetsimple_http_request_ce);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZVAL_NULL(&_1);
	ZEPHIR_CALL_METHOD(NULL, &request, "__construct", NULL, 66, _GET, _POST, &_0, _COOKIE, _FILES, _SERVER, &_1, &option);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&_2, "normalizerequestfromcontent", NULL, 0, &request);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&request, &_2);
	RETURN_CCTOR(&request);

}

/**
 * 格式化请求的内容
 *
 * @param \Queryyetsimple\Http\Request $request
 * @return \Queryyetsimple\Http\Request
 */
PHP_METHOD(Queryyetsimple_Http_Request, normalizeRequestFromContent) {

	zend_bool _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, tmp, data, _0, _1, _2, _3, _5, _6, _7, _8, _9, _10$$3, _11$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);

	ZEPHIR_SEPARATE_PARAM(request);


	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "PUT");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "DELETE");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "PATCH");
	zephir_array_fast_append(&tmp, &_0);
	zephir_read_property(&_1, request, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "CONTENT_TYPE");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "application/x-www-form-urlencoded");
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_strpos(&_3, &_2, &_0, 0 );
	_4 = ZEPHIR_IS_LONG_IDENTICAL(&_3, 0);
	if (_4) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_read_property(&_6, request, SL("server"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_STRING(&_8, "REQUEST_METHOD");
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_STRING(&_9, "GET");
		ZEPHIR_CALL_METHOD(&_7, &_6, "get", NULL, 0, &_8, &_9);
		zephir_check_call_status();
		zephir_fast_strtoupper(&_5, &_7);
		_4 = zephir_fast_in_array(&_5, &tmp TSRMLS_CC);
	}
	if (_4) {
		ZEPHIR_CALL_METHOD(&_10$$3, request, "getcontent", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&data);
		ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 67, &_10$$3, &data);
		ZEPHIR_UNREF(&data);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$3);
		object_init_ex(&_11$$3, queryyetsimple_http_bag_ce);
		ZEPHIR_CALL_METHOD(NULL, &_11$$3, "__construct", NULL, 63, &data);
		zephir_check_call_status();
		zephir_update_property_zval(request, SL("request"), &_11$$3);
	}
	RETVAL_ZVAL(request, 1, 0);
	RETURN_MM();

}

/**
 * 获取参数
 *
 * @param string $key
 * @param mixed $defaults
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Request, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, all, _0$$3, _1$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&all);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaults);

	zephir_get_strval(&key, key_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_CALL_METHOD(&all, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_key_exists(&all, &key TSRMLS_CC)) {
		zephir_array_fetch(&_0$$3, &all, &key, PH_NOISY | PH_READONLY, "queryyetsimple/http/request.zep", 302 TSRMLS_CC);
		RETURN_CTOR(&_0$$3);
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_1$$4, "get", NULL, 0, &key, defaults);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * 请求是否包含给定的 key
 *
 * @param string|array $key
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Request, exists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, keys, input, value, *_0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	if (Z_TYPE_P(key) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&keys, key);
	} else {
		ZEPHIR_INIT_NVAR(&keys);
		zephir_get_args(&keys);
	}
	ZEPHIR_CALL_METHOD(&input, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&keys, 0, "queryyetsimple/http/request.zep", 327);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _0)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (!(zephir_array_key_exists(&input, &value TSRMLS_CC))) {
			RETURN_MM_BOOL(0);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_BOOL(1);

}

/**
 * 请求是否包含非空
 *
 * @param string|array $key
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Request, has) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, keys, value, *_0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);



	if (Z_TYPE_P(key) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&keys, key);
	} else {
		ZEPHIR_INIT_NVAR(&keys);
		zephir_get_args(&keys);
	}
	zephir_is_iterable(&keys, 0, "queryyetsimple/http/request.zep", 348);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _0)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "isemptystring", &_2, 0, &value);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_BOOL(1);

}

/**
 * 取得给定的 key 数据
 *
 * @param array|mixed $keys
 * @return array
 */
PHP_METHOD(Queryyetsimple_Http_Request, only) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL, keys_sub, results, input, key, _0, *_1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys);

	ZEPHIR_SEPARATE_PARAM(keys);


	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, keys);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_get_args(&_0);
	}
	ZEPHIR_CPY_WRT(keys, &_0);
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	ZEPHIR_CALL_METHOD(&input, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(keys, 0, "queryyetsimple/http/request.zep", 369);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _1);
		ZEPHIR_INIT_LNVAR(_2$$3);
		if (zephir_array_isset(&input, &key)) {
			ZEPHIR_OBS_NVAR(&_2$$3);
			zephir_array_fetch(&_2$$3, &input, &key, PH_NOISY, "queryyetsimple/http/request.zep", 366 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_NULL(&_2$$3);
		}
		zephir_array_update_zval(&results, &key, &_2$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&results);

}

/**
 * 取得排除给定的 key 数据
 *
 * @param array|mixed $keys
 * @return array
 */
PHP_METHOD(Queryyetsimple_Http_Request, except) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys = NULL, keys_sub, results, key, _0, *_1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys);

	ZEPHIR_SEPARATE_PARAM(keys);


	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, keys);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_get_args(&_0);
	}
	ZEPHIR_CPY_WRT(keys, &_0);
	ZEPHIR_CALL_METHOD(&results, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(keys, 0, "queryyetsimple/http/request.zep", 391);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(keys), _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _1);
		if (zephir_array_key_exists(&results, &key TSRMLS_CC)) {
			zephir_array_unset(&results, &key, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&results);

}

/**
 * 取回输入和文件
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Http_Request, all) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "input", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "allfiles", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_replace_recursive", NULL, 68, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取输入数据
 *
 * @param string $key
 * @param string|array|null $defaults
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Request, input) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, input, _0, _1, _2, _3, _4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaults);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinputsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "all", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("query"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &_2, "all", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&input);
	zephir_add_function(&input, &_1, &_3);
	if (Z_TYPE_P(&key) == IS_NULL) {
		RETURN_CCTOR(&input);
	}
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_array_isset(&input, &key)) {
		zephir_array_fetch(&_4, &input, &key, PH_NOISY, "queryyetsimple/http/request.zep", 421 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_4, defaults);
	}
	RETURN_CCTOR(&_4);

}

/**
 * 取回 query
 *
 * @param string $key
 * @param string|array|null $defaults
 * @return string|array
 */
PHP_METHOD(Queryyetsimple_Http_Request, query) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaults);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "query");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getitem", NULL, 0, &_0, &key, defaults);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 请求是否存在 COOKIE
 *
 * @param  string  $key
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Request, hasCookie) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "cookie", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM_BOOL(!(Z_TYPE_P(&_0) == IS_NULL));

}

/**
 * 取回 cookie
 *
 * @param string $key
 * @param string|array|null $defaults
 * @return string|array
 */
PHP_METHOD(Queryyetsimple_Http_Request, cookie) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaults);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cookies");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getitem", NULL, 0, &_0, &key, defaults);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取得所有文件
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Http_Request, allFiles) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取文件
 * 数组文件请在末尾加上反斜杆访问
 *
 * @param string $key
 * @param mixed $defaults
 * @return \Queryyetsimple\Http\UploadedFile|array|null
 */
PHP_METHOD(Queryyetsimple_Http_Request, file) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, _0, _1, _2$$3, _3$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaults);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &key, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "files");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getitem", NULL, 0, &_2$$3, &key, defaults);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		zephir_read_property(&_3$$4, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_3$$4, "getarr", NULL, 0, &key, defaults);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * 文件是否存在已上传的文件
 * 数组文件请在末尾加上反斜杆访问
 *
 * @param string $key
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Request, hasFile) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, files, file, *_0, _1$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&files, this_ptr, "file", NULL, 0, &key);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&files) == IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(&files);
		zephir_create_array(&files, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&files, &files);
	}
	zephir_is_iterable(&files, 0, "queryyetsimple/http/request.zep", 509);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _0)
	{
		ZEPHIR_INIT_NVAR(&file);
		ZVAL_COPY(&file, _0);
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "isvalidfile", &_2, 0, &file);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$4)) {
			RETURN_MM_BOOL(1);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_BOOL(0);

}

/**
 * 验证是否为文件实例
 *
 * @param mixed $file
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Request, isValidFile) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file, file_sub, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	_0 = Z_TYPE_P(file) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(file, spl_ce_SplFileObject TSRMLS_CC);
	}
	_1 = _0;
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, file, "getpath", NULL, 0);
		zephir_check_call_status();
		_1 = !ZEPHIR_IS_STRING(&_2, "");
	}
	RETURN_MM_BOOL(_1);

}

/**
 * 取回 header
 *
 * @param string $key
 * @param string|array|null $defaults
 * @return string|array
 */
PHP_METHOD(Queryyetsimple_Http_Request, header) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaults);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "headers");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getitem", NULL, 0, &_0, &key, defaults);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取回 server
 *
 * @param string $key
 * @param string|array|null $defaults
 * @return string|array
 */
PHP_METHOD(Queryyetsimple_Http_Request, server) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key_param, &defaults);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "server");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getitem", NULL, 0, &_0, &key, defaults);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取回数据项
 *
 * @param string $source
 * @param string $key
 * @param string|array|null $defaults
 * @return string|array
 */
PHP_METHOD(Queryyetsimple_Http_Request, getItem) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *key_param = NULL, *defaults, defaults_sub, _0$$3, _1;
	zval source, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &source_param, &key_param, &defaults);

	zephir_get_strval(&source, source_param);
	zephir_get_strval(&key, key_param);


	if (Z_TYPE_P(&key) == IS_NULL) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property_zval(&_0$$3, this_ptr, &source, PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(&_0$$3, "all", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property_zval(&_1, this_ptr, &source, PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "get", NULL, 0, &key, defaults);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 合并输入
 *
 * @param array $input
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_Request, merge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);

	zephir_get_arrval(&input, input_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinputsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "add", NULL, 0, &input);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 替换输入
 *
 * @param array $input
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_Request, replace) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, _0;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);

	zephir_get_arrval(&input, input_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinputsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "replace", NULL, 0, &input);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * PHP 运行模式命令行, 兼容 swoole http service
 * Swoole http 服务器也以命令行运行
 * 
 * @link http://php.net/manual/zh/function.php-sapi-name.php
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isCli) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "SERVER_SOFTWARE");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&_1, "swoole-http-server")) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "isrealcli", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * PHP 运行模式命令行
 * 
 * @link http://php.net/manual/zh/function.php-sapi-name.php
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isRealCli) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_SAPI");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "cli");
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&_1, &_0));

}

/**
 * PHP 运行模式 cgi
 *
 * @link http://php.net/manual/zh/function.php-sapi-name.php
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isCgi) {

	zval _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_SAPI");
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 3);
	ZEPHIR_INIT_VAR(&_3);
	zephir_substr(&_3, &_0, 0 , 3 , 0);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_3, "cgi"));

}

/**
 * 是否为 Ajax 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isAjax) {

	zend_bool _3;
	zval field, _0, _1, _2, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "var_ajax");
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "has", NULL, 0, &field);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (!(_3)) {
		zephir_read_property(&_4, this_ptr, SL("query"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5, &_4, "has", NULL, 0, &field);
		zephir_check_call_status();
		_3 = zephir_is_true(&_5);
	}
	if (_3) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "isrealajax", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否为 Ajax 请求行为真实
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isRealAjax) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "X_REQUESTED_WITH");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_1, "xmlhttprequest"));

}

/**
 * 是否为 Pjax 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isPjax) {

	zend_bool _3;
	zval field, _0, _1, _2, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "var_pjax");
	ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "has", NULL, 0, &field);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (!(_3)) {
		zephir_read_property(&_4, this_ptr, SL("query"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5, &_4, "has", NULL, 0, &field);
		zephir_check_call_status();
		_3 = zephir_is_true(&_5);
	}
	if (_3) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "isrealpjax", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否为 Pjax 请求行为真实
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isRealPjax) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "X_PJAX");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(!(Z_TYPE_P(&_1) == IS_NULL));

}

/**
 * 是否为手机访问
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isMobile) {

	zend_bool _14;
	zval useAgent, allHttp, tmp, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&useAgent);
	ZVAL_UNDEF(&allHttp);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "USER_AGENT");
	ZEPHIR_CALL_METHOD(&useAgent, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ALL_HTTP");
	ZEPHIR_CALL_METHOD(&allHttp, &_2, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "windows");
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_strpos(&_3, &useAgent, &_1, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_3)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/(up.browser|up.link|mmp|symbian|smartphone|midp|wap|phone|iphone|ipad|ipod|android|xoom)/i");
	zephir_preg_match(&_5, &_6, &useAgent, &_4, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(&_5)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_7, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "ACCEPT");
	ZEPHIR_CALL_METHOD(&_8, &_7, "get", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "application/vnd.wap.xhtml+xml");
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_strpos(&_10, &_8, &_9, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_10)) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_11, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "X_WAP_PROFILE");
	ZEPHIR_CALL_METHOD(&_12, &_11, "has", NULL, 0, &_13);
	zephir_check_call_status();
	_14 = zephir_is_true(&_12);
	if (!(_14)) {
		zephir_read_property(&_15, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_13);
		ZVAL_STRING(&_13, "PROFILE");
		ZEPHIR_CALL_METHOD(&_16, &_15, "has", NULL, 0, &_13);
		zephir_check_call_status();
		_14 = zephir_is_true(&_16);
	}
	if (_14) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 86, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "w3c ");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "acs-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "alav");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "alca");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "amoi");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "audi");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "avan");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "benq");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "bird");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "blac");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "blaz");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "brew");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "cell");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "cldc");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "cmd-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "dang");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "doco");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "eric");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "hipt");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "inno");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "ipaq");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "java");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "jigs");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "kddi");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "keji");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "leno");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "lg-c");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "lg-d");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "lg-g");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "lge-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "maui");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "maxo");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "midp");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "mits");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "mmef");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "mobi");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "mot-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "moto");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "mwbp");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "nec-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "newt");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "noki");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "oper");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "palm");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "pana");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "pant");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "phil");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "play");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "port");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "prox");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "qwap");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "sage");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "sams");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "sany");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "sch-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "sec-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "send");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "seri");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "sgh-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "shar");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "sie-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "siem");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "smal");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "smar");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "sony");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "sph-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "symb");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "t-mo");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "teli");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "tim-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "tosh");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "tsm-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "upg1");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "upsi");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "vk-v");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "voda");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "wap-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "wapa");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "wapi");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "wapp");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "wapr");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "webc");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "winw");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "winw");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "xda");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "xda-");
	zephir_array_fast_append(&tmp, &_13);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_LONG(&_17, 0);
	ZVAL_LONG(&_18, 4);
	ZEPHIR_INIT_VAR(&_19);
	zephir_substr(&_19, &useAgent, 0 , 4 , 0);
	zephir_fast_strtolower(&_13, &_19);
	if (zephir_fast_in_array(&_13, &tmp TSRMLS_CC)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_20);
	zephir_fast_strtolower(&_20, &allHttp);
	ZEPHIR_INIT_VAR(&_21);
	ZVAL_STRING(&_21, "operamini");
	ZEPHIR_INIT_VAR(&_22);
	zephir_fast_strpos(&_22, &_20, &_21, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_22)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_STRING(&_23, "windows phone");
	ZEPHIR_INIT_VAR(&_24);
	zephir_fast_strpos(&_24, &useAgent, &_23, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_24)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 是否为 HEAD 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isHead) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "HEAD"));

}

/**
 * 是否为 GET 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isGet) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "GET"));

}

/**
 * 是否为 POST 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isPost) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "POST"));

}

/**
 * 是否为 PUT 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isPut) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "PUT"));

}

/**
 * 是否为 PATCH 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isPatch) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "PATCH"));

}

/**
 * 是否为 PURGE 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isPurge) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "PURGE"));

}

/**
 * 是否为 OPTIONS 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isOptions) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "OPTIONS"));

}

/**
 * 是否为 TRACE 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isTrace) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "TRACE"));

}

/**
 * 是否为 CONNECT 请求行为
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isConnect) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_0, "CONNECT"));

}

/**
 * 获取 IP 地址
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getClientIp) {

	zval _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "REMOTE_ADDR");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "0.0.0.0");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "CLIENT_IP");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 请求类型
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getMethod) {

	zval method, field, _0, _1, _2, _3, _4, _5, _6, _7$$4, _8$$4, _9$$5, _10$$6, _11$$6, _12$$6, _13$$6, _14$$6, _15$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("method"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_NULL)) {
		RETURN_MM_MEMBER(getThis(), "method");
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "REQUEST_METHOD");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "GET");
	ZEPHIR_CALL_METHOD(&_3, &_2, "get", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	zephir_fast_strtoupper(&_1, &_3);
	zephir_update_property_zval(this_ptr, SL("method"), &_1);
	zephir_read_property(&_6, this_ptr, SL("method"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_6, "POST")) {
		zephir_read_property(&_7$$4, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "X-HTTP-METHOD-OVERRIDE");
		ZEPHIR_CALL_METHOD(&method, &_7$$4, "get", NULL, 0, &_8$$4);
		zephir_check_call_status();
		if (zephir_is_true(&method)) {
			ZEPHIR_INIT_VAR(&_9$$5);
			zephir_fast_strtoupper(&_9$$5, &method);
			zephir_update_property_zval(this_ptr, SL("method"), &_9$$5);
		} else {
			ZEPHIR_INIT_VAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "var_method");
			ZEPHIR_CALL_METHOD(&field, this_ptr, "getoption", NULL, 0, &_10$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_10$$6);
			zephir_read_property(&_11$$6, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_13$$6, this_ptr, SL("query"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_15$$6);
			ZVAL_STRING(&_15$$6, "POST");
			ZEPHIR_CALL_METHOD(&_14$$6, &_13$$6, "get", NULL, 0, &field, &_15$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_12$$6, &_11$$6, "get", NULL, 0, &field, &_14$$6);
			zephir_check_call_status();
			zephir_fast_strtoupper(&_10$$6, &_12$$6);
			zephir_update_property_zval(this_ptr, SL("method"), &_10$$6);
		}
	}
	RETURN_MM_MEMBER(getThis(), "method");

}

/**
 * 设置请求类型
 *
 * @param string $method
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, setMethod) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, __$null, _0, _1;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	zephir_update_property_zval(this_ptr, SL("method"), &__$null);
	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "REQUEST_METHOD");
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1, &method);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 实际请求类型
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getRealMethod) {

	zval _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "REQUEST_METHOD");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "GET");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_fast_strtoupper(return_value, &_1);
	RETURN_MM();

}

/**
 * 取回应用名
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, app) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "app");

}

/**
 * 取回控制器名
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, controller) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "controller");

}

/**
 * 取回方法名
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, action) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "action");

}

/**
 * 取得节点
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getNode) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "app", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "controller", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "action", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVSV(return_value, &_0, "://", &_1, "/", &_2);
	RETURN_MM();

}

/**
 * 设置应用名
 *
 * @param string $app
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, setApp) {

	zval *app_param = NULL;
	zval app;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app_param);

	zephir_get_strval(&app, app_param);


	zephir_update_property_zval(this_ptr, SL("app"), &app);
	RETURN_THIS();

}

/**
 * 设置控制器名
 *
 * @param string $controller
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, setController) {

	zval *controller_param = NULL;
	zval controller;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controller);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controller_param);

	zephir_get_strval(&controller, controller_param);


	zephir_update_property_zval(this_ptr, SL("controller"), &controller);
	RETURN_THIS();

}

/**
 * 设置方法名
 *
 * @param string $action
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, setAction) {

	zval *action_param = NULL;
	zval action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &action_param);

	zephir_get_strval(&action, action_param);


	zephir_update_property_zval(this_ptr, SL("action"), &action);
	RETURN_THIS();

}

/**
 * 返回当前的语言
 *
 * @return string|null
 */
PHP_METHOD(Queryyetsimple_Http_Request, language) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "language");

}

/**
 * 设置当前的语言
 *
 * @param string $language
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, setLanguage) {

	zval *language_param = NULL;
	zval language;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&language);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &language_param);

	zephir_get_strval(&language, language_param);


	zephir_update_property_zval(this_ptr, SL("language"), &language);
	RETURN_THIS();

}

/**
 * 取得请求内容
 *
 * @return string|resource
 */
PHP_METHOD(Queryyetsimple_Http_Request, getContent) {

	zend_bool _4;
	zval resources, _0, _3, _5, _1$$3, _2$$3, _6$$4, _7$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resources);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&resources);
	ZVAL_BOOL(&resources, Z_TYPE_P(&_0) == IS_RESOURCE);
	if (zephir_is_true(&resources)) {
		zephir_read_property(&_1$$3, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "rewind", NULL, 69, &_1$$3);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_FUNCTION("stream_get_contents", NULL, 70, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_3, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
	_4 = Z_TYPE_P(&_3) == IS_NULL;
	if (!(_4)) {
		zephir_read_property(&_5, this_ptr, SL("content"), PH_NOISY_CC | PH_READONLY);
		_4 = ZEPHIR_IS_FALSE_IDENTICAL(&_5);
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "php://input");
		zephir_file_get_contents(&_6$$4, &_7$$4 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("content"), &_6$$4);
	}
	RETURN_MM_MEMBER(getThis(), "content");

}

/**
 * 返回网站公共文件目录
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getPublicUrl) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("publicUrl"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_NULL)) {
		RETURN_MM_MEMBER(getThis(), "publicUrl");
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "public");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("publicUrl"), &_1);
	RETURN_MM_MEMBER(getThis(), "publicUrl");

}

/**
 * 设置网站公共文件目录
 *
 * @param string $publicUrl
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, setPublicUrl) {

	zval *publicUrl_param = NULL;
	zval publicUrl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&publicUrl);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &publicUrl_param);

	zephir_get_strval(&publicUrl, publicUrl_param);


	zephir_update_property_zval(this_ptr, SL("publicUrl"), &publicUrl);
	RETURN_THIS();

}

/**
 * 返回 root URL
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getRoot) {

	zval _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getschemeandhttphost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getbaseurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_0, &_1);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/");
	zephir_fast_trim(return_value, &_2, &_3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	RETURN_MM();

}

/**
 * 返回入口文件
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getEnter) {

	zval scriptName, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scriptName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&scriptName, this_ptr, "getscriptname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "rewrite");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_CCTOR(&scriptName);
	}
	ZEPHIR_CALL_FUNCTION(&_2, "dirname", NULL, 18, &scriptName);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&scriptName, &_2);
	if (ZEPHIR_IS_STRING(&scriptName, "\\")) {
		ZEPHIR_INIT_NVAR(&scriptName);
		ZVAL_STRING(&scriptName, "/");
	}
	RETURN_CCTOR(&scriptName);

}

/**
 * 取得脚本名字
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getScriptName) {

	zval _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "ORIG_SCRIPT_NAME");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "SCRIPT_NAME");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否启用 https
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Http_Request, isSecure) {

	zval tmp, _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "1");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "on");
	zephir_array_fast_append(&tmp, &_0);
	zephir_read_property(&_1, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "HTTPS");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "SERVER_PORT");
	ZEPHIR_CALL_METHOD(&_4, &_3, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_fast_in_array(&_2, &tmp TSRMLS_CC)) {
		RETURN_MM_BOOL(1);
	} else if (ZEPHIR_IS_STRING(&_4, "443")) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 取得 http host
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getHttpHost) {

	zend_bool _0, _1, _2;
	zval scheme, port, _4;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&scheme);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&scheme, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&port, this_ptr, "getport", NULL, 0);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_STRING(&scheme, "http");
	if (_0) {
		_0 = ZEPHIR_IS_LONG(&port, 80);
	}
	_1 = _0;
	if (!(_1)) {
		_2 = ZEPHIR_IS_STRING(&scheme, "https");
		if (_2) {
			_2 = ZEPHIR_IS_LONG(&port, 443);
		}
		_1 = _2;
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "gethost", &_3, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gethost", &_3, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_4, ":", &port);
	RETURN_MM();

}

/**
 * 获取 host
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getHost) {

	zval _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "HOST");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "X_FORWARDED_HOST");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取得 Scheme 和 Host
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getSchemeAndHttpHost) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getscheme", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gethost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_0, "://", &_1);
	RETURN_MM();

}

/**
 * 返回当前 URL 地址
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getUri) {

	zval queryString, _1, _2, _3, _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queryString);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&queryString, this_ptr, "getquerystring", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&queryString) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, "?", &queryString);
		ZEPHIR_CPY_WRT(&queryString, &_0$$3);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getschemeandhttphost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getbaseurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getpathinfo", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVVV(return_value, &_1, &_2, &_3, &queryString);
	RETURN_MM();

}

/**
 * 服务器端口
 *
 * @return integer
 */
PHP_METHOD(Queryyetsimple_Http_Request, getPort) {

	zval port, _0, _1, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "SERVER_PORT");
	ZEPHIR_CALL_METHOD(&port, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&port))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getscheme", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING_IDENTICAL(&_2$$3, "https")) {
			ZEPHIR_INIT_NVAR(&port);
			ZVAL_LONG(&port, 443);
		} else {
			ZEPHIR_INIT_NVAR(&port);
			ZVAL_LONG(&port, 80);
		}
	}
	RETURN_CCTOR(&port);

}

/**
 * 返回 scheme
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getScheme) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "issecure", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZVAL_STRING(&_0, "https");
	} else {
		ZVAL_STRING(&_0, "http");
	}
	RETURN_CCTOR(&_0);

}

/**
 * 取回查询参数
 *
 * @return string|null
 */
PHP_METHOD(Queryyetsimple_Http_Request, getQueryString) {

	zval queryString, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queryString);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "QUERY_STRING");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&queryString, this_ptr, "normalizequerystring", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	if (ZEPHIR_IS_STRING_IDENTICAL(&queryString, "")) {
		ZVAL_NULL(&_2);
	} else {
		ZEPHIR_CPY_WRT(&_2, &queryString);
	}
	RETURN_CCTOR(&_2);

}

/**
 * 设置 pathInfo
 *
 * @param string $pathInfo
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, setPathInfo) {

	zval *pathInfo_param = NULL;
	zval pathInfo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pathInfo);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pathInfo_param);

	zephir_get_strval(&pathInfo, pathInfo_param);


	zephir_update_property_zval(this_ptr, SL("pathInfo"), &pathInfo);
	RETURN_THIS();

}

/**
 * pathInfo 兼容性分析
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getPathInfo) {

	zend_bool _16;
	zval pathInfo, baseUrl, requestUri, pos, _0, _1, _2, _5, _6, _15, _17, _3$$4, _7$$5, _8$$5, _9$$5, _10$$5, _11$$6, _12$$6, _13$$7, _14$$7;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pathInfo);
	ZVAL_UNDEF(&baseUrl);
	ZVAL_UNDEF(&requestUri);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("pathInfo"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_NULL)) {
		RETURN_MM_MEMBER(getThis(), "pathInfo");
	}
	zephir_read_property(&_1, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "PATH_INFO");
	ZEPHIR_CALL_METHOD(&pathInfo, &_1, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&pathInfo)) {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "parsepathinfo", &_4, 0, &pathInfo);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("pathInfo"), &_3$$4);
		RETURN_MM_MEMBER(getThis(), "pathInfo");
	}
	zephir_read_property(&_5, this_ptr, SL("query"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "_url");
	ZEPHIR_CALL_METHOD(&_6, &_5, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		zephir_read_property(&_7$$5, this_ptr, SL("query"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "_url");
		ZEPHIR_CALL_METHOD(&_8$$5, &_7$$5, "get", NULL, 0, &_9$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&pathInfo, this_ptr, "parsepathinfo", &_4, 0, &_8$$5);
		zephir_check_call_status();
		zephir_read_property(&_10$$5, this_ptr, SL("query"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "_url");
		ZEPHIR_CALL_METHOD(NULL, &_10$$5, "remove", NULL, 0, &_9$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("pathInfo"), &pathInfo);
		RETURN_MM_MEMBER(getThis(), "pathInfo");
	}
	ZEPHIR_CALL_METHOD(&baseUrl, this_ptr, "getbaseurl", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&requestUri, this_ptr, "getrequesturi", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&requestUri) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_12$$6);
		ZVAL_STRING(&_12$$6, "");
		ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "parsepathinfo", &_4, 0, &_12$$6);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("pathInfo"), &_11$$6);
		RETURN_MM_MEMBER(getThis(), "pathInfo");
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "?");
	ZEPHIR_INIT_VAR(&pos);
	zephir_fast_strpos(&pos, &requestUri, &_2, 0 );
	if (ZEPHIR_GT_LONG(&pos, 0)) {
		ZVAL_LONG(&_13$$7, 0);
		ZEPHIR_INIT_VAR(&_14$$7);
		zephir_substr(&_14$$7, &requestUri, 0 , zephir_get_intval(&pos), 0);
		ZEPHIR_CPY_WRT(&requestUri, &_14$$7);
	}
	ZVAL_LONG(&_15, zephir_fast_strlen_ev(&baseUrl));
	ZEPHIR_INIT_NVAR(&pathInfo);
	zephir_substr(&pathInfo, &requestUri, zephir_get_intval(&_15), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	_16 = Z_TYPE_P(&baseUrl) != IS_NULL;
	if (_16) {
		_16 = ZEPHIR_IS_FALSE_IDENTICAL(&pathInfo);
	}
	if (_16) {
		ZEPHIR_INIT_NVAR(&pathInfo);
		ZVAL_STRING(&pathInfo, "");
	} else if (Z_TYPE_P(&baseUrl) == IS_NULL) {
		ZEPHIR_CPY_WRT(&pathInfo, &requestUri);
	}
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "parsepathinfo", &_4, 0, &pathInfo);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("pathInfo"), &_17);
	RETURN_MM_MEMBER(getThis(), "pathInfo");

}

/**
 * 分析基础 url
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getBaseUrl) {

	zend_bool _36, _37, _24$$7, _26$$7;
	zval fileName, url, path, segs, maxCount, pos, seg, requestUri, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _28, _30, _34, _35, _40, _41, _13$$4, _14$$4, _15$$5, _16$$5, _17$$6, _18$$6, _19$$7, _20$$7, _21$$7, _22$$7, _25$$7, _27$$7, _23$$8, _31$$10, _32$$10, _33$$10, _38$$12, _39$$12;
	zephir_fcall_cache_entry *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, index = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&segs);
	ZVAL_UNDEF(&maxCount);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&seg);
	ZVAL_UNDEF(&requestUri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_31$$10);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_38$$12);
	ZVAL_UNDEF(&_39$$12);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("baseUrl"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_NULL)) {
		RETURN_MM_MEMBER(getThis(), "baseUrl");
	}
	zephir_read_property(&_1, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "SCRIPT_FILENAME");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&fileName);
	zephir_basename(&fileName, &_2 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_read_property(&_4, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "SCRIPT_NAME");
	ZEPHIR_CALL_METHOD(&_5, &_4, "get", NULL, 0, &_6);
	zephir_check_call_status();
	zephir_basename(&_3, &_5 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_6);
	zephir_read_property(&_7, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "PHP_SELF");
	ZEPHIR_CALL_METHOD(&_8, &_7, "get", NULL, 0, &_9);
	zephir_check_call_status();
	zephir_basename(&_6, &_8 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_9);
	zephir_read_property(&_10, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "ORIG_SCRIPT_NAME");
	ZEPHIR_CALL_METHOD(&_11, &_10, "get", NULL, 0, &_12);
	zephir_check_call_status();
	zephir_basename(&_9, &_11 TSRMLS_CC);
	if (ZEPHIR_IS_IDENTICAL(&_3, &fileName)) {
		zephir_read_property(&_13$$4, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "SCRIPT_NAME");
		ZEPHIR_CALL_METHOD(&url, &_13$$4, "get", NULL, 0, &_14$$4);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_IDENTICAL(&_6, &fileName)) {
		zephir_read_property(&_15$$5, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_16$$5);
		ZVAL_STRING(&_16$$5, "PHP_SELF");
		ZEPHIR_CALL_METHOD(&url, &_15$$5, "get", NULL, 0, &_16$$5);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_IDENTICAL(&_9, &fileName)) {
		zephir_read_property(&_17$$6, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_18$$6);
		ZVAL_STRING(&_18$$6, "ORIG_SCRIPT_NAME");
		ZEPHIR_CALL_METHOD(&url, &_17$$6, "get", NULL, 0, &_18$$6);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_19$$7, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_20$$7);
		ZVAL_STRING(&_20$$7, "PHP_SELF");
		ZEPHIR_CALL_METHOD(&path, &_19$$7, "get", NULL, 0, &_20$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_20$$7);
		ZEPHIR_INIT_VAR(&_21$$7);
		ZVAL_STRING(&_21$$7, "/");
		zephir_fast_trim(&_20$$7, &fileName, &_21$$7, ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_INIT_VAR(&segs);
		zephir_fast_explode_str(&segs, SL("/"), &_20$$7, LONG_MAX TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_22$$7, "array_reverse", NULL, 71, &segs);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&segs, &_22$$7);
		index = 0;
		ZEPHIR_INIT_VAR(&maxCount);
		ZVAL_LONG(&maxCount, zephir_fast_count_int(&segs TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&url);
		ZVAL_STRING(&url, "");
		do {
			ZEPHIR_OBS_NVAR(&seg);
			zephir_array_fetch_long(&seg, &segs, index, PH_NOISY, "queryyetsimple/http/request.zep", 1382 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_23$$8);
			ZEPHIR_CONCAT_SVV(&_23$$8, "/", &seg, &url);
			ZEPHIR_CPY_WRT(&url, &_23$$8);
			index++;
			_24$$7 = ZEPHIR_GT_LONG(&maxCount, index);
			if (_24$$7) {
				ZEPHIR_INIT_NVAR(&_25$$7);
				zephir_fast_strpos(&_25$$7, &path, &url, 0 );
				_24$$7 = !ZEPHIR_IS_FALSE_IDENTICAL(&_25$$7);
			}
			_26$$7 = _24$$7;
			if (_26$$7) {
				ZEPHIR_INIT_NVAR(&_27$$7);
				zephir_fast_strpos(&_27$$7, &path, &url, 0 );
				_26$$7 = !ZEPHIR_IS_LONG_IDENTICAL(&_27$$7, 0);
			}
		} while (_26$$7);
	}
	ZEPHIR_CALL_METHOD(&requestUri, this_ptr, "getrequesturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_12);
	zephir_fast_strpos(&_12, &requestUri, &url, 0 );
	if (ZEPHIR_IS_LONG_IDENTICAL(&_12, 0)) {
		zephir_update_property_zval(this_ptr, SL("baseUrl"), &url);
		RETURN_MM_MEMBER(getThis(), "baseUrl");
	}
	ZEPHIR_CALL_FUNCTION(&_28, "dirname", &_29, 18, &url);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_30);
	zephir_fast_strpos(&_30, &requestUri, &_28, 0 );
	if (ZEPHIR_IS_LONG_IDENTICAL(&_30, 0)) {
		ZEPHIR_INIT_VAR(&_31$$10);
		ZEPHIR_CALL_FUNCTION(&_32$$10, "dirname", &_29, 18, &url);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_33$$10);
		ZVAL_STRING(&_33$$10, "/");
		zephir_fast_trim(&_31$$10, &_32$$10, &_33$$10, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("baseUrl"), &_31$$10);
		RETURN_MM_MEMBER(getThis(), "baseUrl");
	}
	ZEPHIR_INIT_VAR(&_34);
	zephir_basename(&_34, &url TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_35);
	zephir_fast_strpos(&_35, &requestUri, &_34, 0 );
	if (!(zephir_is_true(&_35))) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&pos);
	zephir_fast_strpos(&pos, &requestUri, &url, 0 );
	_36 = zephir_fast_strlen_ev(&requestUri) >= zephir_fast_strlen_ev(&url);
	if (_36) {
		_37 = !ZEPHIR_IS_FALSE_IDENTICAL(&pos);
		if (_37) {
			_37 = !ZEPHIR_IS_LONG_IDENTICAL(&pos, 0);
		}
		_36 = _37;
	}
	if (_36) {
		ZVAL_LONG(&_38$$12, 0);
		ZVAL_LONG(&_39$$12, (zephir_get_numberval(&pos) + zephir_fast_strlen_ev(&url)));
		ZEPHIR_INIT_NVAR(&url);
		zephir_substr(&url, &requestUri, 0 , zephir_get_intval(&_39$$12), 0);
	}
	ZEPHIR_INIT_VAR(&_40);
	ZEPHIR_INIT_VAR(&_41);
	ZVAL_STRING(&_41, "/");
	zephir_fast_trim(&_40, &url, &_41, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("baseUrl"), &_40);
	RETURN_MM_MEMBER(getThis(), "baseUrl");

}

/**
 * 请求参数
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, getRequestUri) {

	zval requestUri, _0, _1, _2, _3, _4, _5, _6$$4, _7$$4, _8$$4, _9$$4, _10$$5, _11$$5, _12$$5, _13$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&requestUri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("requestUri"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_NULL)) {
		RETURN_MM_MEMBER(getThis(), "requestUri");
	}
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "REQUEST_URI");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "");
	ZEPHIR_CALL_METHOD(&_3, &_2, "get", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "X_REWRITE_URL");
	ZEPHIR_CALL_METHOD(&requestUri, &_1, "get", NULL, 0, &_4, &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(&requestUri))) {
		zephir_read_property(&_6$$4, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "ORIG_PATH_INFO");
		ZEPHIR_CALL_METHOD(&requestUri, &_6$$4, "get", NULL, 0, &_7$$4);
		zephir_check_call_status();
		zephir_read_property(&_8$$4, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "QUERY_STRING");
		ZEPHIR_CALL_METHOD(&_9$$4, &_8$$4, "get", NULL, 0, &_7$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_9$$4)) {
			zephir_read_property(&_10$$5, this_ptr, SL("server"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_12$$5);
			ZVAL_STRING(&_12$$5, "QUERY_STRING");
			ZEPHIR_CALL_METHOD(&_11$$5, &_10$$5, "get", NULL, 0, &_12$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_13$$5);
			ZEPHIR_CONCAT_SV(&_13$$5, "?", &_11$$5);
			zephir_concat_self(&requestUri, &_13$$5 TSRMLS_CC);
		}
	}
	zephir_update_property_zval(this_ptr, SL("requestUri"), &requestUri);
	RETURN_MM_MEMBER(getThis(), "requestUri");

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, option) {

	zend_class_entry *_1$$3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, _0$$3, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	if (!(Z_TYPE_P(&name) == IS_STRING)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (!_1$$3) {
		_1$$3 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Http\\InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_0$$3, _1$$3);
		if (zephir_has_constructor(&_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Option set name must be a string.");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_2$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_0$$3, "queryyetsimple/http/request.zep", 1453 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("option"), &name, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 修改数组配置
 *
 * @param string $name
 * @param array $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, optionArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *name_param = NULL, *value_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &name);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &value TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "option", NULL, 0, &name, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 修改多个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, options) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, name, value, *_0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (ZEPHIR_IS_EMPTY(&option)) {
		RETURN_THIS();
	}
	zephir_is_iterable(&option, 0, "queryyetsimple/http/request.zep", 1490);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&option), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "option", &_3, 0, &name, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();

}

/**
 * 获取单个配置
 *
 * @param string $name
 * @param mixed $defaultss
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Request, getOption) {

	zval *name_param = NULL, *defaultss = NULL, defaultss_sub, __$null, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaultss_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultss);

	zephir_get_strval(&name, name_param);
	if (!defaultss) {
		defaultss = &defaultss_sub;
		defaultss = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &name)) {
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &name, PH_NOISY, "queryyetsimple/http/request.zep", 1502 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, defaultss);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 获取所有配置
 *
 * @param array $option
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Request, getOptions) {

	zval *option_param = NULL, _0$$3;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&option))) {
		zephir_read_property(&_0$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(return_value, &_0$$3, &option TSRMLS_CC);
		RETURN_MM();
	} else {
		RETURN_MM_MEMBER(getThis(), "option");
	}

}

/**
 * 删除单个配置
 *
 * @param string $name
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, deleteOption) {

	zval *name_param = NULL, _0, _1$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		zephir_read_property(&_1$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &name, PH_SEPARATE);
	}
	RETURN_THIS();

}

/**
 * 删除多个配置
 *
 * @param array $option
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Http_Request, deleteOptions) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, key, *_0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&option))) {
		RETURN_THIS();
	}
	zephir_is_iterable(&option, 0, "queryyetsimple/http/request.zep", 1553);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&option), _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteoption", &_1, 0, &key);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

/**
 * 注册一个扩展
 *
 * @param string $name
 * @param callable $macro
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_Request, macro) {

	zval *name_param = NULL, *macro, macro_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&macro_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &macro);

	zephir_get_strval(&name, name_param);


	zephir_update_static_property_array_multi_ce(queryyetsimple_http_request_ce, SL("macro"), macro TSRMLS_CC, SL("z"), 1, &name);
	ZEPHIR_MM_RESTORE();

}

/**
 * 判断一个扩展是否注册
 *
 * @param string $name
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Request, hasMacro) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_static_property_ce(&_0, queryyetsimple_http_request_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Queryyetsimple_Http_Request, callStaticMacro) {

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
		zephir_read_static_property_ce(&_1$$3, queryyetsimple_http_request_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY | PH_READONLY, "queryyetsimple/http/request.zep", 1592 TSRMLS_CC);
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
	zephir_throw_exception_debug(&_3, "queryyetsimple/http/request.zep", 1595 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Http_Request, callMacro) {

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
		zephir_read_static_property_ce(&_1$$3, queryyetsimple_http_request_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY, "queryyetsimple/http/request.zep", 1611 TSRMLS_CC);
		if (zephir_is_instance_of(&_2$$3, SL("Queryyetsimple\\Http\\Closure") TSRMLS_CC)) {
			zephir_read_static_property_ce(&_3$$4, queryyetsimple_http_request_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_4$$4, &_3$$4, &method, PH_NOISY | PH_READONLY, "queryyetsimple/http/request.zep", 1612 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "bindto", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_5$$4, &args);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			zephir_read_static_property_ce(&_6$$5, queryyetsimple_http_request_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_7$$5, &_6$$5, &method, PH_NOISY | PH_READONLY, "queryyetsimple/http/request.zep", 1614 TSRMLS_CC);
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
	zephir_throw_exception_debug(&_8, "queryyetsimple/http/request.zep", 1618 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 判断字符串是否为数字
 *
 * @param mixed $value
 * @since bool
 */
PHP_METHOD(Queryyetsimple_Http_Request, isInt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_LONG) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 11, value);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_digit", NULL, 12, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * pathinfo 处理
 *
 * @param string $pathInfo
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, parsePathInfo) {

	zend_bool _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pathInfo_param = NULL, suffix, _1, _2, _9, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3;
	zval pathInfo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pathInfo);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pathInfo_param);

	zephir_get_strval(&pathInfo, pathInfo_param);


	_0 = zephir_is_true(&pathInfo);
	if (_0) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "html_suffix");
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", &_3, 0, &_2);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "html_suffix");
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getoption", &_3, 0, &_5$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, 1);
		ZEPHIR_INIT_VAR(&suffix);
		zephir_substr(&suffix, &_4$$3, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_CONCAT_SVS(&_7$$3, "/\\.", &suffix, "$/");
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "");
		ZEPHIR_CALL_FUNCTION(&_8$$3, "preg_replace", NULL, 72, &_7$$3, &_5$$3, &pathInfo);
		zephir_check_call_status();
		zephir_get_strval(&pathInfo, &_8$$3);
	}
	ZEPHIR_INIT_VAR(&_9);
	if (ZEPHIR_IS_EMPTY(&pathInfo)) {
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_STRING(&_9, "/");
	} else {
		ZEPHIR_CPY_WRT(&_9, &pathInfo);
	}
	zephir_get_strval(&pathInfo, &_9);
	RETURN_CTOR(&pathInfo);

}

/**
 * 格式化查询参数
 * 
 * @param string $queryString
 * @return string
 */
PHP_METHOD(Queryyetsimple_Http_Request, normalizeQueryString) {

	zval *queryString_param = NULL, parts, item, _0, *_1, _3$$4;
	zval queryString, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queryString);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &queryString_param);

	zephir_get_strval(&queryString, queryString_param);


	if (ZEPHIR_IS_STRING(&queryString, "")) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL("&"), &queryString, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(&_0, 0, "queryyetsimple/http/request.zep", 1679);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_INIT_LNVAR(_2$$4);
		ZEPHIR_CONCAT_SS(&_2$$4, "_url", "=");
		ZEPHIR_INIT_NVAR(&_3$$4);
		zephir_fast_strpos(&_3$$4, &item, &_2$$4, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(&_3$$4, 0)) {
			continue;
		}
		zephir_array_append(&parts, &item, PH_SEPARATE, "queryyetsimple/http/request.zep", 1676);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	zephir_fast_join_str(return_value, SL("&"), &parts TSRMLS_CC);
	RETURN_MM();

}

/**
 * 取得请求输入源
 *
 * @return \Queryyetsimple\Http\Bag
 */
PHP_METHOD(Queryyetsimple_Http_Request, getInputSource) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmethod", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&_1, "GET")) {
		zephir_read_property(&_0, this_ptr, SL("query"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0, this_ptr, SL("request"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 是否为空字符串
 *
 * @param string $key
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Request, isEmptyString) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, value, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&value, this_ptr, "input", NULL, 0, &key);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&value) == IS_STRING;
	if (_0) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_fast_trim(&_1, &value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "");
	}
	RETURN_MM_BOOL(_0);

}

/**
 * 对象转数组
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Http_Request, toArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetExists
 *
 * @param string $offset
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Request, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, _0;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(&offset, offset_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_key_exists(&_0, &offset TSRMLS_CC));

}

/**
 * 实现 ArrayAccess::offsetGet
 *
 * @param string $offset
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Request, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, _0;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(&offset, offset_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("data_get", NULL, 0, &_0, &offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetSet
 *
 * @param string $offset
 * @param mixed $value
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Request, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, *value, value_sub, _0;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset_param, &value);

	zephir_get_strval(&offset, offset_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinputsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "set", NULL, 0, &offset, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetUnset
 *
 * @param string $offset
 * @return void
 */
PHP_METHOD(Queryyetsimple_Http_Request, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, _0;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(&offset, offset_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinputsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "remove", NULL, 0, &offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否存在输入值
 *
 * @param string $key
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Http_Request, __isset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "__get", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM_BOOL(!(Z_TYPE_P(&_0) == IS_NULL));

}

/**
 * 获取输入值
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Request, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * __callStatic 魔术方法
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_Request, __callStatic) {

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
PHP_METHOD(Queryyetsimple_Http_Request, __call) {

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

void zephir_init_static_properties_Queryyetsimple_Http_Request(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(queryyetsimple_http_request_ce, ZEND_STRL("macro"), &_0);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Queryyetsimple_Http_Request(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval __$false, _0;
		ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 6, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("var_method"), SL("_method"));
			add_assoc_stringl_ex(&_1$$3, SL("var_ajax"), SL("_ajax"));
			add_assoc_stringl_ex(&_1$$3, SL("var_pjax"), SL("_pjax"));
			add_assoc_stringl_ex(&_1$$3, SL("html_suffix"), SL(".html"));
			zephir_array_update_string(&_1$$3, SL("rewrite"), &__$false, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_1$$3, SL("public"), SL("http://public.foo.bar"));
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

