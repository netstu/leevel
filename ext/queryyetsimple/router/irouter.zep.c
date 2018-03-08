
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * 路由解析接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.08
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Router_IRouter) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Router, IRouter, queryyetsimple, router_irouter, NULL);

	/**
	 * 应用参数名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_router_irouter_ce, SL("APP"), "_app");

	/**
	 * 控制器参数名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_router_irouter_ce, SL("CONTROLLER"), "_c");

	/**
	 * 方法参数名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_router_irouter_ce, SL("ACTION"), "_a");

	/**
	 * 解析参数名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_router_irouter_ce, SL("PARAMS"), "_params");

	/**
	 * 控制器前缀
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_router_irouter_ce, SL("PREFIX"), "_prefix");

	/**
	 * restful show
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_router_irouter_ce, SL("RESTFUL_SHOW"), "show");

	/**
	 * restful store
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_router_irouter_ce, SL("RESTFUL_STORE"), "store");

	/**
	 * restful update
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_router_irouter_ce, SL("RESTFUL_UPDATE"), "update");

	/**
	 * restful destroy
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_router_irouter_ce, SL("RESTFUL_DESTROY"), "destroy");

	return SUCCESS;

}

