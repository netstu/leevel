
extern zend_class_entry *leevel_1__closure_ce;

ZEPHIR_INIT_CLASS(leevel_1__closure);

PHP_METHOD(leevel_1__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_1__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_1__closure_method_entry) {
	PHP_ME(leevel_1__closure, __invoke, arginfo_leevel_1__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
