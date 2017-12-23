
extern zend_class_entry *queryyetsimple_db_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Db);

PHP_METHOD(Queryyetsimple_Db, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_db_method_entry) {
	PHP_ME(Queryyetsimple_Db, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
