
extern zend_class_entry *queryyetsimple_http_serverbag_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Http_ServerBag);

PHP_METHOD(Queryyetsimple_Http_ServerBag, getHeaders);

ZEPHIR_INIT_FUNCS(queryyetsimple_http_serverbag_method_entry) {
	PHP_ME(Queryyetsimple_Http_ServerBag, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
