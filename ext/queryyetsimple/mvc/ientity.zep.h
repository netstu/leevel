
extern zend_class_entry *queryyetsimple_mvc_ientity_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_IEntity);

ZEPHIR_INIT_FUNCS(queryyetsimple_mvc_ientity_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Mvc_IEntity, id, NULL)
	PHP_FE_END
};
