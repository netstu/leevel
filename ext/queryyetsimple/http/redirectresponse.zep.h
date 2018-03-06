
extern zend_class_entry *queryyetsimple_http_redirectresponse_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Http_RedirectResponse);

PHP_METHOD(Queryyetsimple_Http_RedirectResponse, __construct);
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, create);
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, with);
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, getTargetUrl);
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, setTargetUrl);
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, getRequest);
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, setRequest);
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, getSession);
PHP_METHOD(Queryyetsimple_Http_RedirectResponse, setSession);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_redirectresponse___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_redirectresponse_create, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_redirectresponse_with, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_redirectresponse_settargeturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_redirectresponse_setrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Queryyetsimple\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_redirectresponse_setsession, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, session, Queryyetsimple\\Session\\ISession, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_http_redirectresponse_method_entry) {
	PHP_ME(Queryyetsimple_Http_RedirectResponse, __construct, arginfo_queryyetsimple_http_redirectresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Http_RedirectResponse, create, arginfo_queryyetsimple_http_redirectresponse_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Http_RedirectResponse, with, arginfo_queryyetsimple_http_redirectresponse_with, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_RedirectResponse, getTargetUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_RedirectResponse, setTargetUrl, arginfo_queryyetsimple_http_redirectresponse_settargeturl, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_RedirectResponse, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_RedirectResponse, setRequest, arginfo_queryyetsimple_http_redirectresponse_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_RedirectResponse, getSession, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_RedirectResponse, setSession, arginfo_queryyetsimple_http_redirectresponse_setsession, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
