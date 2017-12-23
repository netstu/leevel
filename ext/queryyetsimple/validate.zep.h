
extern zend_class_entry *queryyetsimple_validate_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Validate);

PHP_METHOD(Queryyetsimple_Validate, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_validate_method_entry) {
	PHP_ME(Queryyetsimple_Validate, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
