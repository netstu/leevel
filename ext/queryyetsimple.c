
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



zend_class_entry *queryyetsimple_option_iclass_ce;
zend_class_entry *queryyetsimple_support_iarray_ce;
zend_class_entry *queryyetsimple_support_ijson_ce;
zend_class_entry *queryyetsimple_mvc_iview_ce;
zend_class_entry *queryyetsimple_support_imacro_ce;
zend_class_entry *queryyetsimple_log_iconnect_ce;
zend_class_entry *queryyetsimple_cookie_icookie_ce;
zend_class_entry *queryyetsimple_di_icontainer_ce;
zend_class_entry *queryyetsimple_event_idispatch_ce;
zend_class_entry *queryyetsimple_event_isubject_ce;
zend_class_entry *queryyetsimple_flow_icontrol_ce;
zend_class_entry *queryyetsimple_http_irequest_ce;
zend_class_entry *queryyetsimple_http_iresponse_ce;
zend_class_entry *queryyetsimple_i18n_ii18n_ce;
zend_class_entry *queryyetsimple_log_ilog_ce;
zend_class_entry *queryyetsimple_mvc_icontroller_ce;
zend_class_entry *queryyetsimple_mvc_ientity_ce;
zend_class_entry *queryyetsimple_option_ioption_ce;
zend_class_entry *queryyetsimple_pipeline_ipipeline_ce;
zend_class_entry *queryyetsimple_psr4_ipsr4_ce;
zend_class_entry *queryyetsimple_session_isession_ce;
zend_class_entry *queryyetsimple_view_iconnect_ce;
zend_class_entry *queryyetsimple_view_iview_ce;
zend_class_entry *queryyetsimple_mvc_imodel_ce;
zend_class_entry *queryyetsimple_support_ihtml_ce;
zend_class_entry *queryyetsimple_support_facade_ce;
zend_class_entry *queryyetsimple_di_provider_ce;
zend_class_entry *queryyetsimple_http_bag_ce;
zend_class_entry *queryyetsimple_manager_manager_ce;
zend_class_entry *queryyetsimple_log_connect_ce;
zend_class_entry *queryyetsimple_http_file_ce;
zend_class_entry *queryyetsimple_http_fileexception_ce;
zend_class_entry *queryyetsimple_http_headerbag_ce;
zend_class_entry *queryyetsimple_view_connect_ce;
zend_class_entry *queryyetsimple_0__closure_ce;
zend_class_entry *queryyetsimple_10__closure_ce;
zend_class_entry *queryyetsimple_11__closure_ce;
zend_class_entry *queryyetsimple_12__closure_ce;
zend_class_entry *queryyetsimple_13__closure_ce;
zend_class_entry *queryyetsimple_14__closure_ce;
zend_class_entry *queryyetsimple_15__closure_ce;
zend_class_entry *queryyetsimple_16__closure_ce;
zend_class_entry *queryyetsimple_17__closure_ce;
zend_class_entry *queryyetsimple_18__closure_ce;
zend_class_entry *queryyetsimple_19__closure_ce;
zend_class_entry *queryyetsimple_1__closure_ce;
zend_class_entry *queryyetsimple_20__closure_ce;
zend_class_entry *queryyetsimple_21__closure_ce;
zend_class_entry *queryyetsimple_22__closure_ce;
zend_class_entry *queryyetsimple_23__closure_ce;
zend_class_entry *queryyetsimple_24__closure_ce;
zend_class_entry *queryyetsimple_25__closure_ce;
zend_class_entry *queryyetsimple_26__closure_ce;
zend_class_entry *queryyetsimple_27__closure_ce;
zend_class_entry *queryyetsimple_28__closure_ce;
zend_class_entry *queryyetsimple_29__closure_ce;
zend_class_entry *queryyetsimple_2__closure_ce;
zend_class_entry *queryyetsimple_30__closure_ce;
zend_class_entry *queryyetsimple_31__closure_ce;
zend_class_entry *queryyetsimple_32__closure_ce;
zend_class_entry *queryyetsimple_33__closure_ce;
zend_class_entry *queryyetsimple_34__closure_ce;
zend_class_entry *queryyetsimple_35__closure_ce;
zend_class_entry *queryyetsimple_36__closure_ce;
zend_class_entry *queryyetsimple_37__closure_ce;
zend_class_entry *queryyetsimple_3__closure_ce;
zend_class_entry *queryyetsimple_4__closure_ce;
zend_class_entry *queryyetsimple_5__closure_ce;
zend_class_entry *queryyetsimple_6__closure_ce;
zend_class_entry *queryyetsimple_7__closure_ce;
zend_class_entry *queryyetsimple_8__closure_ce;
zend_class_entry *queryyetsimple_9__closure_ce;
zend_class_entry *queryyetsimple_auth_ce;
zend_class_entry *queryyetsimple_auth_provider_register_ce;
zend_class_entry *queryyetsimple_cache_ce;
zend_class_entry *queryyetsimple_cache_provider_register_ce;
zend_class_entry *queryyetsimple_collection_collection_ce;
zend_class_entry *queryyetsimple_cookie_ce;
zend_class_entry *queryyetsimple_cookie_cookie_ce;
zend_class_entry *queryyetsimple_cookie_provider_register_ce;
zend_class_entry *queryyetsimple_database_ce;
zend_class_entry *queryyetsimple_database_provider_register_ce;
zend_class_entry *queryyetsimple_db_ce;
zend_class_entry *queryyetsimple_di_container_ce;
zend_class_entry *queryyetsimple_encryption_ce;
zend_class_entry *queryyetsimple_encryption_provider_register_ce;
zend_class_entry *queryyetsimple_event_ce;
zend_class_entry *queryyetsimple_event_dispatch_ce;
zend_class_entry *queryyetsimple_event_eventprovider_ce;
zend_class_entry *queryyetsimple_event_observer_ce;
zend_class_entry *queryyetsimple_event_provider_register_ce;
zend_class_entry *queryyetsimple_event_subject_ce;
zend_class_entry *queryyetsimple_filesystem_ce;
zend_class_entry *queryyetsimple_filesystem_provider_register_ce;
zend_class_entry *queryyetsimple_http_filebag_ce;
zend_class_entry *queryyetsimple_http_filenotfoundexception_ce;
zend_class_entry *queryyetsimple_http_request_ce;
zend_class_entry *queryyetsimple_http_response_ce;
zend_class_entry *queryyetsimple_http_responseheaderbag_ce;
zend_class_entry *queryyetsimple_http_serverbag_ce;
zend_class_entry *queryyetsimple_http_uploadedfile_ce;
zend_class_entry *queryyetsimple_i18n_ce;
zend_class_entry *queryyetsimple_i18n_i18n_ce;
zend_class_entry *queryyetsimple_i18n_provider_register_ce;
zend_class_entry *queryyetsimple_log_ce;
zend_class_entry *queryyetsimple_log_file_ce;
zend_class_entry *queryyetsimple_log_log_ce;
zend_class_entry *queryyetsimple_log_manager_ce;
zend_class_entry *queryyetsimple_log_middleware_log_ce;
zend_class_entry *queryyetsimple_log_monolog_ce;
zend_class_entry *queryyetsimple_log_provider_register_ce;
zend_class_entry *queryyetsimple_mail_ce;
zend_class_entry *queryyetsimple_mail_provider_register_ce;
zend_class_entry *queryyetsimple_mvc_controller_ce;
zend_class_entry *queryyetsimple_mvc_view_ce;
zend_class_entry *queryyetsimple_option_ce;
zend_class_entry *queryyetsimple_option_option_ce;
zend_class_entry *queryyetsimple_option_provider_register_ce;
zend_class_entry *queryyetsimple_pipeline_pipeline_ce;
zend_class_entry *queryyetsimple_psr4_ce;
zend_class_entry *queryyetsimple_psr4_psr4_ce;
zend_class_entry *queryyetsimple_request_ce;
zend_class_entry *queryyetsimple_response_ce;
zend_class_entry *queryyetsimple_router_ce;
zend_class_entry *queryyetsimple_router_provider_register_ce;
zend_class_entry *queryyetsimple_session_ce;
zend_class_entry *queryyetsimple_session_manager_ce;
zend_class_entry *queryyetsimple_session_middleware_session_ce;
zend_class_entry *queryyetsimple_session_provider_register_ce;
zend_class_entry *queryyetsimple_session_session_ce;
zend_class_entry *queryyetsimple_support_closureuse_ce;
zend_class_entry *queryyetsimple_support_type_ce;
zend_class_entry *queryyetsimple_throttler_ce;
zend_class_entry *queryyetsimple_throttler_provider_register_ce;
zend_class_entry *queryyetsimple_url_ce;
zend_class_entry *queryyetsimple_validate_ce;
zend_class_entry *queryyetsimple_validate_provider_register_ce;
zend_class_entry *queryyetsimple_view_ce;
zend_class_entry *queryyetsimple_view_html_ce;
zend_class_entry *queryyetsimple_view_manager_ce;
zend_class_entry *queryyetsimple_view_provider_register_ce;
zend_class_entry *queryyetsimple_view_view_ce;

