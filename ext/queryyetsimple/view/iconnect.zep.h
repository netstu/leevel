
extern zend_class_entry *queryyetsimple_view_iconnect_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_IConnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_iconnect_display, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, vars, 1)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, display)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_iconnect_setvar, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_iconnect_getvar, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_iconnect_deletevar, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_iconnect_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_View_IConnect, display, arginfo_queryyetsimple_view_iconnect_display)
	PHP_ABSTRACT_ME(Queryyetsimple_View_IConnect, setVar, arginfo_queryyetsimple_view_iconnect_setvar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_IConnect, getVar, arginfo_queryyetsimple_view_iconnect_getvar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_IConnect, deleteVar, arginfo_queryyetsimple_view_iconnect_deletevar)
	PHP_ABSTRACT_ME(Queryyetsimple_View_IConnect, clearVar, NULL)
	PHP_FE_END
};
