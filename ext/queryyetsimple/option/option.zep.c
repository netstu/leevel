
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * 配置管理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Option_Option) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Option, Option, queryyetsimple, option_option, queryyetsimple_option_option_method_entry, 0);

	/**
	 * 配置数据
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_option_option_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_option_option_ce->create_object = zephir_init_properties_Queryyetsimple_Option_Option;
	/**
	 * 默认命名空间
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_option_option_ce, SL("DEFAUTL_NAMESPACE"), "app");

	zend_class_implements(queryyetsimple_option_option_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(queryyetsimple_option_option_ce TSRMLS_CC, 1, queryyetsimple_option_ioption_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array $options
 * @return void
 */
PHP_METHOD(Queryyetsimple_Option_Option, __construct) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, SL("option"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * 是否存在配置
 *
 * @param string $sName 配置键值
 * @return string
 */
PHP_METHOD(Queryyetsimple_Option_Option, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL, sTempName, arrName, strNamespace, arrParts, sPart, option, _1, _2, _5, _6, *_7, _0$$3, _3$$4, _4$$4, _8$$5;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&sTempName);
	ZVAL_UNDEF(&arrName);
	ZVAL_UNDEF(&strNamespace);
	ZVAL_UNDEF(&arrParts);
	ZVAL_UNDEF(&sPart);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sName_param);

	if (!sName_param) {
		ZEPHIR_INIT_VAR(&sName);
		ZVAL_STRING(&sName, "app\\");
	} else {
		zephir_get_strval(&sName, sName_param);
	}


	ZEPHIR_CALL_METHOD(&arrName, this_ptr, "parsenamespace", NULL, 0, &sName);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&strNamespace);
	zephir_array_fetch_long(&strNamespace, &arrName, 0, PH_NOISY, "queryyetsimple/option/option.zep", 71 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&sTempName);
	zephir_array_fetch_long(&sTempName, &arrName, 1, PH_NOISY, "queryyetsimple/option/option.zep", 72 TSRMLS_CC);
	zephir_get_strval(&sName, &sTempName);
	if (ZEPHIR_IS_STRING(&sName, "*")) {
		zephir_read_property(&_0$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(zephir_array_isset(&_0$$3, &strNamespace));
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ".");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, &sName, &_1, 0 );
	if (!(zephir_is_true(&_2))) {
		zephir_read_property(&_3$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$4, &_3$$4, &strNamespace, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 80 TSRMLS_CC);
		RETURN_MM_BOOL(zephir_array_key_exists(&_4$$4, &sName TSRMLS_CC));
	}
	ZEPHIR_INIT_VAR(&arrParts);
	zephir_fast_explode_str(&arrParts, SL("."), &sName, LONG_MAX TSRMLS_CC);
	zephir_read_property(&_5, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &strNamespace, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 84 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&option, &_6);
	zephir_is_iterable(&arrParts, 0, "queryyetsimple/option/option.zep", 91);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrParts), _7)
	{
		ZEPHIR_INIT_NVAR(&sPart);
		ZVAL_COPY(&sPart, _7);
		if (!(zephir_array_isset(&option, &sPart))) {
			RETURN_MM_BOOL(0);
		}
		zephir_array_fetch(&_8$$5, &option, &sPart, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 89 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&option, &_8$$5);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&sPart);
	RETURN_MM_BOOL(1);

}

/**
 * 获取配置
 *
 * @param string $sName 配置键值
 * @param mixed $mixDefault 配置默认值
 * @return string
 */
