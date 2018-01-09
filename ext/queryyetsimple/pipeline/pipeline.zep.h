
extern zend_class_entry *queryyetsimple_pipeline_pipeline_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Pipeline_Pipeline);

PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, __construct);
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, reset);
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, send);
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, through);
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, then);
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, traverseGenerator);
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, stageGenerator);
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, stageCallback);
PHP_METHOD(Queryyetsimple_Pipeline_Pipeline, parse);
zend_object *zephir_init_properties_Queryyetsimple_Pipeline_Pipeline(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_pipeline___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objContainer, Queryyetsimple\\Support\\Icontainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_pipeline_send, 0, 0, 1)
	ZEND_ARG_INFO(0, mixPassed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_pipeline_through, 0, 0, 1)
	ZEND_ARG_INFO(0, mixStage)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_pipeline_then, 0, 0, 0)
	ZEND_ARG_INFO(0, calEnd)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_pipeline_stagegenerator, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrStage, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_pipeline_stagecallback, 0, 0, 1)
	ZEND_ARG_INFO(0, mixStage)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_pipeline_pipeline_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, strStage)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_pipeline_pipeline_method_entry) {
	PHP_ME(Queryyetsimple_Pipeline_Pipeline, __construct, arginfo_queryyetsimple_pipeline_pipeline___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Pipeline_Pipeline, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Pipeline_Pipeline, send, arginfo_queryyetsimple_pipeline_pipeline_send, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Pipeline_Pipeline, through, arginfo_queryyetsimple_pipeline_pipeline_through, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Pipeline_Pipeline, then, arginfo_queryyetsimple_pipeline_pipeline_then, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Pipeline_Pipeline, traverseGenerator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Pipeline_Pipeline, stageGenerator, arginfo_queryyetsimple_pipeline_pipeline_stagegenerator, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Pipeline_Pipeline, stageCallback, arginfo_queryyetsimple_pipeline_pipeline_stagecallback, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Pipeline_Pipeline, parse, arginfo_queryyetsimple_pipeline_pipeline_parse, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
