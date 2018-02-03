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
namespace Queryyetsimple\Event;

use SplSubject;
use SplObserver;
use RuntimeException;

/**
 * 观察者角色 observer
 * \SplObserver 无法识别 container
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.02.01
 * @link http://php.net/manual/zh/class.splobserver.php
 * @version 1.0
 */
class Observer implements SplObserver
{

    /**
     * 观察者目标角色 subject
     *
     * @var \SplSubject
     */
    protected subject;
    
    /**
     * 构造函数
     *
     * @return void
     */
    public function __construct()
    {
    }
    
    /**
     * {@inheritdoc}
     */
    public function update(<SplSubject> subject) -> void
    {
        var method, tmp, tmp1;
    
        let method = method_exists(this, "handle") ? "handle" : "run";
        let tmp = [this, method];

        if ! (is_callable(tmp)) {
            throw new RuntimeException(sprintf("Observer %s must has run method", get_class(this)));
        }

        let tmp1 = [this, method];
        subject->container->call(tmp1, subject->notifyArgs);
    }
}
