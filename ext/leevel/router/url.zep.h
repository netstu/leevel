
extern zend_class_entry *leevel_router_url_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_Url);

PHP_METHOD(Leevel_Router_Url, __construct);
PHP_METHOD(Leevel_Router_Url, make);
PHP_METHOD(Leevel_Router_Url, getRequest);
PHP_METHOD(Leevel_Router_Url, option);
PHP_METHOD(Leevel_Router_Url, optionArray);
PHP_METHOD(Leevel_Router_Url, options);
PHP_METHOD(Leevel_Router_Url, getOption);
PHP_METHOD(Leevel_Router_Url, getOptions);
PHP_METHOD(Leevel_Router_Url, deleteOption);
PHP_METHOD(Leevel_Router_Url, deleteOptions);
PHP_METHOD(Leevel_Router_Url, pathinfoUrl);
PHP_METHOD(Leevel_Router_Url, customUrl);
PHP_METHOD(Leevel_Router_Url, matchVar);
PHP_METHOD(Leevel_Router_Url, normalUrl);
PHP_METHOD(Leevel_Router_Url, parseMvc);
PHP_METHOD(Leevel_Router_Url, urlWithDomain);
PHP_METHOD(Leevel_Router_Url, isSecure);
PHP_METHOD(Leevel_Router_Url, isNotNormal);
PHP_METHOD(Leevel_Router_Url, withSuffix);
PHP_METHOD(Leevel_Router_Url, equalDefault);
PHP_METHOD(Leevel_Router_Url, parseEnter);
PHP_METHOD(Leevel_Router_Url, isCustom);
zend_object *zephir_init_properties_Leevel_Router_Url(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_make, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_option, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultss)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_customurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_matchvar, 0, 0, 1)
	ZEND_ARG_INFO(0, matchs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_normalurl, 0, 0, 1)
	ZEND_ARG_INFO(0, normal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_parsemvc, 0, 0, 3)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, custom)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_urlwithdomain, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_isnotnormal, 0, 0, 2)
	ZEND_ARG_INFO(0, normal)
	ZEND_ARG_INFO(0, custom)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_withsuffix, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, suffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_equaldefault, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_parseenter, 0, 0, 0)
	ZEND_ARG_INFO(0, normal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_iscustom, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_url_method_entry) {
	PHP_ME(Leevel_Router_Url, __construct, arginfo_leevel_router_url___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Router_Url, make, arginfo_leevel_router_url_make, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, option, arginfo_leevel_router_url_option, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, optionArray, arginfo_leevel_router_url_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, options, arginfo_leevel_router_url_options, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, getOption, arginfo_leevel_router_url_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, getOptions, arginfo_leevel_router_url_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, deleteOption, arginfo_leevel_router_url_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, deleteOptions, arginfo_leevel_router_url_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, pathinfoUrl, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, customUrl, arginfo_leevel_router_url_customurl, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, matchVar, arginfo_leevel_router_url_matchvar, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, normalUrl, arginfo_leevel_router_url_normalurl, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, parseMvc, arginfo_leevel_router_url_parsemvc, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, urlWithDomain, arginfo_leevel_router_url_urlwithdomain, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, isSecure, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, isNotNormal, arginfo_leevel_router_url_isnotnormal, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, withSuffix, arginfo_leevel_router_url_withsuffix, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, equalDefault, arginfo_leevel_router_url_equaldefault, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, parseEnter, arginfo_leevel_router_url_parseenter, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, isCustom, arginfo_leevel_router_url_iscustom, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
