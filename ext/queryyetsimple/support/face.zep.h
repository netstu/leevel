
extern zend_class_entry *queryyetsimple_support_face_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Face);

PHP_METHOD(Queryyetsimple_Support_Face, faces);
PHP_METHOD(Queryyetsimple_Support_Face, container);
PHP_METHOD(Queryyetsimple_Support_Face, setContainer);
PHP_METHOD(Queryyetsimple_Support_Face, name);
PHP_METHOD(Queryyetsimple_Support_Face, __callStatic);
void zephir_init_static_properties_Queryyetsimple_Support_Face(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_face_setcontainer, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Queryyetsimple\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_support_face___callstatic, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_support_face_method_entry) {
	PHP_ME(Queryyetsimple_Support_Face, faces, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Face, container, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Face, setContainer, arginfo_queryyetsimple_support_face_setcontainer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Face, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Queryyetsimple_Support_Face, __callStatic, arginfo_queryyetsimple_support_face___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
