
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


ZEPHIR_INIT_CLASS(queryyetsimple_11__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 11__closure, queryyetsimple, 11__closure, queryyetsimple_11__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_11__closure, __invoke) {

	zend_class_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, option, tmp, _0, _1, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "option");
	ZEPHIR_CALL_METHOD(&option, project, "make", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "view\\action_fail");
	ZEPHIR_CALL_METHOD(&_1, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("action_fail"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "view\\action_success");
	ZEPHIR_CALL_METHOD(&_1, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("action_success"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "default_response");
	ZEPHIR_CALL_METHOD(&_1, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("default_response"), &_1, PH_COPY | PH_SEPARATE);
	if (!_2) {
	_2 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Http\\Response"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _2);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "router");
		ZEPHIR_CALL_METHOD(&_1, project, "make", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "view");
		ZEPHIR_CALL_METHOD(&_3, project, "make", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "session");
		ZEPHIR_CALL_METHOD(&_4, project, "make", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "cookie");
		ZEPHIR_CALL_METHOD(&_5, project, "make", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1, &_3, &_4, &_5, &tmp);
		zephir_check_call_status();
	}
	RETURN_MM();

}

