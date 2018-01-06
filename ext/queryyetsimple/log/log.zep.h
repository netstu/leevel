
extern zend_class_entry *queryyetsimple_log_log_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Log);

PHP_METHOD(Queryyetsimple_Log_Log, __construct);
PHP_METHOD(Queryyetsimple_Log_Log, emergency);
PHP_METHOD(Queryyetsimple_Log_Log, alert);
PHP_METHOD(Queryyetsimple_Log_Log, critical);
PHP_METHOD(Queryyetsimple_Log_Log, error);
PHP_METHOD(Queryyetsimple_Log_Log, warning);
PHP_METHOD(Queryyetsimple_Log_Log, notice);
PHP_METHOD(Queryyetsimple_Log_Log, info);
PHP_METHOD(Queryyetsimple_Log_Log, debug);
PHP_METHOD(Queryyetsimple_Log_Log, log);
PHP_METHOD(Queryyetsimple_Log_Log, write);
PHP_METHOD(Queryyetsimple_Log_Log, save);
PHP_METHOD(Queryyetsimple_Log_Log, registerFilter);
PHP_METHOD(Queryyetsimple_Log_Log, registerProcessor);
PHP_METHOD(Queryyetsimple_Log_Log, clear);
PHP_METHOD(Queryyetsimple_Log_Log, get);
PHP_METHOD(Queryyetsimple_Log_Log, count);
PHP_METHOD(Queryyetsimple_Log_Log, option);
PHP_METHOD(Queryyetsimple_Log_Log, optionArray);
PHP_METHOD(Queryyetsimple_Log_Log, options);
PHP_METHOD(Queryyetsimple_Log_Log, getOption);
PHP_METHOD(Queryyetsimple_Log_Log, getOptions);
PHP_METHOD(Queryyetsimple_Log_Log, deleteOption);
PHP_METHOD(Queryyetsimple_Log_Log, deleteOptions);
PHP_METHOD(Queryyetsimple_Log_Log, saveStore);
PHP_METHOD(Queryyetsimple_Log_Log, formatMessage);
PHP_METHOD(Queryyetsimple_Log_Log, __call);
zend_object *zephir_init_properties_Queryyetsimple_Log_Log(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, oConnect, Queryyetsimple\\Log\\Iconnect, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, mixMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
	ZEND_ARG_INFO(0, booWrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, mixMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
	ZEND_ARG_INFO(0, booWrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, mixMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
	ZEND_ARG_INFO(0, booWrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_error, 0, 0, 1)
	ZEND_ARG_INFO(0, mixMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
	ZEND_ARG_INFO(0, booWrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, mixMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
	ZEND_ARG_INFO(0, booWrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, mixMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
	ZEND_ARG_INFO(0, booWrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_info, 0, 0, 1)
	ZEND_ARG_INFO(0, mixMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
	ZEND_ARG_INFO(0, booWrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, mixMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
	ZEND_ARG_INFO(0, booWrite)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_log, 0, 0, 2)
	ZEND_ARG_INFO(0, strLevel)
	ZEND_ARG_INFO(0, mixMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_write, 0, 0, 2)
	ZEND_ARG_INFO(0, strLevel)
	ZEND_ARG_INFO(0, strMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_registerfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, calFilter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_registerprocessor, 0, 0, 1)
	ZEND_ARG_INFO(0, calProcessor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_get, 0, 0, 0)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_count, 0, 0, 0)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_option, 0, 0, 2)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_ARRAY_INFO(0, arrValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_INFO(0, mixDefault)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_savestore, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log_formatmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, mixMessage)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_log___call, 0, 0, 2)
	ZEND_ARG_INFO(0, sMethod)
	ZEND_ARG_ARRAY_INFO(0, arrArgs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_log_method_entry) {
	PHP_ME(Queryyetsimple_Log_Log, __construct, arginfo_queryyetsimple_log_log___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Log_Log, emergency, arginfo_queryyetsimple_log_log_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, alert, arginfo_queryyetsimple_log_log_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, critical, arginfo_queryyetsimple_log_log_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, error, arginfo_queryyetsimple_log_log_error, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, warning, arginfo_queryyetsimple_log_log_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, notice, arginfo_queryyetsimple_log_log_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, info, arginfo_queryyetsimple_log_log_info, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, debug, arginfo_queryyetsimple_log_log_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, log, arginfo_queryyetsimple_log_log_log, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, write, arginfo_queryyetsimple_log_log_write, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, registerFilter, arginfo_queryyetsimple_log_log_registerfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, registerProcessor, arginfo_queryyetsimple_log_log_registerprocessor, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, clear, arginfo_queryyetsimple_log_log_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, get, arginfo_queryyetsimple_log_log_get, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, count, arginfo_queryyetsimple_log_log_count, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, option, arginfo_queryyetsimple_log_log_option, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, optionArray, arginfo_queryyetsimple_log_log_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, options, arginfo_queryyetsimple_log_log_options, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, getOption, arginfo_queryyetsimple_log_log_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, getOptions, arginfo_queryyetsimple_log_log_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, deleteOption, arginfo_queryyetsimple_log_log_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, deleteOptions, arginfo_queryyetsimple_log_log_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Log, saveStore, arginfo_queryyetsimple_log_log_savestore, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Log, formatMessage, arginfo_queryyetsimple_log_log_formatmessage, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Log, __call, arginfo_queryyetsimple_log_log___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
