
extern zend_class_entry *queryyetsimple_http_jsonresponse_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Http_JsonResponse);

PHP_METHOD(Queryyetsimple_Http_JsonResponse, __construct);
PHP_METHOD(Queryyetsimple_Http_JsonResponse, fromJsonString);
PHP_METHOD(Queryyetsimple_Http_JsonResponse, setCallback);
PHP_METHOD(Queryyetsimple_Http_JsonResponse, setJson);
PHP_METHOD(Queryyetsimple_Http_JsonResponse, setData);
PHP_METHOD(Queryyetsimple_Http_JsonResponse, getData);
PHP_METHOD(Queryyetsimple_Http_JsonResponse, getEncodingOptions);
PHP_METHOD(Queryyetsimple_Http_JsonResponse, setEncodingOptions);
PHP_METHOD(Queryyetsimple_Http_JsonResponse, isJsonData);
PHP_METHOD(Queryyetsimple_Http_JsonResponse, updateContent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_jsonresponse___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, json)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_jsonresponse_fromjsonstring, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_jsonresponse_setcallback, 0, 0, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_jsonresponse_setjson, 0, 0, 1)
	ZEND_ARG_INFO(0, json)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_jsonresponse_setdata, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, encodingOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_jsonresponse_getdata, 0, 0, 0)
	ZEND_ARG_INFO(0, assoc)
	ZEND_ARG_INFO(0, depth)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_jsonresponse_setencodingoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, encodingOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_jsonresponse_isjsondata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_http_jsonresponse_method_entry) {
	PHP_ME(Queryyetsimple_Http_JsonResponse, __construct, arginfo_queryyetsimple_http_jsonresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Http_JsonResponse, fromJsonString, arginfo_queryyetsimple_http_jsonresponse_fromjsonstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Http_JsonResponse, setCallback, arginfo_queryyetsimple_http_jsonresponse_setcallback, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_JsonResponse, setJson, arginfo_queryyetsimple_http_jsonresponse_setjson, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_JsonResponse, setData, arginfo_queryyetsimple_http_jsonresponse_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_JsonResponse, getData, arginfo_queryyetsimple_http_jsonresponse_getdata, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_JsonResponse, getEncodingOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_JsonResponse, setEncodingOptions, arginfo_queryyetsimple_http_jsonresponse_setencodingoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_JsonResponse, isJsonData, arginfo_queryyetsimple_http_jsonresponse_isjsondata, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_JsonResponse, updateContent, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};