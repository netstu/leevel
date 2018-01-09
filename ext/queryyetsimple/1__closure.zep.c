
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
#include "kernel/array.h"
#include "kernel/main.h"


ZEPHIR_INIT_CLASS(queryyetsimple_1__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 1__closure, queryyetsimple, 1__closure, queryyetsimple_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_1__closure, __invoke) {

	zval _1;
	zval thisPipeline, _0, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&thisPipeline);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "pipeline");
	ZEPHIR_CALL_FUNCTION(&thisPipeline, "app", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &thisPipeline);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "traverseGenerator");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_args(&_2);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

