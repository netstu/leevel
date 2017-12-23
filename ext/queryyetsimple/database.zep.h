
extern zend_class_entry *queryyetsimple_database_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Database);

PHP_METHOD(Queryyetsimple_Database, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_database_method_entry) {
	PHP_ME(Queryyetsimple_Database, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
