
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
 * 基类方法器
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_Action) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Mvc, Action, queryyetsimple, mvc_action, queryyetsimple_mvc_action_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 父控制器
	 *
	 * @var \Queryyetsimple\Mvc\IController
	 */
	zend_declare_property_null(queryyetsimple_mvc_action_ce, SL("controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(queryyetsimple_mvc_action_ce TSRMLS_CC, 1, queryyetsimple_mvc_iaction_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, __construct) {

	zval *this_ptr = getThis();



}

/**
 * 设置父控制器
 *
 * @param \Queryyetsimple\Mvc\IController $controller
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, setController) {

	zval *controller, controller_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controller_sub);

	zephir_fetch_params(0, 1, 0, &controller);



	zephir_update_property_zval(this_ptr, SL("controller"), controller);
	RETURN_THISW();

}

/**
 * 设置视图
 *
 * @param \Queryyetsimple\Mvc\IView $view
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, setView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *view, view_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &view);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("controller"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setview", NULL, 0, view);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置路由
 *
 * @param \Queryyetsimple\Router\Router $router
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, setRouter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *router, router_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&router_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &router);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("controller"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setrouter", NULL, 0, router);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 执行子方法器
 *
 * @param string $action 方法名
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, action) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *action_param = NULL, _0;
	zval action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &action_param);

	zephir_get_strval(&action, action_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("controller"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "action", NULL, 0, &action);
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
PHP_METHOD(Queryyetsimple_Mvc_Action, switchView) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("controller"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Queryyetsimple_Mvc_Action, assign) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("controller"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "assign", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取变量赋值
 *
 * @param string|null $name
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, getAssign) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("controller"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Queryyetsimple_Mvc_Action, deleteAssign) {

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



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("controller"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "deleteAssign");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &args);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 清空变量值
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, clearAssign) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("controller"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Queryyetsimple_Mvc_Action, display) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("controller"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "display", NULL, 0, &file, &vars, &option);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 验证 controller
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, checkController) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("controller"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Controller is not set in action", "queryyetsimple/mvc/action.zep", 201);
		return;
	}

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0$$3, _1$$3, _2$$3, _4, _5, _6;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	if (ZEPHIR_IS_STRING(&method, "run")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_BadFunctionCallException);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Run method is not allowed.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", &_3, 1, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 43, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "queryyetsimple/mvc/action.zep", 215 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, spl_ce_BadFunctionCallException);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Method %s is not defined.");
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_3, 1, &_5, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 43, &_6);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "queryyetsimple/mvc/action.zep", 217 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

