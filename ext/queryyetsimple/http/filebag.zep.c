
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * file bag
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.04
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Http_FileBag) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Http, FileBag, queryyetsimple, http_filebag, queryyetsimple_http_bag_ce, queryyetsimple_http_filebag_method_entry, 0);

	/**
	 * 上传文件 keys
	 * 
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_http_filebag_ce, SL("fileKeys"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param array $elements
 * @return void 
 */
PHP_METHOD(Queryyetsimple_Http_FileBag, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements_param = NULL, _0;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
	} else {
		zephir_get_arrval(&elements, elements_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizearray", NULL, 0, &elements);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&elements, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &elements);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Http_FileBag, replace) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements_param = NULL, _0;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
	} else {
		zephir_get_arrval(&elements, elements_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("elements"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &elements);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Http_FileBag, set) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *key, key_sub, *value, value_sub, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &value);



	_0 = !((Z_TYPE_P(value) == IS_ARRAY));
	if (_0) {
		_1 = Z_TYPE_P(value) == IS_OBJECT;
		if (_1) {
			_1 = zephir_instance_of_ev(value, queryyetsimple_http_uploadedfile_ce TSRMLS_CC);
		}
		_0 = !(_1);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "An uploaded file must be an array or an instance of UploadedFile.", "queryyetsimple/http/filebag.zep", 74);
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "convertfile", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, queryyetsimple_http_filebag_ce, getThis(), "set", &_2, 0, key, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Queryyetsimple_Http_FileBag, add) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *files_param = NULL, key, file, *_0;
	zval files;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&file);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &files_param);

	if (!files_param) {
		ZEPHIR_INIT_VAR(&files);
		array_init(&files);
	} else {
		zephir_get_arrval(&files, files_param);
	}


	zephir_is_iterable(&files, 0, "queryyetsimple/http/filebag.zep", 90);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&files), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&file);
		ZVAL_COPY(&file, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, &key, &file);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取回文件数组
 * 数组文件请在末尾加上反斜杆访问
 *
 * @param string $key
 * @param mixed $defaults
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Http_FileBag, getArr) {

	zend_string *_3;
	zend_ulong _2;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, files, k, value, _0, *_1, _5, _4$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaults);

	zephir_get_strval(&key, key_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "queryyetsimple/http/filebag.zep", 111);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&k, _3);
		} else {
			ZVAL_LONG(&k, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_fast_strpos(&_4$$3, &k, &key, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(&_4$$3, 0)) {
			zephir_array_append(&files, &value, PH_SEPARATE, "queryyetsimple/http/filebag.zep", 107);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_INIT_VAR(&_5);
	if (zephir_is_true(&files)) {
		ZEPHIR_CPY_WRT(&_5, &files);
	} else {
		ZEPHIR_CPY_WRT(&_5, defaults);
	}
	RETURN_CCTOR(&_5);

}

/**
 * 转换上传信息到文件实例 UploadedFile
 *
 * @param array|\Queryyetsimple\Http\UploadedFile $file
 * @return \Queryyetsimple\Http\UploadedFile|null
 */
PHP_METHOD(Queryyetsimple_Http_FileBag, convertFile) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file = NULL, file_sub, result, _1, _2, _3$$5, _4$$5, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);

	ZEPHIR_SEPARATE_PARAM(file);


	_0 = Z_TYPE_P(file) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(file, queryyetsimple_http_uploadedfile_ce TSRMLS_CC);
	}
	if (_0) {
		RETVAL_ZVAL(file, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "normalizefile", NULL, 0, file);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(file, &_1);
	zephir_array_fetch_string(&_2, file, SL("error"), PH_NOISY | PH_READONLY, "queryyetsimple/http/filebag.zep", 130 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&result);
	if (ZEPHIR_IS_LONG(&_2, 4)) {
		ZVAL_NULL(&result);
	} else {
		object_init_ex(&result, queryyetsimple_http_uploadedfile_ce);
		zephir_array_fetch_string(&_3$$5, file, SL("tmp_name"), PH_NOISY | PH_READONLY, "queryyetsimple/http/filebag.zep", 133 TSRMLS_CC);
		zephir_array_fetch_string(&_4$$5, file, SL("name"), PH_NOISY | PH_READONLY, "queryyetsimple/http/filebag.zep", 133 TSRMLS_CC);
		zephir_array_fetch_string(&_5$$5, file, SL("type"), PH_NOISY | PH_READONLY, "queryyetsimple/http/filebag.zep", 133 TSRMLS_CC);
		zephir_array_fetch_string(&_6$$5, file, SL("error"), PH_NOISY | PH_READONLY, "queryyetsimple/http/filebag.zep", 133 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &result, "__construct", NULL, 69, &_3$$5, &_4$$5, &_5$$5, &_6$$5);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * 格式化 $_FILES 数组
 *
 * @param array $data
 * @return array
 */
PHP_METHOD(Queryyetsimple_Http_FileBag, normalizeFile) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, result, key, value, keys, *_0, _4, _3$$3, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&data, 0, "queryyetsimple/http/filebag.zep", 156);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		zephir_read_static_property_ce(&_3$$3, queryyetsimple_http_filebag_ce, SL("fileKeys"), PH_NOISY_CC | PH_READONLY);
		if (zephir_fast_in_array(&key, &_3$$3 TSRMLS_CC)) {
			zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&keys, this_ptr, "normalizekey", NULL, 0, &result);
	zephir_check_call_status();
	zephir_read_static_property_ce(&_4, queryyetsimple_http_filebag_ce, SL("fileKeys"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_IDENTICAL(&keys, &_4)) {
		ZEPHIR_INIT_VAR(&_5$$5);
		object_init_ex(&_5$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_6$$5);
		zephir_read_static_property_ce(&_7$$5, queryyetsimple_http_filebag_ce, SL("fileKeys"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_join_str(&_6$$5, SL(","), &_7$$5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "An array uploaded file must be contain keys %s.");
		ZEPHIR_CALL_FUNCTION(&_9$$5, "sprintf", NULL, 1, &_8$$5, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$5, "__construct", NULL, 21, &_9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$5, "queryyetsimple/http/filebag.zep", 158 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&result);

}

/**
 * 格式化多维数组类文件为一维数组
 *
 * @param array $elements
 * @return array
 */
PHP_METHOD(Queryyetsimple_Http_FileBag, normalizeArray) {

	zend_string *_2, *_7$$5;
	zend_ulong _1, _6$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL, *_21 = NULL;
	zval *elements_param = NULL, result, key, value, index, item, element, fileKey, *_0, _3$$3, _4$$5, *_5$$5, _8$$6, *_9$$6, _19$$6, _20$$6, _10$$7, _16$$7, _17$$7, _18$$7, _11$$8, _12$$8, _13$$8;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&fileKey);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &elements_param);

	zephir_get_arrval(&elements, elements_param);


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&elements, 0, "queryyetsimple/http/filebag.zep", 198);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&elements), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		zephir_array_fetch_string(&_3$$3, &value, SL("name"), PH_NOISY | PH_READONLY, "queryyetsimple/http/filebag.zep", 179 TSRMLS_CC);
		if (!(zephir_array_isset_string(&value, SL("name")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "An uploaded file must be contain key name.", "queryyetsimple/http/filebag.zep", 178);
			return;
		} else if (Z_TYPE_P(&_3$$3) == IS_ARRAY) {
			zephir_array_fetch_string(&_4$$5, &value, SL("name"), PH_NOISY | PH_READONLY, "queryyetsimple/http/filebag.zep", 180 TSRMLS_CC);
			zephir_is_iterable(&_4$$5, 0, "queryyetsimple/http/filebag.zep", 193);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_4$$5), _6$$5, _7$$5, _5$$5)
			{
				ZEPHIR_INIT_NVAR(&index);
				if (_7$$5 != NULL) { 
					ZVAL_STR_COPY(&index, _7$$5);
				} else {
					ZVAL_LONG(&index, _6$$5);
				}
				ZEPHIR_INIT_NVAR(&item);
				ZVAL_COPY(&item, _5$$5);
				ZEPHIR_INIT_NVAR(&element);
				array_init(&element);
				zephir_read_static_property_ce(&_8$$6, queryyetsimple_http_filebag_ce, SL("fileKeys"), PH_NOISY_CC | PH_READONLY);
				zephir_is_iterable(&_8$$6, 0, "queryyetsimple/http/filebag.zep", 190);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_8$$6), _9$$6)
				{
					ZEPHIR_INIT_NVAR(&fileKey);
					ZVAL_COPY(&fileKey, _9$$6);
					zephir_array_fetch(&_10$$7, &value, &fileKey, PH_READONLY, "queryyetsimple/http/filebag.zep", 184 TSRMLS_CC);
					if (!(zephir_array_isset(&_10$$7, &index))) {
						ZEPHIR_INIT_NVAR(&_11$$8);
						object_init_ex(&_11$$8, spl_ce_InvalidArgumentException);
						ZEPHIR_INIT_NVAR(&_12$$8);
						ZVAL_STRING(&_12$$8, "An uploaded file must be contain key %s.");
						ZEPHIR_CALL_FUNCTION(&_13$$8, "sprintf", &_14, 1, &_12$$8, &fileKey);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_11$$8, "__construct", &_15, 21, &_13$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$8, "queryyetsimple/http/filebag.zep", 185 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_LNVAR(_16$$7);
					zephir_array_fetch(&_17$$7, &value, &fileKey, PH_READONLY, "queryyetsimple/http/filebag.zep", 187 TSRMLS_CC);
					if (zephir_array_isset(&_17$$7, &index)) {
						zephir_array_fetch(&_18$$7, &value, &fileKey, PH_NOISY | PH_READONLY, "queryyetsimple/http/filebag.zep", 187 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&_16$$7);
						zephir_array_fetch(&_16$$7, &_18$$7, &index, PH_NOISY, "queryyetsimple/http/filebag.zep", 187 TSRMLS_CC);
					} else {
						ZEPHIR_INIT_NVAR(&_16$$7);
						ZVAL_STRING(&_16$$7, "");
					}
					zephir_array_update_zval(&element, &fileKey, &_16$$7, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&fileKey);
				ZEPHIR_INIT_LNVAR(_19$$6);
				ZEPHIR_CONCAT_VSV(&_19$$6, &key, "\\", &index);
				zephir_array_update_zval(&result, &_19$$6, &element, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_20$$6, this_ptr, "normalizearray", &_21, 70, &result);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&result, &_20$$6);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&item);
			ZEPHIR_INIT_NVAR(&index);
		} else {
			zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);

}

/**
 * 格式化 keys
 *
 * @param array $data
 * @return array
 */
PHP_METHOD(Queryyetsimple_Http_FileBag, normalizeKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, keys;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&keys);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_INIT_VAR(&keys);
	zephir_array_keys(&keys, &data TSRMLS_CC);
	ZEPHIR_MAKE_REF(&keys);
	ZEPHIR_CALL_FUNCTION(NULL, "sort", NULL, 71, &keys);
	ZEPHIR_UNREF(&keys);
	zephir_check_call_status();
	RETURN_CCTOR(&keys);

}

void zephir_init_static_properties_Queryyetsimple_Http_FileBag(TSRMLS_D) {

	zval _1;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "error");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "name");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "size");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tmp_name");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "type");
	zephir_array_fast_append(&_0, &_1);
	zend_update_static_property(queryyetsimple_http_filebag_ce, ZEND_STRL("fileKeys"), &_0);
	ZEPHIR_MM_RESTORE();

}

