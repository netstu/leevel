
extern zend_class_entry *queryyetsimple_mail_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Mail);

PHP_METHOD(Queryyetsimple_Mail, name);

ZEPHIR_INIT_FUNCS(queryyetsimple_mail_method_entry) {
	PHP_ME(Queryyetsimple_Mail, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
