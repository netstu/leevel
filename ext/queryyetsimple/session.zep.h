
extern zend_class_entry *queryyetsimple_session_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Session);

PHP_METHOD(Queryyetsimple_Session, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_session_method_entry) {
	PHP_ME(Queryyetsimple_Session, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
