
extern zend_class_entry *queryyetsimple_support_imacro_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_IMacro);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_imacro_macro, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, macro)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_imacro_hasmacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_imacro_callstaticmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_imacro_callmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_support_imacro_method_entry) {
	ZEND_FENTRY(macro, NULL, arginfo_queryyetsimple_support_imacro_macro, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(hasMacro, NULL, arginfo_queryyetsimple_support_imacro_hasmacro, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(callStaticMacro, NULL, arginfo_queryyetsimple_support_imacro_callstaticmacro, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Queryyetsimple_Support_IMacro, callMacro, arginfo_queryyetsimple_support_imacro_callmacro)
	PHP_FE_END
};
