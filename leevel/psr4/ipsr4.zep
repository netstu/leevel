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
namespace Leevel\Psr4;

use Composer\Autoload\ClassLoader;

/**
 * IPsr4 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.25
 * @version 1.0
 */
interface IPsr4
{

    /**
     * 获取 composer
     *
     * @return \Composer\Autoload\ClassLoader
     */
    public function composer() -> <ClassLoader>;
    
    /**
     * 导入一个目录中命名空间结构
     *
     * @param string $namespaces 命名空间名字
     * @param string $package 命名空间路径
     * @param boolean $force 强制覆盖
     * @return void
     */
    public function import(string namespaces, string package, boolean force = false);
    
    /**
     * 获取命名空间路径
     *
     * @param string $namespaces
     * @return string|null
     */
    public function namespaces(string namespaces);
    
    /**
     * 根据命名空间取得文件路径
     *
     * @param string $classname
     * @return string
     */
    public function file(string classname) -> string;
    
    /**
     * 框架自动载入
     *
     * @param string $classname
     * @return void
     */
    public function autoload(string classname);
}