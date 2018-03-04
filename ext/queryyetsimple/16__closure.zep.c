
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(queryyetsimple_16__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 16__closure, queryyetsimple, 16__closure, queryyetsimple_16__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_16__closure, __invoke) {

	zend_class_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, *_GET, *_POST, *_COOKIE, *_FILES, *_SERVER, option, tmp, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	if (!_SERVER) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_FILES, SL("_FILES"));
	if (!_FILES) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	if (!_COOKIE) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_POST, SL("_POST"));
	if (!_POST) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_GET, SL("_GET"));
	if (!_GET) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "option");
	ZEPHIR_CALL_METHOD(&option, project, "make", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "var_method");
	ZEPHIR_CALL_METHOD(&_1, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("var_method"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "var_ajax");
	ZEPHIR_CALL_METHOD(&_1, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("var_ajax"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "var_pjax");
	ZEPHIR_CALL_METHOD(&_1, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("var_pjax"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "html_suffix");
	ZEPHIR_CALL_METHOD(&_1, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("html_suffix"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "rewrite");
	ZEPHIR_CALL_METHOD(&_1, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("rewrite"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "public");
	ZEPHIR_CALL_METHOD(&_1, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("public"), &_1, PH_COPY | PH_SEPARATE);
	if (!_2) {
	_2 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Http\\Request"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&_0);
		array_init(&_0);
		ZVAL_NULL(&_3);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _GET, _POST, &_0, _COOKIE, _FILES, _SERVER, &_3, &tmp);
		zephir_check_call_status();
	}
	RETURN_MM();

}

