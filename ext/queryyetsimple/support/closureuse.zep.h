
extern zend_class_entry *queryyetsimple_support_closureuse_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_ClosureUse);

PHP_METHOD(Queryyetsimple_Support_ClosureUse, __construct);
PHP_METHOD(Queryyetsimple_Support_ClosureUse, make);
PHP_METHOD(Queryyetsimple_Support_ClosureUse, invoke);
zend_object *zephir_init_properties_Queryyetsimple_Support_ClosureUse(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_closureuse___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, closures, Closure, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_closureuse_make, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, closures, Closure, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_support_closureuse_method_entry) {
	PHP_ME(Queryyetsimple_Support_ClosureUse, __construct, arginfo_queryyetsimple_support_closureuse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Support_ClosureUse, make, arginfo_queryyetsimple_support_closureuse_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_ClosureUse, invoke, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
