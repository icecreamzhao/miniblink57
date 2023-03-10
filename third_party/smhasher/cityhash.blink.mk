# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := third_party_smhasher_cityhash_gyp
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_TARGET_ARCH := $(TARGET_$(GYP_VAR_PREFIX)ARCH)
gyp_intermediate_dir := $(call local-intermediates-dir,,$(GYP_VAR_PREFIX))
gyp_shared_intermediate_dir := gen#//$(call intermediates-dir-for,GYP,shared,,,$(GYP_VAR_PREFIX))

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES :=

GYP_GENERATED_OUTPUTS :=

# Make sure our deps and generated files are built first.
#//LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

LOCAL_GENERATED_SOURCES :=

GYP_COPIED_SOURCE_ORIGIN_DIRS :=

LOCAL_SRC_FILES := \
	third_party/smhasher/src/City.cpp


# Flags passed to both C and C++ files.
MY_CFLAGS_Debug := \
	-fstack-protector \
	--param=ssp-buffer-size=4 \
	-fno-exceptions \
	-fno-strict-aliasing \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-Wno-format \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fstack-protector \
	-fno-short-enums \
	-Wa,--noexecstack \
	-U_FORTIFY_SOURCE \
	-Wno-extra \
	-Wno-ignored-qualifiers \
	-Wno-type-limits \
	-Wno-address \
	-Wno-format-security \
	-Wno-return-type \
	-Wno-sequence-point \
	-Os \
	-g \
	-fdata-sections \
	-ffunction-sections \
	-fomit-frame-pointer \
	-funwind-tables

MY_DEFS_Debug := \
	'-DTENCENT_FITSCREEN=1' \
	'-DTENCENT_CHANGES_SPDY=1' \
	'-DTENCENT_CHANGES_HTTP_PROXY=1' \
	'-DTENCENT_CHANGES_QPROXY=1' \
	'-DTENCENT_CHANGES_SOCKET=1' \
	'-DTENCENT_12306_TICKET=1' \
	'-DTENCENT_ALIPAY_USERAGENT=1' \
	'-DTENCENT_CHANGES_PRECONNECT=1' \
	'-DTENCENT_CHANGES_LBS=1' \
	'-DTENCENT_SECURITY_CHECK=1' \
	'-DTENCENT_CHANGES=1' \
	'-DTENCENT_CHANGES_REPORT=1' \
	'-DTENCENT_CHANGES_MISSING_TILES_OPT=1' \
	'-DTENCENT_AD_FILTER=1' \
	'-DTENCENT_CHANGES_DOWNLOAD_GARBLED=1' \
	'-DTENCENT_SAVE_FLOW_NOTIFICATION=1' \
	'-DTENCENT_CHANGES_ERROR_PAGE=1' \
	'-DTENCENT_CHANGES_WML=1' \
	'-DENABLE_WML=1' \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DBLINK_SCALE_FILTERS_AT_RECORD_TIME' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_LIBJPEG_TURBO=1' \
	'-DENABLE_WEBRTC=1' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_BROWSER_CDMS' \
	'-DENABLE_CONFIGURATION_POLICY' \
	'-DDISCARDABLE_MEMORY_ALWAYS_SUPPORTED_NATIVELY' \
	'-DSYSTEM_NATIVELY_SIGNALS_MEMORY_PRESSURE' \
	'-DENABLE_EGLIMAGE=1' \
	'-DCLD_VERSION=1' \
	'-DENABLE_PRINTING=1' \
	'-DENABLE_MANAGED_USERS=1' \
	'-DDATA_REDUCTION_FALLBACK_HOST="http://compress.googlezip.net:80/"' \
	'-DDATA_REDUCTION_DEV_HOST="http://proxy-dev.googlezip.net:80/"' \
	'-DSPDY_PROXY_AUTH_ORIGIN="https://proxy.googlezip.net:443/"' \
	'-DDATA_REDUCTION_PROXY_PROBE_URL="http://check.googlezip.net/connect"' \
	'-DDATA_REDUCTION_PROXY_WARMUP_URL="http://www.gstatic.com/generate_204"' \
	'-DVIDEO_HOLE=1' \
	'-DUSE_OPENSSL=1' \
	'-DUSE_OPENSSL_CERTS=1' \
	'-DANDROID' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DCHROME_BUILD_ID=""' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=1' \
	'-DWTF_USE_DYNAMIC_ANNOTATIONS=1' \
	'-D_DEBUG'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Debug := \
	$(LOCAL_PATH)/$(gyp_shared_intermediate_dir) \
	$(PWD)/frameworks/wilhelm/include \
	$(PWD)/bionic \
	$(NDK_ROOT)sources/cxx-stl/stlport/stlport


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Debug := \
	-fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wno-deprecated \
	-Wno-abi \
	-Wno-non-virtual-dtor \
	-Wno-sign-promo \
	-std=c++11 \
	-std=gnu++11 \
	-Wno-non-virtual-dtor


LOCAL_FDO_SUPPORT_Debug := false

# Flags passed to both C and C++ files.
MY_CFLAGS_Release := \
	-fstack-protector \
	--param=ssp-buffer-size=4 \
	-fno-exceptions \
	-fno-strict-aliasing \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-Wno-format \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fstack-protector \
	-fno-short-enums \
	-Wa,--noexecstack \
	-U_FORTIFY_SOURCE \
	-Wno-extra \
	-Wno-ignored-qualifiers \
	-Wno-type-limits \
	-Wno-address \
	-Wno-format-security \
	-Wno-return-type \
	-Wno-sequence-point \
	-Os \
	-fdata-sections \
	-ffunction-sections \
	-fomit-frame-pointer \
	-funwind-tables

