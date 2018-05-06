
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * HTTP 请求接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.04
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Http_IRequest) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Http, IRequest, leevel, http_irequest, NULL);

	/**
	 * METHOD_HEAD
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_HEAD"), "HEAD");

	/**
	 * METHOD_GET
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_GET"), "GET");

	/**
	 * METHOD_POST
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_POST"), "POST");

	/**
	 * METHOD_PUT
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_PUT"), "PUT");

	/**
	 * METHOD_PATCH
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_PATCH"), "PATCH");

	/**
	 * METHOD_DELETE
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_DELETE"), "DELETE");

	/**
	 * METHOD_PURGE
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_PURGE"), "PURGE");

	/**
	 * METHOD_OPTIONS
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_OPTIONS"), "OPTIONS");

	/**
	 * METHOD_TRACE
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_TRACE"), "TRACE");

	/**
	 * METHOD_CONNECT
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_CONNECT"), "CONNECT");

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
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("PATHINFO_URL"), "_url");

	/**\
	 * 请求方法伪装
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_METHOD"), "_method");

	/**
	 * AJAX 伪装
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_AJAX"), "_ajax");

	/**
	 * PAJAX 伪装
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_PJAX"), "_pjax");

	/**
	 * JSON 伪装
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_JSON"), "_json");

	/**
	 * 接受 JSON 伪装
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_ACCEPT_JSON"), "_acceptjson");

	return SUCCESS;

}

