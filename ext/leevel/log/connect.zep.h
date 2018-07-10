
extern zend_class_entry *leevel_log_connect_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_Connect);

PHP_METHOD(Leevel_Log_Connect, __construct);
PHP_METHOD(Leevel_Log_Connect, setOption);
PHP_METHOD(Leevel_Log_Connect, checkSize);
PHP_METHOD(Leevel_Log_Connect, getPath);
zend_object *zephir_init_properties_Leevel_Log_Connect(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect_checksize, 0, 0, 1)
	ZEND_ARG_INFO(0, filepath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect_getpath, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_connect_method_entry) {
	PHP_ME(Leevel_Log_Connect, __construct, arginfo_leevel_log_connect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Log_Connect, setOption, arginfo_leevel_log_connect_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Connect, checkSize, arginfo_leevel_log_connect_checksize, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_Connect, getPath, arginfo_leevel_log_connect_getpath, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
