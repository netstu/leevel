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
namespace Leevel\I18n\Provider;

use Leevel\Di\Provider;
use Leevel\Di\IContainer;

/**
 * i18n 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.26
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
        this->i18n();
        this->i18nLoad();
    }
    
    /**
     * bootstrap
     *
     * @return void
     */
    public function bootstrap()
    {
        this->console();
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
            "i18n" : [
                "Leevel\\I18n\\I18n", 
                "Leevel\\I18n\\II18n"
            ], 
            "load" : [
                "Leevel\\I18n\\Load"
            ]
        ];
        return tmp;
    }
    
    /**
     * 注册 i18n 服务
     *
     * @return void
     */
    protected function i18n()
    {
        this->singleton("i18n", function (project) {
            return new \Leevel\I18n\I18n(project->make("option")->get("i18n\\default"));
        });
    }
    
    /**
     * 注册 i18n.load 服务
     *
     * @return void
     */
    protected function i18nLoad()
    {
        this->singleton("i18n.load", function () {
            return new \Leevel\I18n\Load();
        });
    }
    
    /**
     * 载入命令包
     *
     * @return void
     */
    protected function console()
    {
        this->loadCommandNamespace("Leevel\\I18n\\Console");
    }
}