PHP_METHOD(Queryyetsimple_Option_Option, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sName_param = NULL, *mixDefault = NULL, mixDefault_sub, __$null, sTempName, arrName, strNamespace, arrParts, sPart, option, _2, _3, _9, _10, *_11, _0$$3, _1$$3, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _12$$5;
	zval sName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&mixDefault_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sTempName);
	ZVAL_UNDEF(&arrName);
	ZVAL_UNDEF(&strNamespace);
	ZVAL_UNDEF(&arrParts);
	ZVAL_UNDEF(&sPart);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &sName_param, &mixDefault);

	if (!sName_param) {
		ZEPHIR_INIT_VAR(&sName);
		ZVAL_STRING(&sName, "app\\");
	} else {
		zephir_get_strval(&sName, sName_param);
	}
	if (!mixDefault) {
		mixDefault = &mixDefault_sub;
		mixDefault = &__$null;
	}


	ZEPHIR_CALL_METHOD(&arrName, this_ptr, "parsenamespace", NULL, 0, &sName);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&strNamespace);
	zephir_array_fetch_long(&strNamespace, &arrName, 0, PH_NOISY, "queryyetsimple/option/option.zep", 106 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&sTempName);
	zephir_array_fetch_long(&sTempName, &arrName, 1, PH_NOISY, "queryyetsimple/option/option.zep", 107 TSRMLS_CC);
	zephir_get_strval(&sName, &sTempName);
	if (ZEPHIR_IS_STRING(&sName, "*")) {
		zephir_read_property(&_0$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_1$$3, &_0$$3, &strNamespace, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 111 TSRMLS_CC);
		RETURN_CTOR(&_1$$3);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ".");
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_strpos(&_3, &sName, &_2, 0 );
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_read_property(&_5$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6$$4, &_5$$4, &strNamespace, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 115 TSRMLS_CC);
		if (zephir_array_key_exists(&_6$$4, &sName TSRMLS_CC)) {
			zephir_read_property(&_7$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$4, &_7$$4, &strNamespace, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 115 TSRMLS_CC);
			zephir_array_fetch(&_4$$4, &_8$$4, &sName, PH_NOISY, "queryyetsimple/option/option.zep", 115 TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&_4$$4, mixDefault);
		}
		RETURN_CCTOR(&_4$$4);
	}
	ZEPHIR_INIT_VAR(&arrParts);
	zephir_fast_explode_str(&arrParts, SL("."), &sName, LONG_MAX TSRMLS_CC);
	zephir_read_property(&_9, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_10, &_9, &strNamespace, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 119 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&option, &_10);
	zephir_is_iterable(&arrParts, 0, "queryyetsimple/option/option.zep", 126);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrParts), _11)
	{
		ZEPHIR_INIT_NVAR(&sPart);
		ZVAL_COPY(&sPart, _11);
		if (!(zephir_array_isset(&option, &sPart))) {
			RETVAL_ZVAL(mixDefault, 1, 0);
			RETURN_MM();
		}
		zephir_array_fetch(&_12$$5, &option, &sPart, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 124 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&option, &_12$$5);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&sPart);
	RETURN_CCTOR(&option);

}

/**
 * 返回所有配置
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Option_Option, all) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "option");

}

/**
 * 设置配置
 *
 * @param mixed $mixName 配置键值
 * @param mixed $mixValue 配置值
 * @return array
 */
