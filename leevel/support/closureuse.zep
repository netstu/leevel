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
namespace Leevel\Support;

use Closure;

/**
 * zephir 不支持 Closure use 替代解决方案
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.24
 * @version 1.0
 */
class ClosureUse {

    /**
     * 待处理的闭包
     *
     * @var \Closure
     */
    protected closures;

    /**
     * use 参数
     *
     * @var array
     */
    protected args = [];

    /**
     * 构造函数
     *
     * @param \Closure $closures
     * @param array $args
     * @return void
     */
    public function __construct(<Closure> closures, array args = []) -> void
    {
	    let this->closures = closures;
	    let this->args = args;
    }

    /**
     * 生成仿 use 闭包
     * 
     * @param \Closure $closures
     * @param array $args
     * @return \Closure
     */
    public static function make(<Closure> closures, array args = []) -> <Closure>
    {
    	var newclosure;
    	let newclosure = new self(closures, args);
        return Closure::fromCallable([newclosure, "invoke"]);
    }

    /**
     * __invoke 魔术方法不支持
     *
     * @return mixed
     */
    protected function invoke() 
    {
        var args = [], item;

        let args = func_get_args();

        if this->args {
            for item in this->args {
                let args[] = item;
            }
        }

        return call_user_func_array(this->closures, args);
    }
}
