
extern zend_class_entry *leevel_i18n_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_I18n_Provider_Register);

PHP_METHOD(Leevel_I18n_Provider_Register, __construct);
PHP_METHOD(Leevel_I18n_Provider_Register, register);
PHP_METHOD(Leevel_I18n_Provider_Register, bootstrap);
PHP_METHOD(Leevel_I18n_Provider_Register, providers);
PHP_METHOD(Leevel_I18n_Provider_Register, i18n);
PHP_METHOD(Leevel_I18n_Provider_Register, i18nLoad);
PHP_METHOD(Leevel_I18n_Provider_Register, console);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_i18n_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_i18n_provider_register_method_entry) {
	PHP_ME(Leevel_I18n_Provider_Register, __construct, arginfo_leevel_i18n_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_I18n_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_I18n_Provider_Register, bootstrap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_I18n_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_I18n_Provider_Register, i18n, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_I18n_Provider_Register, i18nLoad, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_I18n_Provider_Register, console, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
