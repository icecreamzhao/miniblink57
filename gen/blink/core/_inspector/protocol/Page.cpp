// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/Page.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace Page {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Page";
        const char Metainfo::commandPrefix[] = "Page.";
        const char Metainfo::version[] = "1.2";

        namespace ResourceTypeEnum {
            const char* Document = "Document";
            const char* Stylesheet = "Stylesheet";
            const char* Image = "Image";
            const char* Media = "Media";
            const char* Font = "Font";
            const char* Script = "Script";
            const char* TextTrack = "TextTrack";
            const char* XHR = "XHR";
            const char* Fetch = "Fetch";
            const char* EventSource = "EventSource";
            const char* WebSocket = "WebSocket";
            const char* Manifest = "Manifest";
            const char* Other = "Other";
        } // namespace ResourceTypeEnum

        std::unique_ptr<Frame> Frame::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Frame> result(new Frame());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* idValue = object->get("id");
            errors->setName("id");
            result->m_id = ValueConversions<String>::fromValue(idValue, errors);
            protocol::Value* parentIdValue = object->get("parentId");
            if (parentIdValue) {
                errors->setName("parentId");
                result->m_parentId = ValueConversions<String>::fromValue(parentIdValue, errors);
            }
            protocol::Value* loaderIdValue = object->get("loaderId");
            errors->setName("loaderId");
            result->m_loaderId = ValueConversions<String>::fromValue(loaderIdValue, errors);
            protocol::Value* nameValue = object->get("name");
            if (nameValue) {
                errors->setName("name");
                result->m_name = ValueConversions<String>::fromValue(nameValue, errors);
            }
            protocol::Value* urlValue = object->get("url");
            errors->setName("url");
            result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* securityOriginValue = object->get("securityOrigin");
            errors->setName("securityOrigin");
            result->m_securityOrigin = ValueConversions<String>::fromValue(securityOriginValue, errors);
            protocol::Value* mimeTypeValue = object->get("mimeType");
            errors->setName("mimeType");
            result->m_mimeType = ValueConversions<String>::fromValue(mimeTypeValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Frame::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("id", ValueConversions<String>::toValue(m_id));
            if (m_parentId.isJust())
                result->setValue("parentId", ValueConversions<String>::toValue(m_parentId.fromJust()));
            result->setValue("loaderId", ValueConversions<String>::toValue(m_loaderId));
            if (m_name.isJust())
                result->setValue("name", ValueConversions<String>::toValue(m_name.fromJust()));
            result->setValue("url", ValueConversions<String>::toValue(m_url));
            result->setValue("securityOrigin", ValueConversions<String>::toValue(m_securityOrigin));
            result->setValue("mimeType", ValueConversions<String>::toValue(m_mimeType));
            return result;
        }

        std::unique_ptr<Frame> Frame::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<FrameResource> FrameResource::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<FrameResource> result(new FrameResource());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* urlValue = object->get("url");
            errors->setName("url");
            result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* mimeTypeValue = object->get("mimeType");
            errors->setName("mimeType");
            result->m_mimeType = ValueConversions<String>::fromValue(mimeTypeValue, errors);
            protocol::Value* lastModifiedValue = object->get("lastModified");
            if (lastModifiedValue) {
                errors->setName("lastModified");
                result->m_lastModified = ValueConversions<double>::fromValue(lastModifiedValue, errors);
            }
            protocol::Value* contentSizeValue = object->get("contentSize");
            if (contentSizeValue) {
                errors->setName("contentSize");
                result->m_contentSize = ValueConversions<double>::fromValue(contentSizeValue, errors);
            }
            protocol::Value* failedValue = object->get("failed");
            if (failedValue) {
                errors->setName("failed");
                result->m_failed = ValueConversions<bool>::fromValue(failedValue, errors);
            }
            protocol::Value* canceledValue = object->get("canceled");
            if (canceledValue) {
                errors->setName("canceled");
                result->m_canceled = ValueConversions<bool>::fromValue(canceledValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> FrameResource::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("url", ValueConversions<String>::toValue(m_url));
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            result->setValue("mimeType", ValueConversions<String>::toValue(m_mimeType));
            if (m_lastModified.isJust())
                result->setValue("lastModified", ValueConversions<double>::toValue(m_lastModified.fromJust()));
            if (m_contentSize.isJust())
                result->setValue("contentSize", ValueConversions<double>::toValue(m_contentSize.fromJust()));
            if (m_failed.isJust())
                result->setValue("failed", ValueConversions<bool>::toValue(m_failed.fromJust()));
            if (m_canceled.isJust())
                result->setValue("canceled", ValueConversions<bool>::toValue(m_canceled.fromJust()));
            return result;
        }

        std::unique_ptr<FrameResource> FrameResource::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<FrameResourceTree> FrameResourceTree::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<FrameResourceTree> result(new FrameResourceTree());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* frameValue = object->get("frame");
            errors->setName("frame");
            result->m_frame = ValueConversions<protocol::Page::Frame>::fromValue(frameValue, errors);
            protocol::Value* childFramesValue = object->get("childFrames");
            if (childFramesValue) {
                errors->setName("childFrames");
                result->m_childFrames = ValueConversions<protocol::Array<protocol::Page::FrameResourceTree>>::fromValue(childFramesValue, errors);
            }
            protocol::Value* resourcesValue = object->get("resources");
            errors->setName("resources");
            result->m_resources = ValueConversions<protocol::Array<protocol::Page::FrameResource>>::fromValue(resourcesValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> FrameResourceTree::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("frame", ValueConversions<protocol::Page::Frame>::toValue(m_frame.get()));
            if (m_childFrames.isJust())
                result->setValue("childFrames", ValueConversions<protocol::Array<protocol::Page::FrameResourceTree>>::toValue(m_childFrames.fromJust()));
            result->setValue("resources", ValueConversions<protocol::Array<protocol::Page::FrameResource>>::toValue(m_resources.get()));
            return result;
        }

        std::unique_ptr<FrameResourceTree> FrameResourceTree::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<NavigationEntry> NavigationEntry::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<NavigationEntry> result(new NavigationEntry());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* idValue = object->get("id");
            errors->setName("id");
            result->m_id = ValueConversions<int>::fromValue(idValue, errors);
            protocol::Value* urlValue = object->get("url");
            errors->setName("url");
            result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* titleValue = object->get("title");
            errors->setName("title");
            result->m_title = ValueConversions<String>::fromValue(titleValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> NavigationEntry::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("id", ValueConversions<int>::toValue(m_id));
            result->setValue("url", ValueConversions<String>::toValue(m_url));
            result->setValue("title", ValueConversions<String>::toValue(m_title));
            return result;
        }

        std::unique_ptr<NavigationEntry> NavigationEntry::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ScreencastFrameMetadata> ScreencastFrameMetadata::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ScreencastFrameMetadata> result(new ScreencastFrameMetadata());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* offsetTopValue = object->get("offsetTop");
            errors->setName("offsetTop");
            result->m_offsetTop = ValueConversions<double>::fromValue(offsetTopValue, errors);
            protocol::Value* pageScaleFactorValue = object->get("pageScaleFactor");
            errors->setName("pageScaleFactor");
            result->m_pageScaleFactor = ValueConversions<double>::fromValue(pageScaleFactorValue, errors);
            protocol::Value* deviceWidthValue = object->get("deviceWidth");
            errors->setName("deviceWidth");
            result->m_deviceWidth = ValueConversions<double>::fromValue(deviceWidthValue, errors);
            protocol::Value* deviceHeightValue = object->get("deviceHeight");
            errors->setName("deviceHeight");
            result->m_deviceHeight = ValueConversions<double>::fromValue(deviceHeightValue, errors);
            protocol::Value* scrollOffsetXValue = object->get("scrollOffsetX");
            errors->setName("scrollOffsetX");
            result->m_scrollOffsetX = ValueConversions<double>::fromValue(scrollOffsetXValue, errors);
            protocol::Value* scrollOffsetYValue = object->get("scrollOffsetY");
            errors->setName("scrollOffsetY");
            result->m_scrollOffsetY = ValueConversions<double>::fromValue(scrollOffsetYValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            if (timestampValue) {
                errors->setName("timestamp");
                result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ScreencastFrameMetadata::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("offsetTop", ValueConversions<double>::toValue(m_offsetTop));
            result->setValue("pageScaleFactor", ValueConversions<double>::toValue(m_pageScaleFactor));
            result->setValue("deviceWidth", ValueConversions<double>::toValue(m_deviceWidth));
            result->setValue("deviceHeight", ValueConversions<double>::toValue(m_deviceHeight));
            result->setValue("scrollOffsetX", ValueConversions<double>::toValue(m_scrollOffsetX));
            result->setValue("scrollOffsetY", ValueConversions<double>::toValue(m_scrollOffsetY));
            if (m_timestamp.isJust())
                result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp.fromJust()));
            return result;
        }

        std::unique_ptr<ScreencastFrameMetadata> ScreencastFrameMetadata::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace DialogTypeEnum {
            const char* Alert = "alert";
            const char* Confirm = "confirm";
            const char* Prompt = "prompt";
            const char* Beforeunload = "beforeunload";
        } // namespace DialogTypeEnum

        std::unique_ptr<AppManifestError> AppManifestError::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AppManifestError> result(new AppManifestError());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* messageValue = object->get("message");
            errors->setName("message");
            result->m_message = ValueConversions<String>::fromValue(messageValue, errors);
            protocol::Value* criticalValue = object->get("critical");
            errors->setName("critical");
            result->m_critical = ValueConversions<int>::fromValue(criticalValue, errors);
            protocol::Value* lineValue = object->get("line");
            errors->setName("line");
            result->m_line = ValueConversions<int>::fromValue(lineValue, errors);
            protocol::Value* columnValue = object->get("column");
            errors->setName("column");
            result->m_column = ValueConversions<int>::fromValue(columnValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AppManifestError::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("message", ValueConversions<String>::toValue(m_message));
            result->setValue("critical", ValueConversions<int>::toValue(m_critical));
            result->setValue("line", ValueConversions<int>::toValue(m_line));
            result->setValue("column", ValueConversions<int>::toValue(m_column));
            return result;
        }

        std::unique_ptr<AppManifestError> AppManifestError::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace NavigationResponseEnum {
            const char* Proceed = "Proceed";
            const char* Cancel = "Cancel";
            const char* CancelAndIgnore = "CancelAndIgnore";
        } // namespace NavigationResponseEnum

        std::unique_ptr<LayoutViewport> LayoutViewport::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<LayoutViewport> result(new LayoutViewport());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* pageXValue = object->get("pageX");
            errors->setName("pageX");
            result->m_pageX = ValueConversions<int>::fromValue(pageXValue, errors);
            protocol::Value* pageYValue = object->get("pageY");
            errors->setName("pageY");
            result->m_pageY = ValueConversions<int>::fromValue(pageYValue, errors);
            protocol::Value* clientWidthValue = object->get("clientWidth");
            errors->setName("clientWidth");
            result->m_clientWidth = ValueConversions<int>::fromValue(clientWidthValue, errors);
            protocol::Value* clientHeightValue = object->get("clientHeight");
            errors->setName("clientHeight");
            result->m_clientHeight = ValueConversions<int>::fromValue(clientHeightValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> LayoutViewport::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("pageX", ValueConversions<int>::toValue(m_pageX));
            result->setValue("pageY", ValueConversions<int>::toValue(m_pageY));
            result->setValue("clientWidth", ValueConversions<int>::toValue(m_clientWidth));
            result->setValue("clientHeight", ValueConversions<int>::toValue(m_clientHeight));
            return result;
        }

        std::unique_ptr<LayoutViewport> LayoutViewport::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<VisualViewport> VisualViewport::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<VisualViewport> result(new VisualViewport());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* offsetXValue = object->get("offsetX");
            errors->setName("offsetX");
            result->m_offsetX = ValueConversions<double>::fromValue(offsetXValue, errors);
            protocol::Value* offsetYValue = object->get("offsetY");
            errors->setName("offsetY");
            result->m_offsetY = ValueConversions<double>::fromValue(offsetYValue, errors);
            protocol::Value* pageXValue = object->get("pageX");
            errors->setName("pageX");
            result->m_pageX = ValueConversions<double>::fromValue(pageXValue, errors);
            protocol::Value* pageYValue = object->get("pageY");
            errors->setName("pageY");
            result->m_pageY = ValueConversions<double>::fromValue(pageYValue, errors);
            protocol::Value* clientWidthValue = object->get("clientWidth");
            errors->setName("clientWidth");
            result->m_clientWidth = ValueConversions<double>::fromValue(clientWidthValue, errors);
            protocol::Value* clientHeightValue = object->get("clientHeight");
            errors->setName("clientHeight");
            result->m_clientHeight = ValueConversions<double>::fromValue(clientHeightValue, errors);
            protocol::Value* scaleValue = object->get("scale");
            errors->setName("scale");
            result->m_scale = ValueConversions<double>::fromValue(scaleValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> VisualViewport::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("offsetX", ValueConversions<double>::toValue(m_offsetX));
            result->setValue("offsetY", ValueConversions<double>::toValue(m_offsetY));
            result->setValue("pageX", ValueConversions<double>::toValue(m_pageX));
            result->setValue("pageY", ValueConversions<double>::toValue(m_pageY));
            result->setValue("clientWidth", ValueConversions<double>::toValue(m_clientWidth));
            result->setValue("clientHeight", ValueConversions<double>::toValue(m_clientHeight));
            result->setValue("scale", ValueConversions<double>::toValue(m_scale));
            return result;
        }

        std::unique_ptr<VisualViewport> VisualViewport::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<DomContentEventFiredNotification> DomContentEventFiredNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DomContentEventFiredNotification> result(new DomContentEventFiredNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DomContentEventFiredNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            return result;
        }

        std::unique_ptr<DomContentEventFiredNotification> DomContentEventFiredNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<LoadEventFiredNotification> LoadEventFiredNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<LoadEventFiredNotification> result(new LoadEventFiredNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> LoadEventFiredNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            return result;
        }

        std::unique_ptr<LoadEventFiredNotification> LoadEventFiredNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<FrameAttachedNotification> FrameAttachedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<FrameAttachedNotification> result(new FrameAttachedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* frameIdValue = object->get("frameId");
            errors->setName("frameId");
            result->m_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            protocol::Value* parentFrameIdValue = object->get("parentFrameId");
            errors->setName("parentFrameId");
            result->m_parentFrameId = ValueConversions<String>::fromValue(parentFrameIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> FrameAttachedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("frameId", ValueConversions<String>::toValue(m_frameId));
            result->setValue("parentFrameId", ValueConversions<String>::toValue(m_parentFrameId));
            return result;
        }

        std::unique_ptr<FrameAttachedNotification> FrameAttachedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<FrameNavigatedNotification> FrameNavigatedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<FrameNavigatedNotification> result(new FrameNavigatedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* frameValue = object->get("frame");
            errors->setName("frame");
            result->m_frame = ValueConversions<protocol::Page::Frame>::fromValue(frameValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> FrameNavigatedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("frame", ValueConversions<protocol::Page::Frame>::toValue(m_frame.get()));
            return result;
        }

        std::unique_ptr<FrameNavigatedNotification> FrameNavigatedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<FrameDetachedNotification> FrameDetachedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<FrameDetachedNotification> result(new FrameDetachedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* frameIdValue = object->get("frameId");
            errors->setName("frameId");
            result->m_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> FrameDetachedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("frameId", ValueConversions<String>::toValue(m_frameId));
            return result;
        }

        std::unique_ptr<FrameDetachedNotification> FrameDetachedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<FrameStartedLoadingNotification> FrameStartedLoadingNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<FrameStartedLoadingNotification> result(new FrameStartedLoadingNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* frameIdValue = object->get("frameId");
            errors->setName("frameId");
            result->m_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> FrameStartedLoadingNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("frameId", ValueConversions<String>::toValue(m_frameId));
            return result;
        }

        std::unique_ptr<FrameStartedLoadingNotification> FrameStartedLoadingNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<FrameStoppedLoadingNotification> FrameStoppedLoadingNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<FrameStoppedLoadingNotification> result(new FrameStoppedLoadingNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* frameIdValue = object->get("frameId");
            errors->setName("frameId");
            result->m_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> FrameStoppedLoadingNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("frameId", ValueConversions<String>::toValue(m_frameId));
            return result;
        }

        std::unique_ptr<FrameStoppedLoadingNotification> FrameStoppedLoadingNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<FrameScheduledNavigationNotification> FrameScheduledNavigationNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<FrameScheduledNavigationNotification> result(new FrameScheduledNavigationNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* frameIdValue = object->get("frameId");
            errors->setName("frameId");
            result->m_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            protocol::Value* delayValue = object->get("delay");
            errors->setName("delay");
            result->m_delay = ValueConversions<double>::fromValue(delayValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> FrameScheduledNavigationNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("frameId", ValueConversions<String>::toValue(m_frameId));
            result->setValue("delay", ValueConversions<double>::toValue(m_delay));
            return result;
        }

        std::unique_ptr<FrameScheduledNavigationNotification> FrameScheduledNavigationNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<FrameClearedScheduledNavigationNotification> FrameClearedScheduledNavigationNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<FrameClearedScheduledNavigationNotification> result(new FrameClearedScheduledNavigationNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* frameIdValue = object->get("frameId");
            errors->setName("frameId");
            result->m_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> FrameClearedScheduledNavigationNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("frameId", ValueConversions<String>::toValue(m_frameId));
            return result;
        }

        std::unique_ptr<FrameClearedScheduledNavigationNotification> FrameClearedScheduledNavigationNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<JavascriptDialogOpeningNotification> JavascriptDialogOpeningNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<JavascriptDialogOpeningNotification> result(new JavascriptDialogOpeningNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* messageValue = object->get("message");
            errors->setName("message");
            result->m_message = ValueConversions<String>::fromValue(messageValue, errors);
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> JavascriptDialogOpeningNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("message", ValueConversions<String>::toValue(m_message));
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            return result;
        }

        std::unique_ptr<JavascriptDialogOpeningNotification> JavascriptDialogOpeningNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<JavascriptDialogClosedNotification> JavascriptDialogClosedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<JavascriptDialogClosedNotification> result(new JavascriptDialogClosedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* resultValue = object->get("result");
            errors->setName("result");
            result->m_result = ValueConversions<bool>::fromValue(resultValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> JavascriptDialogClosedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("result", ValueConversions<bool>::toValue(m_result));
            return result;
        }

        std::unique_ptr<JavascriptDialogClosedNotification> JavascriptDialogClosedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ScreencastFrameNotification> ScreencastFrameNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ScreencastFrameNotification> result(new ScreencastFrameNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* dataValue = object->get("data");
            errors->setName("data");
            result->m_data = ValueConversions<String>::fromValue(dataValue, errors);
            protocol::Value* metadataValue = object->get("metadata");
            errors->setName("metadata");
            result->m_metadata = ValueConversions<protocol::Page::ScreencastFrameMetadata>::fromValue(metadataValue, errors);
            protocol::Value* sessionIdValue = object->get("sessionId");
            errors->setName("sessionId");
            result->m_sessionId = ValueConversions<int>::fromValue(sessionIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ScreencastFrameNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("data", ValueConversions<String>::toValue(m_data));
            result->setValue("metadata", ValueConversions<protocol::Page::ScreencastFrameMetadata>::toValue(m_metadata.get()));
            result->setValue("sessionId", ValueConversions<int>::toValue(m_sessionId));
            return result;
        }

        std::unique_ptr<ScreencastFrameNotification> ScreencastFrameNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ScreencastVisibilityChangedNotification> ScreencastVisibilityChangedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ScreencastVisibilityChangedNotification> result(new ScreencastVisibilityChangedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* visibleValue = object->get("visible");
            errors->setName("visible");
            result->m_visible = ValueConversions<bool>::fromValue(visibleValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ScreencastVisibilityChangedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("visible", ValueConversions<bool>::toValue(m_visible));
            return result;
        }

        std::unique_ptr<ScreencastVisibilityChangedNotification> ScreencastVisibilityChangedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ColorPickedNotification> ColorPickedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ColorPickedNotification> result(new ColorPickedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* colorValue = object->get("color");
            errors->setName("color");
            result->m_color = ValueConversions<protocol::DOM::RGBA>::fromValue(colorValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ColorPickedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("color", ValueConversions<protocol::DOM::RGBA>::toValue(m_color.get()));
            return result;
        }

        std::unique_ptr<ColorPickedNotification> ColorPickedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<NavigationRequestedNotification> NavigationRequestedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<NavigationRequestedNotification> result(new NavigationRequestedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* isInMainFrameValue = object->get("isInMainFrame");
            errors->setName("isInMainFrame");
            result->m_isInMainFrame = ValueConversions<bool>::fromValue(isInMainFrameValue, errors);
            protocol::Value* isRedirectValue = object->get("isRedirect");
            errors->setName("isRedirect");
            result->m_isRedirect = ValueConversions<bool>::fromValue(isRedirectValue, errors);
            protocol::Value* navigationIdValue = object->get("navigationId");
            errors->setName("navigationId");
            result->m_navigationId = ValueConversions<int>::fromValue(navigationIdValue, errors);
            protocol::Value* urlValue = object->get("url");
            errors->setName("url");
            result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> NavigationRequestedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("isInMainFrame", ValueConversions<bool>::toValue(m_isInMainFrame));
            result->setValue("isRedirect", ValueConversions<bool>::toValue(m_isRedirect));
            result->setValue("navigationId", ValueConversions<int>::toValue(m_navigationId));
            result->setValue("url", ValueConversions<String>::toValue(m_url));
            return result;
        }

        std::unique_ptr<NavigationRequestedNotification> NavigationRequestedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        namespace SetTouchEmulationEnabled {
            namespace ConfigurationEnum {
                const char* Mobile = "mobile";
                const char* Desktop = "desktop";
            } // namespace ConfigurationEnum
        } // namespace SetTouchEmulationEnabled

        namespace StartScreencast {
            namespace FormatEnum {
                const char* Jpeg = "jpeg";
                const char* Png = "png";
            } // namespace FormatEnum
        } // namespace StartScreencast

        // ------------- Frontend notifications.

        void Frontend::domContentEventFired(double timestamp)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DomContentEventFiredNotification> messageData = DomContentEventFiredNotification::create()
                                                                                .setTimestamp(timestamp)
                                                                                .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.domContentEventFired", std::move(messageData)));
        }

        void Frontend::loadEventFired(double timestamp)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<LoadEventFiredNotification> messageData = LoadEventFiredNotification::create()
                                                                          .setTimestamp(timestamp)
                                                                          .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.loadEventFired", std::move(messageData)));
        }

        void Frontend::frameAttached(const String& frameId, const String& parentFrameId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<FrameAttachedNotification> messageData = FrameAttachedNotification::create()
                                                                         .setFrameId(frameId)
                                                                         .setParentFrameId(parentFrameId)
                                                                         .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.frameAttached", std::move(messageData)));
        }

        void Frontend::frameNavigated(std::unique_ptr<protocol::Page::Frame> frame)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<FrameNavigatedNotification> messageData = FrameNavigatedNotification::create()
                                                                          .setFrame(std::move(frame))
                                                                          .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.frameNavigated", std::move(messageData)));
        }

        void Frontend::frameDetached(const String& frameId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<FrameDetachedNotification> messageData = FrameDetachedNotification::create()
                                                                         .setFrameId(frameId)
                                                                         .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.frameDetached", std::move(messageData)));
        }

        void Frontend::frameStartedLoading(const String& frameId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<FrameStartedLoadingNotification> messageData = FrameStartedLoadingNotification::create()
                                                                               .setFrameId(frameId)
                                                                               .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.frameStartedLoading", std::move(messageData)));
        }

        void Frontend::frameStoppedLoading(const String& frameId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<FrameStoppedLoadingNotification> messageData = FrameStoppedLoadingNotification::create()
                                                                               .setFrameId(frameId)
                                                                               .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.frameStoppedLoading", std::move(messageData)));
        }

        void Frontend::frameScheduledNavigation(const String& frameId, double delay)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<FrameScheduledNavigationNotification> messageData = FrameScheduledNavigationNotification::create()
                                                                                    .setFrameId(frameId)
                                                                                    .setDelay(delay)
                                                                                    .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.frameScheduledNavigation", std::move(messageData)));
        }

        void Frontend::frameClearedScheduledNavigation(const String& frameId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<FrameClearedScheduledNavigationNotification> messageData = FrameClearedScheduledNavigationNotification::create()
                                                                                           .setFrameId(frameId)
                                                                                           .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.frameClearedScheduledNavigation", std::move(messageData)));
        }

        void Frontend::frameResized()
        {
            if (!m_frontendChannel)
                return;
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.frameResized"));
        }

        void Frontend::javascriptDialogOpening(const String& message, const String& type)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<JavascriptDialogOpeningNotification> messageData = JavascriptDialogOpeningNotification::create()
                                                                                   .setMessage(message)
                                                                                   .setType(type)
                                                                                   .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.javascriptDialogOpening", std::move(messageData)));
        }

        void Frontend::javascriptDialogClosed(bool result)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<JavascriptDialogClosedNotification> messageData = JavascriptDialogClosedNotification::create()
                                                                                  .setResult(result)
                                                                                  .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Page.javascriptDialogClosed", std::move(messageData)));
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
                m_dispatchMap["Page.enable"] = &DispatcherImpl::enable;
                m_dispatchMap["Page.disable"] = &DispatcherImpl::disable;
                m_dispatchMap["Page.addScriptToEvaluateOnLoad"] = &DispatcherImpl::addScriptToEvaluateOnLoad;
                m_dispatchMap["Page.removeScriptToEvaluateOnLoad"] = &DispatcherImpl::removeScriptToEvaluateOnLoad;
                m_dispatchMap["Page.setAutoAttachToCreatedPages"] = &DispatcherImpl::setAutoAttachToCreatedPages;
                m_dispatchMap["Page.reload"] = &DispatcherImpl::reload;
                m_dispatchMap["Page.navigate"] = &DispatcherImpl::navigate;
                m_dispatchMap["Page.stopLoading"] = &DispatcherImpl::stopLoading;
                m_redirects["Page.getCookies"] = "Network.getCookies";
                m_redirects["Page.deleteCookie"] = "Network.deleteCookie";
                m_dispatchMap["Page.getResourceTree"] = &DispatcherImpl::getResourceTree;
                m_dispatchMap["Page.getResourceContent"] = &DispatcherImpl::getResourceContent;
                m_dispatchMap["Page.searchInResource"] = &DispatcherImpl::searchInResource;
                m_dispatchMap["Page.setDocumentContent"] = &DispatcherImpl::setDocumentContent;
                m_redirects["Page.setDeviceMetricsOverride"] = "Emulation.setDeviceMetricsOverride";
                m_redirects["Page.clearDeviceMetricsOverride"] = "Emulation.clearDeviceMetricsOverride";
                m_redirects["Page.setGeolocationOverride"] = "Emulation.setGeolocationOverride";
                m_redirects["Page.clearGeolocationOverride"] = "Emulation.clearGeolocationOverride";
                m_redirects["Page.setDeviceOrientationOverride"] = "DeviceOrientation.setDeviceOrientationOverride";
                m_redirects["Page.clearDeviceOrientationOverride"] = "DeviceOrientation.clearDeviceOrientationOverride";
                m_redirects["Page.setTouchEmulationEnabled"] = "Emulation.setTouchEmulationEnabled";
                m_dispatchMap["Page.startScreencast"] = &DispatcherImpl::startScreencast;
                m_dispatchMap["Page.stopScreencast"] = &DispatcherImpl::stopScreencast;
                m_dispatchMap["Page.configureOverlay"] = &DispatcherImpl::configureOverlay;
                m_dispatchMap["Page.getLayoutMetrics"] = &DispatcherImpl::getLayoutMetrics;
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
            DispatchResponse::Status addScriptToEvaluateOnLoad(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status removeScriptToEvaluateOnLoad(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setAutoAttachToCreatedPages(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status reload(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status navigate(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status stopLoading(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getResourceTree(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getResourceContent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status searchInResource(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setDocumentContent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status startScreencast(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status stopScreencast(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status configureOverlay(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getLayoutMetrics(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::addScriptToEvaluateOnLoad(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* scriptSourceValue = object ? object->get("scriptSource") : nullptr;
            errors->setName("scriptSource");
            String in_scriptSource = ValueConversions<String>::fromValue(scriptSourceValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            String out_identifier;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->addScriptToEvaluateOnLoad(in_scriptSource, &out_identifier);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("identifier", ValueConversions<String>::toValue(out_identifier));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::removeScriptToEvaluateOnLoad(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* identifierValue = object ? object->get("identifier") : nullptr;
            errors->setName("identifier");
            String in_identifier = ValueConversions<String>::fromValue(identifierValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->removeScriptToEvaluateOnLoad(in_identifier);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setAutoAttachToCreatedPages(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* autoAttachValue = object ? object->get("autoAttach") : nullptr;
            errors->setName("autoAttach");
            bool in_autoAttach = ValueConversions<bool>::fromValue(autoAttachValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setAutoAttachToCreatedPages(in_autoAttach);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::reload(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* ignoreCacheValue = object ? object->get("ignoreCache") : nullptr;
            Maybe<bool> in_ignoreCache;
            if (ignoreCacheValue) {
                errors->setName("ignoreCache");
                in_ignoreCache = ValueConversions<bool>::fromValue(ignoreCacheValue, errors);
            }
            protocol::Value* scriptToEvaluateOnLoadValue = object ? object->get("scriptToEvaluateOnLoad") : nullptr;
            Maybe<String> in_scriptToEvaluateOnLoad;
            if (scriptToEvaluateOnLoadValue) {
                errors->setName("scriptToEvaluateOnLoad");
                in_scriptToEvaluateOnLoad = ValueConversions<String>::fromValue(scriptToEvaluateOnLoadValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->reload(std::move(in_ignoreCache), std::move(in_scriptToEvaluateOnLoad));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::navigate(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            String out_frameId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->navigate(in_url, &out_frameId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("frameId", ValueConversions<String>::toValue(out_frameId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::stopLoading(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->stopLoading();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getResourceTree(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Declare output parameters.
            std::unique_ptr<protocol::Page::FrameResourceTree> out_frameTree;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getResourceTree(&out_frameTree);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("frameTree", ValueConversions<protocol::Page::FrameResourceTree>::toValue(out_frameTree.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        class GetResourceContentCallbackImpl : public Backend::GetResourceContentCallback, public DispatcherBase::Callback {
        public:
            GetResourceContentCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(const String& content, bool base64Encoded) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                resultObject->setValue("content", ValueConversions<String>::toValue(content));
                resultObject->setValue("base64Encoded", ValueConversions<bool>::toValue(base64Encoded));
                sendIfActive(std::move(resultObject), DispatchResponse::OK());
            }

            void fallThrough() override
            {
                fallThroughIfActive();
            }

            void sendFailure(const DispatchResponse& response) override
            {
                DCHECK(response.status() == DispatchResponse::kError);
                sendIfActive(nullptr, response);
            }
        };

        DispatchResponse::Status DispatcherImpl::getResourceContent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* frameIdValue = object ? object->get("frameId") : nullptr;
            errors->setName("frameId");
            String in_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<GetResourceContentCallbackImpl> callback(new GetResourceContentCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->getResourceContent(in_frameId, in_url, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class SearchInResourceCallbackImpl : public Backend::SearchInResourceCallback, public DispatcherBase::Callback {
        public:
            SearchInResourceCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(std::unique_ptr<protocol::Array<v8_inspector::protocol::Debugger::API::SearchMatch>> result) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                resultObject->setValue("result", ValueConversions<protocol::Array<v8_inspector::protocol::Debugger::API::SearchMatch>>::toValue(result.get()));
                sendIfActive(std::move(resultObject), DispatchResponse::OK());
            }

            void fallThrough() override
            {
                fallThroughIfActive();
            }

            void sendFailure(const DispatchResponse& response) override
            {
                DCHECK(response.status() == DispatchResponse::kError);
                sendIfActive(nullptr, response);
            }
        };

        DispatchResponse::Status DispatcherImpl::searchInResource(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* frameIdValue = object ? object->get("frameId") : nullptr;
            errors->setName("frameId");
            String in_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* queryValue = object ? object->get("query") : nullptr;
            errors->setName("query");
            String in_query = ValueConversions<String>::fromValue(queryValue, errors);
            protocol::Value* caseSensitiveValue = object ? object->get("caseSensitive") : nullptr;
            Maybe<bool> in_caseSensitive;
            if (caseSensitiveValue) {
                errors->setName("caseSensitive");
                in_caseSensitive = ValueConversions<bool>::fromValue(caseSensitiveValue, errors);
            }
            protocol::Value* isRegexValue = object ? object->get("isRegex") : nullptr;
            Maybe<bool> in_isRegex;
            if (isRegexValue) {
                errors->setName("isRegex");
                in_isRegex = ValueConversions<bool>::fromValue(isRegexValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<SearchInResourceCallbackImpl> callback(new SearchInResourceCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->searchInResource(in_frameId, in_url, in_query, std::move(in_caseSensitive), std::move(in_isRegex), std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        DispatchResponse::Status DispatcherImpl::setDocumentContent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* frameIdValue = object ? object->get("frameId") : nullptr;
            errors->setName("frameId");
            String in_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            protocol::Value* htmlValue = object ? object->get("html") : nullptr;
            errors->setName("html");
            String in_html = ValueConversions<String>::fromValue(htmlValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setDocumentContent(in_frameId, in_html);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::startScreencast(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* formatValue = object ? object->get("format") : nullptr;
            Maybe<String> in_format;
            if (formatValue) {
                errors->setName("format");
                in_format = ValueConversions<String>::fromValue(formatValue, errors);
            }
            protocol::Value* qualityValue = object ? object->get("quality") : nullptr;
            Maybe<int> in_quality;
            if (qualityValue) {
                errors->setName("quality");
                in_quality = ValueConversions<int>::fromValue(qualityValue, errors);
            }
            protocol::Value* maxWidthValue = object ? object->get("maxWidth") : nullptr;
            Maybe<int> in_maxWidth;
            if (maxWidthValue) {
                errors->setName("maxWidth");
                in_maxWidth = ValueConversions<int>::fromValue(maxWidthValue, errors);
            }
            protocol::Value* maxHeightValue = object ? object->get("maxHeight") : nullptr;
            Maybe<int> in_maxHeight;
            if (maxHeightValue) {
                errors->setName("maxHeight");
                in_maxHeight = ValueConversions<int>::fromValue(maxHeightValue, errors);
            }
            protocol::Value* everyNthFrameValue = object ? object->get("everyNthFrame") : nullptr;
            Maybe<int> in_everyNthFrame;
            if (everyNthFrameValue) {
                errors->setName("everyNthFrame");
                in_everyNthFrame = ValueConversions<int>::fromValue(everyNthFrameValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->startScreencast(std::move(in_format), std::move(in_quality), std::move(in_maxWidth), std::move(in_maxHeight), std::move(in_everyNthFrame));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::stopScreencast(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->stopScreencast();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::configureOverlay(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* suspendedValue = object ? object->get("suspended") : nullptr;
            Maybe<bool> in_suspended;
            if (suspendedValue) {
                errors->setName("suspended");
                in_suspended = ValueConversions<bool>::fromValue(suspendedValue, errors);
            }
            protocol::Value* messageValue = object ? object->get("message") : nullptr;
            Maybe<String> in_message;
            if (messageValue) {
                errors->setName("message");
                in_message = ValueConversions<String>::fromValue(messageValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->configureOverlay(std::move(in_suspended), std::move(in_message));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getLayoutMetrics(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Declare output parameters.
            std::unique_ptr<protocol::Page::LayoutViewport> out_layoutViewport;
            std::unique_ptr<protocol::Page::VisualViewport> out_visualViewport;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getLayoutMetrics(&out_layoutViewport, &out_visualViewport);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("layoutViewport", ValueConversions<protocol::Page::LayoutViewport>::toValue(out_layoutViewport.get()));
                result->setValue("visualViewport", ValueConversions<protocol::Page::VisualViewport>::toValue(out_visualViewport.get()));
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
            uber->registerBackend("Page", std::move(dispatcher));
        }

    } // Page
} // namespace blink
} // namespace protocol
