/*
 * This file is part of the ************************ package.
 * ##########################################################
 * #   ____                          ______  _   _ ______   #
 * #  /     \       ___  _ __  _   _ | ___ \| | | || ___ \  #
 * # |   (  ||(_)| / _ \| '__|| | | || |_/ /| |_| || |_/ /  #
 * #  \____/ |___||  __/| |   | |_| ||  __/ |  _  ||  __/   #
 * #       \__   | \___ |_|    \__  || |    | | | || |      #
 * #     Query Yet Simple      __/  |\_|    |_| |_|\_|      #
 * #                          |___ /  Since 2010.10.03      #
 * ##########################################################
 *
 * The PHP Framework For Code Poem As Free As Wind. <Query Yet Simple>
 * (c) 2010-2018 http://queryphp.com All rights reserved.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
namespace Queryyetsimple\Log;

// todo: zephir 加载无法通过编译，后面回来看看解决 @ 2018.01.06
use Psr\Log\LoggerInterface;

/**
 * ilog 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
interface Ilog /* extends LoggerInterface */
{

    /**
     * debug
     *
     * @var string
     */
    const DEBUG = "debug";

    /**
     * info
     *
     * @var string
     */
    const INFO = "info";

    /**
     * notice
     *
     * @var string
     */
    const NOTICE = "notice";

    /**
     * warning
     *
     * @var string
     */
    const WARNING = "warning";

    /**
     * error
     *
     * @var string
     */
    const ERROR = "error";

    /**
     * critical
     *
     * @var string
     */
    const CRITICAL = "critical";

    /**
     * alert
     *
     * @var string
     */
    const ALERT = "alert";

    /**
     * emergency
     *
     * @var string
     */
    const EMERGENCY = "emergency";

    /**
     * sql
     *
     * @var string
     */
    const SQL = "sql";

    /**
     * 记录错误消息并写入
     *
     * @param string $strLevel 日志类型
     * @param string $strMessage 应该被记录的错误信息
     * @param array $arrContext
     * @return void
     */
    public function write(string strLevel, string strMessage, array arrContext = []);

    /**
     * 保存日志信息
     *
     * @return void
     */
    public function save();

    /**
     * 注册日志过滤器
     *
     * @param callable $calFilter
     * @return void
     */
    public function registerFilter(var calFilter);

    /**
     * 注册日志处理器
     *
     * @param callable $calProcessor
     * @return void
     */
    public function registerProcessor(var calProcessor);

    /**
     * 清理日志记录
     *
     * @param string $strLevel
     * @return int
     */
    public function clear(string strLevel = null);

    /**
     * 获取日志记录
     *
     * @param string $strLevel
     * @return array
     */
    public function get(string strLevel = null);

    /**
     * 获取日志记录数量
     *
     * @param string $strLevel
     * @return int
     */
    public function count(string strLevel = null);
}
