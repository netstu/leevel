
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IModel 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.07.10
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_IModel) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Mvc, IModel, queryyetsimple, mvc_imodel, NULL);

	/**
	 * 批量查找前事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("BEFORE_SELECT_EVENT"), "selecting");

	/**
	 * 批量查找后事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("AFTER_SELECT_EVENT"), "selected");

	/**
	 * 查找前事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("BEFORE_FIND_EVENT"), "finding");

	/**
	 * 查找后事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("AFTER_FIND_EVENT"), "finded");

	/**
	 * 保存前事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("BEFORE_SAVE_EVENT"), "saveing");

	/**
	 * 保存后事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("AFTER_SAVE_EVENT"), "saved");

	/**
	 * 新建前事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("BEFORE_CREATE_EVENT"), "creating");

	/**
	 * 新建后事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("AFTER_CREATE_EVENT"), "created");

	/**
	 * 更新前事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("BEFORE_UPDATE_EVENT"), "updating");

	/**
	 * 更新后事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("AFTER_UPDATE_EVENT"), "updated");

	/**
	 * 删除前事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("BEFORE_DELETE_EVENT"), "deleting");

	/**
	 * 删除后事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("AFTER_DELETE_EVENT"), "deleted");

	/**
	 * 软删除前事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("BEFORE_SOFT_DELETE_EVENT"), "softDeleting");

	/**
	 * 软删除后事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("AFTER_SOFT_DELETE_EVENT"), "softDeleted");

	/**
	 * 软删除恢复前事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("BEFORE_SOFT_RESTORE_EVENT"), "softRestoring");

	/**
	 * 软删除恢复后事件
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("AFTER_SOFT_RESTORE_EVENT"), "softRestored");

	/**
	 * 新建时间字段
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("CREATED_AT"), "created_at");

	/**
	 * 更新时间字段
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_mvc_imodel_ce, SL("UPDATED_AT"), "updated_at");

	zend_class_implements(queryyetsimple_mvc_imodel_ce TSRMLS_CC, 1, queryyetsimple_mvc_ientity_ce);
	return SUCCESS;

}

