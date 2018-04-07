
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IUrl 生成
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.08
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_IUrl) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Router, IUrl, leevel, router_iurl, leevel_router_iurl_method_entry);

	return SUCCESS;

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
ZEPHIR_DOC_METHOD(Leevel_Router_IUrl, make);

/**
 * 返回 HTTP 请求
 * 
 * @return \Leevel\Http\IRequest
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IUrl, getRequest);

