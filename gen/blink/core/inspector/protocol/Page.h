// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Page_h
#define blink_protocol_Page_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "core/inspector/protocol/DOM.h"
#include "core/inspector/protocol/Debugger.h"

namespace blink {
namespace protocol {
    namespace Page {

        // ------------- Forward and enum declarations.
        // Resource type as it was perceived by the rendering engine.
        using ResourceType = String;
        // Unique frame identifier.
        using FrameId = String;
        // Information about the Frame on the page.
        class Frame;
        // Information about the Resource on the page.
        class FrameResource;
        // Information about the Frame hierarchy along with their cached resources.
        class FrameResourceTree;
        // Unique script identifier.
        using ScriptIdentifier = String;
        // Navigation history entry.
        class NavigationEntry;
        // Screencast frame metadata.
        class ScreencastFrameMetadata;
        // Javascript dialog type.
        using DialogType = String;
        // Error while paring app manifest.
        class AppManifestError;
        // Proceed: allow the navigation; Cancel: cancel the navigation; CancelAndIgnore: cancels the navigation and makes the requester of the navigation acts like the request was never made.
        using NavigationResponse = String;
        // Layout viewport position and dimensions.
        class LayoutViewport;
        // Visual viewport position, dimensions, and scale.
        class VisualViewport;
        // Wrapper for notification params
        class DomContentEventFiredNotification;
        // Wrapper for notification params
        class LoadEventFiredNotification;
        // Wrapper for notification params
        class FrameAttachedNotification;
        // Wrapper for notification params
        class FrameNavigatedNotification;
        // Wrapper for notification params
        class FrameDetachedNotification;
        // Wrapper for notification params
        class FrameStartedLoadingNotification;
        // Wrapper for notification params
        class FrameStoppedLoadingNotification;
        // Wrapper for notification params
        class FrameScheduledNavigationNotification;
        // Wrapper for notification params
        class FrameClearedScheduledNavigationNotification;
        // Wrapper for notification params
        using FrameResizedNotification = Object;
        // Wrapper for notification params
        class JavascriptDialogOpeningNotification;
        // Wrapper for notification params
        class JavascriptDialogClosedNotification;
        // Wrapper for notification params
        class ScreencastFrameNotification;
        // Wrapper for notification params
        class ScreencastVisibilityChangedNotification;
        // Wrapper for notification params
        class ColorPickedNotification;
        // Wrapper for notification params
        using InterstitialShownNotification = Object;
        // Wrapper for notification params
        using InterstitialHiddenNotification = Object;
        // Wrapper for notification params
        class NavigationRequestedNotification;

        namespace ResourceTypeEnum {
            CORE_EXPORT extern const char* Document;
            CORE_EXPORT extern const char* Stylesheet;
            CORE_EXPORT extern const char* Image;
            CORE_EXPORT extern const char* Media;
            CORE_EXPORT extern const char* Font;
            CORE_EXPORT extern const char* Script;
            CORE_EXPORT extern const char* TextTrack;
            CORE_EXPORT extern const char* XHR;
            CORE_EXPORT extern const char* Fetch;
            CORE_EXPORT extern const char* EventSource;
            CORE_EXPORT extern const char* WebSocket;
            CORE_EXPORT extern const char* Manifest;
            CORE_EXPORT extern const char* Other;
        } // namespace ResourceTypeEnum

        namespace DialogTypeEnum {
            CORE_EXPORT extern const char* Alert;
            CORE_EXPORT extern const char* Confirm;
            CORE_EXPORT extern const char* Prompt;
            CORE_EXPORT extern const char* Beforeunload;
        } // namespace DialogTypeEnum

        namespace NavigationResponseEnum {
            CORE_EXPORT extern const char* Proceed;
            CORE_EXPORT extern const char* Cancel;
            CORE_EXPORT extern const char* CancelAndIgnore;
        } // namespace NavigationResponseEnum

        namespace SetTouchEmulationEnabled {
            namespace ConfigurationEnum {
                CORE_EXPORT extern const char* Mobile;
                CORE_EXPORT extern const char* Desktop;
            } // ConfigurationEnum
        } // SetTouchEmulationEnabled

        namespace StartScreencast {
            namespace FormatEnum {
                CORE_EXPORT extern const char* Jpeg;
                CORE_EXPORT extern const char* Png;
            } // FormatEnum
        } // StartScreencast

        // ------------- Type and builder declarations.

        // Information about the Frame on the page.
        class CORE_EXPORT Frame : public Serializable {
            PROTOCOL_DISALLOW_COPY(Frame);

        public:
            static std::unique_ptr<Frame> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Frame() override { }

            String getId() { return m_id; }
            void setId(const String& value) { m_id = value; }

            bool hasParentId() { return m_parentId.isJust(); }
            String getParentId(const String& defaultValue) { return m_parentId.isJust() ? m_parentId.fromJust() : defaultValue; }
            void setParentId(const String& value) { m_parentId = value; }

            String getLoaderId() { return m_loaderId; }
            void setLoaderId(const String& value) { m_loaderId = value; }

            bool hasName() { return m_name.isJust(); }
            String getName(const String& defaultValue) { return m_name.isJust() ? m_name.fromJust() : defaultValue; }
            void setName(const String& value) { m_name = value; }

            String getUrl() { return m_url; }
            void setUrl(const String& value) { m_url = value; }

            String getSecurityOrigin() { return m_securityOrigin; }
            void setSecurityOrigin(const String& value) { m_securityOrigin = value; }

            String getMimeType() { return m_mimeType; }
            void setMimeType(const String& value) { m_mimeType = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Frame> clone() const;

            template <int STATE>
            class FrameBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    IdSet = 1 << 1,
                    LoaderIdSet = 1 << 2,
                    UrlSet = 1 << 3,
                    SecurityOriginSet = 1 << 4,
                    MimeTypeSet = 1 << 5,
                    AllFieldsSet = (IdSet | LoaderIdSet | UrlSet | SecurityOriginSet | MimeTypeSet | 0)
                };

                FrameBuilder<STATE | IdSet>& setId(const String& value)
                {
                    static_assert(!(STATE & IdSet), "property id should not be set yet");
                    m_result->setId(value);
                    return castState<IdSet>();
                }

                FrameBuilder<STATE>& setParentId(const String& value)
                {
                    m_result->setParentId(value);
                    return *this;
                }

                FrameBuilder<STATE | LoaderIdSet>& setLoaderId(const String& value)
                {
                    static_assert(!(STATE & LoaderIdSet), "property loaderId should not be set yet");
                    m_result->setLoaderId(value);
                    return castState<LoaderIdSet>();
                }

                FrameBuilder<STATE>& setName(const String& value)
                {
                    m_result->setName(value);
                    return *this;
                }

                FrameBuilder<STATE | UrlSet>& setUrl(const String& value)
                {
                    static_assert(!(STATE & UrlSet), "property url should not be set yet");
                    m_result->setUrl(value);
                    return castState<UrlSet>();
                }

                FrameBuilder<STATE | SecurityOriginSet>& setSecurityOrigin(const String& value)
                {
                    static_assert(!(STATE & SecurityOriginSet), "property securityOrigin should not be set yet");
                    m_result->setSecurityOrigin(value);
                    return castState<SecurityOriginSet>();
                }

