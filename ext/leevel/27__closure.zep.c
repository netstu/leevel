
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


ZEPHIR_INIT_CLASS(leevel_27__closure) {

	ZEPHIR_REGISTER_CLASS(leevel, 27__closure, leevel, 27__closure, leevel_27__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(leevel_27__closure, __invoke) {

	zend_class_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_0);
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("Leevel\\Validate\\Validate"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_0, _1);
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(&_0, "container", NULL, 0, project);
	zephir_check_call_status();
	RETURN_MM();

}

