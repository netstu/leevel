
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/require.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/time.h"


/**
 * 模板处理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.02
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_View_Theme) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\View, Theme, queryyetsimple, view_theme, queryyetsimple_view_theme_method_entry, 0);

	/**
	 * 视图分析器
	 *
	 * @var \queryyetsimple\view\iparser
	 */
	zend_declare_property_null(queryyetsimple_view_theme_ce, SL("objParse"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 解析 parse
	 *
	 * @var callable
	 */
	zend_declare_property_null(queryyetsimple_view_theme_ce, SL("calParseResolver"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 变量值
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_view_theme_ce, SL("arrVar"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_view_theme_ce, SL("arrOption"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_view_theme_ce->create_object = zephir_init_properties_Queryyetsimple_View_Theme;

	zend_class_implements(queryyetsimple_view_theme_ce TSRMLS_CC, 1, queryyetsimple_view_itheme_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array arrOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_View_Theme, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "options", NULL, 0, &arrOption);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置 parse 解析回调
 *
 * @param callable $calParseResolver
 * @return void
 */
PHP_METHOD(Queryyetsimple_View_Theme, setParseResolver) {

	zval *calParseResolver, calParseResolver_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&calParseResolver_sub);

	zephir_fetch_params(0, 1, 0, &calParseResolver);



	zend_update_static_property(queryyetsimple_view_theme_ce, ZEND_STRL("calParseResolver"), calParseResolver);

}

/**
 * 解析 parse
 *
 * @return \queryyetsimple\view\iparser
 */
PHP_METHOD(Queryyetsimple_View_Theme, resolverParse) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_static_property_ce(&_0, queryyetsimple_view_theme_ce, SL("calParseResolver"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Theme not set parse resolver", "queryyetsimple/view/theme.zep", 105);
		return;
	}
	zephir_read_static_property_ce(&_1, queryyetsimple_view_theme_ce, SL("calParseResolver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_USER_FUNC(return_value, &_1);
	zephir_check_call_status();
	return;

}

/**
 * 获取分析器
 *
 * @return \queryyetsimple\view\iparser
 */
PHP_METHOD(Queryyetsimple_View_Theme, parser) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("objParse"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "objParse");
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolverparse", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("objParse"), &_1);
	RETURN_MM_MEMBER(getThis(), "objParse");

}

/**
 * 加载视图文件
 *
 * @param string $sFile 视图文件地址
 * @param boolean $bDisplay 是否显示
 * @param string $strExt 后缀
 * @param string $sTargetCache 主模板缓存路径
 * @param string $sMd5 源文件地址 md5 标记
 * @return string
 */
PHP_METHOD(Queryyetsimple_View_Theme, display) {

	zend_string *_5$$3;
	zend_ulong _4$$3;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool bDisplay, _11$$6;
	zval *sFile_param = NULL, *bDisplay_param = NULL, *strExt_param = NULL, *sTargetCache_param = NULL, *sMd5_param = NULL, sCachePath, sTargetContent, sChildCache, sReturn, strVarKey, mixVarValue, _0, _1, _7, _2$$3, *_3$$3, _6$$4, _8$$5, _9$$6, _12$$6, _14$$7, _15$$7, _16$$7, _17$$7, _18$$8, _19$$8, _20$$8;
	zval sFile, strExt, sTargetCache, sMd5, _13$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sFile);
	ZVAL_UNDEF(&strExt);
	ZVAL_UNDEF(&sTargetCache);
	ZVAL_UNDEF(&sMd5);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&sCachePath);
	ZVAL_UNDEF(&sTargetContent);
	ZVAL_UNDEF(&sChildCache);
	ZVAL_UNDEF(&sReturn);
	ZVAL_UNDEF(&strVarKey);
	ZVAL_UNDEF(&mixVarValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &sFile_param, &bDisplay_param, &strExt_param, &sTargetCache_param, &sMd5_param);

	zephir_get_strval(&sFile, sFile_param);
	if (!bDisplay_param) {
		bDisplay = 1;
	} else {
		bDisplay = zephir_get_boolval(bDisplay_param);
	}
	if (!strExt_param) {
		ZEPHIR_INIT_VAR(&strExt);
		ZVAL_STRING(&strExt, "");
	} else {
		zephir_get_strval(&strExt, strExt_param);
	}
	if (!sTargetCache_param) {
		ZEPHIR_INIT_VAR(&sTargetCache);
		ZVAL_STRING(&sTargetCache, "");
	} else {
		zephir_get_strval(&sTargetCache, sTargetCache_param);
	}
	if (!sMd5_param) {
		ZEPHIR_INIT_VAR(&sMd5);
		ZVAL_STRING(&sMd5, "");
	} else {
		zephir_get_strval(&sMd5, sMd5_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parsedisplayfile", NULL, 0, &sFile, &strExt);
	zephir_check_call_status();
	zephir_get_strval(&sFile, &_0);
	zephir_read_property(&_1, this_ptr, SL("arrVar"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_1))) {
		zephir_read_property(&_2$$3, this_ptr, SL("arrVar"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_2$$3, 0, "queryyetsimple/view/theme.zep", 147);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2$$3), _4$$3, _5$$3, _3$$3)
		{
			ZEPHIR_INIT_NVAR(&strVarKey);
			if (_5$$3 != NULL) { 
				ZVAL_STR_COPY(&strVarKey, _5$$3);
			} else {
				ZVAL_LONG(&strVarKey, _4$$3);
			}
			ZEPHIR_INIT_NVAR(&mixVarValue);
			ZVAL_COPY(&mixVarValue, _3$$3);
			ZEPHIR_CPY_WRT(&_6$$4, &mixVarValue);
			if (zephir_set_symbol(&strVarKey, &_6$$4 TSRMLS_CC) == FAILURE) {
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mixVarValue);
		ZEPHIR_INIT_NVAR(&strVarKey);
	}
	ZEPHIR_CALL_METHOD(&sCachePath, this_ptr, "getcachepath", NULL, 0, &sFile);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "iscacheexpired", NULL, 0, &sFile, &sCachePath);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "parser", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_8$$5, "docombile", NULL, 0, &sFile, &sCachePath);
		zephir_check_call_status();
	}
	if (!(Z_TYPE_P(&sTargetCache) == IS_UNDEF) && Z_STRLEN_P(&sTargetCache)) {
		ZEPHIR_CALL_FUNCTION(&_9$$6, "is_file", &_10, 5, &sFile);
		zephir_check_call_status();
		_11$$6 = zephir_is_true(&_9$$6);
		if (_11$$6) {
			ZEPHIR_CALL_FUNCTION(&_12$$6, "is_file", &_10, 5, &sTargetCache);
			zephir_check_call_status();
			_11$$6 = zephir_is_true(&_12$$6);
		}
		if (_11$$6) {
			ZEPHIR_INIT_VAR(&sTargetContent);
			zephir_file_get_contents(&sTargetContent, &sTargetCache TSRMLS_CC);
			ZEPHIR_INIT_VAR(&sChildCache);
			zephir_file_get_contents(&sChildCache, &sCachePath TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_13$$7);
			ZEPHIR_CONCAT_SVSVS(&_13$$7, "/<!--<\\#\\#\\#\\#incl\\*", &sMd5, "\\*ude\\#\\#\\#\\#>-->(.*?)<!--<\\/\\#\\#\\#\\#incl\\*", &sMd5, "\\*ude\\#\\#\\#\\#\\/>-->/s");
			ZEPHIR_INIT_VAR(&_14$$7);
			ZEPHIR_GET_CONSTANT(&_14$$7, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_15$$7);
			zephir_fast_strpos(&_15$$7, &sChildCache, &_14$$7, 0 );
			ZEPHIR_INIT_VAR(&_16$$7);
			zephir_substr(&_16$$7, &sChildCache, zephir_get_intval(&_15$$7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_FUNCTION(&_17$$7, "preg_replace", NULL, 34, &_13$$7, &_16$$7, &sTargetContent);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&sTargetContent, &_17$$7);
			zephir_file_put_contents(NULL, &sTargetCache, &sTargetContent TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_18$$8);
			object_init_ex(&_18$$8, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_19$$8);
			ZVAL_STRING(&_19$$8, "Source %s and target cache %s is not a valid path");
			ZEPHIR_CALL_FUNCTION(&_20$$8, "sprintf", NULL, 1, &_19$$8, &sFile, &sTargetCache);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_18$$8, "__construct", NULL, 32, &_20$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$8, "queryyetsimple/view/theme.zep", 165 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (bDisplay == 0) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 35);
		zephir_check_call_status();
		if (zephir_require_zval(&sCachePath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CALL_FUNCTION(&sReturn, "ob_get_contents", NULL, 36);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 37);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fixie", NULL, 0, &sReturn);
		zephir_check_call_status();
		RETURN_CCTOR(&sReturn);
	} else {
		if (zephir_require_zval(&sCachePath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置模板变量
 *
 * @param mixed $mixName
 * @param mixed $mixValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_View_Theme, setVar) {

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
PHP_METHOD(Queryyetsimple_View_Theme, getVar) {

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
		zephir_array_fetch(&_0, &_2, &sName, PH_NOISY, "queryyetsimple/view/theme.zep", 209 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_View_Theme, deleteVar) {

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
	zephir_is_iterable(mixName, 0, "queryyetsimple/view/theme.zep", 230);
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
PHP_METHOD(Queryyetsimple_View_Theme, clearVar) {

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
 * 获取编译路径
 *
 * @param string $sFile
 * @return string
 */
PHP_METHOD(Queryyetsimple_View_Theme, getCachePath) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sFile_param = NULL, _0, _1, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14;
	zval sFile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sFile_param);

	zephir_get_strval(&sFile, sFile_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "theme_cache_path");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", &_2, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme cache path must be set", "queryyetsimple/view/theme.zep", 254);
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "\\");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/");
	zephir_fast_str_replace(&_1, &_3, &_4, &sFile TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "//");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/");
	ZEPHIR_INIT_NVAR(&sFile);
	zephir_fast_str_replace(&sFile, &_5, &_6, &_1 TSRMLS_CC);
	ZVAL_LONG(&_7, 4);
	ZEPHIR_CALL_FUNCTION(&_8, "pathinfo", NULL, 25, &sFile, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SV(&_9, ".", &_8);
	ZEPHIR_CALL_FUNCTION(&_10, "basename", NULL, 38, &sFile, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	zephir_md5(&_11, &sFile);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_VSVS(&_12, &_10, ".", &_11, ".php");
	zephir_get_strval(&sFile, &_12);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "theme_cache_path");
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "getoption", &_2, 0, &_14);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_13, "/", &sFile);
	RETURN_MM();

}

/**
 * 修改单个配置
 *
 * @param string $strName
 * @param mixed $mixValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Theme, option) {

	zval *strName_param = NULL, *mixValue, mixValue_sub;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&mixValue_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strName_param, &mixValue);

	zephir_get_strval(&strName, strName_param);


	if (!(Z_TYPE_P(&strName) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Option set name must be a string.", "queryyetsimple/view/theme.zep", 277);
		return;
	}
	zephir_update_property_array(this_ptr, SL("arrOption"), &strName, mixValue TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 修改数组配置
 *
 * @param string $strName
 * @param array $arrValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Theme, optionArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrValue;
	zval *strName_param = NULL, *arrValue_param = NULL, _0, _1;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arrValue);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strName_param, &arrValue_param);

	zephir_get_strval(&strName, strName_param);
	zephir_get_arrval(&arrValue, arrValue_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &strName);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &arrValue TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "option", NULL, 0, &strName, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 修改多个配置
 *
 * @param string $strName
 * @param mixed $mixValue
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Theme, options) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, strName, mixValue, *_0;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&mixValue);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	if (ZEPHIR_IS_EMPTY(&arrOption)) {
		RETURN_THIS();
	}
	zephir_is_iterable(&arrOption, 0, "queryyetsimple/view/theme.zep", 314);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arrOption), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&strName);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&strName, _2);
		} else {
			ZVAL_LONG(&strName, _1);
		}
		ZEPHIR_INIT_NVAR(&mixValue);
		ZVAL_COPY(&mixValue, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "option", &_3, 0, &strName, &mixValue);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&mixValue);
	ZEPHIR_INIT_NVAR(&strName);
	RETURN_THIS();

}

/**
 * 获取单个配置
 *
 * @param string $strName
 * @param mixed $mixDefault
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_View_Theme, getOption) {

	zval *strName_param = NULL, *mixDefault = NULL, mixDefault_sub, __$null, _0, _1, _2;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&mixDefault_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strName_param, &mixDefault);

	zephir_get_strval(&strName, strName_param);
	if (!mixDefault) {
		mixDefault = &mixDefault_sub;
		mixDefault = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &strName)) {
		zephir_read_property(&_2, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &strName, PH_NOISY, "queryyetsimple/view/theme.zep", 326 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, mixDefault);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 获取所有配置
 *
 * @param array $arrOption
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_View_Theme, getOptions) {

	zval *arrOption_param = NULL, _0$$3;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&arrOption))) {
		zephir_read_property(&_0$$3, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(return_value, &_0$$3, &arrOption TSRMLS_CC);
		RETURN_MM();
	} else {
		RETURN_MM_MEMBER(getThis(), "arrOption");
	}

}

/**
 * 删除单个配置
 *
 * @param string $strName
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Theme, deleteOption) {

	zval *strName_param = NULL, _0, _1$$3;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strName_param);

	zephir_get_strval(&strName, strName_param);


	zephir_read_property(&_0, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &strName)) {
		zephir_read_property(&_1$$3, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &strName, PH_SEPARATE);
	}
	RETURN_THIS();

}

/**
 * 删除多个配置
 *
 * @param array $arrOption
 * @return $this
 */
PHP_METHOD(Queryyetsimple_View_Theme, deleteOptions) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, strOption, *_0;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&strOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&arrOption))) {
		RETURN_THIS();
	}
	zephir_is_iterable(&arrOption, 0, "queryyetsimple/view/theme.zep", 377);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrOption), _0)
	{
		ZEPHIR_INIT_NVAR(&strOption);
		ZVAL_COPY(&strOption, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteoption", &_1, 0, &strOption);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&strOption);
	RETURN_THIS();

}

/**
 * 分析展示的视图文件
 *
 * @param string $sFile 视图文件地址
 * @param string $strExt 后缀
 * @return string|void
 */
PHP_METHOD(Queryyetsimple_View_Theme, parseDisplayFile) {

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


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 5, &sFile);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "parsefile", NULL, 0, &sFile, &strExt);
		zephir_check_call_status();
		zephir_get_strval(&sFile, &_2$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_3, "is_file", &_1, 5, &sFile);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "parsedefaultfile", NULL, 0, &sFile);
		zephir_check_call_status();
		zephir_get_strval(&sFile, &_4$$4);
	}
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_1, 5, &sFile);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_7$$5);
		ZVAL_STRING(&_7$$5, "Template file %s does not exist.");
		ZEPHIR_CALL_FUNCTION(&_8$$5, "sprintf", NULL, 1, &_7$$5, &sFile);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 32, &_8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "queryyetsimple/view/theme.zep", 400 TSRMLS_CC);
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
PHP_METHOD(Queryyetsimple_View_Theme, parseFile) {

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
	ZEPHIR_CALL_FUNCTION(&_4, "pathinfo", NULL, 25, &sTpl, &_3);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme path must be set", "queryyetsimple/view/theme.zep", 426);
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
			ZEPHIR_CALL_FUNCTION(&sTempTheme, "array_shift", &_19, 11, &arrArray);
			ZEPHIR_UNREF(&arrArray);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&sTheme, &sTempTheme);
			ZEPHIR_MAKE_REF(&arrArray);
			ZEPHIR_CALL_FUNCTION(&sTempTpl, "array_shift", &_19, 11, &arrArray);
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
		ZEPHIR_CALL_FUNCTION(&_25$$5, "dirname", NULL, 4, &_24$$5);
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
PHP_METHOD(Queryyetsimple_View_Theme, formatFile) {

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
PHP_METHOD(Queryyetsimple_View_Theme, parseDefaultFile) {

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


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 5, &sTpl);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_CTOR(&sTpl);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "theme_path");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getoption", &_4, 0, &_3);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme path must be set", "queryyetsimple/view/theme.zep", 498);
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
		ZEPHIR_CALL_FUNCTION(&_25, "is_file", &_1, 5, &sTempTpl);
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
	ZEPHIR_CALL_FUNCTION(&_27, "dirname", NULL, 4, &_26);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&sTempTpl);
	ZEPHIR_CONCAT_VSV(&sTempTpl, &_27, "/default/", &sTpl);
	ZEPHIR_INIT_NVAR(&_22);
	ZVAL_STRING(&_22, "theme_name");
	ZEPHIR_CALL_METHOD(&_28, this_ptr, "getoption", &_4, 0, &_22);
	zephir_check_call_status();
	_29 = !ZEPHIR_IS_STRING(&_28, "default");
	if (_29) {
		ZEPHIR_CALL_FUNCTION(&_30, "is_file", &_1, 5, &sTempTpl);
		zephir_check_call_status();
		_29 = zephir_is_true(&_30);
	}
	if (_29) {
		RETURN_CCTOR(&sTempTpl);
	}
	RETURN_CCTOR(&sBakTpl);

}

