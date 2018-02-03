
extern zend_class_entry *queryyetsimple_event_idispatch_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Event_IDispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_idispatch_listeners, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_idispatch_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_idispatch_haslisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_idispatch_deletelisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_idispatch_strict, 0, 0, 1)
	ZEND_ARG_INFO(0, strict)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_event_idispatch_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Event_IDispatch, run, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Event_IDispatch, listeners, arginfo_queryyetsimple_event_idispatch_listeners)
	PHP_ABSTRACT_ME(Queryyetsimple_Event_IDispatch, getListeners, arginfo_queryyetsimple_event_idispatch_getlisteners)
	PHP_ABSTRACT_ME(Queryyetsimple_Event_IDispatch, hasListeners, arginfo_queryyetsimple_event_idispatch_haslisteners)
	PHP_ABSTRACT_ME(Queryyetsimple_Event_IDispatch, deleteListeners, arginfo_queryyetsimple_event_idispatch_deletelisteners)
	PHP_ABSTRACT_ME(Queryyetsimple_Event_IDispatch, strict, arginfo_queryyetsimple_event_idispatch_strict)
	PHP_FE_END
};
