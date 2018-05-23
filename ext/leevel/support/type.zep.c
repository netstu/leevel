
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "Zend/zend_closures.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * 类型判断辅助函数
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.02.03
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Support_Type) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Support, Type, leevel, support_type, leevel_support_type_method_entry, 0);

	/**
	 * zephir 不支持动态 instanceof
	 * 
	 * @var boolean
	 */
	zend_declare_property_bool(leevel_support_type_ce, SL("zephirInstanceof"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * 验证 PHP 各种变量类型
 *
 * @param mixed $value 待验证的变量
 * @param string $type 变量类型
 * @return boolean
 */
PHP_METHOD(Leevel_Support_Type, vars) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type;
	zval *value, value_sub, *type_param = NULL, __$true, tmp, tmp1, _0, _1$$12, _2$$16, _3$$17, _4$$18, _5$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tmp1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$12);
	ZVAL_UNDEF(&_2$$16);
	ZVAL_UNDEF(&_3$$17);
	ZVAL_UNDEF(&_4$$18);
	ZVAL_UNDEF(&_5$$18);
	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &type_param);

	zephir_get_strval(&type, type_param);


	ZEPHIR_INIT_VAR(&tmp);
	array_init(&tmp);
	ZEPHIR_INIT_VAR(&tmp1);
	array_init(&tmp1);
	ZEPHIR_INIT_NVAR(&tmp);
	zephir_fast_explode_str(&tmp, SL(":"), &type, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_0, &tmp, 0, PH_NOISY | PH_READONLY, "leevel/support/type.zep", 52 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&type);
	zephir_fast_strtolower(&type, &_0);
	do {
		if (ZEPHIR_IS_STRING(&type, "str") || ZEPHIR_IS_STRING(&type, "string")) {
			RETURN_MM_BOOL(Z_TYPE_P(value) == IS_STRING);
		}
		if (ZEPHIR_IS_STRING(&type, "int") || ZEPHIR_IS_STRING(&type, "integer")) {
			RETURN_MM_BOOL(Z_TYPE_P(value) == IS_LONG);
		}
		if (ZEPHIR_IS_STRING(&type, "float") || ZEPHIR_IS_STRING(&type, "double")) {
			RETURN_MM_BOOL(Z_TYPE_P(value) == IS_DOUBLE);
		}
		if (ZEPHIR_IS_STRING(&type, "bool") || ZEPHIR_IS_STRING(&type, "boolean")) {
			RETURN_MM_BOOL(((Z_TYPE_P(value) == IS_TRUE || Z_TYPE_P(value) == IS_FALSE) == 1));
		}
		if (ZEPHIR_IS_STRING(&type, "num") || ZEPHIR_IS_STRING(&type, "numeric")) {
			RETURN_MM_BOOL(zephir_is_numeric(value));
		}
		if (ZEPHIR_IS_STRING(&type, "base") || ZEPHIR_IS_STRING(&type, "scalar")) {
			RETURN_MM_BOOL(zephir_is_scalar(value));
		}
		if (ZEPHIR_IS_STRING(&type, "handle") || ZEPHIR_IS_STRING(&type, "resource")) {
			RETURN_MM_BOOL(Z_TYPE_P(value) == IS_RESOURCE);
		}
		if (ZEPHIR_IS_STRING(&type, "closure")) {
			RETURN_MM_BOOL(zephir_instance_of_ev(value, zend_ce_closure TSRMLS_CC));
		}
		if (ZEPHIR_IS_STRING(&type, "arr") || ZEPHIR_IS_STRING(&type, "array")) {
			if (zephir_array_isset_long(&tmp, 1)) {
				zephir_array_fetch_long(&_1$$12, &tmp, 1, PH_NOISY | PH_READONLY, "leevel/support/type.zep", 99 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&tmp1);
				zephir_fast_explode_str(&tmp1, SL(","), &_1$$12, LONG_MAX TSRMLS_CC);
				ZEPHIR_RETURN_CALL_SELF("arr", NULL, 0, value, &tmp1);
				zephir_check_call_status();
				RETURN_MM();
			} else {
				RETURN_MM_BOOL(Z_TYPE_P(value) == IS_ARRAY);
			}
		}
		if (ZEPHIR_IS_STRING(&type, "object")) {
			RETURN_MM_BOOL(Z_TYPE_P(value) == IS_OBJECT);
		}
		if (ZEPHIR_IS_STRING(&type, "null")) {
			RETURN_MM_BOOL(Z_TYPE_P(value) == IS_NULL);
		}
		if (ZEPHIR_IS_STRING(&type, "callback")) {
			ZVAL_BOOL(&_2$$16, 0);
			ZEPHIR_RETURN_CALL_FUNCTION("is_callable", NULL, 129, value, &_2$$16);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_read_static_property_ce(&_3$$17, leevel_support_type_ce, SL("zephirInstanceof"), PH_NOISY_CC | PH_READONLY);
		if (!zephir_is_true(&_3$$17)) {
			ZEPHIR_INIT_VAR(&_4$$18);
			ZEPHIR_INIT_VAR(&_5$$18);
			ZVAL_STRING(&_5$$18, "if (! function_exists('zephir_instanceof')) {\n\t\t\t\t\t\tfunction zephir_instanceof($value, $type) {\n\t\t\t\t\t\t\treturn $value instanceof $type;\n\t\t\t\t\t\t}\n\t\t\t\t\t}");
			zephir_eval_php(&_5$$18, &_4$$18, "/data/codes/queryyetsimple/leevel/support/type.zep:120" TSRMLS_CC);
			zend_update_static_property(leevel_support_type_ce, ZEND_STRL("zephirInstanceof"), &__$true);
		}
		ZEPHIR_RETURN_CALL_FUNCTION("zephir_instanceof", NULL, 0, value, &type);
		zephir_check_call_status();
		RETURN_MM();
	} while(0);

	RETURN_MM_BOOL(0);

}

