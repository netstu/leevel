
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * manager 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Manager) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Support, Manager, queryyetsimple, support_manager, queryyetsimple_support_manager_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * IOC Container
	 *
	 * @var \queryyetsimple\support\icontainer
	 */
	zend_declare_property_null(queryyetsimple_support_manager_ce, SL("objContainer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 连接对象
	 *
	 * @var object[]
	 */
	zend_declare_property_null(queryyetsimple_support_manager_ce, SL("arrConnect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \queryyetsimple\support\icontainer $objContainer
 * @return void
 */
PHP_METHOD(Queryyetsimple_Support_Manager, __construct) {

	zval *objContainer, objContainer_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objContainer_sub);

	zephir_fetch_params(0, 1, 0, &objContainer);



	zephir_update_property_zval(this_ptr, SL("objContainer"), objContainer);

}

/**
 * 返回 IOC 容器
 *
 * @return \queryyetsimple\support\icontainer
 */
PHP_METHOD(Queryyetsimple_Support_Manager, container) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "objContainer");

}

/**
 * 连接 connect 并返回连接对象
 *
 * @param array|string|null $mixOption
 * @return object
 */
PHP_METHOD(Queryyetsimple_Support_Manager, connect) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixOption = NULL, mixOption_sub, __$null, strUnique, strDriver, arrTemp, _1, _4, _5, _6, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixOption_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&strUnique);
	ZVAL_UNDEF(&strDriver);
	ZVAL_UNDEF(&arrTemp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mixOption);

	if (!mixOption) {
		mixOption = &mixOption_sub;
		ZEPHIR_CPY_WRT(mixOption, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(mixOption);
	}


	ZEPHIR_CALL_METHOD(&arrTemp, this_ptr, "parseoptionandunique", NULL, 0, mixOption);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&arrTemp);
	ZEPHIR_CALL_FUNCTION(mixOption, "array_shift", &_0, 11, &arrTemp);
	ZEPHIR_UNREF(&arrTemp);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&arrTemp);
	ZEPHIR_CALL_FUNCTION(&strUnique, "array_shift", &_0, 11, &arrTemp);
	ZEPHIR_UNREF(&arrTemp);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("arrConnect"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &strUnique)) {
		zephir_read_property(&_2$$3, this_ptr, SL("arrConnect"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &strUnique, PH_NOISY | PH_READONLY, "queryyetsimple/support/manager.zep", 86 TSRMLS_CC);
		RETURN_CTOR(&_3$$3);
	}
	if (zephir_array_isset_string(mixOption, SL("driver"))) {
		ZEPHIR_OBS_VAR(&strDriver);
		zephir_array_fetch_string(&strDriver, mixOption, SL("driver"), PH_NOISY, "queryyetsimple/support/manager.zep", 89 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&strDriver, this_ptr, "getdefaultdriver", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "makeconnect", NULL, 0, &strDriver, mixOption);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("arrConnect"), &strUnique, &_4 TSRMLS_CC);
	zephir_read_property(&_5, this_ptr, SL("arrConnect"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &strUnique, PH_NOISY | PH_READONLY, "queryyetsimple/support/manager.zep", 93 TSRMLS_CC);
	RETURN_CTOR(&_6);

}

/**
 * 重新连接
 *
 * @param array|string $mixOption
 * @return object
 */
PHP_METHOD(Queryyetsimple_Support_Manager, reconnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixOption = NULL, mixOption_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixOption_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mixOption);

	if (!mixOption) {
		mixOption = &mixOption_sub;
		ZEPHIR_INIT_VAR(mixOption);
		array_init(mixOption);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", NULL, 0, mixOption);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "connect", NULL, 0, mixOption);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除连接
 *
 * @param array|string $mixOption
 * @return void
 */
PHP_METHOD(Queryyetsimple_Support_Manager, disconnect) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixOption = NULL, mixOption_sub, strUnique, arrTemp, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixOption_sub);
	ZVAL_UNDEF(&strUnique);
	ZVAL_UNDEF(&arrTemp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mixOption);

	if (!mixOption) {
		mixOption = &mixOption_sub;
		ZEPHIR_INIT_VAR(mixOption);
		array_init(mixOption);
	} else {
		ZEPHIR_SEPARATE_PARAM(mixOption);
	}


	ZEPHIR_CALL_METHOD(&arrTemp, this_ptr, "parseoptionandunique", NULL, 0, mixOption);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&arrTemp);
	ZEPHIR_CALL_FUNCTION(mixOption, "array_shift", &_0, 11, &arrTemp);
	ZEPHIR_UNREF(&arrTemp);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&arrTemp);
	ZEPHIR_CALL_FUNCTION(&strUnique, "array_shift", &_0, 11, &arrTemp);
	ZEPHIR_UNREF(&arrTemp);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("arrConnect"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &strUnique)) {
		zephir_read_property(&_2$$3, this_ptr, SL("arrConnect"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_2$$3, &strUnique, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 取回所有连接
 *
 * @return object[]
 */
PHP_METHOD(Queryyetsimple_Support_Manager, getConnects) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "arrConnect");

}

/**
 * 返回默认驱动
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Support_Manager, getDefaultDriver) {

	zval strDefault, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strDefault);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "default");
	ZEPHIR_CALL_METHOD(&strDefault, this_ptr, "getoptionname", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptionobject", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "get", NULL, 0, &strDefault);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置默认驱动
 *
 * @param string $strName
 * @return void
 */
PHP_METHOD(Queryyetsimple_Support_Manager, setDefaultDriver) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strName_param = NULL, strDefault, _0, _1;
	zval strName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strName);
	ZVAL_UNDEF(&strDefault);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strName_param);

	zephir_get_strval(&strName, strName_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "default");
	ZEPHIR_CALL_METHOD(&strDefault, this_ptr, "getoptionname", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptionobject", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &strDefault, &strName);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得配置命名空间
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionNamespace) {

}

