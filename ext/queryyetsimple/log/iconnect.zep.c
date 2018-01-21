
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IConnect 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2010.01.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Log_IConnect) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Log, IConnect, queryyetsimple, log_iconnect, queryyetsimple_log_iconnect_method_entry);

	return SUCCESS;

}

/**
 * 日志写入接口
 *
 * @param array $data
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Log_IConnect, save);

