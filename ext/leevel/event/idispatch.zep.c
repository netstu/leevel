
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IDispatch 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.31
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Event_IDispatch) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Event, IDispatch, leevel, event_idispatch, leevel_event_idispatch_method_entry);

	return SUCCESS;

}

/**
 * 执行一个事件
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Event_IDispatch, run);

/**
 * 注册监听器
 *
 * @param string|array $event
 * @param mixed $listener
 * @param int $priority
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Event_IDispatch, listeners);

/**
 * 获取一个事件监听器
 *
 * @param string $event
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Event_IDispatch, getListeners);

/**
 * 判断事件监听器是否存在
 *
 * @param string $event
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Event_IDispatch, hasListeners);

/**
 * 删除一个事件所有监听器
 *
 * @param string $event
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Event_IDispatch, deleteListeners);

/**
 * 设置是否严格匹配事件
 *
 * @param bool $event
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Event_IDispatch, strict);
