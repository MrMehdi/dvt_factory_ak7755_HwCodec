##
## app/ipcam/http_uploader/make.inc
##
## History:
##    2014/12/03 - [Chu Chen] Created file
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

ifeq ($(BUILD_AMBARELLA_APP_HTTP_UPLOADER), y)

LOCAL_PATH   := $(call my-dir)
include $(CLEAR_VARS)

IPCAM_APP_BIN_DIR	= $(FAKEROOT_DIR)/usr/bin

LOCAL_TARGET	:= http_uploader
LOCAL_SRCS	:= $(LOCAL_PATH)/http_uploader.c
LOCAL_CFLAGS	:= -I$(PREBUILD_3RD_PARTY_DIR)/libcurl/include
LOCAL_LDFLAGS	:= -L$(PREBUILD_3RD_PARTY_DIR)/libcurl/usr/lib -lcurl \
                -L$(PREBUILD_3RD_PARTY_DIR)/zlib/usr/lib -lz \
                -L$(PREBUILD_3RD_PARTY_DIR)/openssl/usr/lib -lssl -lcrypto \
                -L$(PREBUILD_3RD_PARTY_DIR)/libssh2/usr/lib -lssh2 \
                -L$(PREBUILD_3RD_PARTY_DIR)/libidn/usr/lib -lidn

include $(BUILD_APP)

.PHONY: $(LOCAL_TARGET)

$(LOCAL_TARGET): $(LOCAL_MODULE)
	@mkdir -p $(IPCAM_APP_BIN_DIR)/
	@cp -dpRf $< $(IPCAM_APP_BIN_DIR)/
	@echo "Build $@ Done."

$(call add-target-into-build, $(LOCAL_TARGET))

###
endif
