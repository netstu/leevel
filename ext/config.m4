PHP_ARG_ENABLE(queryyetsimple, whether to enable queryyetsimple, [ --enable-queryyetsimple   Enable Queryyetsimple])

if test "$PHP_QUERYYETSIMPLE" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, QUERYYETSIMPLE_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_QUERYYETSIMPLE, 1, [Whether you have Queryyetsimple])
	queryyetsimple_sources="queryyetsimple.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c queryyetsimple/support/facade.zep.c
	queryyetsimple/di/provider.zep.c
	queryyetsimple/option/iclass.zep.c
	queryyetsimple/support/iarray.zep.c
	queryyetsimple/support/ijson.zep.c
	queryyetsimple/http/bag.zep.c
	queryyetsimple/manager/manager.zep.c
	queryyetsimple/mvc/iview.zep.c
	queryyetsimple/log/connect.zep.c
	queryyetsimple/log/iconnect.zep.c
	queryyetsimple/cookie/icookie.zep.c
	queryyetsimple/di/icontainer.zep.c
	queryyetsimple/event/idispatch.zep.c
	queryyetsimple/event/isubject.zep.c
	queryyetsimple/i18n/ii18n.zep.c
	queryyetsimple/log/ilog.zep.c
	queryyetsimple/mvc/icontroller.zep.c
	queryyetsimple/mvc/ientity.zep.c
	queryyetsimple/option/ioption.zep.c
	queryyetsimple/pipeline/ipipeline.zep.c
	queryyetsimple/psr4/ipsr4.zep.c
	queryyetsimple/session/isession.zep.c
	queryyetsimple/support/imacro.zep.c
	queryyetsimple/view/connect.zep.c
	queryyetsimple/view/iconnect.zep.c
	queryyetsimple/view/iview.zep.c
	queryyetsimple/auth.zep.c
	queryyetsimple/auth/provider/register.zep.c
	queryyetsimple/cache.zep.c
	queryyetsimple/cache/provider/register.zep.c
	queryyetsimple/collection/collection.zep.c
	queryyetsimple/cookie.zep.c
	queryyetsimple/cookie/cookie.zep.c
	queryyetsimple/cookie/provider/register.zep.c
	queryyetsimple/database.zep.c
	queryyetsimple/database/provider/register.zep.c
	queryyetsimple/db.zep.c
	queryyetsimple/di/container.zep.c
	queryyetsimple/encryption.zep.c
	queryyetsimple/encryption/provider/register.zep.c
	queryyetsimple/event.zep.c
	queryyetsimple/event/dispatch.zep.c
	queryyetsimple/event/eventprovider.zep.c
	queryyetsimple/event/observer.zep.c
	queryyetsimple/event/provider/register.zep.c
	queryyetsimple/event/subject.zep.c
	queryyetsimple/filesystem.zep.c
	queryyetsimple/filesystem/provider/register.zep.c
	queryyetsimple/http/filebag.zep.c
	queryyetsimple/http/headerbag.zep.c
	queryyetsimple/http/irequest.zep.c
	queryyetsimple/http/iresponse.zep.c
	queryyetsimple/http/serverbag.zep.c
	queryyetsimple/i18n.zep.c
	queryyetsimple/i18n/i18n.zep.c
	queryyetsimple/i18n/provider/register.zep.c
	queryyetsimple/log.zep.c
	queryyetsimple/log/file.zep.c
	queryyetsimple/log/log.zep.c
	queryyetsimple/log/manager.zep.c
	queryyetsimple/log/middleware/log.zep.c
	queryyetsimple/log/monolog.zep.c
	queryyetsimple/log/provider/register.zep.c
	queryyetsimple/mail.zep.c
	queryyetsimple/mail/provider/register.zep.c
	queryyetsimple/mvc/controller.zep.c
	queryyetsimple/mvc/imodel.zep.c
	queryyetsimple/mvc/view.zep.c
	queryyetsimple/option.zep.c
	queryyetsimple/option/option.zep.c
	queryyetsimple/option/provider/register.zep.c
	queryyetsimple/pipeline/pipeline.zep.c
	queryyetsimple/psr4.zep.c
	queryyetsimple/psr4/psr4.zep.c
	queryyetsimple/request.zep.c
	queryyetsimple/response.zep.c
	queryyetsimple/router.zep.c
	queryyetsimple/router/provider/register.zep.c
	queryyetsimple/session.zep.c
	queryyetsimple/session/manager.zep.c
	queryyetsimple/session/middleware/session.zep.c
	queryyetsimple/session/provider/register.zep.c
	queryyetsimple/session/session.zep.c
	queryyetsimple/support/closureuse.zep.c
	queryyetsimple/support/ihtml.zep.c
	queryyetsimple/support/type.zep.c
	queryyetsimple/throttler.zep.c
	queryyetsimple/throttler/provider/register.zep.c
	queryyetsimple/url.zep.c
	queryyetsimple/validate.zep.c
	queryyetsimple/validate/provider/register.zep.c
	queryyetsimple/view.zep.c
	queryyetsimple/view/html.zep.c
	queryyetsimple/view/manager.zep.c
	queryyetsimple/view/provider/register.zep.c
	queryyetsimple/view/view.zep.c
	queryyetsimple/0__closure.zep.c
	queryyetsimple/1__closure.zep.c
	queryyetsimple/2__closure.zep.c
	queryyetsimple/3__closure.zep.c
	queryyetsimple/4__closure.zep.c
	queryyetsimple/5__closure.zep.c
	queryyetsimple/6__closure.zep.c
	queryyetsimple/7__closure.zep.c
	queryyetsimple/8__closure.zep.c
	queryyetsimple/9__closure.zep.c
	queryyetsimple/10__closure.zep.c
	queryyetsimple/11__closure.zep.c
	queryyetsimple/12__closure.zep.c
	queryyetsimple/13__closure.zep.c
	queryyetsimple/14__closure.zep.c
	queryyetsimple/15__closure.zep.c
	queryyetsimple/16__closure.zep.c
	queryyetsimple/17__closure.zep.c
	queryyetsimple/18__closure.zep.c
	queryyetsimple/19__closure.zep.c
	queryyetsimple/20__closure.zep.c
	queryyetsimple/21__closure.zep.c
	queryyetsimple/22__closure.zep.c
	queryyetsimple/23__closure.zep.c
	queryyetsimple/24__closure.zep.c
	queryyetsimple/25__closure.zep.c
	queryyetsimple/26__closure.zep.c
	queryyetsimple/27__closure.zep.c
	queryyetsimple/28__closure.zep.c
	queryyetsimple/29__closure.zep.c
	queryyetsimple/30__closure.zep.c
	queryyetsimple/31__closure.zep.c
	queryyetsimple/32__closure.zep.c
	queryyetsimple/33__closure.zep.c
	queryyetsimple/34__closure.zep.c
	queryyetsimple/35__closure.zep.c
	queryyetsimple/36__closure.zep.c
	queryyetsimple/37__closure.zep.c "
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
