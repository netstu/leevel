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
namespace Queryyetsimple\Router;

use Closure;
use Queryyetsimple\Http\IRequest;
use Queryyetsimple\Option\IClass;

/**
 * url 生成
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.08
 * @version 1.0
 */
class Url implements IUrl, IClass
{

    /**
     * HTTP 请求
     * 
     * @var \Queryyetsimple\Http\IRequest
     */
    protected request;
    
    /**
     * 解析后的 MVC 参数
     * 
     * @var array
     */
    protected parseMvc = [];
    
    /**
     * http 前缀
     * 
     * @var string
     */
    protected httpPrefix;
    
    /**
     * http 后缀
     * 
     * @var string
     */
    protected httpSuffix;
    
    /**
     * 生成 url 默认配置
     * 
     * @var array
     */
    protected makeOption = [
    	"suffix" : true, 
    	"normal" : false, 
    	"subdomain" : "www"
    ];
    
    /**
     * 配置
     *
     * @var array
     */
    protected option = [
    	"default_app" : "home", 
    	"default_controller" : "index", 
    	"default_action" : "index", 
    	"model" : "pathinfo", 
    	"html_suffix" : ".html", 
    	"router_domain_top" : "", 
    	"make_subdomain_on" : true
    ];
    
    /**
     * 构造函数
     * 
     * @param \Queryyetsimple\Http\IRequest $request
     * @param array $option
     * @return void
     */
    public function __construct(<IRequest> request, array option = [])
    {
        let this->request = request;

        this->options(option);
    }
    
    /**
     * 生成路由地址
     *
     * @param string $url
     * @param array $params
     * @param array $option
     * @sub boolean suffix 是否包含后缀
     * @sub boolean normal 是否为普通 url
     * @sub string subdomain 子域名
     * @return string
     */
    public function make(string url, array params = [], array option = []) -> string
    {
        var custom, result;
    
        let option = array_merge(this->makeOption, option);

        let custom = this->isCustom(url);

        let this->parseMvc = this->parseMvc(url, params, custom);

        if this->isNotNormal(option["normal"], custom) {
            if custom === false {
                let result = this->pathinfoUrl();
            } else {
                let result = this->customUrl(url);
            }

            let result = this->withSuffix(result, option["suffix"]);

            if this->parseMvc["params"] {
                let result .= "?" . http_build_query(this->parseMvc["params"]);
            }
        } else {
            let result = this->normalUrl(option["normal"]);
        }

        let result = this->urlWithDomain(result, option["subdomain"]);

        return result;
    }
    
