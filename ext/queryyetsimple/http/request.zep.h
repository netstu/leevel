
extern zend_class_entry *queryyetsimple_http_request_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Http_Request);

PHP_METHOD(Queryyetsimple_Http_Request, __construct);
PHP_METHOD(Queryyetsimple_Http_Request, reset);
PHP_METHOD(Queryyetsimple_Http_Request, createFromGlobals);
PHP_METHOD(Queryyetsimple_Http_Request, normalizeRequestFromContent);
PHP_METHOD(Queryyetsimple_Http_Request, get);
PHP_METHOD(Queryyetsimple_Http_Request, exists);
PHP_METHOD(Queryyetsimple_Http_Request, has);
PHP_METHOD(Queryyetsimple_Http_Request, only);
PHP_METHOD(Queryyetsimple_Http_Request, except);
PHP_METHOD(Queryyetsimple_Http_Request, all);
PHP_METHOD(Queryyetsimple_Http_Request, input);
PHP_METHOD(Queryyetsimple_Http_Request, query);
PHP_METHOD(Queryyetsimple_Http_Request, hasCookie);
PHP_METHOD(Queryyetsimple_Http_Request, cookie);
PHP_METHOD(Queryyetsimple_Http_Request, allFiles);
PHP_METHOD(Queryyetsimple_Http_Request, file);
PHP_METHOD(Queryyetsimple_Http_Request, hasFile);
PHP_METHOD(Queryyetsimple_Http_Request, isValidFile);
PHP_METHOD(Queryyetsimple_Http_Request, header);
PHP_METHOD(Queryyetsimple_Http_Request, server);
PHP_METHOD(Queryyetsimple_Http_Request, getItem);
PHP_METHOD(Queryyetsimple_Http_Request, merge);
PHP_METHOD(Queryyetsimple_Http_Request, replace);
PHP_METHOD(Queryyetsimple_Http_Request, isCli);
PHP_METHOD(Queryyetsimple_Http_Request, isRealCli);
PHP_METHOD(Queryyetsimple_Http_Request, isCgi);
PHP_METHOD(Queryyetsimple_Http_Request, isAjax);
PHP_METHOD(Queryyetsimple_Http_Request, isRealAjax);
PHP_METHOD(Queryyetsimple_Http_Request, isXmlHttpRequest);
PHP_METHOD(Queryyetsimple_Http_Request, isPjax);
PHP_METHOD(Queryyetsimple_Http_Request, isRealPjax);
PHP_METHOD(Queryyetsimple_Http_Request, isMobile);
PHP_METHOD(Queryyetsimple_Http_Request, isHead);
PHP_METHOD(Queryyetsimple_Http_Request, isGet);
PHP_METHOD(Queryyetsimple_Http_Request, isPost);
PHP_METHOD(Queryyetsimple_Http_Request, isPut);
PHP_METHOD(Queryyetsimple_Http_Request, isPatch);
PHP_METHOD(Queryyetsimple_Http_Request, isPurge);
PHP_METHOD(Queryyetsimple_Http_Request, isOptions);
PHP_METHOD(Queryyetsimple_Http_Request, isTrace);
PHP_METHOD(Queryyetsimple_Http_Request, isConnect);
PHP_METHOD(Queryyetsimple_Http_Request, getClientIp);
PHP_METHOD(Queryyetsimple_Http_Request, getMethod);
PHP_METHOD(Queryyetsimple_Http_Request, setMethod);
PHP_METHOD(Queryyetsimple_Http_Request, getRealMethod);
PHP_METHOD(Queryyetsimple_Http_Request, isMethod);
PHP_METHOD(Queryyetsimple_Http_Request, app);
PHP_METHOD(Queryyetsimple_Http_Request, controller);
PHP_METHOD(Queryyetsimple_Http_Request, action);
PHP_METHOD(Queryyetsimple_Http_Request, getNode);
PHP_METHOD(Queryyetsimple_Http_Request, setApp);
PHP_METHOD(Queryyetsimple_Http_Request, setController);
PHP_METHOD(Queryyetsimple_Http_Request, setAction);
PHP_METHOD(Queryyetsimple_Http_Request, language);
PHP_METHOD(Queryyetsimple_Http_Request, getLanguage);
PHP_METHOD(Queryyetsimple_Http_Request, setLanguage);
PHP_METHOD(Queryyetsimple_Http_Request, getContent);
PHP_METHOD(Queryyetsimple_Http_Request, getPublicUrl);
PHP_METHOD(Queryyetsimple_Http_Request, setPublicUrl);
PHP_METHOD(Queryyetsimple_Http_Request, getRoot);
PHP_METHOD(Queryyetsimple_Http_Request, getEnter);
PHP_METHOD(Queryyetsimple_Http_Request, getScriptName);
PHP_METHOD(Queryyetsimple_Http_Request, isSecure);
PHP_METHOD(Queryyetsimple_Http_Request, getHttpHost);
PHP_METHOD(Queryyetsimple_Http_Request, getHost);
PHP_METHOD(Queryyetsimple_Http_Request, getSchemeAndHttpHost);
PHP_METHOD(Queryyetsimple_Http_Request, getUri);
PHP_METHOD(Queryyetsimple_Http_Request, getPort);
PHP_METHOD(Queryyetsimple_Http_Request, getScheme);
PHP_METHOD(Queryyetsimple_Http_Request, getQueryString);
PHP_METHOD(Queryyetsimple_Http_Request, setPathInfo);
PHP_METHOD(Queryyetsimple_Http_Request, getPathInfo);
PHP_METHOD(Queryyetsimple_Http_Request, getBasePath);
PHP_METHOD(Queryyetsimple_Http_Request, getBaseUrl);
PHP_METHOD(Queryyetsimple_Http_Request, getRequestUri);
PHP_METHOD(Queryyetsimple_Http_Request, option);
PHP_METHOD(Queryyetsimple_Http_Request, optionArray);
PHP_METHOD(Queryyetsimple_Http_Request, options);
PHP_METHOD(Queryyetsimple_Http_Request, getOption);
PHP_METHOD(Queryyetsimple_Http_Request, getOptions);
PHP_METHOD(Queryyetsimple_Http_Request, deleteOption);
PHP_METHOD(Queryyetsimple_Http_Request, deleteOptions);
PHP_METHOD(Queryyetsimple_Http_Request, macro);
PHP_METHOD(Queryyetsimple_Http_Request, hasMacro);
PHP_METHOD(Queryyetsimple_Http_Request, callStaticMacro);
PHP_METHOD(Queryyetsimple_Http_Request, callMacro);
PHP_METHOD(Queryyetsimple_Http_Request, isInt);
PHP_METHOD(Queryyetsimple_Http_Request, parsePathInfo);
PHP_METHOD(Queryyetsimple_Http_Request, normalizeQueryString);
PHP_METHOD(Queryyetsimple_Http_Request, getInputSource);
PHP_METHOD(Queryyetsimple_Http_Request, isEmptyString);
PHP_METHOD(Queryyetsimple_Http_Request, getUrlencodedPrefix);
PHP_METHOD(Queryyetsimple_Http_Request, toArray);
PHP_METHOD(Queryyetsimple_Http_Request, offsetExists);
PHP_METHOD(Queryyetsimple_Http_Request, offsetGet);
PHP_METHOD(Queryyetsimple_Http_Request, offsetSet);
PHP_METHOD(Queryyetsimple_Http_Request, offsetUnset);
PHP_METHOD(Queryyetsimple_Http_Request, __isset);
PHP_METHOD(Queryyetsimple_Http_Request, __get);
PHP_METHOD(Queryyetsimple_Http_Request, __callStatic);
PHP_METHOD(Queryyetsimple_Http_Request, __call);
void zephir_init_static_properties_Queryyetsimple_Http_Request(TSRMLS_D);
zend_object *zephir_init_properties_Queryyetsimple_Http_Request(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
	ZEND_ARG_ARRAY_INFO(0, request, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_ARRAY_INFO(0, cookies, 1)
	ZEND_ARG_ARRAY_INFO(0, files, 1)
	ZEND_ARG_ARRAY_INFO(0, server, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_reset, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, query, 1)
	ZEND_ARG_ARRAY_INFO(0, request, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_ARRAY_INFO(0, cookies, 1)
	ZEND_ARG_ARRAY_INFO(0, files, 1)
	ZEND_ARG_ARRAY_INFO(0, server, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_createfromglobals, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_normalizerequestfromcontent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Queryyetsimple\\Http\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_input, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_query, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_hascookie, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_cookie, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_file, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_hasfile, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_isvalidfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_header, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_server, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_getitem, 0, 0, 3)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_merge, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, input, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_replace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, input, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_setmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_ismethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_setapp, 0, 0, 1)
	ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_setcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controller)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_setaction, 0, 0, 1)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_setlanguage, 0, 0, 1)
	ZEND_ARG_INFO(0, language)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_setpublicurl, 0, 0, 1)
	ZEND_ARG_INFO(0, publicUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_setpathinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, pathInfo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_option, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_macro, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, macro)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_hasmacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_callstaticmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_callmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_isint, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_parsepathinfo, 0, 0, 1)
	ZEND_ARG_INFO(0, pathInfo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_normalizequerystring, 0, 0, 1)
	ZEND_ARG_INFO(0, queryString)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_isemptystring, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_geturlencodedprefix, 0, 0, 2)
	ZEND_ARG_INFO(0, strings)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request___callstatic, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_request___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_http_request_method_entry) {
	PHP_ME(Queryyetsimple_Http_Request, __construct, arginfo_queryyetsimple_http_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Http_Request, reset, arginfo_queryyetsimple_http_request_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, createFromGlobals, arginfo_queryyetsimple_http_request_createfromglobals, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Http_Request, normalizeRequestFromContent, arginfo_queryyetsimple_http_request_normalizerequestfromcontent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Http_Request, get, arginfo_queryyetsimple_http_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, exists, arginfo_queryyetsimple_http_request_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, has, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, only, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, except, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, input, arginfo_queryyetsimple_http_request_input, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, query, arginfo_queryyetsimple_http_request_query, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, hasCookie, arginfo_queryyetsimple_http_request_hascookie, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, cookie, arginfo_queryyetsimple_http_request_cookie, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, allFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, file, arginfo_queryyetsimple_http_request_file, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, hasFile, arginfo_queryyetsimple_http_request_hasfile, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isValidFile, arginfo_queryyetsimple_http_request_isvalidfile, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, header, arginfo_queryyetsimple_http_request_header, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, server, arginfo_queryyetsimple_http_request_server, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getItem, arginfo_queryyetsimple_http_request_getitem, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, merge, arginfo_queryyetsimple_http_request_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, replace, arginfo_queryyetsimple_http_request_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isCli, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isRealCli, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isCgi, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isAjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isRealAjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isXmlHttpRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isPjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isRealPjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isMobile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isHead, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isGet, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isPost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isPut, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isPatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isPurge, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isTrace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isConnect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getClientIp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, setMethod, arginfo_queryyetsimple_http_request_setmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getRealMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isMethod, arginfo_queryyetsimple_http_request_ismethod, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, app, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, controller, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, action, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getNode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, setApp, arginfo_queryyetsimple_http_request_setapp, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, setController, arginfo_queryyetsimple_http_request_setcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, setAction, arginfo_queryyetsimple_http_request_setaction, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, language, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getLanguage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, setLanguage, arginfo_queryyetsimple_http_request_setlanguage, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getPublicUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, setPublicUrl, arginfo_queryyetsimple_http_request_setpublicurl, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getRoot, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getEnter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getScriptName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isSecure, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getHttpHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getSchemeAndHttpHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getPort, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getScheme, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getQueryString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, setPathInfo, arginfo_queryyetsimple_http_request_setpathinfo, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getPathInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getBasePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getBaseUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getRequestUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, option, arginfo_queryyetsimple_http_request_option, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, optionArray, arginfo_queryyetsimple_http_request_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, options, arginfo_queryyetsimple_http_request_options, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getOption, arginfo_queryyetsimple_http_request_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, getOptions, arginfo_queryyetsimple_http_request_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, deleteOption, arginfo_queryyetsimple_http_request_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, deleteOptions, arginfo_queryyetsimple_http_request_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, macro, arginfo_queryyetsimple_http_request_macro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Http_Request, hasMacro, arginfo_queryyetsimple_http_request_hasmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Http_Request, callStaticMacro, arginfo_queryyetsimple_http_request_callstaticmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Http_Request, callMacro, arginfo_queryyetsimple_http_request_callmacro, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, isInt, arginfo_queryyetsimple_http_request_isint, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Request, parsePathInfo, arginfo_queryyetsimple_http_request_parsepathinfo, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Request, normalizeQueryString, arginfo_queryyetsimple_http_request_normalizequerystring, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Request, getInputSource, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Request, isEmptyString, arginfo_queryyetsimple_http_request_isemptystring, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Request, getUrlencodedPrefix, arginfo_queryyetsimple_http_request_geturlencodedprefix, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Request, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, offsetExists, arginfo_queryyetsimple_http_request_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, offsetGet, arginfo_queryyetsimple_http_request_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, offsetSet, arginfo_queryyetsimple_http_request_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, offsetUnset, arginfo_queryyetsimple_http_request_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, __isset, arginfo_queryyetsimple_http_request___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, __get, arginfo_queryyetsimple_http_request___get, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Request, __callStatic, arginfo_queryyetsimple_http_request___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Http_Request, __call, arginfo_queryyetsimple_http_request___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
