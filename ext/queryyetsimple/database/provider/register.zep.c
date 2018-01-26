
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * database 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.26
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Database_Provider_Register) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Database\\Provider, Register, queryyetsimple, database_provider_register, queryyetsimple_di_provider_ce, queryyetsimple_database_provider_register_method_entry, 0);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Queryyetsimple\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Queryyetsimple_Database_Provider_Register, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_CALL_PARENT(NULL, queryyetsimple_database_provider_register_ce, getThis(), "__construct", &_0, 0, container);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Database_Provider_Register, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "databases", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "database", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 载入命令包
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Database_Provider_Register, bootstrap) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Queryyetsimple\\Database\\Console");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadcommandnamespace", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Database_Provider_Register, providers) {

	zval _0;
	zval tmp, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmp);
	zephir_create_array(&tmp, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\Database\\Manager");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\Database\\Manager");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("databases"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\Database\\Database");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\Database\\IDatabase");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\Database\\Database");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\Database\\IDatabase");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("database"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&tmp);

}

/**
 * 注册 databases 服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Database_Provider_Register, databases) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_5__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "databases");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 database 服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Database_Provider_Register, database) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_6__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "database");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

