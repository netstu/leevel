
extern zend_class_entry *leevel_mvc_ientity_ce;

ZEPHIR_INIT_CLASS(Leevel_Mvc_IEntity);

ZEPHIR_INIT_FUNCS(leevel_mvc_ientity_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Mvc_IEntity, id, NULL)
	PHP_FE_END
};
