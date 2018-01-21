
extern zend_class_entry *queryyetsimple_view_html_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_Html);

PHP_METHOD(Queryyetsimple_View_Html, display);
PHP_METHOD(Queryyetsimple_View_Html, setParseResolver);
PHP_METHOD(Queryyetsimple_View_Html, resolverParser);
PHP_METHOD(Queryyetsimple_View_Html, parser);
PHP_METHOD(Queryyetsimple_View_Html, getCachePath);
PHP_METHOD(Queryyetsimple_View_Html, isCacheExpired);
zend_object *zephir_init_properties_Queryyetsimple_View_Html(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_html_display, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, vars, 1)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, display)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_html_setparseresolver, 0, 0, 1)
	ZEND_ARG_INFO(0, parserResolver)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_html_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_html_iscacheexpired, 0, 0, 2)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, cachepath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_html_method_entry) {
	PHP_ME(Queryyetsimple_View_Html, display, arginfo_queryyetsimple_view_html_display, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Html, setParseResolver, arginfo_queryyetsimple_view_html_setparseresolver, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Html, resolverParser, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Html, parser, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_View_Html, getCachePath, arginfo_queryyetsimple_view_html_getcachepath, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Html, isCacheExpired, arginfo_queryyetsimple_view_html_iscacheexpired, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
