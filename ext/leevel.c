
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "leevel.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *leevel_option_iclass_ce;
zend_class_entry *leevel_support_iarray_ce;
zend_class_entry *leevel_support_imacro_ce;
zend_class_entry *leevel_support_ijson_ce;
zend_class_entry *leevel_flow_icontrol_ce;
zend_class_entry *leevel_http_iresponse_ce;
zend_class_entry *leevel_mvc_iview_ce;
zend_class_entry *leevel_log_iconnect_ce;
zend_class_entry *leevel_cookie_icookie_ce;
zend_class_entry *leevel_di_icontainer_ce;
zend_class_entry *leevel_event_idispatch_ce;
zend_class_entry *leevel_event_isubject_ce;
zend_class_entry *leevel_http_irequest_ce;
zend_class_entry *leevel_i18n_ii18n_ce;
zend_class_entry *leevel_log_ilog_ce;
zend_class_entry *leevel_mvc_icontroller_ce;
zend_class_entry *leevel_mvc_ientity_ce;
zend_class_entry *leevel_option_ioption_ce;
zend_class_entry *leevel_pipeline_ipipeline_ce;
zend_class_entry *leevel_psr4_ipsr4_ce;
zend_class_entry *leevel_router_iurl_ce;
zend_class_entry *leevel_session_isession_ce;
zend_class_entry *leevel_view_iconnect_ce;
zend_class_entry *leevel_view_iview_ce;
zend_class_entry *leevel_mvc_imodel_ce;
zend_class_entry *leevel_router_irouter_ce;
zend_class_entry *leevel_support_ihtml_ce;
zend_class_entry *leevel_support_facade_ce;
zend_class_entry *leevel_di_provider_ce;
zend_class_entry *leevel_http_bag_ce;
zend_class_entry *leevel_http_response_ce;
zend_class_entry *leevel_manager_manager_ce;
zend_class_entry *leevel_log_connect_ce;
zend_class_entry *leevel_http_file_ce;
zend_class_entry *leevel_http_fileexception_ce;
zend_class_entry *leevel_http_headerbag_ce;
zend_class_entry *leevel_http_jsonresponse_ce;
zend_class_entry *leevel_view_connect_ce;
zend_class_entry *leevel_0__closure_ce;
zend_class_entry *leevel_10__closure_ce;
zend_class_entry *leevel_11__closure_ce;
zend_class_entry *leevel_12__closure_ce;
zend_class_entry *leevel_13__closure_ce;
zend_class_entry *leevel_14__closure_ce;
zend_class_entry *leevel_15__closure_ce;
zend_class_entry *leevel_16__closure_ce;
zend_class_entry *leevel_17__closure_ce;
zend_class_entry *leevel_18__closure_ce;
zend_class_entry *leevel_19__closure_ce;
zend_class_entry *leevel_1__closure_ce;
zend_class_entry *leevel_20__closure_ce;
zend_class_entry *leevel_21__closure_ce;
zend_class_entry *leevel_22__closure_ce;
zend_class_entry *leevel_23__closure_ce;
zend_class_entry *leevel_24__closure_ce;
zend_class_entry *leevel_25__closure_ce;
zend_class_entry *leevel_26__closure_ce;
zend_class_entry *leevel_27__closure_ce;
zend_class_entry *leevel_28__closure_ce;
zend_class_entry *leevel_29__closure_ce;
zend_class_entry *leevel_2__closure_ce;
zend_class_entry *leevel_30__closure_ce;
zend_class_entry *leevel_31__closure_ce;
zend_class_entry *leevel_32__closure_ce;
zend_class_entry *leevel_33__closure_ce;
zend_class_entry *leevel_34__closure_ce;
zend_class_entry *leevel_35__closure_ce;
zend_class_entry *leevel_36__closure_ce;
zend_class_entry *leevel_37__closure_ce;
zend_class_entry *leevel_3__closure_ce;
zend_class_entry *leevel_4__closure_ce;
zend_class_entry *leevel_5__closure_ce;
zend_class_entry *leevel_6__closure_ce;
zend_class_entry *leevel_7__closure_ce;
zend_class_entry *leevel_8__closure_ce;
zend_class_entry *leevel_9__closure_ce;
zend_class_entry *leevel_auth_ce;
zend_class_entry *leevel_auth_provider_register_ce;
zend_class_entry *leevel_cache_ce;
zend_class_entry *leevel_cache_provider_register_ce;
zend_class_entry *leevel_collection_collection_ce;
zend_class_entry *leevel_cookie_ce;
zend_class_entry *leevel_cookie_cookie_ce;
zend_class_entry *leevel_cookie_provider_register_ce;
zend_class_entry *leevel_database_ce;
zend_class_entry *leevel_database_provider_register_ce;
zend_class_entry *leevel_db_ce;
zend_class_entry *leevel_di_container_ce;
zend_class_entry *leevel_encryption_ce;
zend_class_entry *leevel_encryption_provider_register_ce;
zend_class_entry *leevel_event_ce;
zend_class_entry *leevel_event_dispatch_ce;
zend_class_entry *leevel_event_eventprovider_ce;
zend_class_entry *leevel_event_observer_ce;
zend_class_entry *leevel_event_provider_register_ce;
zend_class_entry *leevel_event_subject_ce;
zend_class_entry *leevel_filesystem_ce;
zend_class_entry *leevel_filesystem_provider_register_ce;
zend_class_entry *leevel_http_apiresponse_ce;
zend_class_entry *leevel_http_filebag_ce;
zend_class_entry *leevel_http_filenotfoundexception_ce;
zend_class_entry *leevel_http_fileresponse_ce;
zend_class_entry *leevel_http_redirectresponse_ce;
zend_class_entry *leevel_http_request_ce;
zend_class_entry *leevel_http_responseheaderbag_ce;
zend_class_entry *leevel_http_serverbag_ce;
zend_class_entry *leevel_http_uploadedfile_ce;
zend_class_entry *leevel_i18n_ce;
zend_class_entry *leevel_i18n_i18n_ce;
zend_class_entry *leevel_i18n_provider_register_ce;
zend_class_entry *leevel_log_ce;
zend_class_entry *leevel_log_file_ce;
zend_class_entry *leevel_log_log_ce;
zend_class_entry *leevel_log_manager_ce;
zend_class_entry *leevel_log_middleware_log_ce;
zend_class_entry *leevel_log_monolog_ce;
zend_class_entry *leevel_log_provider_register_ce;
zend_class_entry *leevel_mail_ce;
zend_class_entry *leevel_mail_provider_register_ce;
zend_class_entry *leevel_mvc_controller_ce;
zend_class_entry *leevel_mvc_view_ce;
zend_class_entry *leevel_option_ce;
zend_class_entry *leevel_option_option_ce;
zend_class_entry *leevel_option_provider_register_ce;
zend_class_entry *leevel_pipeline_pipeline_ce;
zend_class_entry *leevel_psr4_ce;
zend_class_entry *leevel_psr4_psr4_ce;
zend_class_entry *leevel_request_ce;
zend_class_entry *leevel_response_ce;
zend_class_entry *leevel_router_ce;
zend_class_entry *leevel_router_provider_register_ce;
zend_class_entry *leevel_router_url_ce;
zend_class_entry *leevel_session_ce;
zend_class_entry *leevel_session_manager_ce;
zend_class_entry *leevel_session_middleware_session_ce;
zend_class_entry *leevel_session_provider_register_ce;
zend_class_entry *leevel_session_session_ce;
zend_class_entry *leevel_support_closureuse_ce;
zend_class_entry *leevel_support_type_ce;
zend_class_entry *leevel_throttler_ce;
zend_class_entry *leevel_throttler_provider_register_ce;
zend_class_entry *leevel_url_ce;
zend_class_entry *leevel_validate_ce;
zend_class_entry *leevel_validate_provider_register_ce;
zend_class_entry *leevel_view_ce;
zend_class_entry *leevel_view_html_ce;
zend_class_entry *leevel_view_manager_ce;
zend_class_entry *leevel_view_provider_register_ce;
zend_class_entry *leevel_view_view_ce;

