
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


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
	 * @var \queryyetsimple\mvc\icontroller
	 */
	zend_declare_property_null(queryyetsimple_mvc_action_ce, SL("objController"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
 * @param \queryyetsimple\mvc\icontroller $objController
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, setController) {

	zval *objController, objController_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objController_sub);

	zephir_fetch_params(0, 1, 0, &objController);



	zephir_update_property_zval(this_ptr, SL("objController"), objController);
	RETURN_THISW();

}

/**
 * 设置视图
 *
 * @param \queryyetsimple\mvc\iview $objView
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, setView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *objView, objView_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objView_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &objView);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objController"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setview", NULL, 0, objView);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置路由
 *
 * @param \queryyetsimple\router\router $objRouter
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, setRouter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *objRouter, objRouter_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objRouter_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &objRouter);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objController"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setrouter", NULL, 0, objRouter);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 执行子方法器
 *
 * @param string $sActionName 方法名
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, action) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sActionName_param = NULL, _0;
	zval sActionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sActionName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sActionName_param);

	zephir_get_strval(&sActionName, sActionName_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objController"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "action", NULL, 0, &sActionName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 变量赋值
 *
 * @param mixed $mixName
 * @param mixed $mixValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, assign) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixName, mixName_sub, *mixValue = NULL, mixValue_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixName_sub);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &mixName, &mixValue);

	if (!mixValue) {
		mixValue = &mixValue_sub;
		mixValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objController"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "assign", NULL, 0, mixName, mixValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取变量赋值
 *
 * @param string|null $sName
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, getAssign) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL, _0;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sName_param);

	if (!sName_param) {
		ZEPHIR_INIT_VAR(&sName);
		ZVAL_STRING(&sName, "");
	} else {
		zephir_get_strval(&sName, sName_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objController"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getassign", NULL, 0, &sName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除变量值
 *
 * @param mixed $mixName
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, deleteAssign) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixName, mixName_sub, arrArgs, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixName_sub);
	ZVAL_UNDEF(&arrArgs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixName);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&arrArgs);
	zephir_get_args(&arrArgs);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("objController"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "deleteAssign");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &arrArgs);
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
	zephir_read_property(&_0, this_ptr, SL("objController"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clearassign", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 加载视图文件
 *
 * @param string $sFile
 * @param array $arrOption
 * @sub string charset 编码
 * @sub string content_type 类型
 * @return string
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, display) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *sFile_param = NULL, *arrOption_param = NULL, _0;
	zval sFile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &sFile_param, &arrOption_param);

	if (!sFile_param) {
		ZEPHIR_INIT_VAR(&sFile);
		ZVAL_STRING(&sFile, "");
	} else {
		zephir_get_strval(&sFile, sFile_param);
	}
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcontroller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objController"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "display", NULL, 0, &sFile, &arrOption);
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


	zephir_read_property(&_0, this_ptr, SL("objController"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Controller is not set in action", "queryyetsimple/mvc/action.zep", 205);
		return;
	}

}

/**
 * call 
 *
 * @param string $sMethod
 * @param array $arrArgs
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_Action, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval arrArgs;
	zval *sMethod_param = NULL, *arrArgs_param = NULL, _0$$3, _1$$3, _2$$3, _4, _5, _6;
	zval sMethod;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sMethod);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&arrArgs);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sMethod_param, &arrArgs_param);

	zephir_get_strval(&sMethod, sMethod_param);
	zephir_get_arrval(&arrArgs, arrArgs_param);


	if (ZEPHIR_IS_STRING(&sMethod, "run")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_BadFunctionCallException);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Run method is not allowed.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", &_3, 1, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 27, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "queryyetsimple/mvc/action.zep", 219 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, spl_ce_BadFunctionCallException);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Method %s is not defined.");
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", &_3, 1, &_5, &sMethod);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 27, &_6);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "queryyetsimple/mvc/action.zep", 221 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

