
extern zend_class_entry *queryyetsimple_log_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Log);

PHP_METHOD(Queryyetsimple_Log, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_log_method_entry) {
	PHP_ME(Queryyetsimple_Log, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
