
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * 沙盒 auth
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.23
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Auth) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple, Auth, queryyetsimple, auth, queryyetsimple_support_facade_ce, queryyetsimple_auth_method_entry, 0);

	return SUCCESS;

}

/**
 * 返回门面名字
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Auth, name) {

	zval *this_ptr = getThis();


	RETURN_STRING("auths");

}

