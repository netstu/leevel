
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


ZEPHIR_INIT_CLASS(Queryyetsimple_Database2) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple, Database2, queryyetsimple, database2, queryyetsimple_database2_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Queryyetsimple_Database2, say) {

	zval *this_ptr = getThis();


	php_printf("%s", "database");

}

