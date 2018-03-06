
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * 事件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.31
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Event_Dispatch) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Event, Dispatch, queryyetsimple, event_dispatch, queryyetsimple_event_dispatch_method_entry, 0);

	/**
	 * 项目容器
	 *
	 * @var \Queryyetsimple\Di\IContainer
	 */
	zend_declare_property_null(queryyetsimple_event_dispatch_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 注册的监听器
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_event_dispatch_ce, SL("listeners"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 通配符的监听器
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_event_dispatch_ce, SL("wildcards"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 通配符是否严格匹配
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(queryyetsimple_event_dispatch_ce, SL("strict"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_event_dispatch_ce->create_object = zephir_init_properties_Queryyetsimple_Event_Dispatch;

	zend_class_implements(queryyetsimple_event_dispatch_ce TSRMLS_CC, 1, queryyetsimple_event_idispatch_ce);
	return SUCCESS;

}

/**
 * 创建一个事件解析器
 *
 * @param \Queryyetsimple\Di\IContainer $container
 * @param bool $event
 * @return void
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, __construct) {

	zend_bool strict;
	zval *container, container_sub, *strict_param = NULL, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 1, &container, &strict_param);

	if (!strict_param) {
		strict = 0;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	zephir_update_property_zval(this_ptr, SL("container"), container);
	if (strict) {
		zephir_update_property_zval(this_ptr, SL("strict"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("strict"), &__$false);
	}

}

/**
 * 执行一个事件
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, run) {

	zval _10$$7;
	zval event, objects, listeners, items, params, _5, *_6, _0$$3, _1$$4, _2$$5, _3$$5, _4$$5, _7$$7, _9$$7, _11$$7;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&objects);
	ZVAL_UNDEF(&listeners);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_10$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_NVAR(&params);
	zephir_get_args(&params);
	ZEPHIR_MAKE_REF(&params);
	ZEPHIR_CALL_FUNCTION(&event, "array_shift", NULL, 6, &params);
	ZEPHIR_UNREF(&params);
	zephir_check_call_status();
	if (Z_TYPE_P(&event) == IS_OBJECT) {
		ZEPHIR_CPY_WRT(&objects, &event);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, &event, 0 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&event, &_0$$3);
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&objects, &_1$$4, "make", NULL, 0, &event);
		zephir_check_call_status();
		if (!(Z_TYPE_P(&objects) == IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, spl_ce_RuntimeException);
			ZEPHIR_INIT_VAR(&_3$$5);
			ZVAL_STRING(&_3$$5, "Event %s is invalid.");
			ZEPHIR_CALL_FUNCTION(&_4$$5, "sprintf", NULL, 1, &_3$$5, &event);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 2, &_4$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "queryyetsimple/event/dispatch.zep", 94 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_MAKE_REF(&params);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 55, &params, &objects);
	ZEPHIR_UNREF(&params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "haslisteners", NULL, 0, &event);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&listeners, this_ptr, "getlisteners", NULL, 0, &event);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&listeners);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 64, &listeners);
	ZEPHIR_UNREF(&listeners);
	zephir_check_call_status();
	zephir_is_iterable(&listeners, 0, "queryyetsimple/event/dispatch.zep", 111);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&listeners), _6)
	{
		ZEPHIR_INIT_NVAR(&items);
		ZVAL_COPY(&items, _6);
		ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "makesubject", &_8, 0, &items);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&items, &_7$$7);
		ZEPHIR_INIT_NVAR(&_9$$7);
		ZEPHIR_INIT_NVAR(&_10$$7);
		zephir_create_array(&_10$$7, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_10$$7, &items);
		ZEPHIR_INIT_NVAR(&_11$$7);
		ZVAL_STRING(&_11$$7, "notify");
		zephir_array_fast_append(&_10$$7, &_11$$7);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$7, &_10$$7, &params);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&items);
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册监听器
 *
 * @param string|array $event
 * @param mixed $listener
 * @param int $priority
 * @return void
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, listeners) {

	zend_long priority;
	zval *event = NULL, event_sub, *listener, listener_sub, *priority_param = NULL, item, temp, _0, *_1, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&listener_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event, &listener, &priority_param);

	ZEPHIR_SEPARATE_PARAM(event);
	if (!priority_param) {
		priority = 500;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(&temp);
	array_init(&temp);
	if (Z_TYPE_P(event) != IS_ARRAY) {
		zephir_array_append(&temp, event, PH_SEPARATE, "queryyetsimple/event/dispatch.zep", 126);
		ZEPHIR_CPY_WRT(event, &temp);
	}
	ZVAL_LONG(&_0, priority);
	priority = zephir_get_intval(&_0);
	zephir_is_iterable(event, 0, "queryyetsimple/event/dispatch.zep", 138);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(event), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "*");
		ZEPHIR_INIT_NVAR(&_3$$4);
		zephir_fast_strpos(&_3$$4, &item, &_2$$4, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_3$$4)) {
			zephir_update_property_array_multi(this_ptr, SL("wildcards"), listener TSRMLS_CC, SL("zla"), 3, &item, priority);
		} else {
			zephir_update_property_array_multi(this_ptr, SL("listeners"), listener TSRMLS_CC, SL("zla"), 3, &item, priority);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取一个事件监听器
 *
 * @param string $event
 * @return array
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, getListeners) {

	zend_string *_6, *_16$$5;
	zend_ulong _5, _15$$5;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event_param = NULL, listeners, key, item, priority, value, res, _0, _3, *_4, _1$$3, _2$$3, _7$$4, _8$$4, _10$$4, _11$$4, _12$$4, _13$$4, *_14$$5, _17$$7, _18$$6, _19$$6;
	zval event;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&listeners);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event_param);

	zephir_get_strval(&event, event_param);


	ZEPHIR_INIT_VAR(&listeners);
	array_init(&listeners);
	zephir_read_property(&_0, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &event)) {
		zephir_read_property(&_1$$3, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &event, PH_NOISY | PH_READONLY, "queryyetsimple/event/dispatch.zep", 153 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&listeners, &_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("wildcards"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_3, 0, "queryyetsimple/event/dispatch.zep", 172);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&key, _6);
		} else {
			ZVAL_LONG(&key, _5);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _4);
		zephir_read_property(&_8$$4, this_ptr, SL("strict"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "prepareregexforwildcard", &_9, 0, &key, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&key, &_7$$4);
		ZEPHIR_INIT_NVAR(&_10$$4);
		ZEPHIR_INIT_NVAR(&_11$$4);
		ZVAL_STRING(&_11$$4, "\\");
		ZEPHIR_INIT_NVAR(&_12$$4);
		ZVAL_STRING(&_12$$4, "\\\\");
		zephir_fast_str_replace(&_10$$4, &_11$$4, &_12$$4, &event TSRMLS_CC);
		zephir_get_strval(&event, &_10$$4);
		ZEPHIR_INIT_NVAR(&res);
		ZVAL_NULL(&res);
		ZEPHIR_INIT_NVAR(&_13$$4);
		zephir_preg_match(&_13$$4, &key, &event, &res, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_13$$4)) {
			zephir_is_iterable(&item, 0, "queryyetsimple/event/dispatch.zep", 169);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&item), _15$$5, _16$$5, _14$$5)
			{
				ZEPHIR_INIT_NVAR(&priority);
				if (_16$$5 != NULL) { 
					ZVAL_STR_COPY(&priority, _16$$5);
				} else {
					ZVAL_LONG(&priority, _15$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _14$$5);
				if (!(zephir_array_isset(&listeners, &priority))) {
					ZEPHIR_INIT_NVAR(&_17$$7);
					array_init(&_17$$7);
					zephir_array_update_zval(&listeners, &priority, &_17$$7, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_INIT_NVAR(&_18$$6);
				zephir_array_fetch(&_19$$6, &listeners, &priority, PH_NOISY | PH_READONLY, "queryyetsimple/event/dispatch.zep", 167 TSRMLS_CC);
				zephir_fast_array_merge(&_18$$6, &_19$$6, &value TSRMLS_CC);
				zephir_array_update_zval(&listeners, &priority, &_18$$6, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&priority);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&listeners);

}

/**
 * 判断事件监听器是否存在
 *
 * @param string $event
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, hasListeners) {

	zend_bool _1;
	zval *event_param = NULL, _0, _2;
	zval event;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event_param);

	zephir_get_strval(&event, event_param);


	zephir_read_property(&_0, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, &event);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, SL("wildcards"), PH_NOISY_CC | PH_READONLY);
		_1 = zephir_array_isset(&_2, &event);
	}
	RETURN_MM_BOOL(_1);

}

/**
 * 删除一个事件所有监听器
 *
 * @param string $event
 * @return void
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, deleteListeners) {

	zval *event_param = NULL, _0, _2, _1$$3, _3$$4;
	zval event;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event_param);

	zephir_get_strval(&event, event_param);


	zephir_read_property(&_0, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &event)) {
		zephir_read_property(&_1$$3, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &event, PH_SEPARATE);
	}
	zephir_read_property(&_2, this_ptr, SL("wildcards"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_2, &event)) {
		zephir_read_property(&_3$$4, this_ptr, SL("wildcards"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_3$$4, &event, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置是否严格匹配事件
 *
 * @param bool $event
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, strict) {

	zval *strict_param = NULL, __$true, __$false;
	zend_bool strict;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &strict_param);

	strict = zephir_get_boolval(strict_param);


	if (strict) {
		zephir_update_property_zval(this_ptr, SL("strict"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("strict"), &__$false);
	}
	RETURN_THISW();

}

/**
 * 创建监听器观察者角色主体
 *
 * @param string $listeners
 * @return \Queryyetsimple\Event\Subject
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, makeSubject) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *listeners_param = NULL, subject, item, _0, *_1;
	zval listeners;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&listeners);
	ZVAL_UNDEF(&subject);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &listeners_param);

	zephir_get_arrval(&listeners, listeners_param);


	ZEPHIR_INIT_VAR(&subject);
	object_init_ex(&subject, queryyetsimple_event_subject_ce);
	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &subject, "__construct", NULL, 65, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&listeners, 0, "queryyetsimple/event/dispatch.zep", 231);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&listeners), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_METHOD(NULL, &subject, "attachs", &_2, 66, &item);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&subject);

}

/**
 * 通配符正则
 *
 * @param string $strFoo
 * @param bool $strict
 * @return string
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, prepareRegexForWildcard) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool strict;
	zval *regex, regex_sub, *strict_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&regex_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &regex, &strict_param);

	if (!strict_param) {
		strict = 1;
	} else {
		strict = zephir_get_boolval(strict_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "*");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "6084fef57e91a6ecb13fff498f9275a7");
	zephir_fast_str_replace(&_2, &_3, &_4, regex TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "escaperegexcharacter", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "6084fef57e91a6ecb13fff498f9275a7");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "(\\S+)");
	zephir_fast_str_replace(&_0, &_5, &_6, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	if (strict) {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "$");
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "");
	}
	ZEPHIR_CONCAT_SVVS(return_value, "/^", &_0, &_7, "/");
	RETURN_MM();

}

/**
 * 转移正则表达式特殊字符
 *
 * @param string $txt
 * @return string
 */
PHP_METHOD(Queryyetsimple_Event_Dispatch, escapeRegexCharacter) {

	zval *txt_param = NULL, tmp, tmp1, _0;
	zval txt;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&txt);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tmp1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &txt_param);

	zephir_get_strval(&txt, txt_param);


	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 17, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "$");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "?");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "*");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, ".");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "!");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "-");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "+");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "(");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, ")");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "[");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "]");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, ",");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "{");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "}");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "|");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_VAR(&tmp1);
	zephir_create_array(&tmp1, 17, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\$");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\/");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\?");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\*");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\.");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\!");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\-");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\+");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\(");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\)");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\[");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\]");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\,");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\{");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\}");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\|");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "\\\\\\\\");
	zephir_array_fast_append(&tmp1, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_fast_str_replace(&_0, &tmp, &tmp1, &txt TSRMLS_CC);
	zephir_get_strval(&txt, &_0);
	RETURN_CTOR(&txt);

}

zend_object *zephir_init_properties_Queryyetsimple_Event_Dispatch(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("wildcards"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("wildcards"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("listeners"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

