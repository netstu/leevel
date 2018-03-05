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
namespace Queryyetsimple\Http;

use ArrayAccess;
use SplFileObject;
use RuntimeException;
use Queryyetsimple\Option\IClass;
use Queryyetsimple\Support\IMacro;
use Queryyetsimple\Support\IArray;

/**
 * HTTP 请求
 * This class borrows heavily from the Symfony2 Framework and is part of the symfony package
 * 
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.05
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
class Request implements IClass, IMacro, IRequest, IArray, ArrayAccess
{

    /**
     * GET Bag
     *
     * @var \Queryyetsimple\Http\Bag
     */
    public query;
    
    /**
     * POST Bag
     *
     * @var \Queryyetsimple\Http\Bag
     */
    public request;
    
    /**
     * 路由解析后的参数
     *
     * @var \Queryyetsimple\Http\Bag
     */
    public params;
    
    /**
     * COOKIE Bag
     *
     * @var \Queryyetsimple\Http\Bag
     */
    public cookie;
    
    /**
     * FILE Bag
     *
     * @var \Queryyetsimple\Http\FileBag
     */
    public files;
    
    /**
     * SERVER Bag
     *
     * @var \Queryyetsimple\Http\ServerBag
     */
    public server;
    
    /**
     * HEADER Bag
     *
     * @var \Queryyetsimple\Http\HeaderBag
     */
    public headers;
    
    /**
     * 内容
     * 
     * @var string|resource|false|null
     */
    protected content;
    
    /**
     * 基础 url
     *
     * @var string
     */
    protected baseUrl;
    
    /**
     * 请求 url
     *
     * @var string
     */
    protected requestUri;
    
    /**
     * 请求类型
     *
     * @var string
     */
    protected method;
    
    /**
     * public URL
     *
     * @var string
     */
    protected publicUrl;
    
    /**
     * pathInfo
     *
     * @var string
     */
    protected pathInfo;
    
    /**
     * 应用名字
     *
     * @var string
     */
    protected app;
    
    /**
     * 控制器名字
     *
     * @var string
     */
    protected controller;
    
    /**
     * 方法名字
     *
     * @var string
     */
    protected action;
    
    /**
     * 当前语言
     *
     * @var string
     */
    protected language;

    /**
     * 注册的动态扩展
     *
     * @var array
     */
    protected static macro = [];

    /**
     * 配置
     *
     * @var array
     */
    protected option = [
    	"var_method" : "_method", 
    	"var_ajax" : "_ajax", 
    	"var_pjax" : "_pjax", 
    	"html_suffix" : ".html", 
    	"rewrite" : false, 
    	"public" : "http://public.foo.bar"
    ];

    /**
     * 服务器 url 重写支持 pathInfo
     *
     * Nginx
     * location @rewrite {
     *     rewrite ^/(.*)$ /index.php?_url=/$1;
     * }
     *
     * @var string
     */
    const PATHINFO_URL = "_url";
    
    /**
     * 构造函数
     * 
     * @param array $query
     * @param array $request
     * @param array $params
     * @param array $cookie
     * @param array $files
     * @param array $server
     * @param string $content
     * @param array $option
     * @return void
     */
    public function __construct(array query = [], array request = [], array params = [], array cookie = [], array files = [], array server = [], string content = null, array option = []) -> void
    {
        this->reset(query, request, params, cookie, files, server, content);
        this->options(option);
    }
    
    /**
     * 重置或者初始化
     * 
     * @param array $query
     * @param array $request
     * @param array $params
     * @param array $cookie
     * @param array $files
     * @param array $server
     * @param string $content
     * @param array $option
     * @return void
     */
    public function reset(array query = [], array request = [], array params = [], array cookie = [], array files = [], array server = [], string content = null) -> void
    {
        let this->query = new Bag(query);
        let this->request = new Bag(request);
        let this->params = new Bag(params);
        let this->cookie = new Bag(cookie);
        let this->files = new FileBag(files);
        let this->server = new ServerBag(server);
        let this->headers = new HeaderBag(this->server->getHeaders());
        let this->content = content;

        let this->baseUrl = null;
        let this->requestUri = null;
        let this->method = null;
        let this->publicUrl = null;
        let this->pathInfo = null;
        let this->app = null;
        let this->controller = null;
        let this->action = null;
        let this->language = null;
    }
    
    /**
     * 全局变量创建一个 Request
     *
     * @param array $options
     * @return static
     */
    public static function createFromGlobals(array option = [])
    {
        var request;
    
        let request = new static(_GET, _POST, [], _COOKIE, _FILES, _SERVER, null, option);
        let request = self::normalizeRequestFromContent(request);

        return request;
    }
    
    /**
     * 格式化请求的内容
     *
     * @param \Queryyetsimple\Http\Request $request
     * @return \Queryyetsimple\Http\Request
     */
    public static function normalizeRequestFromContent(<Request> request) -> <Request>
    {
        var tmp, data;
    
        let tmp = [
        	self::METHOD_PUT, 
        	self::METHOD_DELETE, 
        	self::METHOD_PATCH
        ];

        if 0 === strpos(request->headers->get("CONTENT_TYPE"), "application/x-www-form-urlencoded") && 
        	in_array(strtoupper(request->server->get("REQUEST_METHOD", self::METHOD_GET)), tmp) {
            parse_str(request->getContent(), data);
            let request->request = new Bag(data);
        }

        return request;
    }
    
    /**
     * 获取参数
     *
     * @param string $key
     * @param mixed $defaults
     * @return mixed
     */
    public function get(string key, var defaults = null)
    {
        var all;
    
        let all = this->all();

        if array_key_exists(key, all) {
            return all[key];
        } else {
            return this->params->get(key, defaults);
        }
    }
    
    /**
     * 请求是否包含给定的 key
     *
     * @param string|array $key
     * @return bool
     */
    public function exists(var key) -> boolean
    {
        var keys, input, value;
    
        let keys = is_array(key) ? key : func_get_args();
        let input = this->all();

        for value in keys {
            if ! (array_key_exists(value, input)) {
                return false;
            }
        }

        return true;
    }
    
    /**
     * 请求是否包含非空
     *
     * @param string|array $key
     * @return bool
     */
    public function has(var key) -> boolean
    {
        var keys, value;
    
        let keys = is_array(key) ? key : func_get_args();

        for value in keys {
            if this->isEmptyString(value) {
                return false;
            }
        }

        return true;
    }
    
    /**
     * 取得给定的 key 数据
     *
     * @param array|mixed $keys
     * @return array
     */
    public function only(var keys) -> array
    {
        var results, input, key;
    
        let keys = is_array(keys) ? keys : func_get_args();
        let results = [];
        let input = this->all();

        for key in keys {
            let results[key] = isset input[key] ? input[key] : null;
        }

        return results;
    }
    
    /**
     * 取得排除给定的 key 数据
     *
     * @param array|mixed $keys
     * @return array
     */
    public function except(var keys) -> array
    {
        var results, key;
    
        let keys = is_array(keys) ? keys : func_get_args();
        let results = this->all();

        for key in keys {
            if array_key_exists(key, results) {
                unset results[key];
            }
        }

        return results;
    }
    
    /**
     * 取回输入和文件
     *
     * @return array
     */
    public function all() -> array
    {
        return array_replace_recursive(this->input(), this->allFiles());
    }
    
    /**
     * 获取输入数据
     *
     * @param string $key
     * @param string|array|null $defaults
     * @return mixed
     */
    public function input(string key = null, var defaults = null)
    {
        var input;
    
        let input = this->getInputSource()->all() + this->query->all();

        if is_null(key) {
            return input;
        }

        return  isset input[key] ? input[key] : defaults;
    }
    
    /**
     * 取回 query
     *
     * @param string $key
     * @param string|array|null $defaults
     * @return string|array
     */
    public function query(string key = null, var defaults = null)
    {
        return this->getItem("query", key, defaults);
    }
    
    /**
     * 请求是否存在 COOKIE
     *
     * @param  string  $key
     * @return bool
     */
    public function hasCookie(string key) -> boolean
    {
        return ! (is_null(this->cookie(key)));
    }
    
    /**
     * 取回 cookie
     *
     * @param string $key
     * @param string|array|null $defaults
     * @return string|array
     */
    public function cookie(string key = null, var defaults = null)
    {
        return this->getItem("cookies", key, defaults);
    }
    
    /**
     * 取得所有文件
     *
     * @return array
     */
    public function allFiles() -> array
    {
        return this->files->all();
    }
    
    /**
     * 获取文件
     * 数组文件请在末尾加上反斜杆访问
     *
     * @param string $key
     * @param mixed $defaults
     * @return \Queryyetsimple\Http\UploadedFile|array|null
     */
    public function file(string key = null, var defaults = null)
    {
        if strpos(key, "\\") === false {
            return this->getItem("files", key, defaults);
        } else {
            return this->files->getArr(key, defaults);
        }
    }
    
    /**
     * 文件是否存在已上传的文件
     * 数组文件请在末尾加上反斜杆访问
     *
     * @param string $key
     * @return bool
     */
    public function hasFile(string key) -> boolean
    {
        var files, file;
    
        let files = this->file(key);

        if ! (is_array(files)) {
            let files = [files];
        }

        for file in files {
            if this->isValidFile(file) {
                return true;
            }
        }

        return false;
    }
    
    /**
     * 验证是否为文件实例
     *
     * @param mixed $file
     * @return bool
     */
    public function isValidFile(var file) -> boolean
    {
        return is_object(file) && file instanceof SplFileObject && file->getPath() != "";
    }
    
    /**
     * 取回 header
     *
     * @param string $key
     * @param string|array|null $defaults
     * @return string|array
     */
    public function header(string key = null, var defaults = null)
    {
        return this->getItem("headers", key, defaults);
    }
    
    /**
     * 取回 server
     *
     * @param string $key
     * @param string|array|null $defaults
     * @return string|array
     */
    public function server(string key = null, var defaults = null)
    {
        return this->getItem("server", key, defaults);
    }
    
    /**
     * 取回数据项
     *
     * @param string $source
     * @param string $key
     * @param string|array|null $defaults
     * @return string|array
     */
    public function getItem(string source, string key, var defaults)
    {
        if is_null(key) {
            return this->{source}->all();
        }

        return this->{source}->get(key, defaults);
    }
    
    /**
     * 合并输入
     *
     * @param array $input
     * @return void
     */
    public function merge(array input)
    {
        this->getInputSource()->add(input);
    }
    
    /**
     * 替换输入
     *
     * @param array $input
     * @return void
     */
    public function replace(array input)
    {
        this->getInputSource()->replace(input);
    }
    
    /**
     * PHP 运行模式命令行, 兼容 swoole http service
     * Swoole http 服务器也以命令行运行
     * 
     * @link http://php.net/manual/zh/function.php-sapi-name.php
     * @return boolean
     */
    public function isCli() -> boolean
    {
        if this->server->get("SERVER_SOFTWARE") == "swoole-http-server" {
            return false;
        }

        return this->isRealCli();
    }
    
    /**
     * PHP 运行模式命令行
     * 
     * @link http://php.net/manual/zh/function.php-sapi-name.php
     * @return boolean
     */
    public function isRealCli() -> boolean
    {
        return "cli" == PHP_SAPI;
    }
    
    /**
     * PHP 运行模式 cgi
     *
     * @link http://php.net/manual/zh/function.php-sapi-name.php
     * @return boolean
     */
    public function isCgi() -> boolean
    {
        return substr(PHP_SAPI, 0, 3) == "cgi";
    }
    
    /**
     * 是否为 Ajax 请求行为
     *
     * @return boolean
     */
    public function isAjax() -> boolean
    {
        var field;
    
        let field = this->getOption("var_ajax");

        if this->request->has(field) || this->query->has(field) {
            return true;
        }

        return this->isRealAjax();
    }
    
    /**
     * 是否为 Ajax 请求行为真实
     *
     * @return boolean
     */
    public function isRealAjax() -> boolean
    {
        return this->headers->get("X_REQUESTED_WITH") === "xmlhttprequest";
    }
    
    /**
     * 是否为 Pjax 请求行为
     *
     * @return boolean
     */
    public function isPjax() -> boolean
    {
        var field;
    
        let field = this->getOption("var_pjax");

        if this->request->has(field) || this->query->has(field) {
            return true;
        }

        return this->isRealPjax();
    }
    
    /**
     * 是否为 Pjax 请求行为真实
     *
     * @return boolean
     */
    public function isRealPjax() -> boolean
    {
        return ! (is_null(this->headers->get("X_PJAX")));
    }
    
    /**
     * 是否为手机访问
     *
     * @return boolean
     */
    public function isMobile() -> boolean
    {
        var useAgent, allHttp, tmp;
    
        let useAgent = this->headers->get("USER_AGENT");
        let allHttp = this->server->get("ALL_HTTP");

        // Pre-final check to reset everything if the user is on Windows
        if strpos(useAgent, "windows") !== false {
            return false;
        }

        if preg_match("/(up.browser|up.link|mmp|symbian|smartphone|midp|wap|phone|iphone|ipad|ipod|android|xoom)/i", useAgent) {
            return true;
        }

        if strpos(this->headers->get("ACCEPT"), "application/vnd.wap.xhtml+xml") !== false {
            return true;
        }

        if this->headers->has("X_WAP_PROFILE") || this->headers->has("PROFILE") {
            return true;
        }

        let tmp = [
        	"w3c ", 
        	"acs-", 
        	"alav", 
        	"alca", 
        	"amoi", 
        	"audi", 
        	"avan", 
        	"benq", 
        	"bird", 
        	"blac", 
        	"blaz", 
        	"brew", 
        	"cell", 
        	"cldc", 
        	"cmd-", 
        	"dang", 
        	"doco", 
        	"eric", 
        	"hipt", 
        	"inno", 
        	"ipaq", 
        	"java", 
        	"jigs", 
        	"kddi", 
        	"keji", 
        	"leno", 
        	"lg-c", 
        	"lg-d", 
        	"lg-g", 
        	"lge-", 
        	"maui", 
        	"maxo", 
        	"midp", 
        	"mits", 
        	"mmef", 
        	"mobi", 
        	"mot-", 
        	"moto", 
        	"mwbp", 
        	"nec-", 
        	"newt", 
        	"noki", 
        	"oper", 
        	"palm", 
        	"pana", 
        	"pant", 
        	"phil", 
        	"play", 
        	"port", 
        	"prox", 
        	"qwap", 
        	"sage", 
        	"sams", 
        	"sany", 
        	"sch-", 
        	"sec-", 
        	"send", 
        	"seri", 
        	"sgh-", 
        	"shar", 
        	"sie-", 
        	"siem", 
        	"smal", 
        	"smar", 
        	"sony", 
        	"sph-", 
        	"symb", 
        	"t-mo", 
        	"teli", 
        	"tim-", 
        	"tosh", 
        	"tsm-", 
        	"upg1", 
        	"upsi", 
        	"vk-v", 
        	"voda", 
        	"wap-", 
        	"wapa", 
        	"wapi", 
        	"wapp", 
        	"wapr", 
        	"webc", 
        	"winw", 
        	"winw", 
        	"xda", 
        	"xda-"
        ];

        if in_array(strtolower(substr(useAgent, 0, 4)), tmp) {
            return true;
        }

        if strpos(strtolower(allHttp), "operamini") !== false {
            return true;
        }

        // But WP7 is also Windows, with a slightly different characteristic
        if strpos(useAgent, "windows phone") !== false {
            return true;
        }

        return false;
    }
    
    /**
     * 是否为 HEAD 请求行为
     *
     * @return boolean
     */
    public function isHead() -> boolean
    {
        return this->getMethod() == self::METHOD_HEAD;
    }
    
    /**
     * 是否为 GET 请求行为
     *
     * @return boolean
     */
    public function isGet() -> boolean
    {
        return this->getMethod() == self::METHOD_GET;
    }
    
    /**
     * 是否为 POST 请求行为
     *
     * @return boolean
     */
    public function isPost() -> boolean
    {
        return this->getMethod() == self::METHOD_POST;
    }
    
    /**
     * 是否为 PUT 请求行为
     *
     * @return boolean
     */
    public function isPut() -> boolean
    {
        return this->getMethod() == self::METHOD_PUT;
    }
    
    /**
     * 是否为 PATCH 请求行为
     *
     * @return boolean
     */
    public function isPatch() -> boolean
    {
        return this->getMethod() == self::METHOD_PATCH;
    }
    
    /**
     * 是否为 PURGE 请求行为
     *
     * @return boolean
     */
    public function isPurge() -> boolean
    {
        return this->getMethod() == self::METHOD_PURGE;
    }
    
    /**
     * 是否为 OPTIONS 请求行为
     *
     * @return boolean
     */
    public function isOptions() -> boolean
    {
        return this->getMethod() == self::METHOD_OPTIONS;
    }
    
    /**
     * 是否为 TRACE 请求行为
     *
     * @return boolean
     */
    public function isTrace() -> boolean
    {
        return this->getMethod() == self::METHOD_TRACE;
    }
    
    /**
     * 是否为 CONNECT 请求行为
     *
     * @return boolean
     */
    public function isConnect() -> boolean
    {
        return this->getMethod() == self::METHOD_CONNECT;
    }
    
    /**
     * 获取 IP 地址
     *
     * @return string
     */
    public function getClientIp() -> string
    {
        return this->headers->get("CLIENT_IP", this->server->get("REMOTE_ADDR", "0.0.0.0"));
    }
    
    /**
     * 请求类型
     *
     * @return string
     */
    public function getMethod() -> string
    {
        var method, field;
    
        if ! (is_null(this->method)) {
            return this->method;
        }

        let this->method = strtoupper(this->server->get("REQUEST_METHOD", "GET"));

        if this->method === "POST" {
            let method = this->headers->get("X-HTTP-METHOD-OVERRIDE");

            if method {
                let this->method = strtoupper(method);
            } else {
                let field = this->getOption("var_method");
                let this->method = strtoupper(this->request->get(field, this->query->get(field, "POST")));
            }
        }

        return this->method;
    }
    
    /**
     * 设置请求类型
     *
     * @param string $method
     * @return $this
     */
    public function setMethod(string method)
    {
        let this->method = null;

        this->server->set("REQUEST_METHOD", method);

        return this;
    }
    
    /**
     * 实际请求类型
     *
     * @return string
     */
    public function getRealMethod() -> string
    {
        return strtoupper(this->server->get("REQUEST_METHOD", "GET"));
    }
    
    /**
     * 取回应用名
     *
     * @return string
     */
    public function app() -> string
    {
        return this->app;
    }
    
    /**
     * 取回控制器名
     *
     * @return string
     */
    public function controller() -> string
    {
        return this->controller;
    }
    
    /**
     * 取回方法名
     *
     * @return string
     */
    public function action() -> string
    {
        return this->action;
    }
    
    /**
     * 取得节点
     *
     * @return string
     */
    public function getNode() -> string
    {
        return this->app() . "://" . this->controller() . "/" . this->action();
    }
    
    /**
     * 设置应用名
     *
     * @param string $app
     * @return $this
     */
    public function setApp(string app)
    {
        let this->app = app;

        return this;
    }
    
    /**
     * 设置控制器名
     *
     * @param string $controller
     * @return $this
     */
    public function setController(string controller)
    {
        let this->controller = controller;

        return this;
    }
    
    /**
     * 设置方法名
     *
     * @param string $action
     * @return $this
     */
    public function setAction(string action)
    {
        let this->action = action;

        return this;
    }
    
    /**
     * 返回当前的语言
     *
     * @return string|null
     */
    public function language()
    {
        return this->language;
    }
    
    /**
     * 设置当前的语言
     *
     * @param string $language
     * @return $this
     */
    public function setLanguage(string language)
    {
        let this->language = language;

        return this;
    }
    
    /**
     * 取得请求内容
     *
     * @return string|resource
     */
    public function getContent()
    {
        var resources;
    
        let resources = is_resource(this->content);

        if resources {
            rewind(this->content);
            return stream_get_contents(this->content);
        }

        if this->content === null || this->content === false {
            let this->content = file_get_contents("php://input");
        }

        return this->content;
    }
    
    /**
     * 返回网站公共文件目录
     *
     * @return string
     */
    public function getPublicUrl() -> string
    {
        if ! (is_null(this->publicUrl)) {
            return this->publicUrl;
        }

        let this->publicUrl = this->getOption("public");

        return this->publicUrl;
    }
    
    /**
     * 设置网站公共文件目录
     *
     * @param string $publicUrl
     * @return $this
     */
    public function setPublicUrl(string publicUrl)
    {
        let this->publicUrl = publicUrl;

        return this;
    }
    
    /**
     * 返回 root URL
     *
     * @return string
     */
    public function getRoot() -> string
    {
        return rtrim(this->getSchemeAndHttpHost() . this->getBaseUrl(), "/");
    }
    
    /**
     * 返回入口文件
     *
     * @return string
     */
    public function getEnter() -> string
    {
        var scriptName;
    
        let scriptName = this->getScriptName();

        if this->getOption("rewrite") !== true {
            return scriptName;
        }

        let scriptName = dirname(scriptName);
        if scriptName == "\\" {
            let scriptName = "/";
        }

        return scriptName;
    }
    
    /**
     * 取得脚本名字
     *
     * @return string
     */
    public function getScriptName() -> string
    {
        return this->server->get("SCRIPT_NAME", this->server->get("ORIG_SCRIPT_NAME", ""));
    }
    
    /**
     * 是否启用 https
     *
     * @return boolean
     */
    public function isSecure() -> boolean
    {
        var tmp;
    
        let tmp = ["1", "on"];

        if in_array(this->server->get("HTTPS"), tmp) {
            return true;
        } elseif this->server->get("SERVER_PORT") == "443" {
            return true;
        }

        return false;
    }
    
    /**
     * 取得 http host
     *
     * @return string
     */
    public function getHttpHost() -> string
    {
        var scheme, port;
    
        let scheme = this->getScheme();
        let port = this->getPort();

        if (scheme == "http" && 80 == port) || (scheme == "https" && 443 == port) {
            return this->getHost();
        }

        return this->getHost() . ":" . port;
    }
    
    /**
     * 获取 host
     *
     * @return string
     */
    public function getHost() -> string
    {
        return this->headers->get("X_FORWARDED_HOST", this->headers->get("HOST", ""));
    }
    
    /**
     * 取得 Scheme 和 Host
     *
     * @return string
     */
    public function getSchemeAndHttpHost() -> string
    {
        return this->getScheme() . "://" . this->getHost();
    }
    
    /**
     * 返回当前 URL 地址
     *
     * @return string
     */
    public function getUri() -> string
    {
        var queryString;
    
        let queryString = this->getQueryString();

        if queryString !== null {
            let queryString = "?" . queryString;
        }

        return this->getSchemeAndHttpHost() . this->getBaseUrl() . this->getPathInfo() . queryString;
    }
    
    /**
     * 服务器端口
     *
     * @return integer
     */
    public function getPort() -> int
    {
        var port;
    
        let port = this->server->get("SERVER_PORT");

        if ! (port) {
            let port = this->getScheme() === "https" ? 443 : 80;
        }

        return port;
    }
    
    /**
     * 返回 scheme
     *
     * @return string
     */
    public function getScheme() -> string
    {
        return this->isSecure() ? "https" : "http";
    }
    
    /**
     * 取回查询参数
     *
     * @return string|null
     */
    public function getQueryString()
    {
        var queryString;
    
        let queryString = this->normalizeQueryString(this->server->get("QUERY_STRING"));

        return queryString === "" ? null : queryString;
    }
    
    /**
     * 设置 pathInfo
     *
     * @param string $pathInfo
     * @return $this
     */
    public function setPathInfo(string pathInfo)
    {
        let this->pathInfo = pathInfo;

        return this;
    }
    
    /**
     * pathInfo 兼容性分析
     *
     * @return string
     */
    public function getPathInfo() -> string
    {
        var pathInfo, baseUrl, requestUri, pos;
    
        if ! (is_null(this->pathInfo)) {
            return this->pathInfo;
        }

        let pathInfo = this->server->get("PATH_INFO");
        if pathInfo {
            let this->pathInfo = this->parsePathInfo(pathInfo);
            return this->pathInfo;
        }

        // 服务器重写
        if this->query->get(self::PATHINFO_URL) {
            let pathInfo = this->parsePathInfo(this->query->get(self::PATHINFO_URL));
            this->query->remove(self::PATHINFO_URL);
            let this->pathInfo = pathInfo;
            return this->pathInfo;
        }

        // 分析基础 url
        let baseUrl = this->getBaseUrl();

        // 分析请求参数
        let requestUri = this->getRequestUri();
        if requestUri === null {
            let this->pathInfo = this->parsePathInfo("");
            return this->pathInfo;
        }

        let pos = strpos(requestUri, "?");
        if pos > 0 {
            let requestUri = substr(requestUri, 0, pos);
        }

        let pathInfo = substr(requestUri, strlen(baseUrl));
        if baseUrl !== null && pathInfo === false {
            let pathInfo = "";
        } elseif null === baseUrl {
            let pathInfo = requestUri;
        }

        let this->pathInfo = this->parsePathInfo(pathInfo);

        return this->pathInfo;
    }
    
    /**
     * 分析基础 url
     *
     * @return string
     */
    public function getBaseUrl() -> string
    {
        var fileName, url, path, segs, index, maxCount, pos, seg, requestUri;
    
        if ! (is_null(this->baseUrl)) {
            return this->baseUrl;
        }

        // 兼容分析
        let fileName = basename(this->server->get("SCRIPT_FILENAME"));

        if basename(this->server->get("SCRIPT_NAME")) === fileName {
            let url = this->server->get("SCRIPT_NAME");
        } elseif basename(this->server->get("PHP_SELF")) === fileName {
            let url = this->server->get("PHP_SELF");
        } elseif basename(this->server->get("ORIG_SCRIPT_NAME")) === fileName {
            let url = this->server->get("ORIG_SCRIPT_NAME");
        } else {
            let path = this->server->get("PHP_SELF");
            let segs = explode("/", trim(fileName, "/"));
            let segs = array_reverse(segs);
            let index = 0;
            let maxCount = count(segs);
            let url = "";

            do {
                let seg = segs[index];
                let url = "/" . seg . url;
                let index++;
            } while (maxCount > index && strpos(path, url) !== false && 0 !== strpos(path, url));
        }

        // 比对请求
        let requestUri = this->getRequestUri();

        if 0 === strpos(requestUri, url) {
            let this->baseUrl = url;
            return this->baseUrl;
        }

        if 0 === strpos(requestUri, dirname(url)) {
            let this->baseUrl = rtrim(dirname(url), "/");
            return this->baseUrl;
        }

        if ! (strpos(requestUri, basename(url))) {
            return "";
        }

        let pos = strpos(requestUri, url);
        if strlen(requestUri) >= strlen(url) && (pos !== false && pos !== 0) {
            let url = substr(requestUri, 0, pos + strlen(url));
        }

        let this->baseUrl = rtrim(url, "/");

        return this->baseUrl;
    }
    
    /**
     * 请求参数
     *
     * @return string
     */
    public function getRequestUri() -> string
    {
        var requestUri;
    
        if ! (is_null(this->requestUri)) {
            return this->requestUri;
        }

        let requestUri = this->headers->get("X_REWRITE_URL", this->server->get("REQUEST_URI", ""));

        if ! (requestUri) {
            let requestUri = this->server->get("ORIG_PATH_INFO");

            if this->server->get("QUERY_STRING") {
                let requestUri .= "?" . this->server->get("QUERY_STRING");
            }
        }

        let this->requestUri = requestUri;

        return this->requestUri;
    }

    /**
     * 修改单个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function option(string name, var value)
    {
        if ! is_string(name) {
            throw new InvalidArgumentException("Option set name must be a string.");
        }
        let this->option[name] = value;
        return this;
    }

    /**
     * 修改数组配置
     *
     * @param string $name
     * @param array $value
     * @return $this
     */
    public function optionArray(string name, array value)
    {
        return this->option(name, array_merge(this->getOption(name), value));
    }

    /**
     * 修改多个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function options(array option = [])
    {
    	var name, value;

        if empty option {
            return this;
        }

        for name, value in option {
        	this->option(name, value);
        }

        return this;
    }

    /**
     * 获取单个配置
     *
     * @param string $name
     * @param mixed $defaultss
     * @return mixed
     */
    public function getOption(string name, var defaultss = null)
    {
        return isset(this->option[name]) ? this->option[name] : defaultss;
    }

    /**
     * 获取所有配置
     *
     * @param array $option
     * @return mixed
     */
    public function getOptions(array option = [])
    {
    	if ! empty option {
    		return array_merge(this->option, option);
    	} else {
    		return this->option;
    	}
    }

    /**
     * 删除单个配置
     *
     * @param string $name
     * @return $this
     */
    public function deleteOption(string name)
    {
        if isset this->option[name] {
            unset(this->option[name]);
        }

        return this;
    }

    /**
     * 删除多个配置
     *
     * @param array $option
     * @return $this
     */
    public function deleteOptions(array option = [])
    {
    	var key;

        if ! empty option {
            return this;
        }

        for key in option {
        	this->deleteOption(key);
        }

        return this;
    }

    /**
     * 注册一个扩展
     *
     * @param string $name
     * @param callable $macro
     * @return void
     */
    public static function macro(string name, macro)
    {
        let self::macro[name] = macro;
    }
    
    /**
     * 判断一个扩展是否注册
     *
     * @param string $name
     * @return bool
     */
    public static function hasMacro(string name) -> bool
    {
        return isset self::macro[name];
    }

    /**
     * __callStatic 魔术方法隐射
     * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
     * 即 Closure::bind($closures, null, get_called_class())
     * 为保持功能一致，所以取消 PHP 版本的静态闭包绑定功能
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public static function callStaticMacro(string method, array args)
    {
        if self::hasMacro(method) {
            return call_user_func_array(self::macro[method], args);
        }

        throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
    }

    /**
     * __call 魔术方法隐射
     * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
     * 即 Closure::bind($closures, null, get_called_class())
     * 为保持功能一致，所以绑定对象但是不绑定作用域，即可以使用 $this,只能访问 public 属性
     * 
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function callMacro(string method, array args)
    {
        if self::hasMacro(method) {
            if self::macro[method] instanceof Closure {
            	return call_user_func_array(self::macro[method]->bindTo(this), args);
            } else {
                return call_user_func_array(self::macro[method], args);
            }
        }

        throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
    }
    
    /**
     * 判断字符串是否为数字
     *
     * @param mixed $value
     * @since bool
     */
    protected function isInt(var value)
    {
        if is_int(value) {
            return true;
        }

        return ctype_digit(strval(value));
    }
    
    /**
     * pathinfo 处理
     *
     * @param string $pathInfo
     * @return string
     */
    protected function parsePathInfo(string pathInfo) -> string
    {
        var suffix;
    
        if pathInfo && this->getOption("html_suffix") {
            let suffix = substr(this->getOption("html_suffix"), 1);
            let pathInfo = preg_replace("/\\." . suffix . "$/", "", pathInfo);
        }

        let pathInfo = empty(pathInfo) ? "/" : pathInfo;

        return pathInfo;
    }
    
    /**
     * 格式化查询参数
     * 
     * @param string $queryString
     * @return string
     */
    protected function normalizeQueryString(string queryString) -> string
    {
        var parts, item;
    
        if queryString == "" {
            return "";
        }

        let parts = [];
        for item in explode("&", queryString) {
            if strpos(item, self::PATHINFO_URL . "=") === 0 {
                continue;
            }

            let parts[] = item;
        }

        return implode("&", parts);
    }
    
    /**
     * 取得请求输入源
     *
     * @return \Queryyetsimple\Http\Bag
     */
    protected function getInputSource()
    {
        return  this->getMethod() == self::METHOD_GET ? this->query : this->request;
    }
    
    /**
     * 是否为空字符串
     *
     * @param string $key
     * @return bool
     */
    protected function isEmptyString(string key) -> boolean
    {
        var value;
    
        let value = this->input(key);

        return is_string(value) && trim(value) === "";
    }
    
    /**
     * 对象转数组
     *
     * @return array
     */
    public function toArray() -> array
    {
        return this->all();
    }
    
    /**
     * 实现 ArrayAccess::offsetExists
     *
     * @param string $offset
     * @return mixed
     */
    public function offsetExists(string offset)
    {
        return array_key_exists(offset, this->all());
    }
    
    /**
     * 实现 ArrayAccess::offsetGet
     *
     * @param string $offset
     * @return mixed
     */
    public function offsetGet(string offset)
    {
        return data_get(this->all(), offset);
    }
    
    /**
     * 实现 ArrayAccess::offsetSet
     *
     * @param string $offset
     * @param mixed $value
     * @return mixed
     */
    public function offsetSet(string offset, var value)
    {
        return this->getInputSource()->set(offset, value);
    }
    
    /**
     * 实现 ArrayAccess::offsetUnset
     *
     * @param string $offset
     * @return void
     */
    public function offsetUnset(string offset)
    {
        return this->getInputSource()->remove(offset);
    }
    
    /**
     * 是否存在输入值
     *
     * @param string $key
     * @return bool
     */
    public function __isset(string key) -> boolean
    {
        return ! (is_null(this->__get(key)));
    }
    
    /**
     * 获取输入值
     *
     * @param string $key
     * @return mixed
     */
    public function __get(string key)
    {
        return this->get(key);
    }

    /**
     * __callStatic 魔术方法
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public static function __callStatic(string method, array args)
    {
        return self::callStaticMacro(method, args);
    }
    
    /**
     * __call 魔术方法
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function __call(string method, array args)
    {
        return this->callMacro(method, args);
    }
}