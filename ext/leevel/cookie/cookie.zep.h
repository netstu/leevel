
extern zend_class_entry *leevel_cookie_cookie_ce;

ZEPHIR_INIT_CLASS(Leevel_Cookie_Cookie);

PHP_METHOD(Leevel_Cookie_Cookie, __construct);
PHP_METHOD(Leevel_Cookie_Cookie, set);
PHP_METHOD(Leevel_Cookie_Cookie, put);
PHP_METHOD(Leevel_Cookie_Cookie, push);
PHP_METHOD(Leevel_Cookie_Cookie, merge);
PHP_METHOD(Leevel_Cookie_Cookie, pop);
PHP_METHOD(Leevel_Cookie_Cookie, arrays);
PHP_METHOD(Leevel_Cookie_Cookie, arraysDelete);
PHP_METHOD(Leevel_Cookie_Cookie, get);
PHP_METHOD(Leevel_Cookie_Cookie, delete);
PHP_METHOD(Leevel_Cookie_Cookie, clear);
PHP_METHOD(Leevel_Cookie_Cookie, option);
PHP_METHOD(Leevel_Cookie_Cookie, optionArray);
PHP_METHOD(Leevel_Cookie_Cookie, options);
PHP_METHOD(Leevel_Cookie_Cookie, getOption);
PHP_METHOD(Leevel_Cookie_Cookie, getOptions);
PHP_METHOD(Leevel_Cookie_Cookie, deleteOption);
PHP_METHOD(Leevel_Cookie_Cookie, deleteOptions);
PHP_METHOD(Leevel_Cookie_Cookie, isJson);
zend_object *zephir_init_properties_Leevel_Cookie_Cookie(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_put, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_push, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_pop, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_arrays, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_arraysdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, deletePrefix)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_option, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_cookie_isjson, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cookie_cookie_method_entry) {
	PHP_ME(Leevel_Cookie_Cookie, __construct, arginfo_leevel_cookie_cookie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Cookie_Cookie, set, arginfo_leevel_cookie_cookie_set, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, put, arginfo_leevel_cookie_cookie_put, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, push, arginfo_leevel_cookie_cookie_push, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, merge, arginfo_leevel_cookie_cookie_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, pop, arginfo_leevel_cookie_cookie_pop, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, arrays, arginfo_leevel_cookie_cookie_arrays, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, arraysDelete, arginfo_leevel_cookie_cookie_arraysdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, get, arginfo_leevel_cookie_cookie_get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, delete, arginfo_leevel_cookie_cookie_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, clear, arginfo_leevel_cookie_cookie_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, option, arginfo_leevel_cookie_cookie_option, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, optionArray, arginfo_leevel_cookie_cookie_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, options, arginfo_leevel_cookie_cookie_options, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, getOption, arginfo_leevel_cookie_cookie_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, getOptions, arginfo_leevel_cookie_cookie_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, deleteOption, arginfo_leevel_cookie_cookie_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, deleteOptions, arginfo_leevel_cookie_cookie_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cookie_Cookie, isJson, arginfo_leevel_cookie_cookie_isjson, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
