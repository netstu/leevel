<?php
// [$QueryPHP] A PHP Framework Since 2010.10.03. <Query Yet Simple>
// ©2010-2017 http://queryphp.com All rights reserved.
namespace tests\pipeline;

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

use queryyetsimple\pipeline\pipeline;
use tests\testcase;
use queryyetsimple\mvc\project;

/**
 * pipeline 组件测试
 *
 * @author Xiangmin Liu<635750556@qq.com>
 * @package $$
 * @since 2017.05.27
 * @version 1.0
 */
class Pipeline_test extends testcase {
    
    /**
     * 管道对象 base
     *
     * @var \queryyetsimple\pipeline\pipeline
     */
    protected $objPipelineBase;
    
    /**
     * 管道对象 class
     *
     * @var \queryyetsimple\pipeline\pipeline
     */
    protected $objPipelineClass;
    
    /**
     * 初始化
     *
     * @return void
     */
    protected function setUp() {
        $this->objPipelineBase = new pipeline ();
        $this->objPipelineClass = new pipeline ( project::bootstrap () );
    }
    
    /**
     * 基础测试
     *
     * @return void
     */
    public function testBase() {
        $intPassed = 5;
        
        $intPassedEnd = $this->objPipelineBase->send ( $intPassed )->through ( function ($intPassed) {
            $this->assertTrue ( $intPassed === 5 );
            return $intPassed + 1;
        } )->through ( function ($intPassed) {
            $this->assertTrue ( $intPassed === 6 );
            return $intPassed * 10;
        }, function ($intPassed) {
            $this->assertTrue ( $intPassed === 60 );
            return $intPassed + 30;
        } )->then ( function ($intPassed) {
            $this->assertTrue ( $intPassed === 90 );
            return $intPassed + 2000;
        } );
        
        $this->assertTrue ( $intPassedEnd === 2090 );
    }
    
    /**
     * 类测试
     *
     * @return void
     */
    public function testClass() {
        $strPassed = 'I';
        
        $strPassedEnd = $this->objPipelineClass->send ( $strPassed )->through ( [ 
                'tests\pipeline\first',
                'tests\pipeline\second:you' 
        ] )->then ( function ($strPassed) {
            $this->assertTrue ( $strPassed === 'I Love You' );
            return $strPassed . ' Forever';
        } );
        
        $this->assertTrue ( $strPassedEnd === 'I Love You Forever' );
    }
}
