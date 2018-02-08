
extern zend_class_entry *queryyetsimple_url_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Url);

PHP_METHOD(Queryyetsimple_Url, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_url_method_entry) {
	PHP_ME(Queryyetsimple_Url, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
