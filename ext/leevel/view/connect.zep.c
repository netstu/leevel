
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
ZEPHIR_INIT_CLASS(Leevel_View_Connect) {

	ZEPHIR_REGISTER_CLASS(Leevel\\View, Connect, leevel, view_connect, leevel_view_connect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 变量值
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_view_connect_ce, SL("vars"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_view_connect_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_view_connect_ce->create_object = zephir_init_properties_Leevel_View_Connect;

	zend_class_implements(leevel_view_connect_ce TSRMLS_CC, 1, leevel_option_iclass_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array option
 * @return void
 */
PHP_METHOD(Leevel_View_Connect, __construct) {

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
 * @param mixed $name
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_View_Connect, setVar) {

	zval *name, name_sub, *value = NULL, value_sub, __$null, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &value);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	if (Z_TYPE_P(name) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, name TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("vars"), &_0$$3);
	} else {
		zephir_update_property_array(this_ptr, SL("vars"), name, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取变量值
 *
 * @param string|null $name
 * @return mixed
 */
PHP_METHOD(Leevel_View_Connect, getVar) {

	zval *name = NULL, name_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	if (Z_TYPE_P(name) == IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "vars");
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, name)) {
		zephir_read_property(&_2, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, name, PH_NOISY, "leevel/view/connect.zep", 87 TSRMLS_CC);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 删除变量值
 *
 * @return $this
 */
PHP_METHOD(Leevel_View_Connect, deleteVar) {

	zval item, name, args, _0, *_1, _2$$4, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_BadMethodCallException, "Wrong number of parameters", "leevel/view/connect.zep", 102);
		return;
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_array_fetch_long(&_0, &args, 0, PH_NOISY, "leevel/view/connect.zep", 105 TSRMLS_CC);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_long(&name, &args, 0, PH_NOISY, "leevel/view/connect.zep", 105 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&name, &args);
	}
	zephir_is_iterable(&name, 0, "leevel/view/connect.zep", 113);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&name), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		zephir_read_property(&_2$$4, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_2$$4, &item)) {
			zephir_read_property(&_3$$5, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_3$$5, &item, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_THIS();

}

/**
 * 清空变量值
 *
 * @param string|null $name
 * @return $this
 */
PHP_METHOD(Leevel_View_Connect, clearVar) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("vars"), &_0);
	RETURN_THIS();

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Leevel_View_Connect, option) {

	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	if (!(Z_TYPE_P(&name) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Option set name must be a string.", "leevel/view/connect.zep", 138);
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
PHP_METHOD(Leevel_View_Connect, optionArray) {

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
PHP_METHOD(Leevel_View_Connect, options) {

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
	zephir_is_iterable(&option, 0, "leevel/view/connect.zep", 177);
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
PHP_METHOD(Leevel_View_Connect, getOption) {

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
		zephir_array_fetch(&_0, &_2, &name, PH_NOISY, "leevel/view/connect.zep", 189 TSRMLS_CC);
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
PHP_METHOD(Leevel_View_Connect, getOptions) {

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
PHP_METHOD(Leevel_View_Connect, deleteOption) {

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
PHP_METHOD(Leevel_View_Connect, deleteOptions) {

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
	zephir_is_iterable(&option, 0, "leevel/view/connect.zep", 240);
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
 * @param string $file 视图文件地址
 * @param string $ext 后缀
 * @return string|void
 */
PHP_METHOD(Leevel_View_Connect, parseDisplayFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *file_param = NULL, *ext_param = NULL, _0, _3, _5, _2$$3, _4$$4, _6$$5, _7$$5, _8$$5;
	zval file, ext;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &ext_param);

	zephir_get_strval(&file, file_param);
	if (!ext_param) {
		ZEPHIR_INIT_VAR(&ext);
		ZVAL_STRING(&ext, "");
	} else {
		zephir_get_strval(&ext, ext_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 27, &file);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "parsefile", NULL, 0, &file, &ext);
		zephir_check_call_status();
		zephir_get_strval(&file, &_2$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_3, "is_file", &_1, 27, &file);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "parsedefaultfile", NULL, 0, &file);
		zephir_check_call_status();
		zephir_get_strval(&file, &_4$$4);
	}
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_1, 27, &file);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "Template file %s does not exist.");
		ZEPHIR_CALL_FUNCTION(&_8$$5, "sprintf", NULL, 1, &_7$$5, &file);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 21, &_8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "leevel/view/connect.zep", 263 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&file);

}

/**
 * 分析模板真实路径			
 *
 * @param string $tpl 文件地址
 * @param string $ext 扩展名
 * @return string
 */
PHP_METHOD(Leevel_View_Connect, parseFile) {

	zval _22$$4;
	zend_bool _5, _8;
	zephir_fcall_cache_entry *_13 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tpl_param = NULL, *ext_param = NULL, arr, theme, tempTheme, tempTpl, result, _0, _1, _2, _3, _4, _6, _7, _9, _10, _11$$4, _12$$4, _19$$4, _21$$4, _23$$4, _24$$4, _25$$4, _26$$4, _14$$6, _15$$6, _16$$6, _17$$6, _18$$6, _27$$8, _28$$9, _29$$9, _30$$9, _31$$11, _32$$11;
	zval tpl, ext;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tpl);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&theme);
	ZVAL_UNDEF(&tempTheme);
	ZVAL_UNDEF(&tempTpl);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_22$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tpl_param, &ext_param);

	zephir_get_strval(&tpl, tpl_param);
	if (!ext_param) {
		ZEPHIR_INIT_VAR(&ext);
		ZVAL_STRING(&ext, "");
	} else {
		zephir_get_strval(&ext, ext_param);
	}


	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "->");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ".");
	zephir_fast_str_replace(&_0, &_1, &_2, &tpl TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&tpl);
	zephir_fast_trim(&tpl, &_0, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZVAL_LONG(&_3, 4);
	ZEPHIR_CALL_FUNCTION(&_4, "pathinfo", NULL, 55, &tpl, &_3);
	zephir_check_call_status();
	_5 = zephir_is_true(&_4);
	if (!(_5)) {
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_STRING(&_6, "$");
		ZEPHIR_INIT_VAR(&_7);
		zephir_fast_strpos(&_7, &tpl, &_6, 0 );
		_5 = ZEPHIR_IS_LONG_IDENTICAL(&_7, 0);
	}
	_8 = _5;
	if (!(_8)) {
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_STRING(&_9, "(");
		ZEPHIR_INIT_VAR(&_10);
		zephir_fast_strpos(&_10, &tpl, &_9, 0 );
		_8 = !ZEPHIR_IS_FALSE_IDENTICAL(&_10);
	}
	if (_8) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "formatfile", NULL, 0, &tpl);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_INIT_VAR(&_12$$4);
		ZVAL_STRING(&_12$$4, "theme_path");
		ZEPHIR_CALL_METHOD(&_11$$4, this_ptr, "getoption", &_13, 0, &_12$$4);
		zephir_check_call_status();
		if (!(zephir_is_true(&_11$$4))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme path must be set", "leevel/view/connect.zep", 287);
			return;
		}
		if (ZEPHIR_IS_STRING(&tpl, "")) {
			ZEPHIR_INIT_VAR(&_15$$6);
			ZVAL_STRING(&_15$$6, "controller_name");
			ZEPHIR_CALL_METHOD(&_14$$6, this_ptr, "getoption", &_13, 0, &_15$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_15$$6);
			ZVAL_STRING(&_15$$6, "controlleraction_depr");
			ZEPHIR_CALL_METHOD(&_16$$6, this_ptr, "getoption", &_13, 0, &_15$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_15$$6);
			ZVAL_STRING(&_15$$6, "action_name");
			ZEPHIR_CALL_METHOD(&_17$$6, this_ptr, "getoption", &_13, 0, &_15$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_18$$6);
			ZEPHIR_CONCAT_VVV(&_18$$6, &_14$$6, &_16$$6, &_17$$6);
			zephir_get_strval(&tpl, &_18$$6);
		}
		ZEPHIR_INIT_NVAR(&_12$$4);
		ZVAL_STRING(&_12$$4, "@");
		ZEPHIR_INIT_VAR(&_19$$4);
		zephir_fast_strpos(&_19$$4, &tpl, &_12$$4, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_19$$4)) {
			ZEPHIR_INIT_VAR(&arr);
			zephir_fast_explode_str(&arr, SL("@"), &tpl, LONG_MAX TSRMLS_CC);
			ZEPHIR_MAKE_REF(&arr);
			ZEPHIR_CALL_FUNCTION(&tempTheme, "array_shift", &_20, 6, &arr);
			ZEPHIR_UNREF(&arr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&theme, &tempTheme);
			ZEPHIR_MAKE_REF(&arr);
			ZEPHIR_CALL_FUNCTION(&tempTpl, "array_shift", &_20, 6, &arr);
			ZEPHIR_UNREF(&arr);
			zephir_check_call_status();
			zephir_get_strval(&tpl, &tempTpl);
		}
		ZEPHIR_INIT_VAR(&_21$$4);
		ZEPHIR_INIT_VAR(&_22$$4);
		zephir_create_array(&_22$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_23$$4);
		ZVAL_STRING(&_23$$4, "+");
		zephir_array_fast_append(&_22$$4, &_23$$4);
		ZEPHIR_INIT_NVAR(&_23$$4);
		ZVAL_STRING(&_23$$4, ":");
		zephir_array_fast_append(&_22$$4, &_23$$4);
		ZEPHIR_INIT_NVAR(&_23$$4);
		ZVAL_STRING(&_23$$4, "controlleraction_depr");
		ZEPHIR_CALL_METHOD(&_24$$4, this_ptr, "getoption", &_13, 0, &_23$$4);
		zephir_check_call_status();
		zephir_fast_str_replace(&_21$$4, &_22$$4, &_24$$4, &tpl TSRMLS_CC);
		zephir_get_strval(&tpl, &_21$$4);
		ZEPHIR_INIT_NVAR(&_23$$4);
		ZVAL_STRING(&_23$$4, "theme_path");
		ZEPHIR_CALL_METHOD(&_25$$4, this_ptr, "getoption", &_13, 0, &_23$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_26$$4, "dirname", NULL, 26, &_25$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&result);
		ZEPHIR_CONCAT_VS(&result, &_26$$4, "/");
		if (zephir_is_true(&theme)) {
			ZEPHIR_INIT_VAR(&_27$$8);
			ZEPHIR_CONCAT_VS(&_27$$8, &theme, "/");
			zephir_concat_self(&result, &_27$$8 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_29$$9);
			ZVAL_STRING(&_29$$9, "theme_name");
			ZEPHIR_CALL_METHOD(&_28$$9, this_ptr, "getoption", &_13, 0, &_29$$9);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_30$$9);
			ZEPHIR_CONCAT_VS(&_30$$9, &_28$$9, "/");
			zephir_concat_self(&result, &_30$$9 TSRMLS_CC);
		}
		zephir_concat_self(&result, &tpl TSRMLS_CC);
		if (!(ZEPHIR_IS_EMPTY(&ext))) {
			zephir_concat_self(&result, &ext TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_32$$11);
			ZVAL_STRING(&_32$$11, "suffix");
			ZEPHIR_CALL_METHOD(&_31$$11, this_ptr, "getoption", &_13, 0, &_32$$11);
			zephir_check_call_status();
			zephir_concat_self(&result, &_31$$11 TSRMLS_CC);
		}
		RETURN_CCTOR(&result);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化文件名
 *
 * @param string $content
 * @return string
 */
