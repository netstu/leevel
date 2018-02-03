
extern zend_class_entry *queryyetsimple_event_eventprovider_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Event_EventProvider);

PHP_METHOD(Queryyetsimple_Event_EventProvider, bootstrap);
PHP_METHOD(Queryyetsimple_Event_EventProvider, register);
PHP_METHOD(Queryyetsimple_Event_EventProvider, getListeners);
zend_object *zephir_init_properties_Queryyetsimple_Event_EventProvider(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_eventprovider_bootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dispatch, Queryyetsimple\\Event\\IDispatch, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_event_eventprovider_method_entry) {
	PHP_ME(Queryyetsimple_Event_EventProvider, bootstrap, arginfo_queryyetsimple_event_eventprovider_bootstrap, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Event_EventProvider, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Event_EventProvider, getListeners, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
