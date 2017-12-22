
extern zend_class_entry *queryyetsimple_greeting_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Greeting);

PHP_METHOD(Queryyetsimple_Greeting, say);

ZEPHIR_INIT_FUNCS(queryyetsimple_greeting_method_entry) {
	PHP_ME(Queryyetsimple_Greeting, say, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
