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

use RuntimeException;
use BadFunctionCallException;
use Queryyetsimple\Mvc\Iview;
use Queryyetsimple\Mvc\Iaction;
use Queryyetsimple\Router\Router;
use Queryyetsimple\Mvc\Icontroller;
use Queryyetsimple\View\Iview as view_iview;

/**
 * 基类方法器
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
abstract class Action implements Iaction
{

    /**
     * 父控制器
     *
     * @var \queryyetsimple\mvc\icontroller
     */
    protected controller;

    /**
     * 构造函数
     *
     * @return void
     */
    public function __construct()
    {
    }

    /**
     * 设置父控制器
     *
     * @param \queryyetsimple\mvc\icontroller $controller
     * @return $this
     */
    public function setController(<Icontroller> controller)
    {
        let this->controller = controller;
        return this;
    }

    /**
     * 设置视图
     *
     * @param \queryyetsimple\mvc\iview $view
     * @return $this
     */
    public function setView(<Iview> view)
    {
        this->checkController();
        return this->controller->setView(view);
    }

    /**
     * 设置路由
     *
     * @param \queryyetsimple\router\router $router
     * @return $this
     */
    public function setRouter(<Router> router)
    {
        this->checkController();
        return this->controller->setRouter(router);
    }

    /**
     * 执行子方法器
     *
     * @param string $action 方法名
     * @return void
     */
    public function action(string action)
    {
        this->checkController();
        return this->controller->action(action);
    }

    /**
     * 切换视图
     *
     * @param \queryyetsimple\view\iview $theme
     * @param boolean $forever
     * @return $this
     */
    public function switchView(<view_iview> theme, boolean forever = false)
    {
        this->checkController();
        this->controller->switchView(theme, forever);
        return this;
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
        this->checkController();
        return this->controller->assign(name, value);
    }

    /**
     * 获取变量赋值
     *
     * @param string|null $name
     * @return mixed
     */
    public function getAssign(string $name = null)
    {
        this->checkController();
        return this->controller->getAssign(name);
    }

    /**
     * 删除变量值
     *
     * @param mixed $name
     * @return $this
     */
    public function deleteAssign(name)
    {
    	var args;

        this->checkController();

        let args = func_get_args();

        call_user_func_array([
        	this->controller,
        	"deleteAssign"
        ], args);

        return this;
    }

    /**
     * 清空变量值
     *
     * @return $this
     */
    public function clearAssign()
    {
        this->checkController();
        this->controller->clearAssign();
        return this;
    }

    /**
     * 加载视图文件
     *
     * @param string $file
     * @param array $option
     * @sub string charset 编码
     * @sub string content_type 类型
     * @return string
     */
    public function display(string file = null, array option = [])
    {
        this->checkController();
        return this->controller->display(file, option);
    }

    /**
     * 验证 controller
     *
     * @return void
     */
    protected function checkController()
    {
        if ! this->controller {
            throw new RuntimeException("Controller is not set in action");
        }
    }

    /**
     * call 
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function __call(string method, array args)
    {
        if method == "run" {
            throw new BadFunctionCallException(sprintf("Run method is not allowed."));
        }
        throw new BadFunctionCallException(sprintf("Method %s is not defined.", method));
    }
}
