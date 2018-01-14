
extern zend_class_entry *queryyetsimple_view_iconnect_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_Iconnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_iconnect_display, 0, 0, 1)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_INFO(0, bDisplay)
	ZEND_ARG_INFO(0, strExt)
	ZEND_ARG_INFO(0, sTargetCache)
	ZEND_ARG_INFO(0, sMd5)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_iconnect_setvar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_iconnect_getvar, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_iconnect_deletevar, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_iconnect_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_View_Iconnect, display, arginfo_queryyetsimple_view_iconnect_display)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Iconnect, setVar, arginfo_queryyetsimple_view_iconnect_setvar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Iconnect, getVar, arginfo_queryyetsimple_view_iconnect_getvar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Iconnect, deleteVar, arginfo_queryyetsimple_view_iconnect_deletevar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_Iconnect, clearVar, NULL)
	PHP_FE_END
};
