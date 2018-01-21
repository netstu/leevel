
extern zend_class_entry *queryyetsimple_i18n_ii18n_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_I18n_II18n);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_i18n_ii18n_addtext, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_i18n_ii18n_seti18n, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_i18n_ii18n_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_I18n_II18n, getText, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_I18n_II18n, __, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_I18n_II18n, addText, arginfo_queryyetsimple_i18n_ii18n_addtext)
	PHP_ABSTRACT_ME(Queryyetsimple_I18n_II18n, setI18n, arginfo_queryyetsimple_i18n_ii18n_seti18n)
	PHP_ABSTRACT_ME(Queryyetsimple_I18n_II18n, getI18n, NULL)
	PHP_FE_END
};
