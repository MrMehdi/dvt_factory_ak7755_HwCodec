/*
 * am_muxer_ts_normal.h
 *
 * 11/09/2012 [Hanbo Xiao] [Created]
 * 28/03/2016 [Chengcai Jing] [Modified]
 * Copyright (c) 2016 Ambarella, Inc.
 *
 * This file and its contents ("Software") are protected by intellectual
 * property rights including, without limitation, U.S. and/or foreign
 * copyrights. This Software is also the confidential and proprietary
 * information of Ambarella, Inc. and its licensors. You may not use, reproduce,
 * disclose, distribute, modify, or otherwise prepare derivative works of this
 * Software or any portion thereof except pursuant to a signed license agreement
 * or nondisclosure agreement with Ambarella, Inc. or its authorized affiliates.
 * In the absence of such an agreement, you agree to promptly notify and return
 * this Software to Ambarella, Inc.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF NON-INFRINGEMENT,
 * MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL AMBARELLA, INC. OR ITS AFFILIATES BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; COMPUTER FAILURE OR MALFUNCTION; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __AM_MUXER_TS_NORMAL_H__
#define __AM_MUXER_TS_NORMAL_H__

#include "am_muxer_ts_base.h"

class AMTsMuxerNormal : public AMTsMuxerBase
{
    typedef AMTsMuxerBase inherited;
  public:
    static AMIMuxerCodec *create(const char* config_file);
    virtual bool start_file_writing();
    virtual AM_MUXER_CODEC_ATTR get_muxer_attr();
    virtual void feed_data(AMPacket* packet);
  private:
    AMTsMuxerNormal();
    AM_STATE init(const char* config_file);
    virtual ~AMTsMuxerNormal();
    virtual AM_STATE generate_file_name(std::string &file_name);
    virtual AM_STATE on_info_packet(AMPacket* packet);
    virtual AM_STATE on_data_packet(AMPacket* packet);
    virtual void clear_params_for_new_file();
    virtual void main_loop();
};

#endif