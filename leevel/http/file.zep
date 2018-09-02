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

namespace Leevel\Http;

use Closure;
use SplFileObject;

/**
 * 文件
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.26
 *
 * @version 1.0
 *
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
class File extends SplFileObject
{

    /**
     * 构造函数
     *
     * @param string $path
     * @return void
     */
    public function __construct(string path)
    {
        if ! (is_file(path)) {
            throw new FileNotFoundException(path);
        }

        parent::__construct(path);
    }
    
    /**
     * 移动文件
     *
     * @param string $directory
     * @param string $name
     * @return \Leevel\Http\File
     */
    public function move(string directory, var name = null) -> <File>
    {
        var target;

        let target = this->getTargetFile(directory, name);
        this->moveToTarget(this->getPathname(), target);

        return new self(target);
    }
    
    /**
     * 获取目标文件
     *
     * @param string $directory
     * @param string $name
     * @return string
     */
    protected function getTargetFile(string directory, var name = null) -> string
    {
        var target;
    
        if ! (is_dir(directory)) {
            if (!is_writable(dirname(directory))) {
                throw new FileException(
                    sprintf("Unable to create the %s directory.", directory)
                );
            }

            mkdir(directory, 0777, true);
        } elseif ! (is_writable(directory)) {
            throw new FileException(
                sprintf("Unable to write in the %s directory.", directory)
            );
        }

        let target = rtrim(directory, "/\\") . DIRECTORY_SEPARATOR .
            (name === null ? this->getBasename() : name);
        
        return target;
    }
    
    /**
     * 移动文件到目标文件
     *
     * @param string $sourcePath
     * @param string $target
     * @param bool   $isUploaded
     */
    protected function moveToTarget(string sourcePath, string target, bool isUploaded = false)
    {
        var method;

        set_error_handler(Closure::fromCallable([this, "errorHandlerClosure"]));

        let method = isUploaded ? "move_uploaded_file" : "rename";
        call_user_func(method, sourcePath, target);

        restore_error_handler();

        chmod(target, 0666);
    }

    /**
     * 创建错误句柄闭包
     */
    protected function errorHandlerClosure()
    {
        var args;
        let args = func_get_args();

        throw new FileException(args[1]);
    }
}
