PHP_ARG_ENABLE(queryyetsimple, whether to enable queryyetsimple, [ --enable-queryyetsimple   Enable Queryyetsimple])

if test "$PHP_QUERYYETSIMPLE" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, QUERYYETSIMPLE_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_QUERYYETSIMPLE, 1, [Whether you have Queryyetsimple])
	queryyetsimple_sources="queryyetsimple.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c queryyetsimple/support/face.zep.c
	queryyetsimple/mvc/iview.zep.c
	queryyetsimple/mvc/iaction.zep.c
	queryyetsimple/mvc/icontroller.zep.c
	queryyetsimple/mvc/ientity.zep.c
	queryyetsimple/option/ioption.zep.c
	queryyetsimple/pipeline/ipipeline.zep.c
	queryyetsimple/view/itheme.zep.c
	queryyetsimple/auth.zep.c
	queryyetsimple/cache.zep.c
	queryyetsimple/cookie.zep.c
	queryyetsimple/database.zep.c
	queryyetsimple/db.zep.c
	queryyetsimple/encryption.zep.c
	queryyetsimple/event.zep.c
	queryyetsimple/filesystem.zep.c
	queryyetsimple/i18n.zep.c
	queryyetsimple/log.zep.c
	queryyetsimple/mail.zep.c
	queryyetsimple/mvc/action.zep.c
	queryyetsimple/mvc/controller.zep.c
	queryyetsimple/mvc/imodel.zep.c
	queryyetsimple/mvc/view.zep.c
	queryyetsimple/option.zep.c
	queryyetsimple/option/option.zep.c
	queryyetsimple/pipeline/pipeline.zep.c
	queryyetsimple/psr4.zep.c
	queryyetsimple/request.zep.c
	queryyetsimple/response.zep.c
	queryyetsimple/router.zep.c
	queryyetsimple/session.zep.c
	queryyetsimple/support/icontainer.zep.c
	queryyetsimple/support/ihtml.zep.c
	queryyetsimple/support/ijson.zep.c
	queryyetsimple/throttler.zep.c
	queryyetsimple/validate.zep.c
	queryyetsimple/view.zep.c
	queryyetsimple/view/theme.zep.c
	queryyetsimple/0__closure.zep.c "
	PHP_NEW_EXTENSION(queryyetsimple, $queryyetsimple_sources, $ext_shared,, )
	PHP_SUBST(QUERYYETSIMPLE_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([queryyetsimple], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([queryyetsimple], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/queryyetsimple], [php_QUERYYETSIMPLE.h])

fi
