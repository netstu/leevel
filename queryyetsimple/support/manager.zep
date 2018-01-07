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
namespace Queryyetsimple\Support;

use Exception;
use InvalidArgumentException;
use Queryyetsimple\Support\Icontainer;

/**
 * manager 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
abstract class Manager
{

    /**
     * IOC Container
     *
     * @var \queryyetsimple\support\icontainer
     */
    protected objContainer;

    /**
     * 连接对象
     *
     * @var object[]
     */
    protected arrConnect;

    /**
     * 构造函数
     *
     * @param \queryyetsimple\support\icontainer $objContainer
     * @return void
     */
    public function __construct(<Icontainer> objContainer)
    {
        let this->objContainer = objContainer;
    }

    /**
     * 返回 IOC 容器
     *
     * @return \queryyetsimple\support\icontainer
     */
    public function container()
    {
        return this->objContainer;
    }

    /**
     * 连接 connect 并返回连接对象
     *
     * @param array|string|null $mixOption
     * @return object
     */
    public function connect(var mixOption = null)
    {
        var strUnique, strDriver, arrTemp;

        let arrTemp = this->parseOptionAndUnique(mixOption);
        let mixOption = array_shift(arrTemp);
        let strUnique = array_shift(arrTemp);

        if isset this->arrConnect[strUnique] {
            return this->arrConnect[strUnique];
        }

        let strDriver = isset mixOption["driver"] ? mixOption["driver"] : this->getDefaultDriver();

        let this->arrConnect[strUnique] = this->makeConnect(strDriver, mixOption);

        return this->arrConnect[strUnique];
    }

    /**
     * 重新连接
     *
     * @param array|string $mixOption
     * @return object
     */
    public function reconnect(var mixOption = [])
    {
        this->disconnect(mixOption);
        return this->connect(mixOption);
    }

    /**
     * 删除连接
     *
     * @param array|string $mixOption
     * @return void
     */
    public function disconnect(var mixOption = [])
    {
        var strUnique, arrTemp;

        let arrTemp = this->parseOptionAndUnique(mixOption);
        let mixOption = array_shift(arrTemp);
        let strUnique = array_shift(arrTemp);

        if isset this->arrConnect[strUnique] {
            unset this->arrConnect[strUnique];
        }
    }

    /**
     * 取回所有连接
     *
     * @return object[]
     */
    public function getConnects()
    {
        return this->arrConnect;
    }

    /**
     * 返回默认驱动
     *
     * @return string
     */
    public function getDefaultDriver()
    {
    	var strDefault;
    	let strDefault = this->getOptionName("default");
        return this->getOptionObject()->get(strDefault);
    }

    /**
     * 设置默认驱动
     *
     * @param string $strName
     * @return void
     */
    public function setDefaultDriver(string strName)
    {
    	var strDefault;
    	let strDefault = this->getOptionName("default");
        this->getOptionObject()->set(strDefault, strName);
    }

    /**
     * 取得配置命名空间
     *
     * @return string
     */
    abstract protected function getOptionNamespace();

    /**
     * 创建连接对象
     *
     * @param object $objConnect
     * @return object
     */
    abstract protected function createConnect(var objConnect);

    /**
     * 取得连接名字
     *
     * @param string $strOptionName
     * @return string
     */
    protected function getOptionName(string strOptionName = null)
    {
        return this->getOptionNamespace() . "\\" . strOptionName;
    }

    /**
     * 创建连接
     *
     * @param string $strConnect
     * @param array $arrOption
     * @return object
     */
    protected function makeConnect(string strConnect, array arrOption = [])
    {
    	var strTemp;
    	let strTemp = this->getOptionName("connect." . strConnect);
        if typeof this->getOptionObject()->get(strTemp) == "null" {
            throw new Exception(sprintf("Connect driver %s not exits", strConnect));
        }
        return this->createConnect(this->createConnectCommon(strConnect, arrOption));
    }

    /**
     * 创建连接对象公共入口
     *
     * @param string $strConnect
     * @param array $arrOption
     * @return object
     */
    protected function createConnectCommon(string strConnect, array arrOption = [])
    {
    	var strConnect;
    	let strConnect = "makeConnect" . ucwords(strConnect);
        return this->{strConnect}(arrOption);
    }

    /**
     * 分析连接参数以及其唯一值
     *
     * @param array|string $mixOption
     * @return array
     */
    protected function parseOptionAndUnique(var mixOption = [])
    {
    	var strUnique;

    	let mixOption = this->parseOptionParameter(mixOption);
    	let strUnique = this->getUnique(mixOption);

    	return [
    		mixOption,
    		strUnique
    	];
    }

    /**
     * 分析连接参数
     *
     * @param array|string $mixOption
     * @return array
     */
    protected function parseOptionParameter(var mixOption = [])
    {
        if typeof mixOption == "null" {
            return [];
        }

        if typeof mixOption == "string" {
        	let mixOption = this->getOptionObject()->get(this->getOptionName("connect." . mixOption));
        }

        if typeof mixOption != "array" {
            let mixOption = [];
        }

        return mixOption;
    }

    /**
     * 取得唯一值
     *
     * @param array $arrOption
     * @return string
     */
    protected function getUnique(array arrOption)
    {
        return md5(serialize(arrOption));
    }

    /**
     * 读取默认配置
     *
     * @param string $strConnect
     * @param array $arrExtendOption
     * @return array
     */
    protected function getOption(string strConnect, array! arrExtendOption = [])
    {
    	if typeof arrExtendOption != "array" {
    		let arrExtendOption = [];
    	}
        return array_merge(this->getOptionConnect(strConnect), this->getOptionCommon(), arrExtendOption);
    }

    /**
     * 读取连接全局配置
     *
     * @return array
     */
    protected function getOptionCommon()
    {
        var arrOption;
        let arrOption = this->getOptionObject()->get(this->getOptionName());
        let arrOption = this->filterOptionCommon(arrOption);
        return arrOption;
    }

    /**
     * 过滤全局配置
     *
     * @param array $arrOption
     * @return array
     */
    protected function filterOptionCommon(array arrOption)
    {
        var strItem;
        for strItem in this->filterOptionCommonItem() {
            if isset arrOption[strItem] {
                unset arrOption[strItem];
            }
        }

        return arrOption;
    }

    /**
     * 过滤全局配置项
     *
     * @return array
     */
    protected function filterOptionCommonItem()
    {
        return [
            "default",
            "connect"
        ];
    }

    /**
     * 读取连接配置
     *
     * @param string $strConnect
     * @return array
     */
    protected function getOptionConnect(string strConnect)
    {
        return this->getOptionObject()->get(this->getOptionName("connect." . strConnect));
    }

    /**
     * 清除配置 null
     *
     * @param array $arrOption
     * @return array
     */
    protected function optionFilterNull(array arrOption)
    {
        return array_filter(arrOption, function (mixValue) {
            return typeof mixValue !== "null";
        });
    }

    /**
     * 返回配置对象
     *
     * @return \queryyetsimple\option\option
     */
    protected function getOptionObject()
    {
    	return this->objContainer->make("option");
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
    	return call_user_func_array([this->connect(), sMethod], arrArgs);
    }
}
