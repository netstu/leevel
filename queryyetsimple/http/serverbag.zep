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

/**
 * server bag
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.03.04
 * @version 1.0
 */
class ServerBag extends Bag
{

	/**
	 * 取回 HTTP HEADERS
	 *
	 * @return array
	 */
	public function getHeaders() -> array
	{
		var result, contentHeaders, key, value;
	
		let result = [];
		let contentHeaders = [
			"CONTENT_LENGTH", 
			"CONTENT_MD5", 
			"CONTENT_TYPE"
		];

		for key, value in this->elements {
			if 0 === strpos(key, "HTTP_") {
			    let result[substr(key, 5)] = value;
			} elseif in_array(key, contentHeaders, true) {
			    let result[key] = value;
			}
		}

		return result;
	}
}
