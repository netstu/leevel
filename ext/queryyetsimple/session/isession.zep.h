
extern zend_class_entry *queryyetsimple_session_isession_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Session_Isession);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_set, 0, 0, 2)
	ZEND_ARG_INFO(0, sName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_put, 0, 0, 1)
	ZEND_ARG_INFO(0, mixKey)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_push, 0, 0, 2)
	ZEND_ARG_INFO(0, strKey)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, strKey)
	ZEND_ARG_ARRAY_INFO(0, arrValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_pop, 0, 0, 2)
	ZEND_ARG_INFO(0, strKey)
	ZEND_ARG_ARRAY_INFO(0, arrValue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_arrays, 0, 0, 2)
	ZEND_ARG_INFO(0, strKey)
	ZEND_ARG_INFO(0, mixKey)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_arraysdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, strKey)
	ZEND_ARG_INFO(0, mixKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_get, 0, 0, 1)
	ZEND_ARG_INFO(0, sName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, sName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, sName)
	ZEND_ARG_INFO(0, bPrefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_has, 0, 0, 1)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, bPrefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_flash, 0, 0, 1)
	ZEND_ARG_INFO(0, strKey)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_flashs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrFlash, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_nowflash, 0, 0, 2)
	ZEND_ARG_INFO(0, strKey)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_keepflash, 0, 0, 1)
	ZEND_ARG_INFO(0, mixKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_getflash, 0, 0, 1)
	ZEND_ARG_INFO(0, strKey)
	ZEND_ARG_INFO(0, mixDefault)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_deleteflash, 0, 0, 1)
	ZEND_ARG_INFO(0, mixKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_setprevurl, 0, 0, 1)
	ZEND_ARG_INFO(0, strUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_savepath, 0, 0, 0)
	ZEND_ARG_INFO(0, sSavePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_cachelimiter, 0, 0, 0)
	ZEND_ARG_INFO(0, strCacheLimiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_cacheexpire, 0, 0, 0)
	ZEND_ARG_INFO(0, nExpireSecond)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_sessionname, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_sessionid, 0, 0, 0)
	ZEND_ARG_INFO(0, sId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_cookiedomain, 0, 0, 0)
	ZEND_ARG_INFO(0, sSessionDomain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_usecookies, 0, 0, 0)
	ZEND_ARG_INFO(0, bUseCookies)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_usetranssid, 0, 0, 0)
	ZEND_ARG_INFO(0, nUseTransSid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_cookielifetime, 0, 0, 1)
	ZEND_ARG_INFO(0, nCookieLifeTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_gcmaxlifetime, 0, 0, 0)
	ZEND_ARG_INFO(0, nGcMaxlifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_session_isession_gcprobability, 0, 0, 0)
	ZEND_ARG_INFO(0, nGcProbability)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_session_isession_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, start, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, set, arginfo_queryyetsimple_session_isession_set)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, put, arginfo_queryyetsimple_session_isession_put)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, push, arginfo_queryyetsimple_session_isession_push)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, merge, arginfo_queryyetsimple_session_isession_merge)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, pop, arginfo_queryyetsimple_session_isession_pop)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, arrays, arginfo_queryyetsimple_session_isession_arrays)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, arraysDelete, arginfo_queryyetsimple_session_isession_arraysdelete)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, get, arginfo_queryyetsimple_session_isession_get)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, getPart, arginfo_queryyetsimple_session_isession_getpart)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, delete, arginfo_queryyetsimple_session_isession_delete)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, has, arginfo_queryyetsimple_session_isession_has)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, clear, arginfo_queryyetsimple_session_isession_clear)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, flash, arginfo_queryyetsimple_session_isession_flash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, flashs, arginfo_queryyetsimple_session_isession_flashs)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, nowFlash, arginfo_queryyetsimple_session_isession_nowflash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, rebuildFlash, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, keepFlash, arginfo_queryyetsimple_session_isession_keepflash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, getFlash, arginfo_queryyetsimple_session_isession_getflash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, deleteFlash, arginfo_queryyetsimple_session_isession_deleteflash)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, clearFlash, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, unregisterFlash, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, prevUrl, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, setPrevUrl, arginfo_queryyetsimple_session_isession_setprevurl)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, pause, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, destroy, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, isStart, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, status, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, parseSessionId, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, savePath, arginfo_queryyetsimple_session_isession_savepath)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, cacheLimiter, arginfo_queryyetsimple_session_isession_cachelimiter)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, cacheExpire, arginfo_queryyetsimple_session_isession_cacheexpire)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, sessionName, arginfo_queryyetsimple_session_isession_sessionname)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, sessionId, arginfo_queryyetsimple_session_isession_sessionid)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, cookieDomain, arginfo_queryyetsimple_session_isession_cookiedomain)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, useCookies, arginfo_queryyetsimple_session_isession_usecookies)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, useTransSid, arginfo_queryyetsimple_session_isession_usetranssid)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, cookieLifetime, arginfo_queryyetsimple_session_isession_cookielifetime)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, gcMaxlifetime, arginfo_queryyetsimple_session_isession_gcmaxlifetime)
	PHP_ABSTRACT_ME(Queryyetsimple_Session_Isession, gcProbability, arginfo_queryyetsimple_session_isession_gcprobability)
	PHP_FE_END
};
