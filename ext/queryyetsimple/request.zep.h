
extern zend_class_entry *queryyetsimple_request_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Request);

PHP_METHOD(Queryyetsimple_Request, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_request_method_entry) {
	PHP_ME(Queryyetsimple_Request, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
