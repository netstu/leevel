
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/require.h"


/**
 * psr4 自动载入规范
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.25
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Psr4_Psr4) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Psr4, Psr4, queryyetsimple, psr4_psr4, queryyetsimple_psr4_psr4_method_entry, 0);

	/**
	 * Composer
	 *
	 * @var \Composer\Autoload\ClassLoader
	 */
	zend_declare_property_null(queryyetsimple_psr4_psr4_ce, SL("composer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 沙盒路径
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_psr4_psr4_ce, SL("sandbox"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 系统命名空间
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_psr4_psr4_ce, SL("namespaces"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 短命名空间
	 *
	 * @var string
	 */
	zend_declare_property_null(queryyetsimple_psr4_psr4_ce, SL("shortNamespace"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(queryyetsimple_psr4_psr4_ce TSRMLS_CC, 1, queryyetsimple_psr4_ipsr4_ce);
	return SUCCESS;

}

/**
 * 设置 composer
 *
 * @param \Composer\Autoload\ClassLoader $composer
 * @param string $sandbox
 * @param string $namespaces
 * @param string $shortNamespace
 * @return void
 */
PHP_METHOD(Queryyetsimple_Psr4_Psr4, __construct) {

	zval sandbox, namespaces, shortNamespace;
	zval *composer, composer_sub, *sandbox_param = NULL, *namespaces_param = NULL, *shortNamespace_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&composer_sub);
	ZVAL_UNDEF(&sandbox);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&shortNamespace);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &composer, &sandbox_param, &namespaces_param, &shortNamespace_param);

	zephir_get_strval(&sandbox, sandbox_param);
	zephir_get_strval(&namespaces, namespaces_param);
	zephir_get_strval(&shortNamespace, shortNamespace_param);


	zephir_update_property_zval(this_ptr, SL("composer"), composer);
	zephir_update_property_zval(this_ptr, SL("sandbox"), &sandbox);
	zephir_update_property_zval(this_ptr, SL("namespaces"), &namespaces);
	zephir_update_property_zval(this_ptr, SL("shortNamespace"), &shortNamespace);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取 composer
 *
 * @return \Composer\Autoload\ClassLoader
 */
PHP_METHOD(Queryyetsimple_Psr4_Psr4, composer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "composer");

}

/**
 * 导入一个目录中命名空间结构
 *
 * @param string $namespaces 命名空间名字
 * @param string $package 命名空间路径
 * @param boolean $force 强制覆盖
 * @return void
 */
PHP_METHOD(Queryyetsimple_Psr4_Psr4, import) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool force, _1;
	zval *namespaces_param = NULL, *package_param = NULL, *force_param = NULL, packagePath, _0, _2, _3;
	zval namespaces, package, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&package);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&packagePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &namespaces_param, &package_param, &force_param);

	zephir_get_strval(&namespaces, namespaces_param);
	zephir_get_strval(&package, package_param);
	if (!force_param) {
		force = 0;
	} else {
		force = zephir_get_boolval(force_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 12, &package);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	_1 = force == 0;
	if (_1) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "namespaces", NULL, 0, &namespaces);
		zephir_check_call_status();
		_1 = !(Z_TYPE_P(&_2) == IS_NULL);
	}
	if (_1) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&packagePath, "realpath", NULL, 45, &package);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "composer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &namespaces, "\\");
	ZEPHIR_CALL_METHOD(NULL, &_3, "setpsr4", NULL, 0, &_4, &packagePath);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取命名空间路径
 *
 * @param string $namespaces
 * @return string|null
 */
PHP_METHOD(Queryyetsimple_Psr4_Psr4, namespaces) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespaces_param = NULL, temp, prefix, path, _0, _1, _2, _3;
	zval namespaces;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaces_param);

	zephir_get_strval(&namespaces, namespaces_param);


	ZEPHIR_INIT_VAR(&temp);
	zephir_fast_explode_str(&temp, SL("\\"), &namespaces, LONG_MAX TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "composer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&prefix, &_0, "getprefixespsr4", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &temp, 0, PH_NOISY | PH_READONLY, "queryyetsimple/psr4/psr4.zep", 127 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&path);
	ZEPHIR_CONCAT_VS(&path, &_1, "\\");
	if (!(zephir_array_isset(&prefix, &path))) {
		RETURN_MM_NULL();
	}
	zephir_array_fetch(&_2, &prefix, &path, PH_NOISY | PH_READONLY, "queryyetsimple/psr4/psr4.zep", 132 TSRMLS_CC);
	zephir_array_fetch_long(&_3, &_2, 0, PH_NOISY | PH_READONLY, "queryyetsimple/psr4/psr4.zep", 132 TSRMLS_CC);
	zephir_array_update_long(&temp, 0, &_3, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_fast_join_str(return_value, SL("/"), &temp TSRMLS_CC);
	RETURN_MM();

}

/**
 * 根据命名空间取得文件路径
 *
 * @param string $classname
 * @return string
 */
PHP_METHOD(Queryyetsimple_Psr4_Psr4, file) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classname_param = NULL, namespaces;
	zval classname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classname);
	ZVAL_UNDEF(&namespaces);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	zephir_get_strval(&classname, classname_param);


	ZEPHIR_CALL_METHOD(&namespaces, this_ptr, "namespaces", NULL, 0, &classname);
	zephir_check_call_status();
	if (zephir_is_true(&namespaces)) {
		ZEPHIR_CONCAT_VS(return_value, &namespaces, ".php");
		RETURN_MM();
	} else {
		ZEPHIR_CONCAT_VS(return_value, &classname, ".php");
		RETURN_MM();
	}

}

