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
namespace Queryyetsimple\Mvc;

use Closure;
use RuntimeException;
use Queryyetsimple\Mvc\Iview;
use Queryyetsimple\View\Itheme;
use Queryyetsimple\View\Iview as view_iview;

/**
 * 视图
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.02
 * @version 1.0
 */
class View implements Iview
{

	/**
	 * 视图模板
	 *
	 * @var \queryyessimple\view\iview
	 */
	protected theme;

	/**
     * 备份视图模板
     *
     * @var \queryyessimple\view\iview
     */
    protected backupTheme;

    /**
     * 是否永久切换
     *
     * @var boolean
     */
    protected foreverSwitch = false;

	/**
	 * 响应工厂
	 *
	 * @var \Closure
	 */
	protected responseFactory;

	/**
	 * 响应
	 *
	 * @var \queryyetsimple\http\response
	 */
	protected response;

	/**
	 * 构造函数
	 *
	 * @param \queryyetsimple\view\iview $theme
	 * @return void
	 */
	public function __construct(<view_iview> theme)
	{
		let this->theme = theme;
	}

	/**
     * 切换视图
     *
     * @param \queryyetsimple\view\iview $theme
     * @param boolean $foreverSwitch
     * @return $this
     */
    public function switchView(<view_iview> theme, boolean foreverSwitch = false)
    {
    	var assign;

        let assign = this->getAssign();

        if foreverSwitch === false {
            let this->backupTheme = this->theme;
        }
        
        let this->foreverSwitch = foreverSwitch;
        let this->theme = theme;
        this->assign(assign);

        return this;
    }

	/**
	 * 设置响应工厂
	 *
	 * @param \Closure $responseFactory
	 * @return $this;
	 */
	public function setResponseFactory(<Closure> responseFactory)
	{
		let this->responseFactory = responseFactory;
		return this;
	}

	/**
	 * 获取响应
	 *
	 * @return \queryyetsimple\http\response $response
	 */
	public function getResponse()
	{
		if ! this->response {
			let this->response = call_user_func(this->responseFactory);
		}
		return this->response;
	}

	/**
	 * 变量赋值
	 *
	 * @param mixed $name
	 * @param mixed $value
	 * @return $this
	 */
	public function assign(var name, var value = null)
	{
		this->checkTheme();
		this->theme->setVar(name, value);
		return this;
	}

	/**
	 * 获取变量赋值
	 *
	 * @param string|null $name
	 * @return mixed
	 */
	public function getAssign(var name = null)
	{
		this->checkTheme();
		return this->theme->getVar(name);
	}

	/**
	 * 删除变量值
	 *
	 * @param mixed $name
	 * @return $this
	 */
	public function deleteAssign(var name)
	{
		var args;

		this->checkTheme();

		let args = func_get_args();

		call_user_func_array([
			this->theme,
			"deleteVar"
		], args);

		return this;
	}

	/**
	 * 清空变量值
	 *
	 * @param string|null $name
	 * @return $this
	 */
	public function clearAssign()
	{
		this->checkTheme();
		this->theme->clearVar();
		return this;
	}

	/**
	 * 加载视图文件
	 *
	 * @param string $file
	 * @param array $option
	 * @sub string charset 编码
	 * @sub string content_type 内容类型
	 * @return string
	 */
	public function display(string file = null, array option = [])
	{
		var arrInitOption, result;

		this->checkTheme();

		let arrInitOption = [
			"charset" : "utf-8",
			"content_type" : "text/html"
		];
		if empty option {
			let option = [];
		}
		let option = array_merge(arrInitOption, option);

		this->responseHeader(option["content_type"], option["charset"]);

		let result = this->theme->display(file, false);

		if this->foreverSwitch === false {
            let this->theme = this->backupTheme;
        }
        let this->foreverSwitch = false;

		return result;
	}

	/**
	 * 验证 theme
	 *
	 * @return void
	 */
	protected function checkTheme()
	{
		if ! this->theme {
			throw new RuntimeException("Theme is not set in view");
		}
	}

	/**
	 * 发送 header
	 *
	 * @param string $contentType
	 * @param string $charset
	 * @return void
	 */
	protected function responseHeader(string contentType = "text/html", string charset = "utf-8")
	{
		this->getResponse();

		if ! this->response {
			throw new RuntimeException("Response is not set in view");
		}

		this->response->contentType(contentType)->charset(charset);
	}
}
