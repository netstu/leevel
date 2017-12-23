
extern zend_class_entry *queryyetsimple_greeting2_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Greeting2);

PHP_METHOD(Queryyetsimple_Greeting2, say);

ZEPHIR_INIT_FUNCS(queryyetsimple_greeting2_method_entry) {
	PHP_ME(Queryyetsimple_Greeting2, say, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