                FrameBuilder<STATE | MimeTypeSet>& setMimeType(const String& value)
                {
                    static_assert(!(STATE & MimeTypeSet), "property mimeType should not be set yet");
                    m_result->setMimeType(value);
                    return castState<MimeTypeSet>();
                }

                std::unique_ptr<Frame> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Frame;
                FrameBuilder()
                    : m_result(new Frame())
                {
                }

                template <int STEP>
                FrameBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::Frame> m_result;
            };

            static FrameBuilder<0> create()
            {
                return FrameBuilder<0>();
            }

        private:
            Frame()
            {
            }

            String m_id;
            Maybe<String> m_parentId;
            String m_loaderId;
            Maybe<String> m_name;
            String m_url;
            String m_securityOrigin;
            String m_mimeType;
        };

        // Information about the Resource on the page.
        class CORE_EXPORT FrameResource : public Serializable {
            PROTOCOL_DISALLOW_COPY(FrameResource);

        public:
            static std::unique_ptr<FrameResource> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~FrameResource() override { }

            String getUrl() { return m_url; }
            void setUrl(const String& value) { m_url = value; }

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            String getMimeType() { return m_mimeType; }
            void setMimeType(const String& value) { m_mimeType = value; }

            bool hasLastModified() { return m_lastModified.isJust(); }
            double getLastModified(double defaultValue) { return m_lastModified.isJust() ? m_lastModified.fromJust() : defaultValue; }
            void setLastModified(double value) { m_lastModified = value; }

            bool hasContentSize() { return m_contentSize.isJust(); }
            double getContentSize(double defaultValue) { return m_contentSize.isJust() ? m_contentSize.fromJust() : defaultValue; }
            void setContentSize(double value) { m_contentSize = value; }

            bool hasFailed() { return m_failed.isJust(); }
            bool getFailed(bool defaultValue) { return m_failed.isJust() ? m_failed.fromJust() : defaultValue; }
            void setFailed(bool value) { m_failed = value; }

            bool hasCanceled() { return m_canceled.isJust(); }
            bool getCanceled(bool defaultValue) { return m_canceled.isJust() ? m_canceled.fromJust() : defaultValue; }
            void setCanceled(bool value) { m_canceled = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<FrameResource> clone() const;

            template <int STATE>
            class FrameResourceBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    UrlSet = 1 << 1,
                    TypeSet = 1 << 2,
                    MimeTypeSet = 1 << 3,
                    AllFieldsSet = (UrlSet | TypeSet | MimeTypeSet | 0)
                };

                FrameResourceBuilder<STATE | UrlSet>& setUrl(const String& value)
                {
                    static_assert(!(STATE & UrlSet), "property url should not be set yet");
                    m_result->setUrl(value);
                    return castState<UrlSet>();
                }

                FrameResourceBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                FrameResourceBuilder<STATE | MimeTypeSet>& setMimeType(const String& value)
                {
                    static_assert(!(STATE & MimeTypeSet), "property mimeType should not be set yet");
                    m_result->setMimeType(value);
                    return castState<MimeTypeSet>();
                }

                FrameResourceBuilder<STATE>& setLastModified(double value)
                {
                    m_result->setLastModified(value);
                    return *this;
                }

                FrameResourceBuilder<STATE>& setContentSize(double value)
                {
                    m_result->setContentSize(value);
                    return *this;
                }

                FrameResourceBuilder<STATE>& setFailed(bool value)
                {
                    m_result->setFailed(value);
                    return *this;
                }

                FrameResourceBuilder<STATE>& setCanceled(bool value)
                {
                    m_result->setCanceled(value);
                    return *this;
                }

                std::unique_ptr<FrameResource> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class FrameResource;
                FrameResourceBuilder()
                    : m_result(new FrameResource())
                {
                }

                template <int STEP>
                FrameResourceBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameResourceBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::FrameResource> m_result;
            };

            static FrameResourceBuilder<0> create()
            {
                return FrameResourceBuilder<0>();
            }

        private:
            FrameResource()
            {
            }

            String m_url;
            String m_type;
            String m_mimeType;
            Maybe<double> m_lastModified;
            Maybe<double> m_contentSize;
            Maybe<bool> m_failed;
            Maybe<bool> m_canceled;
        };

        // Information about the Frame hierarchy along with their cached resources.
        class CORE_EXPORT FrameResourceTree : public Serializable {
            PROTOCOL_DISALLOW_COPY(FrameResourceTree);

        public:
            static std::unique_ptr<FrameResourceTree> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~FrameResourceTree() override { }

            protocol::Page::Frame* getFrame() { return m_frame.get(); }
            void setFrame(std::unique_ptr<protocol::Page::Frame> value) { m_frame = std::move(value); }

            bool hasChildFrames() { return m_childFrames.isJust(); }
            protocol::Array<protocol::Page::FrameResourceTree>* getChildFrames(protocol::Array<protocol::Page::FrameResourceTree>* defaultValue) { return m_childFrames.isJust() ? m_childFrames.fromJust() : defaultValue; }
            void setChildFrames(std::unique_ptr<protocol::Array<protocol::Page::FrameResourceTree>> value) { m_childFrames = std::move(value); }

            protocol::Array<protocol::Page::FrameResource>* getResources() { return m_resources.get(); }
            void setResources(std::unique_ptr<protocol::Array<protocol::Page::FrameResource>> value) { m_resources = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<FrameResourceTree> clone() const;

            template <int STATE>
            class FrameResourceTreeBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    FrameSet = 1 << 1,
                    ResourcesSet = 1 << 2,
                    AllFieldsSet = (FrameSet | ResourcesSet | 0)
                };

                FrameResourceTreeBuilder<STATE | FrameSet>& setFrame(std::unique_ptr<protocol::Page::Frame> value)
                {
                    static_assert(!(STATE & FrameSet), "property frame should not be set yet");
                    m_result->setFrame(std::move(value));
                    return castState<FrameSet>();
                }

                FrameResourceTreeBuilder<STATE>& setChildFrames(std::unique_ptr<protocol::Array<protocol::Page::FrameResourceTree>> value)
                {
                    m_result->setChildFrames(std::move(value));
                    return *this;
                }

                FrameResourceTreeBuilder<STATE | ResourcesSet>& setResources(std::unique_ptr<protocol::Array<protocol::Page::FrameResource>> value)
                {
                    static_assert(!(STATE & ResourcesSet), "property resources should not be set yet");
                    m_result->setResources(std::move(value));
                    return castState<ResourcesSet>();
                }

                std::unique_ptr<FrameResourceTree> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class FrameResourceTree;
                FrameResourceTreeBuilder()
                    : m_result(new FrameResourceTree())
                {
                }

                template <int STEP>
                FrameResourceTreeBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameResourceTreeBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::FrameResourceTree> m_result;
            };

            static FrameResourceTreeBuilder<0> create()
            {
                return FrameResourceTreeBuilder<0>();
            }

        private:
            FrameResourceTree()
            {
            }

