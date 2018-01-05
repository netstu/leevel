
extern zend_class_entry *queryyetsimple_view_itheme_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_Itheme);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme_setparseresolver, 0, 0, 1)
	ZEND_ARG_INFO(0, calParseResolver)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme_display, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_INFO(0, bDisplay)
	ZEND_ARG_INFO(0, strExt)
	ZEND_ARG_INFO(0, sTargetCache)
	ZEND_ARG_INFO(0, sMd5)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme_setvar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme_getvar, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme_deletevar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_itheme_method_entry) {
	ZEND_FENTRY(setParseResolver, NULL, arginfo_queryyetsimple_view_itheme_setparseresolver, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme, resolverParse, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme, parser, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme, display, arginfo_queryyetsimple_view_itheme_display)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme, setVar, arginfo_queryyetsimple_view_itheme_setvar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme, getVar, arginfo_queryyetsimple_view_itheme_getvar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme, deleteVar, arginfo_queryyetsimple_view_itheme_deletevar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme, clearVar, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme, getCachePath, arginfo_queryyetsimple_view_itheme_getcachepath)
	PHP_FE_END
};
