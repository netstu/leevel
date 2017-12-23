
extern zend_class_entry *queryyetsimple_filesystem_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Filesystem);

PHP_METHOD(Queryyetsimple_Filesystem, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_filesystem_method_entry) {
	PHP_ME(Queryyetsimple_Filesystem, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
