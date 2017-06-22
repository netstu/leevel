<?php
// [$QueryPHP] The PHP Framework For Code Poem As Free As Wind. <Query Yet Simple>
// ©2010-2017 http://queryphp.com All rights reserved.
namespace queryyetsimple\rss\interfaces;

<<<queryphp
##########################################################
#   ____                          ______  _   _ ______   #
#  /     \       ___  _ __  _   _ | ___ \| | | || ___ \  #
# |   (  ||(_)| / _ \| '__|| | | || |_/ /| |_| || |_/ /  #
#  \____/ |___||  __/| |   | |_| ||  __/ |  _  ||  __/   #
#       \__   | \___ |_|    \__  || |    | | | || |      #
#     Query Yet Simple      __/  |\_|    |_| |_|\_|      #
#                          |___ /  Since 2010.10.03      #
##########################################################
queryphp;

/**
 * rss 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.04.23
 * @version 1.0
 */
interface rss {
    
    /**
     * 生成 rss
     *
     * @return void
     */
    public function run($booDisplay = true);
    
    /**
     * 添加一个 rss 项数据
     *
     * @param array $arrItem            
     * @return void
     */
    public function addItem($arrItem);
    
    /**
     * 更改配置
     *
     * @param string|array $mixKey            
     * @param string|null $sValue            
     * @return void
     */
    public function setOption($mixKey, $sValue = null);
    
    /**
     * 返回配置
     *
     * @param string $sKey            
     * @return string
     */
    public function getOption($sKey);
}
