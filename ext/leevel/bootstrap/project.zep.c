
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/require.h"


/**
 * 项目管理
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.01.14
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Project) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Bootstrap, Project, leevel, bootstrap_project, leevel_di_container_ce, leevel_bootstrap_project_method_entry, 0);

	/**
	 * 当前项目实例
	 *
	 * @var static
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("project"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 项目基础路径
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 应用路径
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("applicationPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 公共路径
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("commonPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 运行时路径
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("runtimePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 存储路径
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("storagePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置路径
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("optionPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 语言包路径
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("i18nPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 环境变量路径
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("envPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 环境变量文件
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("envFile"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 延迟载入服务提供者
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("deferredProviders"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 服务提供者 bootstrap
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("providerBootstraps"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_bootstrap_project_ce->create_object = zephir_init_properties_Leevel_Bootstrap_Project;

	zend_class_implements(leevel_bootstrap_project_ce TSRMLS_CC, 1, leevel_kernel_iproject_ce);
	return SUCCESS;

}

/**
 * 构造函数
 * 受保护的禁止外部通过 new 实例化，只能通过 singletons 生成单一实例
 *
 * @param string $path
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Project, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path);

	if (!path) {
		path = &path_sub;
		path = &__$null;
	}


	if (zephir_is_true(path)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpath", NULL, 0, path);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerbaseservices", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerbaseprovider", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 禁止克隆
 *
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Project, __clone) {

	zval *this_ptr = getThis();


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Project disallowed clone.", "leevel/bootstrap/project.zep", 147);
	return;

}

/**
 * 返回项目
 *
 * @param string $path
 * @return static
 */
PHP_METHOD(Leevel_Bootstrap_Project, singletons) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, __$null, _0, _1$$3, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path);

	if (!path) {
		path = &path_sub;
		path = &__$null;
	}


	zephir_read_static_property_ce(&_0, leevel_bootstrap_project_ce, SL("project"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_static_property_ce(&_1$$3, leevel_bootstrap_project_ce, SL("project"), PH_NOISY_CC | PH_READONLY);
		RETURN_CTOR(&_1$$3);
	} else {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, leevel_bootstrap_project_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 69, path);
		zephir_check_call_status();
		zend_update_static_property(leevel_bootstrap_project_ce, ZEND_STRL("project"), &_2$$4);
		zephir_read_static_property_ce(&_3$$4, leevel_bootstrap_project_ce, SL("project"), PH_NOISY_CC | PH_READONLY);
		RETURN_CTOR(&_3$$4);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 程序版本
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, version) {

	zval *this_ptr = getThis();


	RETURN_STRING("1.0.0");

}

