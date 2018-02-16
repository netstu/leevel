
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IController 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_IController) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Mvc, IController, queryyetsimple, mvc_icontroller, queryyetsimple_mvc_icontroller_method_entry);

	zend_class_implements(queryyetsimple_mvc_icontroller_ce TSRMLS_CC, 1, queryyetsimple_mvc_iview_ce);
	return SUCCESS;

}

/**
 * 返回父控制器
 *
 * @param \Queryyetsimple\Mvc\IView $view
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_IController, setView);

