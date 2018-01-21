
extern zend_class_entry *queryyetsimple_log_iconnect_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_IConnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_iconnect_save, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, datas, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_iconnect_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Log_IConnect, save, arginfo_queryyetsimple_log_iconnect_save)
	PHP_FE_END
};
