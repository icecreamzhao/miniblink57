// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_DOM_h
#define blink_protocol_DOM_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "core/inspector/protocol/Runtime.h"

namespace blink {
namespace protocol {
    namespace DOM {

        // ------------- Forward and enum declarations.
        // Unique DOM node identifier.
        using NodeId = int;
        // Unique DOM node identifier used to reference a node that may not have been pushed to the front-end.
        using BackendNodeId = int;
        // Backend node with a friendly name.
        class BackendNode;
        // Pseudo element type.
        using PseudoType = String;
        // Shadow root type.
        using ShadowRootType = String;
        // DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes. DOMNode is a base node mirror type.
        class Node;
        // A structure holding an RGBA color.
        class RGBA;
        // Box model.
        class BoxModel;
        // CSS Shape Outside details.
        class ShapeOutsideInfo;
        // Rectangle.
        class Rect;
        // Configuration data for the highlighting of page elements.
        class HighlightConfig;
        //
        using InspectMode = String;
        // Wrapper for notification params
        using DocumentUpdatedNotification = Object;
        // Wrapper for notification params
        class InspectNodeRequestedNotification;
        // Wrapper for notification params
        class SetChildNodesNotification;
        // Wrapper for notification params
        class AttributeModifiedNotification;
        // Wrapper for notification params
        class AttributeRemovedNotification;
        // Wrapper for notification params
        class InlineStyleInvalidatedNotification;
        // Wrapper for notification params
        class CharacterDataModifiedNotification;
        // Wrapper for notification params
        class ChildNodeCountUpdatedNotification;
        // Wrapper for notification params
        class ChildNodeInsertedNotification;
        // Wrapper for notification params
        class ChildNodeRemovedNotification;
        // Wrapper for notification params
        class ShadowRootPushedNotification;
        // Wrapper for notification params
        class ShadowRootPoppedNotification;
        // Wrapper for notification params
        class PseudoElementAddedNotification;
        // Wrapper for notification params
        class PseudoElementRemovedNotification;
        // Wrapper for notification params
        class DistributedNodesUpdatedNotification;
        // Wrapper for notification params
        class NodeHighlightRequestedNotification;

        namespace PseudoTypeEnum {
            CORE_EXPORT extern const char* FirstLine;
            CORE_EXPORT extern const char* FirstLetter;
            CORE_EXPORT extern const char* Before;
            CORE_EXPORT extern const char* After;
            CORE_EXPORT extern const char* Backdrop;
            CORE_EXPORT extern const char* Selection;
            CORE_EXPORT extern const char* FirstLineInherited;
            CORE_EXPORT extern const char* Scrollbar;
            CORE_EXPORT extern const char* ScrollbarThumb;
            CORE_EXPORT extern const char* ScrollbarButton;
            CORE_EXPORT extern const char* ScrollbarTrack;
            CORE_EXPORT extern const char* ScrollbarTrackPiece;
            CORE_EXPORT extern const char* ScrollbarCorner;
            CORE_EXPORT extern const char* Resizer;
            CORE_EXPORT extern const char* InputListButton;
        } // namespace PseudoTypeEnum

        namespace ShadowRootTypeEnum {
            CORE_EXPORT extern const char* UserAgent;
            CORE_EXPORT extern const char* Open;
            CORE_EXPORT extern const char* Closed;
        } // namespace ShadowRootTypeEnum

        namespace InspectModeEnum {
            CORE_EXPORT extern const char* SearchForNode;
            CORE_EXPORT extern const char* SearchForUAShadowDOM;
            CORE_EXPORT extern const char* None;
        } // namespace InspectModeEnum

        // ------------- Type and builder declarations.

        // Backend node with a friendly name.
        class CORE_EXPORT BackendNode : public Serializable {
            PROTOCOL_DISALLOW_COPY(BackendNode);

        public:
            static std::unique_ptr<BackendNode> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~BackendNode() override { }

            int getNodeType() { return m_nodeType; }
            void setNodeType(int value) { m_nodeType = value; }

            String getNodeName() { return m_nodeName; }
            void setNodeName(const String& value) { m_nodeName = value; }

            int getBackendNodeId() { return m_backendNodeId; }
            void setBackendNodeId(int value) { m_backendNodeId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<BackendNode> clone() const;

            template <int STATE>
            class BackendNodeBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NodeTypeSet = 1 << 1,
                    NodeNameSet = 1 << 2,
                    BackendNodeIdSet = 1 << 3,
                    AllFieldsSet = (NodeTypeSet | NodeNameSet | BackendNodeIdSet | 0)
                };

                BackendNodeBuilder<STATE | NodeTypeSet>& setNodeType(int value)
                {
                    static_assert(!(STATE & NodeTypeSet), "property nodeType should not be set yet");
                    m_result->setNodeType(value);
                    return castState<NodeTypeSet>();
                }

                BackendNodeBuilder<STATE | NodeNameSet>& setNodeName(const String& value)
                {
                    static_assert(!(STATE & NodeNameSet), "property nodeName should not be set yet");
                    m_result->setNodeName(value);
                    return castState<NodeNameSet>();
                }

                BackendNodeBuilder<STATE | BackendNodeIdSet>& setBackendNodeId(int value)
                {
                    static_assert(!(STATE & BackendNodeIdSet), "property backendNodeId should not be set yet");
                    m_result->setBackendNodeId(value);
                    return castState<BackendNodeIdSet>();
                }

                std::unique_ptr<BackendNode> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class BackendNode;
                BackendNodeBuilder()
                    : m_result(new BackendNode())
                {
                }

                template <int STEP>
                BackendNodeBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<BackendNodeBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::BackendNode> m_result;
            };

            static BackendNodeBuilder<0> create()
            {
                return BackendNodeBuilder<0>();
            }

        private:
            BackendNode()
            {
                m_nodeType = 0;
                m_backendNodeId = 0;
            }

            int m_nodeType;
            String m_nodeName;
            int m_backendNodeId;
        };

        // DOM interaction is implemented in terms of mirror objects that represent the actual DOM nodes. DOMNode is a base node mirror type.
        class CORE_EXPORT Node : public Serializable {
            PROTOCOL_DISALLOW_COPY(Node);

        public:
            static std::unique_ptr<Node> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Node() override { }

            int getNodeId() { return m_nodeId; }
            void setNodeId(int value) { m_nodeId = value; }

            int getBackendNodeId() { return m_backendNodeId; }
            void setBackendNodeId(int value) { m_backendNodeId = value; }

            int getNodeType() { return m_nodeType; }
            void setNodeType(int value) { m_nodeType = value; }

            String getNodeName() { return m_nodeName; }
            void setNodeName(const String& value) { m_nodeName = value; }

            String getLocalName() { return m_localName; }
            void setLocalName(const String& value) { m_localName = value; }

            String getNodeValue() { return m_nodeValue; }
            void setNodeValue(const String& value) { m_nodeValue = value; }

            bool hasChildNodeCount() { return m_childNodeCount.isJust(); }
            int getChildNodeCount(int defaultValue) { return m_childNodeCount.isJust() ? m_childNodeCount.fromJust() : defaultValue; }
            void setChildNodeCount(int value) { m_childNodeCount = value; }

            bool hasChildren() { return m_children.isJust(); }
            protocol::Array<protocol::DOM::Node>* getChildren(protocol::Array<protocol::DOM::Node>* defaultValue) { return m_children.isJust() ? m_children.fromJust() : defaultValue; }
            void setChildren(std::unique_ptr<protocol::Array<protocol::DOM::Node>> value) { m_children = std::move(value); }

            bool hasAttributes() { return m_attributes.isJust(); }
            protocol::Array<String>* getAttributes(protocol::Array<String>* defaultValue) { return m_attributes.isJust() ? m_attributes.fromJust() : defaultValue; }
            void setAttributes(std::unique_ptr<protocol::Array<String>> value) { m_attributes = std::move(value); }

            bool hasDocumentURL() { return m_documentURL.isJust(); }
            String getDocumentURL(const String& defaultValue) { return m_documentURL.isJust() ? m_documentURL.fromJust() : defaultValue; }
            void setDocumentURL(const String& value) { m_documentURL = value; }

            bool hasBaseURL() { return m_baseURL.isJust(); }
            String getBaseURL(const String& defaultValue) { return m_baseURL.isJust() ? m_baseURL.fromJust() : defaultValue; }
            void setBaseURL(const String& value) { m_baseURL = value; }

            bool hasPublicId() { return m_publicId.isJust(); }
            String getPublicId(const String& defaultValue) { return m_publicId.isJust() ? m_publicId.fromJust() : defaultValue; }
            void setPublicId(const String& value) { m_publicId = value; }

            bool hasSystemId() { return m_systemId.isJust(); }
            String getSystemId(const String& defaultValue) { return m_systemId.isJust() ? m_systemId.fromJust() : defaultValue; }
            void setSystemId(const String& value) { m_systemId = value; }

            bool hasInternalSubset() { return m_internalSubset.isJust(); }
            String getInternalSubset(const String& defaultValue) { return m_internalSubset.isJust() ? m_internalSubset.fromJust() : defaultValue; }
            void setInternalSubset(const String& value) { m_internalSubset = value; }

            bool hasXmlVersion() { return m_xmlVersion.isJust(); }
            String getXmlVersion(const String& defaultValue) { return m_xmlVersion.isJust() ? m_xmlVersion.fromJust() : defaultValue; }
            void setXmlVersion(const String& value) { m_xmlVersion = value; }

            bool hasName() { return m_name.isJust(); }
            String getName(const String& defaultValue) { return m_name.isJust() ? m_name.fromJust() : defaultValue; }
            void setName(const String& value) { m_name = value; }

