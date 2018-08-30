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
namespace Leevel\View;

use RuntimeException;

/**
 * 模板处理抽象类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.02
 * @version 1.0
 */
abstract class Connect
{

    /**
     * 变量值
     *
     * @var array
     */
    protected vars = [];

    /**
     * 配置
     *
     * @var array
     */
    protected option = [];

    /**
     * 构造函数
     *
     * @param array option
     * @return void
     */
    public function __construct(array option = [])
    {
        let this->option = array_merge(this->option, option);
    }

    /**
     * 设置配置
     * 
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function setOption(string name, var value)
    {
        let this->option[name] = value;

        return this;
    }

    /**
     * 设置模板变量
     *
     * @param mixed $name
     * @param mixed $value
     * @return void
     */
    public function setVar(var name, var value = null)
    {
        if is_array(name) {
            let this->vars = array_merge(this->vars, name);
        } else {
            let this->vars[name] = value;
        }
    }

    /**
     * 获取变量值
     *
     * @param string|null $name
     * @return mixed
     */
    public function getVar(var name = null)
    {
        if typeof name == "null" {
            return this->vars;
        }
        
        return isset(this->vars[name]) ? this->vars[name] : null;
    }

    /**
     * 删除变量值
     *
     * @return $this
     */
    public function deleteVar()
    {
        var item, name, args = [];

        let args = func_get_args();

        if empty args {
            throw new BadMethodCallException("Wrong number of parameters");
        }

        let name = typeof args[0] === "array" ? args[0] : args;

        for item in name {
            if isset this->vars[item] {
                unset(this->vars[item]);
            }
        }

        return this;
    }

    /**
     * 清空变量值
     *
     * @param string|null $name
     * @return $this
     */
    public function clearVar()
    {
        let this->vars = [];
        return this;
    }

    /**
     * 分析展示的视图文件
     *
     * @param string $file 视图文件地址
     * @param string $ext 后缀
     * @return string|void
     */
    protected function parseDisplayFile(string file, string ext = "")
    {
        // 加载视图文件
        if ! is_file(file) {
            let file = this->parseFile(file, ext);
        }

        // 分析默认视图文件
        if ! is_file(file) {
            let file = this->parseDefaultFile(file);
        }

        if ! is_file(file) {
            throw new RuntimeException(
                sprintf("Template file %s does not exist.", file)
            );
        }

        return file;
    }

    /**
     * 分析模板真实路径            
     *
     * @param string $tpl 文件地址
     * @param string $ext 扩展名
     * @return string
     */
    protected function parseFile(string tpl, string ext = "")
    {
        var arr, theme, tempTheme, tempTpl, result = "";

        let tpl = trim(str_replace("->", ".", tpl));

        // 完整路径或者变量
        if pathinfo(tpl, PATHINFO_EXTENSION) ||
            strpos(tpl, "$") === 0 ||
            strpos(tpl, "(") !== false {
            return this->formatFile(tpl);
        } else {
            if ! this->option["theme_path"] {
                throw new RuntimeException("Theme path must be set.");
            }

            // 空取默认控制器和方法
            if tpl == "" {
                let tpl = this->option["controller_name"] .
                    this->option["controlleraction_depr"] .
                    this->option["action_name"];
            }

            // 分析主题
            if strpos(tpl, "@") !== false {
                let arr = explode("@", tpl);
                let tempTheme = array_shift(arr);
                let theme = tempTheme;
                let tempTpl = array_shift(arr);
                let tpl = tempTpl; 
            }

            let tpl = str_replace([
                "+",
                ":"
            ], this->option["controlleraction_depr"], tpl);

            let result = dirname(this->option["theme_path"]) . "/";
            if theme {
                let result .= theme . "/";
            } else {
                let result .= this->option["theme_name"] . "/";
            }

            let result .= tpl;

            if ! empty ext {
                let result .= ext;
            } else {
                let result .= this->option["suffix"];
            }

            return result;
        }
    }

    /**
     * 格式化文件名
     *
     * @param string $content
     * @return string
     */
    protected function formatFile(string content)
    {
        return str_replace([
            ":",
            "+"
        ], [
            "->",
            "::"
        ], content);
    }

    /**
     * 匹配默认地址（文件不存在）
     *
     * @param string $tpl 文件地址
     * @return string
     */
    protected function parseDefaultFile(string tpl)
    {
        var source, tempTpl;

        if ! $this->option["theme_path"] {
            throw new RuntimeException("Theme path must be set.");
        }

        let source = tpl;

        // 物理路径
        if strpos(tpl, ":") !== false ||
            strpos(tpl, "/") === 0 ||
            strpos(tpl, "\\") === 0 {
            let tpl = str_replace(
                str_replace(
                    "\\",
                    "/",
                    this->option["theme_path"] . "/"
                ),
                "",
                str_replace("\\", "/", tpl)
            );
        }

        // 备用地址
        let tempTpl = this->option["theme_path_default"] . "/" . tpl;

        if this->option["theme_path_default"] && is_file(tempTpl) {
            return tempTpl;
        }

        // default 主题
        let tempTpl = dirname(this->option["theme_path"]) . "/default/" . tpl;
        
        if this->option["theme_name"] != "default" && is_file(tempTpl) {
            return tempTpl;
        }

        return source;
    }
}
