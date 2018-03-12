
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/main.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * 视图
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.02
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_View) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Mvc, View, queryyetsimple, mvc_view, queryyetsimple_mvc_view_method_entry, 0);

	/**
	 * 视图模板
	 *
	 * @var \Queryyessimple\View\IView
	 */
	zend_declare_property_null(queryyetsimple_mvc_view_ce, SL("theme"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 备份视图模板
	 *
	 * @var \Queryyessimple\View\IView
	 */
	zend_declare_property_null(queryyetsimple_mvc_view_ce, SL("backupTheme"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 是否永久切换
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(queryyetsimple_mvc_view_ce, SL("foreverSwitch"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(queryyetsimple_mvc_view_ce TSRMLS_CC, 1, queryyetsimple_mvc_iview_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Queryyetsimple\View\IView $theme
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_View, __construct) {

	zval *theme, theme_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&theme_sub);

	zephir_fetch_params(0, 1, 0, &theme);



	zephir_update_property_zval(this_ptr, SL("theme"), theme);

}

/**
 * 切换视图
 *
 * @param \Queryyetsimple\View\IView $theme
 * @param boolean $foreverSwitch
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_View, switchView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool foreverSwitch;
	zval *theme, theme_sub, *foreverSwitch_param = NULL, __$true, __$false, assign, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&theme_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&assign);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &theme, &foreverSwitch_param);

	if (!foreverSwitch_param) {
		foreverSwitch = 0;
	} else {
		foreverSwitch = zephir_get_boolval(foreverSwitch_param);
	}


	ZEPHIR_CALL_METHOD(&assign, this_ptr, "getassign", NULL, 0);
	zephir_check_call_status();
	if (foreverSwitch == 0) {
		zephir_read_property(&_0$$3, this_ptr, SL("theme"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("backupTheme"), &_0$$3);
	}
	if (foreverSwitch) {
		zephir_update_property_zval(this_ptr, SL("foreverSwitch"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("foreverSwitch"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("theme"), theme);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, &assign);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 变量赋值
 *
 * @param mixed $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_View, assign) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value = NULL, value_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &value);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktheme", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("theme"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setvar", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 获取变量赋值
 *
 * @param string|null $name
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_View, getAssign) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktheme", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("theme"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getvar", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除变量值
 *
 * @param mixed $name
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_View, deleteAssign) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, args, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktheme", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("theme"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "deleteVar");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &args);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 清空变量值
 *
 * @param string|null $name
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_View, clearAssign) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktheme", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("theme"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clearvar", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 加载视图文件
 *
 * @param string $file
 * @param array $vars
 * @param string $ext
 * @return string
 */
PHP_METHOD(Queryyetsimple_Mvc_View, display) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval vars;
	zval *file = NULL, file_sub, *vars_param = NULL, *ext = NULL, ext_sub, __$true, __$false, __$null, result, _0, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&ext_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&vars);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &file, &vars_param, &ext);

	if (!file) {
		file = &file_sub;
		file = &__$null;
	}
	if (!vars_param) {
		ZEPHIR_INIT_VAR(&vars);
		array_init(&vars);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&vars, vars_param);
	}
	if (!ext) {
		ext = &ext_sub;
		ext = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktheme", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("theme"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_CALL_METHOD(&result, &_0, "display", NULL, 0, file, &vars, ext, &_1);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("foreverSwitch"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		zephir_read_property(&_2$$3, this_ptr, SL("backupTheme"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("theme"), &_2$$3);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("foreverSwitch"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("foreverSwitch"), &__$false);
	}
	RETURN_CCTOR(&result);

}

/**
 * 验证 theme
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_View, checkTheme) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("theme"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Theme is not set in view", "queryyetsimple/mvc/view.zep", 185);
		return;
	}

}

