
extern zend_class_entry *queryyetsimple_mvc_icontroller_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_Icontroller);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_icontroller_setview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objView, Queryyetsimple\\Mvc\\Iview, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_icontroller_setrouter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objRouter, Queryyetsimple\\Router\\Router, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_icontroller_action, 0, 0, 1)
	ZEND_ARG_INFO(0, sActionName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_mvc_icontroller_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_Icontroller, setView, arginfo_queryyetsimple_mvc_icontroller_setview)
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_Icontroller, setRouter, arginfo_queryyetsimple_mvc_icontroller_setrouter)
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_Icontroller, action, arginfo_queryyetsimple_mvc_icontroller_action)
	PHP_FE_END
};