PHP_METHOD(Queryyetsimple_Option_Option, set) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixName, mixName_sub, *mixValue = NULL, mixValue_sub, __$null, sTempName, sKey, mixValues, sName, arrName, strNamespace, arrParts, option, *_0$$3, _4$$5, _5$$5, _6$$8, _7$$8, _8$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixName_sub);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sTempName);
	ZVAL_UNDEF(&sKey);
	ZVAL_UNDEF(&mixValues);
	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&arrName);
	ZVAL_UNDEF(&strNamespace);
	ZVAL_UNDEF(&arrParts);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &mixName, &mixValue);

	if (!mixValue) {
		mixValue = &mixValue_sub;
		mixValue = &__$null;
	}


	if (Z_TYPE_P(mixName) == IS_ARRAY) {
		zephir_is_iterable(mixName, 0, "queryyetsimple/option/option.zep", 154);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(mixName), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&sKey);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&sKey, _2$$3);
			} else {
				ZVAL_LONG(&sKey, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&mixValues);
			ZVAL_COPY(&mixValues, _0$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 29, &sKey, &mixValues);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mixValues);
		ZEPHIR_INIT_NVAR(&sKey);
	} else {
		ZEPHIR_CALL_METHOD(&arrName, this_ptr, "parsenamespace", NULL, 0, mixName);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&strNamespace);
		zephir_array_fetch_long(&strNamespace, &arrName, 0, PH_NOISY, "queryyetsimple/option/option.zep", 156 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&sTempName);
		zephir_array_fetch_long(&sTempName, &arrName, 1, PH_NOISY, "queryyetsimple/option/option.zep", 157 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&sName, &sTempName);
		if (ZEPHIR_IS_STRING(&sName, "*")) {
			zephir_update_property_array(this_ptr, SL("option"), &strNamespace, mixValue TSRMLS_CC);
			RETURN_MM_NULL();
		}
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, ".");
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_fast_strpos(&_5$$5, &sName, &_4$$5, 0 );
		if (!(zephir_is_true(&_5$$5))) {
			zephir_update_property_array_multi(this_ptr, SL("option"), mixValue TSRMLS_CC, SL("zz"), 2, &strNamespace, mixName);
		} else {
			ZEPHIR_INIT_VAR(&arrParts);
			zephir_fast_explode_str(&arrParts, SL("."), &sName, LONG_MAX TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&option, this_ptr, "setrecursion", NULL, 0, &arrParts, mixValue);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_6$$8);
			zephir_read_property(&_7$$8, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$8, &_7$$8, &strNamespace, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 170 TSRMLS_CC);
			zephir_fast_array_merge(&_6$$8, &_8$$8, &option TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("option"), &strNamespace, &_6$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 删除配置
 *
 * @param string $sName 配置键值
 * @return string
 */
PHP_METHOD(Queryyetsimple_Option_Option, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sName, *sName_param = NULL, sTempName, arrName, strNamespace, arrParts, option, _1, _2, _0$$3, _3$$4, _4$$4, _5$$5, _6$$5, _7$$6, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sName);
	ZVAL_UNDEF(&sTempName);
	ZVAL_UNDEF(&arrName);
	ZVAL_UNDEF(&strNamespace);
	ZVAL_UNDEF(&arrParts);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sName_param);

	zephir_get_strval(&sName, sName_param);


	ZEPHIR_CALL_METHOD(&arrName, this_ptr, "parsenamespace", NULL, 0, &sName);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&strNamespace);
	zephir_array_fetch_long(&strNamespace, &arrName, 0, PH_NOISY, "queryyetsimple/option/option.zep", 186 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&sTempName);
	zephir_array_fetch_long(&sTempName, &arrName, 1, PH_NOISY, "queryyetsimple/option/option.zep", 187 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&sName, &sTempName);
	if (ZEPHIR_IS_STRING(&sName, "*")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_array(this_ptr, SL("option"), &strNamespace, &_0$$3 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ".");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, &sName, &_1, 0 );
	if (!(zephir_is_true(&_2))) {
		zephir_read_property(&_3$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$4, &_3$$4, &strNamespace, PH_READONLY, "queryyetsimple/option/option.zep", 196 TSRMLS_CC);
		if (zephir_array_isset(&_4$$4, &sName)) {
			zephir_read_property(&_5$$5, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_6$$5, &_5$$5, &strNamespace, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 197 TSRMLS_CC);
			zephir_array_unset(&_6$$5, &sName, PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_VAR(&arrParts);
		zephir_fast_explode_str(&arrParts, SL("."), &sName, LONG_MAX TSRMLS_CC);
		zephir_read_property(&_7$$6, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_8$$6, &_7$$6, &strNamespace, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 201 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&option, this_ptr, "deleterecursion", NULL, 0, &arrParts, &_8$$6);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("option"), &strNamespace, &option TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化配置参数
 *
 * @param mixed $mixNamespace
 * @return boolean
 */
PHP_METHOD(Queryyetsimple_Option_Option, reset) {

	zval *mixNamespace = NULL, mixNamespace_sub, __$null, _0$$4, _1$$5, _2$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixNamespace_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mixNamespace);

	if (!mixNamespace) {
		mixNamespace = &mixNamespace_sub;
		mixNamespace = &__$null;
	}


	if (Z_TYPE_P(mixNamespace) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("option"), mixNamespace);
	} else if (Z_TYPE_P(mixNamespace) == IS_STRING) {
		zephir_read_property(&_0$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_0$$4, mixNamespace)) {
			ZEPHIR_INIT_VAR(&_1$$5);
			array_init(&_1$$5);
			zephir_update_property_array(this_ptr, SL("option"), mixNamespace, &_1$$5 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(&_2$$6);
		array_init(&_2$$6);
		zephir_update_property_zval(this_ptr, SL("option"), &_2$$6);
	}
	RETURN_MM_BOOL(1);

}

/**
 * 判断配置是否存在
 *
 * @param string $strName
 * @return bool
 */
PHP_METHOD(Queryyetsimple_Option_Option, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strName_param = NULL;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strName_param);

	zephir_get_strval(&strName, strName_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &strName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取配置
 *
 * @param string $strName
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Option_Option, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strName_param = NULL;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strName_param);

	zephir_get_strval(&strName, strName_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &strName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置配置
 *
 * @param string $strName
 * @param mixed $mixValue
 * @return void
 */
PHP_METHOD(Queryyetsimple_Option_Option, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strName_param = NULL, *mixValue, mixValue_sub;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&mixValue_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &strName_param, &mixValue);

	zephir_get_strval(&strName, strName_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &strName, mixValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除配置
 *
 * @param string $strName
 * @return void
 */
PHP_METHOD(Queryyetsimple_Option_Option, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strName_param = NULL;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strName_param);

	zephir_get_strval(&strName, strName_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, &strName);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 递归设置配置数据
 *
 * @param array $arrPart
 * @param mixed $mixValue
 * @return array
 */
PHP_METHOD(Queryyetsimple_Option_Option, setRecursion) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrPart_param = NULL, *mixValue = NULL, mixValue_sub, __$null, arrResult, sItem, _0$$3, _1$$4;
	zval arrPart;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrPart);
	ZVAL_UNDEF(&mixValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&arrResult);
	ZVAL_UNDEF(&sItem);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &arrPart_param, &mixValue);

	ZEPHIR_OBS_COPY_OR_DUP(&arrPart, arrPart_param);
	if (!mixValue) {
		mixValue = &mixValue_sub;
		mixValue = &__$null;
	}


	ZEPHIR_INIT_VAR(&arrResult);
	array_init(&arrResult);
	ZEPHIR_MAKE_REF(&arrPart);
	ZEPHIR_CALL_FUNCTION(&sItem, "array_shift", NULL, 4, &arrPart);
	ZEPHIR_UNREF(&arrPart);
	zephir_check_call_status();
	if (!(zephir_array_isset(&arrResult, &sItem))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_array_update_zval(&arrResult, &sItem, &_0$$3, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(&arrPart))) {
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "setrecursion", NULL, 30, &arrPart, mixValue);
		zephir_check_call_status();
		zephir_array_update_zval(&arrResult, &sItem, &_1$$4, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_zval(&arrResult, &sItem, mixValue, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&arrResult);

}

/**
 * 递归删除配置数据
 *
 * @param array $arrPart
 * @return array
 */
PHP_METHOD(Queryyetsimple_Option_Option, deleteRecursion) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrPart_param = NULL, *arrResult_param = NULL, sItem, _0$$4, _1$$4;
	zval arrPart, arrResult;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrPart);
	ZVAL_UNDEF(&arrResult);
	ZVAL_UNDEF(&sItem);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &arrPart_param, &arrResult_param);

	ZEPHIR_OBS_COPY_OR_DUP(&arrPart, arrPart_param);
	ZEPHIR_OBS_COPY_OR_DUP(&arrResult, arrResult_param);


	ZEPHIR_MAKE_REF(&arrPart);
	ZEPHIR_CALL_FUNCTION(&sItem, "array_shift", NULL, 4, &arrPart);
	ZEPHIR_UNREF(&arrPart);
	zephir_check_call_status();
	if (!(zephir_array_isset(&arrResult, &sItem))) {
		RETURN_CTOR(&arrResult);
	}
	if (!(ZEPHIR_IS_EMPTY(&arrPart))) {
		zephir_array_fetch(&_1$$4, &arrResult, &sItem, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 313 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "deleterecursion", NULL, 31, &arrPart, &_1$$4);
		zephir_check_call_status();
		zephir_array_update_zval(&arrResult, &sItem, &_0$$4, PH_COPY | PH_SEPARATE);
	} else {
		if (zephir_array_isset(&arrResult, &sItem)) {
			zephir_array_unset(&arrResult, &sItem, PH_SEPARATE);
		}
	}
	RETURN_CTOR(&arrResult);

}

