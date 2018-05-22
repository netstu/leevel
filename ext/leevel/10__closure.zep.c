
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


ZEPHIR_INIT_CLASS(leevel_10__closure) {

	ZEPHIR_REGISTER_CLASS(leevel, 10__closure, leevel, 10__closure, leevel_10__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(leevel_10__closure, __invoke) {

	zend_class_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, option, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "option");
	ZEPHIR_CALL_METHOD(&option, project, "make", NULL, 0, &_0);
	zephir_check_call_status();
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("Leevel\\Encryption\\Encryption"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "auth_key");
		ZEPHIR_CALL_METHOD(&_2, &option, "get", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "auth_expiry");
		ZEPHIR_CALL_METHOD(&_3, &option, "get", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_2, &_3);
		zephir_check_call_status();
	}
	RETURN_MM();

}

