
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
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * 国际化组件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.06
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_I18n_I18n) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\I18n, I18n, queryyetsimple, i18n_i18n, queryyetsimple_i18n_i18n_method_entry, 0);

	/**
	 * 当前语言上下文
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_i18n_i18n_ce, SL("sI18n"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 默认语言上下文
	 *
	 * @var string
	 */
	zend_declare_property_string(queryyetsimple_i18n_i18n_ce, SL("sDefault"), "zh-cn", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 语言数据
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_i18n_i18n_ce, SL("arrText"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_i18n_i18n_ce->create_object = zephir_init_properties_Queryyetsimple_I18n_I18n;

	zend_class_implements(queryyetsimple_i18n_i18n_ce TSRMLS_CC, 1, queryyetsimple_i18n_ii18n_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param string $sI18n
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_I18n, __construct) {

	zval *sI18n_param = NULL;
	zval sI18n;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sI18n);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sI18n_param);

	zephir_get_strval(&sI18n, sI18n_param);


	zephir_update_property_zval(this_ptr, SL("sI18n"), &sI18n);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取语言 text
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_I18n_I18n, getText) {

	zval arr, sI18n, _0, _1, _2, _3, _10, _4$$4, _5$$4, _6$$4, _7$$4, _8$$5, _9$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&sI18n);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&arr);
	zephir_get_args(&arr);
	zephir_array_fetch_long(&_0, &arr, 0, PH_NOISY | PH_READONLY, "queryyetsimple/i18n/i18n.zep", 78 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_CALL_METHOD(&sI18n, this_ptr, "geti18n", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("arrText"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &sI18n, PH_READONLY, "queryyetsimple/i18n/i18n.zep", 83 TSRMLS_CC);
	zephir_array_fetch_long(&_3, &arr, 0, PH_READONLY, "queryyetsimple/i18n/i18n.zep", 83 TSRMLS_CC);
	if (zephir_array_isset(&_2, &_3)) {
		zephir_read_property(&_4$$4, this_ptr, SL("arrText"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$4, &_4$$4, &sI18n, PH_NOISY | PH_READONLY, "queryyetsimple/i18n/i18n.zep", 84 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_7$$4);
		zephir_array_fetch_long(&_7$$4, &arr, 0, PH_NOISY, "queryyetsimple/i18n/i18n.zep", 84 TSRMLS_CC);
		zephir_array_fetch(&_6$$4, &_5$$4, &_7$$4, PH_NOISY | PH_READONLY, "queryyetsimple/i18n/i18n.zep", 84 TSRMLS_CC);
		zephir_array_update_long(&arr, 0, &_6$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	if (zephir_fast_count_int(&arr TSRMLS_CC) > 1) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "sprintf");
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_8$$5, &_9$$5, &arr);
		zephir_check_call_status();
		zephir_array_update_long(&arr, 0, &_8$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	zephir_array_fetch_long(&_10, &arr, 0, PH_NOISY | PH_READONLY, "queryyetsimple/i18n/i18n.zep", 91 TSRMLS_CC);
	RETURN_CTOR(&_10);

}

/**
 * 获取语言 text
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_I18n_I18n, __) {

	zval _0;
	zval arr, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&arr);
	zephir_get_args(&arr);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "getText");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func_arrray", NULL, 0, &_0, &arr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 添加语言包
 *
 * @param string $sI18n 语言名字
 * @param array $arrData 语言包数据
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_I18n, addText) {

	zval arrData;
	zval *sI18n_param = NULL, *arrData_param = NULL, _0, _1$$3, _2$$3, _3$$3;
	zval sI18n;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sI18n);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&arrData);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sI18n_param, &arrData_param);

	zephir_get_strval(&sI18n, sI18n_param);
	if (!arrData_param) {
		ZEPHIR_INIT_VAR(&arrData);
		array_init(&arrData);
	} else {
		zephir_get_arrval(&arrData, arrData_param);
	}


	zephir_read_property(&_0, this_ptr, SL("arrText"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &sI18n TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("arrText"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &sI18n, PH_NOISY | PH_READONLY, "queryyetsimple/i18n/i18n.zep", 116 TSRMLS_CC);
		zephir_fast_array_merge(&_1$$3, &_3$$3, &arrData TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("arrText"), &sI18n, &_1$$3 TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("arrText"), &sI18n, &arrData TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置当前语言包上下文环境
 *
 * @param string $sI18n
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_I18n, setI18n) {

	zval *sI18n_param = NULL;
	zval sI18n;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sI18n);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sI18n_param);

	zephir_get_strval(&sI18n, sI18n_param);


	zephir_update_property_zval(this_ptr, SL("sI18n"), &sI18n);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取当前语言包
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_I18n_I18n, getI18n) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sI18n");

}

/**
 * 设置默认语言包
 *
 * @param string $sI18nName
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_I18n, setDefault) {

	zval *sI18n_param = NULL;
	zval sI18n;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sI18n);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sI18n_param);

	zephir_get_strval(&sI18n, sI18n_param);


	zephir_update_property_zval(this_ptr, SL("sDefault"), &sI18n);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取默认语言包
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_I18n_I18n, getDefault) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "sDefault");

}

zend_object *zephir_init_properties_Queryyetsimple_I18n_I18n(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("arrText"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("arrText"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

