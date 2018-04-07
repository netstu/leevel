
extern zend_class_entry *leevel_25__closure_ce;

ZEPHIR_INIT_CLASS(leevel_25__closure);

PHP_METHOD(leevel_25__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_25__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, project)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_25__closure_method_entry) {
	PHP_ME(leevel_25__closure, __invoke, arginfo_leevel_25__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
