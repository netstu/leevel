<?php
// [$QueryPHP] The PHP Framework For Code Poem As Free As Wind. <Query Yet Simple>
// ©2010-2017 http://queryphp.com All rights reserved.
namespace queryyetsimple\session;

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

use RuntimeException;
use SessionHandlerInterface;
use queryyetsimple\classs\option;
use queryyetsimple\assert\assert;
use queryyetsimple\session\interfaces\store as interfaces_store;

/**
 * session 存储
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.04.17
 * @version 1.0
 */
class store implements interfaces_store {
    
    use option;
    
    /**
     * 配置
     *
     * @var array
     */
    protected $oHandler;
    
    /**
     * 配置
     *
     * @var array
     */
    protected $arrOption = [ 
            'default' => null,
            'prefix' => 'q_',
            'id' => null,
            'name' => null,
            'cookie_domain' => null,
            'cache_limiter' => null,
            'expire' => 86400,
            'cookie_lifetime' => null,
            'gc_maxlifetime' => null,
            'save_path' => null,
            'use_trans_sid' => null,
            'gc_probability' => null 
    ];
    
    /**
     * 构造函数
     *
     * @param array $arrOption            
     * @param \SessionHandlerInterface|null $oHandler            
     * @return void
     */
    public function __construct(array $arrOption = [], SessionHandlerInterface $oHandler = null) {
        $this->options ( $arrOption );
        $this->oHandler = $oHandler;
    }
    
    /**
     * 启动 session
     *
     * @return void
     */
    public function start() {
        if ($this->isStart ()) {
            return;
        }
        
        // 设置 session 不自动启动
        ini_set ( 'session.auto_start', 0 );
        
        // 设置 session id
        if ($this->getOption ( 'id' )) {
            session_id ( $this->getOption ( 'id' ) );
        } else {
            if (is_null ( $this->parseSessionId () )) {
                $this->sessionId ( uniqid ( dechex ( mt_rand () ) ) );
            }
        }
        
        // cookie domain
        if ($this->getOption ( 'cookie_domain' )) {
            $this->cookieDomain ( $this->getOption ( 'cookie_domain' ) );
        }
        
        // session name
        if ($this->getOption ( 'name' )) {
            $this->sessionName ( $this->getOption ( 'name' ) );
        }
        
        // cache expire
        if ($this->getOption ( 'expire' )) {
            $this->cacheExpire ( $this->getOption ( 'expire' ) );
        }
        
        // gc maxlifetime
        if ($this->getOption ( 'gc_maxlifetime' )) {
            $this->gcMaxlifetime ( $this->getOption ( 'gc_maxlifetime' ) );
        }
        
        // cookie lifetime
        if ($this->getOption ( 'cookie_lifetime' )) {
            $this->cookieLifetime ( $this->getOption ( 'cookie_lifetime' ) );
        }
        
        // cache limiter
        if ($this->getOption ( 'cache_limiter' )) {
            $this->cacheLimiter ( $this->getOption ( 'cache_limiter' ) );
        }
        
        // save path
        if ($this->getOption ( 'save_path' )) {
            $this->savePath ( $this->getOption ( 'save_path' ) );
        }
        
        // use_trans_sid
        if ($this->getOption ( 'use_trans_sid' )) {
            $this->useTransSid ( $this->getOption ( 'use_trans_sid' ) );
        }
        
        // gc_probability
        if ($this->getOption ( 'gc_probability' )) {
            $this->gcProbability ( $this->getOption ( 'gc_probability' ) );
        }
        
        // 驱动
        if ($this->oHandler && ! session_set_save_handler ( $this->oHandler )) {
            throw new RuntimeException ( __ ( 'session 驱动 %s 设置失败', get_class ( $this->oHandler ) ) );
        }
        
        // 启动 session
        if (! session_start ()) {
            return null;
        }
    }
    
