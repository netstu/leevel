
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


ZEPHIR_INIT_CLASS(leevel_36__closure) {

	ZEPHIR_REGISTER_CLASS(leevel, 36__closure, leevel, 36__closure, leevel_36__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(leevel_36__closure, __invoke) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, parser, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&parser);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&parser);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\View\\Parser"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&parser, _0);
	if (zephir_has_constructor(&parser TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "view.compiler");
		ZEPHIR_CALL_METHOD(&_1, project, "make", NULL, 0, &_2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &parser, "__construct", NULL, 0, &_1);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_3, &parser, "registercompilers", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_3, "registerparsers", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

