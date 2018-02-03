
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ISubject 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.06.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Event_ISubject) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Event, ISubject, queryyetsimple, event_isubject, queryyetsimple_event_isubject_method_entry);

	return SUCCESS;

}

/**
 * 添加一个观察者角色
 *
 * @param \SplObserver|string $observer
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Event_ISubject, attachs);

