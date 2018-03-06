
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * 观察者目标角色 subject
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.06.23
 * @link http://php.net/manual/zh/class.splsubject.php
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Event_Subject) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Event, Subject, queryyetsimple, event_subject, queryyetsimple_event_subject_method_entry, 0);

	/**
	 * 容器
	 *
	 * @var \Queryyetsimple\Di\IContainer
	 */
	zend_declare_property_null(queryyetsimple_event_subject_ce, SL("container"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 观察者角色 observer
	 *
	 * @var \SplObjectStorage(\SplObserver)
	 */
	zend_declare_property_null(queryyetsimple_event_subject_ce, SL("observers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 通知附件参数
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_event_subject_ce, SL("notifyArgs"), ZEND_ACC_PUBLIC TSRMLS_CC);

	queryyetsimple_event_subject_ce->create_object = zephir_init_properties_Queryyetsimple_Event_Subject;

	zend_class_implements(queryyetsimple_event_subject_ce TSRMLS_CC, 1, queryyetsimple_event_isubject_ce);
	zend_class_implements(queryyetsimple_event_subject_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("splsubject")));
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Queryyetsimple\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Queryyetsimple_Event_Subject, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("observers"), &_0);
	zephir_update_property_zval(this_ptr, SL("container"), container);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Event_Subject, attach) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *observer, observer_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&observer_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &observer);



	zephir_read_property(&_0, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "attach", NULL, 0, observer);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Event_Subject, detach) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *observer, observer_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&observer_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &observer);



	zephir_read_property(&_0, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "detach", NULL, 0, observer);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Event_Subject, notify) {

	zval observer, _0, _1, *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&observer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_update_property_zval(this_ptr, SL("notifyArgs"), &_0);
	zephir_read_property(&_1, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "queryyetsimple/event/subject.zep", 100);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
	{
		ZEPHIR_INIT_NVAR(&observer);
		ZVAL_COPY(&observer, _2);
		ZEPHIR_CALL_METHOD(NULL, &observer, "update", NULL, 0, this_ptr);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&observer);
	ZEPHIR_MM_RESTORE();

}

/**
 * 添加一个观察者角色
 *
 * @param \SplObserver|string $observer
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Event_Subject, attachs) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *observer = NULL, observer_sub, _0$$3, _1$$3, _2$$4, _3$$4, _4$$4, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&observer_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &observer);

	ZEPHIR_SEPARATE_PARAM(observer);


	if (Z_TYPE_P(observer) == IS_STRING) {
		zephir_read_property(&_0$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$3, &_0$$3, "make", NULL, 0, observer);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(observer, &_1$$3);
		if (ZEPHIR_IS_FALSE_IDENTICAL(observer)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "Observer is invalid.");
			ZEPHIR_CALL_FUNCTION(&_4$$4, "sprintf", NULL, 1, &_3$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 26, &_4$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$4, "queryyetsimple/event/subject.zep", 114 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (zephir_is_instance_of(observer, SL("SplObserver") TSRMLS_CC)) {
		zephir_read_property(&_5$$5, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "attach", NULL, 0, observer);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid observer argument because it not instanceof SplObserver", "queryyetsimple/event/subject.zep", 121);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Queryyetsimple_Event_Subject(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("notifyArgs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("notifyArgs"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

