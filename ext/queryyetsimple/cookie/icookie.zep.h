
extern zend_class_entry *queryyetsimple_cookie_icookie_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Cookie_Icookie);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_put, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_push, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_pop, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_arrays, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_arraysdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_cookie_icookie_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, deletePrefix)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_cookie_icookie_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, set, arginfo_queryyetsimple_cookie_icookie_set)
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, put, arginfo_queryyetsimple_cookie_icookie_put)
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, push, arginfo_queryyetsimple_cookie_icookie_push)
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, merge, arginfo_queryyetsimple_cookie_icookie_merge)
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, pop, arginfo_queryyetsimple_cookie_icookie_pop)
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, arrays, arginfo_queryyetsimple_cookie_icookie_arrays)
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, arraysDelete, arginfo_queryyetsimple_cookie_icookie_arraysdelete)
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, get, arginfo_queryyetsimple_cookie_icookie_get)
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, delete, arginfo_queryyetsimple_cookie_icookie_delete)
	PHP_ABSTRACT_ME(Queryyetsimple_Cookie_Icookie, clear, arginfo_queryyetsimple_cookie_icookie_clear)
	PHP_FE_END
};