/**
 * 创建连接对象
 *
 * @param object $objConnect
 * @return object
 */
PHP_METHOD(Queryyetsimple_Support_Manager, createConnect) {

}

/**
 * 取得连接名字
 *
 * @param string $strOptionName
 * @return string
 */
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strOptionName_param = NULL, _0;
	zval strOptionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strOptionName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &strOptionName_param);

	if (!strOptionName_param) {
		ZEPHIR_INIT_VAR(&strOptionName);
		ZVAL_STRING(&strOptionName, "");
	} else {
		zephir_get_strval(&strOptionName, strOptionName_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptionnamespace", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_0, "\\", &strOptionName);
	RETURN_MM();

}

/**
 * 创建连接
 *
 * @param string $strConnect
 * @param array $arrOption
 * @return object
 */
PHP_METHOD(Queryyetsimple_Support_Manager, makeConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval *strConnect_param = NULL, *arrOption_param = NULL, strTemp, _1, _2, _6, _3$$3, _4$$3, _5$$3;
	zval strConnect, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strConnect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&strTemp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strConnect_param, &arrOption_param);

	zephir_get_strval(&strConnect, strConnect_param);
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "connect.", &strConnect);
	ZEPHIR_CALL_METHOD(&strTemp, this_ptr, "getoptionname", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptionobject", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &strTemp);
	zephir_check_call_status();
	if (Z_TYPE_P(&_2) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Connect driver %s not exits");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", NULL, 1, &_4$$3, &strConnect);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 12, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "queryyetsimple/support/manager.zep", 200 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "createconnectcommon", NULL, 0, &strConnect, &arrOption);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "createconnect", NULL, 0, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建连接对象公共入口
 *
 * @param string $strConnect
 * @param array $arrOption
 * @return object
 */
PHP_METHOD(Queryyetsimple_Support_Manager, createConnectCommon) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrOption;
	zval strConnect, *strConnect_param = NULL, *arrOption_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strConnect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strConnect_param, &arrOption_param);

	zephir_get_strval(&strConnect, strConnect_param);
	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "ucwords", NULL, 13, &strConnect);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "makeConnect", &_0);
	ZEPHIR_CPY_WRT(&strConnect, &_1);
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &strConnect, NULL, 0, &arrOption);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 分析连接参数以及其唯一值
 *
 * @param array|string $mixOption
 * @return array
 */
PHP_METHOD(Queryyetsimple_Support_Manager, parseOptionAndUnique) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixOption = NULL, mixOption_sub, strUnique, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixOption_sub);
	ZVAL_UNDEF(&strUnique);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mixOption);

	if (!mixOption) {
		mixOption = &mixOption_sub;
		ZEPHIR_INIT_VAR(mixOption);
		array_init(mixOption);
	} else {
		ZEPHIR_SEPARATE_PARAM(mixOption);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseoptionparameter", NULL, 0, mixOption);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(mixOption, &_0);
	ZEPHIR_CALL_METHOD(&strUnique, this_ptr, "getunique", NULL, 0, mixOption);
	zephir_check_call_status();
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, mixOption);
	zephir_array_fast_append(return_value, &strUnique);
	RETURN_MM();

}

