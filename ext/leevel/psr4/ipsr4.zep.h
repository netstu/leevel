
extern zend_class_entry *leevel_psr4_ipsr4_ce;

ZEPHIR_INIT_CLASS(Leevel_Psr4_IPsr4);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_ipsr4_import, 0, 0, 2)
	ZEND_ARG_INFO(0, namespaces)
	ZEND_ARG_INFO(0, package)
	ZEND_ARG_INFO(0, force)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_ipsr4_namespaces, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_ipsr4_file, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_psr4_ipsr4_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_psr4_ipsr4_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Psr4_IPsr4, composer, NULL)
	PHP_ABSTRACT_ME(Leevel_Psr4_IPsr4, import, arginfo_leevel_psr4_ipsr4_import)
	PHP_ABSTRACT_ME(Leevel_Psr4_IPsr4, namespaces, arginfo_leevel_psr4_ipsr4_namespaces)
	PHP_ABSTRACT_ME(Leevel_Psr4_IPsr4, file, arginfo_leevel_psr4_ipsr4_file)
	PHP_ABSTRACT_ME(Leevel_Psr4_IPsr4, autoload, arginfo_leevel_psr4_ipsr4_autoload)
	PHP_FE_END
};
