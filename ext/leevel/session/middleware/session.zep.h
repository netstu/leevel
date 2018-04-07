
extern zend_class_entry *leevel_session_middleware_session_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_Middleware_Session);

PHP_METHOD(Leevel_Session_Middleware_Session, __construct);
PHP_METHOD(Leevel_Session_Middleware_Session, handle);
PHP_METHOD(Leevel_Session_Middleware_Session, terminate);
PHP_METHOD(Leevel_Session_Middleware_Session, startSession);
PHP_METHOD(Leevel_Session_Middleware_Session, unregisterFlash);
PHP_METHOD(Leevel_Session_Middleware_Session, setPrevUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_middleware_session___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Leevel\\Session\\Manager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_middleware_session_handle, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, next, Closure, 0)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_middleware_session_terminate, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, next, Closure, 0)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, response, Leevel\\Http\\Response, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_middleware_session_setprevurl, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_middleware_session_method_entry) {
	PHP_ME(Leevel_Session_Middleware_Session, __construct, arginfo_leevel_session_middleware_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Session_Middleware_Session, handle, arginfo_leevel_session_middleware_session_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Middleware_Session, terminate, arginfo_leevel_session_middleware_session_terminate, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Middleware_Session, startSession, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Middleware_Session, unregisterFlash, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Middleware_Session, setPrevUrl, arginfo_leevel_session_middleware_session_setprevurl, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
