
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * iview 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_Iview) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Mvc, Iview, queryyetsimple, mvc_iview, queryyetsimple_mvc_iview_method_entry);

	return SUCCESS;

}

/**
 * 切换视图
 *
 * @param \queryyetsimple\view\iview $objTheme
 * @param boolean $booForever
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Iview, switchView);

/**
 * 变量赋值
 *
 * @param mixed $mixName
 * @param mixed $mixValue
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Iview, assign);

/**
 * 获取变量赋值
 *
 * @param string|null $sName
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Iview, getAssign);

/**
 * 删除变量值
 *
 * @param mixed $mixName
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Iview, deleteAssign);

/**
 * 清空变量值
 *
 * @param string|null $sName
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Iview, clearAssign);

/**
 * 加载视图文件
 *
 * @param string $sFile
 * @param array $arrOption
 * @sub string charset 编码
 * @sub string content_type 内容类型
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Mvc_Iview, display);

