
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * isession 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.09
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Session_Isession) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Session, Isession, queryyetsimple, session_isession, queryyetsimple_session_isession_method_entry);

	return SUCCESS;

}

/**
 * 启动 session
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, start);

/**
 * 设置 session
 *
 * @param string $sName
 * @param mxied $mixValue
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, set);

/**
 * 批量插入
 *
 * @param string|array $mixKey
 * @param mixed $mixValue
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, put);

/**
 * 数组插入数据
 *
 * @param string $strKey
 * @param mixed $mixValue
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, push);

/**
 * 合并元素
 *
 * @param string $strKey
 * @param array $arrValue
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, merge);

/**
 * 弹出元素
 *
 * @param string $strKey
 * @param mixed $mixValue
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, pop);

/**
 * 数组插入键值对数据
 *
 * @param string $strKey
 * @param mixed $mixKey
 * @param mixed $mixValue
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, arrays);

/**
 * 数组键值删除数据
 *
 * @param string $strKey
 * @param mixed $mixKey
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, arraysDelete);

/**
 * 取回 session
 *
 * @param string $sName
 * @param mixed $mixValue
 * @return mxied
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, get);

/**
 * 返回数组部分数据
 *
 * @param string $sName
 * @param mixed $mixValue
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, getPart);

/**
 * 删除 session
 *
 * @param string $sName
 * @param boolean $bPrefix
 * @return bool
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, delete);

/**
 * 是否存在 session
 *
 * @param string $sName
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, has);

/**
 * 删除 session
 *
 * @param boolean $bPrefix
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, clear);

/**
 * 闪存一个数据，当前请求和下一个请求可用
 *
 * @param string $strKey
 * @param mixed $mixValue
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, flash);

/**
 * 批量闪存数据，当前请求和下一个请求可用
 *
 * @param array $arrFlash
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, flashs);

/**
 * 闪存一个 flash 用于当前请求使用，下一个请求将无法获取
 *
 * @param string $strKey
 * @param mixed $mixValue
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, nowFlash);

/**
 * 保持所有闪存数据
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, rebuildFlash);

/**
 * 保持闪存数据
 *
 * @param mixed $mixKey
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, keepFlash);

/**
 * 返回闪存数据
 *
 * @param string $strKey
 * @param mixed $mixDefault
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, getFlash);

/**
 * 删除闪存数据
 *
 * @param mixed $mixKey
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, deleteFlash);

/**
 * 清理所有闪存数据
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, clearFlash);

/**
 * 程序执行结束清理 flash
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, unregisterFlash);

/**
 * 获取前一个请求地址
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, prevUrl);

/**
 * 设置前一个请求地址
 *
 * @param string $strUrl
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, setPrevUrl);

/**
 * 暂停 session
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, pause);

/**
 * 终止会话
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, destroy);

/**
 * session 是否已经启动
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, isStart);

/**
 * session 状态
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, status);

/**
 * 获取解析 session_id
 *
 * @param string $sId
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, parseSessionId);

/**
 * 设置 save path
 *
 * @param string $sSavePath
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, savePath);

/**
 * 设置 cache limiter
 *
 * @param string $strCacheLimiter
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, cacheLimiter);

/**
 * 设置 cache expire
 *
 * @param int $nExpireSecond
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, cacheExpire);

/**
 * session_name
 *
 * @param string $sName
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, sessionName);

/**
 * session id
 *
 * @param string $sId
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, sessionId);

/**
 * session 的 cookie_domain 设置
 *
 * @param string $sSessionDomain
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, cookieDomain);

/**
 * session 是否使用 cookie
 *
 * @param boolean $bUseCookies
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, useCookies);

/**
 * 客户端禁用 cookie 可以开启这个项
 *
 * @param string $nUseTransSid
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, useTransSid);

/**
 * 设置过期 cookie lifetime
 *
 * @param int $nCookieLifeTime
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, cookieLifetime);

/**
 * gc maxlifetime
 *
 * @param int $nGcMaxlifetime
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, gcMaxlifetime);

/**
 * session 垃圾回收概率分子 (分母为 session.gc_divisor)
 *
 * @param int $nGcProbability
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_Isession, gcProbability);

