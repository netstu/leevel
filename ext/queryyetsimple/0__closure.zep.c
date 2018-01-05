
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
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(queryyetsimple_0__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 0__closure, queryyetsimple, 0__closure, queryyetsimple_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_0__closure, __invoke) {

	zval _1;
	zval _0, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "traverseGenerator");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_args(&_2);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

