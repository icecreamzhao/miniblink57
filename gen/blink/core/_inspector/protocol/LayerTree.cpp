// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/LayerTree.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace LayerTree {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "LayerTree";
        const char Metainfo::commandPrefix[] = "LayerTree.";
        const char Metainfo::version[] = "1.2";

        const char* ScrollRect::TypeEnum::RepaintsOnScroll = "RepaintsOnScroll";
        const char* ScrollRect::TypeEnum::TouchEventHandler = "TouchEventHandler";
        const char* ScrollRect::TypeEnum::WheelEventHandler = "WheelEventHandler";

        std::unique_ptr<ScrollRect> ScrollRect::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ScrollRect> result(new ScrollRect());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* rectValue = object->get("rect");
            errors->setName("rect");
            result->m_rect = ValueConversions<protocol::DOM::Rect>::fromValue(rectValue, errors);
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ScrollRect::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("rect", ValueConversions<protocol::DOM::Rect>::toValue(m_rect.get()));
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            return result;
        }

        std::unique_ptr<ScrollRect> ScrollRect::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<PictureTile> PictureTile::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<PictureTile> result(new PictureTile());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* xValue = object->get("x");
            errors->setName("x");
            result->m_x = ValueConversions<double>::fromValue(xValue, errors);
            protocol::Value* yValue = object->get("y");
            errors->setName("y");
            result->m_y = ValueConversions<double>::fromValue(yValue, errors);
            protocol::Value* pictureValue = object->get("picture");
            errors->setName("picture");
            result->m_picture = ValueConversions<String>::fromValue(pictureValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> PictureTile::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("x", ValueConversions<double>::toValue(m_x));
            result->setValue("y", ValueConversions<double>::toValue(m_y));
            result->setValue("picture", ValueConversions<String>::toValue(m_picture));
            return result;
        }

        std::unique_ptr<PictureTile> PictureTile::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<Layer> Layer::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Layer> result(new Layer());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* layerIdValue = object->get("layerId");
            errors->setName("layerId");
            result->m_layerId = ValueConversions<String>::fromValue(layerIdValue, errors);
            protocol::Value* parentLayerIdValue = object->get("parentLayerId");
            if (parentLayerIdValue) {
                errors->setName("parentLayerId");
                result->m_parentLayerId = ValueConversions<String>::fromValue(parentLayerIdValue, errors);
            }
            protocol::Value* backendNodeIdValue = object->get("backendNodeId");
            if (backendNodeIdValue) {
                errors->setName("backendNodeId");
                result->m_backendNodeId = ValueConversions<int>::fromValue(backendNodeIdValue, errors);
            }
            protocol::Value* offsetXValue = object->get("offsetX");
            errors->setName("offsetX");
            result->m_offsetX = ValueConversions<double>::fromValue(offsetXValue, errors);
            protocol::Value* offsetYValue = object->get("offsetY");
            errors->setName("offsetY");
            result->m_offsetY = ValueConversions<double>::fromValue(offsetYValue, errors);
            protocol::Value* widthValue = object->get("width");
            errors->setName("width");
            result->m_width = ValueConversions<double>::fromValue(widthValue, errors);
            protocol::Value* heightValue = object->get("height");
            errors->setName("height");
            result->m_height = ValueConversions<double>::fromValue(heightValue, errors);
            protocol::Value* transformValue = object->get("transform");
            if (transformValue) {
                errors->setName("transform");
                result->m_transform = ValueConversions<protocol::Array<double>>::fromValue(transformValue, errors);
            }
            protocol::Value* anchorXValue = object->get("anchorX");
            if (anchorXValue) {
                errors->setName("anchorX");
                result->m_anchorX = ValueConversions<double>::fromValue(anchorXValue, errors);
            }
            protocol::Value* anchorYValue = object->get("anchorY");
            if (anchorYValue) {
                errors->setName("anchorY");
                result->m_anchorY = ValueConversions<double>::fromValue(anchorYValue, errors);
            }
            protocol::Value* anchorZValue = object->get("anchorZ");
            if (anchorZValue) {
                errors->setName("anchorZ");
                result->m_anchorZ = ValueConversions<double>::fromValue(anchorZValue, errors);
            }
            protocol::Value* paintCountValue = object->get("paintCount");
            errors->setName("paintCount");
            result->m_paintCount = ValueConversions<int>::fromValue(paintCountValue, errors);
            protocol::Value* drawsContentValue = object->get("drawsContent");
            errors->setName("drawsContent");
            result->m_drawsContent = ValueConversions<bool>::fromValue(drawsContentValue, errors);
            protocol::Value* invisibleValue = object->get("invisible");
            if (invisibleValue) {
                errors->setName("invisible");
                result->m_invisible = ValueConversions<bool>::fromValue(invisibleValue, errors);
            }
            protocol::Value* scrollRectsValue = object->get("scrollRects");
            if (scrollRectsValue) {
                errors->setName("scrollRects");
                result->m_scrollRects = ValueConversions<protocol::Array<protocol::LayerTree::ScrollRect>>::fromValue(scrollRectsValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Layer::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("layerId", ValueConversions<String>::toValue(m_layerId));
            if (m_parentLayerId.isJust())
                result->setValue("parentLayerId", ValueConversions<String>::toValue(m_parentLayerId.fromJust()));
            if (m_backendNodeId.isJust())
                result->setValue("backendNodeId", ValueConversions<int>::toValue(m_backendNodeId.fromJust()));
            result->setValue("offsetX", ValueConversions<double>::toValue(m_offsetX));
            result->setValue("offsetY", ValueConversions<double>::toValue(m_offsetY));
            result->setValue("width", ValueConversions<double>::toValue(m_width));
            result->setValue("height", ValueConversions<double>::toValue(m_height));
            if (m_transform.isJust())
                result->setValue("transform", ValueConversions<protocol::Array<double>>::toValue(m_transform.fromJust()));
            if (m_anchorX.isJust())
                result->setValue("anchorX", ValueConversions<double>::toValue(m_anchorX.fromJust()));
            if (m_anchorY.isJust())
                result->setValue("anchorY", ValueConversions<double>::toValue(m_anchorY.fromJust()));
            if (m_anchorZ.isJust())
                result->setValue("anchorZ", ValueConversions<double>::toValue(m_anchorZ.fromJust()));
            result->setValue("paintCount", ValueConversions<int>::toValue(m_paintCount));
            result->setValue("drawsContent", ValueConversions<bool>::toValue(m_drawsContent));
            if (m_invisible.isJust())
                result->setValue("invisible", ValueConversions<bool>::toValue(m_invisible.fromJust()));
            if (m_scrollRects.isJust())
                result->setValue("scrollRects", ValueConversions<protocol::Array<protocol::LayerTree::ScrollRect>>::toValue(m_scrollRects.fromJust()));
            return result;
        }

        std::unique_ptr<Layer> Layer::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<LayerTreeDidChangeNotification> LayerTreeDidChangeNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<LayerTreeDidChangeNotification> result(new LayerTreeDidChangeNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* layersValue = object->get("layers");
            if (layersValue) {
                errors->setName("layers");
                result->m_layers = ValueConversions<protocol::Array<protocol::LayerTree::Layer>>::fromValue(layersValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> LayerTreeDidChangeNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (m_layers.isJust())
                result->setValue("layers", ValueConversions<protocol::Array<protocol::LayerTree::Layer>>::toValue(m_layers.fromJust()));
            return result;
        }

        std::unique_ptr<LayerTreeDidChangeNotification> LayerTreeDidChangeNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<LayerPaintedNotification> LayerPaintedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<LayerPaintedNotification> result(new LayerPaintedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* layerIdValue = object->get("layerId");
            errors->setName("layerId");
            result->m_layerId = ValueConversions<String>::fromValue(layerIdValue, errors);
            protocol::Value* clipValue = object->get("clip");
            errors->setName("clip");
            result->m_clip = ValueConversions<protocol::DOM::Rect>::fromValue(clipValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> LayerPaintedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("layerId", ValueConversions<String>::toValue(m_layerId));
            result->setValue("clip", ValueConversions<protocol::DOM::Rect>::toValue(m_clip.get()));
            return result;
        }

        std::unique_ptr<LayerPaintedNotification> LayerPaintedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::layerTreeDidChange(Maybe<protocol::Array<protocol::LayerTree::Layer>> layers)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<LayerTreeDidChangeNotification> messageData = LayerTreeDidChangeNotification::create()
                                                                              .build();
            if (layers.isJust())
                messageData->setLayers(std::move(layers).takeJust());
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("LayerTree.layerTreeDidChange", std::move(messageData)));
        }

        void Frontend::layerPainted(const String& layerId, std::unique_ptr<protocol::DOM::Rect> clip)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<LayerPaintedNotification> messageData = LayerPaintedNotification::create()
                                                                        .setLayerId(layerId)
                                                                        .setClip(std::move(clip))
                                                                        .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("LayerTree.layerPainted", std::move(messageData)));
        }

        void Frontend::flush()
        {
            m_frontendChannel->flushProtocolNotifications();
        }

        void Frontend::sendRawNotification(const String& notification)
        {
            m_frontendChannel->sendProtocolNotification(InternalRawNotification::create(notification));
        }

        // --------------------- Dispatcher.

        class DispatcherImpl : public protocol::DispatcherBase {
        public:
            DispatcherImpl(FrontendChannel* frontendChannel, Backend* backend, bool fallThroughForNotFound)
                : DispatcherBase(frontendChannel)
                , m_backend(backend)
                , m_fallThroughForNotFound(fallThroughForNotFound)
            {
                m_dispatchMap["LayerTree.enable"] = &DispatcherImpl::enable;
                m_dispatchMap["LayerTree.disable"] = &DispatcherImpl::disable;
                m_dispatchMap["LayerTree.compositingReasons"] = &DispatcherImpl::compositingReasons;
                m_dispatchMap["LayerTree.makeSnapshot"] = &DispatcherImpl::makeSnapshot;
                m_dispatchMap["LayerTree.loadSnapshot"] = &DispatcherImpl::loadSnapshot;
                m_dispatchMap["LayerTree.releaseSnapshot"] = &DispatcherImpl::releaseSnapshot;
                m_dispatchMap["LayerTree.profileSnapshot"] = &DispatcherImpl::profileSnapshot;
                m_dispatchMap["LayerTree.replaySnapshot"] = &DispatcherImpl::replaySnapshot;
                m_dispatchMap["LayerTree.snapshotCommandLog"] = &DispatcherImpl::snapshotCommandLog;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status enable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status disable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status compositingReasons(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status makeSnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status loadSnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status releaseSnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status profileSnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status replaySnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status snapshotCommandLog(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

            Backend* m_backend;
            bool m_fallThroughForNotFound;
        };

        DispatchResponse::Status DispatcherImpl::dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject)
        {
            protocol::HashMap<String, CallHandler>::iterator it = m_dispatchMap.find(method);
            if (it == m_dispatchMap.end()) {
                if (m_fallThroughForNotFound)
                    return DispatchResponse::kFallThrough;
                reportProtocolError(callId, DispatchResponse::kMethodNotFound, "'" + method + "' wasn't found", nullptr);
                return DispatchResponse::kError;
            }

            protocol::ErrorSupport errors;
            return (this->*(it->second))(callId, std::move(messageObject), &errors);
        }

        DispatchResponse::Status DispatcherImpl::enable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->enable();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::disable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->disable();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::compositingReasons(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* layerIdValue = object ? object->get("layerId") : nullptr;
            errors->setName("layerId");
            String in_layerId = ValueConversions<String>::fromValue(layerIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<String>> out_compositingReasons;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->compositingReasons(in_layerId, &out_compositingReasons);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("compositingReasons", ValueConversions<protocol::Array<String>>::toValue(out_compositingReasons.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::makeSnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* layerIdValue = object ? object->get("layerId") : nullptr;
            errors->setName("layerId");
            String in_layerId = ValueConversions<String>::fromValue(layerIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            String out_snapshotId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->makeSnapshot(in_layerId, &out_snapshotId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("snapshotId", ValueConversions<String>::toValue(out_snapshotId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::loadSnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* tilesValue = object ? object->get("tiles") : nullptr;
            errors->setName("tiles");
            std::unique_ptr<protocol::Array<protocol::LayerTree::PictureTile>> in_tiles = ValueConversions<protocol::Array<protocol::LayerTree::PictureTile>>::fromValue(tilesValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            String out_snapshotId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->loadSnapshot(std::move(in_tiles), &out_snapshotId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("snapshotId", ValueConversions<String>::toValue(out_snapshotId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::releaseSnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* snapshotIdValue = object ? object->get("snapshotId") : nullptr;
            errors->setName("snapshotId");
            String in_snapshotId = ValueConversions<String>::fromValue(snapshotIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->releaseSnapshot(in_snapshotId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::profileSnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* snapshotIdValue = object ? object->get("snapshotId") : nullptr;
            errors->setName("snapshotId");
            String in_snapshotId = ValueConversions<String>::fromValue(snapshotIdValue, errors);
            protocol::Value* minRepeatCountValue = object ? object->get("minRepeatCount") : nullptr;
            Maybe<int> in_minRepeatCount;
            if (minRepeatCountValue) {
                errors->setName("minRepeatCount");
                in_minRepeatCount = ValueConversions<int>::fromValue(minRepeatCountValue, errors);
            }
            protocol::Value* minDurationValue = object ? object->get("minDuration") : nullptr;
            Maybe<double> in_minDuration;
            if (minDurationValue) {
                errors->setName("minDuration");
                in_minDuration = ValueConversions<double>::fromValue(minDurationValue, errors);
            }
            protocol::Value* clipRectValue = object ? object->get("clipRect") : nullptr;
            Maybe<protocol::DOM::Rect> in_clipRect;
            if (clipRectValue) {
                errors->setName("clipRect");
                in_clipRect = ValueConversions<protocol::DOM::Rect>::fromValue(clipRectValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<protocol::Array<double>>> out_timings;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->profileSnapshot(in_snapshotId, std::move(in_minRepeatCount), std::move(in_minDuration), std::move(in_clipRect), &out_timings);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("timings", ValueConversions<protocol::Array<protocol::Array<double>>>::toValue(out_timings.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::replaySnapshot(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* snapshotIdValue = object ? object->get("snapshotId") : nullptr;
            errors->setName("snapshotId");
            String in_snapshotId = ValueConversions<String>::fromValue(snapshotIdValue, errors);
            protocol::Value* fromStepValue = object ? object->get("fromStep") : nullptr;
            Maybe<int> in_fromStep;
            if (fromStepValue) {
                errors->setName("fromStep");
                in_fromStep = ValueConversions<int>::fromValue(fromStepValue, errors);
            }
            protocol::Value* toStepValue = object ? object->get("toStep") : nullptr;
            Maybe<int> in_toStep;
            if (toStepValue) {
                errors->setName("toStep");
                in_toStep = ValueConversions<int>::fromValue(toStepValue, errors);
            }
            protocol::Value* scaleValue = object ? object->get("scale") : nullptr;
            Maybe<double> in_scale;
            if (scaleValue) {
                errors->setName("scale");
                in_scale = ValueConversions<double>::fromValue(scaleValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            String out_dataURL;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->replaySnapshot(in_snapshotId, std::move(in_fromStep), std::move(in_toStep), std::move(in_scale), &out_dataURL);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("dataURL", ValueConversions<String>::toValue(out_dataURL));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::snapshotCommandLog(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* snapshotIdValue = object ? object->get("snapshotId") : nullptr;
            errors->setName("snapshotId");
            String in_snapshotId = ValueConversions<String>::fromValue(snapshotIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<protocol::DictionaryValue>> out_commandLog;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->snapshotCommandLog(in_snapshotId, &out_commandLog);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("commandLog", ValueConversions<protocol::Array<protocol::DictionaryValue>>::toValue(out_commandLog.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("LayerTree", std::move(dispatcher));
        }

    } // LayerTree
} // namespace blink
} // namespace protocol