/**
 * 判断字符串是否为数字
 *
 * @param string $strSearch
 * @since bool
 */
PHP_METHOD(Leevel_Support_Type, num) {

	zval *value, value_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (zephir_is_numeric(value)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "'");
	zephir_fast_trim(&_2, value, &_3, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/[^\\d-.,]/");
	zephir_preg_match(&_1, &_4, &_2, &_0, 0, 0 , 0  TSRMLS_CC);
	RETURN_MM_BOOL(!zephir_is_true(&_1));

}

/**
 * 判断字符串是否为整数
 *
 * @param string $strSearch
 * @since bool
 */
PHP_METHOD(Leevel_Support_Type, ints) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_LONG) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 11, value);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_digit", NULL, 12, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 验证参数是否为指定的类型集合
 *
 * @param mixed $value
 * @param mixed $types
 * @return boolean
 */
PHP_METHOD(Leevel_Support_Type, these) {

	zend_bool _2;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *types, types_sub, tmp, item, tmps, _0, _1, _3, *_4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&types_sub);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&tmps);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &types);



	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "string");
	zephir_array_fast_append(&tmp, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "string");
	ZEPHIR_CALL_SELF(&_1, "vars", NULL, 0, types, &_0);
	zephir_check_call_status();
	_2 = !zephir_is_true(&_1);
	if (_2) {
		ZEPHIR_CALL_SELF(&_3, "arr", NULL, 0, types, &tmp);
		zephir_check_call_status();
		_2 = !zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The parameter must be string or an array of string elements.", "leevel/support/type.zep", 172);
		return;
	}
	if (Z_TYPE_P(types) == IS_STRING) {
		ZEPHIR_INIT_VAR(&tmps);
		zephir_create_array(&tmps, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&tmps, types);
	} else {
		ZEPHIR_CPY_WRT(&tmps, types);
	}
	zephir_is_iterable(&tmps, 0, "leevel/support/type.zep", 188);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmps), _4)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _4);
		ZEPHIR_CALL_SELF(&_5$$6, "vars", &_6, 0, value, &item);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$6)) {
			RETURN_MM_BOOL(1);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_MM_BOOL(0);

}

/**
 * 验证数组中的每一项格式化是否正确
 *
 * @param array $arr
 * @param array $types
 * @return boolean
 */
PHP_METHOD(Leevel_Support_Type, arr) {

	zend_bool ret = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *arr_param = NULL, *types_param = NULL, value, item, *_0, *_1$$4, _2$$5;
	zval arr, types;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arr_param, &types_param);

	zephir_get_arrval(&arr, arr_param);
	zephir_get_arrval(&types, types_param);


	if (!(Z_TYPE_P(&arr) == IS_ARRAY)) {
		RETURN_MM_BOOL(0);
	}
	zephir_is_iterable(&arr, 0, "leevel/support/type.zep", 223);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arr), _0)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ret = 0;
		zephir_is_iterable(&types, 0, "leevel/support/type.zep", 218);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&types), _1$$4)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1$$4);
			ZEPHIR_CALL_SELF(&_2$$5, "vars", &_3, 0, &value, &item);
			zephir_check_call_status();
			if (zephir_is_true(&_2$$5)) {
				ret = 1;
				break;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
		if (!(ret)) {
			RETURN_MM_BOOL(0);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	RETURN_MM_BOOL(1);

}

