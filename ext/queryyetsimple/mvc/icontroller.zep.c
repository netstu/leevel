
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * icontroller 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_Icontroller) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Mvc, Icontroller, queryyetsimple, mvc_icontroller, queryyetsimple_mvc_icontroller_method_entry);

	zend_class_implements(queryyetsimple_mvc_icontroller_ce TSRMLS_CC, 1, queryyetsimple_mvc_iview_ce);
	return SUCCESS;

}

/**
 * 返回父控制器
 *
 * @param \queryyetsimple\mvc\iview $objView
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Icontroller, setView);

/**
 * 返回父控制器
 *
 * @param \queryyetsimple\router\router $objRouter
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Icontroller, setRouter);

/**
 * 执行子方法器
 *
 * @param string $sActionName 方法名
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Icontroller, action);

