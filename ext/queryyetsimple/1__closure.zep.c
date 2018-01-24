
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
#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(queryyetsimple_1__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 1__closure, queryyetsimple, 1__closure, queryyetsimple_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_1__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, args, closures, obj;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&closures);
	ZVAL_UNDEF(&obj);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	if (Z_TYPE_P(&obj) == IS_NULL) {
		ZEPHIR_INIT_VAR(&args);
		zephir_get_args(&args);
		ZEPHIR_OBS_VAR(&closures);
		zephir_array_fetch_long(&closures, &args, 1, PH_NOISY, "queryyetsimple/di/container.zep", 162 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&obj, "closures", NULL, 0, container);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&obj);

}

