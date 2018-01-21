
extern zend_class_entry *queryyetsimple_log_connect_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Connect);

PHP_METHOD(Queryyetsimple_Log_Connect, __construct);
PHP_METHOD(Queryyetsimple_Log_Connect, option);
PHP_METHOD(Queryyetsimple_Log_Connect, optionArray);
PHP_METHOD(Queryyetsimple_Log_Connect, options);
PHP_METHOD(Queryyetsimple_Log_Connect, getOption);
PHP_METHOD(Queryyetsimple_Log_Connect, getOptions);
PHP_METHOD(Queryyetsimple_Log_Connect, deleteOption);
PHP_METHOD(Queryyetsimple_Log_Connect, deleteOptions);
PHP_METHOD(Queryyetsimple_Log_Connect, checkSize);
PHP_METHOD(Queryyetsimple_Log_Connect, getPath);
zend_object *zephir_init_properties_Queryyetsimple_Log_Connect(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect_option, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect_checksize, 0, 0, 1)
	ZEND_ARG_INFO(0, filepath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_connect_getpath, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_connect_method_entry) {
	PHP_ME(Queryyetsimple_Log_Connect, __construct, arginfo_queryyetsimple_log_connect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Log_Connect, option, arginfo_queryyetsimple_log_connect_option, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Connect, optionArray, arginfo_queryyetsimple_log_connect_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Connect, options, arginfo_queryyetsimple_log_connect_options, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Connect, getOption, arginfo_queryyetsimple_log_connect_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Connect, getOptions, arginfo_queryyetsimple_log_connect_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Connect, deleteOption, arginfo_queryyetsimple_log_connect_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Connect, deleteOptions, arginfo_queryyetsimple_log_connect_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Connect, checkSize, arginfo_queryyetsimple_log_connect_checksize, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Connect, getPath, arginfo_queryyetsimple_log_connect_getpath, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
