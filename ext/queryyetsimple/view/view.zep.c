
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
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * view 仓储
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.10
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_View_View) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\View, View, queryyetsimple, view_view, queryyetsimple_view_view_method_entry, 0);

	/**
	 * 连接驱动
	 *
	 * @var \queryyetsimple\view\iconnect
	 */
	zend_declare_property_null(queryyetsimple_view_view_ce, SL("oConnect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(queryyetsimple_view_view_ce TSRMLS_CC, 1, queryyetsimple_view_iview_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \queryyetsimple\view\iconnect $oConnect
 * @return void
 */
PHP_METHOD(Queryyetsimple_View_View, __construct) {

	zval *oConnect, oConnect_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&oConnect_sub);

	zephir_fetch_params(0, 1, 0, &oConnect);



	zephir_update_property_zval(this_ptr, SL("oConnect"), oConnect);

}

/**
 * call 
 *
 * @param string $sMethod
 * @param array $arrArgs
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_View_View, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrArgs, _0;
	zval *sMethod_param = NULL, *arrArgs_param = NULL, _1;
	zval sMethod;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sMethod);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arrArgs);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sMethod_param, &arrArgs_param);

	zephir_get_strval(&sMethod, sMethod_param);
	zephir_get_arrval(&arrArgs, arrArgs_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("oConnect"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &sMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &arrArgs);
	zephir_check_call_status();
	RETURN_MM();

}

