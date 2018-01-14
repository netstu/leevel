
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
#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * 管道实现类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.05
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Pipeline_Pipeline) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Pipeline, Pipeline, queryyetsimple, pipeline_pipeline, queryyetsimple_pipeline_pipeline_method_entry, 0);

	/**
	 * 容器
	 *
	 * @var \queryyetsimple\support\icontainer
	 */
	zend_declare_property_null(queryyetsimple_pipeline_pipeline_ce, SL("objContainer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 管道传递的对象
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_pipeline_pipeline_ce, SL("arrPassed"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 管道中所有执行工序
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_pipeline_pipeline_ce, SL("arrStage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 迭代器
	 *
	 * @var \queryyetsimple\support\collection
	 */
	zend_declare_property_null(queryyetsimple_pipeline_pipeline_ce, SL("objGenerator"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_pipeline_pipeline_ce->create_object = zephir_init_properties_Queryyetsimple_Pipeline_Pipeline;

	zend_class_implements(queryyetsimple_pipeline_pipeline_ce TSRMLS_CC, 1, queryyetsimple_pipeline_ipipeline_ce);
	return SUCCESS;

}

/**
 * 创建一个管道
 *
 * @param \queryyetsimple\support\icontainer $objContainer
 * @return void
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, __construct) {

	zval *objContainer, objContainer_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objContainer_sub);

	zephir_fetch_params(0, 1, 0, &objContainer);



	zephir_update_property_zval(this_ptr, SL("objContainer"), objContainer);

}

/**
 * 管道初始化
 *
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, reset) {

	zval __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("arrPassed"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("arrStage"), &_1);
	zephir_update_property_zval(this_ptr, SL("objGenerator"), &__$null);
	RETURN_THIS();

}

/**
 * 将传输对象传入管道
 *
 * @param mixed $mixPassed
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, send) {

	zval *mixPassed = NULL, mixPassed_sub, mixItem, _0, *_1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixPassed_sub);
	ZVAL_UNDEF(&mixItem);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixPassed);

	ZEPHIR_SEPARATE_PARAM(mixPassed);


	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(mixPassed) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, mixPassed);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_get_args(&_0);
	}
	ZEPHIR_CPY_WRT(mixPassed, &_0);
	zephir_is_iterable(mixPassed, 0, "queryyetsimple/pipeline/pipeline.zep", 107);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(mixPassed), _1)
	{
		ZEPHIR_INIT_NVAR(&mixItem);
		ZVAL_COPY(&mixItem, _1);
		zephir_update_property_array_append(this_ptr, SL("arrPassed"), &mixItem TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&mixItem);
	RETURN_THIS();

}

/**
 * 设置管道中的执行工序
 *
 * @param dynamic|array $mixStage
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, through) {

	zval *mixStage = NULL, mixStage_sub, mixItem, _0, *_1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixStage_sub);
	ZVAL_UNDEF(&mixItem);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixStage);

	ZEPHIR_SEPARATE_PARAM(mixStage);


	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(mixStage) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&_0, mixStage);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_get_args(&_0);
	}
	ZEPHIR_CPY_WRT(mixStage, &_0);
	zephir_is_iterable(mixStage, 0, "queryyetsimple/pipeline/pipeline.zep", 125);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(mixStage), _1)
	{
		ZEPHIR_INIT_NVAR(&mixItem);
		ZVAL_COPY(&mixItem, _1);
		zephir_update_property_array_append(this_ptr, SL("arrStage"), &mixItem TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&mixItem);
	RETURN_THIS();

}

/**
 * 执行管道工序响应结果
 *
 * @param callable $calEnd
 * @since 2018.01.03
 * @return void
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, then) {

	zval _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *calEnd = NULL, calEnd_sub, __$null, arrStage, _0, _1, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&calEnd_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&arrStage);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &calEnd);

	if (!calEnd) {
		calEnd = &calEnd_sub;
		calEnd = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("arrStage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&arrStage, &_0);
	if (zephir_is_true(calEnd)) {
		if (!(zephir_is_callable(calEnd TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Pipeline then must be a callable.", "queryyetsimple/pipeline/pipeline.zep", 142);
			return;
		}
		zephir_array_append(&arrStage, calEnd, PH_SEPARATE, "queryyetsimple/pipeline/pipeline.zep", 144);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "stagegenerator", NULL, 0, &arrStage);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("objGenerator"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "traverseGenerator");
	zephir_array_fast_append(&_3, &_4);
	zephir_read_property(&_0, this_ptr, SL("arrPassed"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_2, &_3, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 遍历迭代器
 *
 * @since 2018.01.03
 * @return void
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, traverseGenerator) {

	zval _9;
	zend_class_entry *_8;
	zend_bool _2, _5;
	zval aArgs, calCurrent, calNext, _0, _1, _3, _4, _6, _7, _10, _11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&aArgs);
	ZVAL_UNDEF(&calCurrent);
	ZVAL_UNDEF(&calNext);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("objGenerator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "valid", NULL, 0);
	zephir_check_call_status();
	_2 = !zephir_is_true(&_1);
	if (!(_2)) {
		zephir_read_property(&_3, this_ptr, SL("objGenerator"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4, &_3, "next", NULL, 0);
		zephir_check_call_status();
		_2 = zephir_is_true(&_4);
	}
	_5 = _2;
	if (!(_5)) {
		zephir_read_property(&_6, this_ptr, SL("objGenerator"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7, &_6, "valid", NULL, 0);
		zephir_check_call_status();
		_5 = !zephir_is_true(&_7);
	}
	if (_5) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&aArgs);
	zephir_get_args(&aArgs);
	_8 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_9, this_ptr);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "makeNextClosure");
	zephir_array_fast_append(&_9, &_10);
	ZEPHIR_CALL_CE_STATIC(&calNext, _8, "fromcallable", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&aArgs);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 32, &aArgs, &calNext);
	ZEPHIR_UNREF(&aArgs);
	zephir_check_call_status();
	zephir_read_property(&_11, this_ptr, SL("objGenerator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&calCurrent, &_11, "current", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_10);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_10, &calCurrent, &aArgs);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 下一次迭代执行回调
 *
 * @since 2018.01.12
 * @return void
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, makeNextClosure) {

	zval _1;
	zval _0, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "traverseGenerator");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_args(&_2);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 工序迭代器
 * 添加一个空的迭代器，第一次迭代 next 自动移除
 * zephir 不支持 yield，用集合替代
 *
 * @param array $arrStage
 * @return \queryyetsimple\support\collection
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, stageGenerator) {

	zend_class_entry *_4 = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrStage_param = NULL, mixStage, _0, *_1, _2$$3;
	zval arrStage, arrTemp;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrStage);
	ZVAL_UNDEF(&arrTemp);
	ZVAL_UNDEF(&mixStage);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrStage_param);

	zephir_get_arrval(&arrStage, arrStage_param);


	ZEPHIR_INIT_VAR(&arrTemp);
	array_init(&arrTemp);
	ZVAL_NULL(&_0);
	ZEPHIR_MAKE_REF(&arrStage);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 32, &arrStage, &_0);
	ZEPHIR_UNREF(&arrStage);
	zephir_check_call_status();
	zephir_is_iterable(&arrStage, 0, "queryyetsimple/pipeline/pipeline.zep", 201);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arrStage), _1)
	{
		ZEPHIR_INIT_NVAR(&mixStage);
		ZVAL_COPY(&mixStage, _1);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "stagecallback", &_3, 0, &mixStage);
		zephir_check_call_status();
		zephir_array_append(&arrTemp, &_2$$3, PH_SEPARATE, "queryyetsimple/pipeline/pipeline.zep", 198);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&mixStage);
	if (!_4) {
	_4 = zephir_fetch_class_str_ex(SL("queryyetsimple\\support\\collection"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _4);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &arrTemp);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 工序回调
 *
 * @param mixed $mixStage
 * @return null|callable
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, stageCallback) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixStage, mixStage_sub, strStage, arrParams, strMethod, objStage, tempArray, _0$$5, _1$$5, _2$$5, _3$$8, _4$$8, _5$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixStage_sub);
	ZVAL_UNDEF(&strStage);
	ZVAL_UNDEF(&arrParams);
	ZVAL_UNDEF(&strMethod);
	ZVAL_UNDEF(&objStage);
	ZVAL_UNDEF(&tempArray);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixStage);



	if (Z_TYPE_P(mixStage) == IS_NULL) {
		RETURN_MM_NULL();
	}
	if (zephir_is_callable(mixStage TSRMLS_CC)) {
		RETVAL_ZVAL(mixStage, 1, 0);
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&tempArray, this_ptr, "parse", NULL, 0, mixStage);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&strStage);
		zephir_array_fetch_long(&strStage, &tempArray, 0, PH_NOISY, "queryyetsimple/pipeline/pipeline.zep", 222 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&arrParams);
		zephir_array_fetch_long(&arrParams, &tempArray, 1, PH_NOISY, "queryyetsimple/pipeline/pipeline.zep", 223 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$5);
		ZVAL_STRING(&_0$$5, "@");
		ZEPHIR_INIT_VAR(&_1$$5);
		zephir_fast_strpos(&_1$$5, &strStage, &_0$$5, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1$$5)) {
			ZEPHIR_INIT_NVAR(&tempArray);
			zephir_fast_explode_str(&tempArray, SL("@"), &strStage, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&strStage);
			zephir_array_fetch_long(&strStage, &tempArray, 0, PH_NOISY, "queryyetsimple/pipeline/pipeline.zep", 227 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&strMethod);
			zephir_array_fetch_long(&strMethod, &tempArray, 1, PH_NOISY, "queryyetsimple/pipeline/pipeline.zep", 228 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&strMethod);
			ZVAL_STRING(&strMethod, "handle");
		}
		zephir_read_property(&_2$$5, this_ptr, SL("objContainer"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&objStage, &_2$$5, "make", NULL, 0, &strStage);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&objStage)) {
			ZEPHIR_INIT_VAR(&_3$$8);
			object_init_ex(&_3$$8, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_4$$8);
			ZVAL_STRING(&_4$$8, "Stage %s is not valid.");
			ZEPHIR_CALL_FUNCTION(&_5$$8, "sprintf", NULL, 1, &_4$$8, &strStage);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_3$$8, "__construct", NULL, 17, &_5$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$8, "queryyetsimple/pipeline/pipeline.zep", 235 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, &objStage);
		zephir_array_fast_append(return_value, &strMethod);
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 解析工序
 *
 * @param string $strStage
 * @return array
 */
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, parse) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strStage_param = NULL, strName, arrArgs, tempArray, _0, _1, _2, _3$$3;
	zval strStage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strStage);
	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&arrArgs);
	ZVAL_UNDEF(&tempArray);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strStage_param);

	zephir_get_strval(&strStage, strStage_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL(":"), &strStage, 2  TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(&tempArray, "array_pad", NULL, 33, &_0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&strName);
	zephir_array_fetch_long(&strName, &tempArray, 0, PH_NOISY, "queryyetsimple/pipeline/pipeline.zep", 256 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&arrArgs);
	zephir_array_fetch_long(&arrArgs, &tempArray, 1, PH_NOISY, "queryyetsimple/pipeline/pipeline.zep", 257 TSRMLS_CC);
	if (Z_TYPE_P(&arrArgs) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_fast_explode_str(&_3$$3, SL(","), &arrArgs, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(&arrArgs, &_3$$3);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &strName);
	zephir_array_fast_append(return_value, &arrArgs);
	RETURN_MM();

}

zend_object *zephir_init_properties_Queryyetsimple_Pipeline_Pipeline(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("arrStage"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("arrStage"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("arrPassed"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("arrPassed"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

