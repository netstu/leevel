
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


ZEPHIR_INIT_CLASS(Queryyetsimple_Db) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple, Db, queryyetsimple, db, queryyetsimple_db_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Queryyetsimple_Db, say2) {

	zval *this_ptr = getThis();


	php_printf("%s", "hello world, m php ext!");

}

