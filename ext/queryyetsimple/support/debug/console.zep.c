
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/**
 * 调试
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Debug_Console) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Support\\Debug, Console, queryyetsimple, support_debug_console, queryyetsimple_support_debug_console_method_entry, 0);

	return SUCCESS;

}

/**
 * 记录调试信息
 * SQL 记录，加载文件等等
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Support_Debug_Console, trace) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_SERVER, _0, _2, _3, _4, arrTrace, _5, _6, _7, _8, sReturn;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&arrTrace);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&sReturn);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	if (!_SERVER) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_SAPI");
	if (ZEPHIR_IS_STRING(&_0, "cli")) {
		RETURN_MM_NULL();
	}
	_1 = zephir_array_isset_string(_SERVER, SL("HTTP_X_REQUESTED_WITH"));
	if (_1) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_array_fetch_string(&_3, _SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "queryyetsimple/support/debug/console.zep", 47 TSRMLS_CC);
		zephir_fast_strtolower(&_2, &_3);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "xmlhttprequest");
		_1 = ZEPHIR_IS_EQUAL(&_4, &_2);
	}
	if (_1) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&arrTrace);
	array_init(&arrTrace);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CALL_SELF(&_6, "formatlogo", NULL, 0);
	zephir_check_call_status();
	zephir_fast_join_str(&_5, SL("\n"), &_6 TSRMLS_CC);
	zephir_array_append(&arrTrace, &_5, PH_SEPARATE, "queryyetsimple/support/debug/console.zep", 54);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "bootstrap/template/trace.php");
	ZEPHIR_CALL_FUNCTION(&_8, "path_framework", NULL, 0, &_7);
	zephir_check_call_status();
	if (zephir_require_zval(&_8 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&sReturn, "ob_get_contents", NULL, 6);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 7);
	zephir_check_call_status();
	RETURN_CCTOR(&sReturn);

}

/**
 * 格式化日志信息
 *
 * @param array $arrItem
 * @return string
 */
PHP_METHOD(Queryyetsimple_Support_Debug_Console, formatMessage) {

	zval *arrItem_param = NULL;
	zval arrItem;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrItem);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrItem_param);

	ZEPHIR_OBS_COPY_OR_DUP(&arrItem, arrItem_param);



}

/**
 * 格式化 LOGO
 *
 * @return array
 */
PHP_METHOD(Queryyetsimple_Support_Debug_Console, formatLogo) {

	zval _0, _1, _2;
	zval strLogo;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strLogo);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&strLogo);
	ZVAL_STRING(&strLogo, "\n##########################################################\n#   ____                          ______  _   _ ______   #\n#  /     \       ___  _ __  _   _ | ___ \| | | || ___ \  #\n# |   (  ||(_)| / _ \| '__|| | | || |_/ /| |_| || |_/ /  #\n#  \____/ |___||  __/| |   | |_| ||  __/ |  _  ||  __/   #\n#       \__   | \___ |_|    \__  || |    | | | || |      #\n#     Query Yet Simple      __/  |\_|    |_| |_|\_|      #\n#                          |___ /  Since 2010.10.03      #\n##########################################################\n");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, queryyetsimple_0__closure_ce, SL("__invoke"));
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	zephir_fast_explode(&_1, &_2, &strLogo, LONG_MAX TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("array_map", NULL, 8, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

