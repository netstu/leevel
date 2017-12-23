
extern zend_class_entry *queryyetsimple_psr4_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Psr4);

PHP_METHOD(Queryyetsimple_Psr4, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_psr4_method_entry) {
	PHP_ME(Queryyetsimple_Psr4, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
