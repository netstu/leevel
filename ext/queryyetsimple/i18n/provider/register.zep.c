
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
 * i18n 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.26
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_I18n_Provider_Register) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\I18n\\Provider, Register, queryyetsimple, i18n_provider_register, queryyetsimple_di_provider_ce, queryyetsimple_i18n_provider_register_method_entry, 0);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Queryyetsimple\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_Provider_Register, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_CALL_PARENT(NULL, queryyetsimple_i18n_provider_register_ce, getThis(), "__construct", &_0, 0, container);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_Provider_Register, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "i18n", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "i18nload", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * bootstrap
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_Provider_Register, bootstrap) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "console", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_I18n_Provider_Register, providers) {

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
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "queryyetsimple\\I18n\\I18n");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\I18n\\II18n");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\I18n\\I18n");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\I18n\\II18n");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("i18n"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Queryyetsimple\\I18n\\Load");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Qys\\I18n\\Load");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&tmp, SL("load"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&tmp);

}

/**
 * 注册 i18n 服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_Provider_Register, i18n) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_17__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "i18n");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册 i18n.load 服务
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_Provider_Register, i18nLoad) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_18__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "i18n.load");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "singleton", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 载入命令包
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_I18n_Provider_Register, console) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Queryyetsimple\\I18n\\Console");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadcommandnamespace", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

