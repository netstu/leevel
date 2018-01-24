
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
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * 基类控制器
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_Controller) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Mvc, Controller, queryyetsimple, mvc_controller, queryyetsimple_mvc_controller_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 视图
	 *
	 * @var \Queryyetsimple\Mvc\IView
	 */
	zend_declare_property_null(queryyetsimple_mvc_controller_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 视图
	 *
	 * @var \Queryyetsimple\Router\Router
	 */
	zend_declare_property_null(queryyetsimple_mvc_controller_ce, SL("router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(queryyetsimple_mvc_controller_ce TSRMLS_CC, 1, queryyetsimple_mvc_icontroller_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, __construct) {

	zval *this_ptr = getThis();



}

/**
 * 设置视图
 *
 * @param \Queryyetsimple\Mvc\IView $view
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, setView) {

	zval *view, view_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);

	zephir_fetch_params(0, 1, 0, &view);



	zephir_update_property_zval(this_ptr, SL("view"), view);
	RETURN_THISW();

}

/**
 * 设置路由
 *
 * @param \Queryyetsimple\Router\Router $router
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, setRouter) {

	zval *router, router_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router_sub);

	zephir_fetch_params(0, 1, 0, &router);



	zephir_update_property_zval(this_ptr, SL("router"), router);
	RETURN_THISW();

}

/**
 * 执行子方法器
 *
 * @param string $action 方法名
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, action) {

	zval _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *action_param = NULL, args, _1, _2, _3, _4, _5;
	zval action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &action_param);

	zephir_get_strval(&action, action_param);


	if ((zephir_method_exists(this_ptr, &action TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(&args);
		zephir_get_args(&args);
		ZEPHIR_MAKE_REF(&args);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 4, &args);
		ZEPHIR_UNREF(&args);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_0$$3, this_ptr);
		zephir_array_fast_append(&_0$$3, &action);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0$$3, &args);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, SL("router"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Router is not set in controller", "queryyetsimple/mvc/controller.zep", 107);
		return;
	}
	zephir_read_property(&_2, this_ptr, SL("router"), PH_NOISY_CC | PH_READONLY);
	ZVAL_NULL(&_3);
	ZVAL_NULL(&_4);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "dobind", NULL, 0, &_3, &action, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 切换视图
 *
 * @param \Queryyetsimple\View\IView $theme
 * @param boolean $forever
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, switchView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool forever;
	zval *theme, theme_sub, *forever_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&theme_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &theme, &forever_param);

	if (!forever_param) {
		forever = 0;
	} else {
		forever = zephir_get_boolval(forever_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	if (forever) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "switchview", NULL, 0, theme, &_1);
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
PHP_METHOD(Queryyetsimple_Mvc_Controller, assign) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "assign", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 获取变量赋值
 *
 * @param string|null $name
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, getAssign) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getassign", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除变量值
 *
 * @param mixed $name
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, deleteAssign) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("view"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "deleteAssign");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_get_args(&_3);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &_3);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 清空变量值
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, clearAssign) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clearassign", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 加载视图文件
 *
 * @param string $file
 * @param array $vars
 * @param array $option
 * @sub string charset 编码
 * @sub string content_type 类型
 * @return string
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, display) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval vars, option;
	zval *file_param = NULL, *vars_param = NULL, *option_param = NULL, _0;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &file_param, &vars_param, &option_param);

	if (!file_param) {
		ZEPHIR_INIT_VAR(&file);
		ZVAL_STRING(&file, "");
	} else {
		zephir_get_strval(&file, file_param);
	}
	if (!vars_param) {
		ZEPHIR_INIT_VAR(&vars);
		array_init(&vars);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&vars, vars_param);
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "display", NULL, 0, &file, &vars, &option);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 验证 view
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, checkView) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "View is not set in controller", "queryyetsimple/mvc/controller.zep", 206);
		return;
	}

}

/**
 * 赋值
 *
 * @param mixed $name
 * @param mixed $Value
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取值
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getassign", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}
