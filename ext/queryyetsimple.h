
/* This file was generated automatically by Zephir do not modify it! */

#ifndef ZEPHIR_CLASS_ENTRIES_H
#define ZEPHIR_CLASS_ENTRIES_H

#include "queryyetsimple/support/facade.zep.h"
#include "queryyetsimple/di/provider.zep.h"
#include "queryyetsimple/option/iclass.zep.h"
#include "queryyetsimple/support/iarray.zep.h"
#include "queryyetsimple/support/imacro.zep.h"
#include "queryyetsimple/support/ijson.zep.h"
#include "queryyetsimple/flow/icontrol.zep.h"
#include "queryyetsimple/http/iresponse.zep.h"
#include "queryyetsimple/http/bag.zep.h"
#include "queryyetsimple/http/response.zep.h"
#include "queryyetsimple/manager/manager.zep.h"
#include "queryyetsimple/mvc/iview.zep.h"
#include "queryyetsimple/log/connect.zep.h"
#include "queryyetsimple/log/iconnect.zep.h"
#include "queryyetsimple/cookie/icookie.zep.h"
#include "queryyetsimple/di/icontainer.zep.h"
#include "queryyetsimple/event/idispatch.zep.h"
#include "queryyetsimple/event/isubject.zep.h"
#include "queryyetsimple/http/file.zep.h"
#include "queryyetsimple/http/fileexception.zep.h"
#include "queryyetsimple/http/headerbag.zep.h"
#include "queryyetsimple/http/irequest.zep.h"
#include "queryyetsimple/http/jsonresponse.zep.h"
#include "queryyetsimple/i18n/ii18n.zep.h"
#include "queryyetsimple/log/ilog.zep.h"
#include "queryyetsimple/mvc/icontroller.zep.h"
#include "queryyetsimple/mvc/ientity.zep.h"
#include "queryyetsimple/option/ioption.zep.h"
#include "queryyetsimple/pipeline/ipipeline.zep.h"
#include "queryyetsimple/psr4/ipsr4.zep.h"
#include "queryyetsimple/router/iurl.zep.h"
#include "queryyetsimple/session/isession.zep.h"
#include "queryyetsimple/view/connect.zep.h"
#include "queryyetsimple/view/iconnect.zep.h"
#include "queryyetsimple/view/iview.zep.h"
#include "queryyetsimple/auth.zep.h"
#include "queryyetsimple/auth/provider/register.zep.h"
#include "queryyetsimple/cache.zep.h"
#include "queryyetsimple/cache/provider/register.zep.h"
#include "queryyetsimple/collection/collection.zep.h"
#include "queryyetsimple/cookie.zep.h"
#include "queryyetsimple/cookie/cookie.zep.h"
#include "queryyetsimple/cookie/provider/register.zep.h"
#include "queryyetsimple/database.zep.h"
#include "queryyetsimple/database/provider/register.zep.h"
#include "queryyetsimple/db.zep.h"
#include "queryyetsimple/di/container.zep.h"
#include "queryyetsimple/encryption.zep.h"
#include "queryyetsimple/encryption/provider/register.zep.h"
#include "queryyetsimple/event.zep.h"
#include "queryyetsimple/event/dispatch.zep.h"
#include "queryyetsimple/event/eventprovider.zep.h"
#include "queryyetsimple/event/observer.zep.h"
#include "queryyetsimple/event/provider/register.zep.h"
#include "queryyetsimple/event/subject.zep.h"
#include "queryyetsimple/filesystem.zep.h"
#include "queryyetsimple/filesystem/provider/register.zep.h"
#include "queryyetsimple/http/apiresponse.zep.h"
#include "queryyetsimple/http/filebag.zep.h"
#include "queryyetsimple/http/filenotfoundexception.zep.h"
#include "queryyetsimple/http/fileresponse.zep.h"
#include "queryyetsimple/http/redirectresponse.zep.h"
#include "queryyetsimple/http/request.zep.h"
#include "queryyetsimple/http/responseheaderbag.zep.h"
#include "queryyetsimple/http/serverbag.zep.h"
#include "queryyetsimple/http/uploadedfile.zep.h"
#include "queryyetsimple/i18n.zep.h"
#include "queryyetsimple/i18n/i18n.zep.h"
#include "queryyetsimple/i18n/provider/register.zep.h"
#include "queryyetsimple/log.zep.h"
#include "queryyetsimple/log/file.zep.h"
#include "queryyetsimple/log/log.zep.h"
#include "queryyetsimple/log/manager.zep.h"
#include "queryyetsimple/log/middleware/log.zep.h"
#include "queryyetsimple/log/monolog.zep.h"
#include "queryyetsimple/log/provider/register.zep.h"
#include "queryyetsimple/mail.zep.h"
#include "queryyetsimple/mail/provider/register.zep.h"
#include "queryyetsimple/mvc/controller.zep.h"
#include "queryyetsimple/mvc/imodel.zep.h"
#include "queryyetsimple/mvc/view.zep.h"
#include "queryyetsimple/option.zep.h"
#include "queryyetsimple/option/option.zep.h"
#include "queryyetsimple/option/provider/register.zep.h"
#include "queryyetsimple/pipeline/pipeline.zep.h"
#include "queryyetsimple/psr4.zep.h"
#include "queryyetsimple/psr4/psr4.zep.h"
#include "queryyetsimple/request.zep.h"
#include "queryyetsimple/response.zep.h"
#include "queryyetsimple/router.zep.h"
#include "queryyetsimple/router/irouter.zep.h"
#include "queryyetsimple/router/provider/register.zep.h"
#include "queryyetsimple/router/url.zep.h"
#include "queryyetsimple/session.zep.h"
#include "queryyetsimple/session/manager.zep.h"
#include "queryyetsimple/session/middleware/session.zep.h"
#include "queryyetsimple/session/provider/register.zep.h"
#include "queryyetsimple/session/session.zep.h"
#include "queryyetsimple/support/closureuse.zep.h"
#include "queryyetsimple/support/ihtml.zep.h"
#include "queryyetsimple/support/type.zep.h"
#include "queryyetsimple/throttler.zep.h"
#include "queryyetsimple/throttler/provider/register.zep.h"
#include "queryyetsimple/url.zep.h"
#include "queryyetsimple/validate.zep.h"
#include "queryyetsimple/validate/provider/register.zep.h"
#include "queryyetsimple/view.zep.h"
#include "queryyetsimple/view/html.zep.h"
#include "queryyetsimple/view/manager.zep.h"
#include "queryyetsimple/view/provider/register.zep.h"
#include "queryyetsimple/view/view.zep.h"
#include "queryyetsimple/0__closure.zep.h"
#include "queryyetsimple/1__closure.zep.h"
#include "queryyetsimple/2__closure.zep.h"
#include "queryyetsimple/3__closure.zep.h"
#include "queryyetsimple/4__closure.zep.h"
#include "queryyetsimple/5__closure.zep.h"
#include "queryyetsimple/6__closure.zep.h"
#include "queryyetsimple/7__closure.zep.h"
#include "queryyetsimple/8__closure.zep.h"
#include "queryyetsimple/9__closure.zep.h"
#include "queryyetsimple/10__closure.zep.h"
#include "queryyetsimple/11__closure.zep.h"
#include "queryyetsimple/12__closure.zep.h"
#include "queryyetsimple/13__closure.zep.h"
#include "queryyetsimple/14__closure.zep.h"
#include "queryyetsimple/15__closure.zep.h"
#include "queryyetsimple/16__closure.zep.h"
#include "queryyetsimple/17__closure.zep.h"
#include "queryyetsimple/18__closure.zep.h"
#include "queryyetsimple/19__closure.zep.h"
#include "queryyetsimple/20__closure.zep.h"
#include "queryyetsimple/21__closure.zep.h"
#include "queryyetsimple/22__closure.zep.h"
#include "queryyetsimple/23__closure.zep.h"
#include "queryyetsimple/24__closure.zep.h"
#include "queryyetsimple/25__closure.zep.h"
#include "queryyetsimple/26__closure.zep.h"
#include "queryyetsimple/27__closure.zep.h"
#include "queryyetsimple/28__closure.zep.h"
#include "queryyetsimple/29__closure.zep.h"
#include "queryyetsimple/30__closure.zep.h"
#include "queryyetsimple/31__closure.zep.h"
#include "queryyetsimple/32__closure.zep.h"
#include "queryyetsimple/33__closure.zep.h"
#include "queryyetsimple/34__closure.zep.h"
#include "queryyetsimple/35__closure.zep.h"
#include "queryyetsimple/36__closure.zep.h"
#include "queryyetsimple/37__closure.zep.h"

#endif