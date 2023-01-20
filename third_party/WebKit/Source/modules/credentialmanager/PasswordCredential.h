// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PasswordCredential_h
#define PasswordCredential_h

#include "bindings/core/v8/ScriptWrappable.h"
#include "bindings/core/v8/SerializedScriptValue.h"
<<<<<<< HEAD
#include "bindings/modules/v8/FormDataOrURLSearchParams.h"
#include "modules/ModulesExport.h"
#include "modules/credentialmanager/SiteBoundCredential.h"
#include "platform/heap/Handle.h"
#include "platform/network/EncodedFormData.h"
=======
#include "modules/credentialmanager/Credential.h"
#include "platform/heap/Handle.h"
>>>>>>> miniblink49
#include "platform/weborigin/KURL.h"

namespace blink {

<<<<<<< HEAD
class HTMLFormElement;
class PasswordCredentialData;
class WebPasswordCredential;

using CredentialPostBodyType = FormDataOrURLSearchParams;

class MODULES_EXPORT PasswordCredential final : public SiteBoundCredential {
    DEFINE_WRAPPERTYPEINFO();

public:
    static PasswordCredential* create(const PasswordCredentialData&,
        ExceptionState&);
    static PasswordCredential* create(HTMLFormElement*, ExceptionState&);
    static PasswordCredential* create(WebPasswordCredential*);

    // PasswordCredential.idl
    void setIdName(const String& name) { m_idName = name; }
    const String& idName() const { return m_idName; }

    void setPasswordName(const String& name) { m_passwordName = name; }
    const String& passwordName() const { return m_passwordName; }

    void setAdditionalData(const CredentialPostBodyType& data)
    {
        m_additionalData = data;
    }
    void additionalData(CredentialPostBodyType& out) const
    {
        out = m_additionalData;
    }

    // Internal methods
    PassRefPtr<EncodedFormData> encodeFormData(String& contentType) const;
    const String& password() const;
=======
class DOMFormData;
class WebPasswordCredential;

class PasswordCredential final : public Credential {
    DEFINE_WRAPPERTYPEINFO();
public:
    static PasswordCredential* create(const String& id, const String& password, ExceptionState& exceptionState)
    {
        return create(id, password, emptyString(), emptyString(), exceptionState);
    }

    static PasswordCredential* create(const String& id, const String& password, const String& name, ExceptionState& exceptionState)
    {
        return create(id, password, name, emptyString(), exceptionState);
    }

    static PasswordCredential* create(const String& id, const String& password, const String& name, const String& icon, ExceptionState&);
    static PasswordCredential* create(WebPasswordCredential*);

    // PasswordCredential.idl
    const String& password() const;
    DOMFormData* formData() const { return m_formData; }

>>>>>>> miniblink49
    DECLARE_VIRTUAL_TRACE();

private:
    PasswordCredential(WebPasswordCredential*);
<<<<<<< HEAD
    PasswordCredential(const String& id,
        const String& password,
        const String& name,
        const KURL& icon);

    String m_idName;
    String m_passwordName;
    CredentialPostBodyType m_additionalData;
=======
    PasswordCredential(const String& id, const String& password, const String& name, const KURL& icon);

    Member<DOMFormData> m_formData;
>>>>>>> miniblink49
};

} // namespace blink

#endif // PasswordCredential_h
