
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ilog 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Ilog) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Log, Ilog, queryyetsimple, log_ilog, queryyetsimple_log_ilog_method_entry);

	/**
	 * debug
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_log_ilog_ce, SL("DEBUG"), "debug");

	/**
	 * info
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_log_ilog_ce, SL("INFO"), "info");

	/**
	 * notice
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_log_ilog_ce, SL("NOTICE"), "notice");

	/**
	 * warning
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_log_ilog_ce, SL("WARNING"), "warning");

	/**
	 * error
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_log_ilog_ce, SL("ERROR"), "error");

	/**
	 * critical
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_log_ilog_ce, SL("CRITICAL"), "critical");

	/**
	 * alert
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_log_ilog_ce, SL("ALERT"), "alert");

	/**
	 * emergency
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_log_ilog_ce, SL("EMERGENCY"), "emergency");

	/**
	 * sql
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(queryyetsimple_log_ilog_ce, SL("SQL"), "sql");

	return SUCCESS;

}

/**
 * 记录错误消息并写入
 *
 * @param string $strLevel 日志类型
 * @param string $strMessage 应该被记录的错误信息
 * @param array $arrContext
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Log_Ilog, write);

/**
 * 保存日志信息
 *
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Log_Ilog, save);

/**
 * 注册日志过滤器
 *
 * @param callable $calFilter
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Log_Ilog, registerFilter);

/**
 * 注册日志处理器
 *
 * @param callable $calProcessor
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Log_Ilog, registerProcessor);

/**
 * 清理日志记录
 *
 * @param string $strLevel
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Log_Ilog, clear);

/**
 * 获取日志记录
 *
 * @param string $strLevel
 * @return array
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Log_Ilog, get);

/**
 * 获取日志记录数量
 *
 * @param string $strLevel
 * @return int
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Log_Ilog, count);

