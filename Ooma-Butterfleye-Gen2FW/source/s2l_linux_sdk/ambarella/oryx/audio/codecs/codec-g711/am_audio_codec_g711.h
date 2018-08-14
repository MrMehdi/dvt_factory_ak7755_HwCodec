/*******************************************************************************
 * am_audio_codec_g711.h
 *
 * History:
 *   2015-1-28 - [ypchang] created file
 *
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
 *
 ******************************************************************************/
#ifndef ORYX_STREAM_COMMON_CODECS_CODEC_G711_AM_AUDIO_CODEC_G711_H_
#define ORYX_STREAM_COMMON_CODECS_CODEC_G711_AM_AUDIO_CODEC_G711_H_

class AMAudioCodecG711Config;
struct AudioCodecG711Config;
struct g711_state_s;

class AMAudioCodecG711: public AMAudioCodec
{
    typedef AMAudioCodec inherited;

  public:
    static AMIAudioCodec* create(const char *config);

  public:
    virtual void destroy();
    virtual bool initialize(AM_AUDIO_INFO *srcAudioInfo,
                            AM_AUDIO_CODEC_MODE mode);
    virtual bool finalize();
    virtual AM_AUDIO_INFO* get_codec_audio_info();
    virtual uint32_t get_codec_output_size();
    virtual bool check_encode_src_parameter(AM_AUDIO_INFO &info);
    virtual uint32_t get_encode_required_chunk_size(AM_AUDIO_INFO &info);
    /* encode: return generated bytes,
     * generated data size is also stored in out_data_size
     */
    virtual uint32_t encode(uint8_t *input,  uint32_t in_data_size,
                            uint8_t *output, uint32_t *out_data_size);
    /* decode: return consumed bytes,
     * generated data size is stored in out_data_size
     */
    virtual uint32_t decode(uint8_t *input,  uint32_t in_data_size,
                            uint8_t *output, uint32_t *out_data_size);

  protected:
    AMAudioCodecG711();
    virtual ~AMAudioCodecG711();
    bool init(const char *config);

  private:
    AudioCodecG711Config   *m_g711_config; /* No need to delete */
    AMAudioCodecG711Config *m_config;
    g711_state_s           *m_g711_state;
};

#endif /* ORYX_STREAM_COMMON_CODECS_CODEC_G711_AM_AUDIO_CODEC_G711_H_ */