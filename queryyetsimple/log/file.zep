namespace Queryyetsimple\Log;

use RuntimeException;
use Queryyetsimple\Log\Aconnect;
use Queryyetsimple\Log\Iconnect;

class File extends Aconnect implements Iconnect
{

    protected arrOption = [
        "name" : "Y-m-d H",
        "size" : 2097152,
        "path" : ""
    ];

    public function save(array arrData)
    {
        var strDestination, arrItem;

        // 保存日志
        let strDestination = this->getPath(arrData[0][0]);
        this->checkSize(strDestination);

        // 记录到系统
        for arrItem in arrData {
            error_log(this->formatMessage(arrItem[1], arrItem[2]) . PHP_EOL, 3, strDestination);
        }
    }

    protected function formatMessage(string strMessage, array arrContext = [])
    {
        return strMessage . " " . json_encode(arrContext, JSON_UNESCAPED_UNICODE);
    }
}
