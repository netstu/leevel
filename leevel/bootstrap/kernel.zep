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
use Throwable;
use ErrorException;
use Leevel\Http\IRequest;
use Leevel\Router\Router;
use Leevel\Kernel\IKernel;
use Leevel\Http\IResponse;
use Leevel\Kernel\IProject;
use Leevel\Http\ApiResponse;
use Leevel\Http\JsonResponse;
use Leevel\Http\RedirectResponse;
use Leevel\Support\Debug\Console;

/**
 * 内核执行
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2016.11.18
 * 
 * @version 1.0
 */
abstract class Kernel implements IKernel
{
    /**
     * 项目
     *
     * @var \Leevel\Kernel\IProject
     */
    protected project;
    
    /**
     * 路由
     *
     * @var \Leevel\Router\Router
     */
    protected router;
    
    /**
     * 项目初始化执行
     *
     * @var array
     */
    protected bootstraps = [
        "Leevel\\Bootstrap\\Bootstrap\\LoadOption",
        "Leevel\\Bootstrap\\Bootstrap\\LoadI18n",
        "Leevel\\Bootstrap\\Bootstrap\\RegisterRuntime",
        "Leevel\\Bootstrap\\Bootstrap\\TraverseProvider"
    ];
    
    /**
     * 构造函数
     *
     * @param \Leevel\Kernel\IProject $project
     * @param \Leevel\Router\Router $router
     * @return void
     */
    public function __construct(<IProject> project, <Router> router)
    {
        let this->project = project;
        let this->router = router;
    }
    
    /**
     * 响应 HTTP 请求
     *
     * @param \Leevel\Http\IRequest $request
     * @return \Leevel\Http\IResponse
     */
    public function handle(<IRequest> request)
    {
        var response, e, fatalException;
    
        try {
            this->registerBaseService(request);

            this->bootstrap();

            let response = this->getResponseWithRequest(request);

            let response = this->prepareTrace(response);
        } catch Exception, e {
            this->reportException(e);

            let response = this->renderException(request, e);
        } catch Throwable, e {
            let fatalException = new ErrorException(     
                e->getMessage(),
                e->getCode(),
                E_ERROR,
                e->getFile(),
                e->getLine(),
                e->getPrevious()
            );

            this->reportException(fatalException);

            let response = this->renderException(request, fatalException);
        }

        return response;
    }
    
    /**
     * 返回运行处理器
     * 
     * @return \Leevel\Bootstrap\Runtime\IRuntime
     */
    protected function getRuntime()
    {
        return this->project->make("Leevel\\Kernel\\Runtime\\IRuntime");
    }
    
    /**
     * 执行结束
     *
     * @param \Leevel\Http\IRequest $request
     * @param \Leevel\Http\IResponse $response
     * @return void
     */
    public function terminate(<IRequest> request, <IResponse> response)
    {
        this->router->throughMiddleware(request, [response]);
    }
    
    /**
     * 返回项目
     *
     * @return \Leevel\Kernel\IProject
     */
    public function getProject()
    {
        return this->project;
    }
    
    /**
     * 注册基础服务
     * 
     * @param \Leevel\Http\IRequest $request
     * @return void
     */
    protected function registerBaseService(<IRequest> request)
    {
        this->project->instance("request", request);
    }
    
    /**
     * 根据请求返回响应
     *
     * @param \Leevel\Http\IRequest $request
     * @return \Leevel\Http\IResponse
     */
    protected function getResponseWithRequest(<IRequest> request)
    {
        return this->dispatchRouter(request);
    }
    
    /**
     * 路由调度
     *
     * @param \Leevel\Http\IRequest $request
     * @return \Leevel\Http\IResponse
     */
    protected function dispatchRouter(<IRequest> request)
    {
        return this->router->dispatch(request);
    }
    
    /**
     * 初始化
     *
     * @return void
     */
    protected function bootstrap()
    {
        this->project->bootstrap(this->bootstraps);
    }
    
    /**
     * 上报错误
     *
     * @param \Exception $e
     * @return void
     */
    protected function reportException(<Exception> e)
    {
        this->getRuntime()->report(e);
    }
    
    /**
     * 渲染异常
     *
     * @param \Leevel\Http\IRequest $request
     * @param \Exception $e
     * @return \Leevel\Http\IResponse
     */
    protected function renderException(<IRequest> request, <Exception> e)
    {
        return this->getRuntime()->render(request, e);
    }
    
    /**
     * 调试信息
     *
     * @param \Leevel\Http\IResponse $response
     * @return \Leevel\Http\IResponse
     */
    protected function prepareTrace(<IResponse> response)
    {
        var logs, data;
    
        if ! (this->project->debug()) {
            return response;
        }

        let logs = this->project->make("Leevel\\Log\\ILog")->get();
        let data = response->getData();

        if (response instanceof ApiResponse || 
            response instanceof JsonResponse || 
            response->isJson()) && is_array(data) {
            let data["_TRACE"] = Console::jsonTrace(logs);
            response->setData(data);
        } elseif ! (response instanceof RedirectResponse) {
            let data = Console::trace(logs);
            response->appendContent(data);
        }

        return response;
    }
}
