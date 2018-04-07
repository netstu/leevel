
extern zend_class_entry *leevel_log_iconnect_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_IConnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_iconnect_save, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, datas, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_iconnect_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Log_IConnect, save, arginfo_leevel_log_iconnect_save)
	PHP_FE_END
};
