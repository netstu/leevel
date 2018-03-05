
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
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(queryyetsimple_28__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 28__closure, queryyetsimple, 28__closure, queryyetsimple_28__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_28__closure, __invoke) {

	zend_class_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, option, response, _0, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "option");
	ZEPHIR_CALL_METHOD(&option, project, "make", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&response);
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Router\\ResponseFactory"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&response, _1);
	if (zephir_has_constructor(&response TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "view");
		ZEPHIR_CALL_METHOD(&_2, project, "make", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "redirect");
		ZEPHIR_CALL_METHOD(&_3, project, "make", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &response, "__construct", NULL, 0, &_2, &_3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "view\\action_success");
	ZEPHIR_CALL_METHOD(&_5, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &response, "setviewsuccesstemplate", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "view\\action_fail");
	ZEPHIR_CALL_METHOD(&_6, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_4, "setviewfailtemplate", NULL, 0, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

