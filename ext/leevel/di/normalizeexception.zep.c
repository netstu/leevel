
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_exceptions.h"


/**
 * 容器格式化异常
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.05.27
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Di_NormalizeException) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Di, NormalizeException, leevel, di_normalizeexception, spl_ce_RuntimeException, NULL, 0);

	return SUCCESS;

}

