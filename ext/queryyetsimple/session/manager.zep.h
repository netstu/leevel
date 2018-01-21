
extern zend_class_entry *queryyetsimple_session_manager_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Session_Manager);

PHP_METHOD(Queryyetsimple_Session_Manager, getOptionNamespace);
PHP_METHOD(Queryyetsimple_Session_Manager, createConnect);
PHP_METHOD(Queryyetsimple_Session_Manager, makeConnectCookie);
PHP_METHOD(Queryyetsimple_Session_Manager, makeConnectMemcache);
PHP_METHOD(Queryyetsimple_Session_Manager, makeConnectRedis);
PHP_METHOD(Queryyetsimple_Session_Manager, getOptionConnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_manager_createconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_manager_makeconnectcookie, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_manager_makeconnectmemcache, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_manager_makeconnectredis, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_manager_getoptionconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_session_manager_method_entry) {
	PHP_ME(Queryyetsimple_Session_Manager, getOptionNamespace, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Manager, createConnect, arginfo_queryyetsimple_session_manager_createconnect, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Manager, makeConnectCookie, arginfo_queryyetsimple_session_manager_makeconnectcookie, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Manager, makeConnectMemcache, arginfo_queryyetsimple_session_manager_makeconnectmemcache, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Manager, makeConnectRedis, arginfo_queryyetsimple_session_manager_makeconnectredis, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Manager, getOptionConnect, arginfo_queryyetsimple_session_manager_getoptionconnect, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
