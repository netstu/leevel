
extern zend_class_entry *queryyetsimple_pipeline_ipipeline_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Pipeline_IPipeline);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_ipipeline_then, 0, 0, 0)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_pipeline_ipipeline_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_IPipeline, send, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_IPipeline, through, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_IPipeline, then, arginfo_queryyetsimple_pipeline_ipipeline_then)
	PHP_FE_END
};