/**
 * 是否以扩展方式运行
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Bootstrap_Project, runWithExtension) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "leevel");
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 70, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Bootstrap_Project, make) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *name = NULL, name_sub, *args_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &args_param);

	ZEPHIR_SEPARATE_PARAM(name);
	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getalias", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property(&_1, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, name)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerdeferredprovider", NULL, 0, name);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_PARENT(leevel_bootstrap_project_ce, getThis(), "make", &_2, 0, name, &args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置项目路径
 *
 * @param string $path
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPath) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path, path_sub, _0, _2, _3$$3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("path"), path);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "pathruntime", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "is_writeable", NULL, 71, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, spl_ce_RuntimeException);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "pathruntime", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Runtime path %s is not writeable.");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", NULL, 1, &_5$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 2, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "leevel/bootstrap/project.zep", 211 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 基础路径
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, path) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "path");

}

/**
 * 应用路径
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathApplication) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("applicationPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("applicationPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "application");
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置应用路径
 *
 * @param string $path
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPathApplication) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("applicationPath"), path);
	RETURN_THISW();

}

/**
 * 设置公共路径
 *
 * @param string $path
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPathCommon) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("commonPath"), path);
	RETURN_THISW();

}

/**
 * 公共路径
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathCommon) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("commonPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("commonPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "common");
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置运行时路径
 *
 * @param string $path
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPathRuntime) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("runtimePath"), path);
	RETURN_THISW();

}

/**
 * 运行路径
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathRuntime) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("runtimePath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("runtimePath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "runtime");
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置存储路径
 *
 * @param string $path
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPathStorage) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("storagePath"), path);
	RETURN_THISW();

}

/**
 * 附件路径
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathStorage) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("storagePath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("storagePath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "storage");
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置配置路径
 *
 * @param string $path
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPathOption) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("optionPath"), path);
	RETURN_THISW();

}

/**
 * 配置路径
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathOption) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("optionPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("optionPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "option");
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置语言包路径
 *
 * @param string $path
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPathI18n) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("i18nPath"), path);
	RETURN_THISW();

}

/**
 * 语言包路径
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathI18n) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("i18nPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("i18nPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "i18n");
	}
	RETURN_CCTOR(&_0);

}

/**
 * 环境变量路径
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathEnv) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("envPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("envPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置环境变量路径
 *
 * @param string $path
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPathEnv) {

	zval *path, path_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);

	zephir_fetch_params(0, 1, 0, &path);



	zephir_update_property_zval(this_ptr, SL("envPath"), path);
	RETURN_THISW();

}

/**
 * 设置环境变量文件
 *
 * @param string $file
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, setEnvFile) {

	zval *file_param = NULL;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(&file, file_param);


	zephir_update_property_zval(this_ptr, SL("envFile"), &file);
	RETURN_THIS();

}

/**
 * 取得环境变量文件
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, envFile) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("envFile"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("envFile"), PH_NOISY_CC);
	} else {
		ZVAL_STRING(&_0, ".env");
	}
	RETURN_CCTOR(&_0);

}

/**
 * 取得环境变量完整路径
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, fullEnvPath) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "pathenv", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "envfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_0, "/", &_1);
	RETURN_MM();

}

/**
 * 应用路径
 *
 * @param string $app
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathAnApplication) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app = NULL, app_sub, __$null, _0, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &app);

	if (!app) {
		app = &app_sub;
		app = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "pathapplication", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	if (zephir_is_true(app)) {
		ZEPHIR_CPY_WRT(&_2, app);
	} else {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "request");
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "make", NULL, 0, &_4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, &_3, "app", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_5)) {
			ZEPHIR_INIT_NVAR(&_4);
			ZVAL_STRING(&_4, "request");
			ZEPHIR_CALL_METHOD(&_6, this_ptr, "make", NULL, 0, &_4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2, &_6, "app", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&_2);
			ZVAL_STRING(&_2, "App");
		}
	}
	zephir_fast_strtolower(&_1, &_2);
	ZEPHIR_CONCAT_VSV(return_value, &_0, "/", &_1);
	RETURN_MM();

}

/**
 * 取得应用缓存目录
 *
 * @param string $type
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathApplicationCache) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, types, _0, _4, _1$$3, _2$$3, _3$$3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	ZEPHIR_INIT_VAR(&types);
	zephir_create_array(&types, 9, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "file");
	zephir_array_fast_append(&types, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "log");
	zephir_array_fast_append(&types, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "table");
	zephir_array_fast_append(&types, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "theme");
	zephir_array_fast_append(&types, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "option");
	zephir_array_fast_append(&types, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "i18n");
	zephir_array_fast_append(&types, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "router");
	zephir_array_fast_append(&types, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "console");
	zephir_array_fast_append(&types, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "swoole");
	zephir_array_fast_append(&types, &_0);
	if (!(zephir_fast_in_array(&type, &types TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Application cache type %s not support");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, &type);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 22, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "leevel/bootstrap/project.zep", 452 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "pathruntime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_4, "/", &type);
	RETURN_MM();

}

/**
 * 取得应用目录
 *
 * @param string $type
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathApplicationDir) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, types, _0, _4, _1$$3, _2$$3, _3$$3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&types);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	ZEPHIR_INIT_VAR(&types);
	zephir_create_array(&types, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "theme");
	zephir_array_fast_append(&types, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "i18n");
	zephir_array_fast_append(&types, &_0);
	if (!(zephir_fast_in_array(&type, &types TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Application dir type %s not support");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 1, &_2$$3, &type);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 22, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "leevel/bootstrap/project.zep", 474 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "pathanapplication", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_4, "/ui/", &type);
	RETURN_MM();

}

/**
 * 返回语言包路径
 * 
 * @param string $i18n
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathCacheI18nFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *i18n, i18n_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i18n_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i18n);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "pathruntime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, &_0, "/cache/i18n/", i18n, ".php");
	RETURN_MM();

}

/**
 * 是否缓存语言包
 *
 * @param string $i18n
 * @return boolean
 */
