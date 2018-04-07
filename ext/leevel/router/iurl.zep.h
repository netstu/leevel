
extern zend_class_entry *leevel_router_iurl_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_IUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_iurl_make, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_iurl_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Router_IUrl, make, arginfo_leevel_router_iurl_make)
	PHP_ABSTRACT_ME(Leevel_Router_IUrl, getRequest, NULL)
	PHP_FE_END
};
