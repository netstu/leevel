
extern zend_class_entry *queryyetsimple_view_connect_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_Connect);

PHP_METHOD(Queryyetsimple_View_Connect, __construct);
PHP_METHOD(Queryyetsimple_View_Connect, setVar);
PHP_METHOD(Queryyetsimple_View_Connect, getVar);
PHP_METHOD(Queryyetsimple_View_Connect, deleteVar);
PHP_METHOD(Queryyetsimple_View_Connect, clearVar);
PHP_METHOD(Queryyetsimple_View_Connect, option);
PHP_METHOD(Queryyetsimple_View_Connect, optionArray);
PHP_METHOD(Queryyetsimple_View_Connect, options);
PHP_METHOD(Queryyetsimple_View_Connect, getOption);
PHP_METHOD(Queryyetsimple_View_Connect, getOptions);
PHP_METHOD(Queryyetsimple_View_Connect, deleteOption);
PHP_METHOD(Queryyetsimple_View_Connect, deleteOptions);
PHP_METHOD(Queryyetsimple_View_Connect, parseDisplayFile);
PHP_METHOD(Queryyetsimple_View_Connect, parseFile);
PHP_METHOD(Queryyetsimple_View_Connect, formatFile);
PHP_METHOD(Queryyetsimple_View_Connect, parseDefaultFile);
zend_object *zephir_init_properties_Queryyetsimple_View_Connect(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_setvar, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_getvar, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_option, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_parsedisplayfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_parsefile, 0, 0, 1)
	ZEND_ARG_INFO(0, tpl)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_formatfile, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_connect_parsedefaultfile, 0, 0, 1)
	ZEND_ARG_INFO(0, tpl)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_connect_method_entry) {
	PHP_ME(Queryyetsimple_View_Connect, __construct, arginfo_queryyetsimple_view_connect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_View_Connect, setVar, arginfo_queryyetsimple_view_connect_setvar, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, getVar, arginfo_queryyetsimple_view_connect_getvar, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, deleteVar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, clearVar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, option, arginfo_queryyetsimple_view_connect_option, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, optionArray, arginfo_queryyetsimple_view_connect_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, options, arginfo_queryyetsimple_view_connect_options, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, getOption, arginfo_queryyetsimple_view_connect_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, getOptions, arginfo_queryyetsimple_view_connect_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, deleteOption, arginfo_queryyetsimple_view_connect_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, deleteOptions, arginfo_queryyetsimple_view_connect_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Connect, parseDisplayFile, arginfo_queryyetsimple_view_connect_parsedisplayfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Connect, parseFile, arginfo_queryyetsimple_view_connect_parsefile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Connect, formatFile, arginfo_queryyetsimple_view_connect_formatfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Connect, parseDefaultFile, arginfo_queryyetsimple_view_connect_parsedefaultfile, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
