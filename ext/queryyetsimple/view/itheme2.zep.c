
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * itheme 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.02
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_View_Itheme2) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\View, Itheme2, queryyetsimple, view_itheme2, queryyetsimple_view_itheme2_method_entry);

	return SUCCESS;

}

/**
 * 设置 parse 解析回调
 *
 * @param callable $calParseResolver
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, setParseResolver);

/**
 * 解析 parse
 *
 * @return \queryyetsimple\view\parser
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, resolverParse);

/**
 * 获取分析器
 *
 * @return \queryyetsimple\view\iparser
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, parser);

/**
 * 加载视图文件
 *
 * @param string $sFile 视图文件地址
 * @param boolean $bDisplay 是否显示
 * @param string $strExt 后缀
 * @param string $sTargetCache 主模板缓存路径
 * @param string $sMd5 源文件地址 md5 标记
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, display);

/**
 * 设置模板变量
 *
 * @param mixed $mixName
 * @param mixed $mixValue
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, setVar);

/**
 * 获取变量值
 *
 * @param string|null $sName
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, getVar);

/**
 * 删除变量值
 *
 * @param mixed $mixName
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, deleteVar);

/**
 * 清空变量值
 *
 * @param string|null $sName
 * @return $this
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, clearVar);

/**
 * 获取编译路径
 *
 * @param string $sFile
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, getCachePath);

/**
 * 自动分析视图上下文环境
 *
 * @param string $strThemePath
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_View_Itheme2, parseContext);

