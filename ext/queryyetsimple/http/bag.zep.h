
extern zend_class_entry *queryyetsimple_http_bag_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Http_Bag);

PHP_METHOD(Queryyetsimple_Http_Bag, __construct);
PHP_METHOD(Queryyetsimple_Http_Bag, all);
PHP_METHOD(Queryyetsimple_Http_Bag, keys);
PHP_METHOD(Queryyetsimple_Http_Bag, replace);
PHP_METHOD(Queryyetsimple_Http_Bag, add);
PHP_METHOD(Queryyetsimple_Http_Bag, get);
PHP_METHOD(Queryyetsimple_Http_Bag, set);
PHP_METHOD(Queryyetsimple_Http_Bag, has);
PHP_METHOD(Queryyetsimple_Http_Bag, remove);
PHP_METHOD(Queryyetsimple_Http_Bag, filter);
PHP_METHOD(Queryyetsimple_Http_Bag, count);
PHP_METHOD(Queryyetsimple_Http_Bag, toArray);
PHP_METHOD(Queryyetsimple_Http_Bag, jsonSerialize);
PHP_METHOD(Queryyetsimple_Http_Bag, toJson);
PHP_METHOD(Queryyetsimple_Http_Bag, getIterator);
PHP_METHOD(Queryyetsimple_Http_Bag, __toString);
PHP_METHOD(Queryyetsimple_Http_Bag, parseKeyFilter);
PHP_METHOD(Queryyetsimple_Http_Bag, parseFilter);
PHP_METHOD(Queryyetsimple_Http_Bag, filterValue);
PHP_METHOD(Queryyetsimple_Http_Bag, filterValueWithFunc);
PHP_METHOD(Queryyetsimple_Http_Bag, filterValueWithCallable);
PHP_METHOD(Queryyetsimple_Http_Bag, filterValueWithFilterVar);
PHP_METHOD(Queryyetsimple_Http_Bag, parseFilterId);
PHP_METHOD(Queryyetsimple_Http_Bag, isInt);
PHP_METHOD(Queryyetsimple_Http_Bag, formatOptions);
PHP_METHOD(Queryyetsimple_Http_Bag, getPartData);
PHP_METHOD(Queryyetsimple_Http_Bag, normalize);
zend_object *zephir_init_properties_Queryyetsimple_Http_Bag(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_replace, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_add, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_has, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_tojson, 0, 0, 0)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_parsekeyfilter, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, filter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_parsefilter, 0, 0, 0)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_filtervalue, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_filtervaluewithfunc, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_filtervaluewithcallable, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_filtervaluewithfiltervar, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_parsefilterid, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_isint, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_formatoptions, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_getpartdata, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_http_bag_normalize, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_http_bag_method_entry) {
	PHP_ME(Queryyetsimple_Http_Bag, __construct, arginfo_queryyetsimple_http_bag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Http_Bag, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, keys, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, replace, arginfo_queryyetsimple_http_bag_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, add, arginfo_queryyetsimple_http_bag_add, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, get, arginfo_queryyetsimple_http_bag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, set, arginfo_queryyetsimple_http_bag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, has, arginfo_queryyetsimple_http_bag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, remove, arginfo_queryyetsimple_http_bag_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, filter, arginfo_queryyetsimple_http_bag_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, toJson, arginfo_queryyetsimple_http_bag_tojson, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, getIterator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Http_Bag, parseKeyFilter, arginfo_queryyetsimple_http_bag_parsekeyfilter, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, parseFilter, arginfo_queryyetsimple_http_bag_parsefilter, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, filterValue, arginfo_queryyetsimple_http_bag_filtervalue, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, filterValueWithFunc, arginfo_queryyetsimple_http_bag_filtervaluewithfunc, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, filterValueWithCallable, arginfo_queryyetsimple_http_bag_filtervaluewithcallable, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, filterValueWithFilterVar, arginfo_queryyetsimple_http_bag_filtervaluewithfiltervar, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, parseFilterId, arginfo_queryyetsimple_http_bag_parsefilterid, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, isInt, arginfo_queryyetsimple_http_bag_isint, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, formatOptions, arginfo_queryyetsimple_http_bag_formatoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, getPartData, arginfo_queryyetsimple_http_bag_getpartdata, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Http_Bag, normalize, arginfo_queryyetsimple_http_bag_normalize, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
