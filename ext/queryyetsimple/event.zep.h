
extern zend_class_entry *queryyetsimple_event_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Event);

PHP_METHOD(Queryyetsimple_Event, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_event_method_entry) {
	PHP_ME(Queryyetsimple_Event, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
