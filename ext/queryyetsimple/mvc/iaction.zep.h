
extern zend_class_entry *queryyetsimple_mvc_iaction_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_IAction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_iaction_setcontroller, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, controller, Queryyetsimple\\Mvc\\IController, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_mvc_iaction_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_IAction, setController, arginfo_queryyetsimple_mvc_iaction_setcontroller)
	PHP_FE_END
};
