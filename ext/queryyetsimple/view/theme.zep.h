
extern zend_class_entry *queryyetsimple_view_theme_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_Theme);

PHP_METHOD(Queryyetsimple_View_Theme, __construct);
PHP_METHOD(Queryyetsimple_View_Theme, setParseResolver);
PHP_METHOD(Queryyetsimple_View_Theme, resolverParse);
PHP_METHOD(Queryyetsimple_View_Theme, parser);
PHP_METHOD(Queryyetsimple_View_Theme, display);
PHP_METHOD(Queryyetsimple_View_Theme, setVar);
PHP_METHOD(Queryyetsimple_View_Theme, getVar);
PHP_METHOD(Queryyetsimple_View_Theme, deleteVar);
PHP_METHOD(Queryyetsimple_View_Theme, clearVar);
PHP_METHOD(Queryyetsimple_View_Theme, getCachePath);
PHP_METHOD(Queryyetsimple_View_Theme, option);
PHP_METHOD(Queryyetsimple_View_Theme, optionArray);
PHP_METHOD(Queryyetsimple_View_Theme, options);
PHP_METHOD(Queryyetsimple_View_Theme, getOption);
PHP_METHOD(Queryyetsimple_View_Theme, getOptions);
PHP_METHOD(Queryyetsimple_View_Theme, deleteOption);
PHP_METHOD(Queryyetsimple_View_Theme, deleteOptions);
PHP_METHOD(Queryyetsimple_View_Theme, parseDisplayFile);
PHP_METHOD(Queryyetsimple_View_Theme, parseFile);
PHP_METHOD(Queryyetsimple_View_Theme, formatFile);
PHP_METHOD(Queryyetsimple_View_Theme, parseDefaultFile);
PHP_METHOD(Queryyetsimple_View_Theme, isCacheExpired);
PHP_METHOD(Queryyetsimple_View_Theme, fixIe);
zend_object *zephir_init_properties_Queryyetsimple_View_Theme(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_setparseresolver, 0, 0, 1)
	ZEND_ARG_INFO(0, calParseResolver)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_display, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_INFO(0, bDisplay)
	ZEND_ARG_INFO(0, strExt)
	ZEND_ARG_INFO(0, sTargetCache)
	ZEND_ARG_INFO(0, sMd5)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_setvar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_getvar, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_deletevar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_option, 0, 0, 2)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_ARRAY_INFO(0, arrValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_INFO(0, mixDefault)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_parsedisplayfile, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_INFO(0, strExt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_parsefile, 0, 0, 1)
	ZEND_ARG_INFO(0, sTpl)
	ZEND_ARG_INFO(0, sExt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_formatfile, 0, 0, 1)
	ZEND_ARG_INFO(0, sContent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_parsedefaultfile, 0, 0, 1)
	ZEND_ARG_INFO(0, sTpl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_iscacheexpired, 0, 0, 2)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_INFO(0, sCachePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_theme_fixie, 0, 0, 1)
	ZEND_ARG_INFO(0, sContent)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_theme_method_entry) {
	PHP_ME(Queryyetsimple_View_Theme, __construct, arginfo_queryyetsimple_view_theme___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_View_Theme, setParseResolver, arginfo_queryyetsimple_view_theme_setparseresolver, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_View_Theme, resolverParse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, parser, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, display, arginfo_queryyetsimple_view_theme_display, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, setVar, arginfo_queryyetsimple_view_theme_setvar, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, getVar, arginfo_queryyetsimple_view_theme_getvar, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, deleteVar, arginfo_queryyetsimple_view_theme_deletevar, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, clearVar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, getCachePath, arginfo_queryyetsimple_view_theme_getcachepath, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, option, arginfo_queryyetsimple_view_theme_option, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, optionArray, arginfo_queryyetsimple_view_theme_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, options, arginfo_queryyetsimple_view_theme_options, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, getOption, arginfo_queryyetsimple_view_theme_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, getOptions, arginfo_queryyetsimple_view_theme_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, deleteOption, arginfo_queryyetsimple_view_theme_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, deleteOptions, arginfo_queryyetsimple_view_theme_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Theme, parseDisplayFile, arginfo_queryyetsimple_view_theme_parsedisplayfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Theme, parseFile, arginfo_queryyetsimple_view_theme_parsefile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Theme, formatFile, arginfo_queryyetsimple_view_theme_formatfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Theme, parseDefaultFile, arginfo_queryyetsimple_view_theme_parsedefaultfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Theme, isCacheExpired, arginfo_queryyetsimple_view_theme_iscacheexpired, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Theme, fixIe, arginfo_queryyetsimple_view_theme_fixie, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
