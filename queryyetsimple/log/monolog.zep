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

class Monolog extends Aconnect implements Iconnect
{

    protected objMonolog;

    protected arrOption = [
        "type" : [
            "file"
        ],
        "channel" : "Q",
        "name" : "Y-m-d H",
        "size" : 2097152,
        "path" : ""
    ];

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

    public function file(string strPath, string strLevel = ilog::DEBUG)
    {
        var objHandler;
        let objHandler = new StreamHandler(strPath, this->parseMonologLevel(strLevel));
        this->objMonolog->pushHandler(objHandler);
        objHandler->setFormatter(this->getDefaultFormatter());
    }

    public function dailyFile(string strPath, int intDays = 0, string strLevel = ilog::DEBUG)
    {
        var objHandler;
        let objHandler = new RotatingFileHandler(strPath, intDays, this->parseMonologLevel(strLevel));
        this->objMonolog->pushHandler(objHandler);
        objHandler->setFormatter(this->getDefaultFormatter());
    }

    public function syslog(string strName = "queryphp", string strLevel = ilog::DEBUG)
    {
    	var objHandler;
    	let objHandler = new SyslogHandler(strName, LOG_USER, strLevel);
        return this->objMonolog->pushHandler(objHandler);
    }

    public function errorLog(string strLevel = ilog::DEBUG, int intMessageType = 0/* ErrorLogHandler::OPERATING_SYSTEM */)
    {
        var objHandler;
        let objHandler = new ErrorLogHandler(intMessageType, this->parseMonologLevel(strLevel));
        this->objMonolog->pushHandler(objHandler);
        objHandler->setFormatter(this->getDefaultFormatter());
    }

    public function monolog(var mixCallback = null)
    {
        if is_callable(mixCallback) {
            call_user_func_array(mixCallback, [
                this
            ]);
        }

        return this;
    }

    public function getMonolog()
    {
        return this->objMonolog;
    }

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

    protected function makeFileHandler()
    {
        var strPath;
        let strPath = this->getPath();
        this->checkSize(strPath);
        this->file(strPath);
    }

    protected function makeDailyFileHandler()
    {
        var strPath;
        let strPath = this->getPath();
        this->checkSize(this->getDailyFilePath(strPath));
        this->dailyFile(strPath);
    }

    protected function makeSyslogHandler()
    {
        this->syslog();
    }

    protected function makeErrorLogHandler()
    {
        this->errorLog();
    }

    protected function getDailyFilePath(string strPath)
    {
        var strExt;
        let strExt = pathinfo(strPath, PATHINFO_EXTENSION);
        if strExt {
            let strPath = substr(strPath, 0, strrpos(strPath, "." . strExt));
        }
        return strPath . date("-Y-m-d") . (strExt ? "." . strExt : "");
    }

    protected function getDefaultFormatter()
    {
        return new LineFormatter(null, null, true, true);
    }

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
