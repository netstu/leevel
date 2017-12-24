
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * iaction 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_Iaction) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Mvc, Iaction, queryyetsimple, mvc_iaction, queryyetsimple_mvc_iaction_method_entry);

	return SUCCESS;

}

/**
 * 设置父控制器
 *
 * @param \queryyetsimple\mvc\icontroller $objController
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Iaction, setController);