/**
 * 分析命名空间
 *
 * @param string $strName
 * @return array
 */
PHP_METHOD(Queryyetsimple_Option_Option, parseNamespace) {

	zval *strName_param = NULL, arrName, sTempName, strNamespace, _0, _1, _4, _2$$3, _3$$4, _5$$6;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&arrName);
	ZVAL_UNDEF(&sTempName);
	ZVAL_UNDEF(&strNamespace);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strName_param);

	zephir_get_strval(&strName, strName_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &strName, &_0, 0 );
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&arrName);
		zephir_fast_explode_str(&arrName, SL("\\"), &strName, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_2$$3, &arrName, 1, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 335 TSRMLS_CC);
		if (ZEPHIR_IS_EMPTY(&_2$$3)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "*");
			zephir_array_update_long(&arrName, 1, &_3$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		zephir_array_fetch_long(&sTempName, &arrName, 1, PH_NOISY | PH_READONLY, "queryyetsimple/option/option.zep", 338 TSRMLS_CC);
		zephir_get_strval(&strName, &sTempName);
		ZEPHIR_OBS_VAR(&strNamespace);
		zephir_array_fetch_long(&strNamespace, &arrName, 0, PH_NOISY, "queryyetsimple/option/option.zep", 340 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&strNamespace);
		ZVAL_STRING(&strNamespace, "app");
	}
	zephir_read_property(&_4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_4, &strNamespace))) {
		ZEPHIR_INIT_VAR(&_5$$6);
		array_init(&_5$$6);
		zephir_update_property_array(this_ptr, SL("option"), &strNamespace, &_5$$6 TSRMLS_CC);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &strNamespace);
	zephir_array_fast_append(return_value, &strName);
	RETURN_MM();

}

zend_object *zephir_init_properties_Queryyetsimple_Option_Option(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

