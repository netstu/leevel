
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/main.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * 模板处理抽象类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.02
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_View_Aconnect) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\View, Aconnect, queryyetsimple, view_aconnect, queryyetsimple_view_aconnect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 变量值
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_view_aconnect_ce, SL("arrVar"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_view_aconnect_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_view_aconnect_ce->create_object = zephir_init_properties_Queryyetsimple_View_Aconnect;
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array option
 * @return void
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "options", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置模板变量
 *
 * @param mixed $mixName
 * @param mixed $mixValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, setVar) {

	zval *mixName, mixName_sub, *mixValue = NULL, mixValue_sub, __$null, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixName_sub);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &mixName, &mixValue);

	if (!mixValue) {
		mixValue = &mixValue_sub;
		mixValue = &__$null;
	}


	if (Z_TYPE_P(mixName) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("arrVar"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, mixName TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("arrVar"), &_0$$3);
	} else {
		zephir_update_property_array(this_ptr, SL("arrVar"), mixName, mixValue TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取变量值
 *
 * @param string|null $sName
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, getVar) {

	zval *sName_param = NULL, _0, _1, _2;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sName_param);

	if (!sName_param) {
		ZEPHIR_INIT_VAR(&sName);
		ZVAL_STRING(&sName, "");
	} else {
		zephir_get_strval(&sName, sName_param);
	}


	if (1 == 0) {
		RETURN_MM_MEMBER(getThis(), "arrVar");
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("arrVar"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &sName)) {
		zephir_read_property(&_2, this_ptr, SL("arrVar"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &sName, PH_NOISY, "queryyetsimple/view/aconnect.zep", 87 TSRMLS_CC);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 删除变量值
 *
 * @param mixed $mixName
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, deleteVar) {

	zval *mixName = NULL, mixName_sub, strName, _0, *_1, _2$$3, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixName_sub);
	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixName);

	ZEPHIR_SEPARATE_PARAM(mixName);


	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(mixName) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, mixName);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_get_args(&_0);
	}
	ZEPHIR_CPY_WRT(mixName, &_0);
	zephir_is_iterable(mixName, 0, "queryyetsimple/view/aconnect.zep", 108);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(mixName), _1)
	{
		ZEPHIR_INIT_NVAR(&strName);
		ZVAL_COPY(&strName, _1);
		zephir_read_property(&_2$$3, this_ptr, SL("arrVar"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_2$$3, &strName)) {
			zephir_read_property(&_3$$4, this_ptr, SL("arrVar"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_3$$4, &strName, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&strName);
	RETURN_THIS();

}

/**
 * 清空变量值
 *
 * @param string|null $sName
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, clearVar) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("arrVar"), &_0);
	RETURN_THIS();

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, option) {

	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	if (!(Z_TYPE_P(&name) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Option set name must be a string.", "queryyetsimple/view/aconnect.zep", 133);
		return;
	}
	zephir_update_property_array(this_ptr, SL("option"), &name, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 修改数组配置
 *
 * @param string $name
 * @param array $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, optionArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *name_param = NULL, *value_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &name);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &value TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "option", NULL, 0, &name, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 修改多个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, options) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, name, value, *_0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (ZEPHIR_IS_EMPTY(&option)) {
		RETURN_THIS();
	}
	zephir_is_iterable(&option, 0, "queryyetsimple/view/aconnect.zep", 170);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&option), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "option", &_3, 0, &name, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();

}

/**
 * 获取单个配置
 *
 * @param string $name
 * @param mixed $defaults
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, getOption) {

	zval *name_param = NULL, *defaults = NULL, defaults_sub, __$null, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaults);

	zephir_get_strval(&name, name_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &name)) {
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &name, PH_NOISY, "queryyetsimple/view/aconnect.zep", 182 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, defaults);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 获取所有配置
 *
 * @param array $option
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, getOptions) {

	zval *option_param = NULL, _0$$3;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&option))) {
		zephir_read_property(&_0$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(return_value, &_0$$3, &option TSRMLS_CC);
		RETURN_MM();
	} else {
		RETURN_MM_MEMBER(getThis(), "option");
	}

}

/**
 * 删除单个配置
 *
 * @param string $name
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, deleteOption) {

	zval *name_param = NULL, _0, _1$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		zephir_read_property(&_1$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &name, PH_SEPARATE);
	}
	RETURN_THIS();

}

/**
 * 删除多个配置
 *
 * @param array $option
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, deleteOptions) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, key, *_0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&option))) {
		RETURN_THIS();
	}
	zephir_is_iterable(&option, 0, "queryyetsimple/view/aconnect.zep", 233);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&option), _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteoption", &_1, 0, &key);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

/**
 * 分析展示的视图文件
 *
 * @param string $sFile 视图文件地址
 * @param string $strExt 后缀
 * @return string|void
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, parseDisplayFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *sFile_param = NULL, *strExt_param = NULL, _0, _3, _5, _2$$3, _4$$4, _6$$5, _7$$5, _8$$5;
	zval sFile, strExt;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sFile);
	ZVAL_UNDEF(&strExt);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sFile_param, &strExt_param);

	zephir_get_strval(&sFile, sFile_param);
	if (!strExt_param) {
		ZEPHIR_INIT_VAR(&strExt);
		ZVAL_STRING(&strExt, "");
	} else {
		zephir_get_strval(&strExt, strExt_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 11, &sFile);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "parsefile", NULL, 0, &sFile, &strExt);
		zephir_check_call_status();
		zephir_get_strval(&sFile, &_2$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_3, "is_file", &_1, 11, &sFile);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "parsedefaultfile", NULL, 0, &sFile);
		zephir_check_call_status();
		zephir_get_strval(&sFile, &_4$$4);
	}
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_1, 11, &sFile);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "Template file %s does not exist.");
		ZEPHIR_CALL_FUNCTION(&_8$$5, "sprintf", NULL, 1, &_7$$5, &sFile);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 17, &_8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "queryyetsimple/view/aconnect.zep", 256 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&sFile);

}

/**
 * 分析模板真实路径			
 *
 * @param string $sTpl 文件地址
 * @param string $sExt 扩展名
 * @return string
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, parseFile) {

	zval _21$$5;
	zend_bool _5;
	zephir_fcall_cache_entry *_12 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sTpl_param = NULL, *sExt_param = NULL, arrArray, sTheme, sTempTheme, sTempTpl, sReturnFile, _0, _1, _2, _3, _4, _6, _7, _8, _9, _10$$5, _11$$5, _18$$5, _20$$5, _22$$5, _23$$5, _24$$5, _25$$5, _13$$7, _14$$7, _15$$7, _16$$7, _17$$7, _26$$9, _27$$10, _28$$10, _29$$10, _30$$12, _31$$12;
	zval sTpl, sExt;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sTpl);
	ZVAL_UNDEF(&sExt);
	ZVAL_UNDEF(&arrArray);
	ZVAL_UNDEF(&sTheme);
	ZVAL_UNDEF(&sTempTheme);
	ZVAL_UNDEF(&sTempTpl);
	ZVAL_UNDEF(&sReturnFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_21$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sTpl_param, &sExt_param);

	zephir_get_strval(&sTpl, sTpl_param);
	if (!sExt_param) {
		ZEPHIR_INIT_VAR(&sExt);
		ZVAL_STRING(&sExt, "");
	} else {
		zephir_get_strval(&sExt, sExt_param);
	}


	ZEPHIR_INIT_VAR(&sReturnFile);
	ZVAL_STRING(&sReturnFile, "");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "->");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ".");
	zephir_fast_str_replace(&_0, &_1, &_2, &sTpl TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&sTpl);
	zephir_fast_trim(&sTpl, &_0, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZVAL_LONG(&_3, 4);
	ZEPHIR_CALL_FUNCTION(&_4, "pathinfo", NULL, 18, &sTpl, &_3);
	zephir_check_call_status();
	_5 = zephir_is_true(&_4);
	if (!(_5)) {
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_STRING(&_6, "$");
		ZEPHIR_INIT_VAR(&_7);
		zephir_fast_strpos(&_7, &sTpl, &_6, 0 );
		_5 = ZEPHIR_IS_LONG_IDENTICAL(&_7, 0);
	}
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "(");
	ZEPHIR_INIT_VAR(&_9);
	zephir_fast_strpos(&_9, &sTpl, &_8, 0 );
	if (_5) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "formatfile", NULL, 0, &sTpl);
		zephir_check_call_status();
		RETURN_MM();
	} else if (!ZEPHIR_IS_FALSE_IDENTICAL(&_9)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "formatfile", NULL, 0, &sTpl);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "theme_path");
		ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "getoption", &_12, 0, &_11$$5);
		zephir_check_call_status();
		if (!(zephir_is_true(&_10$$5))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme path must be set", "queryyetsimple/view/aconnect.zep", 282);
			return;
		}
		if (ZEPHIR_IS_STRING(&sTpl, "")) {
			ZEPHIR_INIT_VAR(&_14$$7);
			ZVAL_STRING(&_14$$7, "controller_name");
			ZEPHIR_CALL_METHOD(&_13$$7, this_ptr, "getoption", &_12, 0, &_14$$7);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_14$$7);
			ZVAL_STRING(&_14$$7, "controlleraction_depr");
			ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "getoption", &_12, 0, &_14$$7);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_14$$7);
			ZVAL_STRING(&_14$$7, "action_name");
			ZEPHIR_CALL_METHOD(&_16$$7, this_ptr, "getoption", &_12, 0, &_14$$7);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_17$$7);
			ZEPHIR_CONCAT_VVV(&_17$$7, &_13$$7, &_15$$7, &_16$$7);
			zephir_get_strval(&sTpl, &_17$$7);
		}
		ZEPHIR_INIT_NVAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "@");
		ZEPHIR_INIT_VAR(&_18$$5);
		zephir_fast_strpos(&_18$$5, &sTpl, &_11$$5, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_18$$5)) {
			ZEPHIR_INIT_VAR(&arrArray);
			zephir_fast_explode_str(&arrArray, SL("@"), &sTpl, LONG_MAX TSRMLS_CC);
			ZEPHIR_MAKE_REF(&arrArray);
			ZEPHIR_CALL_FUNCTION(&sTempTheme, "array_shift", &_19, 4, &arrArray);
			ZEPHIR_UNREF(&arrArray);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&sTheme, &sTempTheme);
			ZEPHIR_MAKE_REF(&arrArray);
			ZEPHIR_CALL_FUNCTION(&sTempTpl, "array_shift", &_19, 4, &arrArray);
			ZEPHIR_UNREF(&arrArray);
			zephir_check_call_status();
			zephir_get_strval(&sTpl, &sTempTpl);
		}
		ZEPHIR_INIT_VAR(&_20$$5);
		ZEPHIR_INIT_VAR(&_21$$5);
		zephir_create_array(&_21$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_22$$5);
		ZVAL_STRING(&_22$$5, "+");
		zephir_array_fast_append(&_21$$5, &_22$$5);
		ZEPHIR_INIT_NVAR(&_22$$5);
		ZVAL_STRING(&_22$$5, ":");
		zephir_array_fast_append(&_21$$5, &_22$$5);
		ZEPHIR_INIT_NVAR(&_22$$5);
		ZVAL_STRING(&_22$$5, "controlleraction_depr");
		ZEPHIR_CALL_METHOD(&_23$$5, this_ptr, "getoption", &_12, 0, &_22$$5);
		zephir_check_call_status();
		zephir_fast_str_replace(&_20$$5, &_21$$5, &_23$$5, &sTpl TSRMLS_CC);
		zephir_get_strval(&sTpl, &_20$$5);
		ZEPHIR_INIT_NVAR(&_22$$5);
		ZVAL_STRING(&_22$$5, "theme_path");
		ZEPHIR_CALL_METHOD(&_24$$5, this_ptr, "getoption", &_12, 0, &_22$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_25$$5, "dirname", NULL, 10, &_24$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&sReturnFile);
		ZEPHIR_CONCAT_VS(&sReturnFile, &_25$$5, "/");
		if (zephir_is_true(&sTheme)) {
			ZEPHIR_INIT_VAR(&_26$$9);
			ZEPHIR_CONCAT_VS(&_26$$9, &sTheme, "/");
			zephir_concat_self(&sReturnFile, &_26$$9 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_28$$10);
			ZVAL_STRING(&_28$$10, "theme_name");
			ZEPHIR_CALL_METHOD(&_27$$10, this_ptr, "getoption", &_12, 0, &_28$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_29$$10);
			ZEPHIR_CONCAT_VS(&_29$$10, &_27$$10, "/");
			zephir_concat_self(&sReturnFile, &_29$$10 TSRMLS_CC);
		}
		zephir_concat_self(&sReturnFile, &sTpl TSRMLS_CC);
		if (!(ZEPHIR_IS_EMPTY(&sExt))) {
			zephir_concat_self(&sReturnFile, &sExt TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_31$$12);
			ZVAL_STRING(&_31$$12, "suffix");
			ZEPHIR_CALL_METHOD(&_30$$12, this_ptr, "getoption", &_12, 0, &_31$$12);
			zephir_check_call_status();
			zephir_concat_self(&sReturnFile, &_30$$12 TSRMLS_CC);
		}
		RETURN_CCTOR(&sReturnFile);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化文件名
 *
 * @param string $sContent
 * @return string
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, formatFile) {

	zval _0, _2;
	zval *sContent_param = NULL, _1;
	zval sContent;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sContent);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sContent_param);

	zephir_get_strval(&sContent, sContent_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ":");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "+");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "->");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "::");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_fast_str_replace(&_1, &_0, &_2, &sContent TSRMLS_CC);
	RETURN_CCTOR(&_1);

}

/**
 * 匹配默认地址（文件不存在）
 *
 * @param string $sTpl 文件地址
 * @return string
 */
PHP_METHOD(Queryyetsimple_View_Aconnect, parseDefaultFile) {

	zend_bool _6, _9, _24, _29;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *sTpl_param = NULL, sBakTpl, sTempTpl, _0, _2, _3, _5, _7, _8, _10, _11, _21, _22, _23, _25, _26, _27, _28, _30, _12$$5, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5;
	zval sTpl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sTpl);
	ZVAL_UNDEF(&sBakTpl);
	ZVAL_UNDEF(&sTempTpl);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sTpl_param);

	zephir_get_strval(&sTpl, sTpl_param);


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 11, &sTpl);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_CTOR(&sTpl);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "theme_path");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", &_4, 0, &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme path must be set", "queryyetsimple/view/aconnect.zep", 354);
		return;
	}
	ZEPHIR_CPY_WRT(&sBakTpl, &sTpl);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, ":");
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_strpos(&_5, &sTpl, &_3, 0 );
	_6 = !ZEPHIR_IS_FALSE_IDENTICAL(&_5);
	if (!(_6)) {
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_STRING(&_7, "/");
		ZEPHIR_INIT_VAR(&_8);
		zephir_fast_strpos(&_8, &sTpl, &_7, 0 );
		_6 = ZEPHIR_IS_LONG_IDENTICAL(&_8, 0);
	}
	_9 = _6;
	if (!(_9)) {
		ZEPHIR_INIT_VAR(&_10);
		ZVAL_STRING(&_10, "\\");
		ZEPHIR_INIT_VAR(&_11);
		zephir_fast_strpos(&_11, &sTpl, &_10, 0 );
		_9 = ZEPHIR_IS_LONG_IDENTICAL(&_11, 0);
	}
	if (_9) {
		ZEPHIR_INIT_VAR(&_12$$5);
		ZEPHIR_INIT_VAR(&_14$$5);
		ZVAL_STRING(&_14$$5, "theme_path");
		ZEPHIR_CALL_METHOD(&_13$$5, this_ptr, "getoption", &_4, 0, &_14$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_15$$5);
		ZEPHIR_CONCAT_VS(&_15$$5, &_13$$5, "/");
		ZEPHIR_INIT_NVAR(&_14$$5);
		ZVAL_STRING(&_14$$5, "\\");
		ZEPHIR_INIT_VAR(&_16$$5);
		ZVAL_STRING(&_16$$5, "/");
		zephir_fast_str_replace(&_12$$5, &_14$$5, &_16$$5, &_15$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_17$$5);
		ZEPHIR_INIT_VAR(&_18$$5);
		ZVAL_STRING(&_18$$5, "\\");
		ZEPHIR_INIT_VAR(&_19$$5);
		ZVAL_STRING(&_19$$5, "/");
		zephir_fast_str_replace(&_17$$5, &_18$$5, &_19$$5, &sTpl TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_20$$5);
		ZVAL_STRING(&_20$$5, "");
		ZEPHIR_INIT_NVAR(&sTpl);
		zephir_fast_str_replace(&sTpl, &_12$$5, &_20$$5, &_17$$5 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_22);
	ZVAL_STRING(&_22, "theme_path_default");
	ZEPHIR_CALL_METHOD(&_21, this_ptr, "getoption", &_4, 0, &_22);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sTempTpl);
	ZEPHIR_CONCAT_VSV(&sTempTpl, &_21, "/", &sTpl);
	ZEPHIR_INIT_NVAR(&_22);
	ZVAL_STRING(&_22, "theme_path_default");
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "getoption", &_4, 0, &_22);
	zephir_check_call_status();
	_24 = zephir_is_true(&_23);
	if (_24) {
		ZEPHIR_CALL_FUNCTION(&_25, "is_file", &_1, 11, &sTempTpl);
		zephir_check_call_status();
		_24 = zephir_is_true(&_25);
	}
	if (_24) {
		RETURN_CCTOR(&sTempTpl);
	}
	ZEPHIR_INIT_NVAR(&_22);
	ZVAL_STRING(&_22, "theme_path");
	ZEPHIR_CALL_METHOD(&_26, this_ptr, "getoption", &_4, 0, &_22);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_27, "dirname", NULL, 10, &_26);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&sTempTpl);
	ZEPHIR_CONCAT_VSV(&sTempTpl, &_27, "/default/", &sTpl);
	ZEPHIR_INIT_NVAR(&_22);
	ZVAL_STRING(&_22, "theme_name");
	ZEPHIR_CALL_METHOD(&_28, this_ptr, "getoption", &_4, 0, &_22);
	zephir_check_call_status();
	_29 = !ZEPHIR_IS_STRING(&_28, "default");
	if (_29) {
		ZEPHIR_CALL_FUNCTION(&_30, "is_file", &_1, 11, &sTempTpl);
		zephir_check_call_status();
		_29 = zephir_is_true(&_30);
	}
	if (_29) {
		RETURN_CCTOR(&sTempTpl);
	}
	RETURN_CCTOR(&sBakTpl);

}

zend_object *zephir_init_properties_Queryyetsimple_View_Aconnect(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("arrVar"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("arrVar"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

