
extern zend_class_entry *queryyetsimple_support_ijson_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_IJson);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_ijson_tojson, 0, 0, 0)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_support_ijson_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Support_IJson, toJson, arginfo_queryyetsimple_support_ijson_tojson)
	PHP_FE_END
};
