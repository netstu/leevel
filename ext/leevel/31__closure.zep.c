
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
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(leevel_31__closure) {

	ZEPHIR_REGISTER_CLASS(leevel, 31__closure, leevel, 31__closure, leevel_31__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(leevel_31__closure, __invoke) {

	zend_class_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, throttler, cache, _0, _1, _2, _3, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&throttler);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cache");
	ZEPHIR_CALL_METHOD(&_0, project, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&_2, project, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "throttler\\driver");
	ZEPHIR_CALL_METHOD(&_3, &_2, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&cache, &_0, "connect", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&throttler);
	if (!_4) {
	_4 = zephir_fetch_class_str_ex(SL("Leevel\\Throttler\\Throttler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&throttler, _4);
	if (zephir_has_constructor(&throttler TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &throttler, "__construct", NULL, 0, &cache);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_5, project, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &throttler, "setrequest", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_CCTOR(&throttler);

}

