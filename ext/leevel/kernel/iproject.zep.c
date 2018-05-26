
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IProject 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.04.23
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Kernel_IProject) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Kernel, IProject, leevel, kernel_iproject, leevel_kernel_iproject_method_entry);

	/**
	 * QueryPHP 版本
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_kernel_iproject_ce, SL("VERSION"), "1.0.0");

	/**
	 * 默认环境变量名字
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_kernel_iproject_ce, SL("DEFAULT_ENV"), ".env");

	zend_class_implements(leevel_kernel_iproject_ce TSRMLS_CC, 1, leevel_di_icontainer_ce);
	return SUCCESS;

}

/**
 * 返回项目
 *
 * @param string $path
 * @return static
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, singletons);

/**
 * 程序版本
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, version);

/**
 * 是否以扩展方式运行
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, runWithExtension);

/**
 * {@inheritdoc}
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, make);

/**
 * 设置项目路径
 *
 * @param string $path
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPath);

/**
 * 基础路径
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, path);

/**
 * 应用路径
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathApplication);

/**
 * 设置应用路径
 *
 * @param string $path
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPathApplication);

/**
 * 设置公共路径
 *
 * @param string $path
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPathCommon);

/**
 * 公共路径
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathCommon);

/**
 * 设置运行时路径
 *
 * @param string $path
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPathRuntime);

/**
 * 运行路径
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathRuntime);

/**
 * 设置存储路径
 *
 * @param string $path
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPathStorage);

/**
 * 附件路径
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathStorage);

/**
 * 设置配置路径
 *
 * @param string $path
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPathOption);

/**
 * 配置路径
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathOption);

/**
 * 设置语言包路径
 *
 * @param string $path
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPathI18n);

/**
 * 语言包路径
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathI18n);

/**
 * 环境变量路径
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathEnv);

/**
 * 设置环境变量路径
 *
 * @param string $path
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPathEnv);

/**
 * 设置环境变量文件
 *
 * @param string $file
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setEnvFile);

/**
 * 取得环境变量文件
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, envFile);

/**
 * 取得环境变量完整路径
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, fullEnvPath);

/**
 * 应用路径
 *
 * @param string $app
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathAnApplication);

/**
 * 取得应用缓存目录
 *
 * @param string $type
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathApplicationCache);

/**
 * 取得应用目录
 *
 * @param string $type
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathApplicationDir);

/**
 * 返回语言包路径
 * 
 * @param string $i18n
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathCacheI18nFile);

/**
 * 是否缓存语言包
 *
 * @param string $i18n
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, isCachedI18n);

/**
 * 返回缓存路径
 * 
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, pathCacheOptionFile);

/**
 * 是否缓存配置
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, isCachedOption);

/**
 * 取得 composer
 *
 * @return \Composer\Autoload\ClassLoader
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, composer);

/**
 * 获取命名空间路径
 *
 * @param string $namespaces
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, getPathByNamespace);

/**
 * 批量获取命名空间路径
 *
 * @param array $namespaces
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, getPathByNamespaces);

/**
 * 是否开启 debug
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, debug);

/**
 * 是否为开发环境
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, development);

/**
 * 运行环境
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, environment);

/**
 * 是否为 API
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, api);

/**
 * 是否为 Console
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, console);

/**
 * 创建服务提供者
 *
 * @param string $provider
 * @return \Leevel\Di\Provider
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, makeProvider);

/**
 * 执行 bootstrap
 *
 * @param \Leevel\Di\Provider $provider
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, callProviderBootstrap);

/**
 * 初始化项目
 * 
 * @param array $bootstraps
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, bootstrap);

/**
 * 是否已经初始化引导
 * 
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, isBootstrap);

/**
 * 框架基础提供者 register
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, registerProviders);

/**
 * 执行框架基础提供者 bootstrap
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, bootstrapProviders);

/**
 * 注册服务提供者
 *
 * @param \Leevel\Di\Provider|string $provider
 * @return \Leevel\Di\Provider
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, register);

