
extern zend_class_entry *queryyetsimple_support_iarray_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_IArray);

ZEPHIR_INIT_FUNCS(queryyetsimple_support_iarray_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Support_IArray, toArray, NULL)
	PHP_FE_END
};
