
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * url 生成
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.08
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Router_Url) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Router, Url, queryyetsimple, router_url, queryyetsimple_router_url_method_entry, 0);

	/**
	 * HTTP 请求
	 * 
	 * @var \Queryyetsimple\Http\IRequest
	 */
	zend_declare_property_null(queryyetsimple_router_url_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 解析后的 MVC 参数
	 * 
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_router_url_ce, SL("parseMvc"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * http 前缀
	 * 
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_router_url_ce, SL("httpPrefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * http 后缀
	 * 
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_router_url_ce, SL("httpSuffix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 生成 url 默认配置
	 * 
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_router_url_ce, SL("makeOption"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_router_url_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_router_url_ce->create_object = zephir_init_properties_Queryyetsimple_Router_Url;

	zend_class_implements(queryyetsimple_router_url_ce TSRMLS_CC, 1, queryyetsimple_router_iurl_ce);
	zend_class_implements(queryyetsimple_router_url_ce TSRMLS_CC, 1, queryyetsimple_option_iclass_ce);
	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param \Queryyetsimple\Http\IRequest $request
 * @param array $option
 * @return void
 */
PHP_METHOD(Queryyetsimple_Router_Url, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *request, request_sub, *option_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	zephir_update_property_zval(this_ptr, SL("request"), request);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "options", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 生成路由地址
 *
 * @param string $url
 * @param array $params
 * @param array $option
 * @sub boolean suffix 是否包含后缀
 * @sub boolean normal 是否为普通 url
 * @sub string subdomain 子域名
 * @return string
 */
PHP_METHOD(Queryyetsimple_Router_Url, make) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, option;
	zval *url_param = NULL, *params_param = NULL, *option_param = NULL, custom, result, _0, _1, _2, _3, _4, _14, _15, _5$$3, _6$$3, _7$$3, _8$$3, _9$$6, _10$$6, _11$$6, _12$$6, _13$$7;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&custom);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &url_param, &params_param, &option_param);

	zephir_get_strval(&url, url_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("makeOption"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &option TSRMLS_CC);
	ZEPHIR_CPY_WRT(&option, &_0);
	ZEPHIR_CALL_METHOD(&custom, this_ptr, "iscustom", NULL, 0, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "parsemvc", NULL, 0, &url, &params, &custom);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("parseMvc"), &_2);
	zephir_array_fetch_string(&_4, &option, SL("normal"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 122 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "isnotnormal", NULL, 0, &_4, &custom);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(&custom)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "pathinfourl", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "customurl", NULL, 0, &url);
			zephir_check_call_status();
		}
		zephir_array_fetch_string(&_6$$3, &option, SL("suffix"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 129 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "withsuffix", NULL, 0, &result, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&result, &_5$$3);
		zephir_read_property(&_7$$3, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_8$$3, &_7$$3, SL("params"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 131 TSRMLS_CC);
		if (zephir_is_true(&_8$$3)) {
			zephir_read_property(&_9$$6, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_10$$6, &_9$$6, SL("params"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 132 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_11$$6, "http_build_query", NULL, 105, &_10$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_12$$6);
			ZEPHIR_CONCAT_SV(&_12$$6, "?", &_11$$6);
			zephir_concat_self(&result, &_12$$6 TSRMLS_CC);
		}
	} else {
		zephir_array_fetch_string(&_13$$7, &option, SL("normal"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 135 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&result, this_ptr, "normalurl", NULL, 0, &_13$$7);
		zephir_check_call_status();
	}
	zephir_array_fetch_string(&_15, &option, SL("subdomain"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 138 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "urlwithdomain", NULL, 0, &result, &_15);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&result, &_14);
	RETURN_CCTOR(&result);

}

/**
 * 返回 HTTP 请求
 * 
 * @return \Queryyetsimple\Http\IRequest
 */
PHP_METHOD(Queryyetsimple_Router_Url, getRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "request");

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Router_Url, option) {

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
		_1$$3 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Router\\InvalidArgumentException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_0$$3, _1$$3);
		if (zephir_has_constructor(&_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Option set name must be a string.");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_2$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_0$$3, "queryyetsimple/router/url.zep", 163 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Router_Url, optionArray) {

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
PHP_METHOD(Queryyetsimple_Router_Url, options) {

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
	zephir_is_iterable(&option, 0, "queryyetsimple/router/url.zep", 202);
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
PHP_METHOD(Queryyetsimple_Router_Url, getOption) {

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
		zephir_array_fetch(&_0, &_2, &name, PH_NOISY, "queryyetsimple/router/url.zep", 214 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_Router_Url, getOptions) {

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
PHP_METHOD(Queryyetsimple_Router_Url, deleteOption) {

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
PHP_METHOD(Queryyetsimple_Router_Url, deleteOptions) {

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
	zephir_is_iterable(&option, 0, "queryyetsimple/router/url.zep", 265);
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
 * pathinfo url 解析
 * 
 * @return string
 */
PHP_METHOD(Queryyetsimple_Router_Url, pathinfoUrl) {

	zend_bool _19;
	zval url, _0, _1, _2, _3, _5, _6, _7, _8, _18, _20, _23, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3, _15$$3, _16$$3, _17$$3, _21$$4, _22$$4, _24$$5, _25$$5, _26$$5;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseenter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "app");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "equaldefault", &_4, 0, &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		zephir_read_property(&_5, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_6, &_5, SL("app"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 277 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_1);
		ZEPHIR_CONCAT_SVS(&_1, "/", &_6, "/");
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "/");
	}
	ZEPHIR_INIT_VAR(&url);
	ZEPHIR_CONCAT_VV(&url, &_0, &_1);
	zephir_read_property(&_7, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_8, &_7, SL("prefix"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 279 TSRMLS_CC);
	if (zephir_is_true(&_8)) {
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_read_property(&_10$$3, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_11$$3, &_10$$3, SL("prefix"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 280 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_12$$3);
		ZVAL_STRING(&_12$$3, "\\");
		ZEPHIR_INIT_VAR(&_13$$3);
		ZVAL_STRING(&_13$$3, "/");
		zephir_fast_str_replace(&_9$$3, &_12$$3, &_13$$3, &_11$$3 TSRMLS_CC);
		zephir_read_property(&_14$$3, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_15$$3, &_14$$3, SL("action"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 280 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_16$$3);
		ZEPHIR_CONCAT_VSV(&_16$$3, &_9$$3, "/", &_15$$3);
		ZEPHIR_INIT_VAR(&_17$$3);
		ZVAL_STRING(&_17$$3, "action");
		zephir_update_property_array(this_ptr, SL("parseMvc"), &_17$$3, &_16$$3 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "controller");
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "equaldefault", &_4, 0, &_3);
	zephir_check_call_status();
	_19 = !zephir_is_true(&_18);
	if (!(_19)) {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "action");
		ZEPHIR_CALL_METHOD(&_20, this_ptr, "equaldefault", &_4, 0, &_3);
		zephir_check_call_status();
		_19 = !zephir_is_true(&_20);
	}
	if (_19) {
		zephir_read_property(&_21$$4, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_22$$4, &_21$$4, SL("controller"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 284 TSRMLS_CC);
		zephir_concat_self(&url, &_22$$4 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "action");
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "equaldefault", &_4, 0, &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(&_23))) {
		zephir_read_property(&_24$$5, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_25$$5, &_24$$5, SL("action"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 288 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_26$$5);
		ZEPHIR_CONCAT_SV(&_26$$5, "/", &_25$$5);
		zephir_concat_self(&url, &_26$$5 TSRMLS_CC);
	}
	RETURN_CCTOR(&url);

}

/**
 * 自定义 URL
 * 
 * @param string $url
 * @return string
 */
PHP_METHOD(Queryyetsimple_Router_Url, customUrl) {

	zend_string *_13$$5;
	zend_ulong _12$$5;
	zval _4$$3;
	zend_class_entry *_3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, result, tmp, k, v, tmpQuery, _0, _1, _6, _7, _2$$3, _5$$3, _8$$5, _9$$5, _10$$5, *_11$$5, _14$$5;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&tmpQuery);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "{");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &url, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		_3$$3 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_4$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "matchVar");
		zephir_array_fast_append(&_4$$3, &_5$$3);
		ZEPHIR_CALL_CE_STATIC(&_2$$3, _3$$3, "fromcallable", NULL, 0, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "/{(.+?)}/");
		ZEPHIR_CALL_FUNCTION(&result, "preg_replace_callback", NULL, 106, &_5$$3, &_2$$3, &url);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&result, &url);
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "?");
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_strpos(&_7, &result, &_6, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_7)) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_fast_explode_str(&tmp, SL("?"), &result, LONG_MAX TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&result);
		zephir_array_fetch_long(&result, &tmp, 0, PH_NOISY, "queryyetsimple/router/url.zep", 312 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&tmpQuery);
		array_init(&tmpQuery);
		zephir_array_fetch_long(&_8$$5, &tmp, 1, PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 315 TSRMLS_CC);
		ZEPHIR_MAKE_REF(&tmpQuery);
		ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 83, &_8$$5, &tmpQuery);
		ZEPHIR_UNREF(&tmpQuery);
		zephir_check_call_status();
		zephir_read_property(&_9$$5, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_10$$5, &_9$$5, SL("params"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 317 TSRMLS_CC);
		zephir_is_iterable(&_10$$5, 0, "queryyetsimple/router/url.zep", 321);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_10$$5), _12$$5, _13$$5, _11$$5)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_13$$5 != NULL) { 
				ZVAL_STR_COPY(&k, _13$$5);
			} else {
				ZVAL_LONG(&k, _12$$5);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _11$$5);
			zephir_array_update_zval(&tmpQuery, &k, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
		ZEPHIR_INIT_VAR(&_14$$5);
		ZVAL_STRING(&_14$$5, "params");
		zephir_update_property_array(this_ptr, SL("parseMvc"), &_14$$5, &tmpQuery TSRMLS_CC);
	}
	RETURN_CCTOR(&result);

}

/**
 * 匹配 URL 变量
 * 
 * @param array $match
 * @return string
 */
PHP_METHOD(Queryyetsimple_Router_Url, matchVar) {

	zval *matchs, matchs_sub, result, params, key, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matchs_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matchs);



	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	zephir_read_property(&_0, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_NVAR(&params);
	zephir_array_fetch_string(&params, &_0, SL("params"), PH_NOISY, "queryyetsimple/router/url.zep", 336 TSRMLS_CC);
	zephir_array_fetch_long(&key, matchs, 1, PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 337 TSRMLS_CC);
	zephir_array_fetch_long(&_1, matchs, 1, PH_READONLY, "queryyetsimple/router/url.zep", 339 TSRMLS_CC);
	if (zephir_array_isset(&params, &_1)) {
		ZEPHIR_OBS_VAR(&result);
		zephir_array_fetch(&result, &params, &key, PH_NOISY, "queryyetsimple/router/url.zep", 340 TSRMLS_CC);
		zephir_array_unset(&params, &key, PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&result);
		zephir_array_fetch_long(&result, matchs, 0, PH_NOISY, "queryyetsimple/router/url.zep", 343 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "params");
	zephir_update_property_array(this_ptr, SL("parseMvc"), &_2, &params TSRMLS_CC);
	RETURN_CCTOR(&result);

}

/**
 * 普通 url 生成
 * 
 * @param bool $normal
 * @return string
 */
PHP_METHOD(Queryyetsimple_Router_Url, normalUrl) {

	zend_string *_19;
	zend_ulong _18;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *normal_param = NULL, querys, params, key, val, url, _1, _2, _6, _9, _12, _13, _16, *_17, _20, _21, _22, _23, _4$$3, _5$$3, _7$$4, _8$$4, _10$$5, _11$$5, _14$$6, _15$$6;
	zend_bool normal, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&querys);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &normal_param);

	normal = zephir_get_boolval(normal_param);


	ZEPHIR_INIT_VAR(&querys);
	array_init(&querys);
	_0 = normal;
	if (!(_0)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "app");
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "equaldefault", &_3, 0, &_2);
		zephir_check_call_status();
		_0 = !zephir_is_true(&_1);
	}
	if (_0) {
		zephir_read_property(&_4$$3, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_5$$3, &_4$$3, SL("app"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 364 TSRMLS_CC);
		zephir_array_update_string(&querys, SL("_app"), &_5$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "controller");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "equaldefault", &_3, 0, &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(&_6))) {
		zephir_read_property(&_7$$4, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_8$$4, &_7$$4, SL("controller"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 368 TSRMLS_CC);
		zephir_array_update_string(&querys, SL("_c"), &_8$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "action");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "equaldefault", &_3, 0, &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(&_9))) {
		zephir_read_property(&_10$$5, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_11$$5, &_10$$5, SL("action"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 372 TSRMLS_CC);
		zephir_array_update_string(&querys, SL("_a"), &_11$$5, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_12, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_13, &_12, SL("prefix"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 375 TSRMLS_CC);
	if (zephir_is_true(&_13)) {
		zephir_read_property(&_14$$6, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_15$$6, &_14$$6, SL("prefix"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 376 TSRMLS_CC);
		zephir_array_update_string(&querys, SL("_prefix"), &_15$$6, PH_COPY | PH_SEPARATE);
	}
	zephir_read_property(&_16, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&params);
	zephir_array_fetch_string(&params, &_16, SL("params"), PH_NOISY, "queryyetsimple/router/url.zep", 379 TSRMLS_CC);
	zephir_is_iterable(&params, 0, "queryyetsimple/router/url.zep", 385);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _18, _19, _17)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_19 != NULL) { 
			ZVAL_STR_COPY(&key, _19);
		} else {
			ZVAL_LONG(&key, _18);
		}
		ZEPHIR_INIT_NVAR(&val);
		ZVAL_COPY(&val, _17);
		zephir_array_update_zval(&querys, &key, &val, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	if (normal) {
		ZVAL_BOOL(&_21, 1);
	} else {
		ZVAL_BOOL(&_21, 0);
	}
	ZEPHIR_CALL_METHOD(&_20, this_ptr, "parseenter", NULL, 0, &_21);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_22);
	if (zephir_is_true(&querys)) {
		ZEPHIR_CALL_FUNCTION(&_23, "http_build_query", NULL, 105, &querys);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_22);
		ZEPHIR_CONCAT_SV(&_22, "?", &_23);
	} else {
		ZEPHIR_INIT_NVAR(&_22);
		ZVAL_STRING(&_22, "");
	}
	ZEPHIR_INIT_VAR(&url);
	ZEPHIR_CONCAT_VV(&url, &_20, &_22);
	RETURN_CCTOR(&url);

}

/**
 * 解析 MVC 参数
 * 
 * @param string $url
 * @param array $params
 * @param bool $custom
 * @return array
 */
PHP_METHOD(Queryyetsimple_Router_Url, parseMvc) {

	zend_string *_15, *_38$$17;
	zend_ulong _14, _37$$17;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool custom;
	zval params;
	zval *url_param = NULL, *params_param = NULL, *custom_param = NULL, tmp, tmp1, parse, result, mvc, key, item, tmpAction, tmpQuery, k, v, _0, _11, _12, *_13, _30, _31, _1$$4, _2$$4, _3$$5, _4$$5, _5$$5, _6$$7, _7$$7, _9$$7, _10$$7, _16$$9, _17$$10, _20$$10, _18$$11, _19$$11, _21$$12, _22$$12, _23$$12, _24$$13, _27$$13, _25$$14, _26$$14, _28$$15, _29$$15, _32$$16, _33$$16, _34$$16, _35$$17, *_36$$17;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tmp1);
	ZVAL_UNDEF(&parse);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&mvc);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&tmpAction);
	ZVAL_UNDEF(&tmpQuery);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &url_param, &params_param, &custom_param);

	zephir_get_strval(&url, url_param);
	zephir_get_arrval(&params, params_param);
	custom = zephir_get_boolval(custom_param);


	if (custom) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_create_array(&tmp, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&tmp, SL("params"), &params, PH_COPY | PH_SEPARATE);
		RETURN_CCTOR(&tmp);
	}
	ZEPHIR_INIT_VAR(&tmp1);
	zephir_create_array(&tmp1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/");
	zephir_array_fast_append(&tmp1, &_0);
	if (!(zephir_fast_in_array(&url, &tmp1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "://");
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_fast_strpos(&_2$$4, &url, &_1$$4, 0 );
		if (!(zephir_is_true(&_2$$4))) {
			zephir_read_property(&_3$$5, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_4$$5, &_3$$5, "app", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_5$$5);
			ZEPHIR_CONCAT_VSV(&_5$$5, &_4$$5, "://", &url);
			zephir_get_strval(&url, &_5$$5);
		}
		ZEPHIR_CALL_FUNCTION(&parse, "parse_url", NULL, 107, &url);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&parse);
		array_init(&parse);
	}
	ZEPHIR_INIT_VAR(&result);
	zephir_create_array(&result, 5, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&result, SL("app"), SL(""));
	add_assoc_stringl_ex(&result, SL("controller"), SL(""));
	add_assoc_stringl_ex(&result, SL("action"), SL(""));
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	zephir_array_update_string(&result, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&result, SL("prefix"), SL(""));
	if (ZEPHIR_IS_STRING_IDENTICAL(&url, "/")) {
		ZEPHIR_INIT_VAR(&_7$$7);
		ZVAL_STRING(&_7$$7, "default_app");
		ZEPHIR_CALL_METHOD(&_6$$7, this_ptr, "getoption", &_8, 0, &_7$$7);
		zephir_check_call_status();
		zephir_array_update_string(&result, SL("app"), &_6$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_7$$7);
		ZVAL_STRING(&_7$$7, "default_controller");
		ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "getoption", &_8, 0, &_7$$7);
		zephir_check_call_status();
		zephir_array_update_string(&result, SL("controller"), &_9$$7, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_7$$7);
		ZVAL_STRING(&_7$$7, "default_action");
		ZEPHIR_CALL_METHOD(&_10$$7, this_ptr, "getoption", &_8, 0, &_7$$7);
		zephir_check_call_status();
		zephir_array_update_string(&result, SL("action"), &_10$$7, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_11);
	if (zephir_array_isset_string(&parse, SL("scheme"))) {
		ZEPHIR_OBS_NVAR(&_11);
		zephir_array_fetch_string(&_11, &parse, SL("scheme"), PH_NOISY, "queryyetsimple/router/url.zep", 439 TSRMLS_CC);
	} else {
		zephir_read_property(&_12, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_11, &_12, "app", NULL, 0);
		zephir_check_call_status();
	}
	zephir_array_update_string(&result, SL("app"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&mvc);
	zephir_create_array(&mvc, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&mvc, SL("_app"), SL("app"));
	add_assoc_stringl_ex(&mvc, SL("_c"), SL("controller"));
	add_assoc_stringl_ex(&mvc, SL("_a"), SL("action"));
	zephir_is_iterable(&mvc, 0, "queryyetsimple/router/url.zep", 454);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&mvc), _14, _15, _13)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_15 != NULL) { 
			ZVAL_STR_COPY(&key, _15);
		} else {
			ZVAL_LONG(&key, _14);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _13);
		if (zephir_array_isset(&params, &key)) {
			zephir_array_fetch(&_16$$9, &params, &key, PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 449 TSRMLS_CC);
			zephir_array_update_zval(&result, &item, &_16$$9, PH_COPY | PH_SEPARATE);
			zephir_array_unset(&params, &key, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	if (zephir_array_isset_string(&parse, SL("path"))) {
		zephir_array_fetch_string(&_17$$10, &result, SL("controller"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 455 TSRMLS_CC);
		if (!(zephir_is_true(&_17$$10))) {
			ZEPHIR_INIT_VAR(&_18$$11);
			if (zephir_array_isset_string(&parse, SL("host"))) {
				ZEPHIR_OBS_NVAR(&_18$$11);
				zephir_array_fetch_string(&_18$$11, &parse, SL("host"), PH_NOISY, "queryyetsimple/router/url.zep", 456 TSRMLS_CC);
			} else {
				zephir_read_property(&_19$$11, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_18$$11, &_19$$11, "controller", NULL, 0);
				zephir_check_call_status();
			}
			zephir_array_update_string(&result, SL("controller"), &_18$$11, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_string(&_20$$10, &result, SL("action"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 459 TSRMLS_CC);
		if (!(zephir_is_true(&_20$$10))) {
			zephir_array_fetch_string(&_21$$12, &parse, SL("path"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 460 TSRMLS_CC);
			ZVAL_LONG(&_22$$12, 1);
			ZEPHIR_INIT_VAR(&_23$$12);
			zephir_substr(&_23$$12, &_21$$12, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_array_update_string(&result, SL("action"), &_23$$12, PH_COPY | PH_SEPARATE);
		}
	} else {
		zephir_array_fetch_string(&_24$$13, &result, SL("controller"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 463 TSRMLS_CC);
		if (!(zephir_is_true(&_24$$13))) {
			ZEPHIR_INIT_VAR(&_25$$14);
			if (zephir_array_isset_string(&parse, SL("host"))) {
				ZEPHIR_OBS_NVAR(&_25$$14);
				zephir_array_fetch_string(&_25$$14, &parse, SL("host"), PH_NOISY, "queryyetsimple/router/url.zep", 464 TSRMLS_CC);
			} else {
				zephir_read_property(&_26$$14, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_25$$14, &_26$$14, "controller", NULL, 0);
				zephir_check_call_status();
			}
			zephir_array_update_string(&result, SL("controller"), &_25$$14, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_string(&_27$$13, &result, SL("action"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 467 TSRMLS_CC);
		if (!(zephir_is_true(&_27$$13))) {
			zephir_read_property(&_28$$15, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_29$$15, &_28$$15, "action", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_string(&result, SL("action"), &_29$$15, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_array_fetch_string(&_30, &result, SL("action"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 472 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/");
	ZEPHIR_INIT_VAR(&_31);
	zephir_fast_strpos(&_31, &_30, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_31)) {
		zephir_array_fetch_string(&_32$$16, &result, SL("action"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 473 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&tmpAction);
		zephir_fast_explode_str(&tmpAction, SL("/"), &_32$$16, LONG_MAX TSRMLS_CC);
		ZEPHIR_MAKE_REF(&tmpAction);
		ZEPHIR_CALL_FUNCTION(&_33$$16, "array_pop", NULL, 104, &tmpAction);
		ZEPHIR_UNREF(&tmpAction);
		zephir_check_call_status();
		zephir_array_update_string(&result, SL("action"), &_33$$16, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_34$$16);
		zephir_fast_join_str(&_34$$16, SL("\\"), &tmpAction TSRMLS_CC);
		zephir_array_update_string(&result, SL("prefix"), &_34$$16, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string(&parse, SL("query"))) {
		ZEPHIR_INIT_VAR(&tmpQuery);
		array_init(&tmpQuery);
		zephir_array_fetch_string(&_35$$17, &parse, SL("query"), PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 480 TSRMLS_CC);
		ZEPHIR_MAKE_REF(&tmpQuery);
		ZEPHIR_CALL_FUNCTION(NULL, "parse_str", NULL, 83, &_35$$17, &tmpQuery);
		ZEPHIR_UNREF(&tmpQuery);
		zephir_check_call_status();
		zephir_is_iterable(&params, 0, "queryyetsimple/router/url.zep", 486);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&params), _37$$17, _38$$17, _36$$17)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_38$$17 != NULL) { 
				ZVAL_STR_COPY(&k, _38$$17);
			} else {
				ZVAL_LONG(&k, _37$$17);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _36$$17);
			zephir_array_update_zval(&tmpQuery, &k, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
		zephir_array_update_string(&result, SL("params"), &tmpQuery, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_string(&result, SL("params"), &params, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&result);

}

/**
 * 返回完整 URL 地址
 *
 * @param string $url
 * @param string $domain
 * @return string
 */
PHP_METHOD(Queryyetsimple_Router_Url, urlWithDomain) {

	zend_bool _3, _5, _13;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *domain_param = NULL, _0, _1, _4, _6, _11, _12, _15, _7$$4, _8$$4, _9$$4, _10$$4;
	zval url, domain, _14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &domain_param);

	zephir_get_strval(&url, url_param);
	zephir_get_strval(&domain, domain_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "make_subdomain_on");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", &_2, 0, &_1);
	zephir_check_call_status();
	_3 = !ZEPHIR_IS_TRUE_IDENTICAL(&_0);
	if (!(_3)) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "router_domain_top");
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getoption", &_2, 0, &_1);
		zephir_check_call_status();
		_3 = !zephir_is_true(&_4);
	}
	_5 = _3;
	if (!(_5)) {
		_5 = ZEPHIR_IS_EMPTY(&domain);
	}
	if (_5) {
		RETURN_CTOR(&url);
	}
	zephir_read_property(&_6, this_ptr, SL("httpPrefix"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_6) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "issecure", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_8$$4)) {
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "https://");
		} else {
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "http://");
		}
		zephir_update_property_zval(this_ptr, SL("httpPrefix"), &_7$$4);
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "router_domain_top");
		ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "getoption", &_2, 0, &_10$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("httpSuffix"), &_9$$4);
	}
	zephir_read_property(&_11, this_ptr, SL("httpPrefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_12);
	_13 = zephir_is_true(&domain);
	if (_13) {
		_13 = !ZEPHIR_IS_STRING(&domain, "*");
	}
	if (_13) {
		ZEPHIR_INIT_VAR(&_14);
		ZEPHIR_CONCAT_VS(&_14, &domain, ".");
		ZEPHIR_CPY_WRT(&_12, &_14);
	} else {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_STRING(&_12, "");
	}
	zephir_read_property(&_15, this_ptr, SL("httpSuffix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VVVV(return_value, &_11, &_12, &_15, &url);
	RETURN_MM();

}

/**
 * 是否启用 https
 *
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Router_Url, isSecure) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "issecure", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否非默认 url
 * 
 * @param bool $normal
 * @param bool $custom
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Router_Url, isNotNormal) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *normal_param = NULL, *custom_param = NULL, _0, _1;
	zend_bool normal, custom, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &normal_param, &custom_param);

	normal = zephir_get_boolval(normal_param);
	custom = zephir_get_boolval(custom_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "model");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_STRING(&_0, "pathinfo");
	if (_2) {
		_2 = normal == 0;
	}
	_3 = _2;
	if (!(_3)) {
		_3 = custom == 1;
	}
	RETURN_MM_BOOL(_3);

}

/**
 * url 带后缀
 * 
 * @param string $url
 * @param string|boolean $suffix
 * @return string
 */
PHP_METHOD(Queryyetsimple_Router_Url, withSuffix) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *suffix, suffix_sub, _2$$3, _3$$3;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&suffix_sub);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &suffix);

	zephir_get_strval(&url, url_param);


	_0 = zephir_is_true(suffix);
	if (_0) {
		_0 = zephir_is_true(&url);
	}
	_1 = _0;
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(&url, "/");
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$3);
		if (ZEPHIR_IS_TRUE_IDENTICAL(suffix)) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "html_suffix");
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getoption", NULL, 0, &_3$$3);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&_2$$3, suffix);
		}
		zephir_concat_self(&url, &_2$$3 TSRMLS_CC);
	}
	RETURN_CTOR(&url);

}

/**
 * 是否为默认 app、controller 或则 action
 * 
 * @param string $type
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Router_Url, equalDefault) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, _0, _2, _3;
	zval type, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "default_", &type);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &type, PH_NOISY | PH_READONLY, "queryyetsimple/router/url.zep", 566 TSRMLS_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_0, &_3));

}

/**
 * 分析入口文件
 * 
 * @param boolean $normal
 * @return string
 */
PHP_METHOD(Queryyetsimple_Router_Url, parseEnter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *normal_param = NULL, enter, _0, _1;
	zend_bool normal, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&enter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &normal_param);

	if (!normal_param) {
		normal = 0;
	} else {
		normal = zephir_get_boolval(normal_param);
	}


	zephir_read_property(&_0, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&enter, &_0, "getenter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	_2 = normal == 1;
	if (!(_2)) {
		_2 = !ZEPHIR_IS_STRING_IDENTICAL(&enter, "/");
	}
	if (_2) {
		ZEPHIR_CPY_WRT(&_1, &enter);
	} else {
		ZVAL_STRING(&_1, "");
	}
	RETURN_CCTOR(&_1);

}

/**
 * 以 “/” 开头的为自定义 URL
 * 
 * @param string $url
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Router_Url, isCustom) {

	zend_bool _0;
	zval *url_param = NULL, _1, _2;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&url, "/");
	if (_0) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "/");
		ZEPHIR_INIT_VAR(&_2);
		zephir_fast_strpos(&_2, &url, &_1, 0 );
		_0 = ZEPHIR_IS_LONG_IDENTICAL(&_2, 0);
	}
	RETURN_MM_BOOL(_0);

}

zend_object *zephir_init_properties_Queryyetsimple_Router_Url(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _3$$4;
	zval __$true, __$false, _0, _2, _4, _5$$5;
		ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 7, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("default_app"), SL("home"));
			add_assoc_stringl_ex(&_1$$3, SL("default_controller"), SL("index"));
			add_assoc_stringl_ex(&_1$$3, SL("default_action"), SL("index"));
			add_assoc_stringl_ex(&_1$$3, SL("model"), SL("pathinfo"));
			add_assoc_stringl_ex(&_1$$3, SL("html_suffix"), SL(".html"));
			add_assoc_stringl_ex(&_1$$3, SL("router_domain_top"), SL(""));
			zephir_array_update_string(&_1$$3, SL("make_subdomain_on"), &__$true, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("makeOption"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 3, 0 TSRMLS_CC);
			zephir_array_update_string(&_3$$4, SL("suffix"), &__$true, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3$$4, SL("normal"), &__$false, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_3$$4, SL("subdomain"), SL("www"));
			zephir_update_property_zval(this_ptr, SL("makeOption"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("parseMvc"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("parseMvc"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

