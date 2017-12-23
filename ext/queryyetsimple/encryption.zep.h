
extern zend_class_entry *queryyetsimple_encryption_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Encryption);

PHP_METHOD(Queryyetsimple_Encryption, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_encryption_method_entry) {
	PHP_ME(Queryyetsimple_Encryption, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
