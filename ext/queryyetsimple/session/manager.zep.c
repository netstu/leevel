
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * manager 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.09
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Session_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Session, Manager, queryyetsimple, session_manager, queryyetsimple_support_manager_ce, queryyetsimple_session_manager_method_entry, 0);

	return SUCCESS;

}

/**
 * 取得配置命名空间
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Session_Manager, getOptionNamespace) {

	zval *this_ptr = getThis();


	RETURN_STRING("session");

}

/**
 * 创建连接对象
 *
 * @param object $objConnect
 * @return object
 */
PHP_METHOD(Queryyetsimple_Session_Manager, createConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *objConnect, objConnect_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objConnect_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &objConnect);



	object_init_ex(return_value, queryyetsimple_session_session_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptioncommon", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 34, objConnect, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 cookie 缓存
 *
 * @param array $arrOption
 * @return null
 */
PHP_METHOD(Queryyetsimple_Session_Manager, makeConnectCookie) {

	zval *arrOption_param = NULL;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	RETURN_MM_NULL();

}

/**
 * 创建 memcache 缓存
 *
 * @param array $arrOption
 * @return \queryyetsimple\session\memcache
 */
PHP_METHOD(Queryyetsimple_Session_Manager, makeConnectMemcache) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, _1, _2;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Session\\Memcache"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "memcache");
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &_2, &arrOption);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 创建 redis 缓存
 *
 * @param array $arrOption
 * @return \queryyetsimple\session\redis
 */
PHP_METHOD(Queryyetsimple_Session_Manager, makeConnectRedis) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, _1, _2;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Queryyetsimple\\Session\\Redis"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "redis");
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &_2, &arrOption);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 读取连接配置
 *
 * @param string $strConnect
 * @return array
 */
PHP_METHOD(Queryyetsimple_Session_Manager, getOptionConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *strConnect_param = NULL, _0;
	zval strConnect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strConnect);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &strConnect_param);

	zephir_get_strval(&strConnect, strConnect_param);


	ZEPHIR_CALL_PARENT(&_0, queryyetsimple_session_manager_ce, getThis(), "getoptionconnect", &_1, 0, &strConnect);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "optionfilternull", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