PHP_METHOD(Leevel_Bootstrap_Project, isCachedI18n) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *i18n, i18n_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i18n_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i18n);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "pathcachei18nfile", NULL, 0, i18n);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("is_file", NULL, 27, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回缓存路径
 * 
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, pathCacheOptionFile) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "pathruntime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VS(return_value, &_0, "/cache/option.php");
	RETURN_MM();

}

/**
 * 是否缓存配置
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Bootstrap_Project, isCachedOption) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "pathcacheoptionfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("is_file", NULL, 27, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取得 composer
 *
 * @return \Composer\Autoload\ClassLoader
 */
PHP_METHOD(Leevel_Bootstrap_Project, composer) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VS(&_1, &_0, "/vendor/autoload.php");
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_2);
	if (zephir_require_zval_ret(&_2, &_1 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&_2);

}

/**
 * 获取命名空间路径
 *
 * @param string $namespaces
 * @return string|null
 */
PHP_METHOD(Leevel_Bootstrap_Project, getPathByNamespace) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespaces = NULL, namespaces_sub, prefix, _0, _1, _2, _3, _4, _5, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces_sub);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaces);

	ZEPHIR_SEPARATE_PARAM(namespaces);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL("\\"), namespaces, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(namespaces, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "composer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&prefix, &_1, "getprefixespsr4", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, namespaces, 0, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 545 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, &_2, "\\");
	if (!(zephir_array_isset(&prefix, &_3))) {
		RETURN_MM_NULL();
	}
	zephir_array_fetch_long(&_5, namespaces, 0, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 549 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_VS(&_6, &_5, "\\");
	zephir_array_fetch(&_4, &prefix, &_6, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 549 TSRMLS_CC);
	zephir_array_fetch_long(&_7, &_4, 0, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 549 TSRMLS_CC);
	zephir_array_update_long(namespaces, 0, &_7, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_fast_join_str(return_value, SL("/"), namespaces TSRMLS_CC);
	RETURN_MM();

}

/**
 * 批量获取命名空间路径
 *
 * @param array $namespaces
 * @return array
 */
PHP_METHOD(Leevel_Bootstrap_Project, getPathByNamespaces) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespaces_param = NULL, result, item, *_0, _1$$3;
	zval namespaces;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaces_param);

	zephir_get_arrval(&namespaces, namespaces_param);


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&namespaces, 0, "leevel/bootstrap/project.zep", 570);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&namespaces), _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _0);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getpathbynamespace", &_2, 0, &item);
		zephir_check_call_status();
		zephir_array_update_zval(&result, &item, &_1$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&result);

}

/**
 * 是否开启 debug
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Bootstrap_Project, debug) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "debug");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否为开发环境
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Bootstrap_Project, development) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "environment", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "development"));

}

/**
 * 运行环境
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Bootstrap_Project, environment) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "environment");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否为 API
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Bootstrap_Project, api) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isacceptjson", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否为 Console
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Bootstrap_Project, console) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "iscli", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建服务提供者
 *
 * @param string $provider
 * @return \Leevel\Di\Provider
 */
PHP_METHOD(Leevel_Bootstrap_Project, makeProvider) {

	zend_class_entry *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider_param = NULL, _0;
	zval provider;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider_param);

	zephir_get_strval(&provider, provider_param);


	zephir_fetch_safe_class(&_0, &provider);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 执行 bootstrap
 *
 * @param \Leevel\Di\Provider $provider
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Project, callProviderBootstrap) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider, provider_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);



	if (!((zephir_method_exists_ex(provider, SL("bootstrap") TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, provider);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "bootstrap");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "call", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化项目
 * 
 * @param array $bootstraps
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Project, bootstrap) {

	zend_class_entry *_3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bootstraps_param = NULL, value, *_0, _1$$3, _2$$3;
	zval bootstraps;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bootstraps);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bootstraps_param);

	zephir_get_arrval(&bootstraps, bootstraps_param);


	zephir_is_iterable(&bootstraps, 0, "leevel/bootstrap/project.zep", 665);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&bootstraps), _0)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_INIT_NVAR(&_1$$3);
		zephir_fetch_safe_class(&_2$$3, &value);
		_3$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2$$3), Z_STRLEN_P(&_2$$3), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_1$$3, _3$$3);
		if (zephir_has_constructor(&_1$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "handle", NULL, 0, this_ptr);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_MM_RESTORE();

}

