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
namespace Queryyetsimple\Option;

/**
 * IClass 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.22
 * @version 1.0
 */
interface IClass
{

    /**
     * 修改单个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function option(string name, var value);

    /**
     * 修改数组配置
     *
     * @param string $name
     * @param array $value
     * @return $this
     */
    public function optionArray(string name, array value);

    /**
     * 修改多个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function options(array option = []);

    /**
     * 获取单个配置
     *
     * @param string $name
     * @param mixed $defaults
     * @return mixed
     */
    public function getOption(string name, var defaults = null);

    /**
     * 获取所有配置
     *
     * @param array $option
     * @return mixed
     */
    public function getOptions(array option = []);

    /**
     * 删除单个配置
     *
     * @param string $name
     * @return $this
     */
    public function deleteOption(string name);

    /**
     * 删除多个配置
     *
     * @param array $option
     * @return $this
     */
    public function deleteOptions(array option = []);
}
