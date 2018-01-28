
extern zend_class_entry *queryyetsimple_router_provider_register_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Router_Provider_Register);

PHP_METHOD(Queryyetsimple_Router_Provider_Register, __construct);
PHP_METHOD(Queryyetsimple_Router_Provider_Register, register);
PHP_METHOD(Queryyetsimple_Router_Provider_Register, providers);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_router_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Queryyetsimple\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_router_provider_register_method_entry) {
	PHP_ME(Queryyetsimple_Router_Provider_Register, __construct, arginfo_queryyetsimple_router_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Router_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Router_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
