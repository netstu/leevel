
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "queryyetsimple.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *queryyetsimple_support_icontainer_ce;
zend_class_entry *queryyetsimple_support_face_ce;
zend_class_entry *queryyetsimple_auth_ce;
zend_class_entry *queryyetsimple_cache_ce;
zend_class_entry *queryyetsimple_cookie_ce;
zend_class_entry *queryyetsimple_database_ce;
zend_class_entry *queryyetsimple_db_ce;
zend_class_entry *queryyetsimple_encryption_ce;
zend_class_entry *queryyetsimple_event_ce;
zend_class_entry *queryyetsimple_filesystem_ce;
zend_class_entry *queryyetsimple_i18n_ce;
zend_class_entry *queryyetsimple_log_ce;
zend_class_entry *queryyetsimple_mail_ce;
zend_class_entry *queryyetsimple_option_ce;
zend_class_entry *queryyetsimple_psr4_ce;
zend_class_entry *queryyetsimple_request_ce;
zend_class_entry *queryyetsimple_response_ce;
zend_class_entry *queryyetsimple_router_ce;
zend_class_entry *queryyetsimple_session_ce;
zend_class_entry *queryyetsimple_throttler_ce;
zend_class_entry *queryyetsimple_validate_ce;
zend_class_entry *queryyetsimple_view_ce;

ZEND_DECLARE_MODULE_GLOBALS(queryyetsimple)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(queryyetsimple)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Queryyetsimple_Support_Icontainer);
	ZEPHIR_INIT(Queryyetsimple_Support_Face);
	ZEPHIR_INIT(Queryyetsimple_Auth);
	ZEPHIR_INIT(Queryyetsimple_Cache);
	ZEPHIR_INIT(Queryyetsimple_Cookie);
	ZEPHIR_INIT(Queryyetsimple_Database);
	ZEPHIR_INIT(Queryyetsimple_Db);
	ZEPHIR_INIT(Queryyetsimple_Encryption);
	ZEPHIR_INIT(Queryyetsimple_Event);
	ZEPHIR_INIT(Queryyetsimple_Filesystem);
	ZEPHIR_INIT(Queryyetsimple_I18n);
	ZEPHIR_INIT(Queryyetsimple_Log);
	ZEPHIR_INIT(Queryyetsimple_Mail);
	ZEPHIR_INIT(Queryyetsimple_Option);
	ZEPHIR_INIT(Queryyetsimple_Psr4);
	ZEPHIR_INIT(Queryyetsimple_Request);
	ZEPHIR_INIT(Queryyetsimple_Response);
	ZEPHIR_INIT(Queryyetsimple_Router);
	ZEPHIR_INIT(Queryyetsimple_Session);
	ZEPHIR_INIT(Queryyetsimple_Throttler);
	ZEPHIR_INIT(Queryyetsimple_Validate);
	ZEPHIR_INIT(Queryyetsimple_View);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(queryyetsimple)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_queryyetsimple_globals *queryyetsimple_globals TSRMLS_DC)
{
	queryyetsimple_globals->initialized = 0;

	/* Memory options */
	queryyetsimple_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	queryyetsimple_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	queryyetsimple_globals->cache_enabled = 1;

	/* Recursive Lock */
	queryyetsimple_globals->recursive_lock = 0;

	/* Static cache */
	memset(queryyetsimple_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_queryyetsimple_globals *queryyetsimple_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(queryyetsimple)
{

	zend_queryyetsimple_globals *queryyetsimple_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	queryyetsimple_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(queryyetsimple_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(queryyetsimple_globals_ptr TSRMLS_CC);

	zephir_init_static_properties_Queryyetsimple_Support_Face(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(queryyetsimple)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(queryyetsimple)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_QUERYYETSIMPLE_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_QUERYYETSIMPLE_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_QUERYYETSIMPLE_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_QUERYYETSIMPLE_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_QUERYYETSIMPLE_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(queryyetsimple)
{
	php_zephir_init_globals(queryyetsimple_globals TSRMLS_CC);
	php_zephir_init_module_globals(queryyetsimple_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(queryyetsimple)
{

}


zend_function_entry php_queryyetsimple_functions[] = {
ZEND_FE_END

};

zend_module_entry queryyetsimple_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_QUERYYETSIMPLE_EXTNAME,
	php_queryyetsimple_functions,
	PHP_MINIT(queryyetsimple),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(queryyetsimple),
#else
	NULL,
#endif
	PHP_RINIT(queryyetsimple),
	PHP_RSHUTDOWN(queryyetsimple),
	PHP_MINFO(queryyetsimple),
	PHP_QUERYYETSIMPLE_VERSION,
	ZEND_MODULE_GLOBALS(queryyetsimple),
	PHP_GINIT(queryyetsimple),
	PHP_GSHUTDOWN(queryyetsimple),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_QUERYYETSIMPLE
ZEND_GET_MODULE(queryyetsimple)
#endif
