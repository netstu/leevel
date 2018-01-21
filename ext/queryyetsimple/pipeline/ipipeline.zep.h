
extern zend_class_entry *queryyetsimple_pipeline_ipipeline_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Pipeline_IPipeline);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_ipipeline_send, 0, 0, 1)
	ZEND_ARG_INFO(0, passed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_ipipeline_through, 0, 0, 1)
	ZEND_ARG_INFO(0, stage)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_ipipeline_then, 0, 0, 0)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_pipeline_ipipeline_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_IPipeline, reset, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_IPipeline, send, arginfo_queryyetsimple_pipeline_ipipeline_send)
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_IPipeline, through, arginfo_queryyetsimple_pipeline_ipipeline_through)
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_IPipeline, then, arginfo_queryyetsimple_pipeline_ipipeline_then)
	PHP_FE_END
};
