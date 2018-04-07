
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * 实体基础接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Mvc_IEntity) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Mvc, IEntity, leevel, mvc_ientity, leevel_mvc_ientity_method_entry);

	return SUCCESS;

}

/**
 * 唯一标识符
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Mvc_IEntity, id);

