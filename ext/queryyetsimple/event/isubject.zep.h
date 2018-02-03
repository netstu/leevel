
extern zend_class_entry *queryyetsimple_event_isubject_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Event_ISubject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_event_isubject_attachs, 0, 0, 1)
	ZEND_ARG_INFO(0, observer)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_event_isubject_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Event_ISubject, attachs, arginfo_queryyetsimple_event_isubject_attachs)
	PHP_FE_END
};
