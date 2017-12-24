
extern zend_class_entry *queryyetsimple_support_ihtml_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Ihtml);

ZEPHIR_INIT_FUNCS(queryyetsimple_support_ihtml_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Support_Ihtml, toHtml, NULL)
	PHP_FE_END
};
