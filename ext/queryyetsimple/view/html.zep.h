
extern zend_class_entry *queryyetsimple_view_html_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_Html);

PHP_METHOD(Queryyetsimple_View_Html, display);
PHP_METHOD(Queryyetsimple_View_Html, setParseResolver);
PHP_METHOD(Queryyetsimple_View_Html, resolverParse);
PHP_METHOD(Queryyetsimple_View_Html, parser);
PHP_METHOD(Queryyetsimple_View_Html, getCachePath);
PHP_METHOD(Queryyetsimple_View_Html, isCacheExpired);
PHP_METHOD(Queryyetsimple_View_Html, fixIe);
zend_object *zephir_init_properties_Queryyetsimple_View_Html(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_html_display, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_INFO(0, bDisplay)
	ZEND_ARG_INFO(0, strExt)
	ZEND_ARG_INFO(0, sTargetCache)
	ZEND_ARG_INFO(0, sMd5)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_html_setparseresolver, 0, 0, 1)
	ZEND_ARG_INFO(0, calParseResolver)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_html_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_html_iscacheexpired, 0, 0, 2)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_INFO(0, sCachePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_html_fixie, 0, 0, 1)
	ZEND_ARG_INFO(0, sContent)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_html_method_entry) {
	PHP_ME(Queryyetsimple_View_Html, display, arginfo_queryyetsimple_view_html_display, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Html, setParseResolver, arginfo_queryyetsimple_view_html_setparseresolver, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_View_Html, resolverParse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Html, parser, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Html, getCachePath, arginfo_queryyetsimple_view_html_getcachepath, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Html, isCacheExpired, arginfo_queryyetsimple_view_html_iscacheexpired, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Html, fixIe, arginfo_queryyetsimple_view_html_fixie, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
