
extern zend_class_entry *queryyetsimple_view_aconnect_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_Aconnect);

PHP_METHOD(Queryyetsimple_View_Aconnect, __construct);
PHP_METHOD(Queryyetsimple_View_Aconnect, setVar);
PHP_METHOD(Queryyetsimple_View_Aconnect, getVar);
PHP_METHOD(Queryyetsimple_View_Aconnect, deleteVar);
PHP_METHOD(Queryyetsimple_View_Aconnect, clearVar);
PHP_METHOD(Queryyetsimple_View_Aconnect, option);
PHP_METHOD(Queryyetsimple_View_Aconnect, optionArray);
PHP_METHOD(Queryyetsimple_View_Aconnect, options);
PHP_METHOD(Queryyetsimple_View_Aconnect, getOption);
PHP_METHOD(Queryyetsimple_View_Aconnect, getOptions);
PHP_METHOD(Queryyetsimple_View_Aconnect, deleteOption);
PHP_METHOD(Queryyetsimple_View_Aconnect, deleteOptions);
PHP_METHOD(Queryyetsimple_View_Aconnect, parseDisplayFile);
PHP_METHOD(Queryyetsimple_View_Aconnect, parseFile);
PHP_METHOD(Queryyetsimple_View_Aconnect, formatFile);
PHP_METHOD(Queryyetsimple_View_Aconnect, parseDefaultFile);
zend_object *zephir_init_properties_Queryyetsimple_View_Aconnect(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_setvar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_getvar, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_deletevar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_option, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_parsedisplayfile, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_INFO(0, strExt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_parsefile, 0, 0, 1)
	ZEND_ARG_INFO(0, sTpl)
	ZEND_ARG_INFO(0, sExt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_formatfile, 0, 0, 1)
	ZEND_ARG_INFO(0, sContent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_aconnect_parsedefaultfile, 0, 0, 1)
	ZEND_ARG_INFO(0, sTpl)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_aconnect_method_entry) {
	PHP_ME(Queryyetsimple_View_Aconnect, __construct, arginfo_queryyetsimple_view_aconnect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_View_Aconnect, setVar, arginfo_queryyetsimple_view_aconnect_setvar, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, getVar, arginfo_queryyetsimple_view_aconnect_getvar, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, deleteVar, arginfo_queryyetsimple_view_aconnect_deletevar, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, clearVar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, option, arginfo_queryyetsimple_view_aconnect_option, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, optionArray, arginfo_queryyetsimple_view_aconnect_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, options, arginfo_queryyetsimple_view_aconnect_options, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, getOption, arginfo_queryyetsimple_view_aconnect_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, getOptions, arginfo_queryyetsimple_view_aconnect_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, deleteOption, arginfo_queryyetsimple_view_aconnect_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, deleteOptions, arginfo_queryyetsimple_view_aconnect_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Aconnect, parseDisplayFile, arginfo_queryyetsimple_view_aconnect_parsedisplayfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Aconnect, parseFile, arginfo_queryyetsimple_view_aconnect_parsefile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Aconnect, formatFile, arginfo_queryyetsimple_view_aconnect_formatfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Aconnect, parseDefaultFile, arginfo_queryyetsimple_view_aconnect_parsedefaultfile, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
