
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/require.h"
#include "kernel/time.h"
#include "kernel/array.h"


/**
 * html 模板处理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2016.11.18
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_View_Html) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\View, Html, queryyetsimple, view_html, queryyetsimple_view_aconnect_ce, queryyetsimple_view_html_method_entry, 0);

	/**
	 * 视图分析器
	 *
	 * @var \queryyetsimple\view\iparser
	 */
	zend_declare_property_null(queryyetsimple_view_html_ce, SL("objParse"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 解析 parse
	 *
	 * @var callable
	 */
	zend_declare_property_null(queryyetsimple_view_html_ce, SL("calParseResolver"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_view_html_ce, SL("arrOption"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_view_html_ce->create_object = zephir_init_properties_Queryyetsimple_View_Html;

	zend_class_implements(queryyetsimple_view_html_ce TSRMLS_CC, 1, queryyetsimple_view_iconnect_ce);
	return SUCCESS;

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
PHP_METHOD(Queryyetsimple_View_Html, display) {

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
		zephir_is_iterable(&_2$$3, 0, "queryyetsimple/view/html.zep", 91);
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
		ZEPHIR_CALL_FUNCTION(&_9$$6, "is_file", &_10, 11, &sFile);
		zephir_check_call_status();
		_11$$6 = zephir_is_true(&_9$$6);
		if (_11$$6) {
			ZEPHIR_CALL_FUNCTION(&_12$$6, "is_file", &_10, 11, &sTargetCache);
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
			ZEPHIR_CALL_FUNCTION(&_17$$7, "preg_replace", NULL, 51, &_13$$7, &_16$$7, &sTargetContent);
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
			ZEPHIR_CALL_METHOD(NULL, &_18$$8, "__construct", NULL, 17, &_20$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$8, "queryyetsimple/view/html.zep", 109 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (bDisplay == 0) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 52);
		zephir_check_call_status();
		if (zephir_require_zval(&sCachePath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CALL_FUNCTION(&sReturn, "ob_get_contents", NULL, 53);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 54);
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
 * 设置 parse 解析回调
 *
 * @param callable $calParseResolver
 * @return void
 */
PHP_METHOD(Queryyetsimple_View_Html, setParseResolver) {

	zval *calParseResolver, calParseResolver_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&calParseResolver_sub);

	zephir_fetch_params(0, 1, 0, &calParseResolver);



	zend_update_static_property(queryyetsimple_view_html_ce, ZEND_STRL("calParseResolver"), calParseResolver);

}

/**
 * 解析 parse
 *
 * @return \queryyetsimple\view\iparser
 */
PHP_METHOD(Queryyetsimple_View_Html, resolverParse) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_static_property_ce(&_0, queryyetsimple_view_html_ce, SL("calParseResolver"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Theme not set parse resolver", "queryyetsimple/view/html.zep", 145);
		return;
	}
	zephir_read_static_property_ce(&_1, queryyetsimple_view_html_ce, SL("calParseResolver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_USER_FUNC(return_value, &_1);
	zephir_check_call_status();
	return;

}

/**
 * 获取分析器
 *
 * @return \queryyetsimple\view\iparser
 */
PHP_METHOD(Queryyetsimple_View_Html, parser) {

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
 * 获取编译路径
 *
 * @param string $sFile
 * @return string
 */
PHP_METHOD(Queryyetsimple_View_Html, getCachePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sFile_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13;
	zval sFile;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sFile_param);

	zephir_get_strval(&sFile, sFile_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "theme_cache_path");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme cache path must be set", "queryyetsimple/view/html.zep", 174);
		return;
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/");
	zephir_fast_str_replace(&_1, &_2, &_3, &sFile TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "//");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/");
	ZEPHIR_INIT_NVAR(&sFile);
	zephir_fast_str_replace(&sFile, &_4, &_5, &_1 TSRMLS_CC);
	ZVAL_LONG(&_6, 4);
	ZEPHIR_CALL_FUNCTION(&_7, "pathinfo", NULL, 18, &sFile, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_SV(&_8, ".", &_7);
	ZEPHIR_CALL_FUNCTION(&_9, "basename", NULL, 55, &sFile, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_10);
	zephir_md5(&_10, &sFile);
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_CONCAT_VSVS(&_11, &_9, ".", &_10, ".php");
	zephir_get_strval(&sFile, &_11);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "theme_cache_path");
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getoption", NULL, 0, &_13);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_12, "/", &sFile);
	RETURN_MM();

}

/**
 * 判断缓存是否过期
 *
 * @param string $sFile
 * @param string $sCachePath
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_View_Html, isCacheExpired) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sFile_param = NULL, *sCachePath_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zval sFile, sCachePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sFile);
	ZVAL_UNDEF(&sCachePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sFile_param, &sCachePath_param);

	zephir_get_strval(&sFile, sFile_param);
	zephir_get_strval(&sCachePath, sCachePath_param);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "app_development");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&_2, "is_file", NULL, 11, &sCachePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "cache_lifetime");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", NULL, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(&_3, 0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(&_1);
	zephir_filemtime(&_1, &sCachePath TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "cache_lifetime");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getoption", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	zephir_time(&_5);
	if (ZEPHIR_GT_LONG(&_5, (zephir_get_numberval(&_1) + zephir_get_intval(&_4)))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_filemtime(&_6, &sFile TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	zephir_filemtime(&_7, &sCachePath TSRMLS_CC);
	if (ZEPHIR_GE(&_6, &_7)) {
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
PHP_METHOD(Queryyetsimple_View_Html, fixIe) {

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
		ZEPHIR_CALL_FUNCTION(&_4$$3, "preg_replace", &_5, 51, &_2$$3, &_3$$3, &sContent);
		zephir_check_call_status();
		zephir_get_strval(&sContent, &_4$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "/<!--<\\/\\#\\#\\#\\#incl\\*(.*?)\\*ude\\#\\#\\#\\#\\/>-->/");
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "preg_replace", &_5, 51, &_2$$3, &_3$$3, &sContent);
		zephir_check_call_status();
		zephir_get_strval(&sContent, &_6$$3);
	}
	RETURN_CTOR(&sContent);

}

zend_object *zephir_init_properties_Queryyetsimple_View_Html(zend_class_entry *class_type TSRMLS_DC) {

		zval _5$$5;
	zval __$false, _0, _2, _4, _1$$3, _3$$4;
		ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

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
		zephir_read_property(&_4, this_ptr, SL("arrOption"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			zephir_create_array(&_5$$5, 10, 0 TSRMLS_CC);
			zephir_array_update_string(&_5$$5, SL("development"), &__$false, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_5$$5, SL("controller_name"), SL("index"));
			add_assoc_stringl_ex(&_5$$5, SL("action_name"), SL("index"));
			add_assoc_stringl_ex(&_5$$5, SL("controlleraction_depr"), SL("_"));
			add_assoc_stringl_ex(&_5$$5, SL("theme_name"), SL("default"));
			add_assoc_stringl_ex(&_5$$5, SL("theme_path"), SL(""));
			add_assoc_stringl_ex(&_5$$5, SL("theme_path_default"), SL(""));
			add_assoc_stringl_ex(&_5$$5, SL("suffix"), SL(".html"));
			add_assoc_stringl_ex(&_5$$5, SL("theme_cache_path"), SL(""));
			zephir_array_update_string(&_5$$5, SL("cache_children"), &__$false, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("arrOption"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

