/*
 * Copyright (C) 2010 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

<<<<<<< HEAD
#include "platform/weborigin/SchemeRegistry.h"

//#include "url/url_util.h"
#include "wtf/ThreadSpecific.h"
#include "wtf/Threading.h"
=======
#include "config.h"
#include "platform/weborigin/SchemeRegistry.h"

#include "wtf/ThreadSpecific.h"
>>>>>>> miniblink49
#include "wtf/ThreadingPrimitives.h"
#include "wtf/text/StringBuilder.h"

namespace blink {

<<<<<<< HEAD
namespace {

    class URLSchemesRegistry final {
    public:
        URLSchemesRegistry()
            : emptyDocumentSchemes({ "about" })
            ,
            // For ServiceWorker schemes: HTTP is required because http://localhost
            // is considered secure. Additional checks are performed to ensure that
            // other http pages are filtered out.
            serviceWorkerSchemes({ "http", "https" })
            , fetchAPISchemes({ "http", "https" })
            , allowedInReferrerSchemes({ "http", "https" })
        {
            //     for (auto& scheme : url::GetLocalSchemes())
            //       localSchemes.add(scheme.c_str());
            //     for (auto& scheme : url::GetSecureSchemes())
            //       secureSchemes.add(scheme.c_str());
            //     for (auto& scheme : url::GetNoAccessSchemes())
            //       schemesWithUniqueOrigins.add(scheme.c_str());
            //     for (auto& scheme : url::GetCORSEnabledSchemes())
            //       CORSEnabledSchemes.add(scheme.c_str());
            //DebugBreak();

            const char* schemes[] = {"http", "https", "file", nullptr};
            for (size_t i = 0; schemes[i] != nullptr; ++i) {
                localSchemes.add(schemes[i]);
                secureSchemes.add(schemes[i]);
                //schemesWithUniqueOrigins.add(schemes[i]);
                CORSEnabledSchemes.add(schemes[i]);
            }
        }
        ~URLSchemesRegistry() = default;

        URLSchemesSet localSchemes;
        URLSchemesSet displayIsolatedURLSchemes;
        URLSchemesSet secureSchemes;
        URLSchemesSet schemesWithUniqueOrigins;
        URLSchemesSet emptyDocumentSchemes;
        URLSchemesSet schemesForbiddenFromDomainRelaxation;
        URLSchemesSet notAllowingJavascriptURLsSchemes;
        URLSchemesSet CORSEnabledSchemes;
        URLSchemesSet serviceWorkerSchemes;
        URLSchemesSet fetchAPISchemes;
        URLSchemesSet firstPartyWhenTopLevelSchemes;
        URLSchemesMap<SchemeRegistry::PolicyAreas>
            contentSecurityPolicyBypassingSchemes;
        URLSchemesSet secureContextBypassingSchemes;
        URLSchemesSet allowedInReferrerSchemes;

    private:
        friend const URLSchemesRegistry& getURLSchemesRegistry();
        friend URLSchemesRegistry& getMutableURLSchemesRegistry();

        static URLSchemesRegistry& getInstance()
        {
            DEFINE_STATIC_LOCAL(URLSchemesRegistry, schemes, ());
            return schemes;
        }
    };

    const URLSchemesRegistry& getURLSchemesRegistry()
    {
        return URLSchemesRegistry::getInstance();
    }

    URLSchemesRegistry& getMutableURLSchemesRegistry()
    {
#if DCHECK_IS_ON()
        DCHECK(WTF::isBeforeThreadCreated());
#endif
        return URLSchemesRegistry::getInstance();
    }

} // namespace

// Must be called before we create other threads to avoid racy static local
// initialization.
void SchemeRegistry::initialize()
{
    getURLSchemesRegistry();
=======
static Mutex& mutex()
{
    // The first call to this should be made before or during blink
    // initialization to avoid racy static local initialization.
    DEFINE_STATIC_LOCAL(Mutex, m, ());
    return m;
}

static void assertLockHeld()
{
#if ENABLE(ASSERT)
    ASSERT(mutex().locked());
#endif
}

static URLSchemesSet& localURLSchemes()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesSet, localSchemes, ());

    if (localSchemes.isEmpty())
        localSchemes.add("file");

    return localSchemes;
}

static URLSchemesSet& displayIsolatedURLSchemes()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesSet, displayIsolatedSchemes, ());
    return displayIsolatedSchemes;
}

static URLSchemesSet& mixedContentRestrictingSchemes()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesSet, mixedContentRestrictingSchemes, ());

    if (mixedContentRestrictingSchemes.isEmpty())
        mixedContentRestrictingSchemes.add("https");

    return mixedContentRestrictingSchemes;
}

static URLSchemesSet& secureSchemes()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesSet, secureSchemes, ());

    if (secureSchemes.isEmpty()) {
        secureSchemes.add("https");
        secureSchemes.add("about");
        secureSchemes.add("data");
        secureSchemes.add("wss");
    }

    return secureSchemes;
}

static URLSchemesSet& schemesWithUniqueOrigins()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesSet, schemesWithUniqueOrigins, ());

    if (schemesWithUniqueOrigins.isEmpty()) {
        schemesWithUniqueOrigins.add("about");
        schemesWithUniqueOrigins.add("javascript");
        // This is a willful violation of HTML5.
        // See https://bugs.webkit.org/show_bug.cgi?id=11885
        schemesWithUniqueOrigins.add("data");
    }

    return schemesWithUniqueOrigins;
}

static URLSchemesSet& emptyDocumentSchemes()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesSet, emptyDocumentSchemes, ());

    if (emptyDocumentSchemes.isEmpty())
        emptyDocumentSchemes.add("about");

    return emptyDocumentSchemes;
}

static HashSet<String>& schemesForbiddenFromDomainRelaxation()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(HashSet<String>, schemes, ());
    return schemes;
}

static URLSchemesSet& notAllowingJavascriptURLsSchemes()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesSet, notAllowingJavascriptURLsSchemes, ());
    return notAllowingJavascriptURLsSchemes;
>>>>>>> miniblink49
}

void SchemeRegistry::registerURLSchemeAsLocal(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().localSchemes.add(scheme);
=======
    MutexLocker locker(mutex());
    localURLSchemes().add(scheme);
}

const URLSchemesSet& SchemeRegistry::localSchemes()
{
    MutexLocker locker(mutex());
    return localURLSchemes();
}

static URLSchemesSet& CORSEnabledSchemes()
{
    // FIXME: http://bugs.webkit.org/show_bug.cgi?id=77160
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesSet, CORSEnabledSchemes, ());

    if (CORSEnabledSchemes.isEmpty()) {
        CORSEnabledSchemes.add("http");
        CORSEnabledSchemes.add("https");
        CORSEnabledSchemes.add("data");
    }

    return CORSEnabledSchemes;
}

static URLSchemesSet& serviceWorkerSchemes()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesSet, serviceWorkerSchemes, ());

    if (serviceWorkerSchemes.isEmpty()) {
        // HTTP is required because http://localhost is considered secure.
        // Additional checks are performed to ensure that other http pages
        // are filtered out.
        serviceWorkerSchemes.add("http");
        serviceWorkerSchemes.add("https");
    }

    return serviceWorkerSchemes;
}

static URLSchemesMap<SchemeRegistry::PolicyAreas>& ContentSecurityPolicyBypassingSchemes()
{
    assertLockHeld();
    DEFINE_STATIC_LOCAL_NOASSERT(URLSchemesMap<SchemeRegistry::PolicyAreas>, schemes, ());
    return schemes;
>>>>>>> miniblink49
}

bool SchemeRegistry::shouldTreatURLSchemeAsLocal(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().localSchemes.contains(scheme);
=======
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return localURLSchemes().contains(scheme);
>>>>>>> miniblink49
}

void SchemeRegistry::registerURLSchemeAsNoAccess(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().schemesWithUniqueOrigins.add(scheme);
=======
    MutexLocker locker(mutex());
    schemesWithUniqueOrigins().add(scheme);
>>>>>>> miniblink49
}

bool SchemeRegistry::shouldTreatURLSchemeAsNoAccess(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().schemesWithUniqueOrigins.contains(scheme);
=======
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return schemesWithUniqueOrigins().contains(scheme);
>>>>>>> miniblink49
}

void SchemeRegistry::registerURLSchemeAsDisplayIsolated(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().displayIsolatedURLSchemes.add(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsDisplayIsolated(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().displayIsolatedURLSchemes.contains(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsRestrictingMixedContent(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    return scheme == "https";
=======
    MutexLocker locker(mutex());
    displayIsolatedURLSchemes().add(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsDisplayIsolated(const String& scheme)
{
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return displayIsolatedURLSchemes().contains(scheme);
}

void SchemeRegistry::registerURLSchemeAsRestrictingMixedContent(const String& scheme)
{
    MutexLocker locker(mutex());
    mixedContentRestrictingSchemes().add(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsRestrictingMixedContent(const String& scheme)
{
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return mixedContentRestrictingSchemes().contains(scheme);
>>>>>>> miniblink49
}

void SchemeRegistry::registerURLSchemeAsSecure(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().secureSchemes.add(scheme);
=======
    MutexLocker locker(mutex());
    secureSchemes().add(scheme);
>>>>>>> miniblink49
}

bool SchemeRegistry::shouldTreatURLSchemeAsSecure(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().secureSchemes.contains(scheme);
=======
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return secureSchemes().contains(scheme);
>>>>>>> miniblink49
}

void SchemeRegistry::registerURLSchemeAsEmptyDocument(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().emptyDocumentSchemes.add(scheme);
=======
    MutexLocker locker(mutex());
    emptyDocumentSchemes().add(scheme);
>>>>>>> miniblink49
}

bool SchemeRegistry::shouldLoadURLSchemeAsEmptyDocument(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().emptyDocumentSchemes.contains(scheme);
}

void SchemeRegistry::setDomainRelaxationForbiddenForURLScheme(
    bool forbidden,
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return;

    if (forbidden) {
        getMutableURLSchemesRegistry().schemesForbiddenFromDomainRelaxation.add(
            scheme);
    } else {
        getMutableURLSchemesRegistry().schemesForbiddenFromDomainRelaxation.remove(
            scheme);
    }
}

bool SchemeRegistry::isDomainRelaxationForbiddenForURLScheme(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().schemesForbiddenFromDomainRelaxation.contains(
        scheme);
=======
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return emptyDocumentSchemes().contains(scheme);
}

void SchemeRegistry::setDomainRelaxationForbiddenForURLScheme(bool forbidden, const String& scheme)
{
    if (scheme.isEmpty())
        return;

    MutexLocker locker(mutex());
    if (forbidden)
        schemesForbiddenFromDomainRelaxation().add(scheme);
    else
        schemesForbiddenFromDomainRelaxation().remove(scheme);
}

bool SchemeRegistry::isDomainRelaxationForbiddenForURLScheme(const String& scheme)
{
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return schemesForbiddenFromDomainRelaxation().contains(scheme);
>>>>>>> miniblink49
}

bool SchemeRegistry::canDisplayOnlyIfCanRequest(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    return scheme == "blob" || scheme == "filesystem";
}

void SchemeRegistry::registerURLSchemeAsNotAllowingJavascriptURLs(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().notAllowingJavascriptURLsSchemes.add(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsNotAllowingJavascriptURLs(
    const String& scheme)
{
//     DCHECK_EQ(scheme, scheme.lower());
//     if (scheme.isEmpty())
//         return false;
//     return getURLSchemesRegistry().notAllowingJavascriptURLsSchemes.contains(
//         scheme);
    return true;
=======
    return equalIgnoringCase("blob", scheme) || equalIgnoringCase("filesystem", scheme);
}

void SchemeRegistry::registerURLSchemeAsNotAllowingJavascriptURLs(const String& scheme)
{
    MutexLocker locker(mutex());
    notAllowingJavascriptURLsSchemes().add(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsNotAllowingJavascriptURLs(const String& scheme)
{
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return notAllowingJavascriptURLsSchemes().contains(scheme);
>>>>>>> miniblink49
}

void SchemeRegistry::registerURLSchemeAsCORSEnabled(const String& scheme)
{
<<<<<<< HEAD
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().CORSEnabledSchemes.add(scheme);
=======
    MutexLocker locker(mutex());
    CORSEnabledSchemes().add(scheme);
>>>>>>> miniblink49
}

bool SchemeRegistry::shouldTreatURLSchemeAsCORSEnabled(const String& scheme)
{
<<<<<<< HEAD
//     DCHECK_EQ(scheme, scheme.lower());
//     if (scheme.isEmpty())
//         return false;
//     return getURLSchemesRegistry().CORSEnabledSchemes.contains(scheme);
    return true;
=======
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return CORSEnabledSchemes().contains(scheme);
>>>>>>> miniblink49
}

String SchemeRegistry::listOfCORSEnabledURLSchemes()
{
    StringBuilder builder;
    bool addSeparator = false;
<<<<<<< HEAD
    for (const auto& scheme : getURLSchemesRegistry().CORSEnabledSchemes) {
        if (addSeparator)
            builder.append(", ");
=======
    URLSchemesSet schemes;
    {
        MutexLocker locker(mutex());
        schemes = CORSEnabledSchemes();
    }
    for (const auto& scheme : schemes) {
        if (addSeparator)
            builder.appendLiteral(", ");
>>>>>>> miniblink49
        else
            addSeparator = true;

        builder.append(scheme);
    }
    return builder.toString();
}

bool SchemeRegistry::shouldTreatURLSchemeAsLegacy(const String& scheme)
{
<<<<<<< HEAD
    return scheme == "ftp" || scheme == "gopher";
}

bool SchemeRegistry::shouldTrackUsageMetricsForScheme(const String& scheme)
{
    // The scheme represents content which likely cannot be easily updated.
    // Specifically this includes internal pages such as about, chrome-devtools,
    // etc.
    // "chrome-extension" is not included because they have a single deployment
    // point (the webstore) and are designed specifically for Chrome.
    // "data" is not included because real sites shouldn't be using it for
    // top-level
    // pages and Chrome does use it internally (eg. PluginPlaceholder).
    return scheme == "http" || scheme == "https" || scheme == "file";
}

void SchemeRegistry::registerURLSchemeAsAllowingServiceWorkers(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().serviceWorkerSchemes.add(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().serviceWorkerSchemes.contains(scheme);
}

void SchemeRegistry::registerURLSchemeAsSupportingFetchAPI(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().fetchAPISchemes.add(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsSupportingFetchAPI(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().fetchAPISchemes.contains(scheme);
}

void SchemeRegistry::registerURLSchemeAsFirstPartyWhenTopLevel(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().firstPartyWhenTopLevelSchemes.add(scheme);
}

void SchemeRegistry::removeURLSchemeAsFirstPartyWhenTopLevel(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().firstPartyWhenTopLevelSchemes.remove(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsFirstPartyWhenTopLevel(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().firstPartyWhenTopLevelSchemes.contains(scheme);
}

void SchemeRegistry::registerURLSchemeAsAllowedForReferrer(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().allowedInReferrerSchemes.add(scheme);
}

void SchemeRegistry::removeURLSchemeAsAllowedForReferrer(const String& scheme)
{
    getMutableURLSchemesRegistry().allowedInReferrerSchemes.remove(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsAllowedForReferrer(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    if (scheme.isEmpty())
        return false;
    return getURLSchemesRegistry().allowedInReferrerSchemes.contains(scheme);
}

void SchemeRegistry::registerURLSchemeAsBypassingContentSecurityPolicy(
    const String& scheme,
    PolicyAreas policyAreas)
{
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().contentSecurityPolicyBypassingSchemes.add(
        scheme, policyAreas);
}

void SchemeRegistry::removeURLSchemeRegisteredAsBypassingContentSecurityPolicy(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().contentSecurityPolicyBypassingSchemes.remove(
        scheme);
}

bool SchemeRegistry::schemeShouldBypassContentSecurityPolicy(
    const String& scheme,
    PolicyAreas policyAreas)
=======
    return equalIgnoringCase("ftp", scheme) || equalIgnoringCase("gopher", scheme);
}

void SchemeRegistry::registerURLSchemeAsAllowingServiceWorkers(const String& scheme)
{
    MutexLocker locker(mutex());
    serviceWorkerSchemes().add(scheme);
}

bool SchemeRegistry::shouldTreatURLSchemeAsAllowingServiceWorkers(const String& scheme)
{
    if (scheme.isEmpty())
        return false;
    MutexLocker locker(mutex());
    return serviceWorkerSchemes().contains(scheme);
}

void SchemeRegistry::registerURLSchemeAsBypassingContentSecurityPolicy(const String& scheme, PolicyAreas policyAreas)
{
    MutexLocker locker(mutex());
    ContentSecurityPolicyBypassingSchemes().add(scheme, policyAreas);
}

void SchemeRegistry::removeURLSchemeRegisteredAsBypassingContentSecurityPolicy(const String& scheme)
{
    MutexLocker locker(mutex());
    ContentSecurityPolicyBypassingSchemes().remove(scheme);
}

bool SchemeRegistry::schemeShouldBypassContentSecurityPolicy(const String& scheme, PolicyAreas policyAreas)
>>>>>>> miniblink49
{
    ASSERT(policyAreas != PolicyAreaNone);
    if (scheme.isEmpty() || policyAreas == PolicyAreaNone)
        return false;

    // get() returns 0 (PolicyAreaNone) if there is no entry in the map.
    // Thus by default, schemes do not bypass CSP.
<<<<<<< HEAD
    return (getURLSchemesRegistry().contentSecurityPolicyBypassingSchemes.get(
                scheme)
               & policyAreas)
        == policyAreas;
}

void SchemeRegistry::registerURLSchemeBypassingSecureContextCheck(
    const String& scheme)
{
    DCHECK_EQ(scheme, scheme.lower());
    getMutableURLSchemesRegistry().secureContextBypassingSchemes.add(scheme);
}

bool SchemeRegistry::schemeShouldBypassSecureContextCheck(
    const String& scheme)
{
    if (scheme.isEmpty())
        return false;
    DCHECK_EQ(scheme, scheme.lower());
    return getURLSchemesRegistry().secureContextBypassingSchemes.contains(scheme);
=======
    MutexLocker locker(mutex());
    return (ContentSecurityPolicyBypassingSchemes().get(scheme) & policyAreas) == policyAreas;
>>>>>>> miniblink49
}

} // namespace blink