/**
 * 判断缓存是否过期
 *
 * @param string $sFile
 * @param string $sCachePath
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_View_Theme, isCacheExpired) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sFile_param = NULL, *sCachePath_param = NULL, _0, _1, _3, _4, _5, _6, _7, _8;
	zval sFile, sCachePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sFile);
	ZVAL_UNDEF(&sCachePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sFile_param, &sCachePath_param);

	zephir_get_strval(&sFile, sFile_param);
	zephir_get_strval(&sCachePath, sCachePath_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "app_development");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", &_2, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&_3, "is_file", NULL, 5, &sCachePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "cache_lifetime");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getoption", &_2, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(&_4, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_1);
	zephir_filemtime(&_1, &sCachePath TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "cache_lifetime");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getoption", &_2, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_6);
	zephir_time(&_6);
	if (ZEPHIR_GT_LONG(&_6, (zephir_get_numberval(&_1) + zephir_get_intval(&_5)))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_filemtime(&_7, &sFile TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_8);
	zephir_filemtime(&_8, &sCachePath TSRMLS_CC);
	if (ZEPHIR_GE(&_7, &_8)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 修复 ie 显示问题
 * 过滤编译文件子模板定位注释标签，防止在网页头部出现注释，导致 IE 浏览器不居中
 *
 * @param string $sContent
 * @return string
 */
