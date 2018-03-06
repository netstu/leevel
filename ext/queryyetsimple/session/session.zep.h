
extern zend_class_entry *queryyetsimple_session_session_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Session_Session);

PHP_METHOD(Queryyetsimple_Session_Session, __construct);
PHP_METHOD(Queryyetsimple_Session_Session, start);
PHP_METHOD(Queryyetsimple_Session_Session, set);
PHP_METHOD(Queryyetsimple_Session_Session, put);
PHP_METHOD(Queryyetsimple_Session_Session, push);
PHP_METHOD(Queryyetsimple_Session_Session, merge);
PHP_METHOD(Queryyetsimple_Session_Session, pop);
PHP_METHOD(Queryyetsimple_Session_Session, arr);
PHP_METHOD(Queryyetsimple_Session_Session, arrDelete);
PHP_METHOD(Queryyetsimple_Session_Session, get);
PHP_METHOD(Queryyetsimple_Session_Session, getPart);
PHP_METHOD(Queryyetsimple_Session_Session, delete);
PHP_METHOD(Queryyetsimple_Session_Session, has);
PHP_METHOD(Queryyetsimple_Session_Session, clear);
PHP_METHOD(Queryyetsimple_Session_Session, flash);
PHP_METHOD(Queryyetsimple_Session_Session, flashs);
PHP_METHOD(Queryyetsimple_Session_Session, nowFlash);
PHP_METHOD(Queryyetsimple_Session_Session, rebuildFlash);
PHP_METHOD(Queryyetsimple_Session_Session, keepFlash);
PHP_METHOD(Queryyetsimple_Session_Session, getFlash);
PHP_METHOD(Queryyetsimple_Session_Session, deleteFlash);
PHP_METHOD(Queryyetsimple_Session_Session, clearFlash);
PHP_METHOD(Queryyetsimple_Session_Session, unregisterFlash);
PHP_METHOD(Queryyetsimple_Session_Session, prevUrl);
PHP_METHOD(Queryyetsimple_Session_Session, setPrevUrl);
PHP_METHOD(Queryyetsimple_Session_Session, pause);
PHP_METHOD(Queryyetsimple_Session_Session, destroy);
PHP_METHOD(Queryyetsimple_Session_Session, isStart);
PHP_METHOD(Queryyetsimple_Session_Session, status);
PHP_METHOD(Queryyetsimple_Session_Session, setName);
PHP_METHOD(Queryyetsimple_Session_Session, getName);
PHP_METHOD(Queryyetsimple_Session_Session, setId);
PHP_METHOD(Queryyetsimple_Session_Session, getId);
PHP_METHOD(Queryyetsimple_Session_Session, setSavePath);
PHP_METHOD(Queryyetsimple_Session_Session, getSavePath);
PHP_METHOD(Queryyetsimple_Session_Session, setCookieDomain);
PHP_METHOD(Queryyetsimple_Session_Session, getCookieDomain);
PHP_METHOD(Queryyetsimple_Session_Session, setCacheExpire);
PHP_METHOD(Queryyetsimple_Session_Session, setUseCookies);
PHP_METHOD(Queryyetsimple_Session_Session, setCacheLimiter);
PHP_METHOD(Queryyetsimple_Session_Session, getCacheLimiter);
PHP_METHOD(Queryyetsimple_Session_Session, setGcProbability);
PHP_METHOD(Queryyetsimple_Session_Session, getGcProbability);
PHP_METHOD(Queryyetsimple_Session_Session, option);
PHP_METHOD(Queryyetsimple_Session_Session, optionArray);
PHP_METHOD(Queryyetsimple_Session_Session, options);
PHP_METHOD(Queryyetsimple_Session_Session, getOption);
PHP_METHOD(Queryyetsimple_Session_Session, getOptions);
PHP_METHOD(Queryyetsimple_Session_Session, deleteOption);
PHP_METHOD(Queryyetsimple_Session_Session, deleteOptions);
PHP_METHOD(Queryyetsimple_Session_Session, getNormalizeName);
PHP_METHOD(Queryyetsimple_Session_Session, checkStart);
PHP_METHOD(Queryyetsimple_Session_Session, popOldFlash);
PHP_METHOD(Queryyetsimple_Session_Session, mergeOldFlash);
PHP_METHOD(Queryyetsimple_Session_Session, popNewFlash);
PHP_METHOD(Queryyetsimple_Session_Session, mergeNewFlash);
PHP_METHOD(Queryyetsimple_Session_Session, getPartData);
PHP_METHOD(Queryyetsimple_Session_Session, flashDataKey);
PHP_METHOD(Queryyetsimple_Session_Session, flashNewKey);
PHP_METHOD(Queryyetsimple_Session_Session, flashOldKey);
PHP_METHOD(Queryyetsimple_Session_Session, prevUrlKey);
PHP_METHOD(Queryyetsimple_Session_Session, __call);
zend_object *zephir_init_properties_Queryyetsimple_Session_Session(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, connect, SessionHandlerInterface, 1)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_put, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_push, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_pop, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_arr, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_arrdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_flash, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_flashs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, flash, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_nowflash, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_keepflash, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_getflash, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_deleteflash, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_setprevurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_setsavepath, 0, 0, 1)
	ZEND_ARG_INFO(0, savepath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_setcookiedomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_setcacheexpire, 0, 0, 1)
	ZEND_ARG_INFO(0, second)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_setcachelimiter, 0, 0, 1)
	ZEND_ARG_INFO(0, limiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_setgcprobability, 0, 0, 1)
	ZEND_ARG_INFO(0, probability)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_option, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_optionarray, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_options, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_getoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_deleteoption, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_deleteoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_getnormalizename, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_popoldflash, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_mergeoldflash, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_popnewflash, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_mergenewflash, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_getpartdata, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session_flashdatakey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_session___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_session_session_method_entry) {
	PHP_ME(Queryyetsimple_Session_Session, __construct, arginfo_queryyetsimple_session_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Session_Session, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, set, arginfo_queryyetsimple_session_session_set, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, put, arginfo_queryyetsimple_session_session_put, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, push, arginfo_queryyetsimple_session_session_push, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, merge, arginfo_queryyetsimple_session_session_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, pop, arginfo_queryyetsimple_session_session_pop, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, arr, arginfo_queryyetsimple_session_session_arr, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, arrDelete, arginfo_queryyetsimple_session_session_arrdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, get, arginfo_queryyetsimple_session_session_get, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getPart, arginfo_queryyetsimple_session_session_getpart, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, delete, arginfo_queryyetsimple_session_session_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, has, arginfo_queryyetsimple_session_session_has, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, clear, arginfo_queryyetsimple_session_session_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, flash, arginfo_queryyetsimple_session_session_flash, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, flashs, arginfo_queryyetsimple_session_session_flashs, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, nowFlash, arginfo_queryyetsimple_session_session_nowflash, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, rebuildFlash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, keepFlash, arginfo_queryyetsimple_session_session_keepflash, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getFlash, arginfo_queryyetsimple_session_session_getflash, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, deleteFlash, arginfo_queryyetsimple_session_session_deleteflash, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, clearFlash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, unregisterFlash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, prevUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, setPrevUrl, arginfo_queryyetsimple_session_session_setprevurl, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, pause, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, destroy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, isStart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, status, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, setName, arginfo_queryyetsimple_session_session_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, setId, arginfo_queryyetsimple_session_session_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, setSavePath, arginfo_queryyetsimple_session_session_setsavepath, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getSavePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, setCookieDomain, arginfo_queryyetsimple_session_session_setcookiedomain, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getCookieDomain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, setCacheExpire, arginfo_queryyetsimple_session_session_setcacheexpire, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, setUseCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, setCacheLimiter, arginfo_queryyetsimple_session_session_setcachelimiter, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getCacheLimiter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, setGcProbability, arginfo_queryyetsimple_session_session_setgcprobability, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getGcProbability, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, option, arginfo_queryyetsimple_session_session_option, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, optionArray, arginfo_queryyetsimple_session_session_optionarray, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, options, arginfo_queryyetsimple_session_session_options, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getOption, arginfo_queryyetsimple_session_session_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getOptions, arginfo_queryyetsimple_session_session_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, deleteOption, arginfo_queryyetsimple_session_session_deleteoption, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, deleteOptions, arginfo_queryyetsimple_session_session_deleteoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Session_Session, getNormalizeName, arginfo_queryyetsimple_session_session_getnormalizename, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, checkStart, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, popOldFlash, arginfo_queryyetsimple_session_session_popoldflash, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, mergeOldFlash, arginfo_queryyetsimple_session_session_mergeoldflash, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, popNewFlash, arginfo_queryyetsimple_session_session_popnewflash, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, mergeNewFlash, arginfo_queryyetsimple_session_session_mergenewflash, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, getPartData, arginfo_queryyetsimple_session_session_getpartdata, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, flashDataKey, arginfo_queryyetsimple_session_session_flashdatakey, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, flashNewKey, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, flashOldKey, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, prevUrlKey, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Session_Session, __call, arginfo_queryyetsimple_session_session___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