            bool hasValue() { return m_value.isJust(); }
            String getValue(const String& defaultValue) { return m_value.isJust() ? m_value.fromJust() : defaultValue; }
            void setValue(const String& value) { m_value = value; }

            bool hasPseudoType() { return m_pseudoType.isJust(); }
            String getPseudoType(const String& defaultValue) { return m_pseudoType.isJust() ? m_pseudoType.fromJust() : defaultValue; }
            void setPseudoType(const String& value) { m_pseudoType = value; }

            bool hasShadowRootType() { return m_shadowRootType.isJust(); }
            String getShadowRootType(const String& defaultValue) { return m_shadowRootType.isJust() ? m_shadowRootType.fromJust() : defaultValue; }
            void setShadowRootType(const String& value) { m_shadowRootType = value; }

            bool hasFrameId() { return m_frameId.isJust(); }
            String getFrameId(const String& defaultValue) { return m_frameId.isJust() ? m_frameId.fromJust() : defaultValue; }
            void setFrameId(const String& value) { m_frameId = value; }

            bool hasContentDocument() { return m_contentDocument.isJust(); }
            protocol::DOM::Node* getContentDocument(protocol::DOM::Node* defaultValue) { return m_contentDocument.isJust() ? m_contentDocument.fromJust() : defaultValue; }
            void setContentDocument(std::unique_ptr<protocol::DOM::Node> value) { m_contentDocument = std::move(value); }

            bool hasShadowRoots() { return m_shadowRoots.isJust(); }
            protocol::Array<protocol::DOM::Node>* getShadowRoots(protocol::Array<protocol::DOM::Node>* defaultValue) { return m_shadowRoots.isJust() ? m_shadowRoots.fromJust() : defaultValue; }
            void setShadowRoots(std::unique_ptr<protocol::Array<protocol::DOM::Node>> value) { m_shadowRoots = std::move(value); }

            bool hasTemplateContent() { return m_templateContent.isJust(); }
            protocol::DOM::Node* getTemplateContent(protocol::DOM::Node* defaultValue) { return m_templateContent.isJust() ? m_templateContent.fromJust() : defaultValue; }
            void setTemplateContent(std::unique_ptr<protocol::DOM::Node> value) { m_templateContent = std::move(value); }

            bool hasPseudoElements() { return m_pseudoElements.isJust(); }
            protocol::Array<protocol::DOM::Node>* getPseudoElements(protocol::Array<protocol::DOM::Node>* defaultValue) { return m_pseudoElements.isJust() ? m_pseudoElements.fromJust() : defaultValue; }
            void setPseudoElements(std::unique_ptr<protocol::Array<protocol::DOM::Node>> value) { m_pseudoElements = std::move(value); }

            bool hasImportedDocument() { return m_importedDocument.isJust(); }
            protocol::DOM::Node* getImportedDocument(protocol::DOM::Node* defaultValue) { return m_importedDocument.isJust() ? m_importedDocument.fromJust() : defaultValue; }
            void setImportedDocument(std::unique_ptr<protocol::DOM::Node> value) { m_importedDocument = std::move(value); }

            bool hasDistributedNodes() { return m_distributedNodes.isJust(); }
            protocol::Array<protocol::DOM::BackendNode>* getDistributedNodes(protocol::Array<protocol::DOM::BackendNode>* defaultValue) { return m_distributedNodes.isJust() ? m_distributedNodes.fromJust() : defaultValue; }
            void setDistributedNodes(std::unique_ptr<protocol::Array<protocol::DOM::BackendNode>> value) { m_distributedNodes = std::move(value); }

            bool hasIsSVG() { return m_isSVG.isJust(); }
            bool getIsSVG(bool defaultValue) { return m_isSVG.isJust() ? m_isSVG.fromJust() : defaultValue; }
            void setIsSVG(bool value) { m_isSVG = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Node> clone() const;

            template <int STATE>
            class NodeBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NodeIdSet = 1 << 1,
                    BackendNodeIdSet = 1 << 2,
                    NodeTypeSet = 1 << 3,
                    NodeNameSet = 1 << 4,
                    LocalNameSet = 1 << 5,
                    NodeValueSet = 1 << 6,
                    AllFieldsSet = (NodeIdSet | BackendNodeIdSet | NodeTypeSet | NodeNameSet | LocalNameSet | NodeValueSet | 0)
                };

                NodeBuilder<STATE | NodeIdSet>& setNodeId(int value)
                {
                    static_assert(!(STATE & NodeIdSet), "property nodeId should not be set yet");
                    m_result->setNodeId(value);
                    return castState<NodeIdSet>();
                }

                NodeBuilder<STATE | BackendNodeIdSet>& setBackendNodeId(int value)
                {
                    static_assert(!(STATE & BackendNodeIdSet), "property backendNodeId should not be set yet");
                    m_result->setBackendNodeId(value);
                    return castState<BackendNodeIdSet>();
                }

                NodeBuilder<STATE | NodeTypeSet>& setNodeType(int value)
                {
                    static_assert(!(STATE & NodeTypeSet), "property nodeType should not be set yet");
                    m_result->setNodeType(value);
                    return castState<NodeTypeSet>();
                }

                NodeBuilder<STATE | NodeNameSet>& setNodeName(const String& value)
                {
                    static_assert(!(STATE & NodeNameSet), "property nodeName should not be set yet");
                    m_result->setNodeName(value);
                    return castState<NodeNameSet>();
                }

                NodeBuilder<STATE | LocalNameSet>& setLocalName(const String& value)
                {
                    static_assert(!(STATE & LocalNameSet), "property localName should not be set yet");
                    m_result->setLocalName(value);
                    return castState<LocalNameSet>();
                }

                NodeBuilder<STATE | NodeValueSet>& setNodeValue(const String& value)
                {
                    static_assert(!(STATE & NodeValueSet), "property nodeValue should not be set yet");
                    m_result->setNodeValue(value);
                    return castState<NodeValueSet>();
                }

                NodeBuilder<STATE>& setChildNodeCount(int value)
                {
                    m_result->setChildNodeCount(value);
                    return *this;
                }

                NodeBuilder<STATE>& setChildren(std::unique_ptr<protocol::Array<protocol::DOM::Node>> value)
                {
                    m_result->setChildren(std::move(value));
                    return *this;
                }

                NodeBuilder<STATE>& setAttributes(std::unique_ptr<protocol::Array<String>> value)
                {
                    m_result->setAttributes(std::move(value));
                    return *this;
                }

                NodeBuilder<STATE>& setDocumentURL(const String& value)
                {
                    m_result->setDocumentURL(value);
                    return *this;
                }

                NodeBuilder<STATE>& setBaseURL(const String& value)
                {
                    m_result->setBaseURL(value);
                    return *this;
                }

                NodeBuilder<STATE>& setPublicId(const String& value)
                {
                    m_result->setPublicId(value);
                    return *this;
                }

                NodeBuilder<STATE>& setSystemId(const String& value)
                {
                    m_result->setSystemId(value);
                    return *this;
                }

                NodeBuilder<STATE>& setInternalSubset(const String& value)
                {
                    m_result->setInternalSubset(value);
                    return *this;
                }

                NodeBuilder<STATE>& setXmlVersion(const String& value)
                {
                    m_result->setXmlVersion(value);
                    return *this;
                }

                NodeBuilder<STATE>& setName(const String& value)
                {
                    m_result->setName(value);
                    return *this;
                }

                NodeBuilder<STATE>& setValue(const String& value)
                {
                    m_result->setValue(value);
                    return *this;
                }

                NodeBuilder<STATE>& setPseudoType(const String& value)
                {
                    m_result->setPseudoType(value);
                    return *this;
                }

                NodeBuilder<STATE>& setShadowRootType(const String& value)
                {
                    m_result->setShadowRootType(value);
                    return *this;
                }

                NodeBuilder<STATE>& setFrameId(const String& value)
                {
                    m_result->setFrameId(value);
                    return *this;
                }

                NodeBuilder<STATE>& setContentDocument(std::unique_ptr<protocol::DOM::Node> value)
                {
                    m_result->setContentDocument(std::move(value));
                    return *this;
                }

                NodeBuilder<STATE>& setShadowRoots(std::unique_ptr<protocol::Array<protocol::DOM::Node>> value)
                {
                    m_result->setShadowRoots(std::move(value));
                    return *this;
                }

                NodeBuilder<STATE>& setTemplateContent(std::unique_ptr<protocol::DOM::Node> value)
                {
                    m_result->setTemplateContent(std::move(value));
                    return *this;
                }

                NodeBuilder<STATE>& setPseudoElements(std::unique_ptr<protocol::Array<protocol::DOM::Node>> value)
                {
                    m_result->setPseudoElements(std::move(value));
                    return *this;
                }

                NodeBuilder<STATE>& setImportedDocument(std::unique_ptr<protocol::DOM::Node> value)
                {
                    m_result->setImportedDocument(std::move(value));
                    return *this;
                }

                NodeBuilder<STATE>& setDistributedNodes(std::unique_ptr<protocol::Array<protocol::DOM::BackendNode>> value)
                {
                    m_result->setDistributedNodes(std::move(value));
                    return *this;
                }

                NodeBuilder<STATE>& setIsSVG(bool value)
                {
                    m_result->setIsSVG(value);
                    return *this;
                }

                std::unique_ptr<Node> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Node;
                NodeBuilder()
                    : m_result(new Node())
                {
                }

                template <int STEP>
                NodeBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<NodeBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::Node> m_result;
            };

            static NodeBuilder<0> create()
            {
                return NodeBuilder<0>();
            }

