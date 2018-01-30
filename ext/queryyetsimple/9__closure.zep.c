
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
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(queryyetsimple_9__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 9__closure, queryyetsimple, 9__closure, queryyetsimple_9__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_9__closure, __invoke) {

	zval args, closures, obj, hash, container, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&closures);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	ZEPHIR_OBS_VAR(&container);
	zephir_array_fetch_long(&container, &args, 0, PH_NOISY, "queryyetsimple/di/container.zep", 168 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&closures);
	zephir_array_fetch_long(&closures, &args, 1, PH_NOISY, "queryyetsimple/di/container.zep", 169 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&hash, "spl_object_hash", NULL, 73, &closures);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&obj);
	zephir_read_static_property_ce(&_0, queryyetsimple_di_container_ce, SL("shareClosure"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&obj, &_0, &hash, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&obj);
	}
	ZEPHIR_CALL_FUNCTION(&obj, "call_user_func", NULL, 74, &closures, &container);
	zephir_check_call_status();
	zephir_update_static_property_array_multi_ce(queryyetsimple_di_container_ce, SL("shareClosure"), &obj TSRMLS_CC, SL("z"), 1, &hash);
	RETURN_CCTOR(&obj);

}

