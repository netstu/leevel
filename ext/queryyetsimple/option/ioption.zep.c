
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ioption 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Option_Ioption) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Option, Ioption, queryyetsimple, option_ioption, queryyetsimple_option_ioption_method_entry);

	return SUCCESS;

}

/**
 * 是否存在配置
 *
 * @param string $sName 配置键值
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_Ioption, has);

/**
 * 获取配置
 *
 * @param string $sName 配置键值
 * @param mixed $mixDefault 配置默认值
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_Ioption, get);

/**
 * 返回所有配置
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_Ioption, all);

/**
 * 设置配置
 *
 * @param mixed $mixName 配置键值
 * @param mixed $mixValue 配置值
 * @return array
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_Ioption, set);

/**
 * 删除配置
 *
 * @param string $sName 配置键值
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_Ioption, delete);

/**
 * 初始化配置参数
 *
 * @param mixed $mixNamespace
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Option_Ioption, reset);

