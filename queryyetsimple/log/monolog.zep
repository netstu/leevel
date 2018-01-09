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

use Monolog\Logger;
use RuntimeException;
use InvalidArgumentException;
use Queryyetsimple\Log\Aconnect;
use Queryyetsimple\Log\Iconnect;
use Monolog\Handler\StreamHandler;
use Monolog\Handler\SyslogHandler;
use Monolog\Handler\ErrorLogHandler;
use Monolog\Formatter\LineFormatter;
use Monolog\Handler\RotatingFileHandler;

/**
 * log.monolog
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.08
 * @version 1.0
 */
class Monolog extends Aconnect implements Iconnect
{

    /**
     * Monolog
     *
     * @var \Monolog\Logger
     */
    protected objMonolog;

    /**
     * 配置
     *
     * @var array
     */
    protected arrOption = [
        "type" : [
            "file"
        ],
        "channel" : "Q",
        "name" : "Y-m-d H",
        "size" : 2097152,
        "path" : ""
    ];

    /**
     * Monolog 支持日志级别
     *
     * @var array
     */
    protected arrSupportLevel = [
        // ilog::DEBUG : Logger::DEBUG,
        // ilog::INFO : Logger::INFO,
        // ilog::NOTICE : Logger::NOTICE,
        // ilog::WARNING : Logger::WARNING,
        // ilog::ERROR : Logger::ERROR,
        // ilog::CRITICAL : Logger::CRITICAL,
        // ilog::ALERT : Logger::ALERT,
        // ilog::EMERGENCY : Logger::EMERGENCY
        "debug" : 100,
        "info" : 200,
        "notice" : 250,
        "warning" : 300,
        "error" : 400,
        "critical" : 500,
        "alert" : 550,
        "emergency" : 600
    ];

    /**
     * 构造函数
     *
     * @param array $arrOption
     * @return void
     */
    public function __construct(array arrOption = [])
    {
        var strType, strMake;

        parent::__construct(arrOption);

        let this->objMonolog = new Logger(this->getOption("channel"));

        for strType in this->getOption("type") {
        	let strMake = "make" . ucwords(this->camelize(strType)) . "Handler";
            this->{strMake}();
        }
    }

    /**
     * 注册文件 handler
     *
     * @param string $strPath
     * @param string $strLevel
     * @return void
     */
    public function file(string strPath, string strLevel = ilog::DEBUG)
    {
        var objHandler;
        let objHandler = new StreamHandler(strPath, this->parseMonologLevel(strLevel));
        this->objMonolog->pushHandler(objHandler);
        objHandler->setFormatter(this->getDefaultFormatter());
    }

    /**
     * 注册每日文件 handler
     *
     * @param string $strPath
     * @param int $intDays
     * @param string $level
     * @return void
     */
    public function dailyFile(string strPath, int intDays = 0, string strLevel = ilog::DEBUG)
    {
        var objHandler;
        let objHandler = new RotatingFileHandler(strPath, intDays, this->parseMonologLevel(strLevel));
        this->objMonolog->pushHandler(objHandler);
        objHandler->setFormatter(this->getDefaultFormatter());
    }

    /**
     * 注册系统 handler
     *
     * @param string $strName
     * @param string $strLevel
     * @return \Psr\Log\LoggerInterface
     */
    public function syslog(string strName = "queryphp", string strLevel = ilog::DEBUG)
    {
    	var objHandler;
    	let objHandler = new SyslogHandler(strName, LOG_USER, strLevel);
        return this->objMonolog->pushHandler(objHandler);
    }

    /**
     * 注册 error_log handler
     *
     * @param string $strLevel
     * @param int $intMessageType
     * @return void
     */
    public function errorLog(string strLevel = ilog::DEBUG, int intMessageType = 0/* ErrorLogHandler::OPERATING_SYSTEM */)
    {
        var objHandler;
        let objHandler = new ErrorLogHandler(intMessageType, this->parseMonologLevel(strLevel));
        this->objMonolog->pushHandler(objHandler);
        objHandler->setFormatter(this->getDefaultFormatter());
    }

    /**
     * monolog 回调
     *
     * @param callable|null $mixCallback
     * @return $this
     */
    public function monolog(var mixCallback = null)
    {
        if is_callable(mixCallback) {
            call_user_func_array(mixCallback, [
                this
            ]);
        }

        return this;
    }

    /**
     * 取得 Monolog
     *
     * @return \Monolog\Logger
     */
    public function getMonolog()
    {
        return this->objMonolog;
    }

    /**
     * 日志写入接口
     *
     * @param array $arrData
     * @return void
     */
    public function save(array arrData)
    {
        var arrItem, arrLevel, strLevel;

        let arrLevel = array_keys(this->arrSupportLevel);

        for arrItem in arrData {
        	if ! in_array(arrItem[0], arrLevel) {
                let strLevel = "debug";
            } else {
            	let strLevel = arrItem[0];
            }

            this->objMonolog->{strLevel}(arrItem[1], arrItem[2]);
        }
    }

    /**
     * 初始化文件 handler
     *
     * @return void
     */
    protected function makeFileHandler()
    {
        var strPath;
        let strPath = this->getPath();
        this->checkSize(strPath);
        this->file(strPath);
    }

    /**
     * 初始化每日文件 handler
     *
     * @return void
     */
    protected function makeDailyFileHandler()
    {
        var strPath;
        let strPath = this->getPath();
        this->checkSize(this->getDailyFilePath(strPath));
        this->dailyFile(strPath);
    }

    /**
     * 初始化系统 handler
     *
     * @return void
     */
    protected function makeSyslogHandler()
    {
        this->syslog();
    }

    /**
     * 初始化 error_log handler
     *
     * @return void
     */
    protected function makeErrorLogHandler()
    {
        this->errorLog();
    }

    /**
     * 每日文件真实路径
     *
     * @param string $strPath
     * @return void
     */
    protected function getDailyFilePath(string strPath)
    {
        var strExt;
        let strExt = pathinfo(strPath, PATHINFO_EXTENSION);
        if strExt {
            let strPath = substr(strPath, 0, strrpos(strPath, "." . strExt));
        }
        return strPath . date("-Y-m-d") . (strExt ? "." . strExt : "");
    }

    /**
     * 默认格式化
     *
     * @return \Monolog\Formatter\LineFormatter
     */
    protected function getDefaultFormatter()
    {
        return new LineFormatter(null, null, true, true);
    }

    /**
     * 获取 Monolog 级别
     * 不支持级别归并到 DEBUG
     *
     * @param string $strLevel
     * @return int
     */
    protected function parseMonologLevel(string strLevel)
    {
        if isset(this->arrSupportLevel[strLevel]) {
            return this->arrSupportLevel[strLevel];
        }
        return this->arrSupportLevel[ilog::DEBUG];
    }

    /**
     * 下划线转驼峰
     *
     * @param string $strValue
     * @param string $strSeparator
     * @return string
     */
    protected function camelize(string strValue, string strSeparator = "_")
    {
        let strValue = strSeparator . str_replace(strSeparator, " ", strtolower(strValue));
        return ltrim(str_replace(" ", "", ucwords(strValue)), strSeparator);
    }
}
