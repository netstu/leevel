
extern zend_class_entry *queryyetsimple_log_manager_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Manager);

PHP_METHOD(Queryyetsimple_Log_Manager, getOptionNamespace);
PHP_METHOD(Queryyetsimple_Log_Manager, createConnect);
PHP_METHOD(Queryyetsimple_Log_Manager, makeConnectFile);
PHP_METHOD(Queryyetsimple_Log_Manager, makeConnectMonolog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_manager_createconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, objConnect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_manager_makeconnectfile, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_manager_makeconnectmonolog, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_manager_method_entry) {
	PHP_ME(Queryyetsimple_Log_Manager, getOptionNamespace, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Manager, createConnect, arginfo_queryyetsimple_log_manager_createconnect, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Manager, makeConnectFile, arginfo_queryyetsimple_log_manager_makeconnectfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Manager, makeConnectMonolog, arginfo_queryyetsimple_log_manager_makeconnectmonolog, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
