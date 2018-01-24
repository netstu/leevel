
extern zend_class_entry *queryyetsimple_support_facade_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Facade);

PHP_METHOD(Queryyetsimple_Support_Facade, facades);
PHP_METHOD(Queryyetsimple_Support_Facade, container);
PHP_METHOD(Queryyetsimple_Support_Facade, setContainer);
PHP_METHOD(Queryyetsimple_Support_Facade, name);
PHP_METHOD(Queryyetsimple_Support_Facade, __callStatic);
void zephir_init_static_properties_Queryyetsimple_Support_Facade(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_facade_setcontainer, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Queryyetsimple\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_facade___callstatic, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_support_facade_method_entry) {
	PHP_ME(Queryyetsimple_Support_Facade, facades, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Facade, container, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Facade, setContainer, arginfo_queryyetsimple_support_facade_setcontainer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Facade, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Facade, __callStatic, arginfo_queryyetsimple_support_facade___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
