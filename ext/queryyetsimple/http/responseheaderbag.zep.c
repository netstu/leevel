
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


/**
 * response header bag
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.05
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Http_ResponseHeaderBag) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Http, ResponseHeaderBag, queryyetsimple, http_responseheaderbag, queryyetsimple_http_headerbag_ce, NULL, 0);

	/**
	 * 下载附件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_responseheaderbag_ce, SL("DISPOSITION_ATTACHMENT"), "attachment");

	/**
	 * 文件直接读取
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_http_responseheaderbag_ce, SL("DISPOSITION_INLINE"), "inline");

	return SUCCESS;

}

