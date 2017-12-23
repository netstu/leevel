
extern zend_class_entry *queryyetsimple_cookie_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Cookie);

PHP_METHOD(Queryyetsimple_Cookie, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_cookie_method_entry) {
	PHP_ME(Queryyetsimple_Cookie, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