    /**
     * 设置 session
     *
     * @param string $sName            
     * @param mxied $mixValue            
     * @return void
     */
    public function set($sName, $mixValue) {
        $this->checkStart ();
        
        assert::string ( $sName );
        $sName = $this->getName ( $sName );
        $_SESSION [$sName] = $mixValue;
    }
    
    /**
     * 批量插入
     *
     * @param string|array $mixKey            
     * @param mixed $mixValue            
     * @return void
     */
    public function put($mixKey, $mixValue = null) {
        $this->checkStart ();
        
        if (! is_array ( $mixKey )) {
            $mixKey = [ 
                    $mixKey => $mixValue 
            ];
        }
        
        foreach ( $mixKey as $strKey => $mixValue ) {
            $this->set ( $strKey, $mixValue );
        }
    }
    
    /**
     * 取回 session
     *
     * @param string $sName            
     * @param mixed $mixValue            
     * @return mxied
     */
    public function get($sName, $mixValue = null) {
        $this->checkStart ();
        
        assert::string ( $sName );
        $sName = $this->getName ( $sName );
        return isset ( $_SESSION [$sName] ) ? $_SESSION [$sName] : $mixValue;
    }
    
    /**
     * 删除 session
     *
     * @param string $sName            
     * @return bool
     */
    public function delete($sName) {
        $this->checkStart ();
        
        assert::string ( $sName );
        $sName = $this->getName ( $sName );
        return session_unregister ( $sName );
    }
    
    /**
     * 是否存在 session
     *
     * @param string $sName            
     * @return boolean
     */
    public function has($sName) {
        $this->checkStart ();
        
        assert::string ( $sName );
        $sName = $this->getName ( $sName );
        return isset ( $_SESSION [$sName] );
    }
    
    /**
     * 删除 session
     *
     * @param boolean $bPrefix            
     * @return void
     */
    public function clear($bPrefix = true) {
        $this->checkStart ();
        
        $strPrefix = $this->getOption ( 'prefix' );
        foreach ( $_SESSION as $sKey => $Val ) {
            if ($bPrefix === true && $strPrefix && strpos ( $sKey, $strPrefix ) === 0)
                $this->delete ( $sKey, false );
            else
                $this->delete ( $sKey, false );
        }
    }
    
    /**
     * 暂停 session
     *
     * @return void
     */
    public function pause() {
        $this->checkStart ();
        session_write_close ();
    }
    
    /**
     * 终止会话
     *
     * @return bool
     */
    public function destroy() {
        $this->checkStart ();
        
        $this->clear ( false );
        
        if (isset ( $_COOKIE [$this->sessionName ()] )) {
            setcookie ( $this->sessionName (), '', time () - 42000, '/' );
        }
        
        session_destroy ();
    }
    
    /**
     * 获取解析 session_id
     *
     * @param string $sId            
     * @return string
     */
    public function parseSessionId() {
        if (($sId = $this->sessionId ())) {
            return $sId;
        }
        if ($this->useCookies ()) {
            if (isset ( $_COOKIE [$this->sessionName ()] )) {
                return $_COOKIE [$this->sessionName ()];
            }
        } else {
            if (isset ( $_GET [$this->sessionName ()] )) {
                return $_GET [$this->sessionName ()];
            }
            if (isset ( $_POST [$this->sessionName ()] )) {
                return $_POST [$this->sessionName ()];
            }
        }
        return null;
    }
    
    /**
     * 设置 save path
     *
     * @param string $sSavePath            
     * @return string
     */
    public function savePath($sSavePath = null) {
        return ! empty ( $sSavePath ) ? session_save_path ( $sSavePath ) : session_save_path ();
    }
    
    /**
     * 设置 cache limiter
     *
     * @param string $strCacheLimiter            
     * @return string
     */
    public function cacheLimiter($strCacheLimiter = null) {
        return isset ( $strCacheLimiter ) ? session_cache_limiter ( $strCacheLimiter ) : session_cache_limiter ();
    }
    
