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

use Queryyetsimple\Log\Log;
use queryyetsimple\Log\File;
use Queryyetsimple\Log\Monolog;
use Queryyetsimple\Support\Manager as support_manager;

/**
 * log 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
class Manager extends support_manager
{

    /**
     * 取得配置命名空间
     *
     * @return string
     */
    protected function getOptionNamespace()
    {
        return "log";
    }

    /**
     * 创建连接对象
     *
     * @param object $objConnect
     * @return object
     */
    protected function createConnect(var objConnect)
    {
        return new Log(objConnect, this->getOptionCommon());
    }

    /**
     * 创建 file 日志驱动
     *
     * @param array $arrOption
     * @return \queryyetsimple\log\file
     */
    protected function makeConnectFile(array arrOption = [])
    {
        return new File(this->getOption("file", arrOption));
    }

    /**
     * 创建 monolog 日志驱动
     *
     * @param array $arrOption
     * @return \queryyetsimple\log\monolog
     */
    protected function makeConnectMonolog(array arrOption = [])
    {
        return new Monolog(this->getOption("monolog", arrOption));
    }
}
