
extern zend_class_entry *queryyetsimple_option_ioption_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Option_Ioption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_ioption_has, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_ioption_get, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
	ZEND_ARG_INFO(0, mixDefault)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_ioption_set, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_ioption_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_ioption_reset, 0, 0, 0)
	ZEND_ARG_INFO(0, mixNamespace)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_option_ioption_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Option_Ioption, has, arginfo_queryyetsimple_option_ioption_has)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_Ioption, get, arginfo_queryyetsimple_option_ioption_get)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_Ioption, all, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_Ioption, set, arginfo_queryyetsimple_option_ioption_set)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_Ioption, delete, arginfo_queryyetsimple_option_ioption_delete)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_Ioption, reset, arginfo_queryyetsimple_option_ioption_reset)
	PHP_FE_END
};