        private:
            Node()
            {
                m_nodeId = 0;
                m_backendNodeId = 0;
                m_nodeType = 0;
            }

            int m_nodeId;
            int m_backendNodeId;
            int m_nodeType;
            String m_nodeName;
            String m_localName;
            String m_nodeValue;
            Maybe<int> m_childNodeCount;
            Maybe<protocol::Array<protocol::DOM::Node>> m_children;
            Maybe<protocol::Array<String>> m_attributes;
            Maybe<String> m_documentURL;
            Maybe<String> m_baseURL;
            Maybe<String> m_publicId;
            Maybe<String> m_systemId;
            Maybe<String> m_internalSubset;
            Maybe<String> m_xmlVersion;
            Maybe<String> m_name;
            Maybe<String> m_value;
            Maybe<String> m_pseudoType;
            Maybe<String> m_shadowRootType;
            Maybe<String> m_frameId;
            Maybe<protocol::DOM::Node> m_contentDocument;
            Maybe<protocol::Array<protocol::DOM::Node>> m_shadowRoots;
            Maybe<protocol::DOM::Node> m_templateContent;
            Maybe<protocol::Array<protocol::DOM::Node>> m_pseudoElements;
            Maybe<protocol::DOM::Node> m_importedDocument;
            Maybe<protocol::Array<protocol::DOM::BackendNode>> m_distributedNodes;
            Maybe<bool> m_isSVG;
        };

        // A structure holding an RGBA color.
        class CORE_EXPORT RGBA : public Serializable {
            PROTOCOL_DISALLOW_COPY(RGBA);

        public:
            static std::unique_ptr<RGBA> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~RGBA() override { }

            int getR() { return m_r; }
            void setR(int value) { m_r = value; }

            int getG() { return m_g; }
            void setG(int value) { m_g = value; }

            int getB() { return m_b; }
            void setB(int value) { m_b = value; }

            bool hasA() { return m_a.isJust(); }
            double getA(double defaultValue) { return m_a.isJust() ? m_a.fromJust() : defaultValue; }
            void setA(double value) { m_a = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<RGBA> clone() const;

            template <int STATE>
            class RGBABuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RSet = 1 << 1,
                    GSet = 1 << 2,
                    BSet = 1 << 3,
                    AllFieldsSet = (RSet | GSet | BSet | 0)
                };

                RGBABuilder<STATE | RSet>& setR(int value)
                {
                    static_assert(!(STATE & RSet), "property r should not be set yet");
                    m_result->setR(value);
                    return castState<RSet>();
                }

                RGBABuilder<STATE | GSet>& setG(int value)
                {
                    static_assert(!(STATE & GSet), "property g should not be set yet");
                    m_result->setG(value);
                    return castState<GSet>();
                }

                RGBABuilder<STATE | BSet>& setB(int value)
                {
                    static_assert(!(STATE & BSet), "property b should not be set yet");
                    m_result->setB(value);
                    return castState<BSet>();
                }

                RGBABuilder<STATE>& setA(double value)
                {
                    m_result->setA(value);
                    return *this;
                }

                std::unique_ptr<RGBA> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class RGBA;
                RGBABuilder()
                    : m_result(new RGBA())
                {
                }

                template <int STEP>
                RGBABuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<RGBABuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::RGBA> m_result;
            };

            static RGBABuilder<0> create()
            {
                return RGBABuilder<0>();
            }

        private:
            RGBA()
            {
                m_r = 0;
                m_g = 0;
                m_b = 0;
            }

