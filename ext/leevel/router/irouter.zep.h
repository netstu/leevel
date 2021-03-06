
extern zend_class_entry *leevel_router_irouter_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_IRouter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_dispatch, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_setmatcheddata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, matchedData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_throughmiddleware, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, passed, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_ARRAY_INFO(0, passedExtend, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_setcontrollerdir, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_setrouters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, routers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_setbasepaths, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, basepaths, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_addbasepaths, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, basepaths, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_setgroups, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, groups, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_addgroups, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, groups, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_setmiddlewaregroups, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middlewareGroups, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_setglobalmiddlewares, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middlewares, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_setmiddlewarealias, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middlewareAlias, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_irouter_matchepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_irouter_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, dispatch, arginfo_leevel_router_irouter_dispatch)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, initRequest, NULL)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, setMatchedData, arginfo_leevel_router_irouter_setmatcheddata)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, throughMiddleware, arginfo_leevel_router_irouter_throughmiddleware)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, setControllerDir, arginfo_leevel_router_irouter_setcontrollerdir)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, getControllerDir, NULL)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, setRouters, arginfo_leevel_router_irouter_setrouters)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, getRouters, NULL)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, setBasepaths, arginfo_leevel_router_irouter_setbasepaths)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, addBasepaths, arginfo_leevel_router_irouter_addbasepaths)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, getBasepaths, NULL)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, setGroups, arginfo_leevel_router_irouter_setgroups)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, addGroups, arginfo_leevel_router_irouter_addgroups)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, getGroups, NULL)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, setMiddlewareGroups, arginfo_leevel_router_irouter_setmiddlewaregroups)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, getMiddlewareGroups, NULL)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, setGlobalMiddlewares, arginfo_leevel_router_irouter_setglobalmiddlewares)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, getGlobalMiddlewares, NULL)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, setMiddlewareAlias, arginfo_leevel_router_irouter_setmiddlewarealias)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, getMiddlewareAlias, NULL)
	PHP_ABSTRACT_ME(Leevel_Router_IRouter, matchePath, arginfo_leevel_router_irouter_matchepath)
	PHP_FE_END
};
