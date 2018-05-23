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
namespace Leevel\Filesystem\Provider;

use Closure;
use Leevel\Di\Provider;
use Leevel\Di\IContainer;
use Leevel\Filesystem\Manager;

/**
 * filesystem 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.28
 * @version 1.0
 */
class Register extends Provider
{

    /**
     * 是否延迟载入
     *
     * @var boolean
     */
    public static defer = true;

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
        this->filesystems();
        this->filesystem();
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
            "filesystems" : [
                "Leevel\\Filesystem\\Manager"
            ], 
            "filesystem" : [
                "Leevel\\Filesystem\\Filesystem", 
                "Leevel\\Filesystem\\IFilesystem"
            ]
        ];

        return tmp;
    }
    
    /**
     * 注册 filesystems 服务
     *
     * @return void
     */
    protected function filesystems()
    {
        this->container->singleton("filesystems", Closure::fromCallable([this, "filesystemsClosure"]));
    }

    /**
     * 创建 filesystems 闭包
     * 
     * @param \Leevel\Project\IProject $project
     * @return \Leevel\Filesystem\Manager
     */
    protected function filesystemsClosure(var project)
    {
        return new Manager(project);
    }
    
    /**
     * 注册 filesystem 服务
     *
     * @return void
     */
    protected function filesystem()
    {
        this->container->singleton("filesystem", Closure::fromCallable([this, "filesystemClosure"]));
    }

    /**
     * 创建 filesystem 服务闭包
     *
     * @param \Leevel\Kernel\IProject $project
     * @return object
     */
    protected function filesystemClosure(var project)
    {
        return project->make("filesystems")->connect();
    }
}
