
extern zend_class_entry *queryyetsimple_i18n_i18n_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_I18n_I18n);

PHP_METHOD(Queryyetsimple_I18n_I18n, __construct);
PHP_METHOD(Queryyetsimple_I18n_I18n, getText);
PHP_METHOD(Queryyetsimple_I18n_I18n, __);
PHP_METHOD(Queryyetsimple_I18n_I18n, addText);
PHP_METHOD(Queryyetsimple_I18n_I18n, setI18n);
PHP_METHOD(Queryyetsimple_I18n_I18n, getI18n);
PHP_METHOD(Queryyetsimple_I18n_I18n, setDefault);
PHP_METHOD(Queryyetsimple_I18n_I18n, getDefault);
zend_object *zephir_init_properties_Queryyetsimple_I18n_I18n(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_i18n_i18n___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, sI18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_i18n_i18n_addtext, 0, 0, 1)
	ZEND_ARG_INFO(0, sI18n)
	ZEND_ARG_ARRAY_INFO(0, arrData, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_i18n_i18n_seti18n, 0, 0, 1)
	ZEND_ARG_INFO(0, sI18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_i18n_i18n_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, sI18n)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_i18n_i18n_method_entry) {
	PHP_ME(Queryyetsimple_I18n_I18n, __construct, arginfo_queryyetsimple_i18n_i18n___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_I18n_I18n, getText, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_I18n_I18n, __, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_I18n_I18n, addText, arginfo_queryyetsimple_i18n_i18n_addtext, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_I18n_I18n, setI18n, arginfo_queryyetsimple_i18n_i18n_seti18n, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_I18n_I18n, getI18n, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_I18n_I18n, setDefault, arginfo_queryyetsimple_i18n_i18n_setdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_I18n_I18n, getDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
