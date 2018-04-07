
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


ZEPHIR_INIT_CLASS(leevel_22__closure) {

	ZEPHIR_REGISTER_CLASS(leevel, 22__closure, leevel, 22__closure, leevel_22__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(leevel_22__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, leevel_option_option_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 134);
	zephir_check_call_status();
	RETURN_MM();

}

