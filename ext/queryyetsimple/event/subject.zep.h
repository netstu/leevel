
extern zend_class_entry *queryyetsimple_event_subject_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Event_Subject);

PHP_METHOD(Queryyetsimple_Event_Subject, __construct);
PHP_METHOD(Queryyetsimple_Event_Subject, attach);
PHP_METHOD(Queryyetsimple_Event_Subject, detach);
PHP_METHOD(Queryyetsimple_Event_Subject, notify);
PHP_METHOD(Queryyetsimple_Event_Subject, attachs);
zend_object *zephir_init_properties_Queryyetsimple_Event_Subject(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_subject___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Queryyetsimple\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_subject_attach, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, observer, SplObserver, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_subject_detach, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, observer, SplObserver, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_subject_attachs, 0, 0, 1)
	ZEND_ARG_INFO(0, observer)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_event_subject_method_entry) {
	PHP_ME(Queryyetsimple_Event_Subject, __construct, arginfo_queryyetsimple_event_subject___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Event_Subject, attach, arginfo_queryyetsimple_event_subject_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Event_Subject, detach, arginfo_queryyetsimple_event_subject_detach, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Event_Subject, notify, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Event_Subject, attachs, arginfo_queryyetsimple_event_subject_attachs, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
