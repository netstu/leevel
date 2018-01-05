
extern zend_class_entry *queryyetsimple_view_itheme2_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_Itheme2);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme2_setparseresolver, 0, 0, 1)
	ZEND_ARG_INFO(0, calParseResolver)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme2_display, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_INFO(0, bDisplay)
	ZEND_ARG_INFO(0, strExt)
	ZEND_ARG_INFO(0, sTargetCache)
	ZEND_ARG_INFO(0, sMd5)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme2_setvar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme2_getvar, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme2_deletevar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme2_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_itheme2_parsecontext, 0, 0, 1)
	ZEND_ARG_INFO(0, strThemePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_itheme2_method_entry) {
	ZEND_FENTRY(setParseResolver, NULL, arginfo_queryyetsimple_view_itheme2_setparseresolver, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme2, resolverParse, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme2, parser, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme2, display, arginfo_queryyetsimple_view_itheme2_display)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme2, setVar, arginfo_queryyetsimple_view_itheme2_setvar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme2, getVar, arginfo_queryyetsimple_view_itheme2_getvar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme2, deleteVar, arginfo_queryyetsimple_view_itheme2_deletevar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme2, clearVar, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme2, getCachePath, arginfo_queryyetsimple_view_itheme2_getcachepath)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Itheme2, parseContext, arginfo_queryyetsimple_view_itheme2_parsecontext)
	PHP_FE_END
};
