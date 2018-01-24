
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IClass 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.22
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Option_IClass) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Option, IClass, queryyetsimple, option_iclass, queryyetsimple_option_iclass_method_entry);

	return SUCCESS;

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_IClass, option);

/**
 * 修改数组配置
 *
 * @param string $name
 * @param array $value
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_IClass, optionArray);

/**
 * 修改多个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_IClass, options);

/**
 * 获取单个配置
 *
 * @param string $name
 * @param mixed $defaults
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_IClass, getOption);

/**
 * 获取所有配置
 *
 * @param array $option
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_IClass, getOptions);

/**
 * 删除单个配置
 *
 * @param string $name
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_IClass, deleteOption);

/**
 * 删除多个配置
 *
 * @param array $option
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_IClass, deleteOptions);

