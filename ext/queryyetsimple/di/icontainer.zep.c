
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IContainer 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.04.13
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Di_IContainer) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Di, IContainer, queryyetsimple, di_icontainer, queryyetsimple_di_icontainer_method_entry);

	return SUCCESS;

}

/**
 * 注册到容器
 *
 * @param mixed $name
 * @param mixed $service
 * @param boolean $share
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Di_IContainer, bind);

/**
 * 注册为实例
 *
 * @param mixed $name
 * @param mixed $service
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Di_IContainer, instance);

/**
 * 注册单一实例
 *
 * @param string $name
 * @param mixed $service
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Di_IContainer, singleton);

/**
 * 创建共享的闭包
 *
 * @param \Closure $closure
 * @return \Closure
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Di_IContainer, share);

/**
 * 设置别名
 *
 * @param array|string $alias
 * @param string|null|array $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Di_IContainer, alias);

/**
 * 分组注册
 *
 * @param string $group
 * @param mixed $data
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Di_IContainer, group);

/**
 * 分组制造
 *
 * @param string $group
 * @param array $args
 * @return array
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Di_IContainer, groupMake);

/**
 * 服务容器返回对象
 *
 * @param string $name
 * @param array $args
 * @return object|false
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Di_IContainer, make);

/**
 * 实例回调自动注入
 *
 * @param callable $callback
 * @param array $args
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Di_IContainer, call);

