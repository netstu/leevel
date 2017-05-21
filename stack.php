<?php
// [$QueryPHP] A PHP Framework Since 2010.10.03. <Query Yet Simple>
// ©2010-2017 http://queryphp.com All rights reserved.
namespace queryyetsimple\datastruct\queue;

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
 * 栈，后进先出
 *
 * @author Xiangmin Liu<635750556@qq.com>
 * @package $$
 * @since 2016.11.21
 * @version 1.0
 */
class stack extends stack_queue {
    
    /**
     * 进栈
     *
     * @param mixed $mixItem            
     * @return void
     */
    public function in($Item) {
        $this->arrElements [] = &$Item;
    }
    
    /**
     * 出栈
     *
     * @return mixed
     */
    public function out() {
        if (! $this->getLength ()) {
            return null;
        }
        return array_pop ( $this->arrElements );
    }
}
