
extern zend_class_entry *leevel_29__closure_ce;

ZEPHIR_INIT_CLASS(leevel_29__closure);

PHP_METHOD(leevel_29__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_29__closure___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, project)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_29__closure_method_entry) {
	PHP_ME(leevel_29__closure, __invoke, arginfo_leevel_29__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
