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
namespace Leevel\Kernel;

use Leevel\Di\Provider;
use Leevel\Di\IContainer;
use Composer\Autoload\ClassLoader;

/**
 * IProject 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.04.23
 * @version 1.0
 */
interface IProject extends IContainer
{
    /**
     * QueryPHP 版本
     *
     * @var string
     */
    const VERSION = "1.0.0";

    /**
     * 默认环境变量名字
     *
     * @var string
     */
    const DEFAULT_ENV = ".env";

    /**
     * 返回项目
     *
     * @param string $path
     * @return static
     */
    public static function singletons(var path = null);
    
    /**
     * 程序版本
     *
     * @return string
     */
    public function version() -> string;
    
    /**
     * 是否以扩展方式运行
     *
     * @return boolean
     */
    public function runWithExtension() -> boolean;
    
    /**
     * {@inheritdoc}
     */
    public function make(var name, array args = []);
    
    /**
     * 设置项目路径
     *
     * @param string $path
     * @return void
     */
    public function setPath(var path);
    
    /**
     * 基础路径
     *
     * @return string
     */
    public function path() -> string;
    
    /**
     * 应用路径
     *
     * @return string
     */
    public function pathApplication() -> string;
    
    /**
     * 设置应用路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathApplication(var path);
    
    /**
     * 设置公共路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathCommon(var path);
    
    /**
     * 公共路径
     *
     * @return string
     */
    public function pathCommon() -> string;
    
    /**
     * 设置运行时路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathRuntime(var path);
    
    /**
     * 运行路径
     *
     * @return string
     */
    public function pathRuntime() -> string;
    
    /**
     * 设置存储路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathStorage(var path);
    
    /**
     * 附件路径
     *
     * @return string
     */
    public function pathStorage() -> string;
    
    /**
     * 设置配置路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathOption(var path);
    
    /**
     * 配置路径
     *
     * @return string
     */
    public function pathOption() -> string;
    
    /**
     * 设置语言包路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathI18n(var path);
    
    /**
     * 语言包路径
     *
     * @return string
     */
    public function pathI18n() -> string;
    
    /**
     * 环境变量路径
     *
     * @return string
     */
    public function pathEnv() -> string;
    
    /**
     * 设置环境变量路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathEnv(var path);
    
    /**
     * 设置环境变量文件
     *
     * @param string $file
     * @return $this
     */
    public function setEnvFile(string file);
    
    /**
     * 取得环境变量文件
     *
     * @return string
     */
    public function envFile() -> string;
    
    /**
     * 取得环境变量完整路径
     *
     * @return string
     */
    public function fullEnvPath() -> string;
    
    /**
     * 应用路径
     *
     * @param string $app
     * @return string
     */
    public function pathAnApplication(var app = null) -> string;
    
    /**
     * 取得应用缓存目录
     *
     * @param string $type
     * @return string
     */
    public function pathApplicationCache(string type) -> string;
    
    /**
     * 取得应用主题目录
     *
     * @param string $app
     * @return string
     */
    public function pathApplicationTheme(var app = null) -> string;
    
    /**
     * 返回语言包路径
     * 
     * @param string $i18n
     * @return string
     */
    public function pathCacheI18nFile(var i18n) -> string;
    
    /**
     * 是否缓存语言包
     *
     * @param string $i18n
     * @return boolean
     */
    public function isCachedI18n(var i18n) -> boolean;
    
    /**
     * 返回缓存路径
     * 
     * @return string
     */
    public function pathCacheOptionFile() -> string;
    
    /**
     * 是否缓存配置
     *
     * @return boolean
     */
    public function isCachedOption() -> boolean;
    
    /**
     * 取得 composer
     *
     * @return \Composer\Autoload\ClassLoader
     */
    public function composer() -> <ClassLoader>;
    
    /**
     * 获取命名空间路径
     *
     * @param string $namespaces
     * @return string|null
     */
    public function getPathByNamespace(var namespaces);
    
    /**
     * 批量获取命名空间路径
     *
     * @param array $namespaces
     * @return array
     */
    public function getPathByNamespaces(array namespaces) -> array;
    
    /**
     * 是否开启 debug
     *
     * @return boolean
     */
    public function debug() -> boolean;
    
    /**
     * 是否为开发环境
     *
     * @return string
     */
    public function development() -> string;
    
    /**
     * 运行环境
     *
     * @return boolean
     */
    public function environment() -> boolean;
    
    /**
     * 是否为 API
     *
     * @return boolean
     */
    public function api() -> boolean;
    
    /**
     * 是否为 Console
     *
     * @return boolean
     */
    public function console() -> boolean;
    
    /**
     * 创建服务提供者
     *
     * @param string $provider
     * @return \Leevel\Di\Provider
     */
    public function makeProvider(string provider);
    
    /**
     * 执行 bootstrap
     *
     * @param \Leevel\Di\Provider $provider
     * @return void
     */
    public function callProviderBootstrap(<Provider> provider);
    
    /**
     * 初始化项目
     * 
     * @param array $bootstraps
     * @return void
     */
    public function bootstrap(array bootstraps);

    /**
     * 是否已经初始化引导
     * 
     * @return bool
     */
    public function isBootstrap()-> boolean;
    
    /**
     * 框架基础提供者 register
     *
     * @return $this
     */
    public function registerProviders();
    
    /**
     * 执行框架基础提供者 bootstrap
     *
     * @return $this
     */
    public function bootstrapProviders();
    
    /**
     * 注册服务提供者
     *
     * @param \Leevel\Di\Provider|string $provider
     * @return \Leevel\Di\Provider
     */
    public function register(var provider);
}
