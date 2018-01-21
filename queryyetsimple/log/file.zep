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
use Queryyetsimple\Log\Connect;
use Queryyetsimple\Log\IConnect;

/**
 * log.file
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.08
 * @version 1.0
 */
class File extends Connect implements IConnect
{

    /**
     * 配置
     *
     * @var array
     */
    protected option = [
        "name" : "Y-m-d H",
        "size" : 2097152,
        "path" : ""
    ];

    /**
     * 日志写入接口
     *
     * @param array $datas
     * @return void
     */
    public function save(array datas)
    {
        var filepath, item;

        // 保存日志
        let filepath = this->getPath(datas[0][0]);
        this->checkSize(filepath);

        // 记录到系统
        for item in datas {
            error_log(this->formatMessage(item[1], item[2]) . PHP_EOL, 3, filepath);
        }
    }

    /**
     * 格式化日志信息
     *
     * @param string $message 应该被记录的错误信息
     * @param array $contexts
     * @return string
     */
    protected function formatMessage(string message, array contexts = [])
    {
        return message . " " . json_encode(contexts, JSON_UNESCAPED_UNICODE);
    }
}
