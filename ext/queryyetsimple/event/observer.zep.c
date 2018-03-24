
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"


/**
 * 观察者角色 observer
 * \SplObserver 无法识别 container
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.02.01
 * @link http://php.net/manual/zh/class.splobserver.php
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Event_Observer) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Event, Observer, queryyetsimple, event_observer, queryyetsimple_event_observer_method_entry, 0);

	/**
	 * 观察者目标角色 subject
	 *
	 * @var \SplSubject
	 */
	zend_declare_property_null(queryyetsimple_event_observer_ce, SL("subject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(queryyetsimple_event_observer_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("splobserver")));
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Event_Observer, __construct) {

	zval *this_ptr = getThis();



}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Event_Observer, update) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subject, subject_sub, method, tmp, tmp1, _4, _5, _0$$3, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subject_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tmp1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &subject);



	if ((zephir_method_exists_ex(this_ptr, SL("handle") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "handle");
	} else {
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_STRING(&method, "run");
	}
	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&tmp, this_ptr);
	zephir_array_fast_append(&tmp, &method);
	if (!(zephir_is_callable(&tmp TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_get_class(&_1$$3, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Observer %s must has run method");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 2, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "queryyetsimple/event/observer.zep", 62 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&tmp1);
	zephir_create_array(&tmp1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&tmp1, this_ptr);
	zephir_array_fast_append(&tmp1, &method);
	zephir_read_property(&_4, subject, SL("container"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, subject, SL("notifyArgs"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_4, "call", NULL, 0, &tmp1, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

