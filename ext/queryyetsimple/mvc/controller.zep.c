
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
	 * @var \queryyetsimple\mvc\iview
	 */
	zend_declare_property_null(queryyetsimple_mvc_controller_ce, SL("objView"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 视图
	 *
	 * @var \queryyetsimple\router\router
	 */
	zend_declare_property_null(queryyetsimple_mvc_controller_ce, SL("objRouter"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
 * @param \queryyetsimple\mvc\iview $objView
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, setView) {

	zval *objView, objView_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objView_sub);

	zephir_fetch_params(0, 1, 0, &objView);



	zephir_update_property_zval(this_ptr, SL("objView"), objView);
	RETURN_THISW();

}

/**
 * 设置路由
 *
 * @param \queryyetsimple\router\router $objRouter
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, setRouter) {

	zval *objRouter, objRouter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objRouter_sub);

	zephir_fetch_params(0, 1, 0, &objRouter);



	zephir_update_property_zval(this_ptr, SL("objRouter"), objRouter);
	RETURN_THISW();

}

/**
 * 执行子方法器
 *
 * @param string $sActionName 方法名
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, action) {

	zval _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sActionName_param = NULL, arrArgs, _1, _2, _3, _4, _5;
	zval sActionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sActionName);
	ZVAL_UNDEF(&arrArgs);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sActionName_param);

	zephir_get_strval(&sActionName, sActionName_param);


	if ((zephir_method_exists(this_ptr, &sActionName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(&arrArgs);
		zephir_get_args(&arrArgs);
		ZEPHIR_MAKE_REF(&arrArgs);
		ZEPHIR_CALL_FUNCTION(NULL, "array_shift", NULL, 4, &arrArgs);
		ZEPHIR_UNREF(&arrArgs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_0$$3, this_ptr);
		zephir_array_fast_append(&_0$$3, &sActionName);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0$$3, &arrArgs);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, SL("objRouter"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Router is not set in controller", "queryyetsimple/mvc/controller.zep", 107);
		return;
	}
	zephir_read_property(&_2, this_ptr, SL("objRouter"), PH_NOISY_CC | PH_READONLY);
	ZVAL_NULL(&_3);
	ZVAL_NULL(&_4);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_RETURN_CALL_METHOD(&_2, "dobind", NULL, 0, &_3, &sActionName, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 切换视图
 *
 * @param \queryyetsimple\view\iview $objTheme
 * @param boolean $booForever
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, switchView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booForever;
	zval *objTheme, objTheme_sub, *booForever_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objTheme_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &objTheme, &booForever_param);

	if (!booForever_param) {
		booForever = 0;
	} else {
		booForever = zephir_get_boolval(booForever_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objView"), PH_NOISY_CC | PH_READONLY);
	if (booForever) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "switchview", NULL, 0, objTheme, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 变量赋值
 *
 * @param mixed $mixName
 * @param mixed $mixValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, assign) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objView"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "assign", NULL, 0, mixName, mixValue);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 获取变量赋值
 *
 * @param string|null $sName
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, getAssign) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objView"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Queryyetsimple_Mvc_Controller, deleteAssign) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixName, mixName_sub, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixName);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("objView"), PH_NOISY_CC);
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
	zephir_read_property(&_0, this_ptr, SL("objView"), PH_NOISY_CC | PH_READONLY);
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
PHP_METHOD(Queryyetsimple_Mvc_Controller, display) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objView"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "display", NULL, 0, &sFile, &arrOption);
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


	zephir_read_property(&_0, this_ptr, SL("objView"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "View is not set in controller", "queryyetsimple/mvc/controller.zep", 205);
		return;
	}

}

/**
 * 赋值
 *
 * @param mixed $mixName
 * @param mixed $Value
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixName, mixName_sub, *mixValue, mixValue_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixName_sub);
	ZVAL_UNDEF(&mixValue_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &mixName, &mixValue);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, mixName, mixValue);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取值
 *
 * @param string $sName
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_Controller, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sName_param);

	zephir_get_strval(&sName, sName_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getassign", NULL, 0, &sName);
	zephir_check_call_status();
	RETURN_MM();

}

