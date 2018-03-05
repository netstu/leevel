
extern zend_class_entry *queryyetsimple_http_file_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Http_File);

PHP_METHOD(Queryyetsimple_Http_File, __construct);
PHP_METHOD(Queryyetsimple_Http_File, move);
PHP_METHOD(Queryyetsimple_Http_File, getTargetFile);
PHP_METHOD(Queryyetsimple_Http_File, moveToTarget);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_file_move, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_file_gettargetfile, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_file_movetotarget, 0, 0, 2)
	ZEND_ARG_INFO(0, sourcePath)
	ZEND_ARG_INFO(0, target)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_http_file_method_entry) {
	PHP_ME(Queryyetsimple_Http_File, __construct, arginfo_queryyetsimple_http_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Http_File, move, arginfo_queryyetsimple_http_file_move, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_File, getTargetFile, arginfo_queryyetsimple_http_file_gettargetfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_File, moveToTarget, arginfo_queryyetsimple_http_file_movetotarget, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