ZEND_DECLARE_MODULE_GLOBALS(leevel)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(leevel)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Leevel_Option_IClass);
	ZEPHIR_INIT(Leevel_Support_IArray);
	ZEPHIR_INIT(Leevel_Support_IMacro);
	ZEPHIR_INIT(Leevel_Support_IJson);
	ZEPHIR_INIT(Leevel_Flow_IControl);
	ZEPHIR_INIT(Leevel_Http_IResponse);
	ZEPHIR_INIT(Leevel_Mvc_IView);
	ZEPHIR_INIT(Leevel_Log_IConnect);
	ZEPHIR_INIT(Leevel_Cookie_ICookie);
	ZEPHIR_INIT(Leevel_Di_IContainer);
	ZEPHIR_INIT(Leevel_Event_IDispatch);
	ZEPHIR_INIT(Leevel_Event_ISubject);
	ZEPHIR_INIT(Leevel_Http_IRequest);
	ZEPHIR_INIT(Leevel_I18n_II18n);
	ZEPHIR_INIT(Leevel_Log_ILog);
	ZEPHIR_INIT(Leevel_Mvc_IController);
	ZEPHIR_INIT(Leevel_Mvc_IEntity);
	ZEPHIR_INIT(Leevel_Option_IOption);
	ZEPHIR_INIT(Leevel_Pipeline_IPipeline);
	ZEPHIR_INIT(Leevel_Psr4_IPsr4);
	ZEPHIR_INIT(Leevel_Router_IUrl);
	ZEPHIR_INIT(Leevel_Session_ISession);
	ZEPHIR_INIT(Leevel_View_IConnect);
	ZEPHIR_INIT(Leevel_View_IView);
	ZEPHIR_INIT(Leevel_Mvc_IModel);
	ZEPHIR_INIT(Leevel_Router_IRouter);
	ZEPHIR_INIT(Leevel_Support_IHtml);
	ZEPHIR_INIT(Leevel_Support_Facade);
	ZEPHIR_INIT(Leevel_Di_Provider);
	ZEPHIR_INIT(Leevel_Http_Bag);
	ZEPHIR_INIT(Leevel_Http_Response);
	ZEPHIR_INIT(Leevel_Manager_Manager);
	ZEPHIR_INIT(Leevel_Log_Connect);
	ZEPHIR_INIT(Leevel_Http_File);
	ZEPHIR_INIT(Leevel_Http_FileException);
	ZEPHIR_INIT(Leevel_Http_HeaderBag);
	ZEPHIR_INIT(Leevel_Http_JsonResponse);
	ZEPHIR_INIT(Leevel_View_Connect);
	ZEPHIR_INIT(Leevel_Auth);
	ZEPHIR_INIT(Leevel_Auth_Provider_Register);
	ZEPHIR_INIT(Leevel_Cache);
	ZEPHIR_INIT(Leevel_Cache_Provider_Register);
	ZEPHIR_INIT(Leevel_Collection_Collection);
	ZEPHIR_INIT(Leevel_Cookie);
	ZEPHIR_INIT(Leevel_Cookie_Cookie);
	ZEPHIR_INIT(Leevel_Cookie_Provider_Register);
	ZEPHIR_INIT(Leevel_Database);
	ZEPHIR_INIT(Leevel_Database_Provider_Register);
	ZEPHIR_INIT(Leevel_Db);
	ZEPHIR_INIT(Leevel_Di_Container);
	ZEPHIR_INIT(Leevel_Encryption);
	ZEPHIR_INIT(Leevel_Encryption_Provider_Register);
	ZEPHIR_INIT(Leevel_Event);
	ZEPHIR_INIT(Leevel_Event_Dispatch);
	ZEPHIR_INIT(Leevel_Event_EventProvider);
	ZEPHIR_INIT(Leevel_Event_Observer);
	ZEPHIR_INIT(Leevel_Event_Provider_Register);
	ZEPHIR_INIT(Leevel_Event_Subject);
	ZEPHIR_INIT(Leevel_Filesystem);
	ZEPHIR_INIT(Leevel_Filesystem_Provider_Register);
	ZEPHIR_INIT(Leevel_Http_ApiResponse);
	ZEPHIR_INIT(Leevel_Http_FileBag);
	ZEPHIR_INIT(Leevel_Http_FileNotFoundException);
	ZEPHIR_INIT(Leevel_Http_FileResponse);
	ZEPHIR_INIT(Leevel_Http_RedirectResponse);
	ZEPHIR_INIT(Leevel_Http_Request);
	ZEPHIR_INIT(Leevel_Http_ResponseHeaderBag);
	ZEPHIR_INIT(Leevel_Http_ServerBag);
	ZEPHIR_INIT(Leevel_Http_UploadedFile);
	ZEPHIR_INIT(Leevel_I18n);
	ZEPHIR_INIT(Leevel_I18n_I18n);
	ZEPHIR_INIT(Leevel_I18n_Provider_Register);
	ZEPHIR_INIT(Leevel_Log);
	ZEPHIR_INIT(Leevel_Log_File);
	ZEPHIR_INIT(Leevel_Log_Log);
	ZEPHIR_INIT(Leevel_Log_Manager);
	ZEPHIR_INIT(Leevel_Log_Monolog);
	ZEPHIR_INIT(Leevel_Log_Provider_Register);
	ZEPHIR_INIT(Leevel_Log_middleware_Log);
	ZEPHIR_INIT(Leevel_Mail);
	ZEPHIR_INIT(Leevel_Mail_Provider_Register);
	ZEPHIR_INIT(Leevel_Mvc_Controller);
	ZEPHIR_INIT(Leevel_Mvc_View);
	ZEPHIR_INIT(Leevel_Option);
	ZEPHIR_INIT(Leevel_Option_Option);
	ZEPHIR_INIT(Leevel_Option_Provider_Register);
	ZEPHIR_INIT(Leevel_Pipeline_Pipeline);
	ZEPHIR_INIT(Leevel_Psr4);
	ZEPHIR_INIT(Leevel_Psr4_Psr4);
	ZEPHIR_INIT(Leevel_Request);
	ZEPHIR_INIT(Leevel_Response);
	ZEPHIR_INIT(Leevel_Router);
	ZEPHIR_INIT(Leevel_Router_Provider_Register);
	ZEPHIR_INIT(Leevel_Router_Url);
	ZEPHIR_INIT(Leevel_Session);
	ZEPHIR_INIT(Leevel_Session_Manager);
	ZEPHIR_INIT(Leevel_Session_Middleware_Session);
	ZEPHIR_INIT(Leevel_Session_Provider_Register);
	ZEPHIR_INIT(Leevel_Session_Session);
	ZEPHIR_INIT(Leevel_Support_ClosureUse);
	ZEPHIR_INIT(Leevel_Support_Type);
	ZEPHIR_INIT(Leevel_Throttler);
	ZEPHIR_INIT(Leevel_Throttler_Provider_Register);
	ZEPHIR_INIT(Leevel_Url);
	ZEPHIR_INIT(Leevel_Validate);
	ZEPHIR_INIT(Leevel_Validate_Provider_Register);
	ZEPHIR_INIT(Leevel_View);
	ZEPHIR_INIT(Leevel_View_Html);
	ZEPHIR_INIT(Leevel_View_Manager);
	ZEPHIR_INIT(Leevel_View_Provider_Register);
	ZEPHIR_INIT(Leevel_View_View);
	ZEPHIR_INIT(leevel_0__closure);
	ZEPHIR_INIT(leevel_10__closure);
	ZEPHIR_INIT(leevel_11__closure);
	ZEPHIR_INIT(leevel_12__closure);
	ZEPHIR_INIT(leevel_13__closure);
	ZEPHIR_INIT(leevel_14__closure);
	ZEPHIR_INIT(leevel_15__closure);
	ZEPHIR_INIT(leevel_16__closure);
	ZEPHIR_INIT(leevel_17__closure);
	ZEPHIR_INIT(leevel_18__closure);
	ZEPHIR_INIT(leevel_19__closure);
	ZEPHIR_INIT(leevel_1__closure);
	ZEPHIR_INIT(leevel_20__closure);
	ZEPHIR_INIT(leevel_21__closure);
	ZEPHIR_INIT(leevel_22__closure);
	ZEPHIR_INIT(leevel_23__closure);
	ZEPHIR_INIT(leevel_24__closure);
	ZEPHIR_INIT(leevel_25__closure);
	ZEPHIR_INIT(leevel_26__closure);
	ZEPHIR_INIT(leevel_27__closure);
	ZEPHIR_INIT(leevel_28__closure);
	ZEPHIR_INIT(leevel_29__closure);
	ZEPHIR_INIT(leevel_2__closure);
	ZEPHIR_INIT(leevel_30__closure);
	ZEPHIR_INIT(leevel_31__closure);
	ZEPHIR_INIT(leevel_32__closure);
	ZEPHIR_INIT(leevel_33__closure);
	ZEPHIR_INIT(leevel_34__closure);
	ZEPHIR_INIT(leevel_35__closure);
	ZEPHIR_INIT(leevel_36__closure);
	ZEPHIR_INIT(leevel_37__closure);
	ZEPHIR_INIT(leevel_3__closure);
	ZEPHIR_INIT(leevel_4__closure);
	ZEPHIR_INIT(leevel_5__closure);
	ZEPHIR_INIT(leevel_6__closure);
	ZEPHIR_INIT(leevel_7__closure);
	ZEPHIR_INIT(leevel_8__closure);
	ZEPHIR_INIT(leevel_9__closure);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(leevel)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_leevel_globals *leevel_globals TSRMLS_DC)
{
	leevel_globals->initialized = 0;

	/* Memory options */
	leevel_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	leevel_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	leevel_globals->cache_enabled = 1;

	/* Recursive Lock */
	leevel_globals->recursive_lock = 0;

	/* Static cache */
	memset(leevel_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_leevel_globals *leevel_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(leevel)
{

	zend_leevel_globals *leevel_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	leevel_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(leevel_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(leevel_globals_ptr TSRMLS_CC);

	zephir_init_static_properties_Leevel_Support_Facade(TSRMLS_C);
	zephir_init_static_properties_Leevel_Http_Response(TSRMLS_C);
	zephir_init_static_properties_Leevel_Collection_Collection(TSRMLS_C);
	zephir_init_static_properties_Leevel_Di_Container(TSRMLS_C);
	zephir_init_static_properties_Leevel_Http_FileBag(TSRMLS_C);
	zephir_init_static_properties_Leevel_Http_Request(TSRMLS_C);
	zephir_init_static_properties_Leevel_Http_UploadedFile(TSRMLS_C);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(leevel)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(leevel)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_LEEVEL_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_LEEVEL_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_LEEVEL_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_LEEVEL_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_LEEVEL_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(leevel)
{
	php_zephir_init_globals(leevel_globals TSRMLS_CC);
	php_zephir_init_module_globals(leevel_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(leevel)
{

}


zend_function_entry php_leevel_functions[] = {
ZEND_FE_END

};

zend_module_entry leevel_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_LEEVEL_EXTNAME,
	php_leevel_functions,
	PHP_MINIT(leevel),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(leevel),
#else
	NULL,
#endif
	PHP_RINIT(leevel),
	PHP_RSHUTDOWN(leevel),
	PHP_MINFO(leevel),
	PHP_LEEVEL_VERSION,
	ZEND_MODULE_GLOBALS(leevel),
	PHP_GINIT(leevel),
	PHP_GSHUTDOWN(leevel),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_LEEVEL
ZEND_GET_MODULE(leevel)
#endif