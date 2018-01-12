
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
	 * @var \queryyessimple\view\iview
	 */
	zend_declare_property_null(queryyetsimple_mvc_view_ce, SL("objTheme"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 备份视图模板
	 *
	 * @var \queryyessimple\view\iview
	 */
	zend_declare_property_null(queryyetsimple_mvc_view_ce, SL("objBackupTheme"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 是否永久切换
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(queryyetsimple_mvc_view_ce, SL("booForever"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 响应工厂
	 *
	 * @var \Closure
	 */
	zend_declare_property_null(queryyetsimple_mvc_view_ce, SL("calResponseFactory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 响应
	 *
	 * @var \queryyetsimple\http\response
	 */
	zend_declare_property_null(queryyetsimple_mvc_view_ce, SL("objResponse"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(queryyetsimple_mvc_view_ce TSRMLS_CC, 1, queryyetsimple_mvc_iview_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \queryyetsimple\view\iview $objTheme
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_View, __construct) {

	zval *objTheme, objTheme_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objTheme_sub);

	zephir_fetch_params(0, 1, 0, &objTheme);



	zephir_update_property_zval(this_ptr, SL("objTheme"), objTheme);

}

/**
 * 切换视图
 *
 * @param \queryyetsimple\view\iview $objTheme
 * @param boolean $booForever
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_View, switchView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booForever;
	zval *objTheme, objTheme_sub, *booForever_param = NULL, __$true, __$false, arrAssign, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objTheme_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&arrAssign);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &objTheme, &booForever_param);

	if (!booForever_param) {
		booForever = 0;
	} else {
		booForever = zephir_get_boolval(booForever_param);
	}


	ZEPHIR_CALL_METHOD(&arrAssign, this_ptr, "getassign", NULL, 0);
	zephir_check_call_status();
	if (booForever == 0) {
		zephir_read_property(&_0$$3, this_ptr, SL("objTheme"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("objBackupTheme"), &_0$$3);
	}
	if (booForever) {
		zephir_update_property_zval(this_ptr, SL("booForever"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("booForever"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("objTheme"), objTheme);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, &arrAssign);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 设置响应工厂
 *
 * @param \Closure $calResponseFactory
 * @return $this;
 */
PHP_METHOD(Queryyetsimple_Mvc_View, setResponseFactory) {

	zval *calResponseFactory, calResponseFactory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&calResponseFactory_sub);

	zephir_fetch_params(0, 1, 0, &calResponseFactory);



	zephir_update_property_zval(this_ptr, SL("calResponseFactory"), calResponseFactory);
	RETURN_THISW();

}

/**
 * 获取响应
 *
 * @return \queryyetsimple\http\response $objResponse
 */
PHP_METHOD(Queryyetsimple_Mvc_View, getResponse) {

	zval _0, _1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("objResponse"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("calResponseFactory"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_USER_FUNC(&_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("objResponse"), &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "objResponse");

}

/**
 * 变量赋值
 *
 * @param mixed $mixName
 * @param mixed $mixValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_View, assign) {

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktheme", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objTheme"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setvar", NULL, 0, mixName, mixValue);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 获取变量赋值
 *
 * @param string|null $sName
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Mvc_View, getAssign) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName = NULL, sName_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sName);

	if (!sName) {
		sName = &sName_sub;
		sName = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktheme", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objTheme"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getvar", NULL, 0, sName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除变量值
 *
 * @param mixed $mixName
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Mvc_View, deleteAssign) {

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



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktheme", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&arrArgs);
	zephir_get_args(&arrArgs);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("objTheme"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "deleteVar");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &arrArgs);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 清空变量值
 *
 * @param string|null $sName
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
	zephir_read_property(&_0, this_ptr, SL("objTheme"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clearvar", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 加载视图文件
 *
 * @param string $sFile
 * @param array $arrOption
 * @sub string charset 编码
 * @sub string content_type 内容类型
 * @return string
 */
PHP_METHOD(Queryyetsimple_Mvc_View, display) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *sFile_param = NULL, *arrOption_param = NULL, __$true, __$false, arrInitOption, strResult, _0, _1, _2, _3, _4, _5$$4;
	zval sFile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sFile);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&arrInitOption);
	ZVAL_UNDEF(&strResult);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktheme", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&arrInitOption);
	zephir_create_array(&arrInitOption, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&arrInitOption, SL("charset"), SL("utf-8"));
	add_assoc_stringl_ex(&arrInitOption, SL("content_type"), SL("text/html"));
	if (ZEPHIR_IS_EMPTY(&arrOption)) {
		ZEPHIR_INIT_NVAR(&arrOption);
		array_init(&arrOption);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &arrInitOption, &arrOption TSRMLS_CC);
	ZEPHIR_CPY_WRT(&arrOption, &_0);
	zephir_array_fetch_string(&_1, &arrOption, SL("content_type"), PH_NOISY | PH_READONLY, "queryyetsimple/mvc/view.zep", 218 TSRMLS_CC);
	zephir_array_fetch_string(&_2, &arrOption, SL("charset"), PH_NOISY | PH_READONLY, "queryyetsimple/mvc/view.zep", 218 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "responseheader", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("objTheme"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_4, 0);
	ZEPHIR_CALL_METHOD(&strResult, &_3, "display", NULL, 0, &sFile, &_4);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("booForever"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_4)) {
		zephir_read_property(&_5$$4, this_ptr, SL("objBackupTheme"), PH_NOISY_CC | PH_READONLY);
		zephir_update_property_zval(this_ptr, SL("objTheme"), &_5$$4);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("booForever"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("booForever"), &__$false);
	}
	RETURN_CCTOR(&strResult);

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


	zephir_read_property(&_0, this_ptr, SL("objTheme"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Theme is not set in view", "queryyetsimple/mvc/view.zep", 238);
		return;
	}

}

/**
 * 发送 header
 *
 * @param string $strContentType
 * @param string $strCharset
 * @return void
 */
PHP_METHOD(Queryyetsimple_Mvc_View, responseHeader) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strContentType_param = NULL, *strCharset_param = NULL, _0, _1, _2;
	zval strContentType, strCharset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strContentType);
	ZVAL_UNDEF(&strCharset);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &strContentType_param, &strCharset_param);

	if (!strContentType_param) {
		ZEPHIR_INIT_VAR(&strContentType);
		ZVAL_STRING(&strContentType, "text/html");
	} else {
		zephir_get_strval(&strContentType, strContentType_param);
	}
	if (!strCharset_param) {
		ZEPHIR_INIT_VAR(&strCharset);
		ZVAL_STRING(&strCharset, "utf-8");
	} else {
		zephir_get_strval(&strCharset, strCharset_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "getresponse", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("objResponse"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Response is not set in view", "queryyetsimple/mvc/view.zep", 254);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("objResponse"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "contenttype", NULL, 0, &strContentType);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "charset", NULL, 0, &strCharset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

