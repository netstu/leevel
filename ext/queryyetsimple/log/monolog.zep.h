
extern zend_class_entry *queryyetsimple_log_monolog_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Monolog);

PHP_METHOD(Queryyetsimple_Log_Monolog, __construct);
PHP_METHOD(Queryyetsimple_Log_Monolog, file);
PHP_METHOD(Queryyetsimple_Log_Monolog, dailyFile);
PHP_METHOD(Queryyetsimple_Log_Monolog, syslog);
PHP_METHOD(Queryyetsimple_Log_Monolog, errorLog);
PHP_METHOD(Queryyetsimple_Log_Monolog, monolog);
PHP_METHOD(Queryyetsimple_Log_Monolog, getMonolog);
PHP_METHOD(Queryyetsimple_Log_Monolog, save);
PHP_METHOD(Queryyetsimple_Log_Monolog, makeFileHandler);
PHP_METHOD(Queryyetsimple_Log_Monolog, makeDailyFileHandler);
PHP_METHOD(Queryyetsimple_Log_Monolog, makeSyslogHandler);
PHP_METHOD(Queryyetsimple_Log_Monolog, makeErrorLogHandler);
PHP_METHOD(Queryyetsimple_Log_Monolog, getDailyFilePath);
PHP_METHOD(Queryyetsimple_Log_Monolog, getDefaultFormatter);
PHP_METHOD(Queryyetsimple_Log_Monolog, parseMonologLevel);
PHP_METHOD(Queryyetsimple_Log_Monolog, camelize);
zend_object *zephir_init_properties_Queryyetsimple_Log_Monolog(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog_file, 0, 0, 1)
	ZEND_ARG_INFO(0, strPath)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog_dailyfile, 0, 0, 1)
	ZEND_ARG_INFO(0, strPath)
	ZEND_ARG_INFO(0, intDays)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog_syslog, 0, 0, 0)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog_errorlog, 0, 0, 0)
	ZEND_ARG_INFO(0, strLevel)
	ZEND_ARG_INFO(0, intMessageType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog_monolog, 0, 0, 0)
	ZEND_ARG_INFO(0, mixCallback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog_save, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog_getdailyfilepath, 0, 0, 1)
	ZEND_ARG_INFO(0, strPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog_parsemonologlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_monolog_camelize, 0, 0, 1)
	ZEND_ARG_INFO(0, strValue)
	ZEND_ARG_INFO(0, strSeparator)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_monolog_method_entry) {
	PHP_ME(Queryyetsimple_Log_Monolog, __construct, arginfo_queryyetsimple_log_monolog___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Log_Monolog, file, arginfo_queryyetsimple_log_monolog_file, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Monolog, dailyFile, arginfo_queryyetsimple_log_monolog_dailyfile, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Monolog, syslog, arginfo_queryyetsimple_log_monolog_syslog, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Monolog, errorLog, arginfo_queryyetsimple_log_monolog_errorlog, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Monolog, monolog, arginfo_queryyetsimple_log_monolog_monolog, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Monolog, getMonolog, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Monolog, save, arginfo_queryyetsimple_log_monolog_save, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_Monolog, makeFileHandler, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Monolog, makeDailyFileHandler, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Monolog, makeSyslogHandler, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Monolog, makeErrorLogHandler, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Monolog, getDailyFilePath, arginfo_queryyetsimple_log_monolog_getdailyfilepath, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Monolog, getDefaultFormatter, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Monolog, parseMonologLevel, arginfo_queryyetsimple_log_monolog_parsemonologlevel, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Log_Monolog, camelize, arginfo_queryyetsimple_log_monolog_camelize, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