MY_DEFS_Release := \
	'-DTENCENT_FITSCREEN=1' \
	'-DTENCENT_CHANGES_SPDY=1' \
	'-DTENCENT_CHANGES_HTTP_PROXY=1' \
	'-DTENCENT_CHANGES_QPROXY=1' \
	'-DTENCENT_CHANGES_SOCKET=1' \
	'-DTENCENT_12306_TICKET=1' \
	'-DTENCENT_ALIPAY_USERAGENT=1' \
	'-DTENCENT_CHANGES_PRECONNECT=1' \
	'-DTENCENT_CHANGES_LBS=1' \
	'-DTENCENT_SECURITY_CHECK=1' \
	'-DTENCENT_CHANGES=1' \
	'-DTENCENT_CHANGES_REPORT=1' \
	'-DTENCENT_CHANGES_MISSING_TILES_OPT=1' \
	'-DTENCENT_AD_FILTER=1' \
	'-DTENCENT_CHANGES_DOWNLOAD_GARBLED=1' \
	'-DTENCENT_SAVE_FLOW_NOTIFICATION=1' \
	'-DTENCENT_CHANGES_ERROR_PAGE=1' \
	'-DTENCENT_CHANGES_WML=1' \
	'-DENABLE_WML=1' \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DBLINK_SCALE_FILTERS_AT_RECORD_TIME' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_LIBJPEG_TURBO=1' \
	'-DENABLE_WEBRTC=1' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_BROWSER_CDMS' \
	'-DENABLE_CONFIGURATION_POLICY' \
	'-DDISCARDABLE_MEMORY_ALWAYS_SUPPORTED_NATIVELY' \
	'-DSYSTEM_NATIVELY_SIGNALS_MEMORY_PRESSURE' \
	'-DENABLE_EGLIMAGE=1' \
	'-DCLD_VERSION=1' \
	'-DENABLE_PRINTING=1' \
	'-DENABLE_MANAGED_USERS=1' \
	'-DDATA_REDUCTION_FALLBACK_HOST="http://compress.googlezip.net:80/"' \
	'-DDATA_REDUCTION_DEV_HOST="http://proxy-dev.googlezip.net:80/"' \
	'-DSPDY_PROXY_AUTH_ORIGIN="https://proxy.googlezip.net:443/"' \
	'-DDATA_REDUCTION_PROXY_PROBE_URL="http://check.googlezip.net/connect"' \
	'-DDATA_REDUCTION_PROXY_WARMUP_URL="http://www.gstatic.com/generate_204"' \
	'-DVIDEO_HOLE=1' \
	'-DUSE_OPENSSL=1' \
	'-DUSE_OPENSSL_CERTS=1' \
	'-DANDROID' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DCHROME_BUILD_ID=""' \
	'-DNDEBUG' \
	'-DNVALGRIND' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=0'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Release := \
	$(LOCAL_PATH)/$(gyp_shared_intermediate_dir) \
	$(PWD)/frameworks/wilhelm/include \
	$(PWD)/bionic \
	$(NDK_ROOT)sources/cxx-stl/stlport/stlport


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Release := \
	-fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wno-deprecated \
	-Wno-abi \
	-Wno-non-virtual-dtor \
	-Wno-sign-promo \
	-std=c++11 \
	-std=gnu++11 \
	-Wno-non-virtual-dtor


LOCAL_FDO_SUPPORT_Release := false

LOCAL_CFLAGS := $(MY_CFLAGS_$(GYP_CONFIGURATION)) $(MY_DEFS_$(GYP_CONFIGURATION))
LOCAL_FDO_SUPPORT := $(LOCAL_FDO_SUPPORT_$(GYP_CONFIGURATION))
LOCAL_C_INCLUDES := $(GYP_COPIED_SOURCE_ORIGIN_DIRS) $(LOCAL_C_INCLUDES_$(GYP_CONFIGURATION))
LOCAL_CPPFLAGS := $(LOCAL_CPPFLAGS_$(GYP_CONFIGURATION))
LOCAL_ASFLAGS := $(LOCAL_CFLAGS)
### Rules for final target.

LOCAL_LDFLAGS_Debug := \
	-Wl,-z,now \
	-Wl,-z,relro \
	-Wl,--fatal-warnings \
	-Wl,-z,noexecstack \
	-fPIC \
	-Wl,-z,relro \
	-Wl,-z,now \
	-fuse-ld=gold \
	-nostdlib \
	-Wl,--no-undefined \
	-Wl,--exclude-libs=ALL \
	-Wl,--icf=safe \
	-Wl,--warn-shared-textrel \
	-Wl,-O1 \
	-Wl,--as-needed


LOCAL_LDFLAGS_Release := \
	-Wl,-z,now \
	-Wl,-z,relro \
	-Wl,--fatal-warnings \
	-Wl,-z,noexecstack \
	-fPIC \
	-Wl,-z,relro \
	-Wl,-z,now \
	-fuse-ld=gold \
	-nostdlib \
	-Wl,--no-undefined \
	-Wl,--exclude-libs=ALL \
	-Wl,--icf=safe \
	-Wl,-O1 \
	-Wl,--as-needed \
	-Wl,--gc-sections \
	-Wl,--warn-shared-textrel


LOCAL_LDFLAGS := $(LOCAL_LDFLAGS_$(GYP_CONFIGURATION))

LOCAL_STATIC_LIBRARIES :=

# Enable grouping to fix circular references
LOCAL_GROUP_STATIC_LIBRARIES := true

LOCAL_SHARED_LIBRARIES := \
	libstlport \
	libdl

# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: third_party_smhasher_cityhash_gyp

# Alias gyp target name.
.PHONY: cityhash
cityhash: third_party_smhasher_cityhash_gyp

include $(BUILD_STATIC_LIBRARY)
