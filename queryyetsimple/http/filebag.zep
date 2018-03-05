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
namespace Queryyetsimple\Http;

use InvalidArgumentException;

/**
 * file bag
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.04
 * @version 1.0
 */
class FileBag extends Bag
{

    /**
     * 上传文件 keys
     * 
     * @var array
     */
    protected static fileKeys = [
    	"error", 
    	"name", 
    	"size", 
    	"tmp_name", 
    	"type"
    ];
    
    /**
     * 构造函数
     * 
     * @param array $elements
     * @return void 
     */
    public function __construct(array elements = [])
    {
        let elements = this->normalizeArray(elements);
        this->add(elements);
    }
    
    /**
     * {@inheritdoc}
     */
    public function replace(array elements = []) -> void
    {
        let this->elements = [];
        this->add(elements);
    }
    
    /**
     * {@inheritdoc}
     */
    public function set(var key, var value) -> void
    {
        if ! (is_array(value)) && ! (is_object(value) && value instanceof UploadedFile) {
            throw new InvalidArgumentException("An uploaded file must be an array or an instance of UploadedFile.");
        }

        parent::set(key, this->convertFile(value));
    }
    
    /**
     * {@inheritdoc}
     */
    public function add(array files = []) -> void
    {
        var key, file;
    
        for key, file in files {
            this->set(key, file);
        }
    }
    
    /**
     * 取回文件数组
     * 数组文件请在末尾加上反斜杆访问
     *
     * @param string $key
     * @param mixed $defaults
     * @return mixed
     */
    public function getArr(string key, var defaults = null)
    {
        var files, k, value;
    
        let files = [];
        for k, value in this->elements {
            if strpos(k, key) === 0 {
                let files[] = value;
            }
        }

        return  files ? files: defaults;
    }
    
    /**
     * 转换上传信息到文件实例 UploadedFile
     *
     * @param array|\Queryyetsimple\Http\UploadedFile $file
     * @return \Queryyetsimple\Http\UploadedFile|null
     */
    protected function convertFile(var file)
    {
    	var result;

        if is_object(file) && file instanceof UploadedFile {
            return file;
        }

        let file = this->normalizeFile(file);

        if file["error"] == UPLOAD_ERR_NO_FILE {
            let result = null;
        } else {
            let result = new UploadedFile(file["tmp_name"], file["name"], file["type"], file["error"]);
        }

        return result;
    }
    
    /**
     * 格式化 $_FILES 数组
     *
     * @param array $data
     * @return array
     */
    protected function normalizeFile(array data) -> array
    {
        var result, key, value, keys;
    
        let result = [];
        for key, value in data {
            if in_array(key, self::fileKeys) {
                let result[key] = value;
            }
        }

        let keys = this->normalizeKey(result);
        if keys !== self::fileKeys {
            throw new InvalidArgumentException(sprintf("An array uploaded file must be contain keys %s.", implode(",", self::fileKeys)));
        }

        return result;
    }
    
    /**
     * 格式化多维数组类文件为一维数组
     *
     * @param array $elements
     * @return array
     */
    protected function normalizeArray(array elements) -> array
    {
        var result, key, value, index, item, element, fileKey;
    
        let result = [];

        for key, value in elements {
            if ! (isset value["name"]) {
                throw new InvalidArgumentException("An uploaded file must be contain key name.");
            } elseif is_array(value["name"]) {
                for index, item in value["name"] {
                    let element = [];

                    for fileKey in self::fileKeys {
                        if ! isset value[fileKey][index] {
                            throw new InvalidArgumentException(sprintf("An uploaded file must be contain key %s.", fileKey));
                        }
                        let element[fileKey] = isset value[fileKey][index] ? value[fileKey][index] : "";
                    }

                    let result[key . "\\" . index] = element;
                    let result = this->normalizeArray(result);
                }
            } else {
                let result[key] = value;
            }
        }

        return result;
    }
    
    /**
     * 格式化 keys
     *
     * @param array $data
     * @return array
     */
    protected function normalizeKey(array data) -> array
    {
        var keys;
    
        let keys = array_keys(data);
        sort(keys);

        return keys;
    }
}