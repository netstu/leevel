
extern zend_class_entry *leevel_session_manager_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_Manager);

PHP_METHOD(Leevel_Session_Manager, normalizeOptionNamespace);
PHP_METHOD(Leevel_Session_Manager, createConnect);
PHP_METHOD(Leevel_Session_Manager, makeConnectCookie);
PHP_METHOD(Leevel_Session_Manager, makeConnectMemcache);
PHP_METHOD(Leevel_Session_Manager, makeConnectRedis);
PHP_METHOD(Leevel_Session_Manager, getConnectOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_createconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_makeconnectcookie, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_makeconnectmemcache, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_makeconnectredis, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_getconnectoption, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_manager_method_entry) {
	PHP_ME(Leevel_Session_Manager, normalizeOptionNamespace, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, createConnect, arginfo_leevel_session_manager_createconnect, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, makeConnectCookie, arginfo_leevel_session_manager_makeconnectcookie, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, makeConnectMemcache, arginfo_leevel_session_manager_makeconnectmemcache, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, makeConnectRedis, arginfo_leevel_session_manager_makeconnectredis, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, getConnectOption, arginfo_leevel_session_manager_getconnectoption, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
