
extern zend_class_entry *queryyetsimple_event_observer_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Event_Observer);

PHP_METHOD(Queryyetsimple_Event_Observer, __construct);
PHP_METHOD(Queryyetsimple_Event_Observer, update);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_observer_update, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, subject, SplSubject, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_event_observer_method_entry) {
	PHP_ME(Queryyetsimple_Event_Observer, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Event_Observer, update, arginfo_queryyetsimple_event_observer_update, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
