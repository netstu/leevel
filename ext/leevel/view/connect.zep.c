
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * 模板处理抽象类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
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
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array option
 * @return void
 */
PHP_METHOD(Leevel_View_Connect, __construct) {

	zval *option_param = NULL, _0, _1;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &option TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("option"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置配置
 * 
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Leevel_View_Connect, setOption) {

	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("option"), &name, value TSRMLS_CC);
	RETURN_THIS();

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
		zephir_array_fetch(&_0, &_2, name, PH_NOISY, "leevel/view/connect.zep", 98 TSRMLS_CC);
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

	zend_class_entry *_1$$3 = NULL;
	zval item, name, args, _3, *_4, _0$$3, _2$$3, _5$$4, _6$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (!_1$$3) {
		_1$$3 = zephir_fetch_class_str_ex(SL("Leevel\\View\\BadMethodCallException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_0$$3, _1$$3);
		if (zephir_has_constructor(&_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Wrong number of parameters");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_2$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_0$$3, "leevel/view/connect.zep", 113 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&_3);
	zephir_array_fetch_long(&_3, &args, 0, PH_NOISY, "leevel/view/connect.zep", 116 TSRMLS_CC);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_long(&name, &args, 0, PH_NOISY, "leevel/view/connect.zep", 116 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&name, &args);
	}
	zephir_is_iterable(&name, 0, "leevel/view/connect.zep", 124);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&name), _4)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _4);
		zephir_read_property(&_5$$4, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_5$$4, &item)) {
			zephir_read_property(&_6$$5, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_6$$5, &item, PH_SEPARATE);
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


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 22, &file);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "parsefile", NULL, 0, &file, &ext);
		zephir_check_call_status();
		zephir_get_strval(&file, &_2$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_3, "is_file", &_1, 22, &file);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "parsedefaultfile", NULL, 0, &file);
		zephir_check_call_status();
		zephir_get_strval(&file, &_4$$4);
	}
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_1, 22, &file);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "Template file %s does not exist.");
		ZEPHIR_CALL_FUNCTION(&_8$$5, "sprintf", NULL, 1, &_7$$5, &file);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 3, &_8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "leevel/view/connect.zep", 161 TSRMLS_CC);
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

	zval _24$$4;
	zend_bool _5, _8;
	zephir_fcall_cache_entry *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tpl_param = NULL, *ext_param = NULL, arr, theme, tempTheme, tempTpl, result, _0, _1, _2, _3, _4, _6, _7, _9, _10, _11$$4, _12$$4, _20$$4, _21$$4, _23$$4, _25$$4, _26$$4, _27$$4, _28$$4, _29$$4, _30$$4, _13$$6, _14$$6, _15$$6, _16$$6, _17$$6, _18$$6, _19$$6, _31$$8, _32$$9, _33$$9, _34$$9, _35$$11, _36$$11;
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
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_25$$4);
	ZVAL_UNDEF(&_26$$4);
	ZVAL_UNDEF(&_27$$4);
	ZVAL_UNDEF(&_28$$4);
	ZVAL_UNDEF(&_29$$4);
	ZVAL_UNDEF(&_30$$4);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&_36$$11);
	ZVAL_UNDEF(&_24$$4);

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
	ZEPHIR_CALL_FUNCTION(&_4, "pathinfo", NULL, 23, &tpl, &_3);
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
		zephir_read_property(&_11$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_12$$4, &_11$$4, SL("theme_path"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 186 TSRMLS_CC);
		if (!(zephir_is_true(&_12$$4))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme path must be set.", "leevel/view/connect.zep", 187);
			return;
		}
		if (ZEPHIR_IS_STRING(&tpl, "")) {
			zephir_read_property(&_13$$6, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_14$$6, &_13$$6, SL("controller_name"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 192 TSRMLS_CC);
			zephir_read_property(&_15$$6, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_16$$6, &_15$$6, SL("controlleraction_depr"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 193 TSRMLS_CC);
			zephir_read_property(&_17$$6, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_18$$6, &_17$$6, SL("action_name"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 194 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_19$$6);
			ZEPHIR_CONCAT_VVV(&_19$$6, &_14$$6, &_16$$6, &_18$$6);
			zephir_get_strval(&tpl, &_19$$6);
		}
		ZEPHIR_INIT_VAR(&_20$$4);
		ZVAL_STRING(&_20$$4, "@");
		ZEPHIR_INIT_VAR(&_21$$4);
		zephir_fast_strpos(&_21$$4, &tpl, &_20$$4, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_21$$4)) {
			ZEPHIR_INIT_VAR(&arr);
			zephir_fast_explode_str(&arr, SL("@"), &tpl, LONG_MAX TSRMLS_CC);
			ZEPHIR_MAKE_REF(&arr);
			ZEPHIR_CALL_FUNCTION(&tempTheme, "array_shift", &_22, 6, &arr);
			ZEPHIR_UNREF(&arr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&theme, &tempTheme);
			ZEPHIR_MAKE_REF(&arr);
			ZEPHIR_CALL_FUNCTION(&tempTpl, "array_shift", &_22, 6, &arr);
			ZEPHIR_UNREF(&arr);
			zephir_check_call_status();
			zephir_get_strval(&tpl, &tempTpl);
		}
		ZEPHIR_INIT_VAR(&_23$$4);
		ZEPHIR_INIT_VAR(&_24$$4);
		zephir_create_array(&_24$$4, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_25$$4);
		ZVAL_STRING(&_25$$4, "+");
		zephir_array_fast_append(&_24$$4, &_25$$4);
		ZEPHIR_INIT_NVAR(&_25$$4);
		ZVAL_STRING(&_25$$4, ":");
		zephir_array_fast_append(&_24$$4, &_25$$4);
		zephir_read_property(&_26$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_27$$4, &_26$$4, SL("controlleraction_depr"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 209 TSRMLS_CC);
		zephir_fast_str_replace(&_23$$4, &_24$$4, &_27$$4, &tpl TSRMLS_CC);
		zephir_get_strval(&tpl, &_23$$4);
		zephir_read_property(&_28$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_29$$4, &_28$$4, SL("theme_path"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 211 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_30$$4, "dirname", NULL, 24, &_29$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&result);
		ZEPHIR_CONCAT_VS(&result, &_30$$4, "/");
		if (zephir_is_true(&theme)) {
			ZEPHIR_INIT_VAR(&_31$$8);
			ZEPHIR_CONCAT_VS(&_31$$8, &theme, "/");
			zephir_concat_self(&result, &_31$$8 TSRMLS_CC);
		} else {
			zephir_read_property(&_32$$9, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_33$$9, &_32$$9, SL("theme_name"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 215 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_34$$9);
			ZEPHIR_CONCAT_VS(&_34$$9, &_33$$9, "/");
			zephir_concat_self(&result, &_34$$9 TSRMLS_CC);
		}
		zephir_concat_self(&result, &tpl TSRMLS_CC);
		if (!(ZEPHIR_IS_EMPTY(&ext))) {
			zephir_concat_self(&result, &ext TSRMLS_CC);
		} else {
			zephir_read_property(&_35$$11, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_36$$11, &_35$$11, SL("suffix"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 223 TSRMLS_CC);
			zephir_concat_self(&result, &_36$$11 TSRMLS_CC);
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

	zend_bool _4, _7, _24, _32;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_26 = NULL;
	zval *tpl_param = NULL, source, tempTpl, _0, _1, _2, _3, _5, _6, _8, _9, _20, _21, _22, _23, _25, _27, _28, _29, _30, _31, _33, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$4, _16$$4, _17$$4, _18$$4, _19$$4;
	zval tpl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tpl);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&tempTpl);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tpl_param);

	zephir_get_strval(&tpl, tpl_param);


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("theme_path"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 257 TSRMLS_CC);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme path must be set.", "leevel/view/connect.zep", 258);
		return;
	}
	ZEPHIR_CPY_WRT(&source, &tpl);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ":");
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_strpos(&_3, &tpl, &_2, 0 );
	_4 = !ZEPHIR_IS_FALSE_IDENTICAL(&_3);
	if (!(_4)) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "/");
		ZEPHIR_INIT_VAR(&_6);
		zephir_fast_strpos(&_6, &tpl, &_5, 0 );
		_4 = ZEPHIR_IS_LONG_IDENTICAL(&_6, 0);
	}
	_7 = _4;
	if (!(_7)) {
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_STRING(&_8, "\\");
		ZEPHIR_INIT_VAR(&_9);
		zephir_fast_strpos(&_9, &tpl, &_8, 0 );
		_7 = ZEPHIR_IS_LONG_IDENTICAL(&_9, 0);
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_10$$4);
		zephir_read_property(&_11$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_12$$4, &_11$$4, SL("theme_path"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 271 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_13$$4);
		ZEPHIR_CONCAT_VS(&_13$$4, &_12$$4, "/");
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "\\");
		ZEPHIR_INIT_VAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "/");
		zephir_fast_str_replace(&_10$$4, &_14$$4, &_15$$4, &_13$$4 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_16$$4);
		ZEPHIR_INIT_VAR(&_17$$4);
		ZVAL_STRING(&_17$$4, "\\");
		ZEPHIR_INIT_VAR(&_18$$4);
		ZVAL_STRING(&_18$$4, "/");
		zephir_fast_str_replace(&_16$$4, &_17$$4, &_18$$4, &tpl TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_19$$4);
		ZVAL_STRING(&_19$$4, "");
		ZEPHIR_INIT_NVAR(&tpl);
		zephir_fast_str_replace(&tpl, &_10$$4, &_19$$4, &_16$$4 TSRMLS_CC);
	}
	zephir_read_property(&_20, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_21, &_20, SL("theme_path_default"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 279 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&tempTpl);
	ZEPHIR_CONCAT_VSV(&tempTpl, &_21, "/", &tpl);
	zephir_read_property(&_22, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_23, &_22, SL("theme_path_default"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 281 TSRMLS_CC);
	_24 = zephir_is_true(&_23);
	if (_24) {
		ZEPHIR_CALL_FUNCTION(&_25, "is_file", &_26, 22, &tempTpl);
		zephir_check_call_status();
		_24 = zephir_is_true(&_25);
	}
	if (_24) {
		RETURN_CCTOR(&tempTpl);
	}
	zephir_read_property(&_27, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_28, &_27, SL("theme_path"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 286 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_29, "dirname", NULL, 24, &_28);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&tempTpl);
	ZEPHIR_CONCAT_VSV(&tempTpl, &_29, "/default/", &tpl);
	zephir_read_property(&_30, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_31, &_30, SL("theme_name"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 288 TSRMLS_CC);
	_32 = !ZEPHIR_IS_STRING(&_31, "default");
	if (_32) {
		ZEPHIR_CALL_FUNCTION(&_33, "is_file", &_26, 22, &tempTpl);
		zephir_check_call_status();
		_32 = zephir_is_true(&_33);
	}
	if (_32) {
		RETURN_CCTOR(&tempTpl);
	}
	RETURN_CCTOR(&source);

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

