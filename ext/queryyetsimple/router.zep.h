
extern zend_class_entry *queryyetsimple_router_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Router);

PHP_METHOD(Queryyetsimple_Router, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_router_method_entry) {
	PHP_ME(Queryyetsimple_Router, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
