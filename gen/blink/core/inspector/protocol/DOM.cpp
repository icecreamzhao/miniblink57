// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/DOM.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace DOM {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "DOM";
        const char Metainfo::commandPrefix[] = "DOM.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<BackendNode> BackendNode::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<BackendNode> result(new BackendNode());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nodeTypeValue = object->get("nodeType");
            errors->setName("nodeType");
            result->m_nodeType = ValueConversions<int>::fromValue(nodeTypeValue, errors);
            protocol::Value* nodeNameValue = object->get("nodeName");
            errors->setName("nodeName");
            result->m_nodeName = ValueConversions<String>::fromValue(nodeNameValue, errors);
            protocol::Value* backendNodeIdValue = object->get("backendNodeId");
            errors->setName("backendNodeId");
            result->m_backendNodeId = ValueConversions<int>::fromValue(backendNodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> BackendNode::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("nodeType", ValueConversions<int>::toValue(m_nodeType));
            result->setValue("nodeName", ValueConversions<String>::toValue(m_nodeName));
            result->setValue("backendNodeId", ValueConversions<int>::toValue(m_backendNodeId));
            return result;
        }

        std::unique_ptr<BackendNode> BackendNode::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace PseudoTypeEnum {
            const char* FirstLine = "first-line";
            const char* FirstLetter = "first-letter";
            const char* Before = "before";
            const char* After = "after";
            const char* Backdrop = "backdrop";
            const char* Selection = "selection";
            const char* FirstLineInherited = "first-line-inherited";
            const char* Scrollbar = "scrollbar";
            const char* ScrollbarThumb = "scrollbar-thumb";
            const char* ScrollbarButton = "scrollbar-button";
            const char* ScrollbarTrack = "scrollbar-track";
            const char* ScrollbarTrackPiece = "scrollbar-track-piece";
            const char* ScrollbarCorner = "scrollbar-corner";
            const char* Resizer = "resizer";
            const char* InputListButton = "input-list-button";
        } // namespace PseudoTypeEnum

        namespace ShadowRootTypeEnum {
            const char* UserAgent = "user-agent";
            const char* Open = "open";
            const char* Closed = "closed";
        } // namespace ShadowRootTypeEnum

        std::unique_ptr<Node> Node::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Node> result(new Node());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nodeIdValue = object->get("nodeId");
            errors->setName("nodeId");
            result->m_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* backendNodeIdValue = object->get("backendNodeId");
            errors->setName("backendNodeId");
            result->m_backendNodeId = ValueConversions<int>::fromValue(backendNodeIdValue, errors);
            protocol::Value* nodeTypeValue = object->get("nodeType");
            errors->setName("nodeType");
            result->m_nodeType = ValueConversions<int>::fromValue(nodeTypeValue, errors);
            protocol::Value* nodeNameValue = object->get("nodeName");
            errors->setName("nodeName");
            result->m_nodeName = ValueConversions<String>::fromValue(nodeNameValue, errors);
            protocol::Value* localNameValue = object->get("localName");
            errors->setName("localName");
            result->m_localName = ValueConversions<String>::fromValue(localNameValue, errors);
            protocol::Value* nodeValueValue = object->get("nodeValue");
            errors->setName("nodeValue");
            result->m_nodeValue = ValueConversions<String>::fromValue(nodeValueValue, errors);
            protocol::Value* childNodeCountValue = object->get("childNodeCount");
            if (childNodeCountValue) {
                errors->setName("childNodeCount");
                result->m_childNodeCount = ValueConversions<int>::fromValue(childNodeCountValue, errors);
            }
            protocol::Value* childrenValue = object->get("children");
            if (childrenValue) {
                errors->setName("children");
                result->m_children = ValueConversions<protocol::Array<protocol::DOM::Node>>::fromValue(childrenValue, errors);
            }
            protocol::Value* attributesValue = object->get("attributes");
            if (attributesValue) {
                errors->setName("attributes");
                result->m_attributes = ValueConversions<protocol::Array<String>>::fromValue(attributesValue, errors);
            }
            protocol::Value* documentURLValue = object->get("documentURL");
            if (documentURLValue) {
                errors->setName("documentURL");
                result->m_documentURL = ValueConversions<String>::fromValue(documentURLValue, errors);
            }
            protocol::Value* baseURLValue = object->get("baseURL");
            if (baseURLValue) {
                errors->setName("baseURL");
                result->m_baseURL = ValueConversions<String>::fromValue(baseURLValue, errors);
            }
            protocol::Value* publicIdValue = object->get("publicId");
            if (publicIdValue) {
                errors->setName("publicId");
                result->m_publicId = ValueConversions<String>::fromValue(publicIdValue, errors);
            }
            protocol::Value* systemIdValue = object->get("systemId");
            if (systemIdValue) {
                errors->setName("systemId");
                result->m_systemId = ValueConversions<String>::fromValue(systemIdValue, errors);
            }
            protocol::Value* internalSubsetValue = object->get("internalSubset");
            if (internalSubsetValue) {
                errors->setName("internalSubset");
                result->m_internalSubset = ValueConversions<String>::fromValue(internalSubsetValue, errors);
            }
            protocol::Value* xmlVersionValue = object->get("xmlVersion");
            if (xmlVersionValue) {
                errors->setName("xmlVersion");
                result->m_xmlVersion = ValueConversions<String>::fromValue(xmlVersionValue, errors);
            }
            protocol::Value* nameValue = object->get("name");
            if (nameValue) {
                errors->setName("name");
                result->m_name = ValueConversions<String>::fromValue(nameValue, errors);
            }
            protocol::Value* valueValue = object->get("value");
            if (valueValue) {
                errors->setName("value");
                result->m_value = ValueConversions<String>::fromValue(valueValue, errors);
            }
            protocol::Value* pseudoTypeValue = object->get("pseudoType");
            if (pseudoTypeValue) {
                errors->setName("pseudoType");
                result->m_pseudoType = ValueConversions<String>::fromValue(pseudoTypeValue, errors);
            }
            protocol::Value* shadowRootTypeValue = object->get("shadowRootType");
            if (shadowRootTypeValue) {
                errors->setName("shadowRootType");
                result->m_shadowRootType = ValueConversions<String>::fromValue(shadowRootTypeValue, errors);
            }
            protocol::Value* frameIdValue = object->get("frameId");
            if (frameIdValue) {
                errors->setName("frameId");
                result->m_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            }
            protocol::Value* contentDocumentValue = object->get("contentDocument");
            if (contentDocumentValue) {
                errors->setName("contentDocument");
                result->m_contentDocument = ValueConversions<protocol::DOM::Node>::fromValue(contentDocumentValue, errors);
            }
            protocol::Value* shadowRootsValue = object->get("shadowRoots");
            if (shadowRootsValue) {
                errors->setName("shadowRoots");
                result->m_shadowRoots = ValueConversions<protocol::Array<protocol::DOM::Node>>::fromValue(shadowRootsValue, errors);
            }
            protocol::Value* templateContentValue = object->get("templateContent");
            if (templateContentValue) {
                errors->setName("templateContent");
                result->m_templateContent = ValueConversions<protocol::DOM::Node>::fromValue(templateContentValue, errors);
            }
            protocol::Value* pseudoElementsValue = object->get("pseudoElements");
            if (pseudoElementsValue) {
                errors->setName("pseudoElements");
                result->m_pseudoElements = ValueConversions<protocol::Array<protocol::DOM::Node>>::fromValue(pseudoElementsValue, errors);
            }
            protocol::Value* importedDocumentValue = object->get("importedDocument");
            if (importedDocumentValue) {
                errors->setName("importedDocument");
                result->m_importedDocument = ValueConversions<protocol::DOM::Node>::fromValue(importedDocumentValue, errors);
            }
            protocol::Value* distributedNodesValue = object->get("distributedNodes");
            if (distributedNodesValue) {
                errors->setName("distributedNodes");
                result->m_distributedNodes = ValueConversions<protocol::Array<protocol::DOM::BackendNode>>::fromValue(distributedNodesValue, errors);
            }
            protocol::Value* isSVGValue = object->get("isSVG");
            if (isSVGValue) {
                errors->setName("isSVG");
                result->m_isSVG = ValueConversions<bool>::fromValue(isSVGValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Node::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("nodeId", ValueConversions<int>::toValue(m_nodeId));
            result->setValue("backendNodeId", ValueConversions<int>::toValue(m_backendNodeId));
            result->setValue("nodeType", ValueConversions<int>::toValue(m_nodeType));
            result->setValue("nodeName", ValueConversions<String>::toValue(m_nodeName));
            result->setValue("localName", ValueConversions<String>::toValue(m_localName));
            result->setValue("nodeValue", ValueConversions<String>::toValue(m_nodeValue));
            if (m_childNodeCount.isJust())
                result->setValue("childNodeCount", ValueConversions<int>::toValue(m_childNodeCount.fromJust()));
            if (m_children.isJust())
                result->setValue("children", ValueConversions<protocol::Array<protocol::DOM::Node>>::toValue(m_children.fromJust()));
            if (m_attributes.isJust())
                result->setValue("attributes", ValueConversions<protocol::Array<String>>::toValue(m_attributes.fromJust()));
            if (m_documentURL.isJust())
                result->setValue("documentURL", ValueConversions<String>::toValue(m_documentURL.fromJust()));
            if (m_baseURL.isJust())
                result->setValue("baseURL", ValueConversions<String>::toValue(m_baseURL.fromJust()));
            if (m_publicId.isJust())
                result->setValue("publicId", ValueConversions<String>::toValue(m_publicId.fromJust()));
            if (m_systemId.isJust())
                result->setValue("systemId", ValueConversions<String>::toValue(m_systemId.fromJust()));
            if (m_internalSubset.isJust())
                result->setValue("internalSubset", ValueConversions<String>::toValue(m_internalSubset.fromJust()));
            if (m_xmlVersion.isJust())
                result->setValue("xmlVersion", ValueConversions<String>::toValue(m_xmlVersion.fromJust()));
            if (m_name.isJust())
                result->setValue("name", ValueConversions<String>::toValue(m_name.fromJust()));
            if (m_value.isJust())
                result->setValue("value", ValueConversions<String>::toValue(m_value.fromJust()));
            if (m_pseudoType.isJust())
                result->setValue("pseudoType", ValueConversions<String>::toValue(m_pseudoType.fromJust()));
            if (m_shadowRootType.isJust())
                result->setValue("shadowRootType", ValueConversions<String>::toValue(m_shadowRootType.fromJust()));
            if (m_frameId.isJust())
                result->setValue("frameId", ValueConversions<String>::toValue(m_frameId.fromJust()));
            if (m_contentDocument.isJust())
                result->setValue("contentDocument", ValueConversions<protocol::DOM::Node>::toValue(m_contentDocument.fromJust()));
            if (m_shadowRoots.isJust())
                result->setValue("shadowRoots", ValueConversions<protocol::Array<protocol::DOM::Node>>::toValue(m_shadowRoots.fromJust()));
            if (m_templateContent.isJust())
                result->setValue("templateContent", ValueConversions<protocol::DOM::Node>::toValue(m_templateContent.fromJust()));
            if (m_pseudoElements.isJust())
                result->setValue("pseudoElements", ValueConversions<protocol::Array<protocol::DOM::Node>>::toValue(m_pseudoElements.fromJust()));
            if (m_importedDocument.isJust())
                result->setValue("importedDocument", ValueConversions<protocol::DOM::Node>::toValue(m_importedDocument.fromJust()));
            if (m_distributedNodes.isJust())
                result->setValue("distributedNodes", ValueConversions<protocol::Array<protocol::DOM::BackendNode>>::toValue(m_distributedNodes.fromJust()));
            if (m_isSVG.isJust())
                result->setValue("isSVG", ValueConversions<bool>::toValue(m_isSVG.fromJust()));
            return result;
        }

        std::unique_ptr<Node> Node::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<RGBA> RGBA::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<RGBA> result(new RGBA());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* rValue = object->get("r");
            errors->setName("r");
            result->m_r = ValueConversions<int>::fromValue(rValue, errors);
            protocol::Value* gValue = object->get("g");
            errors->setName("g");
            result->m_g = ValueConversions<int>::fromValue(gValue, errors);
            protocol::Value* bValue = object->get("b");
            errors->setName("b");
            result->m_b = ValueConversions<int>::fromValue(bValue, errors);
            protocol::Value* aValue = object->get("a");
            if (aValue) {
                errors->setName("a");
                result->m_a = ValueConversions<double>::fromValue(aValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> RGBA::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("r", ValueConversions<int>::toValue(m_r));
            result->setValue("g", ValueConversions<int>::toValue(m_g));
            result->setValue("b", ValueConversions<int>::toValue(m_b));
            if (m_a.isJust())
                result->setValue("a", ValueConversions<double>::toValue(m_a.fromJust()));
            return result;
        }

        std::unique_ptr<RGBA> RGBA::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<BoxModel> BoxModel::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<BoxModel> result(new BoxModel());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* contentValue = object->get("content");
            errors->setName("content");
            result->m_content = ValueConversions<protocol::Array<double>>::fromValue(contentValue, errors);
            protocol::Value* paddingValue = object->get("padding");
            errors->setName("padding");
            result->m_padding = ValueConversions<protocol::Array<double>>::fromValue(paddingValue, errors);
            protocol::Value* borderValue = object->get("border");
            errors->setName("border");
            result->m_border = ValueConversions<protocol::Array<double>>::fromValue(borderValue, errors);
            protocol::Value* marginValue = object->get("margin");
            errors->setName("margin");
            result->m_margin = ValueConversions<protocol::Array<double>>::fromValue(marginValue, errors);
            protocol::Value* widthValue = object->get("width");
            errors->setName("width");
            result->m_width = ValueConversions<int>::fromValue(widthValue, errors);
            protocol::Value* heightValue = object->get("height");
            errors->setName("height");
            result->m_height = ValueConversions<int>::fromValue(heightValue, errors);
            protocol::Value* shapeOutsideValue = object->get("shapeOutside");
            if (shapeOutsideValue) {
                errors->setName("shapeOutside");
                result->m_shapeOutside = ValueConversions<protocol::DOM::ShapeOutsideInfo>::fromValue(shapeOutsideValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> BoxModel::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("content", ValueConversions<protocol::Array<double>>::toValue(m_content.get()));
            result->setValue("padding", ValueConversions<protocol::Array<double>>::toValue(m_padding.get()));
            result->setValue("border", ValueConversions<protocol::Array<double>>::toValue(m_border.get()));
            result->setValue("margin", ValueConversions<protocol::Array<double>>::toValue(m_margin.get()));
            result->setValue("width", ValueConversions<int>::toValue(m_width));
            result->setValue("height", ValueConversions<int>::toValue(m_height));
            if (m_shapeOutside.isJust())
                result->setValue("shapeOutside", ValueConversions<protocol::DOM::ShapeOutsideInfo>::toValue(m_shapeOutside.fromJust()));
            return result;
        }

        std::unique_ptr<BoxModel> BoxModel::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ShapeOutsideInfo> ShapeOutsideInfo::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ShapeOutsideInfo> result(new ShapeOutsideInfo());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* boundsValue = object->get("bounds");
            errors->setName("bounds");
            result->m_bounds = ValueConversions<protocol::Array<double>>::fromValue(boundsValue, errors);
            protocol::Value* shapeValue = object->get("shape");
            errors->setName("shape");
            result->m_shape = ValueConversions<protocol::Array<protocol::Value>>::fromValue(shapeValue, errors);
            protocol::Value* marginShapeValue = object->get("marginShape");
            errors->setName("marginShape");
            result->m_marginShape = ValueConversions<protocol::Array<protocol::Value>>::fromValue(marginShapeValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ShapeOutsideInfo::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("bounds", ValueConversions<protocol::Array<double>>::toValue(m_bounds.get()));
            result->setValue("shape", ValueConversions<protocol::Array<protocol::Value>>::toValue(m_shape.get()));
            result->setValue("marginShape", ValueConversions<protocol::Array<protocol::Value>>::toValue(m_marginShape.get()));
            return result;
        }

        std::unique_ptr<ShapeOutsideInfo> ShapeOutsideInfo::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<Rect> Rect::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Rect> result(new Rect());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* xValue = object->get("x");
            errors->setName("x");
            result->m_x = ValueConversions<double>::fromValue(xValue, errors);
            protocol::Value* yValue = object->get("y");
            errors->setName("y");
            result->m_y = ValueConversions<double>::fromValue(yValue, errors);
            protocol::Value* widthValue = object->get("width");
            errors->setName("width");
            result->m_width = ValueConversions<double>::fromValue(widthValue, errors);
            protocol::Value* heightValue = object->get("height");
            errors->setName("height");
            result->m_height = ValueConversions<double>::fromValue(heightValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Rect::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("x", ValueConversions<double>::toValue(m_x));
            result->setValue("y", ValueConversions<double>::toValue(m_y));
            result->setValue("width", ValueConversions<double>::toValue(m_width));
            result->setValue("height", ValueConversions<double>::toValue(m_height));
            return result;
        }

        std::unique_ptr<Rect> Rect::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<HighlightConfig> HighlightConfig::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<HighlightConfig> result(new HighlightConfig());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* showInfoValue = object->get("showInfo");
            if (showInfoValue) {
                errors->setName("showInfo");
                result->m_showInfo = ValueConversions<bool>::fromValue(showInfoValue, errors);
            }
            protocol::Value* showRulersValue = object->get("showRulers");
            if (showRulersValue) {
                errors->setName("showRulers");
                result->m_showRulers = ValueConversions<bool>::fromValue(showRulersValue, errors);
            }
            protocol::Value* showExtensionLinesValue = object->get("showExtensionLines");
            if (showExtensionLinesValue) {
                errors->setName("showExtensionLines");
                result->m_showExtensionLines = ValueConversions<bool>::fromValue(showExtensionLinesValue, errors);
            }
            protocol::Value* displayAsMaterialValue = object->get("displayAsMaterial");
            if (displayAsMaterialValue) {
                errors->setName("displayAsMaterial");
                result->m_displayAsMaterial = ValueConversions<bool>::fromValue(displayAsMaterialValue, errors);
            }
            protocol::Value* contentColorValue = object->get("contentColor");
            if (contentColorValue) {
                errors->setName("contentColor");
                result->m_contentColor = ValueConversions<protocol::DOM::RGBA>::fromValue(contentColorValue, errors);
            }
            protocol::Value* paddingColorValue = object->get("paddingColor");
            if (paddingColorValue) {
                errors->setName("paddingColor");
                result->m_paddingColor = ValueConversions<protocol::DOM::RGBA>::fromValue(paddingColorValue, errors);
            }
            protocol::Value* borderColorValue = object->get("borderColor");
            if (borderColorValue) {
                errors->setName("borderColor");
                result->m_borderColor = ValueConversions<protocol::DOM::RGBA>::fromValue(borderColorValue, errors);
            }
            protocol::Value* marginColorValue = object->get("marginColor");
            if (marginColorValue) {
                errors->setName("marginColor");
                result->m_marginColor = ValueConversions<protocol::DOM::RGBA>::fromValue(marginColorValue, errors);
            }
            protocol::Value* eventTargetColorValue = object->get("eventTargetColor");
            if (eventTargetColorValue) {
                errors->setName("eventTargetColor");
                result->m_eventTargetColor = ValueConversions<protocol::DOM::RGBA>::fromValue(eventTargetColorValue, errors);
            }
            protocol::Value* shapeColorValue = object->get("shapeColor");
            if (shapeColorValue) {
                errors->setName("shapeColor");
                result->m_shapeColor = ValueConversions<protocol::DOM::RGBA>::fromValue(shapeColorValue, errors);
            }
            protocol::Value* shapeMarginColorValue = object->get("shapeMarginColor");
            if (shapeMarginColorValue) {
                errors->setName("shapeMarginColor");
                result->m_shapeMarginColor = ValueConversions<protocol::DOM::RGBA>::fromValue(shapeMarginColorValue, errors);
            }
            protocol::Value* selectorListValue = object->get("selectorList");
            if (selectorListValue) {
                errors->setName("selectorList");
                result->m_selectorList = ValueConversions<String>::fromValue(selectorListValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> HighlightConfig::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (m_showInfo.isJust())
                result->setValue("showInfo", ValueConversions<bool>::toValue(m_showInfo.fromJust()));
            if (m_showRulers.isJust())
                result->setValue("showRulers", ValueConversions<bool>::toValue(m_showRulers.fromJust()));
            if (m_showExtensionLines.isJust())
                result->setValue("showExtensionLines", ValueConversions<bool>::toValue(m_showExtensionLines.fromJust()));
            if (m_displayAsMaterial.isJust())
                result->setValue("displayAsMaterial", ValueConversions<bool>::toValue(m_displayAsMaterial.fromJust()));
            if (m_contentColor.isJust())
                result->setValue("contentColor", ValueConversions<protocol::DOM::RGBA>::toValue(m_contentColor.fromJust()));
            if (m_paddingColor.isJust())
                result->setValue("paddingColor", ValueConversions<protocol::DOM::RGBA>::toValue(m_paddingColor.fromJust()));
            if (m_borderColor.isJust())
                result->setValue("borderColor", ValueConversions<protocol::DOM::RGBA>::toValue(m_borderColor.fromJust()));
            if (m_marginColor.isJust())
                result->setValue("marginColor", ValueConversions<protocol::DOM::RGBA>::toValue(m_marginColor.fromJust()));
            if (m_eventTargetColor.isJust())
                result->setValue("eventTargetColor", ValueConversions<protocol::DOM::RGBA>::toValue(m_eventTargetColor.fromJust()));
            if (m_shapeColor.isJust())
                result->setValue("shapeColor", ValueConversions<protocol::DOM::RGBA>::toValue(m_shapeColor.fromJust()));
            if (m_shapeMarginColor.isJust())
                result->setValue("shapeMarginColor", ValueConversions<protocol::DOM::RGBA>::toValue(m_shapeMarginColor.fromJust()));
            if (m_selectorList.isJust())
                result->setValue("selectorList", ValueConversions<String>::toValue(m_selectorList.fromJust()));
            return result;
        }

        std::unique_ptr<HighlightConfig> HighlightConfig::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace InspectModeEnum {
            const char* SearchForNode = "searchForNode";
            const char* SearchForUAShadowDOM = "searchForUAShadowDOM";
            const char* None = "none";
        } // namespace InspectModeEnum

        std::unique_ptr<InspectNodeRequestedNotification> InspectNodeRequestedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<InspectNodeRequestedNotification> result(new InspectNodeRequestedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* backendNodeIdValue = object->get("backendNodeId");
            errors->setName("backendNodeId");
            result->m_backendNodeId = ValueConversions<int>::fromValue(backendNodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> InspectNodeRequestedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("backendNodeId", ValueConversions<int>::toValue(m_backendNodeId));
            return result;
        }

        std::unique_ptr<InspectNodeRequestedNotification> InspectNodeRequestedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<SetChildNodesNotification> SetChildNodesNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<SetChildNodesNotification> result(new SetChildNodesNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* parentIdValue = object->get("parentId");
            errors->setName("parentId");
            result->m_parentId = ValueConversions<int>::fromValue(parentIdValue, errors);
            protocol::Value* nodesValue = object->get("nodes");
            errors->setName("nodes");
            result->m_nodes = ValueConversions<protocol::Array<protocol::DOM::Node>>::fromValue(nodesValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> SetChildNodesNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("parentId", ValueConversions<int>::toValue(m_parentId));
            result->setValue("nodes", ValueConversions<protocol::Array<protocol::DOM::Node>>::toValue(m_nodes.get()));
            return result;
        }

        std::unique_ptr<SetChildNodesNotification> SetChildNodesNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<AttributeModifiedNotification> AttributeModifiedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AttributeModifiedNotification> result(new AttributeModifiedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nodeIdValue = object->get("nodeId");
            errors->setName("nodeId");
            result->m_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* nameValue = object->get("name");
            errors->setName("name");
            result->m_name = ValueConversions<String>::fromValue(nameValue, errors);
            protocol::Value* valueValue = object->get("value");
            errors->setName("value");
            result->m_value = ValueConversions<String>::fromValue(valueValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AttributeModifiedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("nodeId", ValueConversions<int>::toValue(m_nodeId));
            result->setValue("name", ValueConversions<String>::toValue(m_name));
            result->setValue("value", ValueConversions<String>::toValue(m_value));
            return result;
        }

        std::unique_ptr<AttributeModifiedNotification> AttributeModifiedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<AttributeRemovedNotification> AttributeRemovedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AttributeRemovedNotification> result(new AttributeRemovedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nodeIdValue = object->get("nodeId");
            errors->setName("nodeId");
            result->m_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* nameValue = object->get("name");
            errors->setName("name");
            result->m_name = ValueConversions<String>::fromValue(nameValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AttributeRemovedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("nodeId", ValueConversions<int>::toValue(m_nodeId));
            result->setValue("name", ValueConversions<String>::toValue(m_name));
            return result;
        }

        std::unique_ptr<AttributeRemovedNotification> AttributeRemovedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<InlineStyleInvalidatedNotification> InlineStyleInvalidatedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<InlineStyleInvalidatedNotification> result(new InlineStyleInvalidatedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nodeIdsValue = object->get("nodeIds");
            errors->setName("nodeIds");
            result->m_nodeIds = ValueConversions<protocol::Array<int>>::fromValue(nodeIdsValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> InlineStyleInvalidatedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("nodeIds", ValueConversions<protocol::Array<int>>::toValue(m_nodeIds.get()));
            return result;
        }

        std::unique_ptr<InlineStyleInvalidatedNotification> InlineStyleInvalidatedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<CharacterDataModifiedNotification> CharacterDataModifiedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<CharacterDataModifiedNotification> result(new CharacterDataModifiedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nodeIdValue = object->get("nodeId");
            errors->setName("nodeId");
            result->m_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* characterDataValue = object->get("characterData");
            errors->setName("characterData");
            result->m_characterData = ValueConversions<String>::fromValue(characterDataValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> CharacterDataModifiedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("nodeId", ValueConversions<int>::toValue(m_nodeId));
            result->setValue("characterData", ValueConversions<String>::toValue(m_characterData));
            return result;
        }

        std::unique_ptr<CharacterDataModifiedNotification> CharacterDataModifiedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ChildNodeCountUpdatedNotification> ChildNodeCountUpdatedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ChildNodeCountUpdatedNotification> result(new ChildNodeCountUpdatedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nodeIdValue = object->get("nodeId");
            errors->setName("nodeId");
            result->m_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* childNodeCountValue = object->get("childNodeCount");
            errors->setName("childNodeCount");
            result->m_childNodeCount = ValueConversions<int>::fromValue(childNodeCountValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ChildNodeCountUpdatedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("nodeId", ValueConversions<int>::toValue(m_nodeId));
            result->setValue("childNodeCount", ValueConversions<int>::toValue(m_childNodeCount));
            return result;
        }

        std::unique_ptr<ChildNodeCountUpdatedNotification> ChildNodeCountUpdatedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ChildNodeInsertedNotification> ChildNodeInsertedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ChildNodeInsertedNotification> result(new ChildNodeInsertedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* parentNodeIdValue = object->get("parentNodeId");
            errors->setName("parentNodeId");
            result->m_parentNodeId = ValueConversions<int>::fromValue(parentNodeIdValue, errors);
            protocol::Value* previousNodeIdValue = object->get("previousNodeId");
            errors->setName("previousNodeId");
            result->m_previousNodeId = ValueConversions<int>::fromValue(previousNodeIdValue, errors);
            protocol::Value* nodeValue = object->get("node");
            errors->setName("node");
            result->m_node = ValueConversions<protocol::DOM::Node>::fromValue(nodeValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ChildNodeInsertedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("parentNodeId", ValueConversions<int>::toValue(m_parentNodeId));
            result->setValue("previousNodeId", ValueConversions<int>::toValue(m_previousNodeId));
            result->setValue("node", ValueConversions<protocol::DOM::Node>::toValue(m_node.get()));
            return result;
        }

        std::unique_ptr<ChildNodeInsertedNotification> ChildNodeInsertedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ChildNodeRemovedNotification> ChildNodeRemovedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ChildNodeRemovedNotification> result(new ChildNodeRemovedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* parentNodeIdValue = object->get("parentNodeId");
            errors->setName("parentNodeId");
            result->m_parentNodeId = ValueConversions<int>::fromValue(parentNodeIdValue, errors);
            protocol::Value* nodeIdValue = object->get("nodeId");
            errors->setName("nodeId");
            result->m_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ChildNodeRemovedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("parentNodeId", ValueConversions<int>::toValue(m_parentNodeId));
            result->setValue("nodeId", ValueConversions<int>::toValue(m_nodeId));
            return result;
        }

        std::unique_ptr<ChildNodeRemovedNotification> ChildNodeRemovedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ShadowRootPushedNotification> ShadowRootPushedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ShadowRootPushedNotification> result(new ShadowRootPushedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* hostIdValue = object->get("hostId");
            errors->setName("hostId");
            result->m_hostId = ValueConversions<int>::fromValue(hostIdValue, errors);
            protocol::Value* rootValue = object->get("root");
            errors->setName("root");
            result->m_root = ValueConversions<protocol::DOM::Node>::fromValue(rootValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ShadowRootPushedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("hostId", ValueConversions<int>::toValue(m_hostId));
            result->setValue("root", ValueConversions<protocol::DOM::Node>::toValue(m_root.get()));
            return result;
        }

        std::unique_ptr<ShadowRootPushedNotification> ShadowRootPushedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ShadowRootPoppedNotification> ShadowRootPoppedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ShadowRootPoppedNotification> result(new ShadowRootPoppedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* hostIdValue = object->get("hostId");
            errors->setName("hostId");
            result->m_hostId = ValueConversions<int>::fromValue(hostIdValue, errors);
            protocol::Value* rootIdValue = object->get("rootId");
            errors->setName("rootId");
            result->m_rootId = ValueConversions<int>::fromValue(rootIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ShadowRootPoppedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("hostId", ValueConversions<int>::toValue(m_hostId));
            result->setValue("rootId", ValueConversions<int>::toValue(m_rootId));
            return result;
        }

        std::unique_ptr<ShadowRootPoppedNotification> ShadowRootPoppedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<PseudoElementAddedNotification> PseudoElementAddedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<PseudoElementAddedNotification> result(new PseudoElementAddedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* parentIdValue = object->get("parentId");
            errors->setName("parentId");
            result->m_parentId = ValueConversions<int>::fromValue(parentIdValue, errors);
            protocol::Value* pseudoElementValue = object->get("pseudoElement");
            errors->setName("pseudoElement");
            result->m_pseudoElement = ValueConversions<protocol::DOM::Node>::fromValue(pseudoElementValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> PseudoElementAddedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("parentId", ValueConversions<int>::toValue(m_parentId));
            result->setValue("pseudoElement", ValueConversions<protocol::DOM::Node>::toValue(m_pseudoElement.get()));
            return result;
        }

        std::unique_ptr<PseudoElementAddedNotification> PseudoElementAddedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<PseudoElementRemovedNotification> PseudoElementRemovedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<PseudoElementRemovedNotification> result(new PseudoElementRemovedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* parentIdValue = object->get("parentId");
            errors->setName("parentId");
            result->m_parentId = ValueConversions<int>::fromValue(parentIdValue, errors);
            protocol::Value* pseudoElementIdValue = object->get("pseudoElementId");
            errors->setName("pseudoElementId");
            result->m_pseudoElementId = ValueConversions<int>::fromValue(pseudoElementIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> PseudoElementRemovedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("parentId", ValueConversions<int>::toValue(m_parentId));
            result->setValue("pseudoElementId", ValueConversions<int>::toValue(m_pseudoElementId));
            return result;
        }

        std::unique_ptr<PseudoElementRemovedNotification> PseudoElementRemovedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<DistributedNodesUpdatedNotification> DistributedNodesUpdatedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DistributedNodesUpdatedNotification> result(new DistributedNodesUpdatedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* insertionPointIdValue = object->get("insertionPointId");
            errors->setName("insertionPointId");
            result->m_insertionPointId = ValueConversions<int>::fromValue(insertionPointIdValue, errors);
            protocol::Value* distributedNodesValue = object->get("distributedNodes");
            errors->setName("distributedNodes");
            result->m_distributedNodes = ValueConversions<protocol::Array<protocol::DOM::BackendNode>>::fromValue(distributedNodesValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DistributedNodesUpdatedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("insertionPointId", ValueConversions<int>::toValue(m_insertionPointId));
            result->setValue("distributedNodes", ValueConversions<protocol::Array<protocol::DOM::BackendNode>>::toValue(m_distributedNodes.get()));
            return result;
        }

        std::unique_ptr<DistributedNodesUpdatedNotification> DistributedNodesUpdatedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<NodeHighlightRequestedNotification> NodeHighlightRequestedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<NodeHighlightRequestedNotification> result(new NodeHighlightRequestedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nodeIdValue = object->get("nodeId");
            errors->setName("nodeId");
            result->m_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> NodeHighlightRequestedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("nodeId", ValueConversions<int>::toValue(m_nodeId));
            return result;
        }

        std::unique_ptr<NodeHighlightRequestedNotification> NodeHighlightRequestedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::documentUpdated()
        {
            if (!m_frontendChannel)
                return;
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.documentUpdated"));
        }

        void Frontend::inspectNodeRequested(int backendNodeId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<InspectNodeRequestedNotification> messageData = InspectNodeRequestedNotification::create()
                                                                                .setBackendNodeId(backendNodeId)
                                                                                .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.inspectNodeRequested", std::move(messageData)));
        }

        void Frontend::setChildNodes(int parentId, std::unique_ptr<protocol::Array<protocol::DOM::Node>> nodes)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<SetChildNodesNotification> messageData = SetChildNodesNotification::create()
                                                                         .setParentId(parentId)
                                                                         .setNodes(std::move(nodes))
                                                                         .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.setChildNodes", std::move(messageData)));
        }

        void Frontend::attributeModified(int nodeId, const String& name, const String& value)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<AttributeModifiedNotification> messageData = AttributeModifiedNotification::create()
                                                                             .setNodeId(nodeId)
                                                                             .setName(name)
                                                                             .setValue(value)
                                                                             .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.attributeModified", std::move(messageData)));
        }

        void Frontend::attributeRemoved(int nodeId, const String& name)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<AttributeRemovedNotification> messageData = AttributeRemovedNotification::create()
                                                                            .setNodeId(nodeId)
                                                                            .setName(name)
                                                                            .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.attributeRemoved", std::move(messageData)));
        }

        void Frontend::inlineStyleInvalidated(std::unique_ptr<protocol::Array<int>> nodeIds)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<InlineStyleInvalidatedNotification> messageData = InlineStyleInvalidatedNotification::create()
                                                                                  .setNodeIds(std::move(nodeIds))
                                                                                  .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.inlineStyleInvalidated", std::move(messageData)));
        }

        void Frontend::characterDataModified(int nodeId, const String& characterData)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<CharacterDataModifiedNotification> messageData = CharacterDataModifiedNotification::create()
                                                                                 .setNodeId(nodeId)
                                                                                 .setCharacterData(characterData)
                                                                                 .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.characterDataModified", std::move(messageData)));
        }

        void Frontend::childNodeCountUpdated(int nodeId, int childNodeCount)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<ChildNodeCountUpdatedNotification> messageData = ChildNodeCountUpdatedNotification::create()
                                                                                 .setNodeId(nodeId)
                                                                                 .setChildNodeCount(childNodeCount)
                                                                                 .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.childNodeCountUpdated", std::move(messageData)));
        }

        void Frontend::childNodeInserted(int parentNodeId, int previousNodeId, std::unique_ptr<protocol::DOM::Node> node)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<ChildNodeInsertedNotification> messageData = ChildNodeInsertedNotification::create()
                                                                             .setParentNodeId(parentNodeId)
                                                                             .setPreviousNodeId(previousNodeId)
                                                                             .setNode(std::move(node))
                                                                             .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.childNodeInserted", std::move(messageData)));
        }

        void Frontend::childNodeRemoved(int parentNodeId, int nodeId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<ChildNodeRemovedNotification> messageData = ChildNodeRemovedNotification::create()
                                                                            .setParentNodeId(parentNodeId)
                                                                            .setNodeId(nodeId)
                                                                            .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.childNodeRemoved", std::move(messageData)));
        }

        void Frontend::shadowRootPushed(int hostId, std::unique_ptr<protocol::DOM::Node> root)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<ShadowRootPushedNotification> messageData = ShadowRootPushedNotification::create()
                                                                            .setHostId(hostId)
                                                                            .setRoot(std::move(root))
                                                                            .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.shadowRootPushed", std::move(messageData)));
        }

        void Frontend::shadowRootPopped(int hostId, int rootId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<ShadowRootPoppedNotification> messageData = ShadowRootPoppedNotification::create()
                                                                            .setHostId(hostId)
                                                                            .setRootId(rootId)
                                                                            .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.shadowRootPopped", std::move(messageData)));
        }

        void Frontend::pseudoElementAdded(int parentId, std::unique_ptr<protocol::DOM::Node> pseudoElement)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<PseudoElementAddedNotification> messageData = PseudoElementAddedNotification::create()
                                                                              .setParentId(parentId)
                                                                              .setPseudoElement(std::move(pseudoElement))
                                                                              .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.pseudoElementAdded", std::move(messageData)));
        }

        void Frontend::pseudoElementRemoved(int parentId, int pseudoElementId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<PseudoElementRemovedNotification> messageData = PseudoElementRemovedNotification::create()
                                                                                .setParentId(parentId)
                                                                                .setPseudoElementId(pseudoElementId)
                                                                                .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.pseudoElementRemoved", std::move(messageData)));
        }

        void Frontend::distributedNodesUpdated(int insertionPointId, std::unique_ptr<protocol::Array<protocol::DOM::BackendNode>> distributedNodes)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DistributedNodesUpdatedNotification> messageData = DistributedNodesUpdatedNotification::create()
                                                                                   .setInsertionPointId(insertionPointId)
                                                                                   .setDistributedNodes(std::move(distributedNodes))
                                                                                   .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.distributedNodesUpdated", std::move(messageData)));
        }

        void Frontend::nodeHighlightRequested(int nodeId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<NodeHighlightRequestedNotification> messageData = NodeHighlightRequestedNotification::create()
                                                                                  .setNodeId(nodeId)
                                                                                  .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOM.nodeHighlightRequested", std::move(messageData)));
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
                m_dispatchMap["DOM.enable"] = &DispatcherImpl::enable;
                m_dispatchMap["DOM.disable"] = &DispatcherImpl::disable;
                m_dispatchMap["DOM.getDocument"] = &DispatcherImpl::getDocument;
                m_dispatchMap["DOM.collectClassNamesFromSubtree"] = &DispatcherImpl::collectClassNamesFromSubtree;
                m_dispatchMap["DOM.requestChildNodes"] = &DispatcherImpl::requestChildNodes;
                m_dispatchMap["DOM.querySelector"] = &DispatcherImpl::querySelector;
                m_dispatchMap["DOM.querySelectorAll"] = &DispatcherImpl::querySelectorAll;
                m_dispatchMap["DOM.setNodeName"] = &DispatcherImpl::setNodeName;
                m_dispatchMap["DOM.setNodeValue"] = &DispatcherImpl::setNodeValue;
                m_dispatchMap["DOM.removeNode"] = &DispatcherImpl::removeNode;
                m_dispatchMap["DOM.setAttributeValue"] = &DispatcherImpl::setAttributeValue;
                m_dispatchMap["DOM.setAttributesAsText"] = &DispatcherImpl::setAttributesAsText;
                m_dispatchMap["DOM.removeAttribute"] = &DispatcherImpl::removeAttribute;
                m_dispatchMap["DOM.getOuterHTML"] = &DispatcherImpl::getOuterHTML;
                m_dispatchMap["DOM.setOuterHTML"] = &DispatcherImpl::setOuterHTML;
                m_dispatchMap["DOM.performSearch"] = &DispatcherImpl::performSearch;
                m_dispatchMap["DOM.getSearchResults"] = &DispatcherImpl::getSearchResults;
                m_dispatchMap["DOM.discardSearchResults"] = &DispatcherImpl::discardSearchResults;
                m_dispatchMap["DOM.requestNode"] = &DispatcherImpl::requestNode;
                m_dispatchMap["DOM.setInspectMode"] = &DispatcherImpl::setInspectMode;
                m_dispatchMap["DOM.highlightRect"] = &DispatcherImpl::highlightRect;
                m_dispatchMap["DOM.highlightQuad"] = &DispatcherImpl::highlightQuad;
                m_dispatchMap["DOM.highlightNode"] = &DispatcherImpl::highlightNode;
                m_dispatchMap["DOM.hideHighlight"] = &DispatcherImpl::hideHighlight;
                m_dispatchMap["DOM.highlightFrame"] = &DispatcherImpl::highlightFrame;
                m_dispatchMap["DOM.pushNodeByPathToFrontend"] = &DispatcherImpl::pushNodeByPathToFrontend;
                m_dispatchMap["DOM.pushNodesByBackendIdsToFrontend"] = &DispatcherImpl::pushNodesByBackendIdsToFrontend;
                m_dispatchMap["DOM.setInspectedNode"] = &DispatcherImpl::setInspectedNode;
                m_dispatchMap["DOM.resolveNode"] = &DispatcherImpl::resolveNode;
                m_dispatchMap["DOM.getAttributes"] = &DispatcherImpl::getAttributes;
                m_dispatchMap["DOM.copyTo"] = &DispatcherImpl::copyTo;
                m_dispatchMap["DOM.moveTo"] = &DispatcherImpl::moveTo;
                m_dispatchMap["DOM.undo"] = &DispatcherImpl::undo;
                m_dispatchMap["DOM.redo"] = &DispatcherImpl::redo;
                m_dispatchMap["DOM.markUndoableState"] = &DispatcherImpl::markUndoableState;
                m_dispatchMap["DOM.focus"] = &DispatcherImpl::focus;
                m_dispatchMap["DOM.setFileInputFiles"] = &DispatcherImpl::setFileInputFiles;
                m_dispatchMap["DOM.getBoxModel"] = &DispatcherImpl::getBoxModel;
                m_dispatchMap["DOM.getNodeForLocation"] = &DispatcherImpl::getNodeForLocation;
                m_dispatchMap["DOM.getRelayoutBoundary"] = &DispatcherImpl::getRelayoutBoundary;
                m_dispatchMap["DOM.getHighlightObjectForTest"] = &DispatcherImpl::getHighlightObjectForTest;
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
            DispatchResponse::Status getDocument(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status collectClassNamesFromSubtree(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status requestChildNodes(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status querySelector(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status querySelectorAll(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setNodeName(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setNodeValue(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status removeNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setAttributeValue(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setAttributesAsText(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status removeAttribute(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getOuterHTML(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setOuterHTML(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status performSearch(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getSearchResults(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status discardSearchResults(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status requestNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setInspectMode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status highlightRect(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status highlightQuad(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status highlightNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status hideHighlight(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status highlightFrame(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status pushNodeByPathToFrontend(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status pushNodesByBackendIdsToFrontend(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setInspectedNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status resolveNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getAttributes(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status copyTo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status moveTo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status undo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status redo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status markUndoableState(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status focus(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setFileInputFiles(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getBoxModel(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getNodeForLocation(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getRelayoutBoundary(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getHighlightObjectForTest(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::getDocument(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* depthValue = object ? object->get("depth") : nullptr;
            Maybe<int> in_depth;
            if (depthValue) {
                errors->setName("depth");
                in_depth = ValueConversions<int>::fromValue(depthValue, errors);
            }
            protocol::Value* pierceValue = object ? object->get("pierce") : nullptr;
            Maybe<bool> in_pierce;
            if (pierceValue) {
                errors->setName("pierce");
                in_pierce = ValueConversions<bool>::fromValue(pierceValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::DOM::Node> out_root;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getDocument(std::move(in_depth), std::move(in_pierce), &out_root);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("root", ValueConversions<protocol::DOM::Node>::toValue(out_root.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::collectClassNamesFromSubtree(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<String>> out_classNames;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->collectClassNamesFromSubtree(in_nodeId, &out_classNames);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("classNames", ValueConversions<protocol::Array<String>>::toValue(out_classNames.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::requestChildNodes(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* depthValue = object ? object->get("depth") : nullptr;
            Maybe<int> in_depth;
            if (depthValue) {
                errors->setName("depth");
                in_depth = ValueConversions<int>::fromValue(depthValue, errors);
            }
            protocol::Value* pierceValue = object ? object->get("pierce") : nullptr;
            Maybe<bool> in_pierce;
            if (pierceValue) {
                errors->setName("pierce");
                in_pierce = ValueConversions<bool>::fromValue(pierceValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->requestChildNodes(in_nodeId, std::move(in_depth), std::move(in_pierce));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::querySelector(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* selectorValue = object ? object->get("selector") : nullptr;
            errors->setName("selector");
            String in_selector = ValueConversions<String>::fromValue(selectorValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            int out_nodeId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->querySelector(in_nodeId, in_selector, &out_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeId", ValueConversions<int>::toValue(out_nodeId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::querySelectorAll(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* selectorValue = object ? object->get("selector") : nullptr;
            errors->setName("selector");
            String in_selector = ValueConversions<String>::fromValue(selectorValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<int>> out_nodeIds;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->querySelectorAll(in_nodeId, in_selector, &out_nodeIds);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeIds", ValueConversions<protocol::Array<int>>::toValue(out_nodeIds.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setNodeName(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* nameValue = object ? object->get("name") : nullptr;
            errors->setName("name");
            String in_name = ValueConversions<String>::fromValue(nameValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            int out_nodeId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setNodeName(in_nodeId, in_name, &out_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeId", ValueConversions<int>::toValue(out_nodeId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setNodeValue(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* valueValue = object ? object->get("value") : nullptr;
            errors->setName("value");
            String in_value = ValueConversions<String>::fromValue(valueValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setNodeValue(in_nodeId, in_value);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::removeNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->removeNode(in_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setAttributeValue(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* nameValue = object ? object->get("name") : nullptr;
            errors->setName("name");
            String in_name = ValueConversions<String>::fromValue(nameValue, errors);
            protocol::Value* valueValue = object ? object->get("value") : nullptr;
            errors->setName("value");
            String in_value = ValueConversions<String>::fromValue(valueValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setAttributeValue(in_nodeId, in_name, in_value);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setAttributesAsText(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* textValue = object ? object->get("text") : nullptr;
            errors->setName("text");
            String in_text = ValueConversions<String>::fromValue(textValue, errors);
            protocol::Value* nameValue = object ? object->get("name") : nullptr;
            Maybe<String> in_name;
            if (nameValue) {
                errors->setName("name");
                in_name = ValueConversions<String>::fromValue(nameValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setAttributesAsText(in_nodeId, in_text, std::move(in_name));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::removeAttribute(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* nameValue = object ? object->get("name") : nullptr;
            errors->setName("name");
            String in_name = ValueConversions<String>::fromValue(nameValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->removeAttribute(in_nodeId, in_name);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getOuterHTML(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            String out_outerHTML;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getOuterHTML(in_nodeId, &out_outerHTML);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("outerHTML", ValueConversions<String>::toValue(out_outerHTML));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setOuterHTML(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* outerHTMLValue = object ? object->get("outerHTML") : nullptr;
            errors->setName("outerHTML");
            String in_outerHTML = ValueConversions<String>::fromValue(outerHTMLValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setOuterHTML(in_nodeId, in_outerHTML);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::performSearch(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* queryValue = object ? object->get("query") : nullptr;
            errors->setName("query");
            String in_query = ValueConversions<String>::fromValue(queryValue, errors);
            protocol::Value* includeUserAgentShadowDOMValue = object ? object->get("includeUserAgentShadowDOM") : nullptr;
            Maybe<bool> in_includeUserAgentShadowDOM;
            if (includeUserAgentShadowDOMValue) {
                errors->setName("includeUserAgentShadowDOM");
                in_includeUserAgentShadowDOM = ValueConversions<bool>::fromValue(includeUserAgentShadowDOMValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            String out_searchId;
            int out_resultCount;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->performSearch(in_query, std::move(in_includeUserAgentShadowDOM), &out_searchId, &out_resultCount);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("searchId", ValueConversions<String>::toValue(out_searchId));
                result->setValue("resultCount", ValueConversions<int>::toValue(out_resultCount));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getSearchResults(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* searchIdValue = object ? object->get("searchId") : nullptr;
            errors->setName("searchId");
            String in_searchId = ValueConversions<String>::fromValue(searchIdValue, errors);
            protocol::Value* fromIndexValue = object ? object->get("fromIndex") : nullptr;
            errors->setName("fromIndex");
            int in_fromIndex = ValueConversions<int>::fromValue(fromIndexValue, errors);
            protocol::Value* toIndexValue = object ? object->get("toIndex") : nullptr;
            errors->setName("toIndex");
            int in_toIndex = ValueConversions<int>::fromValue(toIndexValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<int>> out_nodeIds;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getSearchResults(in_searchId, in_fromIndex, in_toIndex, &out_nodeIds);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeIds", ValueConversions<protocol::Array<int>>::toValue(out_nodeIds.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::discardSearchResults(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* searchIdValue = object ? object->get("searchId") : nullptr;
            errors->setName("searchId");
            String in_searchId = ValueConversions<String>::fromValue(searchIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->discardSearchResults(in_searchId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::requestNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* objectIdValue = object ? object->get("objectId") : nullptr;
            errors->setName("objectId");
            String in_objectId = ValueConversions<String>::fromValue(objectIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            int out_nodeId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->requestNode(in_objectId, &out_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeId", ValueConversions<int>::toValue(out_nodeId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setInspectMode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* modeValue = object ? object->get("mode") : nullptr;
            errors->setName("mode");
            String in_mode = ValueConversions<String>::fromValue(modeValue, errors);
            protocol::Value* highlightConfigValue = object ? object->get("highlightConfig") : nullptr;
            Maybe<protocol::DOM::HighlightConfig> in_highlightConfig;
            if (highlightConfigValue) {
                errors->setName("highlightConfig");
                in_highlightConfig = ValueConversions<protocol::DOM::HighlightConfig>::fromValue(highlightConfigValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setInspectMode(in_mode, std::move(in_highlightConfig));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::highlightRect(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* xValue = object ? object->get("x") : nullptr;
            errors->setName("x");
            int in_x = ValueConversions<int>::fromValue(xValue, errors);
            protocol::Value* yValue = object ? object->get("y") : nullptr;
            errors->setName("y");
            int in_y = ValueConversions<int>::fromValue(yValue, errors);
            protocol::Value* widthValue = object ? object->get("width") : nullptr;
            errors->setName("width");
            int in_width = ValueConversions<int>::fromValue(widthValue, errors);
            protocol::Value* heightValue = object ? object->get("height") : nullptr;
            errors->setName("height");
            int in_height = ValueConversions<int>::fromValue(heightValue, errors);
            protocol::Value* colorValue = object ? object->get("color") : nullptr;
            Maybe<protocol::DOM::RGBA> in_color;
            if (colorValue) {
                errors->setName("color");
                in_color = ValueConversions<protocol::DOM::RGBA>::fromValue(colorValue, errors);
            }
            protocol::Value* outlineColorValue = object ? object->get("outlineColor") : nullptr;
            Maybe<protocol::DOM::RGBA> in_outlineColor;
            if (outlineColorValue) {
                errors->setName("outlineColor");
                in_outlineColor = ValueConversions<protocol::DOM::RGBA>::fromValue(outlineColorValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->highlightRect(in_x, in_y, in_width, in_height, std::move(in_color), std::move(in_outlineColor));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::highlightQuad(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* quadValue = object ? object->get("quad") : nullptr;
            errors->setName("quad");
            std::unique_ptr<protocol::Array<double>> in_quad = ValueConversions<protocol::Array<double>>::fromValue(quadValue, errors);
            protocol::Value* colorValue = object ? object->get("color") : nullptr;
            Maybe<protocol::DOM::RGBA> in_color;
            if (colorValue) {
                errors->setName("color");
                in_color = ValueConversions<protocol::DOM::RGBA>::fromValue(colorValue, errors);
            }
            protocol::Value* outlineColorValue = object ? object->get("outlineColor") : nullptr;
            Maybe<protocol::DOM::RGBA> in_outlineColor;
            if (outlineColorValue) {
                errors->setName("outlineColor");
                in_outlineColor = ValueConversions<protocol::DOM::RGBA>::fromValue(outlineColorValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->highlightQuad(std::move(in_quad), std::move(in_color), std::move(in_outlineColor));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::highlightNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* highlightConfigValue = object ? object->get("highlightConfig") : nullptr;
            errors->setName("highlightConfig");
            std::unique_ptr<protocol::DOM::HighlightConfig> in_highlightConfig = ValueConversions<protocol::DOM::HighlightConfig>::fromValue(highlightConfigValue, errors);
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            Maybe<int> in_nodeId;
            if (nodeIdValue) {
                errors->setName("nodeId");
                in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            }
            protocol::Value* backendNodeIdValue = object ? object->get("backendNodeId") : nullptr;
            Maybe<int> in_backendNodeId;
            if (backendNodeIdValue) {
                errors->setName("backendNodeId");
                in_backendNodeId = ValueConversions<int>::fromValue(backendNodeIdValue, errors);
            }
            protocol::Value* objectIdValue = object ? object->get("objectId") : nullptr;
            Maybe<String> in_objectId;
            if (objectIdValue) {
                errors->setName("objectId");
                in_objectId = ValueConversions<String>::fromValue(objectIdValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->highlightNode(std::move(in_highlightConfig), std::move(in_nodeId), std::move(in_backendNodeId), std::move(in_objectId));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::hideHighlight(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->hideHighlight();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::highlightFrame(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* frameIdValue = object ? object->get("frameId") : nullptr;
            errors->setName("frameId");
            String in_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            protocol::Value* contentColorValue = object ? object->get("contentColor") : nullptr;
            Maybe<protocol::DOM::RGBA> in_contentColor;
            if (contentColorValue) {
                errors->setName("contentColor");
                in_contentColor = ValueConversions<protocol::DOM::RGBA>::fromValue(contentColorValue, errors);
            }
            protocol::Value* contentOutlineColorValue = object ? object->get("contentOutlineColor") : nullptr;
            Maybe<protocol::DOM::RGBA> in_contentOutlineColor;
            if (contentOutlineColorValue) {
                errors->setName("contentOutlineColor");
                in_contentOutlineColor = ValueConversions<protocol::DOM::RGBA>::fromValue(contentOutlineColorValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->highlightFrame(in_frameId, std::move(in_contentColor), std::move(in_contentOutlineColor));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::pushNodeByPathToFrontend(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* pathValue = object ? object->get("path") : nullptr;
            errors->setName("path");
            String in_path = ValueConversions<String>::fromValue(pathValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            int out_nodeId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->pushNodeByPathToFrontend(in_path, &out_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeId", ValueConversions<int>::toValue(out_nodeId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::pushNodesByBackendIdsToFrontend(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* backendNodeIdsValue = object ? object->get("backendNodeIds") : nullptr;
            errors->setName("backendNodeIds");
            std::unique_ptr<protocol::Array<int>> in_backendNodeIds = ValueConversions<protocol::Array<int>>::fromValue(backendNodeIdsValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<int>> out_nodeIds;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->pushNodesByBackendIdsToFrontend(std::move(in_backendNodeIds), &out_nodeIds);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeIds", ValueConversions<protocol::Array<int>>::toValue(out_nodeIds.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setInspectedNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setInspectedNode(in_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::resolveNode(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* objectGroupValue = object ? object->get("objectGroup") : nullptr;
            Maybe<String> in_objectGroup;
            if (objectGroupValue) {
                errors->setName("objectGroup");
                in_objectGroup = ValueConversions<String>::fromValue(objectGroupValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> out_object;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->resolveNode(in_nodeId, std::move(in_objectGroup), &out_object);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("object", ValueConversions<v8_inspector::protocol::Runtime::API::RemoteObject>::toValue(out_object.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getAttributes(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<String>> out_attributes;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getAttributes(in_nodeId, &out_attributes);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("attributes", ValueConversions<protocol::Array<String>>::toValue(out_attributes.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::copyTo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* targetNodeIdValue = object ? object->get("targetNodeId") : nullptr;
            errors->setName("targetNodeId");
            int in_targetNodeId = ValueConversions<int>::fromValue(targetNodeIdValue, errors);
            protocol::Value* insertBeforeNodeIdValue = object ? object->get("insertBeforeNodeId") : nullptr;
            Maybe<int> in_insertBeforeNodeId;
            if (insertBeforeNodeIdValue) {
                errors->setName("insertBeforeNodeId");
                in_insertBeforeNodeId = ValueConversions<int>::fromValue(insertBeforeNodeIdValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            int out_nodeId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->copyTo(in_nodeId, in_targetNodeId, std::move(in_insertBeforeNodeId), &out_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeId", ValueConversions<int>::toValue(out_nodeId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::moveTo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* targetNodeIdValue = object ? object->get("targetNodeId") : nullptr;
            errors->setName("targetNodeId");
            int in_targetNodeId = ValueConversions<int>::fromValue(targetNodeIdValue, errors);
            protocol::Value* insertBeforeNodeIdValue = object ? object->get("insertBeforeNodeId") : nullptr;
            Maybe<int> in_insertBeforeNodeId;
            if (insertBeforeNodeIdValue) {
                errors->setName("insertBeforeNodeId");
                in_insertBeforeNodeId = ValueConversions<int>::fromValue(insertBeforeNodeIdValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            int out_nodeId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->moveTo(in_nodeId, in_targetNodeId, std::move(in_insertBeforeNodeId), &out_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeId", ValueConversions<int>::toValue(out_nodeId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::undo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->undo();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::redo(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->redo();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::markUndoableState(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->markUndoableState();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::focus(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->focus(in_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setFileInputFiles(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            protocol::Value* filesValue = object ? object->get("files") : nullptr;
            errors->setName("files");
            std::unique_ptr<protocol::Array<String>> in_files = ValueConversions<protocol::Array<String>>::fromValue(filesValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setFileInputFiles(in_nodeId, std::move(in_files));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getBoxModel(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::DOM::BoxModel> out_model;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getBoxModel(in_nodeId, &out_model);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("model", ValueConversions<protocol::DOM::BoxModel>::toValue(out_model.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getNodeForLocation(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* xValue = object ? object->get("x") : nullptr;
            errors->setName("x");
            int in_x = ValueConversions<int>::fromValue(xValue, errors);
            protocol::Value* yValue = object ? object->get("y") : nullptr;
            errors->setName("y");
            int in_y = ValueConversions<int>::fromValue(yValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            int out_nodeId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getNodeForLocation(in_x, in_y, &out_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeId", ValueConversions<int>::toValue(out_nodeId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getRelayoutBoundary(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            int out_nodeId;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getRelayoutBoundary(in_nodeId, &out_nodeId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("nodeId", ValueConversions<int>::toValue(out_nodeId));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getHighlightObjectForTest(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* nodeIdValue = object ? object->get("nodeId") : nullptr;
            errors->setName("nodeId");
            int in_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::DictionaryValue> out_highlight;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getHighlightObjectForTest(in_nodeId, &out_highlight);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("highlight", ValueConversions<protocol::DictionaryValue>::toValue(out_highlight.get()));
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
            uber->registerBackend("DOM", std::move(dispatcher));
        }

    } // DOM
} // namespace blink
} // namespace protocol
