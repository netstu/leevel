
extern zend_class_entry *queryyetsimple_mvc_view_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_View);

PHP_METHOD(Queryyetsimple_Mvc_View, __construct);
PHP_METHOD(Queryyetsimple_Mvc_View, switchView);
PHP_METHOD(Queryyetsimple_Mvc_View, setResponseFactory);
PHP_METHOD(Queryyetsimple_Mvc_View, getResponse);
PHP_METHOD(Queryyetsimple_Mvc_View, assign);
PHP_METHOD(Queryyetsimple_Mvc_View, getAssign);
PHP_METHOD(Queryyetsimple_Mvc_View, deleteAssign);
PHP_METHOD(Queryyetsimple_Mvc_View, clearAssign);
PHP_METHOD(Queryyetsimple_Mvc_View, display);
PHP_METHOD(Queryyetsimple_Mvc_View, checkTheme);
PHP_METHOD(Queryyetsimple_Mvc_View, responseHeader);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_view___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objTheme, Queryyetsimple\\View\\Iview, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_view_switchview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objTheme, Queryyetsimple\\View\\Iview, 0)
	ZEND_ARG_INFO(0, booForever)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_view_setresponsefactory, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, calResponseFactory, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_view_assign, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_view_getassign, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_view_deleteassign, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_view_display, 0, 0, 0)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_view_responseheader, 0, 0, 0)
	ZEND_ARG_INFO(0, strContentType)
	ZEND_ARG_INFO(0, strCharset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_mvc_view_method_entry) {
	PHP_ME(Queryyetsimple_Mvc_View, __construct, arginfo_queryyetsimple_mvc_view___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Mvc_View, switchView, arginfo_queryyetsimple_mvc_view_switchview, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_View, setResponseFactory, arginfo_queryyetsimple_mvc_view_setresponsefactory, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_View, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_View, assign, arginfo_queryyetsimple_mvc_view_assign, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_View, getAssign, arginfo_queryyetsimple_mvc_view_getassign, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_View, deleteAssign, arginfo_queryyetsimple_mvc_view_deleteassign, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_View, clearAssign, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_View, display, arginfo_queryyetsimple_mvc_view_display, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_View, checkTheme, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Mvc_View, responseHeader, arginfo_queryyetsimple_mvc_view_responseheader, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
