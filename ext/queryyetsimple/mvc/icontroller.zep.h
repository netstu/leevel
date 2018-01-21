
extern zend_class_entry *queryyetsimple_mvc_icontroller_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_IController);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_icontroller_setview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Queryyetsimple\\Mvc\\IView, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_icontroller_setrouter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, router, Queryyetsimple\\Router\\Router, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_icontroller_action, 0, 0, 1)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_mvc_icontroller_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_IController, setView, arginfo_queryyetsimple_mvc_icontroller_setview)
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_IController, setRouter, arginfo_queryyetsimple_mvc_icontroller_setrouter)
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_IController, action, arginfo_queryyetsimple_mvc_icontroller_action)
	PHP_FE_END
};
