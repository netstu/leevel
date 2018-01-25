
extern zend_class_entry *queryyetsimple_di_provider_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Di_Provider);

PHP_METHOD(Queryyetsimple_Di_Provider, __construct);
PHP_METHOD(Queryyetsimple_Di_Provider, register);
PHP_METHOD(Queryyetsimple_Di_Provider, registerAlias);
PHP_METHOD(Queryyetsimple_Di_Provider, providers);
PHP_METHOD(Queryyetsimple_Di_Provider, isDeferred);
PHP_METHOD(Queryyetsimple_Di_Provider, container);
PHP_METHOD(Queryyetsimple_Di_Provider, bind);
PHP_METHOD(Queryyetsimple_Di_Provider, instance);
PHP_METHOD(Queryyetsimple_Di_Provider, singleton);
PHP_METHOD(Queryyetsimple_Di_Provider, share);
PHP_METHOD(Queryyetsimple_Di_Provider, alias);
PHP_METHOD(Queryyetsimple_Di_Provider, loadI18nDir);
PHP_METHOD(Queryyetsimple_Di_Provider, loadCommandNamespace);
PHP_METHOD(Queryyetsimple_Di_Provider, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_provider___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Queryyetsimple\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_provider_bind, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
	ZEND_ARG_INFO(0, share)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_provider_instance, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_provider_singleton, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_provider_share, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, closures, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_provider_alias, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_provider_loadi18ndir, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_provider_loadcommandnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_provider___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_di_provider_method_entry) {
	PHP_ME(Queryyetsimple_Di_Provider, __construct, arginfo_queryyetsimple_di_provider___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Di_Provider, register, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Di_Provider, registerAlias, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Di_Provider, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Di_Provider, isDeferred, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Di_Provider, container, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Di_Provider, bind, arginfo_queryyetsimple_di_provider_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Di_Provider, instance, arginfo_queryyetsimple_di_provider_instance, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Di_Provider, singleton, arginfo_queryyetsimple_di_provider_singleton, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Di_Provider, share, arginfo_queryyetsimple_di_provider_share, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Di_Provider, alias, arginfo_queryyetsimple_di_provider_alias, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Di_Provider, loadI18nDir, arginfo_queryyetsimple_di_provider_loadi18ndir, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Di_Provider, loadCommandNamespace, arginfo_queryyetsimple_di_provider_loadcommandnamespace, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Di_Provider, __call, arginfo_queryyetsimple_di_provider___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
