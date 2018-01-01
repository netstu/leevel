--TEST--
Check for queryyetsimple presence
--SKIPIF--
<?php if (!extension_loaded("queryyetsimple")) print "skip"; ?>
--FILE--
<?php 
echo "queryyetsimple extension is available";

use queryyetsimple\option\option;

$oOption = new option([
    'app' => [
        'debug' => true,
        'foo' => 'bar',
        'bar' => [
            'foo' => 'bar'
        ]
    ],
    'hello' => [
        'name' => 'xiaoniu'
    ]
]);

if($oOption->get('app\bar.foo') != 'bar') {
    throw new Exception('get is error');
}

$oOption->set('app\query.yet.simple', 'swoole');
if($oOption->get('app\query.yet.simple') != 'swoole') {
    throw new Exception('set is error');
}

$oOption->delete('app\query.yet.simple');
if($oOption->get('app\query.yet.simple') !== null) {
    throw new Exception('delete is error');
}

if($oOption->has('hello\name') === false) {
    throw new Exception('has is error');
}

?>
--EXPECT--
queryyetsimple extension is available
