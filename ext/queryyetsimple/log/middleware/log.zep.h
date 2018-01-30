
extern zend_class_entry *queryyetsimple_log_middleware_log_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_middleware_Log);

PHP_METHOD(Queryyetsimple_Log_middleware_Log, __construct);
PHP_METHOD(Queryyetsimple_Log_middleware_Log, terminate);
PHP_METHOD(Queryyetsimple_Log_middleware_Log, saveLog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_middleware_log___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Queryyetsimple\\Log\\Manager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_middleware_log_terminate, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, next, Closure, 0)
	ZEND_ARG_OBJ_INFO(0, request, Queryyetsimple\\Http\\Request, 0)
	ZEND_ARG_OBJ_INFO(0, response, Queryyetsimple\\Http\\Response, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_middleware_log_method_entry) {
	PHP_ME(Queryyetsimple_Log_middleware_Log, __construct, arginfo_queryyetsimple_log_middleware_log___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Log_middleware_Log, terminate, arginfo_queryyetsimple_log_middleware_log_terminate, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_middleware_Log, saveLog, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
