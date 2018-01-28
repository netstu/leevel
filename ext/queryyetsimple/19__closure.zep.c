
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
#include "kernel/array.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(queryyetsimple_19__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 19__closure, queryyetsimple, 19__closure, queryyetsimple_19__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_19__closure, __invoke) {

	zend_class_entry *_4 = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, option, options, item, tmp, _0, *_1, _5, _6, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "option");
	ZEPHIR_CALL_METHOD(&option, project, "make", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "url\\");
	ZEPHIR_CALL_METHOD(&options, &option, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "~apps~");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "default_app");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "default_controller");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "default_action");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "middleware_group");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "middleware_alias");
	zephir_array_fast_append(&tmp, &_0);
	zephir_is_iterable(&tmp, 0, "queryyetsimple/router/provider/register.zep", 71);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmp), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_METHOD(&_2$$3, &option, "get", &_3, 0, &item);
		zephir_check_call_status();
		zephir_array_update_zval(&options, &item, &_2$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	if (!_4) {
	_4 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Router\\Router"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _4);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "pipeline");
		ZEPHIR_CALL_METHOD(&_5, project, "make", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "request");
		ZEPHIR_CALL_METHOD(&_6, project, "make", NULL, 0, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, project, &_5, &_6, &options);
		zephir_check_call_status();
	}
	RETURN_MM();

}