PHP_METHOD(Queryyetsimple_View_Theme, fixIe) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sContent_param = NULL, _0, _1, _2$$3, _3$$3, _4$$3, _6$$3;
	zval sContent;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sContent);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sContent_param);

	zephir_get_strval(&sContent, sContent_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cache_children");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "/<!--<\\#\\#\\#\\#incl\\*(.*?)\\*ude\\#\\#\\#\\#>-->/");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "preg_replace", &_5, 34, &_2$$3, &_3$$3, &sContent);
		zephir_check_call_status();
		zephir_get_strval(&sContent, &_4$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "/<!--<\\/\\#\\#\\#\\#incl\\*(.*?)\\*ude\\#\\#\\#\\#\\/>-->/");
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "preg_replace", &_5, 34, &_2$$3, &_3$$3, &sContent);
		zephir_check_call_status();
		zephir_get_strval(&sContent, &_6$$3);
	}
	RETURN_CTOR(&sContent);

}

zend_object *zephir_init_properties_Queryyetsimple_View_Theme(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval __$false, _0, _2, _3$$4;
		ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 10, 0 TSRMLS_CC);
			zephir_array_update_string(&_1$$3, SL("app_development"), &__$false, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_1$$3, SL("controller_name"), SL("index"));
			add_assoc_stringl_ex(&_1$$3, SL("action_name"), SL("index"));
			add_assoc_stringl_ex(&_1$$3, SL("controlleraction_depr"), SL("_"));
			add_assoc_stringl_ex(&_1$$3, SL("theme_name"), SL("default"));
			add_assoc_stringl_ex(&_1$$3, SL("theme_path"), SL(""));
			add_assoc_stringl_ex(&_1$$3, SL("theme_path_default"), SL(""));
			add_assoc_stringl_ex(&_1$$3, SL("suffix"), SL(".html"));
			add_assoc_stringl_ex(&_1$$3, SL("theme_cache_path"), SL(""));
			zephir_array_update_string(&_1$$3, SL("cache_children"), &__$false, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("arrOption"), &_1$$3);
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

