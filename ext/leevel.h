
/* This file was generated automatically by Zephir do not modify it! */

#ifndef ZEPHIR_CLASS_ENTRIES_H
#define ZEPHIR_CLASS_ENTRIES_H

#include "leevel/support/facade.zep.h"
#include "leevel/di/provider.zep.h"
#include "leevel/support/imacro.zep.h"
#include "leevel/support/iarray.zep.h"
#include "leevel/support/ijson.zep.h"
#include "leevel/flow/icontrol.zep.h"
#include "leevel/http/iresponse.zep.h"
#include "leevel/di/icontainer.zep.h"
#include "leevel/http/bag.zep.h"
#include "leevel/http/response.zep.h"
#include "leevel/view/connect.zep.h"
#include "leevel/view/iconnect.zep.h"
#include "leevel/log/iconnect.zep.h"
#include "leevel/manager/manager.zep.h"
#include "leevel/mvc/iview.zep.h"
#include "leevel/cookie/icookie.zep.h"
#include "leevel/di/container.zep.h"
#include "leevel/event/idispatch.zep.h"
#include "leevel/event/isubject.zep.h"
#include "leevel/http/file.zep.h"
#include "leevel/http/fileexception.zep.h"
#include "leevel/http/headerbag.zep.h"
#include "leevel/http/irequest.zep.h"
#include "leevel/http/jsonresponse.zep.h"
#include "leevel/i18n/ii18n.zep.h"
#include "leevel/kernel/ikernel.zep.h"
#include "leevel/kernel/iproject.zep.h"
#include "leevel/log/connect.zep.h"
#include "leevel/log/ilog.zep.h"
#include "leevel/mvc/icontroller.zep.h"
#include "leevel/option/ioption.zep.h"
#include "leevel/pipeline/ipipeline.zep.h"
#include "leevel/router/iresponsefactory.zep.h"
#include "leevel/router/irouter.zep.h"
#include "leevel/router/iurl.zep.h"
#include "leevel/router/match/imatch.zep.h"
#include "leevel/session/isession.zep.h"
#include "leevel/view/iview.zep.h"
#include "leevel/auth.zep.h"
#include "leevel/auth/provider/register.zep.h"
#include "leevel/bootstrap/bootstrap/loadi18n.zep.h"
#include "leevel/bootstrap/bootstrap/loadoption.zep.h"
#include "leevel/bootstrap/bootstrap/registerruntime.zep.h"
#include "leevel/bootstrap/bootstrap/traverseprovider.zep.h"
#include "leevel/bootstrap/kernel.zep.h"
#include "leevel/bootstrap/project.zep.h"
#include "leevel/cache.zep.h"
#include "leevel/cache/provider/register.zep.h"
#include "leevel/collection/collection.zep.h"
#include "leevel/cookie.zep.h"
#include "leevel/cookie/cookie.zep.h"
#include "leevel/cookie/provider/register.zep.h"
#include "leevel/database.zep.h"
#include "leevel/database/provider/register.zep.h"
#include "leevel/db.zep.h"
#include "leevel/di/containerinvalidargumentexception.zep.h"
#include "leevel/encryption.zep.h"
#include "leevel/encryption/provider/register.zep.h"
#include "leevel/event.zep.h"
#include "leevel/event/dispatch.zep.h"
#include "leevel/event/eventprovider.zep.h"
#include "leevel/event/observer.zep.h"
#include "leevel/event/provider/register.zep.h"
#include "leevel/event/subject.zep.h"
#include "leevel/filesystem.zep.h"
#include "leevel/filesystem/provider/register.zep.h"
#include "leevel/http/apiresponse.zep.h"
#include "leevel/http/filebag.zep.h"
#include "leevel/http/filenotfoundexception.zep.h"
#include "leevel/http/fileresponse.zep.h"
#include "leevel/http/redirectresponse.zep.h"
#include "leevel/http/request.zep.h"
#include "leevel/http/responseheaderbag.zep.h"
#include "leevel/http/serverbag.zep.h"
#include "leevel/http/uploadedfile.zep.h"
#include "leevel/i18n.zep.h"
#include "leevel/i18n/i18n.zep.h"
#include "leevel/leevel.zep.h"
#include "leevel/log.zep.h"
#include "leevel/log/file.zep.h"
#include "leevel/log/log.zep.h"
#include "leevel/log/manager.zep.h"
#include "leevel/log/middleware/log.zep.h"
#include "leevel/log/provider/register.zep.h"
#include "leevel/log/syslog.zep.h"
#include "leevel/mail.zep.h"
#include "leevel/mail/provider/register.zep.h"
#include "leevel/mvc/controller.zep.h"
#include "leevel/mvc/view.zep.h"
#include "leevel/option.zep.h"
#include "leevel/option/option.zep.h"
#include "leevel/page.zep.h"
#include "leevel/pipeline/pipeline.zep.h"
#include "leevel/request.zep.h"
#include "leevel/response.zep.h"
#include "leevel/router.zep.h"
#include "leevel/router/match/pathinfo.zep.h"
#include "leevel/router/provider/register.zep.h"
#include "leevel/router/responsefactory.zep.h"
#include "leevel/router/router.zep.h"
#include "leevel/router/routerprovider.zep.h"
#include "leevel/router/url.zep.h"
#include "leevel/session.zep.h"
#include "leevel/session/manager.zep.h"
#include "leevel/session/middleware/session.zep.h"
#include "leevel/session/provider/register.zep.h"
#include "leevel/session/session.zep.h"
#include "leevel/support/debug/console.zep.h"
#include "leevel/support/ihtml.zep.h"
#include "leevel/support/type.zep.h"
#include "leevel/throttler.zep.h"
#include "leevel/throttler/provider/register.zep.h"
#include "leevel/url.zep.h"
#include "leevel/validate.zep.h"
#include "leevel/validate/provider/register.zep.h"
#include "leevel/view.zep.h"
#include "leevel/view/html.zep.h"
#include "leevel/view/manager.zep.h"
#include "leevel/view/phpui.zep.h"
#include "leevel/view/provider/register.zep.h"
#include "leevel/view/twig.zep.h"
#include "leevel/view/v8js.zep.h"
#include "leevel/view/view.zep.h"

#endif