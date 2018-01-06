
extern zend_class_entry *queryyetsimple_log_ilog_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Ilog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_write, 0, 0, 2)
	ZEND_ARG_INFO(0, strLevel)
	ZEND_ARG_INFO(0, strMessage)
	ZEND_ARG_ARRAY_INFO(0, arrContext, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_registerfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, calFilter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_registerprocessor, 0, 0, 1)
	ZEND_ARG_INFO(0, calProcessor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_get, 0, 0, 0)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_count, 0, 0, 0)
	ZEND_ARG_INFO(0, strLevel)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_ilog_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Log_Ilog, write, arginfo_queryyetsimple_log_ilog_write)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_Ilog, save, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_Ilog, registerFilter, arginfo_queryyetsimple_log_ilog_registerfilter)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_Ilog, registerProcessor, arginfo_queryyetsimple_log_ilog_registerprocessor)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_Ilog, clear, arginfo_queryyetsimple_log_ilog_clear)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_Ilog, get, arginfo_queryyetsimple_log_ilog_get)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_Ilog, count, arginfo_queryyetsimple_log_ilog_count)
	PHP_FE_END
};
