![](queryyetsimple.png)

# The QueryYetSimple Framework To Rebuild QueryPHP



QueryYetSimple is an open source web framework delivered as a C extension and supplement for the QueryPHP framework providing high performance and lower resource consumption.

QueryYetSimple is called QueryYet for short.

## Requirement

```
version_compare(PHP_VERSION, '7.1.0', '<') && die('PHP 7.1.0 OR Higher');
```

## How to install

### Windows

Need to tests.

### Linux 

You can download the source code.

```
git clone git@github.com:hunzhiwange/queryyetsimple.git
cd ext
```


Then compile it.

```
$/path/to/phpize
$./configure --with-php-config=/path/to/php-config
$make && make install
```

Then add extension to your php.ini,you can see if installation is successful by command php -m.

```
extension = queryyetsimple.so
```

## Official Documentation

Documentation for the framework can be found on the [QueryYetSimple website](http://www.queryphp.com).

## License

The QueryYetSimple framework is open-sourced software licensed under the [MIT license](http://opensource.org/licenses/MIT).
