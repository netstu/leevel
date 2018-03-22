/*
 * This file is part of the ************************ package.
 * _____________                           _______________
 *  ______/     \__  _____  ____  ______  / /_  _________
 *   ____/ __   / / / / _ \/ __`\/ / __ \/ __ \/ __ \___
 *    __/ / /  / /_/ /  __/ /  \  / /_/ / / / / /_/ /__
 *      \_\ \_/\____/\___/_/   / / .___/_/ /_/ .___/
 *         \_\                /_/_/         /_/
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
use Queryyetsimple\Log\Connect;
use Queryyetsimple\Log\IConnect;
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
class Monolog extends Connect implements IConnect
{

	/**
	 * Monolog
	 *
	 * @var \Monolog\Logger
	 */
	protected monolog;

	/**
	 * 配置
	 *
	 * @var array
	 */
	protected option = [
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
	protected supportLevel = [
		// ILog::DEBUG : Logger::DEBUG,
		// ILog::INFO : Logger::INFO,
		// ILog::NOTICE : Logger::NOTICE,
		// ILog::WARNING : Logger::WARNING,
		// ILog::ERROR : Logger::ERROR,
		// ILog::CRITICAL : Logger::CRITICAL,
		// ILog::ALERT : Logger::ALERT,
		// ILog::EMERGENCY : Logger::EMERGENCY
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
	 * @param array $option
	 * @return void
	 */
	public function __construct(array option = [])
	{
		var type, make;

		parent::__construct(option);

		let this->monolog = new Logger(this->getOption("channel"));

		for type in this->getOption("type") {
			let make = "make" . ucwords(this->camelize(type)) . "Handler";
			this->{make}();
		}
	}

	/**
	 * 注册文件 handler
	 *
	 * @param string $path
	 * @param string $level
	 * @return void
	 */
	public function file(string path, string level = ilog::DEBUG)
	{
		var handler;
		let handler = new StreamHandler(path, this->parseMonologLevel(level));
		this->monolog->pushHandler(handler);
		handler->setFormatter(this->getDefaultFormatter());
	}

	/**
	 * 注册每日文件 handler
	 *
	 * @param string $path
	 * @param int $days
	 * @param string $level
	 * @return void
	 */
	public function dailyFile(string path, int days = 0, string level = ilog::DEBUG)
	{
		var handler;
		let handler = new RotatingFileHandler(path, days, this->parseMonologLevel(level));
		this->monolog->pushHandler(handler);
		handler->setFormatter(this->getDefaultFormatter());
	}

	/**
	 * 注册系统 handler
	 *
	 * @param string $name
	 * @param string $level
	 * @return \Psr\Log\LoggerInterface
	 */
	public function syslog(string name = "queryphp", string level = ilog::DEBUG)
	{
		var handler;
		let handler = new SyslogHandler(name, LOG_USER, level);
		return this->monolog->pushHandler(handler);
	}

	/**
	 * 注册 error_log handler
	 *
	 * @param string $level
	 * @param int $messageType
	 * @return void
	 */
	public function errorLog(string level = ilog::DEBUG, int messageType = 0/* ErrorLogHandler::OPERATING_SYSTEM */)
	{
		var handler;
		let handler = new ErrorLogHandler(messageType, this->parseMonologLevel(level));
		this->monolog->pushHandler(handler);
		handler->setFormatter(this->getDefaultFormatter());
	}

	/**
	 * monolog 回调
	 *
	 * @param callable|null $callback
	 * @return $this
	 */
	public function monolog(var callback = null)
	{
		if is_callable(callback) {
			call_user_func_array(callback, [
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
		return this->monolog;
	}

	/**
	 * 日志写入接口
	 *
	 * @param array $data
	 * @return void
	 */
	public function save(array data)
	{
		var item, level;

		let level = array_keys(this->supportLevel);

		for item in data {
			if ! in_array(item[0], level) {
				let level = "debug";
			} else {
				let level = item[0];
			}

			this->monolog->{level}(item[1], item[2]);
		}
	}

	/**
	 * 初始化文件 handler
	 *
	 * @return void
	 */
	protected function makeFileHandler()
	{
		var path;
		let path = this->getPath();
		this->checkSize(path);
		this->file(path);
	}

	/**
	 * 初始化每日文件 handler
	 *
	 * @return void
	 */
	protected function makeDailyFileHandler()
	{
		var path;
		let path = this->getPath();
		this->checkSize(this->getDailyFilePath(path));
		this->dailyFile(path);
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
	 * @param string $path
	 * @return void
	 */
	protected function getDailyFilePath(string path)
	{
		var ext;
		let ext = pathinfo(path, PATHINFO_EXTENSION);
		if ext {
			let path = substr(path, 0, strrpos(path, "." . ext));
		}
		return path . date("-Y-m-d") . (ext ? "." . ext : "");
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
	 * @param string $level
	 * @return int
	 */
	protected function parseMonologLevel(string level)
	{
		if isset(this->supportLevel[level]) {
			return this->supportLevel[level];
		}
		return this->supportLevel[ilog::DEBUG];
	}

	/**
	 * 下划线转驼峰
	 *
	 * @param string $value
	 * @param string $separator
	 * @return string
	 */
	protected function camelize(string value, string separator = "_")
	{
		let value = separator . str_replace(separator, " ", strtolower(value));
		return ltrim(str_replace(" ", "", ucwords(value)), separator);
	}
}
