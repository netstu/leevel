
extern zend_class_entry *queryyetsimple_support_manager_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Manager);

PHP_METHOD(Queryyetsimple_Support_Manager, __construct);
PHP_METHOD(Queryyetsimple_Support_Manager, container);
PHP_METHOD(Queryyetsimple_Support_Manager, connect);
PHP_METHOD(Queryyetsimple_Support_Manager, reconnect);
PHP_METHOD(Queryyetsimple_Support_Manager, disconnect);
PHP_METHOD(Queryyetsimple_Support_Manager, getConnects);
PHP_METHOD(Queryyetsimple_Support_Manager, getDefaultDriver);
PHP_METHOD(Queryyetsimple_Support_Manager, setDefaultDriver);
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionNamespace);
PHP_METHOD(Queryyetsimple_Support_Manager, createConnect);
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionName);
PHP_METHOD(Queryyetsimple_Support_Manager, makeConnect);
PHP_METHOD(Queryyetsimple_Support_Manager, createConnectCommon);
PHP_METHOD(Queryyetsimple_Support_Manager, parseOptionAndUnique);
PHP_METHOD(Queryyetsimple_Support_Manager, parseOptionParameter);
PHP_METHOD(Queryyetsimple_Support_Manager, getUnique);
PHP_METHOD(Queryyetsimple_Support_Manager, getOption);
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionCommon);
PHP_METHOD(Queryyetsimple_Support_Manager, filterOptionCommon);
PHP_METHOD(Queryyetsimple_Support_Manager, filterOptionCommonItem);
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionConnect);
PHP_METHOD(Queryyetsimple_Support_Manager, optionFilterNull);
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionObject);
PHP_METHOD(Queryyetsimple_Support_Manager, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objContainer, Queryyetsimple\\Support\\Icontainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, mixOption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_reconnect, 0, 0, 0)
	ZEND_ARG_INFO(0, mixOption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_disconnect, 0, 0, 0)
	ZEND_ARG_INFO(0, mixOption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_setdefaultdriver, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_createconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, objConnect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_getoptionname, 0, 0, 0)
	ZEND_ARG_INFO(0, strOptionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_makeconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, strConnect)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_createconnectcommon, 0, 0, 1)
	ZEND_ARG_INFO(0, strConnect)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_parseoptionandunique, 0, 0, 0)
	ZEND_ARG_INFO(0, mixOption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_parseoptionparameter, 0, 0, 0)
	ZEND_ARG_INFO(0, mixOption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_getunique, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, strConnect)
	ZEND_ARG_ARRAY_INFO(0, arrExtendOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_filteroptioncommon, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_getoptionconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, strConnect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager_optionfilternull, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_manager___call, 0, 0, 2)
	ZEND_ARG_INFO(0, sMethod)
	ZEND_ARG_ARRAY_INFO(0, arrArgs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_support_manager_method_entry) {
	PHP_ME(Queryyetsimple_Support_Manager, __construct, arginfo_queryyetsimple_support_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Support_Manager, container, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Support_Manager, connect, arginfo_queryyetsimple_support_manager_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Support_Manager, reconnect, arginfo_queryyetsimple_support_manager_reconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Support_Manager, disconnect, arginfo_queryyetsimple_support_manager_disconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Support_Manager, getConnects, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Support_Manager, getDefaultDriver, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Support_Manager, setDefaultDriver, arginfo_queryyetsimple_support_manager_setdefaultdriver, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Support_Manager, getOptionNamespace, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, createConnect, arginfo_queryyetsimple_support_manager_createconnect, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, getOptionName, arginfo_queryyetsimple_support_manager_getoptionname, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, makeConnect, arginfo_queryyetsimple_support_manager_makeconnect, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, createConnectCommon, arginfo_queryyetsimple_support_manager_createconnectcommon, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, parseOptionAndUnique, arginfo_queryyetsimple_support_manager_parseoptionandunique, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, parseOptionParameter, arginfo_queryyetsimple_support_manager_parseoptionparameter, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, getUnique, arginfo_queryyetsimple_support_manager_getunique, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, getOption, arginfo_queryyetsimple_support_manager_getoption, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, getOptionCommon, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, filterOptionCommon, arginfo_queryyetsimple_support_manager_filteroptioncommon, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, filterOptionCommonItem, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, getOptionConnect, arginfo_queryyetsimple_support_manager_getoptionconnect, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, optionFilterNull, arginfo_queryyetsimple_support_manager_optionfilternull, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, getOptionObject, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Support_Manager, __call, arginfo_queryyetsimple_support_manager___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
