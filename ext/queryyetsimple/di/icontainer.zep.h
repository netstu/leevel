
extern zend_class_entry *queryyetsimple_di_icontainer_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Di_IContainer);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_icontainer_bind, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
	ZEND_ARG_INFO(0, share)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_icontainer_instance, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_icontainer_singleton, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_icontainer_share, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, closure, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_icontainer_alias, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_icontainer_group, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_icontainer_groupmake, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_icontainer_make, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_di_icontainer_call, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_di_icontainer_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Di_IContainer, bind, arginfo_queryyetsimple_di_icontainer_bind)
	PHP_ABSTRACT_ME(Queryyetsimple_Di_IContainer, instance, arginfo_queryyetsimple_di_icontainer_instance)
	PHP_ABSTRACT_ME(Queryyetsimple_Di_IContainer, singleton, arginfo_queryyetsimple_di_icontainer_singleton)
	PHP_ABSTRACT_ME(Queryyetsimple_Di_IContainer, share, arginfo_queryyetsimple_di_icontainer_share)
	PHP_ABSTRACT_ME(Queryyetsimple_Di_IContainer, alias, arginfo_queryyetsimple_di_icontainer_alias)
	PHP_ABSTRACT_ME(Queryyetsimple_Di_IContainer, group, arginfo_queryyetsimple_di_icontainer_group)
	PHP_ABSTRACT_ME(Queryyetsimple_Di_IContainer, groupMake, arginfo_queryyetsimple_di_icontainer_groupmake)
	PHP_ABSTRACT_ME(Queryyetsimple_Di_IContainer, make, arginfo_queryyetsimple_di_icontainer_make)
	PHP_ABSTRACT_ME(Queryyetsimple_Di_IContainer, call, arginfo_queryyetsimple_di_icontainer_call)
	PHP_FE_END
};
