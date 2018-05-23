
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"


/**
 * view 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.05.12
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_View_Provider_Register) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\View\\Provider, Register, leevel, view_provider_register, leevel_di_provider_ce, leevel_view_provider_register_method_entry, 0);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_View_Provider_Register, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_CALL_PARENT(NULL, leevel_view_provider_register_ce, getThis(), "__construct", &_0, 0, container);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册服务
 *
 * @return void
 */
PHP_METHOD(Leevel_View_Provider_Register, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "viewviews", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "viewview", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "viewcompiler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "viewparser", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "viewtwigparser", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Leevel_View_Provider_Register, providers) {

	zval _0;
	zval tmp, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\View\\Manager");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("view.views"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\View\\View");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\View\\IView");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("view.view"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\View\\Compiler");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\View\\ICompiler");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("view.compiler"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\View\\Parser");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\View\\IParser");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("view.parser"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "view.twig.parser");
	zephir_array_fast_append(&tmp, &_1);
	RETURN_CCTOR(&tmp);

}

/**
 * 注册 view.views 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_View_Provider_Register, viewViews) {

	zval _3;
	zend_class_entry *_2;
	zval _0, _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "viewViewsClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "view.views");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 view.views 闭包
 * 
 * @param \Leevel\Project\IProject $project
 * @return \Leevel\View\Manager
 */
PHP_METHOD(Leevel_View_Provider_Register, viewViewsClosure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	object_init_ex(return_value, leevel_view_manager_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 112, project);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 注册 view.view 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_View_Provider_Register, viewView) {

	zval _3;
	zend_class_entry *_2;
	zval _0, _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "viewViewClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "view.view");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 view.view 闭包
 * 
 * @param \Leevel\Project\IProject $project
 * @return object
 */
PHP_METHOD(Leevel_View_Provider_Register, viewViewClosure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "view.views");
	ZEPHIR_CALL_METHOD(&_0, project, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "connect", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 注册 view.compiler 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_View_Provider_Register, viewCompiler) {

	zval _3;
	zend_class_entry *_2;
	zval _0, _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "viewCompilerClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "view.compiler");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 view.compiler 闭包
 * 
 * @param \Leevel\Project\IProject $project
 * @return \Leevel\View\Compiler
 */
PHP_METHOD(Leevel_View_Provider_Register, viewCompilerClosure) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\View\\Compiler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 注册 view.parser 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_View_Provider_Register, viewParser) {

	zval _3;
	zend_class_entry *_2;
	zval _0, _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "viewParserClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "view.parser");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 view.parser 闭包
 * 
 * @param \Leevel\Project\IProject $project
 * @return \Leevel\View\Parser
 */
PHP_METHOD(Leevel_View_Provider_Register, viewParserClosure) {

	zend_class_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, _0, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_0);
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("Leevel\\View\\Parser"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_0, _1);
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "view.compiler");
		ZEPHIR_CALL_METHOD(&_2, project, "make", NULL, 0, &_3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_2);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_4, &_0, "registercompilers", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_4, "registerparsers", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 注册 view.twig.parser 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_View_Provider_Register, viewTwigParser) {

	zval _3;
	zend_class_entry *_2;
	zval _0, _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "viewTwigParserClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "view.twig.parser");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 view.twig.parser 闭包
 * 
 * @param \Leevel\Project\IProject $project
 * @return \Twig_Environment
 */
PHP_METHOD(Leevel_View_Provider_Register, viewTwigParserClosure) {

	zend_class_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, __$true, tmp, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&tmp, SL("auto_reload"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, project, "development", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("debug"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "theme");
	ZEPHIR_CALL_METHOD(&_0, project, "pathapplicationcache", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_2, project, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &_2, "app", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VSV(&_4, &_0, "/", &_3);
	zephir_array_update_string(&tmp, SL("cache"), &_4, PH_COPY | PH_SEPARATE);
	if (!_5) {
	_5 = zephir_fetch_class_str_ex(SL("Twig_Environment"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _5);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&_1);
		if (!_6) {
		_6 = zephir_fetch_class_str_ex(SL("Twig_Loader_Filesystem"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_1, _6);
		if (zephir_has_constructor(&_1 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1, &tmp);
		zephir_check_call_status();
	}
	RETURN_MM();

}

