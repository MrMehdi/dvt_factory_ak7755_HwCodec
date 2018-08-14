##
## utility/jpeg_encoder/make.inc
##
## History:
##    2015/09/18 - [zfgong] Created file
##
## Copyright (c) 2016 Ambarella, Inc.
##
## This file and its contents ("Software") are protected by intellectual
## property rights including, without limitation, U.S. and/or foreign
## copyrights. This Software is also the confidential and proprietary
## information of Ambarella, Inc. and its licensors. You may not use, reproduce,
## disclose, distribute, modify, or otherwise prepare derivative works of this
## Software or any portion thereof except pursuant to a signed license agreement
## or nondisclosure agreement with Ambarella, Inc. or its authorized affiliates.
## In the absence of such an agreement, you agree to promptly notify and return
## this Software to Ambarella, Inc.
##
## THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
## INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF NON-INFRINGEMENT,
## MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
## IN NO EVENT SHALL AMBARELLA, INC. OR ITS AFFILIATES BE LIABLE FOR ANY DIRECT,
## INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS; COMPUTER FAILURE OR MALFUNCTION; OR BUSINESS
## INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
## CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
## ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
## POSSIBILITY OF SUCH DAMAGE.
##

LOCAL_PATH   := $(call my-dir)

## libamjpeg-encoder.so
ifeq ($(BUILD_AMBARELLA_ORYX_JPEG_ENCODER), y)

include $(CLEAR_VARS)

JPEG_ENCODER_VER_FILE   = $(ORYX_DIR)/include/utility/jpeg_encoder/version.h
JPEG_ENCODER_VER_PREFIX = JPEG_ENCODER

JPEG_ENCODER_TARGET  = libamjpeg-encoder.so
LOCAL_TARGET := $(JPEG_ENCODER_TARGET)
LOCAL_SRCS    := $(LOCAL_PATH)/am_jpeg_encoder.cpp \
                 $(LOCAL_PATH)/chroma_convert.S

LOCAL_LDFLAGS := -L$(PREBUILD_3RD_PARTY_DIR)/libjpeg-turbo/usr/lib -ljpeg \
		 -L$(PREBUILD_3RD_PARTY_DIR)/libjpeg-turbo/usr/lib -lturbojpeg

LOCAL_CFLAGS := -I$(ORYX_DIR)/include                             \
                -I$(ORYX_DIR)/include/utility                     \
                -I$(ORYX_DIR)/utility/include                     \
                -I$(ORYX_DIR)/include/utility/jpeg_encoder         \
                -I$(PREBUILD_3RD_PARTY_DIR)/libjpeg-turbo/include \
                -fvisibility=hidden -std=c++11 -Werror

LOCAL_LIBS := libamutil.so

JPEG_ENCODER_SO_VER_MAJOR  := $(shell awk '/define\ $(JPEG_ENCODER_VER_PREFIX)_LIB_MAJOR/{print $$3}' $(JPEG_ENCODER_VER_FILE))
JPEG_ENCODER_SO_VER_MINOR  := $(shell awk '/define\ $(JPEG_ENCODER_VER_PREFIX)_LIB_MINOR/{print $$3}' $(JPEG_ENCODER_VER_FILE))
JPEG_ENCODER_SO_VER_PATCH  := $(shell awk '/define\ $(JPEG_ENCODER_VER_PREFIX)_LIB_PATCH/{print $$3}' $(JPEG_ENCODER_VER_FILE))
JPEG_ENCODER_SO_VER_STRING := $(JPEG_ENCODER_SO_VER_MAJOR).$(JPEG_ENCODER_SO_VER_MINOR).$(JPEG_ENCODER_SO_VER_PATCH)

JPEG_ENCODER_SO_NAME   = $(patsubst %.so,%.so.$(JPEG_ENCODER_SO_VER_MAJOR), $(JPEG_ENCODER_TARGET))
JPEG_ENCODER_SO_TARGET = $(patsubst %.so,%.so.$(JPEG_ENCODER_SO_VER_STRING), $(JPEG_ENCODER_TARGET))

LOCAL_SO_NAME := $(JPEG_ENCODER_SO_NAME)

include $(BUILD_APP)

.PHONY: $(LOCAL_TARGET)

$(LOCAL_TARGET): $(LOCAL_MODULE)
	@mkdir -p $(ORYX_LIB_DIR)/
	@cp -dpRf $< $(ORYX_LIB_DIR)/$(JPEG_ENCODER_SO_TARGET)
	@ln -sf $(JPEG_ENCODER_SO_TARGET) $(ORYX_LIB_DIR)/$(JPEG_ENCODER_SO_NAME)
	@echo "Build $@ Done."

$(call add-target-into-build, $(LOCAL_TARGET))

endif
