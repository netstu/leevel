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
use InvalidArgumentException;

/**
 * aconnect 驱动抽象类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
abstract class Aconnect
{

    /**
     * 配置
     *
     * @var array
     */
    protected arrOption = [];

    /**
     * 构造函数
     *
     * @param array $arrOption
     * @return void
     */
    public function __construct(array arrOption = [])
    {
        this->options(arrOption);
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
     * 验证日志文件大小
     *
     * @param string $sFilePath
     * @return void
     */
    protected function checkSize(string sFilePath)
    {
    	var sFileDir;

    	let sFileDir = dirname(sFilePath);

        // 如果不是文件，则创建
        if ! is_file(sFilePath) && ! is_dir(sFileDir) && ! mkdir(sFileDir, 0777, true) {
            throw new RuntimeException(sprintf("Unable to create log file：%s.", sFilePath));
        }

        // 检测日志文件大小，超过配置大小则备份日志文件重新生成
        if is_file(sFilePath) && floor(this->getOption("size")) <= filesize(sFilePath) {
            rename(sFilePath, sFileDir . "/" . date("Y-m-d H.i.s") . "~@" . basename(sFilePath));
        }
    }
    
    /**
     * 获取日志路径
     *
     * @param string $strLevel
     * @param string $sFilePath
     * @return string
     */
    protected function getPath(string strLevel = "")
    {
        var sFilePath;

        // 不存在路径，则直接使用项目默认路径
        if empty sFilePath {
            if ! this->getOption("path") {
                throw new RuntimeException("Default path for log has not specified.");
            }
            let sFilePath =  this->getOption("path") . "/" . (strLevel ? strLevel . "/" : "") . date(this->getOption("name")) . ".log";
        }

        return sFilePath;
    }
}
