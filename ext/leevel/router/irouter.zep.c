
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
 *
 * @since 2018.03.08
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_IRouter) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Router, IRouter, leevel, router_irouter, NULL);

	/**
	 * 应用参数名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("APP"), "_app");

	/**
	 * 控制器参数名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("CONTROLLER"), "_c");

	/**
	 * 方法参数名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("ACTION"), "_a");

	/**
	 * 解析参数名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("PARAMS"), "_params");

	/**
	 * 解析变量名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("VARS"), "_vars");

	/**
	 * 解析中间件名
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("MIDDLEWARES"), "_middlewares");

	/**
	 * 控制器前缀
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("PREFIX"), "_prefix");

	/**
	 * 匹配基础路径
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("BASEPATH"), "_basepath");

	/**
	 * restful show
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("RESTFUL_SHOW"), "show");

	/**
	 * restful store
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("RESTFUL_STORE"), "store");

	/**
	 * restful update
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("RESTFUL_UPDATE"), "update");

	/**
	 * restful destroy
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("RESTFUL_DESTROY"), "destroy");

	/**
	 * 默认应用
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("DEFAULT_APP"), "app");

	/**
	 * 默认首页控制器
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("DEFAULT_HOME_CONTROLLER"), "home");

	/**
	 * 默认首页方法
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("DEFAULT_HOME_ACTION"), "handle");

	/**
	 * 默认替换参数[字符串]
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_router_irouter_ce, SL("DEFAULT_REGEX"), "\\S+");

	/**
	 * 默认严格匹配模式
	 *
	 * @var string
	 */
	zephir_declare_class_constant_bool(leevel_router_irouter_ce, SL("DEFAULT_STRICT"), 1);

	return SUCCESS;

}

