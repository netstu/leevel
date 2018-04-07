
extern zend_class_entry *leevel_psr4_psr4_ce;

ZEPHIR_INIT_CLASS(Leevel_Psr4_Psr4);

PHP_METHOD(Leevel_Psr4_Psr4, __construct);
PHP_METHOD(Leevel_Psr4_Psr4, composer);
PHP_METHOD(Leevel_Psr4_Psr4, import);
PHP_METHOD(Leevel_Psr4_Psr4, namespaces);
PHP_METHOD(Leevel_Psr4_Psr4, file);
PHP_METHOD(Leevel_Psr4_Psr4, autoload);
PHP_METHOD(Leevel_Psr4_Psr4, shortNamespaceMap);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_psr4___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, composer, Composer\\Autoload\\ClassLoader, 0)
	ZEND_ARG_INFO(0, sandbox)
	ZEND_ARG_INFO(0, namespaces)
	ZEND_ARG_INFO(0, shortNamespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_psr4_import, 0, 0, 2)
	ZEND_ARG_INFO(0, namespaces)
	ZEND_ARG_INFO(0, package)
	ZEND_ARG_INFO(0, force)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_psr4_namespaces, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_psr4_file, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_psr4_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_psr4_shortnamespacemap, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_psr4_psr4_method_entry) {
	PHP_ME(Leevel_Psr4_Psr4, __construct, arginfo_leevel_psr4_psr4___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Psr4_Psr4, composer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Psr4_Psr4, import, arginfo_leevel_psr4_psr4_import, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Psr4_Psr4, namespaces, arginfo_leevel_psr4_psr4_namespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Psr4_Psr4, file, arginfo_leevel_psr4_psr4_file, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Psr4_Psr4, autoload, arginfo_leevel_psr4_psr4_autoload, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Psr4_Psr4, shortNamespaceMap, arginfo_leevel_psr4_psr4_shortnamespacemap, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
