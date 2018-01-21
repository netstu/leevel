
extern zend_class_entry *queryyetsimple_mvc_action_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_Action);

PHP_METHOD(Queryyetsimple_Mvc_Action, __construct);
PHP_METHOD(Queryyetsimple_Mvc_Action, setController);
PHP_METHOD(Queryyetsimple_Mvc_Action, setView);
PHP_METHOD(Queryyetsimple_Mvc_Action, setRouter);
PHP_METHOD(Queryyetsimple_Mvc_Action, action);
PHP_METHOD(Queryyetsimple_Mvc_Action, switchView);
PHP_METHOD(Queryyetsimple_Mvc_Action, assign);
PHP_METHOD(Queryyetsimple_Mvc_Action, getAssign);
PHP_METHOD(Queryyetsimple_Mvc_Action, deleteAssign);
PHP_METHOD(Queryyetsimple_Mvc_Action, clearAssign);
PHP_METHOD(Queryyetsimple_Mvc_Action, display);
PHP_METHOD(Queryyetsimple_Mvc_Action, checkController);
PHP_METHOD(Queryyetsimple_Mvc_Action, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action_setcontroller, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, controller, Queryyetsimple\\Mvc\\IController, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action_setview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Queryyetsimple\\Mvc\\IView, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action_setrouter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, router, Queryyetsimple\\Router\\Router, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action_action, 0, 0, 1)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action_switchview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, theme, Queryyetsimple\\View\\IView, 0)
	ZEND_ARG_INFO(0, forever)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action_assign, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action_getassign, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action_deleteassign, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action_display, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, vars, 1)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_action___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_mvc_action_method_entry) {
	PHP_ME(Queryyetsimple_Mvc_Action, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Mvc_Action, setController, arginfo_queryyetsimple_mvc_action_setcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, setView, arginfo_queryyetsimple_mvc_action_setview, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, setRouter, arginfo_queryyetsimple_mvc_action_setrouter, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, action, arginfo_queryyetsimple_mvc_action_action, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, switchView, arginfo_queryyetsimple_mvc_action_switchview, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, assign, arginfo_queryyetsimple_mvc_action_assign, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, getAssign, arginfo_queryyetsimple_mvc_action_getassign, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, deleteAssign, arginfo_queryyetsimple_mvc_action_deleteassign, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, clearAssign, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, display, arginfo_queryyetsimple_mvc_action_display, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Action, checkController, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Mvc_Action, __call, arginfo_queryyetsimple_mvc_action___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
