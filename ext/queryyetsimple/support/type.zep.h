
extern zend_class_entry *queryyetsimple_support_type_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Type);

PHP_METHOD(Queryyetsimple_Support_Type, vars);
PHP_METHOD(Queryyetsimple_Support_Type, num);
PHP_METHOD(Queryyetsimple_Support_Type, ints);
PHP_METHOD(Queryyetsimple_Support_Type, these);
PHP_METHOD(Queryyetsimple_Support_Type, arr);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_type_vars, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_type_num, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_type_ints, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_type_these, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, types)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_type_arr, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
	ZEND_ARG_ARRAY_INFO(0, types, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_support_type_method_entry) {
	PHP_ME(Queryyetsimple_Support_Type, vars, arginfo_queryyetsimple_support_type_vars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Type, num, arginfo_queryyetsimple_support_type_num, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Type, ints, arginfo_queryyetsimple_support_type_ints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Type, these, arginfo_queryyetsimple_support_type_these, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Type, arr, arginfo_queryyetsimple_support_type_arr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
