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
namespace Leevel\Option\Provider;

use Leevel\Di\Provider;
use Leevel\Di\IContainer;

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
     * @param \Leevel\Di\IContainer $container
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
                "Leevel\\Option\\Option", 
                "Leevel\\Option\\IOption"
            ], 
            "load" : [
                "Leevel\\Option\\Load"
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
            return new \Leevel\Option\Option();
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
            return new \Leevel\Option\Load();
        });
    }
}