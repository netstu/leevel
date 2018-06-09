
extern zend_class_entry *leevel_kernel_iproject_ce;

ZEPHIR_INIT_CLASS(Leevel_Kernel_IProject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_singletons, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_make, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpathapplication, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpathcommon, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpathruntime, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpathstorage, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpathoption, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpathi18n, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpathenv, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setenvfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_pathanapplication, 0, 0, 0)
	ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_pathapplicationcache, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_pathapplicationtheme, 0, 0, 0)
	ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_pathcachei18nfile, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_iscachedi18n, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_getpathbynamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_getpathbynamespaces, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, namespaces, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_makeprovider, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_callproviderbootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Leevel\\Di\\Provider, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_bootstrap, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bootstraps, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_register, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_kernel_iproject_method_entry) {
	ZEND_FENTRY(singletons, NULL, arginfo_leevel_kernel_iproject_singletons, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, version, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, runWithExtension, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, make, arginfo_leevel_kernel_iproject_make)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPath, arginfo_leevel_kernel_iproject_setpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, path, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathApplication, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPathApplication, arginfo_leevel_kernel_iproject_setpathapplication)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPathCommon, arginfo_leevel_kernel_iproject_setpathcommon)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathCommon, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPathRuntime, arginfo_leevel_kernel_iproject_setpathruntime)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathRuntime, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPathStorage, arginfo_leevel_kernel_iproject_setpathstorage)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathStorage, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPathOption, arginfo_leevel_kernel_iproject_setpathoption)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathOption, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPathI18n, arginfo_leevel_kernel_iproject_setpathi18n)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathI18n, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathEnv, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPathEnv, arginfo_leevel_kernel_iproject_setpathenv)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setEnvFile, arginfo_leevel_kernel_iproject_setenvfile)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, envFile, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, fullEnvPath, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathAnApplication, arginfo_leevel_kernel_iproject_pathanapplication)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathApplicationCache, arginfo_leevel_kernel_iproject_pathapplicationcache)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathApplicationTheme, arginfo_leevel_kernel_iproject_pathapplicationtheme)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathCacheI18nFile, arginfo_leevel_kernel_iproject_pathcachei18nfile)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, isCachedI18n, arginfo_leevel_kernel_iproject_iscachedi18n)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, pathCacheOptionFile, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, isCachedOption, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, composer, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, getPathByNamespace, arginfo_leevel_kernel_iproject_getpathbynamespace)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, getPathByNamespaces, arginfo_leevel_kernel_iproject_getpathbynamespaces)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, debug, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, development, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, environment, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, api, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, console, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, makeProvider, arginfo_leevel_kernel_iproject_makeprovider)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, callProviderBootstrap, arginfo_leevel_kernel_iproject_callproviderbootstrap)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, bootstrap, arginfo_leevel_kernel_iproject_bootstrap)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, isBootstrap, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, registerProviders, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, bootstrapProviders, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, register, arginfo_leevel_kernel_iproject_register)
	PHP_FE_END
};