/**
 * 分析连接参数
 *
 * @param array|string $mixOption
 * @return array
 */
PHP_METHOD(Queryyetsimple_Support_Manager, parseOptionParameter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixOption = NULL, mixOption_sub, _0$$4, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixOption_sub);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mixOption);

	if (!mixOption) {
		mixOption = &mixOption_sub;
		ZEPHIR_INIT_VAR(mixOption);
		array_init(mixOption);
	} else {
		ZEPHIR_SEPARATE_PARAM(mixOption);
	}


	if (Z_TYPE_P(mixOption) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	if (Z_TYPE_P(mixOption) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "getoptionobject", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "connect.", mixOption);
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getoptionname", NULL, 0, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(mixOption, &_0$$4, "get", NULL, 0, &_1$$4);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(mixOption) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(mixOption);
		array_init(mixOption);
	}
	RETVAL_ZVAL(mixOption, 1, 0);
	RETURN_MM();

}

/**
 * 取得唯一值
 *
 * @param array $arrOption
 * @return string
 */
PHP_METHOD(Queryyetsimple_Support_Manager, getUnique) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, _0;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrOption_param);

	zephir_get_arrval(&arrOption, arrOption_param);


	ZEPHIR_CALL_FUNCTION(&_0, "serialize", NULL, 14, &arrOption);
	zephir_check_call_status();
	zephir_md5(return_value, &_0);
	RETURN_MM();

}

/**
 * 读取默认配置
 *
 * @param string $strConnect
 * @param array $arrExtendOption
 * @return array
 */
PHP_METHOD(Queryyetsimple_Support_Manager, getOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrExtendOption;
	zval *strConnect_param = NULL, *arrExtendOption_param = NULL, _0, _1;
	zval strConnect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strConnect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arrExtendOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &strConnect_param, &arrExtendOption_param);

	zephir_get_strval(&strConnect, strConnect_param);
	if (!arrExtendOption_param) {
		ZEPHIR_INIT_VAR(&arrExtendOption);
		array_init(&arrExtendOption);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&arrExtendOption, arrExtendOption_param);
	}


	if (1 != 1) {
		ZEPHIR_INIT_NVAR(&arrExtendOption);
		array_init(&arrExtendOption);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptionconnect", NULL, 0, &strConnect);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptioncommon", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_merge", NULL, 15, &_0, &_1, &arrExtendOption);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 读取连接全局配置
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionCommon) {

	zval arrOption, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptionobject", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&arrOption, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "filteroptioncommon", NULL, 0, &arrOption);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&arrOption, &_2);
	RETURN_CCTOR(&arrOption);

}

/**
 * 过滤全局配置
 *
 * @param array $arrOption
 * @return array
 */
PHP_METHOD(Queryyetsimple_Support_Manager, filterOptionCommon) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, strItem, _0, *_1;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&strItem);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrOption_param);

	zephir_get_arrval(&arrOption, arrOption_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "filteroptioncommonitem", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "queryyetsimple/support/manager.zep", 315);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&strItem);
		ZVAL_COPY(&strItem, _1);
		if (zephir_array_isset(&arrOption, &strItem)) {
			zephir_array_unset(&arrOption, &strItem, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&strItem);
	RETURN_CTOR(&arrOption);

}

/**
 * 过滤全局配置项
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Support_Manager, filterOptionCommonItem) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "default");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "connect");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * 读取连接配置
 *
 * @param string $strConnect
 * @return array
 */
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *strConnect_param = NULL, _0, _1;
	zval strConnect, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strConnect);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strConnect_param);

	zephir_get_strval(&strConnect, strConnect_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptionobject", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SV(&_2, "connect.", &strConnect);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoptionname", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 清除配置 null
 *
 * @param array $arrOption
 * @return array
 */
PHP_METHOD(Queryyetsimple_Support_Manager, optionFilterNull) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, _0;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrOption_param);

	zephir_get_arrval(&arrOption, arrOption_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_0__closure_ce, SL("__invoke"));
	ZEPHIR_RETURN_CALL_FUNCTION("array_filter", NULL, 16, &arrOption, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回配置对象
 *
 * @return \queryyetsimple\option\option
 */
PHP_METHOD(Queryyetsimple_Support_Manager, getOptionObject) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("objContainer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "make", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * call 
 *
 * @param string $sMethod
 * @param array $arrArgs
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Support_Manager, __call) {

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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &sMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &arrArgs);
	zephir_check_call_status();
	RETURN_MM();

}

