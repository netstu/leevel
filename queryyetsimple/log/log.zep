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

use RuntimeException;
use Queryyetsimple\Log\Ilog;
use InvalidArgumentException;
use Queryyetsimple\Log\Iconnect;
use Queryyetsimple\Support\Ijson;
use Queryyetsimple\Support\Iarray;

/**
 * 日志仓储
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
class Log implements Ilog
{

    /**
     * 存储连接对象
     *
     * @var \queryyetsimple\log\iconnect
     */
    protected oConnect;

    /**
     * 当前记录的日志信息
     *
     * @var array
     */
    protected arrLog = [];

    /**
     * 日志过滤器
     *
     * @var callable
     */
    protected calFilter;

    /**
     * 日志处理器
     *
     * @var callable
     */
    protected calProcessor;

    /**
     * 配置
     *
     * @var array
     */
    protected arrOption = [
        "enabled" : true,
        "level" : [
            self::DEBUG,
            self::INFO,
            self::NOTICE,
            self::WARNING,
            self::ERROR,
            self::CRITICAL,
            self::ALERT,
            self::EMERGENCY,
            self::SQL
        ],
        "time_format" : "[Y-m-d H:i]"
    ];

    /**
     * 构造函数
     *
     * @param \queryyetsimple\log\iconnect $oConnect
     * @param array $arrOption
     * @return void
     */
    public function __construct(<Iconnect> oConnect, array arrOption = [])
    {
        let this->oConnect =  oConnect;
        this->options(arrOption);
    }

    // ######################################################
    // ------ 实现 \Psr\Log\LoggerInterface 接口 start -------
    // ######################################################

    /**
     * 记录 emergency 日志
     *
     * @param string $mixMessage
     * @param array $arrContext
     * @param boolean $booWrite
     * @return array
     */
    public function emergency(var mixMessage, array arrContext = [], boolean booWrite = false)
    {
    	var strAction;
    	let strAction = booWrite ? "write" : "log";
        return this->{strAction}(self::EMERGENCY, mixMessage, arrContext);
    }

    /**
     * 记录 alert 日志
     *
     * @param string $mixMessage
     * @param array $arrContext
     * @param boolean $booWrite
     * @return array
     */
    public function alert(var mixMessage, array arrContext = [], boolean booWrite = false)
    {
    	var strAction;
    	let strAction = booWrite ? "write" : "log";
        return this->{strAction}(self::ALERT, mixMessage, arrContext);
    }

    /**
     * 记录 critical 日志
     *
     * @param string $mixMessage
     * @param array $arrContext
     * @param boolean $booWrite
     * @return array
     */
    public function critical(var mixMessage, array arrContext = [], boolean booWrite = false)
    {
    	var strAction;
    	let strAction = booWrite ? "write" : "log";
        return this->{strAction}(self::CRITICAL, mixMessage, arrContext);
    }

    /**
     * 记录 error 日志
     *
     * @param string $mixMessage
     * @param array $arrContext
     * @param boolean $booWrite
     * @return array
     */
    public function error(var mixMessage, array arrContext = [], boolean booWrite = false)
    {
    	var strAction;
    	let strAction = booWrite ? "write" : "log";
        return this->{strAction}(self::ERROR, mixMessage, arrContext);
    }

    /**
     * 记录 warning 日志
     *
     * @param string $mixMessage
     * @param array $arrContext
     * @param boolean $booWrite
     * @return array
     */
    public function warning(var mixMessage, array arrContext = [], boolean booWrite = false)
    {
    	var strAction;
    	let strAction = booWrite ? "write" : "log";
        return this->{strAction}(self::WARNING, mixMessage, arrContext);
    }

    /**
     * 记录 notice 日志
     *
     * @param string $mixMessage
     * @param array $arrContext
     * @param boolean $booWrite
     * @return array
     */
    public function notice(var mixMessage, array arrContext = [], boolean booWrite = false)
    {
    	var strAction;
    	let strAction = booWrite ? "write" : "log";
        return this->{strAction}(self::NOTICE, mixMessage, arrContext);
    }

    /**
     * 记录 info 日志
     *
     * @param string $mixMessage
     * @param array $arrContext
     * @param boolean $booWrite
     * @return array
     */
    public function info(var mixMessage, array arrContext = [], boolean booWrite = false)
    {
    	var strAction;
    	let strAction = booWrite ? "write" : "log";
        return this->{strAction}(self::INFO, mixMessage, arrContext);
    }

    /**
     * 记录 debug 日志
     *
     * @param string $mixMessage
     * @param array $arrContext
     * @param boolean $booWrite
     * @return array
     */
    public function debug(var mixMessage, array arrContext = [], boolean booWrite = false)
    {
    	var strAction;
    	let strAction = booWrite ? "write" : "log";
        return this->{strAction}(self::DEBUG, mixMessage, arrContext);
    }

    /**
     * 记录日志
     *
     * @param string $strLevel
     * @param mixed $mixMessage
     * @param array $arrContext
     * @return array
     */
    public function log(string strLevel, var mixMessage, array arrContext = [])
    {
        var arrData;

        // 是否开启日志
        if ! this->getOption("enabled") {
            return;
        }

        // 只记录系统允许的日志级别
        if ! in_array(strLevel, this->getOption("level")) {
            return;
        }

        let mixMessage = date(this->getOption("time_format")) . this->formatMessage(mixMessage);

        let arrData = [
            strLevel,
            mixMessage,
            arrContext
        ];

        // 执行过滤器
        if typeof this->calFilter != "null" && call_user_func_array(this->calFilter, arrData) === false {
            return;
        }

        // 记录到内存方便后期调用
        if ! isset this->arrLog[strLevel] {
            let this->arrLog[strLevel] = [];
        }
        let this->arrLog[strLevel][] = arrData;

        return arrData;
    }

    // ######################################################
    // ------- 实现 \Psr\Log\LoggerInterface 接口 end --------
    // ######################################################

    /**
     * 记录错误消息并写入
     *
     * @param string $strLevel 日志类型
     * @param string $strMessage 应该被记录的错误信息
     * @param array $arrContext
     * @return void
     */
    public function write(string strLevel, string strMessage, array arrContext = [])
    {
        this->saveStore([
            this->log(strLevel, strMessage, arrContext)
        ]);
    }

    /**
     * 保存日志信息
     *
     * @return void
     */
    public function save()
    {
        var arrData;

        if ! this->arrLog {
            return;
        }

        for arrData in this->arrLog {
            this->saveStore(arrData);
        }

        this->clear();
    }

    /**
     * 注册日志过滤器
     *
     * @param callable $calFilter
     * @return void
     */
    public function registerFilter(var calFilter)
    {
    	if ! is_callable(calFilter) {
    		throw new InvalidArgumentException("Filter must be callable.");
    	}
        let this->calFilter = calFilter;
    }

    /**
     * 注册日志处理器
     *
     * @param callable $calProcessor
     * @return void
     */
    public function registerProcessor(var calProcessor)
    {
    	if ! is_callable(calProcessor) {
    		throw new InvalidArgumentException("Processor must be callable.");
    	}
        let this->calProcessor = calProcessor;
    }

    /**
     * 清理日志记录
     *
     * @param string $strLevel
     * @return int
     */
    public function clear(string strLevel = null)
    {
        var nCount;

        if strLevel && isset this->arrLog[strLevel] {
            let nCount = count(this->arrLog[strLevel]);
            let this->arrLog[strLevel] = [];
        } else {
            let nCount = count(this->arrLog);
            let this->arrLog = [];
        }

        return nCount;
    }

    /**
     * 获取日志记录
     *
     * @param string $strLevel
     * @return array
     */
    public function get(string strLevel = null)
    {
        if strLevel && isset this->arrLog[strLevel] {
            return this->arrLog[strLevel];
        } else {
            return this->arrLog;
        }
    }

    /**
     * 获取日志记录数量
     *
     * @param string $strLevel
     * @return int
     */
    public function count(string strLevel = null)
    {
        if strLevel && isset this->arrLog[strLevel] {
            return count(this->arrLog[strLevel]);
        } else {
            return count(this->arrLog);
        }
    }

    /**
     * 修改单个配置
     *
     * @param string $strName
     * @param mixed $mixValue
     * @return $this
     */
    public function option(string strName, var mixValue)
    {
        if ! is_string(strName) {
            throw new InvalidArgumentException("Option set name must be a string.");
        }
        let this->arrOption[strName] = mixValue;
        return this;
    }

    /**
     * 修改数组配置
     *
     * @param string $strName
     * @param array $arrValue
     * @return $this
     */
    public function optionArray(string $strName, array $arrValue)
    {
        return this->option(strName, array_merge(this->getOption(strName), arrValue));
    }

    /**
     * 修改多个配置
     *
     * @param string $strName
     * @param mixed $mixValue
     * @return $this
     */
    public function options(array $arrOption = [])
    {
    	var strName, mixValue;

        if empty arrOption {
            return this;
        }

        for strName, mixValue in arrOption {
        	this->option(strName, mixValue);
        }

        return this;
    }

    /**
     * 获取单个配置
     *
     * @param string $strName
     * @param mixed $mixDefault
     * @return mixed
     */
    public function getOption(string strName, var mixDefault = null)
    {
        return isset(this->arrOption[strName]) ? this->arrOption[strName] : mixDefault;
    }

    /**
     * 获取所有配置
     *
     * @param array $arrOption
     * @return mixed
     */
    public function getOptions(array arrOption = [])
    {
    	if ! empty arrOption {
    		return array_merge(this->arrOption, arrOption);
    	} else {
    		return this->arrOption;
    	}
    }

    /**
     * 删除单个配置
     *
     * @param string $strName
     * @return $this
     */
    public function deleteOption(string strName)
    {
        if isset this->arrOption[strName] {
            unset(this->arrOption[strName]);
        }

        return this;
    }

    /**
     * 删除多个配置
     *
     * @param array $arrOption
     * @return $this
     */
    public function deleteOptions(array arrOption = [])
    {
    	var strOption;

        if ! empty arrOption {
            return this;
        }

        for strOption in arrOption {
        	this->deleteOption(strOption);
        }

        return this;
    }

    /**
     * 存储日志
     *
     * @param array $arrData
     * @return void
     */
    protected function saveStore(array arrData)
    {
        // 执行处理器
        if typeof this->calProcessor != "null" {
            call_user_func_array(this->calProcessor, arrData);
        }
        this->oConnect->save(arrData);
    }

    /**
     * 格式化日志消息
     *
     * @param mixed $mixMessage
     * @return mixed
     */
    protected function formatMessage(var mixMessage)
    {
        if typeof mixMessage == "array" {
            return var_export(mixMessage, true);
        } elseif typeof mixMessage == "object" && mixMessage instanceof Ijson {
            return mixMessage->toJson();
        } elseif typeof mixMessage == "object" && mixMessage instanceof Iarray {
            return var_export(mixMessage->toArray(), true);
        } elseif is_scalar(mixMessage) {
            return mixMessage;
        }
        
        throw new RuntimeException("Message is invalid");
    }

    /**
     * call 
     *
     * @param string $sMethod
     * @param array $arrArgs
     * @return mixed
     */
    public function __call(string sMethod, array arrArgs)
    {
    	return call_user_func_array([this->oConnect, sMethod], arrArgs);
    }
}
