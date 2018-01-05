
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ipipeline 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.05
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Pipeline_Ipipeline) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Pipeline, Ipipeline, queryyetsimple, pipeline_ipipeline, queryyetsimple_pipeline_ipipeline_method_entry);

	return SUCCESS;

}

/**
 * 将传输对象传入管道
 *
 * @param mixed $mixPassed
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Pipeline_Ipipeline, send);

/**
 * 设置管道中的执行工序
 *
 * @param dynamic|array $mixStage
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Pipeline_Ipipeline, through);

/**
 * 执行管道工序响应结果
 *
 * @param callable $calEnd
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Pipeline_Ipipeline, then);

