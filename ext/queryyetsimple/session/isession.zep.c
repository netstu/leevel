
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ISession 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.09
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Session_ISession) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Session, ISession, queryyetsimple, session_isession, queryyetsimple_session_isession_method_entry);

	return SUCCESS;

}

/**
 * 启动 session
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, start);

/**
 * 设置 session
 *
 * @param string $name
 * @param mxied $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, set);

/**
 * 批量插入
 *
 * @param string|array $keys
 * @param mixed $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, put);

/**
 * 数组插入数据
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, push);

/**
 * 合并元素
 *
 * @param string $key
 * @param array $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, merge);

/**
 * 弹出元素
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, pop);

/**
 * 数组插入键值对数据
 *
 * @param string $key
 * @param mixed $keys
 * @param mixed $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, arr);

/**
 * 数组键值删除数据
 *
 * @param string $key
 * @param mixed $keys
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, arrDelete);

/**
 * 取回 session
 *
 * @param string $name
 * @param mixed $value
 * @return mxied
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, get);

/**
 * 返回数组部分数据
 *
 * @param string $name
 * @param mixed $value
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, getPart);

/**
 * 删除 session
 *
 * @param string $name
 * @param boolean $prefix
 * @return bool
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, delete);

/**
 * 是否存在 session
 *
 * @param string $name
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, has);

/**
 * 删除 session
 *
 * @param boolean $prefix
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, clear);

/**
 * 闪存一个数据，当前请求和下一个请求可用
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, flash);

/**
 * 批量闪存数据，当前请求和下一个请求可用
 *
 * @param array $flash
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, flashs);

/**
 * 闪存一个 flash 用于当前请求使用，下一个请求将无法获取
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, nowFlash);

/**
 * 保持所有闪存数据
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, rebuildFlash);

/**
 * 保持闪存数据
 *
 * @param mixed $keys
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, keepFlash);

/**
 * 返回闪存数据
 *
 * @param string $key
 * @param mixed $defaults
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, getFlash);

/**
 * 删除闪存数据
 *
 * @param mixed $keys
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, deleteFlash);

/**
 * 清理所有闪存数据
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, clearFlash);

/**
 * 程序执行结束清理 flash
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, unregisterFlash);

/**
 * 获取前一个请求地址
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, prevUrl);

/**
 * 设置前一个请求地址
 *
 * @param string $url
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, setPrevUrl);

/**
 * 暂停 session
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, pause);

/**
 * 终止会话
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, destroy);

/**
 * session 是否已经启动
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, isStart);

/**
 * session 状态
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, status);

/**
 * 获取解析 session_id
 *
 * @param string $id
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, parseSessionId);

/**
 * 设置 save path
 *
 * @param string $savepath
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, savePath);

/**
 * 设置 cache limiter
 *
 * @param string $limiter
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, cacheLimiter);

/**
 * 设置 cache expire
 *
 * @param int $second
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, cacheExpire);

/**
 * session_name
 *
 * @param string $name
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, sessionName);

/**
 * session id
 *
 * @param string $id
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, sessionId);

/**
 * session 的 cookie_domain 设置
 *
 * @param string $domain
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, cookieDomain);

/**
 * session 是否使用 cookie
 *
 * @param boolean $cookies
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, useCookies);

/**
 * 客户端禁用 cookie 可以开启这个项
 *
 * @param string $id
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, useTransSid);

/**
 * 设置过期 cookie lifetime
 *
 * @param int $lifetime
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, cookieLifetime);

/**
 * gc maxlifetime
 *
 * @param int $lifetime
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, gcMaxlifetime);

/**
 * session 垃圾回收概率分子 (分母为 session.gc_divisor)
 *
 * @param int $probability
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Session_ISession, gcProbability);

