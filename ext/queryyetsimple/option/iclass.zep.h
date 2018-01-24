
extern zend_class_entry *queryyetsimple_option_iclass_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Option_IClass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_iclass_option, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_iclass_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_iclass_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_iclass_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_iclass_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_iclass_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_iclass_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_option_iclass_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Option_IClass, option, arginfo_queryyetsimple_option_iclass_option)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_IClass, optionArray, arginfo_queryyetsimple_option_iclass_optionarray)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_IClass, options, arginfo_queryyetsimple_option_iclass_options)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_IClass, getOption, arginfo_queryyetsimple_option_iclass_getoption)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_IClass, getOptions, arginfo_queryyetsimple_option_iclass_getoptions)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_IClass, deleteOption, arginfo_queryyetsimple_option_iclass_deleteoption)
	PHP_ABSTRACT_ME(Queryyetsimple_Option_IClass, deleteOptions, arginfo_queryyetsimple_option_iclass_deleteoptions)
	PHP_FE_END
};
