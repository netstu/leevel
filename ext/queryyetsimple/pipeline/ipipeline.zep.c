
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
ZEPHIR_INIT_CLASS(Queryyetsimple_Pipeline_IPipeline) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Pipeline, IPipeline, queryyetsimple, pipeline_ipipeline, queryyetsimple_pipeline_ipipeline_method_entry);

	return SUCCESS;

}

/**
 * 管道初始化
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Pipeline_IPipeline, reset);

/**
 * 将传输对象传入管道
 *
 * @param mixed $passed
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Pipeline_IPipeline, send);

/**
 * 设置管道中的执行工序
 *
 * @param dynamic|array $stage
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Pipeline_IPipeline, through);

/**
 * 执行管道工序响应结果
 *
 * @param callable $end
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Pipeline_IPipeline, then);

