
extern zend_class_entry *queryyetsimple_mvc_iview_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_Iview);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_iview_switchview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objTheme, Queryyetsimple\\View\\Iview, 0)
	ZEND_ARG_INFO(0, booForever)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_iview_assign, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_iview_getassign, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_iview_deleteassign, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_iview_display, 0, 0, 0)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_mvc_iview_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_Iview, switchView, arginfo_queryyetsimple_mvc_iview_switchview)
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_Iview, assign, arginfo_queryyetsimple_mvc_iview_assign)
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_Iview, getAssign, arginfo_queryyetsimple_mvc_iview_getassign)
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_Iview, deleteAssign, arginfo_queryyetsimple_mvc_iview_deleteassign)
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_Iview, clearAssign, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_Iview, display, arginfo_queryyetsimple_mvc_iview_display)
	PHP_FE_END
};
