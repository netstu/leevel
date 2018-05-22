
extern zend_class_entry *leevel_bootstrap_bootstrap_registerruntime_ce;

ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Bootstrap_RegisterRuntime);

PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, handle);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, setErrorHandle);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, registerShutdownFunction);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, setExceptionHandler);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, renderConsoleResponse);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, renderHttpResponse);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, formatFatalException);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, getRuntime);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_registerruntime_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, project, Leevel\\Kernel\\IProject, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_registerruntime_seterrorhandle, 0, 0, 2)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, description)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_registerruntime_setexceptionhandler, 0, 0, 1)
	ZEND_ARG_INFO(0, e)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_registerruntime_renderconsoleresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, e, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_registerruntime_renderhttpresponse, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, e, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_registerruntime_formatfatalexception, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, error, 0)
	ZEND_ARG_INFO(0, traceOffset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_bootstrap_bootstrap_registerruntime_method_entry) {
	PHP_ME(Leevel_Bootstrap_Bootstrap_RegisterRuntime, handle, arginfo_leevel_bootstrap_bootstrap_registerruntime_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Bootstrap_RegisterRuntime, setErrorHandle, arginfo_leevel_bootstrap_bootstrap_registerruntime_seterrorhandle, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Bootstrap_RegisterRuntime, registerShutdownFunction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Bootstrap_RegisterRuntime, setExceptionHandler, arginfo_leevel_bootstrap_bootstrap_registerruntime_setexceptionhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Bootstrap_RegisterRuntime, renderConsoleResponse, arginfo_leevel_bootstrap_bootstrap_registerruntime_renderconsoleresponse, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Bootstrap_RegisterRuntime, renderHttpResponse, arginfo_leevel_bootstrap_bootstrap_registerruntime_renderhttpresponse, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Bootstrap_RegisterRuntime, formatFatalException, arginfo_leevel_bootstrap_bootstrap_registerruntime_formatfatalexception, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Bootstrap_RegisterRuntime, getRuntime, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
