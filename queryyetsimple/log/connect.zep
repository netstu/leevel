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
use Queryyetsimple\Option\IClass;

/**
 * aconnect 驱动抽象类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
abstract class Connect implements IClass
{

    /**
     * 配置
     *
     * @var array
     */
    protected option = [];

    /**
     * 构造函数
     *
     * @param array $option
     * @return void
     */
    public function __construct(array option = [])
    {
        this->options(option);
    }

    /**
     * 修改单个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function option(string name, var value)
    {
        if ! is_string(name) {
            throw new InvalidArgumentException("Option set name must be a string.");
        }
        let this->option[name] = value;
        return this;
    }

    /**
     * 修改数组配置
     *
     * @param string $name
     * @param array $value
     * @return $this
     */
    public function optionArray(string name, array value)
    {
        return this->option(name, array_merge(this->getOption(name), value));
    }

    /**
     * 修改多个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function options(array option = [])
    {
    	var name, value;

        if empty option {
            return this;
        }

        for name, value in option {
        	this->option(name, value);
        }

        return this;
    }

    /**
     * 获取单个配置
     *
     * @param string $name
     * @param mixed $defaults
     * @return mixed
     */
    public function getOption(string name, var defaults = null)
    {
        return isset(this->option[name]) ? this->option[name] : defaults;
    }

    /**
     * 获取所有配置
     *
     * @param array $option
     * @return mixed
     */
    public function getOptions(array option = [])
    {
    	if ! empty option {
    		return array_merge(this->option, option);
    	} else {
    		return this->option;
    	}
    }

    /**
     * 删除单个配置
     *
     * @param string $name
     * @return $this
     */
    public function deleteOption(string name)
    {
        if isset this->option[name] {
            unset(this->option[name]);
        }

        return this;
    }

    /**
     * 删除多个配置
     *
     * @param array $option
     * @return $this
     */
    public function deleteOptions(array option = [])
    {
    	var key;

        if ! empty option {
            return this;
        }

        for key in option {
        	this->deleteOption(key);
        }

        return this;
    }

    /**
     * 验证日志文件大小
     *
     * @param string $filepath
     * @return void
     */
    protected function checkSize(string filepath)
    {
    	var filedir;

    	let filedir = dirname(filepath);

        // 如果不是文件，则创建
        if ! is_file(filepath) && ! is_dir(filedir) && ! mkdir(filedir, 0777, true) {
            throw new RuntimeException(sprintf("Unable to create log file：%s.", filepath));
        }

        // 检测日志文件大小，超过配置大小则备份日志文件重新生成
        if is_file(filepath) && floor(this->getOption("size")) <= filesize(filepath) {
            rename(filepath, filedir . "/" . date("Y-m-d H.i.s") . "~@" . basename(filepath));
        }
    }
    
    /**
     * 获取日志路径
     *
     * @param string $level
     * @param string $filepath
     * @return string
     */
    protected function getPath(string level = "")
    {
        var filepath;

        // 不存在路径，则直接使用项目默认路径
        if empty filepath {
            if ! this->getOption("path") {
                throw new RuntimeException("Default path for log has not specified.");
            }
            let filepath =  this->getOption("path") . "/" . (level ? level . "/" : "") . date(this->getOption("name")) . ".log";
        }

        return filepath;
    }
}
