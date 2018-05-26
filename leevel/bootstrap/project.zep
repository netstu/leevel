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
namespace Leevel\Bootstrap;

use Exception;
use RuntimeException;
use Leevel\Di\Provider;
use Leevel\Di\Container;
use Leevel\Kernel\IProject;
use Composer\Autoload\ClassLoader;
use Leevel\Log\Provider\Register as LogProvider;
use Leevel\Event\Provider\Register as EventProvider;
use Leevel\Router\Provider\Register as RouterProvider;

/**
 * 项目管理
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.01.14
 * @version 1.0
 */
class Project extends Container implements IProject
{
    /**
     * 当前项目实例
     *
     * @var static
     */
    protected static project;
    
    /**
     * 项目基础路径
     *
     * @var string
     */
    protected path;
    
    /**
     * 应用路径
     *
     * @var string
     */
    protected applicationPath;
    
    /**
     * 公共路径
     *
     * @var string
     */
    protected commonPath;
    
    /**
     * 运行时路径
     *
     * @var string
     */
    protected runtimePath;
    
    /**
     * 存储路径
     *
     * @var string
     */
    protected storagePath;
    
    /**
     * 配置路径
     *
     * @var string
     */
    protected optionPath;
    
    /**
     * 语言包路径
     *
     * @var string
     */
    protected i18nPath;
    
    /**
     * 环境变量路径
     *
     * @var string
     */
    protected envPath;
    
    /**
     * 环境变量文件
     *
     * @var string
     */
    protected envFile;
    
    /**
     * 延迟载入服务提供者
     *
     * @var array
     */
    protected deferredProviders = [];
    
    /**
     * 服务提供者引导
     *
     * @var array
     */
    protected providerBootstraps = [];

    /**
     * 是否已经初始化引导
     *
     * @var bool
     */
    protected isBootstrap = false;
    
    /**
     * 构造函数
     * 受保护的禁止外部通过 new 实例化，只能通过 singletons 生成单一实例
     *
     * @param string $path
     * @return void
     */
    protected function __construct(var path = null)
    {
        if path {
            this->setPath(path);
        }

        this->registerBaseServices();

        this->registerBaseProvider();
    }
    
    /**
     * 禁止克隆
     *
     * @return void
     */
    protected function __clone()
    {
        throw new RuntimeException("Project disallowed clone.");
    }
    
    /**
     * 返回项目
     *
     * @param string $path
     * @return static
     */
    public static function singletons(var path = null)
    {
        if self::project !== null {
            return self::project;
        } else {
            let self::project = new static(path);
            return self::project;
        }
    }
    
    /**
     * 程序版本
     *
     * @return string
     */
    public function version() -> string
    {
        return self::VERSION;
    }
    
    /**
     * 是否以扩展方式运行
     *
     * @return boolean
     */
    public function runWithExtension() -> boolean
    {
        return extension_loaded("leevel");
    }
    
    /**
     * {@inheritdoc}
     */
    public function make(var name, array args = [])
    {
        let name = this->getAlias(name);

        if isset this->deferredProviders[name] {
            this->registerDeferredProvider(name);
        }

        return parent::make(name, args);
    }
    
    /**
     * 设置项目路径
     *
     * @param string $path
     * @return void
     */
    public function setPath(var path)
    {
        let this->path = path;

        if ! (is_writeable(this->pathRuntime())) {
            throw new RuntimeException(sprintf("Runtime path %s is not writeable.", this->pathRuntime()));
        }
    }
    
    /**
     * 基础路径
     *
     * @return string
     */
    public function path() -> string
    {
        return this->path;
    }
    
    /**
     * 应用路径
     *
     * @return string
     */
    public function pathApplication() -> string
    {
        return this->applicationPath ? this->applicationPath : this->path . DIRECTORY_SEPARATOR . "application";
    }
    
    /**
     * 设置应用路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathApplication(var path)
    {
        let this->applicationPath = path;

        return this;
    }
    
    /**
     * 设置公共路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathCommon(var path)
    {
        let this->commonPath = path;

        return this;
    }
    
    /**
     * 公共路径
     *
     * @return string
     */
    public function pathCommon() -> string
    {
        return this->commonPath ? this->commonPath : this->path . DIRECTORY_SEPARATOR . "common";
    }
    
    /**
     * 设置运行时路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathRuntime(var path)
    {
        let this->runtimePath = path;

        return this;
    }
    
    /**
     * 运行路径
     *
     * @return string
     */
    public function pathRuntime() -> string
    {
        return this->runtimePath ? this->runtimePath : this->path . DIRECTORY_SEPARATOR . "runtime";
    }
    
