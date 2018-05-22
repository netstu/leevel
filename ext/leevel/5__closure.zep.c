
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(leevel_5__closure) {

	ZEPHIR_REGISTER_CLASS(leevel, 5__closure, leevel, 5__closure, leevel_5__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(leevel_5__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, __$true, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (zephir_is_instance_of(value, SL("JsonSerializable") TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(value, "jsonserialize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else if (zephir_instance_of_ev(value, leevel_support_ijson_ce TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_0$$4, value, "tojson", NULL, 0);
		zephir_check_call_status();
		zephir_json_decode(return_value, &_0$$4, zephir_get_intval(&__$true) );
		RETURN_MM();
	} else if (zephir_instance_of_ev(value, leevel_support_iarray_ce TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(value, "toarray", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}

}

