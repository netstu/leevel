
extern zend_class_entry *queryyetsimple_throttler_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Throttler);

PHP_METHOD(Queryyetsimple_Throttler, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_throttler_method_entry) {
	PHP_ME(Queryyetsimple_Throttler, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
