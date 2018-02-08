
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(queryyetsimple_37__closure) {

	ZEPHIR_REGISTER_CLASS(queryyetsimple, 37__closure, queryyetsimple, 37__closure, queryyetsimple_37__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(queryyetsimple_37__closure, __invoke) {

	zend_class_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, __$true, tmp, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&tmp, SL("auto_reload"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, project, "development", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&tmp, SL("debug"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "theme");
	ZEPHIR_CALL_METHOD(&_0, project, "pathapplicationcache", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "app_name");
	ZEPHIR_CALL_METHOD(&_2, project, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VSV(&_3, &_0, "/", &_2);
	zephir_array_update_string(&tmp, SL("cache"), &_3, PH_COPY | PH_SEPARATE);
	if (!_4) {
	_4 = zephir_fetch_class_str_ex(SL("Twig_Environment"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _4);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(&_1);
		if (!_5) {
		_5 = zephir_fetch_class_str_ex(SL("Twig_Loader_Filesystem"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_1, _5);
		if (zephir_has_constructor(&_1 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1, &tmp);
		zephir_check_call_status();
	}
	RETURN_MM();

}

