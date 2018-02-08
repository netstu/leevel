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
namespace Queryyetsimple\Psr4;

use RuntimeException;
use Composer\Autoload\ClassLoader;

/**
 * psr4 自动载入规范
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.25
 * @version 1.0
 */
class Psr4 implements IPsr4
{

    /**
     * Composer
     *
     * @var \Composer\Autoload\ClassLoader
     */
    protected composer;
    
    /**
     * 沙盒路径
     *
     * @var string
     */
    protected sandbox;
    
    /**
     * 系统命名空间
     *
     * @var string
     */
    protected namespaces;
    
    /**
     * 短命名空间
     *
     * @var string
     */
    protected shortNamespace;
    
    /**
     * 设置 composer
     *
     * @param \Composer\Autoload\ClassLoader $composer
     * @param string $sandbox
     * @param string $namespaces
     * @param string $shortNamespace
     * @return void
     */
    public function __construct(<ClassLoader> composer, string sandbox, string namespaces, string shortNamespace)
    {
        let this->composer = composer;
        let this->sandbox = sandbox;
        let this->namespaces = namespaces;
        let this->shortNamespace = shortNamespace;
    }
    
    /**
     * 获取 composer
     *
     * @return \Composer\Autoload\ClassLoader
     */
    public function composer() -> <ClassLoader>
    {
        return this->composer;
    }
    
    /**
     * 导入一个目录中命名空间结构
     *
     * @param string $namespaces 命名空间名字
     * @param string $package 命名空间路径
     * @param boolean $force 强制覆盖
     * @return void
     */
    public function import(string namespaces, string package, boolean force = false)
    {
        var packagePath;
    
        if ! (is_dir(package)) {
            return;
        }

        if force === false && ! (is_null(this->namespaces(namespaces))) {
            return;
        }

        let packagePath = realpath(package);
        this->composer()->setPsr4(namespaces . "\\", packagePath);
    }
    
    /**
     * 获取命名空间路径
     *
     * @param string $namespaces
     * @return string|null
     */
    public function namespaces(string namespaces)
    {
        var temp, prefix, path;
    
        let temp = explode("\\", namespaces);
        let prefix = this->composer()->getPrefixesPsr4();

        let path = temp[0] . "\\";
        if ! (isset prefix[path]) {
            return null;
        }

        let temp[0] = prefix[path][0];
        return implode("/", temp);
    }
    
    /**
     * 根据命名空间取得文件路径
     *
     * @param string $classname
     * @return string
     */
    public function file(string classname) -> string
    {
        var namespaces;
    
        let namespaces = this->namespaces(classname);
        if namespaces {
            return namespaces . ".php";
        } else {
            return classname . ".php";
        }
    }
    
    /**
     * 框架自动载入
     *
     * @param string $classname
     * @return void
     */
    public function autoload(string classname)
    {
        var namespaces, item, sandboxPath;
    
        if strpos(classname, "\\") === false {
            return;
        }

        let namespaces = [this->namespaces, this->shortNamespace];

        for item in namespaces {
            let sandboxPath = this->sandbox . "/" . str_replace("\\", "/", classname) . ".php";
            if strpos(classname, item . "\\") === 0 && is_file(sandboxPath) {
                return require sandboxPath;
            }
        }

        if strpos(classname, this->shortNamespace . "\\") !== false {
            this->shortNamespaceMap(classname);
        }
    }
    
    /**
     * 框架命名空间自动关联
     *
     * @param string $classname
     * @return void
     */
    protected function shortNamespaceMap(string classname)
    {
        var parentClass, tmp, definedClass, namespaces, evals;
    
        let parentClass = str_replace(this->shortNamespace . "\\", this->namespaces . "\\", classname);

        if class_exists(parentClass) || interface_exists(parentClass) {
            let tmp = explode("\\", classname);
            let definedClass = array_pop(tmp);
            let namespaces = implode("\\", tmp);
            let evals = sprintf("namespace %s; %s %s extends  \\%s {}", namespaces,  class_exists(parentClass) ? "class" : "interface", definedClass, parentClass);
            eval(evals);
        }
    }
}
