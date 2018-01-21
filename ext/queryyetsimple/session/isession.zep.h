
extern zend_class_entry *queryyetsimple_session_isession_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Session_ISession);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_put, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_push, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_pop, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_arr, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_arrdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_flash, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_flashs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, flash, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_nowflash, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_keepflash, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_getflash, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_deleteflash, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_setprevurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_savepath, 0, 0, 0)
	ZEND_ARG_INFO(0, savepath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_cachelimiter, 0, 0, 0)
	ZEND_ARG_INFO(0, limiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_cacheexpire, 0, 0, 0)
	ZEND_ARG_INFO(0, second)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_sessionname, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_sessionid, 0, 0, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_cookiedomain, 0, 0, 0)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_usecookies, 0, 0, 0)
	ZEND_ARG_INFO(0, cookies)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_usetranssid, 0, 0, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_cookielifetime, 0, 0, 1)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_gcmaxlifetime, 0, 0, 0)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_gcprobability, 0, 0, 0)
	ZEND_ARG_INFO(0, probability)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_session_isession_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, start, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, set, arginfo_queryyetsimple_session_isession_set)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, put, arginfo_queryyetsimple_session_isession_put)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, push, arginfo_queryyetsimple_session_isession_push)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, merge, arginfo_queryyetsimple_session_isession_merge)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, pop, arginfo_queryyetsimple_session_isession_pop)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, arr, arginfo_queryyetsimple_session_isession_arr)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, arrDelete, arginfo_queryyetsimple_session_isession_arrdelete)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, get, arginfo_queryyetsimple_session_isession_get)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, getPart, arginfo_queryyetsimple_session_isession_getpart)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, delete, arginfo_queryyetsimple_session_isession_delete)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, has, arginfo_queryyetsimple_session_isession_has)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, clear, arginfo_queryyetsimple_session_isession_clear)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, flash, arginfo_queryyetsimple_session_isession_flash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, flashs, arginfo_queryyetsimple_session_isession_flashs)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, nowFlash, arginfo_queryyetsimple_session_isession_nowflash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, rebuildFlash, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, keepFlash, arginfo_queryyetsimple_session_isession_keepflash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, getFlash, arginfo_queryyetsimple_session_isession_getflash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, deleteFlash, arginfo_queryyetsimple_session_isession_deleteflash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, clearFlash, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, unregisterFlash, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, prevUrl, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, setPrevUrl, arginfo_queryyetsimple_session_isession_setprevurl)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, pause, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, destroy, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, isStart, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, status, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, parseSessionId, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, savePath, arginfo_queryyetsimple_session_isession_savepath)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, cacheLimiter, arginfo_queryyetsimple_session_isession_cachelimiter)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, cacheExpire, arginfo_queryyetsimple_session_isession_cacheexpire)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, sessionName, arginfo_queryyetsimple_session_isession_sessionname)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, sessionId, arginfo_queryyetsimple_session_isession_sessionid)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, cookieDomain, arginfo_queryyetsimple_session_isession_cookiedomain)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, useCookies, arginfo_queryyetsimple_session_isession_usecookies)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, useTransSid, arginfo_queryyetsimple_session_isession_usetranssid)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, cookieLifetime, arginfo_queryyetsimple_session_isession_cookielifetime)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, gcMaxlifetime, arginfo_queryyetsimple_session_isession_gcmaxlifetime)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_ISession, gcProbability, arginfo_queryyetsimple_session_isession_gcprobability)
	PHP_FE_END
};
