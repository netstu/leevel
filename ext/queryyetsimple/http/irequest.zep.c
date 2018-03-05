
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
ZEPHIR_INIT_CLASS(Queryyetsimple_Http_IRequest) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Http, IRequest, queryyetsimple, http_irequest, NULL);

	/**
	 * METHOD_HEAD
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_HEAD"), "HEAD");

	/**
	 * METHOD_GET
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_GET"), "GET");

	/**
	 * METHOD_POST
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_POST"), "POST");

	/**
	 * METHOD_PUT
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_PUT"), "PUT");

	/**
	 * METHOD_PATCH
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_PATCH"), "PATCH");

	/**
	 * METHOD_DELETE
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_DELETE"), "DELETE");

	/**
	 * METHOD_PURGE
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_PURGE"), "PURGE");

	/**
	 * METHOD_OPTIONS
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_OPTIONS"), "OPTIONS");

	/**
	 * METHOD_TRACE
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_TRACE"), "TRACE");

	/**
	 * METHOD_CONNECT
	 * 
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_irequest_ce, SL("METHOD_CONNECT"), "CONNECT");

	return SUCCESS;

}

