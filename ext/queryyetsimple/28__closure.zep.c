
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
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(queryyetsimple_28__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 28__closure, queryyetsimple, 28__closure, queryyetsimple_28__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_28__closure, __invoke) {

	zend_class_entry *_4 = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, option, router, url, options, item, tmp, _0, *_1, _5, _6, _7, _8, _9, _10, _11, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&options);
	array_init(&options);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "option");
	ZEPHIR_CALL_METHOD(&option, project, "make", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "router");
	ZEPHIR_CALL_METHOD(&router, project, "make", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 7, 0 TSRMLS_CC);
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
	ZVAL_STRING(&_0, "model");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "html_suffix");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "router_domain_top");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "make_subdomain_on");
	zephir_array_fast_append(&tmp, &_0);
	zephir_is_iterable(&tmp, 0, "queryyetsimple/router/provider/register.zep", 150);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmp), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_METHOD(&_2$$3, &option, "get", &_3, 0, &item);
		zephir_check_call_status();
		zephir_array_update_zval(&options, &item, &_2$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_VAR(&url);
	if (!_4) {
	_4 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Router\\Url"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&url, _4);
	if (zephir_has_constructor(&url TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &url, "__construct", NULL, 0, &options);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_6, &router, "app", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &url, "setapp", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, &router, "controller", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &_5, "setcontroller", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, &router, "action", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, &_7, "setaction", NULL, 0, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "url_enter");
	ZEPHIR_CALL_METHOD(&_11, project, "make", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_9, "seturlenter", NULL, 0, &_11);
	zephir_check_call_status();
	RETURN_CCTOR(&url);

}