            std::unique_ptr<protocol::Page::Frame> m_frame;
            Maybe<protocol::Array<protocol::Page::FrameResourceTree>> m_childFrames;
            std::unique_ptr<protocol::Array<protocol::Page::FrameResource>> m_resources;
        };

        // Navigation history entry.
        class CORE_EXPORT NavigationEntry : public Serializable {
            PROTOCOL_DISALLOW_COPY(NavigationEntry);

        public:
            static std::unique_ptr<NavigationEntry> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~NavigationEntry() override { }

            int getId() { return m_id; }
            void setId(int value) { m_id = value; }

            String getUrl() { return m_url; }
            void setUrl(const String& value) { m_url = value; }

            String getTitle() { return m_title; }
            void setTitle(const String& value) { m_title = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<NavigationEntry> clone() const;

            template <int STATE>
            class NavigationEntryBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    IdSet = 1 << 1,
                    UrlSet = 1 << 2,
                    TitleSet = 1 << 3,
                    AllFieldsSet = (IdSet | UrlSet | TitleSet | 0)
                };

                NavigationEntryBuilder<STATE | IdSet>& setId(int value)
                {
                    static_assert(!(STATE & IdSet), "property id should not be set yet");
                    m_result->setId(value);
                    return castState<IdSet>();
                }

                NavigationEntryBuilder<STATE | UrlSet>& setUrl(const String& value)
                {
                    static_assert(!(STATE & UrlSet), "property url should not be set yet");
                    m_result->setUrl(value);
                    return castState<UrlSet>();
                }

                NavigationEntryBuilder<STATE | TitleSet>& setTitle(const String& value)
                {
                    static_assert(!(STATE & TitleSet), "property title should not be set yet");
                    m_result->setTitle(value);
                    return castState<TitleSet>();
                }

                std::unique_ptr<NavigationEntry> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class NavigationEntry;
                NavigationEntryBuilder()
                    : m_result(new NavigationEntry())
                {
                }

                template <int STEP>
                NavigationEntryBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<NavigationEntryBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::NavigationEntry> m_result;
            };

            static NavigationEntryBuilder<0> create()
            {
                return NavigationEntryBuilder<0>();
            }

        private:
            NavigationEntry()
            {
                m_id = 0;
            }

            int m_id;
            String m_url;
            String m_title;
        };

        // Screencast frame metadata.
        class CORE_EXPORT ScreencastFrameMetadata : public Serializable {
            PROTOCOL_DISALLOW_COPY(ScreencastFrameMetadata);

        public:
            static std::unique_ptr<ScreencastFrameMetadata> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ScreencastFrameMetadata() override { }

            double getOffsetTop() { return m_offsetTop; }
            void setOffsetTop(double value) { m_offsetTop = value; }

            double getPageScaleFactor() { return m_pageScaleFactor; }
            void setPageScaleFactor(double value) { m_pageScaleFactor = value; }

            double getDeviceWidth() { return m_deviceWidth; }
            void setDeviceWidth(double value) { m_deviceWidth = value; }

            double getDeviceHeight() { return m_deviceHeight; }
            void setDeviceHeight(double value) { m_deviceHeight = value; }

            double getScrollOffsetX() { return m_scrollOffsetX; }
            void setScrollOffsetX(double value) { m_scrollOffsetX = value; }

            double getScrollOffsetY() { return m_scrollOffsetY; }
            void setScrollOffsetY(double value) { m_scrollOffsetY = value; }

            bool hasTimestamp() { return m_timestamp.isJust(); }
            double getTimestamp(double defaultValue) { return m_timestamp.isJust() ? m_timestamp.fromJust() : defaultValue; }
            void setTimestamp(double value) { m_timestamp = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ScreencastFrameMetadata> clone() const;

            template <int STATE>
            class ScreencastFrameMetadataBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    OffsetTopSet = 1 << 1,
                    PageScaleFactorSet = 1 << 2,
                    DeviceWidthSet = 1 << 3,
                    DeviceHeightSet = 1 << 4,
                    ScrollOffsetXSet = 1 << 5,
                    ScrollOffsetYSet = 1 << 6,
                    AllFieldsSet = (OffsetTopSet | PageScaleFactorSet | DeviceWidthSet | DeviceHeightSet | ScrollOffsetXSet | ScrollOffsetYSet | 0)
                };

                ScreencastFrameMetadataBuilder<STATE | OffsetTopSet>& setOffsetTop(double value)
                {
                    static_assert(!(STATE & OffsetTopSet), "property offsetTop should not be set yet");
                    m_result->setOffsetTop(value);
                    return castState<OffsetTopSet>();
                }

                ScreencastFrameMetadataBuilder<STATE | PageScaleFactorSet>& setPageScaleFactor(double value)
                {
                    static_assert(!(STATE & PageScaleFactorSet), "property pageScaleFactor should not be set yet");
                    m_result->setPageScaleFactor(value);
                    return castState<PageScaleFactorSet>();
                }

                ScreencastFrameMetadataBuilder<STATE | DeviceWidthSet>& setDeviceWidth(double value)
                {
                    static_assert(!(STATE & DeviceWidthSet), "property deviceWidth should not be set yet");
                    m_result->setDeviceWidth(value);
                    return castState<DeviceWidthSet>();
                }

                ScreencastFrameMetadataBuilder<STATE | DeviceHeightSet>& setDeviceHeight(double value)
                {
                    static_assert(!(STATE & DeviceHeightSet), "property deviceHeight should not be set yet");
                    m_result->setDeviceHeight(value);
                    return castState<DeviceHeightSet>();
                }

                ScreencastFrameMetadataBuilder<STATE | ScrollOffsetXSet>& setScrollOffsetX(double value)
                {
                    static_assert(!(STATE & ScrollOffsetXSet), "property scrollOffsetX should not be set yet");
                    m_result->setScrollOffsetX(value);
                    return castState<ScrollOffsetXSet>();
                }

                ScreencastFrameMetadataBuilder<STATE | ScrollOffsetYSet>& setScrollOffsetY(double value)
                {
                    static_assert(!(STATE & ScrollOffsetYSet), "property scrollOffsetY should not be set yet");
                    m_result->setScrollOffsetY(value);
                    return castState<ScrollOffsetYSet>();
                }

                ScreencastFrameMetadataBuilder<STATE>& setTimestamp(double value)
                {
                    m_result->setTimestamp(value);
                    return *this;
                }

                std::unique_ptr<ScreencastFrameMetadata> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ScreencastFrameMetadata;
                ScreencastFrameMetadataBuilder()
                    : m_result(new ScreencastFrameMetadata())
                {
                }

                template <int STEP>
                ScreencastFrameMetadataBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ScreencastFrameMetadataBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::ScreencastFrameMetadata> m_result;
            };

            static ScreencastFrameMetadataBuilder<0> create()
            {
                return ScreencastFrameMetadataBuilder<0>();
            }

        private:
            ScreencastFrameMetadata()
            {
                m_offsetTop = 0;
                m_pageScaleFactor = 0;
                m_deviceWidth = 0;
                m_deviceHeight = 0;
                m_scrollOffsetX = 0;
                m_scrollOffsetY = 0;
            }

            double m_offsetTop;
            double m_pageScaleFactor;
            double m_deviceWidth;
            double m_deviceHeight;
            double m_scrollOffsetX;
            double m_scrollOffsetY;
            Maybe<double> m_timestamp;
        };

        // Error while paring app manifest.
        class CORE_EXPORT AppManifestError : public Serializable {
            PROTOCOL_DISALLOW_COPY(AppManifestError);

        public:
            static std::unique_ptr<AppManifestError> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~AppManifestError() override { }

            String getMessage() { return m_message; }
            void setMessage(const String& value) { m_message = value; }

            int getCritical() { return m_critical; }
            void setCritical(int value) { m_critical = value; }

            int getLine() { return m_line; }
            void setLine(int value) { m_line = value; }

            int getColumn() { return m_column; }
            void setColumn(int value) { m_column = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<AppManifestError> clone() const;

            template <int STATE>
            class AppManifestErrorBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    MessageSet = 1 << 1,
                    CriticalSet = 1 << 2,
                    LineSet = 1 << 3,
                    ColumnSet = 1 << 4,
                    AllFieldsSet = (MessageSet | CriticalSet | LineSet | ColumnSet | 0)
                };

                AppManifestErrorBuilder<STATE | MessageSet>& setMessage(const String& value)
                {
                    static_assert(!(STATE & MessageSet), "property message should not be set yet");
                    m_result->setMessage(value);
                    return castState<MessageSet>();
                }

                AppManifestErrorBuilder<STATE | CriticalSet>& setCritical(int value)
                {
                    static_assert(!(STATE & CriticalSet), "property critical should not be set yet");
                    m_result->setCritical(value);
                    return castState<CriticalSet>();
                }

                AppManifestErrorBuilder<STATE | LineSet>& setLine(int value)
                {
                    static_assert(!(STATE & LineSet), "property line should not be set yet");
                    m_result->setLine(value);
                    return castState<LineSet>();
                }

                AppManifestErrorBuilder<STATE | ColumnSet>& setColumn(int value)
                {
                    static_assert(!(STATE & ColumnSet), "property column should not be set yet");
                    m_result->setColumn(value);
                    return castState<ColumnSet>();
                }

                std::unique_ptr<AppManifestError> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class AppManifestError;
                AppManifestErrorBuilder()
                    : m_result(new AppManifestError())
                {
                }

                template <int STEP>
                AppManifestErrorBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<AppManifestErrorBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::AppManifestError> m_result;
            };

            static AppManifestErrorBuilder<0> create()
            {
                return AppManifestErrorBuilder<0>();
            }

        private:
            AppManifestError()
            {
                m_critical = 0;
                m_line = 0;
                m_column = 0;
            }

            String m_message;
            int m_critical;
            int m_line;
            int m_column;
        };

        // Layout viewport position and dimensions.
        class CORE_EXPORT LayoutViewport : public Serializable {
            PROTOCOL_DISALLOW_COPY(LayoutViewport);

        public:
            static std::unique_ptr<LayoutViewport> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~LayoutViewport() override { }

            int getPageX() { return m_pageX; }
            void setPageX(int value) { m_pageX = value; }

            int getPageY() { return m_pageY; }
            void setPageY(int value) { m_pageY = value; }

            int getClientWidth() { return m_clientWidth; }
            void setClientWidth(int value) { m_clientWidth = value; }

            int getClientHeight() { return m_clientHeight; }
            void setClientHeight(int value) { m_clientHeight = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<LayoutViewport> clone() const;

            template <int STATE>
            class LayoutViewportBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    PageXSet = 1 << 1,
                    PageYSet = 1 << 2,
                    ClientWidthSet = 1 << 3,
                    ClientHeightSet = 1 << 4,
                    AllFieldsSet = (PageXSet | PageYSet | ClientWidthSet | ClientHeightSet | 0)
                };

                LayoutViewportBuilder<STATE | PageXSet>& setPageX(int value)
                {
                    static_assert(!(STATE & PageXSet), "property pageX should not be set yet");
                    m_result->setPageX(value);
                    return castState<PageXSet>();
                }

                LayoutViewportBuilder<STATE | PageYSet>& setPageY(int value)
                {
                    static_assert(!(STATE & PageYSet), "property pageY should not be set yet");
                    m_result->setPageY(value);
                    return castState<PageYSet>();
                }

                LayoutViewportBuilder<STATE | ClientWidthSet>& setClientWidth(int value)
                {
                    static_assert(!(STATE & ClientWidthSet), "property clientWidth should not be set yet");
                    m_result->setClientWidth(value);
                    return castState<ClientWidthSet>();
                }

                LayoutViewportBuilder<STATE | ClientHeightSet>& setClientHeight(int value)
                {
                    static_assert(!(STATE & ClientHeightSet), "property clientHeight should not be set yet");
                    m_result->setClientHeight(value);
                    return castState<ClientHeightSet>();
                }

                std::unique_ptr<LayoutViewport> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class LayoutViewport;
                LayoutViewportBuilder()
                    : m_result(new LayoutViewport())
                {
                }

                template <int STEP>
                LayoutViewportBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<LayoutViewportBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::LayoutViewport> m_result;
            };

            static LayoutViewportBuilder<0> create()
            {
                return LayoutViewportBuilder<0>();
            }

        private:
            LayoutViewport()
            {
                m_pageX = 0;
                m_pageY = 0;
                m_clientWidth = 0;
                m_clientHeight = 0;
            }

            int m_pageX;
            int m_pageY;
            int m_clientWidth;
            int m_clientHeight;
        };

        // Visual viewport position, dimensions, and scale.
        class CORE_EXPORT VisualViewport : public Serializable {
            PROTOCOL_DISALLOW_COPY(VisualViewport);

        public:
            static std::unique_ptr<VisualViewport> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~VisualViewport() override { }

            double getOffsetX() { return m_offsetX; }
            void setOffsetX(double value) { m_offsetX = value; }

            double getOffsetY() { return m_offsetY; }
            void setOffsetY(double value) { m_offsetY = value; }

            double getPageX() { return m_pageX; }
            void setPageX(double value) { m_pageX = value; }

            double getPageY() { return m_pageY; }
            void setPageY(double value) { m_pageY = value; }

            double getClientWidth() { return m_clientWidth; }
            void setClientWidth(double value) { m_clientWidth = value; }

            double getClientHeight() { return m_clientHeight; }
            void setClientHeight(double value) { m_clientHeight = value; }

            double getScale() { return m_scale; }
            void setScale(double value) { m_scale = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<VisualViewport> clone() const;

            template <int STATE>
            class VisualViewportBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    OffsetXSet = 1 << 1,
                    OffsetYSet = 1 << 2,
                    PageXSet = 1 << 3,
                    PageYSet = 1 << 4,
                    ClientWidthSet = 1 << 5,
                    ClientHeightSet = 1 << 6,
                    ScaleSet = 1 << 7,
                    AllFieldsSet = (OffsetXSet | OffsetYSet | PageXSet | PageYSet | ClientWidthSet | ClientHeightSet | ScaleSet | 0)
                };

                VisualViewportBuilder<STATE | OffsetXSet>& setOffsetX(double value)
                {
                    static_assert(!(STATE & OffsetXSet), "property offsetX should not be set yet");
                    m_result->setOffsetX(value);
                    return castState<OffsetXSet>();
                }

                VisualViewportBuilder<STATE | OffsetYSet>& setOffsetY(double value)
                {
                    static_assert(!(STATE & OffsetYSet), "property offsetY should not be set yet");
                    m_result->setOffsetY(value);
                    return castState<OffsetYSet>();
                }

                VisualViewportBuilder<STATE | PageXSet>& setPageX(double value)
                {
                    static_assert(!(STATE & PageXSet), "property pageX should not be set yet");
                    m_result->setPageX(value);
                    return castState<PageXSet>();
                }

                VisualViewportBuilder<STATE | PageYSet>& setPageY(double value)
                {
                    static_assert(!(STATE & PageYSet), "property pageY should not be set yet");
                    m_result->setPageY(value);
                    return castState<PageYSet>();
                }

                VisualViewportBuilder<STATE | ClientWidthSet>& setClientWidth(double value)
                {
                    static_assert(!(STATE & ClientWidthSet), "property clientWidth should not be set yet");
                    m_result->setClientWidth(value);
                    return castState<ClientWidthSet>();
                }

                VisualViewportBuilder<STATE | ClientHeightSet>& setClientHeight(double value)
                {
                    static_assert(!(STATE & ClientHeightSet), "property clientHeight should not be set yet");
                    m_result->setClientHeight(value);
                    return castState<ClientHeightSet>();
                }

                VisualViewportBuilder<STATE | ScaleSet>& setScale(double value)
                {
                    static_assert(!(STATE & ScaleSet), "property scale should not be set yet");
                    m_result->setScale(value);
                    return castState<ScaleSet>();
                }

                std::unique_ptr<VisualViewport> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class VisualViewport;
                VisualViewportBuilder()
                    : m_result(new VisualViewport())
                {
                }

                template <int STEP>
                VisualViewportBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<VisualViewportBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::VisualViewport> m_result;
            };

            static VisualViewportBuilder<0> create()
            {
                return VisualViewportBuilder<0>();
            }

        private:
            VisualViewport()
            {
                m_offsetX = 0;
                m_offsetY = 0;
                m_pageX = 0;
                m_pageY = 0;
                m_clientWidth = 0;
                m_clientHeight = 0;
                m_scale = 0;
            }

            double m_offsetX;
            double m_offsetY;
            double m_pageX;
            double m_pageY;
            double m_clientWidth;
            double m_clientHeight;
            double m_scale;
        };

        // Wrapper for notification params
        class CORE_EXPORT DomContentEventFiredNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(DomContentEventFiredNotification);

        public:
            static std::unique_ptr<DomContentEventFiredNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DomContentEventFiredNotification() override { }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DomContentEventFiredNotification> clone() const;

            template <int STATE>
            class DomContentEventFiredNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    TimestampSet = 1 << 1,
                    AllFieldsSet = (TimestampSet | 0)
                };

                DomContentEventFiredNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                std::unique_ptr<DomContentEventFiredNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DomContentEventFiredNotification;
                DomContentEventFiredNotificationBuilder()
                    : m_result(new DomContentEventFiredNotification())
                {
                }

                template <int STEP>
                DomContentEventFiredNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DomContentEventFiredNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::DomContentEventFiredNotification> m_result;
            };

            static DomContentEventFiredNotificationBuilder<0> create()
            {
                return DomContentEventFiredNotificationBuilder<0>();
            }

        private:
            DomContentEventFiredNotification()
            {
                m_timestamp = 0;
            }

            double m_timestamp;
        };

        // Wrapper for notification params
        class CORE_EXPORT LoadEventFiredNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(LoadEventFiredNotification);

        public:
            static std::unique_ptr<LoadEventFiredNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~LoadEventFiredNotification() override { }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<LoadEventFiredNotification> clone() const;

            template <int STATE>
            class LoadEventFiredNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    TimestampSet = 1 << 1,
                    AllFieldsSet = (TimestampSet | 0)
                };

                LoadEventFiredNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                std::unique_ptr<LoadEventFiredNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class LoadEventFiredNotification;
                LoadEventFiredNotificationBuilder()
                    : m_result(new LoadEventFiredNotification())
                {
                }

                template <int STEP>
                LoadEventFiredNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<LoadEventFiredNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::LoadEventFiredNotification> m_result;
            };

            static LoadEventFiredNotificationBuilder<0> create()
            {
                return LoadEventFiredNotificationBuilder<0>();
            }

        private:
            LoadEventFiredNotification()
            {
                m_timestamp = 0;
            }

            double m_timestamp;
        };

        // Wrapper for notification params
        class CORE_EXPORT FrameAttachedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(FrameAttachedNotification);

        public:
            static std::unique_ptr<FrameAttachedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~FrameAttachedNotification() override { }

            String getFrameId() { return m_frameId; }
            void setFrameId(const String& value) { m_frameId = value; }

            String getParentFrameId() { return m_parentFrameId; }
            void setParentFrameId(const String& value) { m_parentFrameId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<FrameAttachedNotification> clone() const;

            template <int STATE>
            class FrameAttachedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    FrameIdSet = 1 << 1,
                    ParentFrameIdSet = 1 << 2,
                    AllFieldsSet = (FrameIdSet | ParentFrameIdSet | 0)
                };

                FrameAttachedNotificationBuilder<STATE | FrameIdSet>& setFrameId(const String& value)
                {
                    static_assert(!(STATE & FrameIdSet), "property frameId should not be set yet");
                    m_result->setFrameId(value);
                    return castState<FrameIdSet>();
                }

                FrameAttachedNotificationBuilder<STATE | ParentFrameIdSet>& setParentFrameId(const String& value)
                {
                    static_assert(!(STATE & ParentFrameIdSet), "property parentFrameId should not be set yet");
                    m_result->setParentFrameId(value);
                    return castState<ParentFrameIdSet>();
                }

                std::unique_ptr<FrameAttachedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class FrameAttachedNotification;
                FrameAttachedNotificationBuilder()
                    : m_result(new FrameAttachedNotification())
                {
                }

                template <int STEP>
                FrameAttachedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameAttachedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::FrameAttachedNotification> m_result;
            };

            static FrameAttachedNotificationBuilder<0> create()
            {
                return FrameAttachedNotificationBuilder<0>();
            }

        private:
            FrameAttachedNotification()
            {
            }

            String m_frameId;
            String m_parentFrameId;
        };

        // Wrapper for notification params
        class CORE_EXPORT FrameNavigatedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(FrameNavigatedNotification);

        public:
            static std::unique_ptr<FrameNavigatedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~FrameNavigatedNotification() override { }

            protocol::Page::Frame* getFrame() { return m_frame.get(); }
            void setFrame(std::unique_ptr<protocol::Page::Frame> value) { m_frame = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<FrameNavigatedNotification> clone() const;

            template <int STATE>
            class FrameNavigatedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    FrameSet = 1 << 1,
                    AllFieldsSet = (FrameSet | 0)
                };

                FrameNavigatedNotificationBuilder<STATE | FrameSet>& setFrame(std::unique_ptr<protocol::Page::Frame> value)
                {
                    static_assert(!(STATE & FrameSet), "property frame should not be set yet");
                    m_result->setFrame(std::move(value));
                    return castState<FrameSet>();
                }

                std::unique_ptr<FrameNavigatedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class FrameNavigatedNotification;
                FrameNavigatedNotificationBuilder()
                    : m_result(new FrameNavigatedNotification())
                {
                }

                template <int STEP>
                FrameNavigatedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameNavigatedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::FrameNavigatedNotification> m_result;
            };

            static FrameNavigatedNotificationBuilder<0> create()
            {
                return FrameNavigatedNotificationBuilder<0>();
            }

        private:
            FrameNavigatedNotification()
            {
            }

            std::unique_ptr<protocol::Page::Frame> m_frame;
        };

        // Wrapper for notification params
        class CORE_EXPORT FrameDetachedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(FrameDetachedNotification);

        public:
            static std::unique_ptr<FrameDetachedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~FrameDetachedNotification() override { }

            String getFrameId() { return m_frameId; }
            void setFrameId(const String& value) { m_frameId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<FrameDetachedNotification> clone() const;

            template <int STATE>
            class FrameDetachedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    FrameIdSet = 1 << 1,
                    AllFieldsSet = (FrameIdSet | 0)
                };

                FrameDetachedNotificationBuilder<STATE | FrameIdSet>& setFrameId(const String& value)
                {
                    static_assert(!(STATE & FrameIdSet), "property frameId should not be set yet");
                    m_result->setFrameId(value);
                    return castState<FrameIdSet>();
                }

                std::unique_ptr<FrameDetachedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class FrameDetachedNotification;
                FrameDetachedNotificationBuilder()
                    : m_result(new FrameDetachedNotification())
                {
                }

                template <int STEP>
                FrameDetachedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameDetachedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::FrameDetachedNotification> m_result;
            };

            static FrameDetachedNotificationBuilder<0> create()
            {
                return FrameDetachedNotificationBuilder<0>();
            }

        private:
            FrameDetachedNotification()
            {
            }

            String m_frameId;
        };

        // Wrapper for notification params
        class CORE_EXPORT FrameStartedLoadingNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(FrameStartedLoadingNotification);

        public:
            static std::unique_ptr<FrameStartedLoadingNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~FrameStartedLoadingNotification() override { }

            String getFrameId() { return m_frameId; }
            void setFrameId(const String& value) { m_frameId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<FrameStartedLoadingNotification> clone() const;

            template <int STATE>
            class FrameStartedLoadingNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    FrameIdSet = 1 << 1,
                    AllFieldsSet = (FrameIdSet | 0)
                };

                FrameStartedLoadingNotificationBuilder<STATE | FrameIdSet>& setFrameId(const String& value)
                {
                    static_assert(!(STATE & FrameIdSet), "property frameId should not be set yet");
                    m_result->setFrameId(value);
                    return castState<FrameIdSet>();
                }

                std::unique_ptr<FrameStartedLoadingNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class FrameStartedLoadingNotification;
                FrameStartedLoadingNotificationBuilder()
                    : m_result(new FrameStartedLoadingNotification())
                {
                }

                template <int STEP>
                FrameStartedLoadingNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameStartedLoadingNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::FrameStartedLoadingNotification> m_result;
            };

            static FrameStartedLoadingNotificationBuilder<0> create()
            {
                return FrameStartedLoadingNotificationBuilder<0>();
            }

        private:
            FrameStartedLoadingNotification()
            {
            }

            String m_frameId;
        };

        // Wrapper for notification params
        class CORE_EXPORT FrameStoppedLoadingNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(FrameStoppedLoadingNotification);

        public:
            static std::unique_ptr<FrameStoppedLoadingNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~FrameStoppedLoadingNotification() override { }

            String getFrameId() { return m_frameId; }
            void setFrameId(const String& value) { m_frameId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<FrameStoppedLoadingNotification> clone() const;

            template <int STATE>
            class FrameStoppedLoadingNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    FrameIdSet = 1 << 1,
                    AllFieldsSet = (FrameIdSet | 0)
                };

                FrameStoppedLoadingNotificationBuilder<STATE | FrameIdSet>& setFrameId(const String& value)
                {
                    static_assert(!(STATE & FrameIdSet), "property frameId should not be set yet");
                    m_result->setFrameId(value);
                    return castState<FrameIdSet>();
                }

                std::unique_ptr<FrameStoppedLoadingNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class FrameStoppedLoadingNotification;
                FrameStoppedLoadingNotificationBuilder()
                    : m_result(new FrameStoppedLoadingNotification())
                {
                }

                template <int STEP>
                FrameStoppedLoadingNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameStoppedLoadingNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::FrameStoppedLoadingNotification> m_result;
            };

            static FrameStoppedLoadingNotificationBuilder<0> create()
            {
                return FrameStoppedLoadingNotificationBuilder<0>();
            }

        private:
            FrameStoppedLoadingNotification()
            {
            }

            String m_frameId;
        };

        // Wrapper for notification params
        class CORE_EXPORT FrameScheduledNavigationNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(FrameScheduledNavigationNotification);

        public:
            static std::unique_ptr<FrameScheduledNavigationNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~FrameScheduledNavigationNotification() override { }

            String getFrameId() { return m_frameId; }
            void setFrameId(const String& value) { m_frameId = value; }

            double getDelay() { return m_delay; }
            void setDelay(double value) { m_delay = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<FrameScheduledNavigationNotification> clone() const;

            template <int STATE>
            class FrameScheduledNavigationNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    FrameIdSet = 1 << 1,
                    DelaySet = 1 << 2,
                    AllFieldsSet = (FrameIdSet | DelaySet | 0)
                };

                FrameScheduledNavigationNotificationBuilder<STATE | FrameIdSet>& setFrameId(const String& value)
                {
                    static_assert(!(STATE & FrameIdSet), "property frameId should not be set yet");
                    m_result->setFrameId(value);
                    return castState<FrameIdSet>();
                }

                FrameScheduledNavigationNotificationBuilder<STATE | DelaySet>& setDelay(double value)
                {
                    static_assert(!(STATE & DelaySet), "property delay should not be set yet");
                    m_result->setDelay(value);
                    return castState<DelaySet>();
                }

                std::unique_ptr<FrameScheduledNavigationNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class FrameScheduledNavigationNotification;
                FrameScheduledNavigationNotificationBuilder()
                    : m_result(new FrameScheduledNavigationNotification())
                {
                }

                template <int STEP>
                FrameScheduledNavigationNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameScheduledNavigationNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::FrameScheduledNavigationNotification> m_result;
            };

            static FrameScheduledNavigationNotificationBuilder<0> create()
            {
                return FrameScheduledNavigationNotificationBuilder<0>();
            }

        private:
            FrameScheduledNavigationNotification()
            {
                m_delay = 0;
            }

            String m_frameId;
            double m_delay;
        };

        // Wrapper for notification params
        class CORE_EXPORT FrameClearedScheduledNavigationNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(FrameClearedScheduledNavigationNotification);

        public:
            static std::unique_ptr<FrameClearedScheduledNavigationNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~FrameClearedScheduledNavigationNotification() override { }

            String getFrameId() { return m_frameId; }
            void setFrameId(const String& value) { m_frameId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<FrameClearedScheduledNavigationNotification> clone() const;

            template <int STATE>
            class FrameClearedScheduledNavigationNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    FrameIdSet = 1 << 1,
                    AllFieldsSet = (FrameIdSet | 0)
                };

                FrameClearedScheduledNavigationNotificationBuilder<STATE | FrameIdSet>& setFrameId(const String& value)
                {
                    static_assert(!(STATE & FrameIdSet), "property frameId should not be set yet");
                    m_result->setFrameId(value);
                    return castState<FrameIdSet>();
                }

                std::unique_ptr<FrameClearedScheduledNavigationNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class FrameClearedScheduledNavigationNotification;
                FrameClearedScheduledNavigationNotificationBuilder()
                    : m_result(new FrameClearedScheduledNavigationNotification())
                {
                }

                template <int STEP>
                FrameClearedScheduledNavigationNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<FrameClearedScheduledNavigationNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::FrameClearedScheduledNavigationNotification> m_result;
            };

            static FrameClearedScheduledNavigationNotificationBuilder<0> create()
            {
                return FrameClearedScheduledNavigationNotificationBuilder<0>();
            }

        private:
            FrameClearedScheduledNavigationNotification()
            {
            }

            String m_frameId;
        };

        // Wrapper for notification params
        class CORE_EXPORT JavascriptDialogOpeningNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(JavascriptDialogOpeningNotification);

        public:
            static std::unique_ptr<JavascriptDialogOpeningNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~JavascriptDialogOpeningNotification() override { }

            String getMessage() { return m_message; }
            void setMessage(const String& value) { m_message = value; }

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<JavascriptDialogOpeningNotification> clone() const;

            template <int STATE>
            class JavascriptDialogOpeningNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    MessageSet = 1 << 1,
                    TypeSet = 1 << 2,
                    AllFieldsSet = (MessageSet | TypeSet | 0)
                };

                JavascriptDialogOpeningNotificationBuilder<STATE | MessageSet>& setMessage(const String& value)
                {
                    static_assert(!(STATE & MessageSet), "property message should not be set yet");
                    m_result->setMessage(value);
                    return castState<MessageSet>();
                }

                JavascriptDialogOpeningNotificationBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                std::unique_ptr<JavascriptDialogOpeningNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class JavascriptDialogOpeningNotification;
                JavascriptDialogOpeningNotificationBuilder()
                    : m_result(new JavascriptDialogOpeningNotification())
                {
                }

                template <int STEP>
                JavascriptDialogOpeningNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<JavascriptDialogOpeningNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::JavascriptDialogOpeningNotification> m_result;
            };

            static JavascriptDialogOpeningNotificationBuilder<0> create()
            {
                return JavascriptDialogOpeningNotificationBuilder<0>();
            }

        private:
            JavascriptDialogOpeningNotification()
            {
            }

            String m_message;
            String m_type;
        };

        // Wrapper for notification params
        class CORE_EXPORT JavascriptDialogClosedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(JavascriptDialogClosedNotification);

        public:
            static std::unique_ptr<JavascriptDialogClosedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~JavascriptDialogClosedNotification() override { }

            bool getResult() { return m_result; }
            void setResult(bool value) { m_result = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<JavascriptDialogClosedNotification> clone() const;

            template <int STATE>
            class JavascriptDialogClosedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ResultSet = 1 << 1,
                    AllFieldsSet = (ResultSet | 0)
                };

                JavascriptDialogClosedNotificationBuilder<STATE | ResultSet>& setResult(bool value)
                {
                    static_assert(!(STATE & ResultSet), "property result should not be set yet");
                    m_result->setResult(value);
                    return castState<ResultSet>();
                }

                std::unique_ptr<JavascriptDialogClosedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class JavascriptDialogClosedNotification;
                JavascriptDialogClosedNotificationBuilder()
                    : m_result(new JavascriptDialogClosedNotification())
                {
                }

                template <int STEP>
                JavascriptDialogClosedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<JavascriptDialogClosedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::JavascriptDialogClosedNotification> m_result;
            };

            static JavascriptDialogClosedNotificationBuilder<0> create()
            {
                return JavascriptDialogClosedNotificationBuilder<0>();
            }

        private:
            JavascriptDialogClosedNotification()
            {
                m_result = false;
            }

            bool m_result;
        };

        // Wrapper for notification params
        class CORE_EXPORT ScreencastFrameNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ScreencastFrameNotification);

        public:
            static std::unique_ptr<ScreencastFrameNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ScreencastFrameNotification() override { }

            String getData() { return m_data; }
            void setData(const String& value) { m_data = value; }

            protocol::Page::ScreencastFrameMetadata* getMetadata() { return m_metadata.get(); }
            void setMetadata(std::unique_ptr<protocol::Page::ScreencastFrameMetadata> value) { m_metadata = std::move(value); }

            int getSessionId() { return m_sessionId; }
            void setSessionId(int value) { m_sessionId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ScreencastFrameNotification> clone() const;

            template <int STATE>
            class ScreencastFrameNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    DataSet = 1 << 1,
                    MetadataSet = 1 << 2,
                    SessionIdSet = 1 << 3,
                    AllFieldsSet = (DataSet | MetadataSet | SessionIdSet | 0)
                };

                ScreencastFrameNotificationBuilder<STATE | DataSet>& setData(const String& value)
                {
                    static_assert(!(STATE & DataSet), "property data should not be set yet");
                    m_result->setData(value);
                    return castState<DataSet>();
                }

                ScreencastFrameNotificationBuilder<STATE | MetadataSet>& setMetadata(std::unique_ptr<protocol::Page::ScreencastFrameMetadata> value)
                {
                    static_assert(!(STATE & MetadataSet), "property metadata should not be set yet");
                    m_result->setMetadata(std::move(value));
                    return castState<MetadataSet>();
                }

                ScreencastFrameNotificationBuilder<STATE | SessionIdSet>& setSessionId(int value)
                {
                    static_assert(!(STATE & SessionIdSet), "property sessionId should not be set yet");
                    m_result->setSessionId(value);
                    return castState<SessionIdSet>();
                }

                std::unique_ptr<ScreencastFrameNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ScreencastFrameNotification;
                ScreencastFrameNotificationBuilder()
                    : m_result(new ScreencastFrameNotification())
                {
                }

                template <int STEP>
                ScreencastFrameNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ScreencastFrameNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::ScreencastFrameNotification> m_result;
            };

            static ScreencastFrameNotificationBuilder<0> create()
            {
                return ScreencastFrameNotificationBuilder<0>();
            }

        private:
            ScreencastFrameNotification()
            {
                m_sessionId = 0;
            }

            String m_data;
            std::unique_ptr<protocol::Page::ScreencastFrameMetadata> m_metadata;
            int m_sessionId;
        };

        // Wrapper for notification params
        class CORE_EXPORT ScreencastVisibilityChangedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ScreencastVisibilityChangedNotification);

        public:
            static std::unique_ptr<ScreencastVisibilityChangedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ScreencastVisibilityChangedNotification() override { }

            bool getVisible() { return m_visible; }
            void setVisible(bool value) { m_visible = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ScreencastVisibilityChangedNotification> clone() const;

            template <int STATE>
            class ScreencastVisibilityChangedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    VisibleSet = 1 << 1,
                    AllFieldsSet = (VisibleSet | 0)
                };

                ScreencastVisibilityChangedNotificationBuilder<STATE | VisibleSet>& setVisible(bool value)
                {
                    static_assert(!(STATE & VisibleSet), "property visible should not be set yet");
                    m_result->setVisible(value);
                    return castState<VisibleSet>();
                }

                std::unique_ptr<ScreencastVisibilityChangedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ScreencastVisibilityChangedNotification;
                ScreencastVisibilityChangedNotificationBuilder()
                    : m_result(new ScreencastVisibilityChangedNotification())
                {
                }

                template <int STEP>
                ScreencastVisibilityChangedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ScreencastVisibilityChangedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::ScreencastVisibilityChangedNotification> m_result;
            };

            static ScreencastVisibilityChangedNotificationBuilder<0> create()
            {
                return ScreencastVisibilityChangedNotificationBuilder<0>();
            }

        private:
            ScreencastVisibilityChangedNotification()
            {
                m_visible = false;
            }

            bool m_visible;
        };

        // Wrapper for notification params
        class CORE_EXPORT ColorPickedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ColorPickedNotification);

        public:
            static std::unique_ptr<ColorPickedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ColorPickedNotification() override { }

            protocol::DOM::RGBA* getColor() { return m_color.get(); }
            void setColor(std::unique_ptr<protocol::DOM::RGBA> value) { m_color = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ColorPickedNotification> clone() const;

            template <int STATE>
            class ColorPickedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ColorSet = 1 << 1,
                    AllFieldsSet = (ColorSet | 0)
                };

                ColorPickedNotificationBuilder<STATE | ColorSet>& setColor(std::unique_ptr<protocol::DOM::RGBA> value)
                {
                    static_assert(!(STATE & ColorSet), "property color should not be set yet");
                    m_result->setColor(std::move(value));
                    return castState<ColorSet>();
                }

                std::unique_ptr<ColorPickedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ColorPickedNotification;
                ColorPickedNotificationBuilder()
                    : m_result(new ColorPickedNotification())
                {
                }

                template <int STEP>
                ColorPickedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ColorPickedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::ColorPickedNotification> m_result;
            };

            static ColorPickedNotificationBuilder<0> create()
            {
                return ColorPickedNotificationBuilder<0>();
            }

        private:
            ColorPickedNotification()
            {
            }

            std::unique_ptr<protocol::DOM::RGBA> m_color;
        };

        // Wrapper for notification params
        class CORE_EXPORT NavigationRequestedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(NavigationRequestedNotification);

        public:
            static std::unique_ptr<NavigationRequestedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~NavigationRequestedNotification() override { }

            bool getIsInMainFrame() { return m_isInMainFrame; }
            void setIsInMainFrame(bool value) { m_isInMainFrame = value; }

            bool getIsRedirect() { return m_isRedirect; }
            void setIsRedirect(bool value) { m_isRedirect = value; }

            int getNavigationId() { return m_navigationId; }
            void setNavigationId(int value) { m_navigationId = value; }

            String getUrl() { return m_url; }
            void setUrl(const String& value) { m_url = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<NavigationRequestedNotification> clone() const;

            template <int STATE>
            class NavigationRequestedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    IsInMainFrameSet = 1 << 1,
                    IsRedirectSet = 1 << 2,
                    NavigationIdSet = 1 << 3,
                    UrlSet = 1 << 4,
                    AllFieldsSet = (IsInMainFrameSet | IsRedirectSet | NavigationIdSet | UrlSet | 0)
                };

                NavigationRequestedNotificationBuilder<STATE | IsInMainFrameSet>& setIsInMainFrame(bool value)
                {
                    static_assert(!(STATE & IsInMainFrameSet), "property isInMainFrame should not be set yet");
                    m_result->setIsInMainFrame(value);
                    return castState<IsInMainFrameSet>();
                }

                NavigationRequestedNotificationBuilder<STATE | IsRedirectSet>& setIsRedirect(bool value)
                {
                    static_assert(!(STATE & IsRedirectSet), "property isRedirect should not be set yet");
                    m_result->setIsRedirect(value);
                    return castState<IsRedirectSet>();
                }

                NavigationRequestedNotificationBuilder<STATE | NavigationIdSet>& setNavigationId(int value)
                {
                    static_assert(!(STATE & NavigationIdSet), "property navigationId should not be set yet");
                    m_result->setNavigationId(value);
                    return castState<NavigationIdSet>();
                }

                NavigationRequestedNotificationBuilder<STATE | UrlSet>& setUrl(const String& value)
                {
                    static_assert(!(STATE & UrlSet), "property url should not be set yet");
                    m_result->setUrl(value);
                    return castState<UrlSet>();
                }

                std::unique_ptr<NavigationRequestedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class NavigationRequestedNotification;
                NavigationRequestedNotificationBuilder()
                    : m_result(new NavigationRequestedNotification())
                {
                }

                template <int STEP>
                NavigationRequestedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<NavigationRequestedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Page::NavigationRequestedNotification> m_result;
            };

            static NavigationRequestedNotificationBuilder<0> create()
            {
                return NavigationRequestedNotificationBuilder<0>();
            }

        private:
            NavigationRequestedNotification()
            {
                m_isInMainFrame = false;
                m_isRedirect = false;
                m_navigationId = 0;
            }

            bool m_isInMainFrame;
            bool m_isRedirect;
            int m_navigationId;
            String m_url;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse enable() = 0;
            virtual DispatchResponse disable() = 0;
            virtual DispatchResponse addScriptToEvaluateOnLoad(const String& in_scriptSource, String* out_identifier) = 0;
            virtual DispatchResponse removeScriptToEvaluateOnLoad(const String& in_identifier) = 0;
            virtual DispatchResponse setAutoAttachToCreatedPages(bool in_autoAttach) = 0;
            virtual DispatchResponse reload(Maybe<bool> in_ignoreCache, Maybe<String> in_scriptToEvaluateOnLoad) = 0;
            virtual DispatchResponse navigate(const String& in_url, String* out_frameId) = 0;
            virtual DispatchResponse stopLoading() = 0;
            virtual DispatchResponse getResourceTree(std::unique_ptr<protocol::Page::FrameResourceTree>* out_frameTree) = 0;
            class CORE_EXPORT GetResourceContentCallback {
            public:
                virtual void sendSuccess(const String& content, bool base64Encoded) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~GetResourceContentCallback() { }
            };
            virtual void getResourceContent(const String& in_frameId, const String& in_url, std::unique_ptr<GetResourceContentCallback> callback) = 0;
            class CORE_EXPORT SearchInResourceCallback {
            public:
                virtual void sendSuccess(std::unique_ptr<protocol::Array<v8_inspector::protocol::Debugger::API::SearchMatch>> result) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~SearchInResourceCallback() { }
            };
            virtual void searchInResource(const String& in_frameId, const String& in_url, const String& in_query, Maybe<bool> in_caseSensitive, Maybe<bool> in_isRegex, std::unique_ptr<SearchInResourceCallback> callback) = 0;
            virtual DispatchResponse setDocumentContent(const String& in_frameId, const String& in_html) = 0;
            virtual DispatchResponse startScreencast(Maybe<String> in_format, Maybe<int> in_quality, Maybe<int> in_maxWidth, Maybe<int> in_maxHeight, Maybe<int> in_everyNthFrame) = 0;
            virtual DispatchResponse stopScreencast() = 0;
            virtual DispatchResponse configureOverlay(Maybe<bool> in_suspended, Maybe<String> in_message) = 0;
            virtual DispatchResponse getLayoutMetrics(std::unique_ptr<protocol::Page::LayoutViewport>* out_layoutViewport, std::unique_ptr<protocol::Page::VisualViewport>* out_visualViewport) = 0;
        };

        // ------------- Frontend interface.

        class CORE_EXPORT Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }
            void domContentEventFired(double timestamp);
            void loadEventFired(double timestamp);
            void frameAttached(const String& frameId, const String& parentFrameId);
            void frameNavigated(std::unique_ptr<protocol::Page::Frame> frame);
            void frameDetached(const String& frameId);
            void frameStartedLoading(const String& frameId);
            void frameStoppedLoading(const String& frameId);
            void frameScheduledNavigation(const String& frameId, double delay);
            void frameClearedScheduledNavigation(const String& frameId);
            void frameResized();
            void javascriptDialogOpening(const String& message, const String& type);
            void javascriptDialogClosed(bool result);

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

    } // namespace Page
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Page_h)