    /**
     * 返回 HTTP 请求
     * 
     * @return \Queryyetsimple\Http\IRequest
     */
    public function getRequest()
    {
        return this->request;
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
     * pathinfo url 解析
     * 
     * @return string
     */
    protected function pathinfoUrl() -> string
    {
        var url;
    
        let url = this->parseEnter() . (! this->equalDefault("app") ? "/" . this->parseMvc["app"] . "/" : "/");
        
        if this->parseMvc["prefix"] {
            let this->parseMvc["action"] = str_replace("\\", "/", this->parseMvc["prefix"]) . "/" . this->parseMvc["action"];
        }

        if ! this->equalDefault("controller") || ! this->equalDefault("action") {
            let url .= this->parseMvc["controller"];
        }

        if ! this->equalDefault("action") {
            let url .= "/" . this->parseMvc["action"];
        }

        return url;
    }
    
    /**
     * 自定义 URL
     * 
     * @param string $url
     * @return string
     */
    protected function customUrl(string url) -> string
    {
        var result, tmp, k, v, tmpQuery;
    
        if strpos(url, "{") !== false {
	        let result = preg_replace_callback("/{(.+?)}/", Closure::fromCallable([this, "matchVar"]), url);
        } else {
        	let result = url;
        }

        if strpos(result, "?") !== false {
            let tmp = explode("?", result);
            let result = tmp[0];
            let tmpQuery = [];

            parse_str(tmp[1], tmpQuery);

            for k, v in this->parseMvc["params"] {
                let tmpQuery[k] = v;
            }

            let this->parseMvc["params"] = tmpQuery;
        }
        
        return result;
    }

    /**
     * 匹配 URL 变量
     * 
     * @param array $match
     * @return string
     */
    protected function matchVar(matchs) {
    	var result, params = [], key;

    	let params = this->parseMvc["params"];
    	let key = matchs[1];

        if isset params[matchs[1]] {
            let result = params[key];
            unset params[key];
        } else {
            let result = matchs[0];
        }

        let this->parseMvc["params"] = params;

        return result;
    }
    
    /**
     * 普通 url 生成
     * 
     * @param bool $normal
     * @return string
     */
    protected function normalUrl(bool normal) -> string
    {
        var querys, params, key, val, url;
    
        let querys = [];

        if normal || ! this->equalDefault("app") {
            let querys[IRouter::APP] = this->parseMvc["app"];
        }

        if ! this->equalDefault("controller") {
            let querys[IRouter::CONTROLLER] = this->parseMvc["controller"];
        }

        if ! this->equalDefault("action") {
            let querys[IRouter::ACTION] = this->parseMvc["action"];
        }

        if this->parseMvc["prefix"] {
            let querys[IRouter::PREFIX] = this->parseMvc["prefix"];
        }

        let params = this->parseMvc["params"];

        for key, val in params {
            let querys[key] = val;
        }

        let url = this->parseEnter(normal) . (querys ? "?" . http_build_query(querys) : "");

        return url;
    }
    
    /**
     * 解析 MVC 参数
     * 
     * @param string $url
     * @param array $params
     * @param bool $custom
     * @return array
     */
    protected function parseMvc(string url, array params, bool custom) -> array
    {
        var tmp, tmp1, parse, result, mvc, key, item, tmpAction, tmpQuery, k, v;

        if custom {
            let tmp = [
            	"params" : params
            ];

            return tmp;
        }

        let tmp1 = [
        	"", 
        	"/"
        ];

        if ! (in_array(url, tmp1)) {
            if ! (strpos(url, "://")) {
                let url = this->request->app() . "://" . url;
            }
            let parse = parse_url(url);
        } else {
            let parse = [];
        }

        let result = [
        	"app" : "", 
        	"controller" : "", 
        	"action" : "", 
        	"params" : [], 
        	"prefix" : ""
        ];

        if url === "/" {
            let result["app"] = this->getOption("default_app");
            let result["controller"] = this->getOption("default_controller");
            let result["action"] = this->getOption("default_action");
        }

        // app、controller 和 action
        let result["app"] = isset parse["scheme"] ? parse["scheme"] : this->request->app();

        let mvc = [
        	IRouter::APP : "app", 
        	IRouter::CONTROLLER : "controller", 
        	IRouter::ACTION : "action"
        ];

        for key, item in mvc {
            if isset params[key] {
                let result[item] = params[key];
                unset params[key];
            }
        }

        if isset parse["path"] {
            if ! (result["controller"]) {
                let result["controller"] = isset parse["host"] ? parse["host"] : this->request->controller();
            }

            if ! (result["action"]) {
                let result["action"] = substr(parse["path"], 1);
            }
        } else {
            if ! (result["controller"]) {
                let result["controller"] = isset parse["host"] ? parse["host"] : this->request->controller();
            }

            if ! (result["action"]) {
                let result["action"] = this->request->action();
            }
        }

        if strpos(result["action"], "/") !== false {
            let tmpAction = explode("/", result["action"]);
            let result["action"] = array_pop(tmpAction);
            let result["prefix"] = implode("\\", tmpAction);
        }

        if isset parse["query"] {
        	let tmpQuery = [];
            parse_str(parse["query"], tmpQuery);

            for k, v in params {
               let tmpQuery[k] = v;
            }

            let result["params"] = tmpQuery;
        } else {
        	let result["params"] = params;
        }

        return result;
    }
    
    /**
     * 返回完整 URL 地址
     *
     * @param string $url
     * @param string $domain
     * @return string
     */
    protected function urlWithDomain(string url, string domain) -> string
    {
        if this->getOption("make_subdomain_on") !== true || 
        	! this->getOption("router_domain_top") || 
        	empty domain {
            return url;
        }

        if is_null(this->httpPrefix) {
            let this->httpPrefix = this->isSecure() ? "https://" : "http://";
            let this->httpSuffix = this->getOption("router_domain_top");
        }

        return this->httpPrefix . 
        	(domain && domain != "*" ? domain . "." : "") . 
        	this->httpSuffix . 
        	url;
    }
    
    /**
     * 是否启用 https
     *
     * @return boolean
     */
    protected function isSecure() -> boolean
    {
        return this->request->isSecure();
    }
    
    /**
     * 是否非默认 url
     * 
     * @param bool $normal
     * @param bool $custom
     * @return boolean
     */
    protected function isNotNormal(bool normal, bool custom) -> boolean
    {
        return this->getOption("model") == "pathinfo" && normal === false || custom === true;
    }
    
    /**
     * url 带后缀
     * 
     * @param string $url
     * @param string|boolean $suffix
     * @return string
     */
    protected function withSuffix(string url, suffix) -> string
    {
        if suffix && url && url != "/" {
            let url .=  suffix === true ? this->getOption("html_suffix") : suffix;
        }

        return url;
    }
    
    /**
     * 是否为默认 app、controller 或则 action
     * 
     * @param string $type
     * @return boolean
     */
    protected function equalDefault(string type) -> boolean
    {
        return this->getOption("default_" . type) === this->parseMvc[type];
    }
    
    /**
     * 分析入口文件
     * 
     * @param boolean $normal
     * @return string
     */
    protected function parseEnter(bool normal = false) -> string
    {
        var enter;
    
        let enter = this->request->getEnter();

        return normal === true || enter !== "/" ? enter : "";
    }
    
    /**
     * 以 “/” 开头的为自定义 URL
     * 
     * @param string $url
     * @return boolean
     */
    protected function isCustom(string url) -> boolean
    {
        return url !== "/" && 0 === strpos(url, "/");
    }
}
