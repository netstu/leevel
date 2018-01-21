
extern zend_class_entry *queryyetsimple_view_manager_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_View_Manager);

PHP_METHOD(Queryyetsimple_View_Manager, getOptionNamespace);
PHP_METHOD(Queryyetsimple_View_Manager, createConnect);
PHP_METHOD(Queryyetsimple_View_Manager, makeConnectHtml);
PHP_METHOD(Queryyetsimple_View_Manager, makeConnectTwig);
PHP_METHOD(Queryyetsimple_View_Manager, makeConnectPhpui);
PHP_METHOD(Queryyetsimple_View_Manager, makeConnectV8);
PHP_METHOD(Queryyetsimple_View_Manager, viewOptionCommon);
PHP_METHOD(Queryyetsimple_View_Manager, makeParserClosure);
PHP_METHOD(Queryyetsimple_View_Manager, makeTwigParserClosure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_manager_createconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_manager_makeconnecthtml, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_manager_makeconnecttwig, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_manager_makeconnectphpui, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_view_manager_makeconnectv8, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_view_manager_method_entry) {
	PHP_ME(Queryyetsimple_View_Manager, getOptionNamespace, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Manager, createConnect, arginfo_queryyetsimple_view_manager_createconnect, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Manager, makeConnectHtml, arginfo_queryyetsimple_view_manager_makeconnecthtml, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Manager, makeConnectTwig, arginfo_queryyetsimple_view_manager_makeconnecttwig, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Manager, makeConnectPhpui, arginfo_queryyetsimple_view_manager_makeconnectphpui, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Manager, makeConnectV8, arginfo_queryyetsimple_view_manager_makeconnectv8, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Manager, viewOptionCommon, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Manager, makeParserClosure, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_View_Manager, makeTwigParserClosure, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
