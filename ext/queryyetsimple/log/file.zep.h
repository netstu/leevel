
extern zend_class_entry *queryyetsimple_log_file_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log_File);

PHP_METHOD(Queryyetsimple_Log_File, save);
PHP_METHOD(Queryyetsimple_Log_File, formatMessage);
zend_object *zephir_init_properties_Queryyetsimple_Log_File(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_file_save, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, datas, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_log_file_formatmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, contexts, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_log_file_method_entry) {
	PHP_ME(Queryyetsimple_Log_File, save, arginfo_queryyetsimple_log_file_save, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Log_File, formatMessage, arginfo_queryyetsimple_log_file_formatmessage, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
