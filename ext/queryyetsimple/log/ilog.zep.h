
extern zend_class_entry *queryyetsimple_log_ilog_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_ILog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_write, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_registerfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_registerprocessor, 0, 0, 1)
	ZEND_ARG_INFO(0, processor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_get, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_ilog_count, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_ilog_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Log_ILog, write, arginfo_queryyetsimple_log_ilog_write)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_ILog, save, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_ILog, registerFilter, arginfo_queryyetsimple_log_ilog_registerfilter)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_ILog, registerProcessor, arginfo_queryyetsimple_log_ilog_registerprocessor)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_ILog, clear, arginfo_queryyetsimple_log_ilog_clear)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_ILog, get, arginfo_queryyetsimple_log_ilog_get)
	PHP_ABSTRACT_ME(Queryyetsimple_Log_ILog, count, arginfo_queryyetsimple_log_ilog_count)
	PHP_FE_END
};
