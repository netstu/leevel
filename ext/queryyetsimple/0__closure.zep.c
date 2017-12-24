
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
#include "kernel/concat.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(queryyetsimple_0__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 0__closure, queryyetsimple, 0__closure, queryyetsimple_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_0__closure, __invoke) {

	zval *sPart, sPart_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sPart_sub);

	zephir_fetch_params(0, 1, 0, &sPart);



	ZEPHIR_CONCAT_SVS(return_value, "['", sPart, "']");
	return;

}

