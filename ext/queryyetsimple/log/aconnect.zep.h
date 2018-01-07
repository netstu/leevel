
extern zend_class_entry *queryyetsimple_log_aconnect_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Aconnect);

PHP_METHOD(Queryyetsimple_Log_Aconnect, __construct);
PHP_METHOD(Queryyetsimple_Log_Aconnect, option);
PHP_METHOD(Queryyetsimple_Log_Aconnect, optionArray);
PHP_METHOD(Queryyetsimple_Log_Aconnect, options);
PHP_METHOD(Queryyetsimple_Log_Aconnect, getOption);
PHP_METHOD(Queryyetsimple_Log_Aconnect, getOptions);
PHP_METHOD(Queryyetsimple_Log_Aconnect, deleteOption);
PHP_METHOD(Queryyetsimple_Log_Aconnect, deleteOptions);
PHP_METHOD(Queryyetsimple_Log_Aconnect, checkSize);
PHP_METHOD(Queryyetsimple_Log_Aconnect, getPath);
zend_object *zephir_init_properties_Queryyetsimple_Log_Aconnect(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect_option, 0, 0, 2)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_ARRAY_INFO(0, arrValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_INFO(0, mixDefault)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect_checksize, 0, 0, 1)
	ZEND_ARG_INFO(0, sFilePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_aconnect_getpath, 0, 0, 0)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_aconnect_method_entry) {
	PHP_ME(Queryyetsimple_Log_Aconnect, __construct, arginfo_queryyetsimple_log_aconnect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Log_Aconnect, option, arginfo_queryyetsimple_log_aconnect_option, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Aconnect, optionArray, arginfo_queryyetsimple_log_aconnect_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Aconnect, options, arginfo_queryyetsimple_log_aconnect_options, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Aconnect, getOption, arginfo_queryyetsimple_log_aconnect_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Aconnect, getOptions, arginfo_queryyetsimple_log_aconnect_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Aconnect, deleteOption, arginfo_queryyetsimple_log_aconnect_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Aconnect, deleteOptions, arginfo_queryyetsimple_log_aconnect_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Aconnect, checkSize, arginfo_queryyetsimple_log_aconnect_checksize, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Aconnect, getPath, arginfo_queryyetsimple_log_aconnect_getpath, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
