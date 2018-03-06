
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * 流程控制复用
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.05
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Flow_IControl) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Flow, IControl, queryyetsimple, flow_icontrol, queryyetsimple_flow_icontrol_method_entry);

	return SUCCESS;

}

/**
 * 条件语句 ifs
 *
 * @param boolean $value
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Flow_IControl, ifs);

/**
 * 条件语句 elseIfs
 *
 * @param boolean $value
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Flow_IControl, elseIfs);

/**
 * 条件语句 elses
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Flow_IControl, elses);

/**
 * 条件语句 endIfs
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Flow_IControl, endIfs);

/**
 * 设置当前条件表达式状态
 *
 * @param boolean $inFlowControl
 * @param boolean $isFlowControlTrue
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Flow_IControl, setTControl);

/**
 * 获取当前条件表达式状态
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Flow_IControl, getTControl);

/**
 * 验证一下条件表达式是否通过
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Flow_IControl, checkTControl);

/**
 * 占位符
 *
 * @param string $method
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Flow_IControl, placeholderTControl);

