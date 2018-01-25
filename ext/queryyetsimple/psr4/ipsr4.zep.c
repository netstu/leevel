
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IPsr4 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.25
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Psr4_IPsr4) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Psr4, IPsr4, queryyetsimple, psr4_ipsr4, queryyetsimple_psr4_ipsr4_method_entry);

	return SUCCESS;

}

/**
 * 获取 composer
 *
 * @return \Composer\Autoload\ClassLoader
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Psr4_IPsr4, composer);

/**
 * 导入一个目录中命名空间结构
 *
 * @param string $namespaces 命名空间名字
 * @param string $package 命名空间路径
 * @param boolean $force 强制覆盖
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Psr4_IPsr4, import);

/**
 * 获取命名空间路径
 *
 * @param string $namespaces
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Psr4_IPsr4, namespaces);

/**
 * 根据命名空间取得文件路径
 *
 * @param string $classname
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Psr4_IPsr4, file);

/**
 * 框架自动载入
 *
 * @param string $classname
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Psr4_IPsr4, autoload);

