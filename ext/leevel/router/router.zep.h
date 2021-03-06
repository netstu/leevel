
extern zend_class_entry *leevel_router_router_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_Router);

PHP_METHOD(Leevel_Router_Router, __construct);
PHP_METHOD(Leevel_Router_Router, dispatch);
PHP_METHOD(Leevel_Router_Router, initRequest);
PHP_METHOD(Leevel_Router_Router, setMatchedData);
PHP_METHOD(Leevel_Router_Router, throughMiddleware);
PHP_METHOD(Leevel_Router_Router, setControllerDir);
PHP_METHOD(Leevel_Router_Router, getControllerDir);
PHP_METHOD(Leevel_Router_Router, setRouters);
PHP_METHOD(Leevel_Router_Router, getRouters);
PHP_METHOD(Leevel_Router_Router, setBasepaths);
PHP_METHOD(Leevel_Router_Router, addBasepaths);
PHP_METHOD(Leevel_Router_Router, getBasepaths);
PHP_METHOD(Leevel_Router_Router, setGroups);
PHP_METHOD(Leevel_Router_Router, addGroups);
PHP_METHOD(Leevel_Router_Router, getGroups);
PHP_METHOD(Leevel_Router_Router, setMiddlewareGroups);
PHP_METHOD(Leevel_Router_Router, getMiddlewareGroups);
PHP_METHOD(Leevel_Router_Router, setGlobalMiddlewares);
PHP_METHOD(Leevel_Router_Router, getGlobalMiddlewares);
PHP_METHOD(Leevel_Router_Router, setMiddlewareAlias);
PHP_METHOD(Leevel_Router_Router, getMiddlewareAlias);
PHP_METHOD(Leevel_Router_Router, matchePath);
PHP_METHOD(Leevel_Router_Router, macro);
PHP_METHOD(Leevel_Router_Router, hasMacro);
PHP_METHOD(Leevel_Router_Router, callStaticMacro);
PHP_METHOD(Leevel_Router_Router, callMacro);
PHP_METHOD(Leevel_Router_Router, normalizePrefix);
PHP_METHOD(Leevel_Router_Router, findApp);
PHP_METHOD(Leevel_Router_Router, normalizePathsAndParams);
PHP_METHOD(Leevel_Router_Router, matchRouter);
PHP_METHOD(Leevel_Router_Router, urlRouterBind);
PHP_METHOD(Leevel_Router_Router, resolveMatchedData);
PHP_METHOD(Leevel_Router_Router, normalizeMatchedData);
PHP_METHOD(Leevel_Router_Router, findRouterBind);
PHP_METHOD(Leevel_Router_Router, normalizeRouterBind);
PHP_METHOD(Leevel_Router_Router, dispatchToRoute);
PHP_METHOD(Leevel_Router_Router, runRoute);
PHP_METHOD(Leevel_Router_Router, nodeNotFound);
PHP_METHOD(Leevel_Router_Router, makeNode);
PHP_METHOD(Leevel_Router_Router, parseControllerDir);
PHP_METHOD(Leevel_Router_Router, completeRequest);
PHP_METHOD(Leevel_Router_Router, pathinfoRestful);
PHP_METHOD(Leevel_Router_Router, parseDefaultBind);
PHP_METHOD(Leevel_Router_Router, parseMiddleware);
PHP_METHOD(Leevel_Router_Router, matchedApp);
PHP_METHOD(Leevel_Router_Router, matchedController);
PHP_METHOD(Leevel_Router_Router, matchedAction);
PHP_METHOD(Leevel_Router_Router, matchedPrefix);
PHP_METHOD(Leevel_Router_Router, matchedParams);
PHP_METHOD(Leevel_Router_Router, matchedMiddlewares);
PHP_METHOD(Leevel_Router_Router, matchedVars);
zend_object *zephir_init_properties_Leevel_Router_Router(zend_class_entry *class_type TSRMLS_DC);
void zephir_init_static_properties_Leevel_Router_Router(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_dispatch, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_setmatcheddata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, matchedData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_throughmiddleware, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, passed, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_ARRAY_INFO(0, passedExtend, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_setcontrollerdir, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_setrouters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, routers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_setbasepaths, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, basepaths, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_addbasepaths, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, basepaths, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_setgroups, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, groups, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_addgroups, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, groups, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_setmiddlewaregroups, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middlewareGroups, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_setglobalmiddlewares, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middlewares, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_setmiddlewarealias, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, middlewareAlias, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_matchepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_macro, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, macro)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_hasmacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_callstaticmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_callmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_normalizeprefix, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, paths, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_findapp, 0, 0, 1)
	ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_normalizepathsandparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_urlrouterbind, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, dataPathInfo, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_resolvematcheddata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_normalizematcheddata, 0, 0, 1)
	ZEND_ARG_INFO(0, matche)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_dispatchtoroute, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_router_runroute, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_INFO(0, bind)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_router_method_entry) {
	PHP_ME(Leevel_Router_Router, __construct, arginfo_leevel_router_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Router_Router, dispatch, arginfo_leevel_router_router_dispatch, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, initRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, setMatchedData, arginfo_leevel_router_router_setmatcheddata, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, throughMiddleware, arginfo_leevel_router_router_throughmiddleware, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, setControllerDir, arginfo_leevel_router_router_setcontrollerdir, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, getControllerDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, setRouters, arginfo_leevel_router_router_setrouters, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, getRouters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, setBasepaths, arginfo_leevel_router_router_setbasepaths, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, addBasepaths, arginfo_leevel_router_router_addbasepaths, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, getBasepaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, setGroups, arginfo_leevel_router_router_setgroups, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, addGroups, arginfo_leevel_router_router_addgroups, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, getGroups, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, setMiddlewareGroups, arginfo_leevel_router_router_setmiddlewaregroups, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, getMiddlewareGroups, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, setGlobalMiddlewares, arginfo_leevel_router_router_setglobalmiddlewares, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, getGlobalMiddlewares, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, setMiddlewareAlias, arginfo_leevel_router_router_setmiddlewarealias, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, getMiddlewareAlias, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, matchePath, arginfo_leevel_router_router_matchepath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, macro, arginfo_leevel_router_router_macro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Router_Router, hasMacro, arginfo_leevel_router_router_hasmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Router_Router, callStaticMacro, arginfo_leevel_router_router_callstaticmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Router_Router, callMacro, arginfo_leevel_router_router_callmacro, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Router, normalizePrefix, arginfo_leevel_router_router_normalizeprefix, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, findApp, arginfo_leevel_router_router_findapp, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, normalizePathsAndParams, arginfo_leevel_router_router_normalizepathsandparams, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, matchRouter, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, urlRouterBind, arginfo_leevel_router_router_urlrouterbind, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, resolveMatchedData, arginfo_leevel_router_router_resolvematcheddata, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, normalizeMatchedData, arginfo_leevel_router_router_normalizematcheddata, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, findRouterBind, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, normalizeRouterBind, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, dispatchToRoute, arginfo_leevel_router_router_dispatchtoroute, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, runRoute, arginfo_leevel_router_router_runroute, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, nodeNotFound, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, makeNode, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, parseControllerDir, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, completeRequest, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, pathinfoRestful, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, parseDefaultBind, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, parseMiddleware, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, matchedApp, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, matchedController, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, matchedAction, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, matchedPrefix, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, matchedParams, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, matchedMiddlewares, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Router, matchedVars, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