/**
 * 框架基础提供者 register
 *
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, registerProviders) {

	zval _2;
	zval tmp, alias, deferredAlias, providers, provider, providerInstance, _0, _1, _3, *_4, _6, _7, *_8;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&deferredAlias);
	ZVAL_UNDEF(&providers);
	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&providerInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_deferred_providers");
	ZEPHIR_CALL_METHOD(&tmp, &_0, "get", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, &tmp, 0, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 677 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("deferredProviders"), &_3);
	ZEPHIR_OBS_VAR(&deferredAlias);
	zephir_array_fetch_long(&deferredAlias, &tmp, 1, PH_NOISY, "leevel/bootstrap/project.zep", 678 TSRMLS_CC);
	zephir_is_iterable(&deferredAlias, 0, "leevel/bootstrap/project.zep", 684);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&deferredAlias), _4)
	{
		ZEPHIR_INIT_NVAR(&alias);
		ZVAL_COPY(&alias, _4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", &_5, 0, &alias);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&alias);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "_composer.providers");
	ZEPHIR_CALL_METHOD(&providers, &_6, "get", NULL, 0, &_7, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&providers, 0, "leevel/bootstrap/project.zep", 694);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&providers), _8)
	{
		ZEPHIR_INIT_NVAR(&provider);
		ZVAL_COPY(&provider, _8);
		ZEPHIR_CALL_METHOD(&providerInstance, this_ptr, "register", &_9, 0, &provider);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(&providerInstance, SL("bootstrap") TSRMLS_CC) == SUCCESS)) {
			zephir_update_property_array_append(this_ptr, SL("providerBootstraps"), &providerInstance TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&provider);
	RETURN_THIS();

}

/**
 * 执行框架基础提供者 bootstrap
 *
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, bootstrapProviders) {

	zval item, _0, *_1;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("providerBootstraps"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "leevel/bootstrap/project.zep", 710);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "callproviderbootstrap", &_2, 0, &item);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_THIS();

}

/**
 * 注册服务提供者
 *
 * @param \Leevel\Di\Provider|string $provider
 * @return \Leevel\Di\Provider
 */
PHP_METHOD(Leevel_Bootstrap_Project, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider = NULL, provider_sub, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);

	ZEPHIR_SEPARATE_PARAM(provider);


	if (Z_TYPE_P(provider) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "makeprovider", NULL, 0, provider);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(provider, &_0$$3);
	}
	if ((zephir_method_exists_ex(provider, SL("register") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, provider, "register", NULL, 0);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(provider, 1, 0);
	RETURN_MM();

}

/**
 * 注册基础服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Project, registerBaseServices) {

	zval _1, _2;
	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "project");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "instance", NULL, 0, &_0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Bootstrap\\Project");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Di\\IContainer");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Kernel\\IProject");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "app");
	zephir_array_fast_append(&_2, &_0);
	zephir_array_update_string(&_1, SL("project"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Http\\IRequest");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Http\\Request");
	zephir_array_fast_append(&_2, &_0);
	zephir_array_update_string(&_1, SL("request"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Option\\IOption");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Option\\Option");
	zephir_array_fast_append(&_2, &_0);
	zephir_array_update_string(&_1, SL("option"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\I18n\\I18n");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\I18n\\II18n");
	zephir_array_fast_append(&_2, &_0);
	zephir_array_update_string(&_1, SL("i18n"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册基础服务提供者
 *
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Project, registerBaseProvider) {

	zval _0, _2, _3;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, leevel_event_provider_register_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 72, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", &_1, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, leevel_log_provider_register_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 73, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, leevel_router_provider_register_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 74, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", &_1, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册延迟载入服务提供者
 *
 * @param string $provider
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Project, registerDeferredProvider) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider_param = NULL, providerInstance, _0, _1, _2, _3;
	zval provider;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&providerInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider_param);

	zephir_get_strval(&provider, provider_param);


	zephir_read_property(&_0, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &provider))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &provider, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 791 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&providerInstance, this_ptr, "register", NULL, 0, &_2);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(&providerInstance, SL("bootstrap") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "callproviderbootstrap", NULL, 0, &providerInstance);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_3, &provider, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Leevel_Bootstrap_Project(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _10, _12, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("providerBootstraps"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("providerBootstraps"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("shareClosure"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("shareClosure"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("alias"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("alias"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("singletons"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("singletons"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("instances"), &_9$$7);
		}
		zephir_read_property(&_10, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval(this_ptr, SL("services"), &_11$$8);
		}
		zephir_read_property(&_12, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval(this_ptr, SL("deferredProviders"), &_13$$9);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

