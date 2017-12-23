
extern zend_class_entry *queryyetsimple_cache_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Cache);

PHP_METHOD(Queryyetsimple_Cache, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_cache_method_entry) {
	PHP_ME(Queryyetsimple_Cache, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
