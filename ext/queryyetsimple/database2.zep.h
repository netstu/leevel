
extern zend_class_entry *queryyetsimple_database2_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Database2);

PHP_METHOD(Queryyetsimple_Database2, say);

ZEPHIR_INIT_FUNCS(queryyetsimple_database2_method_entry) {
	PHP_ME(Queryyetsimple_Database2, say, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