/**
 * 框架自动载入
 *
 * @param string $classname
 * @return void
 */
PHP_METHOD(Queryyetsimple_Psr4_Psr4, autoload) {

	zend_bool _10$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_12 = NULL;
	zval *classname_param = NULL, namespaces, item, sandboxPath, _0, _1, _2, *_3, _14, _15, _16, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _11$$4, _13$$5;
	zval classname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classname);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&sandboxPath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	zephir_get_strval(&classname, classname_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &classname, &_0, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&namespaces);
	zephir_create_array(&namespaces, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("namespaces"), PH_NOISY_CC);
	zephir_array_fast_append(&namespaces, &_2);
	ZEPHIR_OBS_NVAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("shortNamespace"), PH_NOISY_CC);
	zephir_array_fast_append(&namespaces, &_2);
	zephir_is_iterable(&namespaces, 0, "queryyetsimple/psr4/psr4.zep", 177);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&namespaces), _3)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _3);
		zephir_read_property(&_4$$4, this_ptr, SL("sandbox"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_5$$4);
		ZEPHIR_INIT_NVAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "\\");
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "/");
		zephir_fast_str_replace(&_5$$4, &_6$$4, &_7$$4, &classname TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&sandboxPath);
		ZEPHIR_CONCAT_VSV(&sandboxPath, &_4$$4, "/", &_5$$4);
		ZEPHIR_INIT_LNVAR(_8$$4);
		ZEPHIR_CONCAT_VS(&_8$$4, &item, "\\");
		ZEPHIR_INIT_NVAR(&_9$$4);
		zephir_fast_strpos(&_9$$4, &classname, &_8$$4, 0 );
		_10$$4 = ZEPHIR_IS_LONG_IDENTICAL(&_9$$4, 0);
		if (_10$$4) {
			ZEPHIR_CALL_FUNCTION(&_11$$4, "is_file", &_12, 11, &sandboxPath);
			zephir_check_call_status();
			_10$$4 = zephir_is_true(&_11$$4);
		}
		if (_10$$4) {
			ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_13$$5);
			if (zephir_require_zval_ret(&_13$$5, &sandboxPath TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
			RETURN_CCTOR(&_13$$5);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	zephir_read_property(&_14, this_ptr, SL("shortNamespace"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CONCAT_VS(&_15, &_14, "\\");
	ZEPHIR_INIT_VAR(&_16);
	zephir_fast_strpos(&_16, &classname, &_15, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_16)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "shortnamespacemap", NULL, 0, &classname);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 框架命名空间自动关联
 *
 * @param string $classname
 * @return void
 */
PHP_METHOD(Queryyetsimple_Psr4_Psr4, shortNamespaceMap) {

	zend_bool _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *classname_param = NULL, parentClass, tmp, definedClass, namespaces, evals, _0, _1, _2, _3, _5$$3, _6$$3;
	zval classname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&classname);
	ZVAL_UNDEF(&parentClass);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&definedClass);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&evals);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classname_param);

	zephir_get_strval(&classname, classname_param);


	zephir_read_property(&_0, this_ptr, SL("shortNamespace"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VS(&_1, &_0, "\\");
	zephir_read_property(&_2, this_ptr, SL("namespaces"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, &_2, "\\");
	ZEPHIR_INIT_VAR(&parentClass);
	zephir_fast_str_replace(&parentClass, &_1, &_3, &classname TSRMLS_CC);
	_4 = zephir_class_exists(&parentClass, 1 TSRMLS_CC);
	if (!(_4)) {
		_4 = zephir_interface_exists(&parentClass, 1  TSRMLS_CC);
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_fast_explode_str(&tmp, SL("\\"), &classname, LONG_MAX TSRMLS_CC);
		ZEPHIR_MAKE_REF(&tmp);
		ZEPHIR_CALL_FUNCTION(&definedClass, "array_pop", NULL, 46, &tmp);
		ZEPHIR_UNREF(&tmp);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&namespaces);
		zephir_fast_join_str(&namespaces, SL("\\"), &tmp TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$3);
		if (zephir_class_exists(&parentClass, 1 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_STRING(&_5$$3, "class");
		} else {
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_STRING(&_5$$3, "interface");
		}
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "namespace %s; %s %s extends  \\%s {}");
		ZEPHIR_CALL_FUNCTION(&evals, "sprintf", NULL, 1, &_6$$3, &namespaces, &_5$$3, &definedClass, &parentClass);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_eval_php(&evals, &_6$$3, "/mnt/hgfs/newphp/queryyetsimple/queryyetsimple/psr4/psr4.zep:199" TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

