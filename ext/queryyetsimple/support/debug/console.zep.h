
extern zend_class_entry *queryyetsimple_support_debug_console_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Debug_Console);

PHP_METHOD(Queryyetsimple_Support_Debug_Console, trace);
PHP_METHOD(Queryyetsimple_Support_Debug_Console, formatMessage);
PHP_METHOD(Queryyetsimple_Support_Debug_Console, formatLogo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_debug_console_formatmessage, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrItem, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_support_debug_console_method_entry) {
	PHP_ME(Queryyetsimple_Support_Debug_Console, trace, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Debug_Console, formatMessage, arginfo_queryyetsimple_support_debug_console_formatmessage, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Debug_Console, formatLogo, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
