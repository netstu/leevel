
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


ZEPHIR_INIT_CLASS(leevel_28__closure) {

	ZEPHIR_REGISTER_CLASS(leevel, 28__closure, leevel, 28__closure, leevel_28__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(leevel_28__closure, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	object_init_ex(return_value, leevel_view_manager_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 138, project);
	zephir_check_call_status();
	RETURN_MM();

}

