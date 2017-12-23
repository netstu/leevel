
extern zend_class_entry *queryyetsimple_option_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Option);

PHP_METHOD(Queryyetsimple_Option, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_option_method_entry) {
	PHP_ME(Queryyetsimple_Option, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
