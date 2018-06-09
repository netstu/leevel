
extern zend_class_entry *leevel_bootstrap_project_ce;

ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Project);

PHP_METHOD(Leevel_Bootstrap_Project, __construct);
PHP_METHOD(Leevel_Bootstrap_Project, __clone);
PHP_METHOD(Leevel_Bootstrap_Project, singletons);
PHP_METHOD(Leevel_Bootstrap_Project, version);
PHP_METHOD(Leevel_Bootstrap_Project, runWithExtension);
PHP_METHOD(Leevel_Bootstrap_Project, make);
PHP_METHOD(Leevel_Bootstrap_Project, setPath);
PHP_METHOD(Leevel_Bootstrap_Project, path);
PHP_METHOD(Leevel_Bootstrap_Project, pathApplication);
PHP_METHOD(Leevel_Bootstrap_Project, setPathApplication);
PHP_METHOD(Leevel_Bootstrap_Project, setPathCommon);
PHP_METHOD(Leevel_Bootstrap_Project, pathCommon);
PHP_METHOD(Leevel_Bootstrap_Project, setPathRuntime);
PHP_METHOD(Leevel_Bootstrap_Project, pathRuntime);
PHP_METHOD(Leevel_Bootstrap_Project, setPathStorage);
PHP_METHOD(Leevel_Bootstrap_Project, pathStorage);
PHP_METHOD(Leevel_Bootstrap_Project, setPathOption);
PHP_METHOD(Leevel_Bootstrap_Project, pathOption);
PHP_METHOD(Leevel_Bootstrap_Project, setPathI18n);
PHP_METHOD(Leevel_Bootstrap_Project, pathI18n);
PHP_METHOD(Leevel_Bootstrap_Project, pathEnv);
PHP_METHOD(Leevel_Bootstrap_Project, setPathEnv);
PHP_METHOD(Leevel_Bootstrap_Project, setEnvFile);
PHP_METHOD(Leevel_Bootstrap_Project, envFile);
PHP_METHOD(Leevel_Bootstrap_Project, fullEnvPath);
PHP_METHOD(Leevel_Bootstrap_Project, pathAnApplication);
PHP_METHOD(Leevel_Bootstrap_Project, pathApplicationCache);
PHP_METHOD(Leevel_Bootstrap_Project, pathApplicationTheme);
PHP_METHOD(Leevel_Bootstrap_Project, pathCacheI18nFile);
PHP_METHOD(Leevel_Bootstrap_Project, isCachedI18n);
PHP_METHOD(Leevel_Bootstrap_Project, pathCacheOptionFile);
PHP_METHOD(Leevel_Bootstrap_Project, isCachedOption);
PHP_METHOD(Leevel_Bootstrap_Project, composer);
PHP_METHOD(Leevel_Bootstrap_Project, getPathByNamespace);
PHP_METHOD(Leevel_Bootstrap_Project, getPathByNamespaces);
PHP_METHOD(Leevel_Bootstrap_Project, debug);
PHP_METHOD(Leevel_Bootstrap_Project, development);
PHP_METHOD(Leevel_Bootstrap_Project, environment);
PHP_METHOD(Leevel_Bootstrap_Project, api);
PHP_METHOD(Leevel_Bootstrap_Project, console);
PHP_METHOD(Leevel_Bootstrap_Project, makeProvider);
PHP_METHOD(Leevel_Bootstrap_Project, callProviderBootstrap);
PHP_METHOD(Leevel_Bootstrap_Project, bootstrap);
PHP_METHOD(Leevel_Bootstrap_Project, isBootstrap);
PHP_METHOD(Leevel_Bootstrap_Project, registerProviders);
PHP_METHOD(Leevel_Bootstrap_Project, bootstrapProviders);
PHP_METHOD(Leevel_Bootstrap_Project, register);
PHP_METHOD(Leevel_Bootstrap_Project, registerBaseServices);
PHP_METHOD(Leevel_Bootstrap_Project, registerBaseProvider);
PHP_METHOD(Leevel_Bootstrap_Project, registerDeferredProvider);
zend_object *zephir_init_properties_Leevel_Bootstrap_Project(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_singletons, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_make, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpathapplication, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpathcommon, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpathruntime, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpathstorage, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpathoption, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpathi18n, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpathenv, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setenvfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_pathanapplication, 0, 0, 0)
	ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_pathapplicationcache, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_pathapplicationtheme, 0, 0, 0)
	ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_pathcachei18nfile, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_iscachedi18n, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_getpathbynamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_getpathbynamespaces, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, namespaces, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_makeprovider, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_callproviderbootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Leevel\\Di\\Provider, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_bootstrap, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bootstraps, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_register, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_registerdeferredprovider, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_bootstrap_project_method_entry) {
	PHP_ME(Leevel_Bootstrap_Project, __construct, arginfo_leevel_bootstrap_project___construct, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Bootstrap_Project, __clone, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Project, singletons, arginfo_leevel_bootstrap_project_singletons, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Bootstrap_Project, version, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, runWithExtension, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, make, arginfo_leevel_bootstrap_project_make, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPath, arginfo_leevel_bootstrap_project_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, path, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathApplication, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPathApplication, arginfo_leevel_bootstrap_project_setpathapplication, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPathCommon, arginfo_leevel_bootstrap_project_setpathcommon, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathCommon, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPathRuntime, arginfo_leevel_bootstrap_project_setpathruntime, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathRuntime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPathStorage, arginfo_leevel_bootstrap_project_setpathstorage, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathStorage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPathOption, arginfo_leevel_bootstrap_project_setpathoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathOption, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPathI18n, arginfo_leevel_bootstrap_project_setpathi18n, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathI18n, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathEnv, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPathEnv, arginfo_leevel_bootstrap_project_setpathenv, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setEnvFile, arginfo_leevel_bootstrap_project_setenvfile, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, envFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, fullEnvPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathAnApplication, arginfo_leevel_bootstrap_project_pathanapplication, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathApplicationCache, arginfo_leevel_bootstrap_project_pathapplicationcache, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathApplicationTheme, arginfo_leevel_bootstrap_project_pathapplicationtheme, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathCacheI18nFile, arginfo_leevel_bootstrap_project_pathcachei18nfile, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, isCachedI18n, arginfo_leevel_bootstrap_project_iscachedi18n, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, pathCacheOptionFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, isCachedOption, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, composer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, getPathByNamespace, arginfo_leevel_bootstrap_project_getpathbynamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, getPathByNamespaces, arginfo_leevel_bootstrap_project_getpathbynamespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, debug, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, development, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, environment, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, api, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, console, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, makeProvider, arginfo_leevel_bootstrap_project_makeprovider, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, callProviderBootstrap, arginfo_leevel_bootstrap_project_callproviderbootstrap, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, bootstrap, arginfo_leevel_bootstrap_project_bootstrap, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, isBootstrap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, registerProviders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, bootstrapProviders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, register, arginfo_leevel_bootstrap_project_register, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, registerBaseServices, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Project, registerBaseProvider, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Project, registerDeferredProvider, arginfo_leevel_bootstrap_project_registerdeferredprovider, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
