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
namespace Queryyetsimple\Option\Provider;

use Queryyetsimple\Di\Provider;
use Queryyetsimple\Di\IContainer;

/**
 * option 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.28
 * @version 1.0
 */
class Register extends Provider
{

    /**
     * 创建一个服务容器提供者实例
     *
     * @param \Queryyetsimple\Di\IContainer $container
     * @return void
     */
    public function __construct(<IContainer> container)
    {
        parent::__construct(container);
    }

    /**
     * 注册服务
     *
     * @return void
     */
    public function register()
    {
        this->option();
        this->optionLoad();
    }
    
    /**
     * 可用服务提供者
     *
     * @return array
     */
    public static function providers() -> array
    {
        var tmp;
    
        let tmp = [
            "option" : [
                "Queryyetsimple\\Option\\Option", 
                "Queryyetsimple\\Option\\IOption", 
                "Qys\\Option\\Option", 
                "Qys\\Option\\IOption"
            ], 
            "load" : [
                "Queryyetsimple\\Option\\Load", 
                "Qys\\Option\\Load"
            ]
        ];
        return tmp;
    }
    
    /**
     * 注册 option 服务
     *
     * @return void
     */
    protected function option()
    {
        this->singleton("option", function () {
            return new \Queryyetsimple\Option\Option();
        });
    }
    
    /**
     * 注册 option.load 服务
     *
     * @return void
     */
    protected function optionLoad()
    {
        this->singleton("option.load", function () {
            return new \Queryyetsimple\Option\Load();
        });
    }
}