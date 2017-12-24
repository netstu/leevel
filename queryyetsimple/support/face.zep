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

use Closure;
use Exception;
use RuntimeException;
use BadMethodCallException;
use Queryyetsimple\Support\Icontainer;

/**
 * 实现类的静态访问门面
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.23
 * @version 1.0
 */
abstract class Face
{

    /**
     * 项目容器
     *
     * @var \queryyetsimple\support\icontainer
     */
    protected static objContainer = null;

    /**
     * 注入容器实例
     *
     * @var object
     */
    protected static arrInstance = [];

    /**
     * 获取注册容器的实例
     *
     * @return mixed
     */
    public static function faces()
    {
    	var strUnique, instance;

        let strUnique = static::name();

        if fetch instance, self::arrInstance[strUnique] {
            return instance;
        }

        let instance = self::container()->make(strUnique);
        if typeof instance != "object" {
            throw new RuntimeException(sprintf("Services %s was not found in the IOC container.", strUnique));
        }

        return instance;
    }

    /**
     * 返回服务容器
     *
     * @return \queryyetsimple\support\icontainer
     */
    public static function container() -> <Icontainer>
    {
        return self::objContainer;
    }

     /**
     * 设置服务容器
     *
     * @param \queryyetsimple\support\icontainer $objContainer
     * @return void
     */
    public static function setContainer(<Icontainer> objContainer) -> void
    {
        let self::objContainer = objContainer;
    }

    /**
     * 门面名字
     *
     * @return string
     */
    protected static function name() -> string {
    	return "";
    }

    /**
     * call 
     *
     * @param string $sMethod
     * @param array $arrArgs
     * @return mixed
     */
    public static function __callStatic(string sMethod, array arrArgs)
    {
    	var objInstance, calMethod;

        let objInstance = self::faces();
        if ! objInstance {
            throw new RuntimeException("Can not find instance from container.");
        }

        let calMethod = [
            objInstance,
            sMethod
        ];
        if ! is_callable(calMethod) {
            throw new BadMethodCallException(sprintf("Method %s is not exits.", sMethod));
        }

        return call_user_func_array(calMethod, arrArgs);
    }

}