PHP_METHOD(Leevel_View_Connect, formatFile) {

	zval _0, _2;
	zval *content_param = NULL, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


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
	zephir_fast_str_replace(&_1, &_0, &_2, &content TSRMLS_CC);
	RETURN_CCTOR(&_1);

}

/**
 * 匹配默认地址（文件不存在）
 *
 * @param string $tpl 文件地址
 * @return string
 */
PHP_METHOD(Leevel_View_Connect, parseDefaultFile) {

	zend_bool _6, _9, _24, _29;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *tpl_param = NULL, bak, tempTpl, _0, _2, _3, _5, _7, _8, _10, _11, _21, _22, _23, _25, _26, _27, _28, _30, _12$$5, _13$$5, _14$$5, _15$$5, _16$$5, _17$$5, _18$$5, _19$$5, _20$$5;
	zval tpl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tpl);
	ZVAL_UNDEF(&bak);
	ZVAL_UNDEF(&tempTpl);
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
	zephir_fetch_params(1, 1, 0, &tpl_param);

	zephir_get_strval(&tpl, tpl_param);


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 27, &tpl);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_CTOR(&tpl);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "theme_path");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", &_4, 0, &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme path must be set", "leevel/view/connect.zep", 359);
		return;
	}
	ZEPHIR_CPY_WRT(&bak, &tpl);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, ":");
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_strpos(&_5, &tpl, &_3, 0 );
	_6 = !ZEPHIR_IS_FALSE_IDENTICAL(&_5);
	if (!(_6)) {
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_STRING(&_7, "/");
		ZEPHIR_INIT_VAR(&_8);
		zephir_fast_strpos(&_8, &tpl, &_7, 0 );
		_6 = ZEPHIR_IS_LONG_IDENTICAL(&_8, 0);
	}
	_9 = _6;
	if (!(_9)) {
		ZEPHIR_INIT_VAR(&_10);
		ZVAL_STRING(&_10, "\\");
		ZEPHIR_INIT_VAR(&_11);
		zephir_fast_strpos(&_11, &tpl, &_10, 0 );
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
		zephir_fast_str_replace(&_17$$5, &_18$$5, &_19$$5, &tpl TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_20$$5);
		ZVAL_STRING(&_20$$5, "");
		ZEPHIR_INIT_NVAR(&tpl);
		zephir_fast_str_replace(&tpl, &_12$$5, &_20$$5, &_17$$5 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_22);
	ZVAL_STRING(&_22, "theme_path_default");
	ZEPHIR_CALL_METHOD(&_21, this_ptr, "getoption", &_4, 0, &_22);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tempTpl);
	ZEPHIR_CONCAT_VSV(&tempTpl, &_21, "/", &tpl);
	ZEPHIR_INIT_NVAR(&_22);
	ZVAL_STRING(&_22, "theme_path_default");
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "getoption", &_4, 0, &_22);
	zephir_check_call_status();
	_24 = zephir_is_true(&_23);
	if (_24) {
		ZEPHIR_CALL_FUNCTION(&_25, "is_file", &_1, 27, &tempTpl);
		zephir_check_call_status();
		_24 = zephir_is_true(&_25);
	}
	if (_24) {
		RETURN_CCTOR(&tempTpl);
	}
	ZEPHIR_INIT_NVAR(&_22);
	ZVAL_STRING(&_22, "theme_path");
	ZEPHIR_CALL_METHOD(&_26, this_ptr, "getoption", &_4, 0, &_22);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_27, "dirname", NULL, 26, &_26);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&tempTpl);
	ZEPHIR_CONCAT_VSV(&tempTpl, &_27, "/default/", &tpl);
	ZEPHIR_INIT_NVAR(&_22);
	ZVAL_STRING(&_22, "theme_name");
	ZEPHIR_CALL_METHOD(&_28, this_ptr, "getoption", &_4, 0, &_22);
	zephir_check_call_status();
	_29 = !ZEPHIR_IS_STRING(&_28, "default");
	if (_29) {
		ZEPHIR_CALL_FUNCTION(&_30, "is_file", &_1, 27, &tempTpl);
		zephir_check_call_status();
		_29 = zephir_is_true(&_30);
	}
	if (_29) {
		RETURN_CCTOR(&tempTpl);
	}
	RETURN_CCTOR(&bak);

}

zend_object *zephir_init_properties_Leevel_View_Connect(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property(&_2, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("vars"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