    /**
     * 设置 cache expire
     *
     * @param int $nExpireSecond            
     * @return void
     */
    public function cacheExpire($nExpireSecond = null) {
        return isset ( $nExpireSecond ) ? session_cache_expire ( intval ( $nExpireSecond ) ) : session_cache_expire ();
    }
    
    /**
     * session_name
     *
     * @param string $sName            
     * @return string
     */
    public function sessionName($sName = null) {
        return isset ( $sName ) ? session_name ( $sName ) : session_name ();
    }
    
    /**
     * session id
     *
     * @param string $sId            
     * @return string
     */
    public function sessionId($sId = null) {
        return isset ( $sId ) ? session_id ( $sId ) : session_id ();
    }
    
    /**
     * session 的 cookie_domain 设置
     *
     * @param string $sSessionDomain            
     * @return string
     */
    public function cookieDomain($sSessionDomain = null) {
        $sReturn = ini_get ( 'session.cookie_domain' );
        if (! empty ( $sSessionDomain )) {
            ini_set ( 'session.cookie_domain', $sSessionDomain ); // 跨域访问 session
        }
        return $sReturn;
    }
    
    /**
     * session 是否使用 cookie
     *
     * @param boolean $bUseCookies            
     * @return boolean
     */
    public function useCookies($bUseCookies = null) {
        $booReturn = ini_get ( 'session.use_cookies' ) ? true : false;
        if (isset ( $bUseCookies )) {
            ini_set ( 'session.use_cookies', $bUseCookies ? 1 : 0 );
        }
        return $booReturn;
    }
    
    /**
     * 客户端禁用 cookie 可以开启这个项
     *
     * @param string $nUseTransSid            
     * @return boolean
     */
    public function useTransSid($nUseTransSid = null) {
        $booReturn = ini_get ( 'session.use_trans_sid' ) ? true : false;
        if (isset ( $nUseTransSid )) {
            ini_set ( 'session.use_trans_sid', $nUseTransSid ? 1 : 0 );
        }
        return $booReturn;
    }
    
    /**
     * 设置过期 cookie lifetime
     *
     * @param int $nCookieLifeTime            
     * @return int
     */
    public function cookieLifetime($nCookieLifeTime) {
        $nReturn = ini_get ( 'session.cookie_lifetime' );
        if (isset ( $nCookieLifeTime ) && intval ( $nCookieLifeTime ) >= 1) {
            ini_set ( 'session.cookie_lifetime', intval ( $nCookieLifeTime ) );
        }
        return $nReturn;
    }
    
    /**
     * gc maxlifetime
     *
     * @param int $nGcMaxlifetime            
     * @return int
     */
    public function gcMaxlifetime($nGcMaxlifetime = null) {
        $nReturn = ini_get ( 'session.gc_maxlifetime' );
        if (isset ( $nGcMaxlifetime ) && intval ( $nGcMaxlifetime ) >= 1) {
            ini_set ( 'session.gc_maxlifetime', intval ( $nGcMaxlifetime ) );
        }
        return $nReturn;
    }
    
    /**
     * session 垃圾回收概率分子 (分母为 session.gc_divisor)
     *
     * @param int $nGcProbability            
     * @return int
     */
    public function gcProbability($nGcProbability = null) {
        $nReturn = ini_get ( 'session.gc_probability' );
        if (isset ( $nGcProbability ) && intval ( $nGcProbability ) >= 1 && intval ( $nGcProbability ) <= 100) {
            ini_set ( 'session.gc_probability', intval ( $nGcProbability ) );
        }
        return $nReturn;
    }
    
    /**
     * 返回 session 名字
     *
     * @param string $sName            
     * @return string
     */
    protected function getName($sName) {
        return $this->getOption ( 'prefix' ) . $sName;
    }
    
    /**
     * session 是否已经启动
     *
     * @return boolean
     */
    protected function isStart() {
        return isset ( $_SESSION );
    }
    
    /**
     * 验证 session 是否开启
     *
     * @return void
     */
    protected function checkStart() {
        if (! $this->isStart ()) {
            throw new RuntimeException ( 'Session is not start yet' );
        }
    }
}
