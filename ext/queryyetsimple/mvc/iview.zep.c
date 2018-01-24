
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IView 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_IView) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Mvc, IView, queryyetsimple, mvc_iview, queryyetsimple_mvc_iview_method_entry);

	return SUCCESS;

}

/**
 * 切换视图
 *
 * @param \Queryyetsimple\View\IView $theme
 * @param boolean $forever
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_IView, switchView);

/**
 * 变量赋值
 *
 * @param mixed $name
 * @param mixed $value
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_IView, assign);

/**
 * 获取变量赋值
 *
 * @param string|null $name
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_IView, getAssign);

/**
 * 删除变量值
 *
 * @param mixed $name
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_IView, deleteAssign);

/**
 * 清空变量值
 *
 * @param string|null $name
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_IView, clearAssign);

/**
 * 加载视图文件
 *
 * @param string $file
 * @param array $vars
 * @param array $option
 * @sub string charset 编码
 * @sub string content_type 内容类型
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_IView, display);