ZEND_DECLARE_MODULE_GLOBALS(queryyetsimple)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(queryyetsimple)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Queryyetsimple_Option_IClass);
	ZEPHIR_INIT(Queryyetsimple_Support_IArray);
	ZEPHIR_INIT(Queryyetsimple_Support_IJson);
	ZEPHIR_INIT(Queryyetsimple_Mvc_IView);
	ZEPHIR_INIT(Queryyetsimple_Support_IMacro);
	ZEPHIR_INIT(Queryyetsimple_Log_IConnect);
	ZEPHIR_INIT(Queryyetsimple_Cookie_ICookie);
	ZEPHIR_INIT(Queryyetsimple_Di_IContainer);
	ZEPHIR_INIT(Queryyetsimple_Event_IDispatch);
	ZEPHIR_INIT(Queryyetsimple_Event_ISubject);
	ZEPHIR_INIT(Queryyetsimple_Flow_IControl);
	ZEPHIR_INIT(Queryyetsimple_Http_IRequest);
	ZEPHIR_INIT(Queryyetsimple_Http_IResponse);
	ZEPHIR_INIT(Queryyetsimple_I18n_II18n);
	ZEPHIR_INIT(Queryyetsimple_Log_ILog);
	ZEPHIR_INIT(Queryyetsimple_Mvc_IController);
	ZEPHIR_INIT(Queryyetsimple_Mvc_IEntity);
	ZEPHIR_INIT(Queryyetsimple_Option_IOption);
	ZEPHIR_INIT(Queryyetsimple_Pipeline_IPipeline);
	ZEPHIR_INIT(Queryyetsimple_Psr4_IPsr4);
	ZEPHIR_INIT(Queryyetsimple_Session_ISession);
	ZEPHIR_INIT(Queryyetsimple_View_IConnect);
	ZEPHIR_INIT(Queryyetsimple_View_IView);
	ZEPHIR_INIT(Queryyetsimple_Mvc_IModel);
	ZEPHIR_INIT(Queryyetsimple_Support_IHtml);
	ZEPHIR_INIT(Queryyetsimple_Support_Facade);
	ZEPHIR_INIT(Queryyetsimple_Di_Provider);
	ZEPHIR_INIT(Queryyetsimple_Http_Bag);
	ZEPHIR_INIT(Queryyetsimple_Manager_Manager);
	ZEPHIR_INIT(Queryyetsimple_Log_Connect);
	ZEPHIR_INIT(Queryyetsimple_Http_File);
	ZEPHIR_INIT(Queryyetsimple_Http_FileException);
	ZEPHIR_INIT(Queryyetsimple_Http_HeaderBag);
	ZEPHIR_INIT(Queryyetsimple_View_Connect);
	ZEPHIR_INIT(Queryyetsimple_Auth);
	ZEPHIR_INIT(Queryyetsimple_Auth_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Cache);
	ZEPHIR_INIT(Queryyetsimple_Cache_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Collection_Collection);
	ZEPHIR_INIT(Queryyetsimple_Cookie);
	ZEPHIR_INIT(Queryyetsimple_Cookie_Cookie);
	ZEPHIR_INIT(Queryyetsimple_Cookie_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Database);
	ZEPHIR_INIT(Queryyetsimple_Database_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Db);
	ZEPHIR_INIT(Queryyetsimple_Di_Container);
	ZEPHIR_INIT(Queryyetsimple_Encryption);
	ZEPHIR_INIT(Queryyetsimple_Encryption_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Event);
	ZEPHIR_INIT(Queryyetsimple_Event_Dispatch);
	ZEPHIR_INIT(Queryyetsimple_Event_EventProvider);
	ZEPHIR_INIT(Queryyetsimple_Event_Observer);
	ZEPHIR_INIT(Queryyetsimple_Event_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Event_Subject);
	ZEPHIR_INIT(Queryyetsimple_Filesystem);
	ZEPHIR_INIT(Queryyetsimple_Filesystem_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Http_FileBag);
	ZEPHIR_INIT(Queryyetsimple_Http_FileNotFoundException);
	ZEPHIR_INIT(Queryyetsimple_Http_Request);
	ZEPHIR_INIT(Queryyetsimple_Http_Response);
	ZEPHIR_INIT(Queryyetsimple_Http_ResponseHeaderBag);
	ZEPHIR_INIT(Queryyetsimple_Http_ServerBag);
	ZEPHIR_INIT(Queryyetsimple_Http_UploadedFile);
	ZEPHIR_INIT(Queryyetsimple_I18n);
	ZEPHIR_INIT(Queryyetsimple_I18n_I18n);
	ZEPHIR_INIT(Queryyetsimple_I18n_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Log);
	ZEPHIR_INIT(Queryyetsimple_Log_File);
	ZEPHIR_INIT(Queryyetsimple_Log_Log);
	ZEPHIR_INIT(Queryyetsimple_Log_Manager);
	ZEPHIR_INIT(Queryyetsimple_Log_Monolog);
	ZEPHIR_INIT(Queryyetsimple_Log_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Log_middleware_Log);
	ZEPHIR_INIT(Queryyetsimple_Mail);
	ZEPHIR_INIT(Queryyetsimple_Mail_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Mvc_Controller);
	ZEPHIR_INIT(Queryyetsimple_Mvc_View);
	ZEPHIR_INIT(Queryyetsimple_Option);
	ZEPHIR_INIT(Queryyetsimple_Option_Option);
	ZEPHIR_INIT(Queryyetsimple_Option_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Pipeline_Pipeline);
	ZEPHIR_INIT(Queryyetsimple_Psr4);
	ZEPHIR_INIT(Queryyetsimple_Psr4_Psr4);
	ZEPHIR_INIT(Queryyetsimple_Request);
	ZEPHIR_INIT(Queryyetsimple_Response);
	ZEPHIR_INIT(Queryyetsimple_Router);
	ZEPHIR_INIT(Queryyetsimple_Router_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Session);
	ZEPHIR_INIT(Queryyetsimple_Session_Manager);
	ZEPHIR_INIT(Queryyetsimple_Session_Middleware_Session);
	ZEPHIR_INIT(Queryyetsimple_Session_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Session_Session);
	ZEPHIR_INIT(Queryyetsimple_Support_ClosureUse);
	ZEPHIR_INIT(Queryyetsimple_Support_Type);
	ZEPHIR_INIT(Queryyetsimple_Throttler);
	ZEPHIR_INIT(Queryyetsimple_Throttler_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_Url);
	ZEPHIR_INIT(Queryyetsimple_Validate);
	ZEPHIR_INIT(Queryyetsimple_Validate_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_View);
	ZEPHIR_INIT(Queryyetsimple_View_Html);
	ZEPHIR_INIT(Queryyetsimple_View_Manager);
	ZEPHIR_INIT(Queryyetsimple_View_Provider_Register);
	ZEPHIR_INIT(Queryyetsimple_View_View);
	ZEPHIR_INIT(queryyetsimple_0__closure);
	ZEPHIR_INIT(queryyetsimple_10__closure);
	ZEPHIR_INIT(queryyetsimple_11__closure);
	ZEPHIR_INIT(queryyetsimple_12__closure);
	ZEPHIR_INIT(queryyetsimple_13__closure);
	ZEPHIR_INIT(queryyetsimple_14__closure);
	ZEPHIR_INIT(queryyetsimple_15__closure);
	ZEPHIR_INIT(queryyetsimple_16__closure);
	ZEPHIR_INIT(queryyetsimple_17__closure);
	ZEPHIR_INIT(queryyetsimple_18__closure);
	ZEPHIR_INIT(queryyetsimple_19__closure);
	ZEPHIR_INIT(queryyetsimple_1__closure);
	ZEPHIR_INIT(queryyetsimple_20__closure);
	ZEPHIR_INIT(queryyetsimple_21__closure);
	ZEPHIR_INIT(queryyetsimple_22__closure);
	ZEPHIR_INIT(queryyetsimple_23__closure);
	ZEPHIR_INIT(queryyetsimple_24__closure);
	ZEPHIR_INIT(queryyetsimple_25__closure);
	ZEPHIR_INIT(queryyetsimple_26__closure);
	ZEPHIR_INIT(queryyetsimple_27__closure);
	ZEPHIR_INIT(queryyetsimple_28__closure);
	ZEPHIR_INIT(queryyetsimple_29__closure);
	ZEPHIR_INIT(queryyetsimple_2__closure);
	ZEPHIR_INIT(queryyetsimple_30__closure);
	ZEPHIR_INIT(queryyetsimple_31__closure);
	ZEPHIR_INIT(queryyetsimple_32__closure);
	ZEPHIR_INIT(queryyetsimple_33__closure);
	ZEPHIR_INIT(queryyetsimple_34__closure);
	ZEPHIR_INIT(queryyetsimple_35__closure);
	ZEPHIR_INIT(queryyetsimple_36__closure);
	ZEPHIR_INIT(queryyetsimple_37__closure);
	ZEPHIR_INIT(queryyetsimple_3__closure);
	ZEPHIR_INIT(queryyetsimple_4__closure);
	ZEPHIR_INIT(queryyetsimple_5__closure);
	ZEPHIR_INIT(queryyetsimple_6__closure);
	ZEPHIR_INIT(queryyetsimple_7__closure);
	ZEPHIR_INIT(queryyetsimple_8__closure);
	ZEPHIR_INIT(queryyetsimple_9__closure);
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

	zephir_init_static_properties_Queryyetsimple_Support_Facade(TSRMLS_C);
	zephir_init_static_properties_Queryyetsimple_Collection_Collection(TSRMLS_C);
	zephir_init_static_properties_Queryyetsimple_Di_Container(TSRMLS_C);
	zephir_init_static_properties_Queryyetsimple_Http_FileBag(TSRMLS_C);
	zephir_init_static_properties_Queryyetsimple_Http_Request(TSRMLS_C);
	zephir_init_static_properties_Queryyetsimple_Http_Response(TSRMLS_C);
	zephir_init_static_properties_Queryyetsimple_Http_UploadedFile(TSRMLS_C);

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
