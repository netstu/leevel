
extern zend_class_entry *queryyetsimple_i18n_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_I18n);

PHP_METHOD(Queryyetsimple_I18n, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_i18n_method_entry) {
	PHP_ME(Queryyetsimple_I18n, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
