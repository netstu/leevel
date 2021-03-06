
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * 路由解析接口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.08
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_IRouter) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Router, IRouter, leevel, router_irouter, leevel_router_irouter_method_entry);

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

/**
 * 分发请求到路由.
 *
 * @param \Leevel\Http\IRequest $request
 *
 * @return \Leevel\Http\IResponse
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, dispatch);

/**
 * 初始化请求
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, initRequest);

/**
 * 设置匹配路由
 * 绕过路由解析，可以用于高性能 RPC 快速匹配资源.
 *
 * @param array $matchedData
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, setMatchedData);

/**
 * 穿越中间件.
 *
 * @param \Leevel\Http\IRequest $passed
 * @param array                 $passedExtend
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, throughMiddleware);

/**
 * 设置控制器相对目录.
 *
 * @param string $controllerDir
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, setControllerDir);

/**
 * 返回控制器相对目录.
 *
 * @param string $controllerDir
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, getControllerDir);

/**
 * 设置路由.
 *
 * @param array $routers
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, setRouters);

/**
 * 取得当前路由.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, getRouters);

/**
 * 设置基础路径.
 *
 * @param array $basepaths
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, setBasepaths);

/**
 * 添加基础路径.
 *
 * @param array $basepaths
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, addBasepaths);

/**
 * 取得基础路径.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, getBasepaths);

/**
 * 设置路由分组.
 *
 * @param array $groups
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, setGroups);

/**
 * 添加路由分组.
 *
 * @param array $groups
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, addGroups);

/**
 * 取得路由分组.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, getGroups);

/**
 * 设置中间件分组.
 *
 * @param array $middlewareGroups
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, setMiddlewareGroups);

/**
 * 取得中间件分组.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, getMiddlewareGroups);

/**
 * 设置全局中间件.
 *
 * @param array $middlewares
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, setGlobalMiddlewares);

/**
 * 取得全局中间件.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, getGlobalMiddlewares);

/**
 * 设置中间件别名.
 *
 * @param array $middlewareAlias
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, setMiddlewareAlias);

/**
 * 取得中间件别名.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, getMiddlewareAlias);

/**
 * 匹配路径.
 *
 * @param string $path
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IRouter, matchePath);

