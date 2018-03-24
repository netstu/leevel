
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


ZEPHIR_INIT_CLASS(queryyetsimple_13__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 13__closure, queryyetsimple, 13__closure, queryyetsimple_13__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_13__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, option, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&option);
	array_init(&option);
	ZEPHIR_CALL_METHOD(&option, project, "appoption", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, queryyetsimple_event_dispatch_ce);
	zephir_array_fetch_string(&_0, &option, SL("event_strict"), PH_NOISY | PH_READONLY, "queryyetsimple/event/provider/register.zep", 54 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 131, project, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

