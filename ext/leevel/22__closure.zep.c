
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(leevel_22__closure) {

	ZEPHIR_REGISTER_CLASS(leevel, 22__closure, leevel, 22__closure, leevel_22__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(leevel_22__closure, __invoke) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, redirect, session, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&redirect);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&redirect);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\Router\\Redirect"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&redirect, _0);
	if (zephir_has_constructor(&redirect TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "url");
		ZEPHIR_CALL_METHOD(&_1, project, "make", NULL, 0, &_2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &redirect, "__construct", NULL, 0, &_1);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "session");
	ZEPHIR_CALL_METHOD(&session, project, "make", NULL, 0, &_2);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&session)) {
		ZEPHIR_CALL_METHOD(NULL, &redirect, "setsession", NULL, 0, &session);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&redirect);

}

