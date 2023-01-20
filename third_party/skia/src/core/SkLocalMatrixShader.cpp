/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkLocalMatrixShader.h"

<<<<<<< HEAD
#if SK_SUPPORT_GPU
#include "GrFragmentProcessor.h"
#endif

#if SK_SUPPORT_GPU
sk_sp<GrFragmentProcessor> SkLocalMatrixShader::asFragmentProcessor(
    GrContext* context, const SkMatrix& viewM,
    const SkMatrix* localMatrix, SkFilterQuality fq,
    SkSourceGammaTreatment gammaTreatment) const
{
    SkMatrix tmp = this->getLocalMatrix();
    if (localMatrix) {
        tmp.preConcat(*localMatrix);
    }
    return fProxyShader->asFragmentProcessor(context, viewM, &tmp, fq, gammaTreatment);
}
#endif

sk_sp<SkFlattenable> SkLocalMatrixShader::CreateProc(SkReadBuffer& buffer)
{
    SkMatrix lm;
    buffer.readMatrix(&lm);
    auto baseShader(buffer.readShader());
    if (!baseShader) {
        return nullptr;
    }
    return baseShader->makeWithLocalMatrix(lm);
}

void SkLocalMatrixShader::flatten(SkWriteBuffer& buffer) const
{
=======
SkFlattenable* SkLocalMatrixShader::CreateProc(SkReadBuffer& buffer) {
    SkMatrix lm;
    buffer.readMatrix(&lm);
    SkAutoTUnref<SkShader> shader(buffer.readShader());
    if (!shader.get()) {
        return NULL;
    }
    return SkShader::CreateLocalMatrixShader(shader, lm);
}

void SkLocalMatrixShader::flatten(SkWriteBuffer& buffer) const {
>>>>>>> miniblink49
    buffer.writeMatrix(this->getLocalMatrix());
    buffer.writeFlattenable(fProxyShader.get());
}

SkShader::Context* SkLocalMatrixShader::onCreateContext(const ContextRec& rec,
<<<<<<< HEAD
    void* storage) const
{
=======
                                                        void* storage) const {
>>>>>>> miniblink49
    ContextRec newRec(rec);
    SkMatrix tmp;
    if (rec.fLocalMatrix) {
        tmp.setConcat(*rec.fLocalMatrix, this->getLocalMatrix());
        newRec.fLocalMatrix = &tmp;
    } else {
        newRec.fLocalMatrix = &this->getLocalMatrix();
    }
    return fProxyShader->createContext(newRec, storage);
}

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
void SkLocalMatrixShader::toString(SkString* str) const
{
=======
void SkLocalMatrixShader::toString(SkString* str) const {
>>>>>>> miniblink49
    str->append("SkLocalMatrixShader: (");

    fProxyShader->toString(str);

    this->INHERITED::toString(str);

    str->append(")");
}
#endif

<<<<<<< HEAD
sk_sp<SkShader> SkShader::makeWithLocalMatrix(const SkMatrix& localMatrix) const
{
    if (localMatrix.isIdentity()) {
        return sk_ref_sp(const_cast<SkShader*>(this));
=======
SkShader* SkShader::CreateLocalMatrixShader(SkShader* proxy, const SkMatrix& localMatrix) {
    if (NULL == proxy) {
        return NULL;
    }

    if (localMatrix.isIdentity()) {
        return SkRef(proxy);
>>>>>>> miniblink49
    }

    const SkMatrix* lm = &localMatrix;

<<<<<<< HEAD
    SkShader* baseShader = const_cast<SkShader*>(this);
    SkMatrix otherLocalMatrix;
    SkAutoTUnref<SkShader> proxy(this->refAsALocalMatrixShader(&otherLocalMatrix));
    if (proxy) {
        otherLocalMatrix.preConcat(localMatrix);
        lm = &otherLocalMatrix;
        baseShader = proxy.get();
    }

    return sk_make_sp<SkLocalMatrixShader>(baseShader, *lm);
=======
    SkMatrix otherLocalMatrix;
    SkAutoTUnref<SkShader> otherProxy(proxy->refAsALocalMatrixShader(&otherLocalMatrix));
    if (otherProxy.get()) {
        otherLocalMatrix.preConcat(localMatrix);
        lm = &otherLocalMatrix;
        proxy = otherProxy.get();
    }

    return SkNEW_ARGS(SkLocalMatrixShader, (proxy, *lm));
>>>>>>> miniblink49
}
