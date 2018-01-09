
extern zend_class_entry *queryyetsimple_pipeline_ipipeline_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Pipeline_Ipipeline);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_ipipeline_send, 0, 0, 1)
	ZEND_ARG_INFO(0, mixPassed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_ipipeline_through, 0, 0, 1)
	ZEND_ARG_INFO(0, mixStage)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_ipipeline_then, 0, 0, 0)
	ZEND_ARG_INFO(0, calEnd)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_pipeline_ipipeline_method_entry) {
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_Ipipeline, reset, NULL)
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_Ipipeline, send, arginfo_queryyetsimple_pipeline_ipipeline_send)
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_Ipipeline, through, arginfo_queryyetsimple_pipeline_ipipeline_through)
	PHP_ABSTRACT_ME(Queryyetsimple_Pipeline_Ipipeline, then, arginfo_queryyetsimple_pipeline_ipipeline_then)
	PHP_FE_END
};