    /**
     * 设置存储路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathStorage(var path)
    {
        let this->storagePath = path;

        return this;
    }
    
    /**
     * 附件路径
     *
     * @return string
     */
    public function pathStorage() -> string
    {
        return this->storagePath ? this->storagePath : this->path . DIRECTORY_SEPARATOR . "storage";
    }
    
    /**
     * 设置配置路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathOption(var path)
    {
        let this->optionPath = path;

        return this;
    }
    
    /**
     * 配置路径
     *
     * @return string
     */
    public function pathOption() -> string
    {
        return this->optionPath ? this->optionPath : this->path . DIRECTORY_SEPARATOR . "option";
    }
    
    /**
     * 设置语言包路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathI18n(var path)
    {
        let this->i18nPath = path;

        return this;
    }
    
    /**
     * 语言包路径
     *
     * @return string
     */
    public function pathI18n() -> string
    {
        return this->i18nPath ? this->i18nPath : this->path . DIRECTORY_SEPARATOR . "i18n";
    }
    
    /**
     * 环境变量路径
     *
     * @return string
     */
    public function pathEnv() -> string
    {
        return this->envPath ? this->envPath : this->path;
    }
    
    /**
     * 设置环境变量路径
     *
     * @param string $path
     * @return $this
     */
    public function setPathEnv(var path)
    {
        let this->envPath = path;

        return this;
    }
    
    /**
     * 设置环境变量文件
     *
     * @param string $file
     * @return $this
     */
    public function setEnvFile(string file)
    {
        let this->envFile = file;
        return this;
    }
    
    /**
     * 取得环境变量文件
     *
     * @return string
     */
    public function envFile() -> string
    {
        return  this->envFile ? this->envFile : self::DEFAULT_ENV;
    }
    
    /**
     * 取得环境变量完整路径
     *
     * @return string
     */
    public function fullEnvPath() -> string
    {
        return this->pathEnv() . DIRECTORY_SEPARATOR . this->envFile();
    }
    
    /**
     * 应用路径
     *
     * @param string $app
     * @return string
     */
    public function pathAnApplication(var app = null) -> string
    {
        return this->pathApplication() . "/" . strtolower(app ? app : (this->make("request")->app() ? this->make("request")->app() : "App"));
    }
    
    /**
     * 取得应用缓存目录
     *
     * @param string $type
     * @return string
     */
    public function pathApplicationCache(string type) -> string
    {
        var types;
    
        let types = [
            "file",
            "log",
            "table",
            "theme",
            "option",
            "i18n",
            "router",
            "console",
            "swoole"
        ];

        if ! (in_array(type, types)) {
            throw new Exception(sprintf("Application cache type %s not support", type));
        }

        return this->pathRuntime() . "/" . type;
    }
    
    /**
     * 取得应用目录
     *
     * @param string $type
     * @return string
     */
    public function pathApplicationDir(string type) -> string
    {
        var types;
    
        let types = [
            "theme",
            "i18n"
        ];

        if ! (in_array(type, types)) {
            throw new Exception(sprintf("Application dir type %s not support", type));
        }

        return this->pathAnApplication() . "/ui/" . type;
    }
    
    /**
     * 返回语言包路径
     * 
     * @param string $i18n
     * @return string
     */
    public function pathCacheI18nFile(var i18n) -> string
    {
        return this->pathRuntime() . "/cache/i18n/" . i18n . ".php";
    }
    
    /**
     * 是否缓存语言包
     *
     * @param string $i18n
     * @return boolean
     */
    public function isCachedI18n(var i18n) -> boolean
    {
        return is_file(this->pathCacheI18nFile(i18n));
    }
    
    /**
     * 返回缓存路径
     * 
     * @return string
     */
    public function pathCacheOptionFile() -> string
    {
        return this->pathRuntime() . "/cache/option.php";
    }
    
    /**
     * 是否缓存配置
     *
     * @return boolean
     */
    public function isCachedOption() -> boolean
    {
        return is_file(this->pathCacheOptionFile());
    }
    
    /**
     * 取得 composer
     *
     * @return \Composer\Autoload\ClassLoader
     */
    public function composer() -> <ClassLoader>
    {
        return require this->path . "/vendor/autoload.php";
    }
    
    /**
     * 获取命名空间路径
     *
     * @param string $namespaces
     * @return string|null
     */
    public function getPathByNamespace(var namespaces)
    {
        var prefix;
    
        let namespaces = explode("\\", namespaces);
        let prefix = this->composer()->getPrefixesPsr4();

        if ! (isset prefix[namespaces[0] . "\\"]) {
            return null;
        }

        let namespaces[0] = prefix[namespaces[0] . "\\"][0];

        return implode("/", namespaces);
    }
    
    /**
     * 批量获取命名空间路径
     *
     * @param array $namespaces
     * @return array
     */
    public function getPathByNamespaces(array namespaces) -> array
    {
        var result, item;
    
        let result = [];

        for item in namespaces {
            let result[item] = this->getPathByNamespace(item);
        }

        return result;
    }
    
