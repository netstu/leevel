
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * iarray 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Iarray) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Support, Iarray, queryyetsimple, support_iarray, queryyetsimple_support_iarray_method_entry);

	return SUCCESS;

}

/**
 * 对象转数组
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Support_Iarray, toArray);