            int m_r;
            int m_g;
            int m_b;
            Maybe<double> m_a;
        };

        // Box model.
        class CORE_EXPORT BoxModel : public Serializable {
            PROTOCOL_DISALLOW_COPY(BoxModel);

        public:
            static std::unique_ptr<BoxModel> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~BoxModel() override { }

            protocol::Array<double>* getContent() { return m_content.get(); }
            void setContent(std::unique_ptr<protocol::Array<double>> value) { m_content = std::move(value); }

            protocol::Array<double>* getPadding() { return m_padding.get(); }
            void setPadding(std::unique_ptr<protocol::Array<double>> value) { m_padding = std::move(value); }

            protocol::Array<double>* getBorder() { return m_border.get(); }
            void setBorder(std::unique_ptr<protocol::Array<double>> value) { m_border = std::move(value); }

            protocol::Array<double>* getMargin() { return m_margin.get(); }
            void setMargin(std::unique_ptr<protocol::Array<double>> value) { m_margin = std::move(value); }

            int getWidth() { return m_width; }
            void setWidth(int value) { m_width = value; }

            int getHeight() { return m_height; }
            void setHeight(int value) { m_height = value; }

            bool hasShapeOutside() { return m_shapeOutside.isJust(); }
            protocol::DOM::ShapeOutsideInfo* getShapeOutside(protocol::DOM::ShapeOutsideInfo* defaultValue) { return m_shapeOutside.isJust() ? m_shapeOutside.fromJust() : defaultValue; }
            void setShapeOutside(std::unique_ptr<protocol::DOM::ShapeOutsideInfo> value) { m_shapeOutside = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<BoxModel> clone() const;

            template <int STATE>
            class BoxModelBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ContentSet = 1 << 1,
                    PaddingSet = 1 << 2,
                    BorderSet = 1 << 3,
                    MarginSet = 1 << 4,
                    WidthSet = 1 << 5,
                    HeightSet = 1 << 6,
                    AllFieldsSet = (ContentSet | PaddingSet | BorderSet | MarginSet | WidthSet | HeightSet | 0)
                };

                BoxModelBuilder<STATE | ContentSet>& setContent(std::unique_ptr<protocol::Array<double>> value)
                {
                    static_assert(!(STATE & ContentSet), "property content should not be set yet");
                    m_result->setContent(std::move(value));
                    return castState<ContentSet>();
                }

                BoxModelBuilder<STATE | PaddingSet>& setPadding(std::unique_ptr<protocol::Array<double>> value)
                {
                    static_assert(!(STATE & PaddingSet), "property padding should not be set yet");
                    m_result->setPadding(std::move(value));
                    return castState<PaddingSet>();
                }

                BoxModelBuilder<STATE | BorderSet>& setBorder(std::unique_ptr<protocol::Array<double>> value)
                {
                    static_assert(!(STATE & BorderSet), "property border should not be set yet");
                    m_result->setBorder(std::move(value));
                    return castState<BorderSet>();
                }

                BoxModelBuilder<STATE | MarginSet>& setMargin(std::unique_ptr<protocol::Array<double>> value)
                {
                    static_assert(!(STATE & MarginSet), "property margin should not be set yet");
                    m_result->setMargin(std::move(value));
                    return castState<MarginSet>();
                }

                BoxModelBuilder<STATE | WidthSet>& setWidth(int value)
                {
                    static_assert(!(STATE & WidthSet), "property width should not be set yet");
                    m_result->setWidth(value);
                    return castState<WidthSet>();
                }

                BoxModelBuilder<STATE | HeightSet>& setHeight(int value)
                {
                    static_assert(!(STATE & HeightSet), "property height should not be set yet");
                    m_result->setHeight(value);
                    return castState<HeightSet>();
                }

                BoxModelBuilder<STATE>& setShapeOutside(std::unique_ptr<protocol::DOM::ShapeOutsideInfo> value)
                {
                    m_result->setShapeOutside(std::move(value));
                    return *this;
                }

                std::unique_ptr<BoxModel> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class BoxModel;
                BoxModelBuilder()
                    : m_result(new BoxModel())
                {
                }

                template <int STEP>
                BoxModelBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<BoxModelBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::BoxModel> m_result;
            };

            static BoxModelBuilder<0> create()
            {
                return BoxModelBuilder<0>();
            }

        private:
            BoxModel()
            {
                m_width = 0;
                m_height = 0;
            }

            std::unique_ptr<protocol::Array<double>> m_content;
            std::unique_ptr<protocol::Array<double>> m_padding;
            std::unique_ptr<protocol::Array<double>> m_border;
            std::unique_ptr<protocol::Array<double>> m_margin;
            int m_width;
            int m_height;
            Maybe<protocol::DOM::ShapeOutsideInfo> m_shapeOutside;
        };

        // CSS Shape Outside details.
        class CORE_EXPORT ShapeOutsideInfo : public Serializable {
            PROTOCOL_DISALLOW_COPY(ShapeOutsideInfo);

        public:
            static std::unique_ptr<ShapeOutsideInfo> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ShapeOutsideInfo() override { }

            protocol::Array<double>* getBounds() { return m_bounds.get(); }
            void setBounds(std::unique_ptr<protocol::Array<double>> value) { m_bounds = std::move(value); }

            protocol::Array<protocol::Value>* getShape() { return m_shape.get(); }
            void setShape(std::unique_ptr<protocol::Array<protocol::Value>> value) { m_shape = std::move(value); }

            protocol::Array<protocol::Value>* getMarginShape() { return m_marginShape.get(); }
            void setMarginShape(std::unique_ptr<protocol::Array<protocol::Value>> value) { m_marginShape = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ShapeOutsideInfo> clone() const;

            template <int STATE>
            class ShapeOutsideInfoBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    BoundsSet = 1 << 1,
                    ShapeSet = 1 << 2,
                    MarginShapeSet = 1 << 3,
                    AllFieldsSet = (BoundsSet | ShapeSet | MarginShapeSet | 0)
                };

                ShapeOutsideInfoBuilder<STATE | BoundsSet>& setBounds(std::unique_ptr<protocol::Array<double>> value)
                {
                    static_assert(!(STATE & BoundsSet), "property bounds should not be set yet");
                    m_result->setBounds(std::move(value));
                    return castState<BoundsSet>();
                }

                ShapeOutsideInfoBuilder<STATE | ShapeSet>& setShape(std::unique_ptr<protocol::Array<protocol::Value>> value)
                {
                    static_assert(!(STATE & ShapeSet), "property shape should not be set yet");
                    m_result->setShape(std::move(value));
                    return castState<ShapeSet>();
                }

                ShapeOutsideInfoBuilder<STATE | MarginShapeSet>& setMarginShape(std::unique_ptr<protocol::Array<protocol::Value>> value)
                {
                    static_assert(!(STATE & MarginShapeSet), "property marginShape should not be set yet");
                    m_result->setMarginShape(std::move(value));
                    return castState<MarginShapeSet>();
                }

                std::unique_ptr<ShapeOutsideInfo> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ShapeOutsideInfo;
                ShapeOutsideInfoBuilder()
                    : m_result(new ShapeOutsideInfo())
                {
                }

                template <int STEP>
                ShapeOutsideInfoBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ShapeOutsideInfoBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::ShapeOutsideInfo> m_result;
            };

            static ShapeOutsideInfoBuilder<0> create()
            {
                return ShapeOutsideInfoBuilder<0>();
            }

        private:
            ShapeOutsideInfo()
            {
            }

            std::unique_ptr<protocol::Array<double>> m_bounds;
            std::unique_ptr<protocol::Array<protocol::Value>> m_shape;
            std::unique_ptr<protocol::Array<protocol::Value>> m_marginShape;
        };

        // Rectangle.
        class CORE_EXPORT Rect : public Serializable {
            PROTOCOL_DISALLOW_COPY(Rect);

        public:
            static std::unique_ptr<Rect> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Rect() override { }

            double getX() { return m_x; }
            void setX(double value) { m_x = value; }

            double getY() { return m_y; }
            void setY(double value) { m_y = value; }

            double getWidth() { return m_width; }
            void setWidth(double value) { m_width = value; }

            double getHeight() { return m_height; }
            void setHeight(double value) { m_height = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Rect> clone() const;

            template <int STATE>
            class RectBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    XSet = 1 << 1,
                    YSet = 1 << 2,
                    WidthSet = 1 << 3,
                    HeightSet = 1 << 4,
                    AllFieldsSet = (XSet | YSet | WidthSet | HeightSet | 0)
                };

                RectBuilder<STATE | XSet>& setX(double value)
                {
                    static_assert(!(STATE & XSet), "property x should not be set yet");
                    m_result->setX(value);
                    return castState<XSet>();
                }

                RectBuilder<STATE | YSet>& setY(double value)
                {
                    static_assert(!(STATE & YSet), "property y should not be set yet");
                    m_result->setY(value);
                    return castState<YSet>();
                }

                RectBuilder<STATE | WidthSet>& setWidth(double value)
                {
                    static_assert(!(STATE & WidthSet), "property width should not be set yet");
                    m_result->setWidth(value);
                    return castState<WidthSet>();
                }

                RectBuilder<STATE | HeightSet>& setHeight(double value)
                {
                    static_assert(!(STATE & HeightSet), "property height should not be set yet");
                    m_result->setHeight(value);
                    return castState<HeightSet>();
                }

                std::unique_ptr<Rect> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Rect;
                RectBuilder()
                    : m_result(new Rect())
                {
                }

                template <int STEP>
                RectBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<RectBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::Rect> m_result;
            };

            static RectBuilder<0> create()
            {
                return RectBuilder<0>();
            }

        private:
            Rect()
            {
                m_x = 0;
                m_y = 0;
                m_width = 0;
                m_height = 0;
            }

            double m_x;
            double m_y;
            double m_width;
            double m_height;
        };

        // Configuration data for the highlighting of page elements.
        class CORE_EXPORT HighlightConfig : public Serializable {
            PROTOCOL_DISALLOW_COPY(HighlightConfig);

        public:
            static std::unique_ptr<HighlightConfig> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~HighlightConfig() override { }

            bool hasShowInfo() { return m_showInfo.isJust(); }
            bool getShowInfo(bool defaultValue) { return m_showInfo.isJust() ? m_showInfo.fromJust() : defaultValue; }
            void setShowInfo(bool value) { m_showInfo = value; }

            bool hasShowRulers() { return m_showRulers.isJust(); }
            bool getShowRulers(bool defaultValue) { return m_showRulers.isJust() ? m_showRulers.fromJust() : defaultValue; }
            void setShowRulers(bool value) { m_showRulers = value; }

            bool hasShowExtensionLines() { return m_showExtensionLines.isJust(); }
            bool getShowExtensionLines(bool defaultValue) { return m_showExtensionLines.isJust() ? m_showExtensionLines.fromJust() : defaultValue; }
            void setShowExtensionLines(bool value) { m_showExtensionLines = value; }

            bool hasDisplayAsMaterial() { return m_displayAsMaterial.isJust(); }
            bool getDisplayAsMaterial(bool defaultValue) { return m_displayAsMaterial.isJust() ? m_displayAsMaterial.fromJust() : defaultValue; }
            void setDisplayAsMaterial(bool value) { m_displayAsMaterial = value; }

            bool hasContentColor() { return m_contentColor.isJust(); }
            protocol::DOM::RGBA* getContentColor(protocol::DOM::RGBA* defaultValue) { return m_contentColor.isJust() ? m_contentColor.fromJust() : defaultValue; }
            void setContentColor(std::unique_ptr<protocol::DOM::RGBA> value) { m_contentColor = std::move(value); }

            bool hasPaddingColor() { return m_paddingColor.isJust(); }
            protocol::DOM::RGBA* getPaddingColor(protocol::DOM::RGBA* defaultValue) { return m_paddingColor.isJust() ? m_paddingColor.fromJust() : defaultValue; }
            void setPaddingColor(std::unique_ptr<protocol::DOM::RGBA> value) { m_paddingColor = std::move(value); }

            bool hasBorderColor() { return m_borderColor.isJust(); }
            protocol::DOM::RGBA* getBorderColor(protocol::DOM::RGBA* defaultValue) { return m_borderColor.isJust() ? m_borderColor.fromJust() : defaultValue; }
            void setBorderColor(std::unique_ptr<protocol::DOM::RGBA> value) { m_borderColor = std::move(value); }

            bool hasMarginColor() { return m_marginColor.isJust(); }
            protocol::DOM::RGBA* getMarginColor(protocol::DOM::RGBA* defaultValue) { return m_marginColor.isJust() ? m_marginColor.fromJust() : defaultValue; }
            void setMarginColor(std::unique_ptr<protocol::DOM::RGBA> value) { m_marginColor = std::move(value); }

            bool hasEventTargetColor() { return m_eventTargetColor.isJust(); }
            protocol::DOM::RGBA* getEventTargetColor(protocol::DOM::RGBA* defaultValue) { return m_eventTargetColor.isJust() ? m_eventTargetColor.fromJust() : defaultValue; }
            void setEventTargetColor(std::unique_ptr<protocol::DOM::RGBA> value) { m_eventTargetColor = std::move(value); }

            bool hasShapeColor() { return m_shapeColor.isJust(); }
            protocol::DOM::RGBA* getShapeColor(protocol::DOM::RGBA* defaultValue) { return m_shapeColor.isJust() ? m_shapeColor.fromJust() : defaultValue; }
            void setShapeColor(std::unique_ptr<protocol::DOM::RGBA> value) { m_shapeColor = std::move(value); }

            bool hasShapeMarginColor() { return m_shapeMarginColor.isJust(); }
            protocol::DOM::RGBA* getShapeMarginColor(protocol::DOM::RGBA* defaultValue) { return m_shapeMarginColor.isJust() ? m_shapeMarginColor.fromJust() : defaultValue; }
            void setShapeMarginColor(std::unique_ptr<protocol::DOM::RGBA> value) { m_shapeMarginColor = std::move(value); }

            bool hasSelectorList() { return m_selectorList.isJust(); }
            String getSelectorList(const String& defaultValue) { return m_selectorList.isJust() ? m_selectorList.fromJust() : defaultValue; }
            void setSelectorList(const String& value) { m_selectorList = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<HighlightConfig> clone() const;

            template <int STATE>
            class HighlightConfigBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    AllFieldsSet = (0)
                };

                HighlightConfigBuilder<STATE>& setShowInfo(bool value)
                {
                    m_result->setShowInfo(value);
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setShowRulers(bool value)
                {
                    m_result->setShowRulers(value);
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setShowExtensionLines(bool value)
                {
                    m_result->setShowExtensionLines(value);
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setDisplayAsMaterial(bool value)
                {
                    m_result->setDisplayAsMaterial(value);
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setContentColor(std::unique_ptr<protocol::DOM::RGBA> value)
                {
                    m_result->setContentColor(std::move(value));
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setPaddingColor(std::unique_ptr<protocol::DOM::RGBA> value)
                {
                    m_result->setPaddingColor(std::move(value));
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setBorderColor(std::unique_ptr<protocol::DOM::RGBA> value)
                {
                    m_result->setBorderColor(std::move(value));
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setMarginColor(std::unique_ptr<protocol::DOM::RGBA> value)
                {
                    m_result->setMarginColor(std::move(value));
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setEventTargetColor(std::unique_ptr<protocol::DOM::RGBA> value)
                {
                    m_result->setEventTargetColor(std::move(value));
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setShapeColor(std::unique_ptr<protocol::DOM::RGBA> value)
                {
                    m_result->setShapeColor(std::move(value));
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setShapeMarginColor(std::unique_ptr<protocol::DOM::RGBA> value)
                {
                    m_result->setShapeMarginColor(std::move(value));
                    return *this;
                }

                HighlightConfigBuilder<STATE>& setSelectorList(const String& value)
                {
                    m_result->setSelectorList(value);
                    return *this;
                }

                std::unique_ptr<HighlightConfig> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class HighlightConfig;
                HighlightConfigBuilder()
                    : m_result(new HighlightConfig())
                {
                }

                template <int STEP>
                HighlightConfigBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<HighlightConfigBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::HighlightConfig> m_result;
            };

            static HighlightConfigBuilder<0> create()
            {
                return HighlightConfigBuilder<0>();
            }

        private:
            HighlightConfig()
            {
            }

            Maybe<bool> m_showInfo;
            Maybe<bool> m_showRulers;
            Maybe<bool> m_showExtensionLines;
            Maybe<bool> m_displayAsMaterial;
            Maybe<protocol::DOM::RGBA> m_contentColor;
            Maybe<protocol::DOM::RGBA> m_paddingColor;
            Maybe<protocol::DOM::RGBA> m_borderColor;
            Maybe<protocol::DOM::RGBA> m_marginColor;
            Maybe<protocol::DOM::RGBA> m_eventTargetColor;
            Maybe<protocol::DOM::RGBA> m_shapeColor;
            Maybe<protocol::DOM::RGBA> m_shapeMarginColor;
            Maybe<String> m_selectorList;
        };

        // Wrapper for notification params
        class CORE_EXPORT InspectNodeRequestedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(InspectNodeRequestedNotification);

        public:
            static std::unique_ptr<InspectNodeRequestedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~InspectNodeRequestedNotification() override { }

            int getBackendNodeId() { return m_backendNodeId; }
            void setBackendNodeId(int value) { m_backendNodeId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<InspectNodeRequestedNotification> clone() const;

            template <int STATE>
            class InspectNodeRequestedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    BackendNodeIdSet = 1 << 1,
                    AllFieldsSet = (BackendNodeIdSet | 0)
                };

                InspectNodeRequestedNotificationBuilder<STATE | BackendNodeIdSet>& setBackendNodeId(int value)
                {
                    static_assert(!(STATE & BackendNodeIdSet), "property backendNodeId should not be set yet");
                    m_result->setBackendNodeId(value);
                    return castState<BackendNodeIdSet>();
                }

                std::unique_ptr<InspectNodeRequestedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class InspectNodeRequestedNotification;
                InspectNodeRequestedNotificationBuilder()
                    : m_result(new InspectNodeRequestedNotification())
                {
                }

                template <int STEP>
                InspectNodeRequestedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<InspectNodeRequestedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::InspectNodeRequestedNotification> m_result;
            };

            static InspectNodeRequestedNotificationBuilder<0> create()
            {
                return InspectNodeRequestedNotificationBuilder<0>();
            }

        private:
            InspectNodeRequestedNotification()
            {
                m_backendNodeId = 0;
            }

            int m_backendNodeId;
        };

        // Wrapper for notification params
        class CORE_EXPORT SetChildNodesNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(SetChildNodesNotification);

        public:
            static std::unique_ptr<SetChildNodesNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~SetChildNodesNotification() override { }

            int getParentId() { return m_parentId; }
            void setParentId(int value) { m_parentId = value; }

            protocol::Array<protocol::DOM::Node>* getNodes() { return m_nodes.get(); }
            void setNodes(std::unique_ptr<protocol::Array<protocol::DOM::Node>> value) { m_nodes = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<SetChildNodesNotification> clone() const;

            template <int STATE>
            class SetChildNodesNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ParentIdSet = 1 << 1,
                    NodesSet = 1 << 2,
                    AllFieldsSet = (ParentIdSet | NodesSet | 0)
                };

                SetChildNodesNotificationBuilder<STATE | ParentIdSet>& setParentId(int value)
                {
                    static_assert(!(STATE & ParentIdSet), "property parentId should not be set yet");
                    m_result->setParentId(value);
                    return castState<ParentIdSet>();
                }

                SetChildNodesNotificationBuilder<STATE | NodesSet>& setNodes(std::unique_ptr<protocol::Array<protocol::DOM::Node>> value)
                {
                    static_assert(!(STATE & NodesSet), "property nodes should not be set yet");
                    m_result->setNodes(std::move(value));
                    return castState<NodesSet>();
                }

                std::unique_ptr<SetChildNodesNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class SetChildNodesNotification;
                SetChildNodesNotificationBuilder()
                    : m_result(new SetChildNodesNotification())
                {
                }

                template <int STEP>
                SetChildNodesNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<SetChildNodesNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::SetChildNodesNotification> m_result;
            };

            static SetChildNodesNotificationBuilder<0> create()
            {
                return SetChildNodesNotificationBuilder<0>();
            }

        private:
            SetChildNodesNotification()
            {
                m_parentId = 0;
            }

            int m_parentId;
            std::unique_ptr<protocol::Array<protocol::DOM::Node>> m_nodes;
        };

        // Wrapper for notification params
        class CORE_EXPORT AttributeModifiedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(AttributeModifiedNotification);

        public:
            static std::unique_ptr<AttributeModifiedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~AttributeModifiedNotification() override { }

            int getNodeId() { return m_nodeId; }
            void setNodeId(int value) { m_nodeId = value; }

            String getName() { return m_name; }
            void setName(const String& value) { m_name = value; }

            String getValue() { return m_value; }
            void setValue(const String& value) { m_value = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<AttributeModifiedNotification> clone() const;

            template <int STATE>
            class AttributeModifiedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NodeIdSet = 1 << 1,
                    NameSet = 1 << 2,
                    ValueSet = 1 << 3,
                    AllFieldsSet = (NodeIdSet | NameSet | ValueSet | 0)
                };

                AttributeModifiedNotificationBuilder<STATE | NodeIdSet>& setNodeId(int value)
                {
                    static_assert(!(STATE & NodeIdSet), "property nodeId should not be set yet");
                    m_result->setNodeId(value);
                    return castState<NodeIdSet>();
                }

                AttributeModifiedNotificationBuilder<STATE | NameSet>& setName(const String& value)
                {
                    static_assert(!(STATE & NameSet), "property name should not be set yet");
                    m_result->setName(value);
                    return castState<NameSet>();
                }

                AttributeModifiedNotificationBuilder<STATE | ValueSet>& setValue(const String& value)
                {
                    static_assert(!(STATE & ValueSet), "property value should not be set yet");
                    m_result->setValue(value);
                    return castState<ValueSet>();
                }

                std::unique_ptr<AttributeModifiedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class AttributeModifiedNotification;
                AttributeModifiedNotificationBuilder()
                    : m_result(new AttributeModifiedNotification())
                {
                }

                template <int STEP>
                AttributeModifiedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<AttributeModifiedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::AttributeModifiedNotification> m_result;
            };

            static AttributeModifiedNotificationBuilder<0> create()
            {
                return AttributeModifiedNotificationBuilder<0>();
            }

        private:
            AttributeModifiedNotification()
            {
                m_nodeId = 0;
            }

            int m_nodeId;
            String m_name;
            String m_value;
        };

        // Wrapper for notification params
        class CORE_EXPORT AttributeRemovedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(AttributeRemovedNotification);

        public:
            static std::unique_ptr<AttributeRemovedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~AttributeRemovedNotification() override { }

            int getNodeId() { return m_nodeId; }
            void setNodeId(int value) { m_nodeId = value; }

            String getName() { return m_name; }
            void setName(const String& value) { m_name = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<AttributeRemovedNotification> clone() const;

            template <int STATE>
            class AttributeRemovedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NodeIdSet = 1 << 1,
                    NameSet = 1 << 2,
                    AllFieldsSet = (NodeIdSet | NameSet | 0)
                };

                AttributeRemovedNotificationBuilder<STATE | NodeIdSet>& setNodeId(int value)
                {
                    static_assert(!(STATE & NodeIdSet), "property nodeId should not be set yet");
                    m_result->setNodeId(value);
                    return castState<NodeIdSet>();
                }

                AttributeRemovedNotificationBuilder<STATE | NameSet>& setName(const String& value)
                {
                    static_assert(!(STATE & NameSet), "property name should not be set yet");
                    m_result->setName(value);
                    return castState<NameSet>();
                }

                std::unique_ptr<AttributeRemovedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class AttributeRemovedNotification;
                AttributeRemovedNotificationBuilder()
                    : m_result(new AttributeRemovedNotification())
                {
                }

                template <int STEP>
                AttributeRemovedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<AttributeRemovedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::AttributeRemovedNotification> m_result;
            };

            static AttributeRemovedNotificationBuilder<0> create()
            {
                return AttributeRemovedNotificationBuilder<0>();
            }

        private:
            AttributeRemovedNotification()
            {
                m_nodeId = 0;
            }

            int m_nodeId;
            String m_name;
        };

        // Wrapper for notification params
        class CORE_EXPORT InlineStyleInvalidatedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(InlineStyleInvalidatedNotification);

        public:
            static std::unique_ptr<InlineStyleInvalidatedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~InlineStyleInvalidatedNotification() override { }

            protocol::Array<int>* getNodeIds() { return m_nodeIds.get(); }
            void setNodeIds(std::unique_ptr<protocol::Array<int>> value) { m_nodeIds = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<InlineStyleInvalidatedNotification> clone() const;

            template <int STATE>
            class InlineStyleInvalidatedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NodeIdsSet = 1 << 1,
                    AllFieldsSet = (NodeIdsSet | 0)
                };

                InlineStyleInvalidatedNotificationBuilder<STATE | NodeIdsSet>& setNodeIds(std::unique_ptr<protocol::Array<int>> value)
                {
                    static_assert(!(STATE & NodeIdsSet), "property nodeIds should not be set yet");
                    m_result->setNodeIds(std::move(value));
                    return castState<NodeIdsSet>();
                }

                std::unique_ptr<InlineStyleInvalidatedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class InlineStyleInvalidatedNotification;
                InlineStyleInvalidatedNotificationBuilder()
                    : m_result(new InlineStyleInvalidatedNotification())
                {
                }

                template <int STEP>
                InlineStyleInvalidatedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<InlineStyleInvalidatedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::InlineStyleInvalidatedNotification> m_result;
            };

            static InlineStyleInvalidatedNotificationBuilder<0> create()
            {
                return InlineStyleInvalidatedNotificationBuilder<0>();
            }

        private:
            InlineStyleInvalidatedNotification()
            {
            }

            std::unique_ptr<protocol::Array<int>> m_nodeIds;
        };

        // Wrapper for notification params
        class CORE_EXPORT CharacterDataModifiedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(CharacterDataModifiedNotification);

        public:
            static std::unique_ptr<CharacterDataModifiedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~CharacterDataModifiedNotification() override { }

            int getNodeId() { return m_nodeId; }
            void setNodeId(int value) { m_nodeId = value; }

            String getCharacterData() { return m_characterData; }
            void setCharacterData(const String& value) { m_characterData = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<CharacterDataModifiedNotification> clone() const;

            template <int STATE>
            class CharacterDataModifiedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NodeIdSet = 1 << 1,
                    CharacterDataSet = 1 << 2,
                    AllFieldsSet = (NodeIdSet | CharacterDataSet | 0)
                };

                CharacterDataModifiedNotificationBuilder<STATE | NodeIdSet>& setNodeId(int value)
                {
                    static_assert(!(STATE & NodeIdSet), "property nodeId should not be set yet");
                    m_result->setNodeId(value);
                    return castState<NodeIdSet>();
                }

                CharacterDataModifiedNotificationBuilder<STATE | CharacterDataSet>& setCharacterData(const String& value)
                {
                    static_assert(!(STATE & CharacterDataSet), "property characterData should not be set yet");
                    m_result->setCharacterData(value);
                    return castState<CharacterDataSet>();
                }

                std::unique_ptr<CharacterDataModifiedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class CharacterDataModifiedNotification;
                CharacterDataModifiedNotificationBuilder()
                    : m_result(new CharacterDataModifiedNotification())
                {
                }

                template <int STEP>
                CharacterDataModifiedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<CharacterDataModifiedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::CharacterDataModifiedNotification> m_result;
            };

            static CharacterDataModifiedNotificationBuilder<0> create()
            {
                return CharacterDataModifiedNotificationBuilder<0>();
            }

        private:
            CharacterDataModifiedNotification()
            {
                m_nodeId = 0;
            }

            int m_nodeId;
            String m_characterData;
        };

        // Wrapper for notification params
        class CORE_EXPORT ChildNodeCountUpdatedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ChildNodeCountUpdatedNotification);

        public:
            static std::unique_ptr<ChildNodeCountUpdatedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ChildNodeCountUpdatedNotification() override { }

            int getNodeId() { return m_nodeId; }
            void setNodeId(int value) { m_nodeId = value; }

            int getChildNodeCount() { return m_childNodeCount; }
            void setChildNodeCount(int value) { m_childNodeCount = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ChildNodeCountUpdatedNotification> clone() const;

            template <int STATE>
            class ChildNodeCountUpdatedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NodeIdSet = 1 << 1,
                    ChildNodeCountSet = 1 << 2,
                    AllFieldsSet = (NodeIdSet | ChildNodeCountSet | 0)
                };

                ChildNodeCountUpdatedNotificationBuilder<STATE | NodeIdSet>& setNodeId(int value)
                {
                    static_assert(!(STATE & NodeIdSet), "property nodeId should not be set yet");
                    m_result->setNodeId(value);
                    return castState<NodeIdSet>();
                }

                ChildNodeCountUpdatedNotificationBuilder<STATE | ChildNodeCountSet>& setChildNodeCount(int value)
                {
                    static_assert(!(STATE & ChildNodeCountSet), "property childNodeCount should not be set yet");
                    m_result->setChildNodeCount(value);
                    return castState<ChildNodeCountSet>();
                }

                std::unique_ptr<ChildNodeCountUpdatedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ChildNodeCountUpdatedNotification;
                ChildNodeCountUpdatedNotificationBuilder()
                    : m_result(new ChildNodeCountUpdatedNotification())
                {
                }

                template <int STEP>
                ChildNodeCountUpdatedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ChildNodeCountUpdatedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::ChildNodeCountUpdatedNotification> m_result;
            };

            static ChildNodeCountUpdatedNotificationBuilder<0> create()
            {
                return ChildNodeCountUpdatedNotificationBuilder<0>();
            }

        private:
            ChildNodeCountUpdatedNotification()
            {
                m_nodeId = 0;
                m_childNodeCount = 0;
            }

            int m_nodeId;
            int m_childNodeCount;
        };

        // Wrapper for notification params
        class CORE_EXPORT ChildNodeInsertedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ChildNodeInsertedNotification);

        public:
            static std::unique_ptr<ChildNodeInsertedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ChildNodeInsertedNotification() override { }

            int getParentNodeId() { return m_parentNodeId; }
            void setParentNodeId(int value) { m_parentNodeId = value; }

            int getPreviousNodeId() { return m_previousNodeId; }
            void setPreviousNodeId(int value) { m_previousNodeId = value; }

            protocol::DOM::Node* getNode() { return m_node.get(); }
            void setNode(std::unique_ptr<protocol::DOM::Node> value) { m_node = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ChildNodeInsertedNotification> clone() const;

            template <int STATE>
            class ChildNodeInsertedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ParentNodeIdSet = 1 << 1,
                    PreviousNodeIdSet = 1 << 2,
                    NodeSet = 1 << 3,
                    AllFieldsSet = (ParentNodeIdSet | PreviousNodeIdSet | NodeSet | 0)
                };

                ChildNodeInsertedNotificationBuilder<STATE | ParentNodeIdSet>& setParentNodeId(int value)
                {
                    static_assert(!(STATE & ParentNodeIdSet), "property parentNodeId should not be set yet");
                    m_result->setParentNodeId(value);
                    return castState<ParentNodeIdSet>();
                }

                ChildNodeInsertedNotificationBuilder<STATE | PreviousNodeIdSet>& setPreviousNodeId(int value)
                {
                    static_assert(!(STATE & PreviousNodeIdSet), "property previousNodeId should not be set yet");
                    m_result->setPreviousNodeId(value);
                    return castState<PreviousNodeIdSet>();
                }

                ChildNodeInsertedNotificationBuilder<STATE | NodeSet>& setNode(std::unique_ptr<protocol::DOM::Node> value)
                {
                    static_assert(!(STATE & NodeSet), "property node should not be set yet");
                    m_result->setNode(std::move(value));
                    return castState<NodeSet>();
                }

                std::unique_ptr<ChildNodeInsertedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ChildNodeInsertedNotification;
                ChildNodeInsertedNotificationBuilder()
                    : m_result(new ChildNodeInsertedNotification())
                {
                }

                template <int STEP>
                ChildNodeInsertedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ChildNodeInsertedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::ChildNodeInsertedNotification> m_result;
            };

            static ChildNodeInsertedNotificationBuilder<0> create()
            {
                return ChildNodeInsertedNotificationBuilder<0>();
            }

        private:
            ChildNodeInsertedNotification()
            {
                m_parentNodeId = 0;
                m_previousNodeId = 0;
            }

            int m_parentNodeId;
            int m_previousNodeId;
            std::unique_ptr<protocol::DOM::Node> m_node;
        };

        // Wrapper for notification params
        class CORE_EXPORT ChildNodeRemovedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ChildNodeRemovedNotification);

        public:
            static std::unique_ptr<ChildNodeRemovedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ChildNodeRemovedNotification() override { }

            int getParentNodeId() { return m_parentNodeId; }
            void setParentNodeId(int value) { m_parentNodeId = value; }

            int getNodeId() { return m_nodeId; }
            void setNodeId(int value) { m_nodeId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ChildNodeRemovedNotification> clone() const;

            template <int STATE>
            class ChildNodeRemovedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ParentNodeIdSet = 1 << 1,
                    NodeIdSet = 1 << 2,
                    AllFieldsSet = (ParentNodeIdSet | NodeIdSet | 0)
                };

                ChildNodeRemovedNotificationBuilder<STATE | ParentNodeIdSet>& setParentNodeId(int value)
                {
                    static_assert(!(STATE & ParentNodeIdSet), "property parentNodeId should not be set yet");
                    m_result->setParentNodeId(value);
                    return castState<ParentNodeIdSet>();
                }

                ChildNodeRemovedNotificationBuilder<STATE | NodeIdSet>& setNodeId(int value)
                {
                    static_assert(!(STATE & NodeIdSet), "property nodeId should not be set yet");
                    m_result->setNodeId(value);
                    return castState<NodeIdSet>();
                }

                std::unique_ptr<ChildNodeRemovedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ChildNodeRemovedNotification;
                ChildNodeRemovedNotificationBuilder()
                    : m_result(new ChildNodeRemovedNotification())
                {
                }

                template <int STEP>
                ChildNodeRemovedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ChildNodeRemovedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::ChildNodeRemovedNotification> m_result;
            };

            static ChildNodeRemovedNotificationBuilder<0> create()
            {
                return ChildNodeRemovedNotificationBuilder<0>();
            }

        private:
            ChildNodeRemovedNotification()
            {
                m_parentNodeId = 0;
                m_nodeId = 0;
            }

            int m_parentNodeId;
            int m_nodeId;
        };

        // Wrapper for notification params
        class CORE_EXPORT ShadowRootPushedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ShadowRootPushedNotification);

        public:
            static std::unique_ptr<ShadowRootPushedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ShadowRootPushedNotification() override { }

            int getHostId() { return m_hostId; }
            void setHostId(int value) { m_hostId = value; }

            protocol::DOM::Node* getRoot() { return m_root.get(); }
            void setRoot(std::unique_ptr<protocol::DOM::Node> value) { m_root = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ShadowRootPushedNotification> clone() const;

            template <int STATE>
            class ShadowRootPushedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    HostIdSet = 1 << 1,
                    RootSet = 1 << 2,
                    AllFieldsSet = (HostIdSet | RootSet | 0)
                };

                ShadowRootPushedNotificationBuilder<STATE | HostIdSet>& setHostId(int value)
                {
                    static_assert(!(STATE & HostIdSet), "property hostId should not be set yet");
                    m_result->setHostId(value);
                    return castState<HostIdSet>();
                }

                ShadowRootPushedNotificationBuilder<STATE | RootSet>& setRoot(std::unique_ptr<protocol::DOM::Node> value)
                {
                    static_assert(!(STATE & RootSet), "property root should not be set yet");
                    m_result->setRoot(std::move(value));
                    return castState<RootSet>();
                }

                std::unique_ptr<ShadowRootPushedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ShadowRootPushedNotification;
                ShadowRootPushedNotificationBuilder()
                    : m_result(new ShadowRootPushedNotification())
                {
                }

                template <int STEP>
                ShadowRootPushedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ShadowRootPushedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::ShadowRootPushedNotification> m_result;
            };

            static ShadowRootPushedNotificationBuilder<0> create()
            {
                return ShadowRootPushedNotificationBuilder<0>();
            }

        private:
            ShadowRootPushedNotification()
            {
                m_hostId = 0;
            }

            int m_hostId;
            std::unique_ptr<protocol::DOM::Node> m_root;
        };

        // Wrapper for notification params
        class CORE_EXPORT ShadowRootPoppedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ShadowRootPoppedNotification);

        public:
            static std::unique_ptr<ShadowRootPoppedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ShadowRootPoppedNotification() override { }

            int getHostId() { return m_hostId; }
            void setHostId(int value) { m_hostId = value; }

            int getRootId() { return m_rootId; }
            void setRootId(int value) { m_rootId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ShadowRootPoppedNotification> clone() const;

            template <int STATE>
            class ShadowRootPoppedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    HostIdSet = 1 << 1,
                    RootIdSet = 1 << 2,
                    AllFieldsSet = (HostIdSet | RootIdSet | 0)
                };

                ShadowRootPoppedNotificationBuilder<STATE | HostIdSet>& setHostId(int value)
                {
                    static_assert(!(STATE & HostIdSet), "property hostId should not be set yet");
                    m_result->setHostId(value);
                    return castState<HostIdSet>();
                }

                ShadowRootPoppedNotificationBuilder<STATE | RootIdSet>& setRootId(int value)
                {
                    static_assert(!(STATE & RootIdSet), "property rootId should not be set yet");
                    m_result->setRootId(value);
                    return castState<RootIdSet>();
                }

                std::unique_ptr<ShadowRootPoppedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ShadowRootPoppedNotification;
                ShadowRootPoppedNotificationBuilder()
                    : m_result(new ShadowRootPoppedNotification())
                {
                }

                template <int STEP>
                ShadowRootPoppedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ShadowRootPoppedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::ShadowRootPoppedNotification> m_result;
            };

            static ShadowRootPoppedNotificationBuilder<0> create()
            {
                return ShadowRootPoppedNotificationBuilder<0>();
            }

        private:
            ShadowRootPoppedNotification()
            {
                m_hostId = 0;
                m_rootId = 0;
            }

            int m_hostId;
            int m_rootId;
        };

        // Wrapper for notification params
        class CORE_EXPORT PseudoElementAddedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(PseudoElementAddedNotification);

        public:
            static std::unique_ptr<PseudoElementAddedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~PseudoElementAddedNotification() override { }

            int getParentId() { return m_parentId; }
            void setParentId(int value) { m_parentId = value; }

            protocol::DOM::Node* getPseudoElement() { return m_pseudoElement.get(); }
            void setPseudoElement(std::unique_ptr<protocol::DOM::Node> value) { m_pseudoElement = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<PseudoElementAddedNotification> clone() const;

            template <int STATE>
            class PseudoElementAddedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ParentIdSet = 1 << 1,
                    PseudoElementSet = 1 << 2,
                    AllFieldsSet = (ParentIdSet | PseudoElementSet | 0)
                };

                PseudoElementAddedNotificationBuilder<STATE | ParentIdSet>& setParentId(int value)
                {
                    static_assert(!(STATE & ParentIdSet), "property parentId should not be set yet");
                    m_result->setParentId(value);
                    return castState<ParentIdSet>();
                }

                PseudoElementAddedNotificationBuilder<STATE | PseudoElementSet>& setPseudoElement(std::unique_ptr<protocol::DOM::Node> value)
                {
                    static_assert(!(STATE & PseudoElementSet), "property pseudoElement should not be set yet");
                    m_result->setPseudoElement(std::move(value));
                    return castState<PseudoElementSet>();
                }

                std::unique_ptr<PseudoElementAddedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class PseudoElementAddedNotification;
                PseudoElementAddedNotificationBuilder()
                    : m_result(new PseudoElementAddedNotification())
                {
                }

                template <int STEP>
                PseudoElementAddedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<PseudoElementAddedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::PseudoElementAddedNotification> m_result;
            };

            static PseudoElementAddedNotificationBuilder<0> create()
            {
                return PseudoElementAddedNotificationBuilder<0>();
            }

        private:
            PseudoElementAddedNotification()
            {
                m_parentId = 0;
            }

            int m_parentId;
            std::unique_ptr<protocol::DOM::Node> m_pseudoElement;
        };

        // Wrapper for notification params
        class CORE_EXPORT PseudoElementRemovedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(PseudoElementRemovedNotification);

        public:
            static std::unique_ptr<PseudoElementRemovedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~PseudoElementRemovedNotification() override { }

            int getParentId() { return m_parentId; }
            void setParentId(int value) { m_parentId = value; }

            int getPseudoElementId() { return m_pseudoElementId; }
            void setPseudoElementId(int value) { m_pseudoElementId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<PseudoElementRemovedNotification> clone() const;

            template <int STATE>
            class PseudoElementRemovedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ParentIdSet = 1 << 1,
                    PseudoElementIdSet = 1 << 2,
                    AllFieldsSet = (ParentIdSet | PseudoElementIdSet | 0)
                };

                PseudoElementRemovedNotificationBuilder<STATE | ParentIdSet>& setParentId(int value)
                {
                    static_assert(!(STATE & ParentIdSet), "property parentId should not be set yet");
                    m_result->setParentId(value);
                    return castState<ParentIdSet>();
                }

                PseudoElementRemovedNotificationBuilder<STATE | PseudoElementIdSet>& setPseudoElementId(int value)
                {
                    static_assert(!(STATE & PseudoElementIdSet), "property pseudoElementId should not be set yet");
                    m_result->setPseudoElementId(value);
                    return castState<PseudoElementIdSet>();
                }

                std::unique_ptr<PseudoElementRemovedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class PseudoElementRemovedNotification;
                PseudoElementRemovedNotificationBuilder()
                    : m_result(new PseudoElementRemovedNotification())
                {
                }

                template <int STEP>
                PseudoElementRemovedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<PseudoElementRemovedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::PseudoElementRemovedNotification> m_result;
            };

            static PseudoElementRemovedNotificationBuilder<0> create()
            {
                return PseudoElementRemovedNotificationBuilder<0>();
            }

        private:
            PseudoElementRemovedNotification()
            {
                m_parentId = 0;
                m_pseudoElementId = 0;
            }

            int m_parentId;
            int m_pseudoElementId;
        };

        // Wrapper for notification params
        class CORE_EXPORT DistributedNodesUpdatedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(DistributedNodesUpdatedNotification);

        public:
            static std::unique_ptr<DistributedNodesUpdatedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DistributedNodesUpdatedNotification() override { }

            int getInsertionPointId() { return m_insertionPointId; }
            void setInsertionPointId(int value) { m_insertionPointId = value; }

            protocol::Array<protocol::DOM::BackendNode>* getDistributedNodes() { return m_distributedNodes.get(); }
            void setDistributedNodes(std::unique_ptr<protocol::Array<protocol::DOM::BackendNode>> value) { m_distributedNodes = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DistributedNodesUpdatedNotification> clone() const;

            template <int STATE>
            class DistributedNodesUpdatedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    InsertionPointIdSet = 1 << 1,
                    DistributedNodesSet = 1 << 2,
                    AllFieldsSet = (InsertionPointIdSet | DistributedNodesSet | 0)
                };

                DistributedNodesUpdatedNotificationBuilder<STATE | InsertionPointIdSet>& setInsertionPointId(int value)
                {
                    static_assert(!(STATE & InsertionPointIdSet), "property insertionPointId should not be set yet");
                    m_result->setInsertionPointId(value);
                    return castState<InsertionPointIdSet>();
                }

                DistributedNodesUpdatedNotificationBuilder<STATE | DistributedNodesSet>& setDistributedNodes(std::unique_ptr<protocol::Array<protocol::DOM::BackendNode>> value)
                {
                    static_assert(!(STATE & DistributedNodesSet), "property distributedNodes should not be set yet");
                    m_result->setDistributedNodes(std::move(value));
                    return castState<DistributedNodesSet>();
                }

                std::unique_ptr<DistributedNodesUpdatedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DistributedNodesUpdatedNotification;
                DistributedNodesUpdatedNotificationBuilder()
                    : m_result(new DistributedNodesUpdatedNotification())
                {
                }

                template <int STEP>
                DistributedNodesUpdatedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DistributedNodesUpdatedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::DistributedNodesUpdatedNotification> m_result;
            };

            static DistributedNodesUpdatedNotificationBuilder<0> create()
            {
                return DistributedNodesUpdatedNotificationBuilder<0>();
            }

        private:
            DistributedNodesUpdatedNotification()
            {
                m_insertionPointId = 0;
            }

            int m_insertionPointId;
            std::unique_ptr<protocol::Array<protocol::DOM::BackendNode>> m_distributedNodes;
        };

        // Wrapper for notification params
        class CORE_EXPORT NodeHighlightRequestedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(NodeHighlightRequestedNotification);

        public:
            static std::unique_ptr<NodeHighlightRequestedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~NodeHighlightRequestedNotification() override { }

            int getNodeId() { return m_nodeId; }
            void setNodeId(int value) { m_nodeId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<NodeHighlightRequestedNotification> clone() const;

            template <int STATE>
            class NodeHighlightRequestedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NodeIdSet = 1 << 1,
                    AllFieldsSet = (NodeIdSet | 0)
                };

                NodeHighlightRequestedNotificationBuilder<STATE | NodeIdSet>& setNodeId(int value)
                {
                    static_assert(!(STATE & NodeIdSet), "property nodeId should not be set yet");
                    m_result->setNodeId(value);
                    return castState<NodeIdSet>();
                }

                std::unique_ptr<NodeHighlightRequestedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class NodeHighlightRequestedNotification;
                NodeHighlightRequestedNotificationBuilder()
                    : m_result(new NodeHighlightRequestedNotification())
                {
                }

                template <int STEP>
                NodeHighlightRequestedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<NodeHighlightRequestedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::NodeHighlightRequestedNotification> m_result;
            };

            static NodeHighlightRequestedNotificationBuilder<0> create()
            {
                return NodeHighlightRequestedNotificationBuilder<0>();
            }

        private:
            NodeHighlightRequestedNotification()
            {
                m_nodeId = 0;
            }

            int m_nodeId;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse enable() = 0;
            virtual DispatchResponse disable() = 0;
            virtual DispatchResponse getDocument(Maybe<int> in_depth, Maybe<bool> in_pierce, std::unique_ptr<protocol::DOM::Node>* out_root) = 0;
            virtual DispatchResponse collectClassNamesFromSubtree(int in_nodeId, std::unique_ptr<protocol::Array<String>>* out_classNames) = 0;
            virtual DispatchResponse requestChildNodes(int in_nodeId, Maybe<int> in_depth, Maybe<bool> in_pierce) = 0;
            virtual DispatchResponse querySelector(int in_nodeId, const String& in_selector, int* out_nodeId) = 0;
            virtual DispatchResponse querySelectorAll(int in_nodeId, const String& in_selector, std::unique_ptr<protocol::Array<int>>* out_nodeIds) = 0;
            virtual DispatchResponse setNodeName(int in_nodeId, const String& in_name, int* out_nodeId) = 0;
            virtual DispatchResponse setNodeValue(int in_nodeId, const String& in_value) = 0;
            virtual DispatchResponse removeNode(int in_nodeId) = 0;
            virtual DispatchResponse setAttributeValue(int in_nodeId, const String& in_name, const String& in_value) = 0;
            virtual DispatchResponse setAttributesAsText(int in_nodeId, const String& in_text, Maybe<String> in_name) = 0;
            virtual DispatchResponse removeAttribute(int in_nodeId, const String& in_name) = 0;
            virtual DispatchResponse getOuterHTML(int in_nodeId, String* out_outerHTML) = 0;
            virtual DispatchResponse setOuterHTML(int in_nodeId, const String& in_outerHTML) = 0;
            virtual DispatchResponse performSearch(const String& in_query, Maybe<bool> in_includeUserAgentShadowDOM, String* out_searchId, int* out_resultCount) = 0;
            virtual DispatchResponse getSearchResults(const String& in_searchId, int in_fromIndex, int in_toIndex, std::unique_ptr<protocol::Array<int>>* out_nodeIds) = 0;
            virtual DispatchResponse discardSearchResults(const String& in_searchId) = 0;
            virtual DispatchResponse requestNode(const String& in_objectId, int* out_nodeId) = 0;
            virtual DispatchResponse setInspectMode(const String& in_mode, Maybe<protocol::DOM::HighlightConfig> in_highlightConfig) = 0;
            virtual DispatchResponse highlightRect(int in_x, int in_y, int in_width, int in_height, Maybe<protocol::DOM::RGBA> in_color, Maybe<protocol::DOM::RGBA> in_outlineColor) = 0;
            virtual DispatchResponse highlightQuad(std::unique_ptr<protocol::Array<double>> in_quad, Maybe<protocol::DOM::RGBA> in_color, Maybe<protocol::DOM::RGBA> in_outlineColor) = 0;
            virtual DispatchResponse highlightNode(std::unique_ptr<protocol::DOM::HighlightConfig> in_highlightConfig, Maybe<int> in_nodeId, Maybe<int> in_backendNodeId, Maybe<String> in_objectId) = 0;
            virtual DispatchResponse hideHighlight() = 0;
            virtual DispatchResponse highlightFrame(const String& in_frameId, Maybe<protocol::DOM::RGBA> in_contentColor, Maybe<protocol::DOM::RGBA> in_contentOutlineColor) = 0;
            virtual DispatchResponse pushNodeByPathToFrontend(const String& in_path, int* out_nodeId) = 0;
            virtual DispatchResponse pushNodesByBackendIdsToFrontend(std::unique_ptr<protocol::Array<int>> in_backendNodeIds, std::unique_ptr<protocol::Array<int>>* out_nodeIds) = 0;
            virtual DispatchResponse setInspectedNode(int in_nodeId) = 0;
            virtual DispatchResponse resolveNode(int in_nodeId, Maybe<String> in_objectGroup, std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject>* out_object) = 0;
            virtual DispatchResponse getAttributes(int in_nodeId, std::unique_ptr<protocol::Array<String>>* out_attributes) = 0;
            virtual DispatchResponse copyTo(int in_nodeId, int in_targetNodeId, Maybe<int> in_insertBeforeNodeId, int* out_nodeId) = 0;
            virtual DispatchResponse moveTo(int in_nodeId, int in_targetNodeId, Maybe<int> in_insertBeforeNodeId, int* out_nodeId) = 0;
            virtual DispatchResponse undo() = 0;
            virtual DispatchResponse redo() = 0;
            virtual DispatchResponse markUndoableState() = 0;
            virtual DispatchResponse focus(int in_nodeId) = 0;
            virtual DispatchResponse setFileInputFiles(int in_nodeId, std::unique_ptr<protocol::Array<String>> in_files) = 0;
            virtual DispatchResponse getBoxModel(int in_nodeId, std::unique_ptr<protocol::DOM::BoxModel>* out_model) = 0;
            virtual DispatchResponse getNodeForLocation(int in_x, int in_y, int* out_nodeId) = 0;
            virtual DispatchResponse getRelayoutBoundary(int in_nodeId, int* out_nodeId) = 0;
            virtual DispatchResponse getHighlightObjectForTest(int in_nodeId, std::unique_ptr<protocol::DictionaryValue>* out_highlight) = 0;
        };

        // ------------- Frontend interface.

        class CORE_EXPORT Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }
            void documentUpdated();
            void inspectNodeRequested(int backendNodeId);
            void setChildNodes(int parentId, std::unique_ptr<protocol::Array<protocol::DOM::Node>> nodes);
            void attributeModified(int nodeId, const String& name, const String& value);
            void attributeRemoved(int nodeId, const String& name);
            void inlineStyleInvalidated(std::unique_ptr<protocol::Array<int>> nodeIds);
            void characterDataModified(int nodeId, const String& characterData);
            void childNodeCountUpdated(int nodeId, int childNodeCount);
            void childNodeInserted(int parentNodeId, int previousNodeId, std::unique_ptr<protocol::DOM::Node> node);
            void childNodeRemoved(int parentNodeId, int nodeId);
            void shadowRootPushed(int hostId, std::unique_ptr<protocol::DOM::Node> root);
            void shadowRootPopped(int hostId, int rootId);
            void pseudoElementAdded(int parentId, std::unique_ptr<protocol::DOM::Node> pseudoElement);
            void pseudoElementRemoved(int parentId, int pseudoElementId);
            void distributedNodesUpdated(int insertionPointId, std::unique_ptr<protocol::Array<protocol::DOM::BackendNode>> distributedNodes);
            void nodeHighlightRequested(int nodeId);

            void flush();
            void sendRawNotification(const String&);

        private:
            FrontendChannel* m_frontendChannel;
        };

        // ------------- Dispatcher.

        class CORE_EXPORT Dispatcher {
        public:
            static void wire(UberDispatcher*, Backend*);

        private:
            Dispatcher() { }
        };

        // ------------- Metainfo.

        class CORE_EXPORT Metainfo {
        public:
            using BackendClass = Backend;
            using FrontendClass = Frontend;
            using DispatcherClass = Dispatcher;
            static const char domainName[];
            static const char commandPrefix[];
            static const char version[];
        };

    } // namespace DOM
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_DOM_h)
