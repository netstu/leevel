
extern zend_class_entry *leevel_event_dispatch_ce;

ZEPHIR_INIT_CLASS(Leevel_Event_Dispatch);

PHP_METHOD(Leevel_Event_Dispatch, __construct);
PHP_METHOD(Leevel_Event_Dispatch, run);
PHP_METHOD(Leevel_Event_Dispatch, listeners);
PHP_METHOD(Leevel_Event_Dispatch, getListeners);
PHP_METHOD(Leevel_Event_Dispatch, hasListeners);
PHP_METHOD(Leevel_Event_Dispatch, deleteListeners);
PHP_METHOD(Leevel_Event_Dispatch, strict);
PHP_METHOD(Leevel_Event_Dispatch, makeSubject);
PHP_METHOD(Leevel_Event_Dispatch, prepareRegexForWildcard);
PHP_METHOD(Leevel_Event_Dispatch, escapeRegexCharacter);
zend_object *zephir_init_properties_Leevel_Event_Dispatch(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
	ZEND_ARG_INFO(0, strict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_listeners, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_haslisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_deletelisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_strict, 0, 0, 1)
	ZEND_ARG_INFO(0, strict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_makesubject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, listeners, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_prepareregexforwildcard, 0, 0, 1)
	ZEND_ARG_INFO(0, regex)
	ZEND_ARG_INFO(0, strict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_escaperegexcharacter, 0, 0, 1)
	ZEND_ARG_INFO(0, txt)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_event_dispatch_method_entry) {
	PHP_ME(Leevel_Event_Dispatch, __construct, arginfo_leevel_event_dispatch___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Event_Dispatch, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, listeners, arginfo_leevel_event_dispatch_listeners, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, getListeners, arginfo_leevel_event_dispatch_getlisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, hasListeners, arginfo_leevel_event_dispatch_haslisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, deleteListeners, arginfo_leevel_event_dispatch_deletelisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, strict, arginfo_leevel_event_dispatch_strict, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, makeSubject, arginfo_leevel_event_dispatch_makesubject, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Event_Dispatch, prepareRegexForWildcard, arginfo_leevel_event_dispatch_prepareregexforwildcard, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Event_Dispatch, escapeRegexCharacter, arginfo_leevel_event_dispatch_escaperegexcharacter, ZEND_ACC_PROTECTED)
	PHP_FE_END
};