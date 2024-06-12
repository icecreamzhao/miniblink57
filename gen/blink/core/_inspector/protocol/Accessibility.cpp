// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/Accessibility.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace Accessibility {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Accessibility";
        const char Metainfo::commandPrefix[] = "Accessibility.";
        const char Metainfo::version[] = "1.2";

        namespace AXValueTypeEnum {
            const char* Boolean = "boolean";
            const char* Tristate = "tristate";
            const char* BooleanOrUndefined = "booleanOrUndefined";
            const char* Idref = "idref";
            const char* IdrefList = "idrefList";
            const char* Integer = "integer";
            const char* Node = "node";
            const char* NodeList = "nodeList";
            const char* Number = "number";
            const char* String = "string";
            const char* ComputedString = "computedString";
            const char* Token = "token";
            const char* TokenList = "tokenList";
            const char* DomRelation = "domRelation";
            const char* Role = "role";
            const char* InternalRole = "internalRole";
            const char* ValueUndefined = "valueUndefined";
        } // namespace AXValueTypeEnum

        namespace AXValueSourceTypeEnum {
            const char* Attribute = "attribute";
            const char* Implicit = "implicit";
            const char* Style = "style";
            const char* Contents = "contents";
            const char* Placeholder = "placeholder";
            const char* RelatedElement = "relatedElement";
        } // namespace AXValueSourceTypeEnum

        namespace AXValueNativeSourceTypeEnum {
            const char* Figcaption = "figcaption";
            const char* Label = "label";
            const char* Labelfor = "labelfor";
            const char* Labelwrapped = "labelwrapped";
            const char* Legend = "legend";
            const char* Tablecaption = "tablecaption";
            const char* Title = "title";
            const char* Other = "other";
        } // namespace AXValueNativeSourceTypeEnum

        std::unique_ptr<AXValueSource> AXValueSource::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AXValueSource> result(new AXValueSource());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* valueValue = object->get("value");
            if (valueValue) {
                errors->setName("value");
                result->m_value = ValueConversions<protocol::Accessibility::AXValue>::fromValue(valueValue, errors);
            }
            protocol::Value* attributeValue = object->get("attribute");
            if (attributeValue) {
                errors->setName("attribute");
                result->m_attribute = ValueConversions<String>::fromValue(attributeValue, errors);
            }
            protocol::Value* attributeValueValue = object->get("attributeValue");
            if (attributeValueValue) {
                errors->setName("attributeValue");
                result->m_attributeValue = ValueConversions<protocol::Accessibility::AXValue>::fromValue(attributeValueValue, errors);
            }
            protocol::Value* supersededValue = object->get("superseded");
            if (supersededValue) {
                errors->setName("superseded");
                result->m_superseded = ValueConversions<bool>::fromValue(supersededValue, errors);
            }
            protocol::Value* nativeSourceValue = object->get("nativeSource");
            if (nativeSourceValue) {
                errors->setName("nativeSource");
                result->m_nativeSource = ValueConversions<String>::fromValue(nativeSourceValue, errors);
            }
            protocol::Value* nativeSourceValueValue = object->get("nativeSourceValue");
            if (nativeSourceValueValue) {
                errors->setName("nativeSourceValue");
                result->m_nativeSourceValue = ValueConversions<protocol::Accessibility::AXValue>::fromValue(nativeSourceValueValue, errors);
            }
            protocol::Value* invalidValue = object->get("invalid");
            if (invalidValue) {
                errors->setName("invalid");
                result->m_invalid = ValueConversions<bool>::fromValue(invalidValue, errors);
            }
            protocol::Value* invalidReasonValue = object->get("invalidReason");
            if (invalidReasonValue) {
                errors->setName("invalidReason");
                result->m_invalidReason = ValueConversions<String>::fromValue(invalidReasonValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AXValueSource::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            if (m_value.isJust())
                result->setValue("value", ValueConversions<protocol::Accessibility::AXValue>::toValue(m_value.fromJust()));
            if (m_attribute.isJust())
                result->setValue("attribute", ValueConversions<String>::toValue(m_attribute.fromJust()));
            if (m_attributeValue.isJust())
                result->setValue("attributeValue", ValueConversions<protocol::Accessibility::AXValue>::toValue(m_attributeValue.fromJust()));
            if (m_superseded.isJust())
                result->setValue("superseded", ValueConversions<bool>::toValue(m_superseded.fromJust()));
            if (m_nativeSource.isJust())
                result->setValue("nativeSource", ValueConversions<String>::toValue(m_nativeSource.fromJust()));
            if (m_nativeSourceValue.isJust())
                result->setValue("nativeSourceValue", ValueConversions<protocol::Accessibility::AXValue>::toValue(m_nativeSourceValue.fromJust()));
            if (m_invalid.isJust())
                result->setValue("invalid", ValueConversions<bool>::toValue(m_invalid.fromJust()));
            if (m_invalidReason.isJust())
                result->setValue("invalidReason", ValueConversions<String>::toValue(m_invalidReason.fromJust()));
            return result;
        }

        std::unique_ptr<AXValueSource> AXValueSource::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<AXRelatedNode> AXRelatedNode::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AXRelatedNode> result(new AXRelatedNode());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* backendDOMNodeIdValue = object->get("backendDOMNodeId");
            errors->setName("backendDOMNodeId");
            result->m_backendDOMNodeId = ValueConversions<int>::fromValue(backendDOMNodeIdValue, errors);
            protocol::Value* idrefValue = object->get("idref");
            if (idrefValue) {
                errors->setName("idref");
                result->m_idref = ValueConversions<String>::fromValue(idrefValue, errors);
            }
            protocol::Value* textValue = object->get("text");
            if (textValue) {
                errors->setName("text");
                result->m_text = ValueConversions<String>::fromValue(textValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AXRelatedNode::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("backendDOMNodeId", ValueConversions<int>::toValue(m_backendDOMNodeId));
            if (m_idref.isJust())
                result->setValue("idref", ValueConversions<String>::toValue(m_idref.fromJust()));
            if (m_text.isJust())
                result->setValue("text", ValueConversions<String>::toValue(m_text.fromJust()));
            return result;
        }

        std::unique_ptr<AXRelatedNode> AXRelatedNode::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<AXProperty> AXProperty::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AXProperty> result(new AXProperty());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nameValue = object->get("name");
            errors->setName("name");
            result->m_name = ValueConversions<String>::fromValue(nameValue, errors);
            protocol::Value* valueValue = object->get("value");
            errors->setName("value");
            result->m_value = ValueConversions<protocol::Accessibility::AXValue>::fromValue(valueValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AXProperty::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("name", ValueConversions<String>::toValue(m_name));
            result->setValue("value", ValueConversions<protocol::Accessibility::AXValue>::toValue(m_value.get()));
            return result;
        }

        std::unique_ptr<AXProperty> AXProperty::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<AXValue> AXValue::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AXValue> result(new AXValue());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* valueValue = object->get("value");
            if (valueValue) {
                errors->setName("value");
                result->m_value = ValueConversions<protocol::Value>::fromValue(valueValue, errors);
            }
            protocol::Value* relatedNodesValue = object->get("relatedNodes");
            if (relatedNodesValue) {
                errors->setName("relatedNodes");
                result->m_relatedNodes = ValueConversions<protocol::Array<protocol::Accessibility::AXRelatedNode>>::fromValue(relatedNodesValue, errors);
            }
            protocol::Value* sourcesValue = object->get("sources");
            if (sourcesValue) {
                errors->setName("sources");
                result->m_sources = ValueConversions<protocol::Array<protocol::Accessibility::AXValueSource>>::fromValue(sourcesValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AXValue::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            if (m_value.isJust())
                result->setValue("value", ValueConversions<protocol::Value>::toValue(m_value.fromJust()));
            if (m_relatedNodes.isJust())
                result->setValue("relatedNodes", ValueConversions<protocol::Array<protocol::Accessibility::AXRelatedNode>>::toValue(m_relatedNodes.fromJust()));
            if (m_sources.isJust())
                result->setValue("sources", ValueConversions<protocol::Array<protocol::Accessibility::AXValueSource>>::toValue(m_sources.fromJust()));
            return result;
        }

        std::unique_ptr<AXValue> AXValue::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace AXGlobalStatesEnum {
            const char* Disabled = "disabled";
            const char* Hidden = "hidden";
            const char* HiddenRoot = "hiddenRoot";
            const char* Invalid = "invalid";
        } // namespace AXGlobalStatesEnum

        namespace AXLiveRegionAttributesEnum {
            const char* Live = "live";
            const char* Atomic = "atomic";
            const char* Relevant = "relevant";
            const char* Busy = "busy";
            const char* Root = "root";
        } // namespace AXLiveRegionAttributesEnum

        namespace AXWidgetAttributesEnum {
            const char* Autocomplete = "autocomplete";
            const char* Haspopup = "haspopup";
            const char* Level = "level";
            const char* Multiselectable = "multiselectable";
            const char* Orientation = "orientation";
            const char* Multiline = "multiline";
            const char* Readonly = "readonly";
            const char* Required = "required";
            const char* Valuemin = "valuemin";
            const char* Valuemax = "valuemax";
            const char* Valuetext = "valuetext";
        } // namespace AXWidgetAttributesEnum

        namespace AXWidgetStatesEnum {
            const char* Checked = "checked";
            const char* Expanded = "expanded";
            const char* Pressed = "pressed";
            const char* Selected = "selected";
        } // namespace AXWidgetStatesEnum

        namespace AXRelationshipAttributesEnum {
            const char* Activedescendant = "activedescendant";
            const char* Flowto = "flowto";
            const char* Controls = "controls";
            const char* Describedby = "describedby";
            const char* Labelledby = "labelledby";
            const char* Owns = "owns";
        } // namespace AXRelationshipAttributesEnum

        std::unique_ptr<AXNode> AXNode::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AXNode> result(new AXNode());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nodeIdValue = object->get("nodeId");
            errors->setName("nodeId");
            result->m_nodeId = ValueConversions<String>::fromValue(nodeIdValue, errors);
            protocol::Value* ignoredValue = object->get("ignored");
            errors->setName("ignored");
            result->m_ignored = ValueConversions<bool>::fromValue(ignoredValue, errors);
            protocol::Value* ignoredReasonsValue = object->get("ignoredReasons");
            if (ignoredReasonsValue) {
                errors->setName("ignoredReasons");
                result->m_ignoredReasons = ValueConversions<protocol::Array<protocol::Accessibility::AXProperty>>::fromValue(ignoredReasonsValue, errors);
            }
            protocol::Value* roleValue = object->get("role");
            if (roleValue) {
                errors->setName("role");
                result->m_role = ValueConversions<protocol::Accessibility::AXValue>::fromValue(roleValue, errors);
            }
            protocol::Value* nameValue = object->get("name");
            if (nameValue) {
                errors->setName("name");
                result->m_name = ValueConversions<protocol::Accessibility::AXValue>::fromValue(nameValue, errors);
            }
            protocol::Value* descriptionValue = object->get("description");
            if (descriptionValue) {
                errors->setName("description");
                result->m_description = ValueConversions<protocol::Accessibility::AXValue>::fromValue(descriptionValue, errors);
            }
            protocol::Value* valueValue = object->get("value");
            if (valueValue) {
                errors->setName("value");
                result->m_value = ValueConversions<protocol::Accessibility::AXValue>::fromValue(valueValue, errors);
            }
            protocol::Value* propertiesValue = object->get("properties");
            if (propertiesValue) {
                errors->setName("properties");
                result->m_properties = ValueConversions<protocol::Array<protocol::Accessibility::AXProperty>>::fromValue(propertiesValue, errors);
            }
            protocol::Value* childIdsValue = object->get("childIds");
            if (childIdsValue) {
                errors->setName("childIds");
                result->m_childIds = ValueConversions<protocol::Array<String>>::fromValue(childIdsValue, errors);
            }
            protocol::Value* backendDOMNodeIdValue = object->get("backendDOMNodeId");
            if (backendDOMNodeIdValue) {
                errors->setName("backendDOMNodeId");
                result->m_backendDOMNodeId = ValueConversions<int>::fromValue(backendDOMNodeIdValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AXNode::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("nodeId", ValueConversions<String>::toValue(m_nodeId));
            result->setValue("ignored", ValueConversions<bool>::toValue(m_ignored));
            if (m_ignoredReasons.isJust())
                result->setValue("ignoredReasons", ValueConversions<protocol::Array<protocol::Accessibility::AXProperty>>::toValue(m_ignoredReasons.fromJust()));
            if (m_role.isJust())
                result->setValue("role", ValueConversions<protocol::Accessibility::AXValue>::toValue(m_role.fromJust()));
            if (m_name.isJust())
                result->setValue("name", ValueConversions<protocol::Accessibility::AXValue>::toValue(m_name.fromJust()));
            if (m_description.isJust())
                result->setValue("description", ValueConversions<protocol::Accessibility::AXValue>::toValue(m_description.fromJust()));
            if (m_value.isJust())
                result->setValue("value", ValueConversions<protocol::Accessibility::AXValue>::toValue(m_value.fromJust()));
            if (m_properties.isJust())
                result->setValue("properties", ValueConversions<protocol::Array<protocol::Accessibility::AXProperty>>::toValue(m_properties.fromJust()));
            if (m_childIds.isJust())
                result->setValue("childIds", ValueConversions<protocol::Array<String>>::toValue(m_childIds.fromJust()));
            if (m_backendDOMNodeId.isJust())
                result->setValue("backendDOMNodeId", ValueConversions<int>::toValue(m_backendDOMNodeId.fromJust()));
            return result;
        }

        std::unique_ptr<AXNode> AXNode::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

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
                m_dispatchMap["Accessibility.getPartialAXTree"] = &DispatcherImpl::getPartialAXTree;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status getPartialAXTree(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::getPartialAXTree(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* fetchRelativesValue = object ? object->get("fetchRelatives") : nullptr;
            Maybe<bool> in_fetchRelatives;
            if (fetchRelativesValue) {
                errors->setName("fetchRelatives");
                in_fetchRelatives = ValueConversions<bool>::fromValue(fetchRelativesValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<protocol::Accessibility::AXNode>> out_nodes;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getPartialAXTree(in_nodeId, std::move(in_fetchRelatives), &out_nodes);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodes", ValueConversions<protocol::Array<protocol::Accessibility::AXNode>>::toValue(out_nodes.get()));
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
            uber->registerBackend("Accessibility", std::move(dispatcher));
        }

    } // Accessibility
} // namespace blink
} // namespace protocol
