
extern zend_class_entry *queryyetsimple_view_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View);

PHP_METHOD(Queryyetsimple_View, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_view_method_entry) {
	PHP_ME(Queryyetsimple_View, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
