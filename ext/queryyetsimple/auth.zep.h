
extern zend_class_entry *queryyetsimple_auth_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Auth);

PHP_METHOD(Queryyetsimple_Auth, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_auth_method_entry) {
	PHP_ME(Queryyetsimple_Auth, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
