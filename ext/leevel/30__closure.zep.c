
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(leevel_30__closure) {

	ZEPHIR_REGISTER_CLASS(leevel, 30__closure, leevel, 30__closure, leevel_30__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(leevel_30__closure, __invoke) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\View\\Compiler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

