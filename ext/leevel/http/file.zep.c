
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
#include "ext/spl/spl_directory.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * 文件
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.05
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
ZEPHIR_INIT_CLASS(Leevel_Http_File) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Http, File, leevel, http_file, spl_ce_SplFileObject, leevel_http_file_method_entry, 0);

	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param string $path
 * @return void
 */
PHP_METHOD(Leevel_Http_File, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1$$3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 27, &path);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, leevel_http_filenotfoundexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 2, &path);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "leevel/http/file.zep", 42 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, leevel_http_file_ce, getThis(), "__construct", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 移动文件
 *
 * @param string $directory
 * @param string $name
 * @return \Leevel\Http\File
 */
PHP_METHOD(Leevel_Http_File, move) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory_param = NULL, *name = NULL, name_sub, __$null, target, _0;
	zval directory;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directory_param, &name);

	zephir_get_strval(&directory, directory_param);
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_METHOD(&target, this_ptr, "gettargetfile", NULL, 0, &directory, name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpathname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "movetotarget", NULL, 0, &_0, &target);
	zephir_check_call_status();
	object_init_ex(return_value, leevel_http_file_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 48, &target);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取目标文件
 *
 * @param string $directory
 * @param string $name
 * @return string
 */
PHP_METHOD(Leevel_Http_File, getTargetFile) {

	zend_bool _5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *directory_param = NULL, *name = NULL, name_sub, __$true, __$null, target, _0, _2, _13, _14, _15, _3$$3, _4$$3, _6$$3, _7$$4, _8$$4, _9$$4, _10$$5, _11$$5, _12$$5;
	zval directory;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&name_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directory_param, &name);

	zephir_get_strval(&directory, directory_param);
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", &_1, 28, &directory);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "is_writable", NULL, 49, &directory);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZVAL_LONG(&_3$$3, 511);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "mkdir", NULL, 29, &directory, &_3$$3, &__$true);
		zephir_check_call_status();
		_5$$3 = ZEPHIR_IS_FALSE_IDENTICAL(&_4$$3);
		if (_5$$3) {
			ZEPHIR_CALL_FUNCTION(&_6$$3, "is_dir", &_1, 28, &directory);
			zephir_check_call_status();
			_5$$3 = !zephir_is_true(&_6$$3);
		}
		if (_5$$3) {
			ZEPHIR_INIT_VAR(&_7$$4);
			object_init_ex(&_7$$4, leevel_http_fileexception_ce);
			ZEPHIR_INIT_VAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "Unable to create the %s directory");
			ZEPHIR_CALL_FUNCTION(&_9$$4, "sprintf", NULL, 1, &_8$$4, &directory);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 2, &_9$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$4, "leevel/http/file.zep", 78 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else if (!(zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_10$$5);
		object_init_ex(&_10$$5, leevel_http_fileexception_ce);
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "Unable to write in the %s directory");
		ZEPHIR_CALL_FUNCTION(&_12$$5, "sprintf", NULL, 1, &_11$$5, &directory);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 2, &_12$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$5, "leevel/http/file.zep", 81 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "/\\");
	zephir_fast_trim(&_13, &directory, &_14, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_15);
	if (Z_TYPE_P(name) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_15, this_ptr, "getbasename", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_15, name);
	}
	ZEPHIR_INIT_VAR(&target);
	ZEPHIR_CONCAT_VSV(&target, &_13, "/", &_15);
	RETURN_CCTOR(&target);

}

/**
 * 移动文件到目标文件
 *
 * @param string $sourcePath
 * @param string $target
 * @return void
 */
PHP_METHOD(Leevel_Http_File, moveToTarget) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sourcePath_param = NULL, *target_param = NULL, error, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zval sourcePath, target;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sourcePath_param, &target_param);

	zephir_get_strval(&sourcePath, sourcePath_param);
	zephir_get_strval(&target, target_param);


	ZEPHIR_CALL_FUNCTION(&_0, "move_uploaded_file", NULL, 50, &sourcePath, &target);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_FUNCTION(&error, "error_get_last", NULL, 51);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, leevel_http_fileexception_ce);
		zephir_array_fetch_string(&_2$$3, &error, SL("message"), PH_NOISY | PH_READONLY, "leevel/http/file.zep", 102 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "strip_tags", NULL, 52, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Could not move the file %s to %s (%s)");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "sprintf", NULL, 1, &_4$$3, &sourcePath, &target, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 2, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "leevel/http/file.zep", 102 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

