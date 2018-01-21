
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * view 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.12
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_View_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\View, Manager, queryyetsimple, view_manager, queryyetsimple_support_manager_ce, queryyetsimple_view_manager_method_entry, 0);

	return SUCCESS;

}

/**
 * 取得配置命名空间
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_View_Manager, getOptionNamespace) {

	zval *this_ptr = getThis();


	RETURN_STRING("view");

}

/**
 * 创建连接对象
 *
 * @param object $connect
 * @return object
 */
PHP_METHOD(Queryyetsimple_View_Manager, createConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connect, connect_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connect);



	object_init_ex(return_value, queryyetsimple_view_view_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 55, connect);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 html 模板驱动
 *
 * @param array $options
 * @return \Queryyetsimple\View\Html
 */
PHP_METHOD(Queryyetsimple_View_Manager, makeConnectHtml) {

	zend_class_entry *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, parser, html, _0, _1, _2, _5;
	zval options, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&parser);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "html");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "viewoptioncommon", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_1, &options, &_2 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&options, &_1);
	_3 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_4, this_ptr);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "makeParserClosure");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_CALL_CE_STATIC(&parser, _3, "fromcallable", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	object_init_ex(&html, queryyetsimple_view_html_ce);
	ZEPHIR_CALL_METHOD(NULL, &html, "__construct", NULL, 56, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &html, "setparseresolver", NULL, 57, &parser);
	zephir_check_call_status();
	RETURN_CCTOR(&html);

}

/**
 * 创建 twig 模板驱动
 *
 * @param array $options
 * @return \Queryyetsimple\View\Twig
 */
PHP_METHOD(Queryyetsimple_View_Manager, makeConnectTwig) {

	zend_class_entry *_6 = NULL;
	zend_class_entry *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, parser, twig, _0, _1, _2, _5;
	zval options, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&parser);
	ZVAL_UNDEF(&twig);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "twig");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "viewoptioncommon", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_1, &options, &_2 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&options, &_1);
	_3 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_4, this_ptr);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "makeTwigParserClosure");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_CALL_CE_STATIC(&parser, _3, "fromcallable", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&twig);
	if (!_6) {
	_6 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\View\\Twig"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&twig, _6);
	if (zephir_has_constructor(&twig TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &twig, "__construct", NULL, 0, &options);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &twig, "setparseresolver", NULL, 0, &parser);
	zephir_check_call_status();
	RETURN_CCTOR(&twig);

}

/**
 * 创建 phpui 模板驱动
 *
 * @param array $options
 * @return \Queryyetsimple\View\Phpui
 */
PHP_METHOD(Queryyetsimple_View_Manager, makeConnectPhpui) {

	zend_class_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1, _2;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "phpui");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "viewoptioncommon", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_1, &options, &_2 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&options, &_1);
	if (!_3) {
	_3 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\View\\Phpui"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _3);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &options);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 创建 v8 模板驱动
 *
 * @param array $options
 * @return \Queryyetsimple\View\Vue
 */
PHP_METHOD(Queryyetsimple_View_Manager, makeConnectV8) {

	zend_class_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1, _2;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "v8");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "viewoptioncommon", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_1, &options, &_2 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&options, &_1);
	if (!_3) {
	_3 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\View\\V8"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _3);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &options);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 视图公共配置
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_View_Manager, viewOptionCommon) {

	zval options, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
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

	ZEPHIR_INIT_VAR(&options);
	zephir_create_array(&options, 5, 0 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "development", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("development"), &_1, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_2, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "controller_name");
	ZEPHIR_CALL_METHOD(&_1, &_2, "make", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("controller_name"), &_1, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_4, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "action_name");
	ZEPHIR_CALL_METHOD(&_1, &_4, "make", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("action_name"), &_1, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_5, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "theme");
	ZEPHIR_CALL_METHOD(&_1, &_5, "pathapplicationdir", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "option");
	ZEPHIR_CALL_METHOD(&_7, &_6, "make", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "view\\theme_name");
	ZEPHIR_CALL_METHOD(&_8, &_7, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_VSV(&_9, &_1, "/", &_8);
	zephir_array_update_string(&options, SL("theme_path"), &_9, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_10, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "theme");
	ZEPHIR_CALL_METHOD(&_11, &_10, "pathapplicationcache", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_12, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "app_name");
	ZEPHIR_CALL_METHOD(&_13, &_12, "make", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_9);
	ZEPHIR_CONCAT_VSV(&_9, &_11, "/", &_13);
	zephir_array_update_string(&options, SL("theme_cache_path"), &_9, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&options);

}

/**
 * 创建分析器回调
 *
 * @since 2018.01.12
 * @return void
 */
PHP_METHOD(Queryyetsimple_View_Manager, makeParserClosure) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "view.parser");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "make", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 twig 分析器回调
 *
 * @since 2018.01.15
 * @return void
 */
PHP_METHOD(Queryyetsimple_View_Manager, makeTwigParserClosure) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "view.twig.parser");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "make", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

