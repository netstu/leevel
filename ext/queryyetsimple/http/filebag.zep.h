
extern zend_class_entry *queryyetsimple_http_filebag_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Http_FileBag);

PHP_METHOD(Queryyetsimple_Http_FileBag, __construct);
PHP_METHOD(Queryyetsimple_Http_FileBag, replace);
PHP_METHOD(Queryyetsimple_Http_FileBag, set);
PHP_METHOD(Queryyetsimple_Http_FileBag, add);
PHP_METHOD(Queryyetsimple_Http_FileBag, getArr);
PHP_METHOD(Queryyetsimple_Http_FileBag, convertFile);
PHP_METHOD(Queryyetsimple_Http_FileBag, normalizeFile);
PHP_METHOD(Queryyetsimple_Http_FileBag, normalizeArray);
PHP_METHOD(Queryyetsimple_Http_FileBag, normalizeKey);
void zephir_init_static_properties_Queryyetsimple_Http_FileBag(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_filebag___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_filebag_replace, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_filebag_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_filebag_add, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, files, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_filebag_getarr, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, defaults, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_filebag_convertfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_filebag_normalizefile, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_filebag_normalizearray, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, elements, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_filebag_normalizekey, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_http_filebag_method_entry) {
	PHP_ME(Queryyetsimple_Http_FileBag, __construct, arginfo_queryyetsimple_http_filebag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Http_FileBag, replace, arginfo_queryyetsimple_http_filebag_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_FileBag, set, arginfo_queryyetsimple_http_filebag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_FileBag, add, arginfo_queryyetsimple_http_filebag_add, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_FileBag, getArr, arginfo_queryyetsimple_http_filebag_getarr, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_FileBag, convertFile, arginfo_queryyetsimple_http_filebag_convertfile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_FileBag, normalizeFile, arginfo_queryyetsimple_http_filebag_normalizefile, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_FileBag, normalizeArray, arginfo_queryyetsimple_http_filebag_normalizearray, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_FileBag, normalizeKey, arginfo_queryyetsimple_http_filebag_normalizekey, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
