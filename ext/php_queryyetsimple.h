
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_QUERYYETSIMPLE_H
#define PHP_QUERYYETSIMPLE_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_QUERYYETSIMPLE_NAME        "queryyetsimple"
#define PHP_QUERYYETSIMPLE_VERSION     "1.0.0"
#define PHP_QUERYYETSIMPLE_EXTNAME     "queryyetsimple"
#define PHP_QUERYYETSIMPLE_AUTHOR      "Xiangmin Liu <635750556@qq.com>"
#define PHP_QUERYYETSIMPLE_ZEPVERSION  "0.10.6-0b7210d4f6"
#define PHP_QUERYYETSIMPLE_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(queryyetsimple)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(queryyetsimple)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(queryyetsimple)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(queryyetsimple, v)
#else
	#define ZEPHIR_GLOBAL(v) (queryyetsimple_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_queryyetsimple_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(queryyetsimple_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(queryyetsimple_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def queryyetsimple_globals
#define zend_zephir_globals_def zend_queryyetsimple_globals

extern zend_module_entry queryyetsimple_module_entry;
#define phpext_queryyetsimple_ptr &queryyetsimple_module_entry

#endif
