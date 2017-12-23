
extern zend_class_entry *queryyetsimple_response_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Response);

PHP_METHOD(Queryyetsimple_Response, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_response_method_entry) {
	PHP_ME(Queryyetsimple_Response, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