    /**
     * 是否开启 debug
     *
     * @return boolean
     */
    public function debug() -> boolean
    {
        return this->make("option")->get("debug");
    }
    
    /**
     * 是否为开发环境
     *
     * @return boolean
     */
    public function development() -> boolean
    {
        return this->environment() === "development";
    }
    
    /**
     * 运行环境
     *
     * @return boolean
     */
    public function environment() -> boolean
    {
        return this->make("option")->get("environment");
    }
    
    /**
     * 是否为 API
     *
     * @return boolean
     */
    public function api() -> boolean
    {
        return this->make("request")->isAcceptJson();
    }
    
    /**
     * 是否为 Console
     *
     * @return boolean
     */
    public function console() -> boolean
    {
        return this->make("request")->isCli();
    }
    
    /**
     * 创建服务提供者
     *
     * @param string $provider
     * @return \Leevel\Di\Provider
     */
    public function makeProvider(string provider)
    {
        return new {provider}(this);
    }
    
    /**
     * 执行 bootstrap
     *
     * @param \Leevel\Di\Provider $provider
     * @return void
     */
    public function callProviderBootstrap(<Provider> provider)
    {
        if ! (method_exists(provider, "bootstrap")) {
            return;
        }

        this->call([
            provider,
            "bootstrap"
        ]);
    }
    
    /**
     * 初始化项目
     * 
     * @param array $bootstraps
     * @return void
     */
    public function bootstrap(array bootstraps)
    {
        var value;
    
        for value in bootstraps {
            (new {value}())->handle(this);
        }
    }

    /**
     * 是否已经初始化引导
     * 
     * @return bool
     */
    public function isBootstrap()-> boolean
    {
        return this->isBootstrap;
    }
    
    /**
     * 框架基础提供者 register
     *
     * @return $this
     */
    public function registerProviders()
    {
        var tmp, alias, deferredAlias, providers, provider, providerInstance;
    
        let tmp = this->make("option")->get("_deferred_providers", [[], []]);
        let this->deferredProviders = tmp[0];
        let deferredAlias = tmp[1];

        for alias in deferredAlias {
            this->alias(alias);
        }

        let providers = this->make("option")->get("_composer.providers", []);
        let providers = array_values(providers);

        for provider in providers {
            let providerInstance = this->register(provider);

            if method_exists(providerInstance, "bootstrap") {
                let this->providerBootstraps[] = providerInstance;
            }
        }

        return this;
    }
    
    /**
     * 执行框架基础提供者引导
     *
     * @return $this
     */
    public function bootstrapProviders()
    {
        var item;
    
        for item in this->providerBootstraps {
            this->callProviderBootstrap(item);
        }

        let this->isBootstrap = true;

        return this;
    }
    
    /**
     * 注册服务提供者
     *
     * @param \Leevel\Di\Provider|string $provider
     * @return \Leevel\Di\Provider
     */
    public function register(var provider)
    {
        var providerInstance;

        if is_string(provider) {
            let providerInstance = this->makeProvider(provider);
        } else {
            let providerInstance = provider;
        }

        if method_exists(providerInstance, "register") {
            providerInstance->register();
        }

        if this->isBootstrap() {
            this->callProviderBootstrap(providerInstance);
        }

        return providerInstance;
    }
    
    /**
     * 注册基础服务
     *
     * @return void
     */
    protected function registerBaseServices()
    {
        this->instance("project", this);

        this->alias([
            "project" : [
                "Leevel\\Bootstrap\\Project",
                "Leevel\\Di\\IContainer",
                "Leevel\\Kernel\\IProject",
                "app"
            ],
            "request" : [
                "Leevel\\Http\\IRequest",
                "Leevel\\Http\\Request"
            ],
            "option" : [
                "Leevel\\Option\\IOption",
                "Leevel\\Option\\Option"
            ], 
            "i18n" : [
                "Leevel\\I18n\\I18n",
                "Leevel\\I18n\\II18n"
            ]
        ]);
    }
    
    /**
     * 注册基础服务提供者
     *
     * @return void
     */
    protected function registerBaseProvider()
    {
        this->register(new EventProvider(this));

        this->register(new LogProvider(this));

        this->register(new RouterProvider(this));
    }
    
    /**
     * 注册延迟载入服务提供者
     *
     * @param string $provider
     * @return void
     */
    protected function registerDeferredProvider(string provider)
    {
        var providerInstance;

        if ! (isset this->deferredProviders[provider]) {
            return;
        }

        let providerInstance = this->register(this->deferredProviders[provider]);

        this->callProviderBootstrap(providerInstance);

        unset this->deferredProviders[provider];
    }
}
