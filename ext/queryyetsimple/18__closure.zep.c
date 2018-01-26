
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


ZEPHIR_INIT_CLASS(queryyetsimple_18__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 18__closure, queryyetsimple, 18__closure, queryyetsimple_18__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_18__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, sessions, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&sessions);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sessions");
	ZEPHIR_CALL_METHOD(&sessions, project, "make", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&sessions, "connect", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

