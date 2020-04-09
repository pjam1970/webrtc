/*
 *  Copyright 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include <jni.h>

#include "modules/video_coding/codecs/h264/include/h264.h"
#include "sdk/android/generated_libvpx_h264_jni/jni/LibvpxH264Decoder_jni.h"
#include "sdk/android/generated_libvpx_h264_jni/jni/LibvpxH264Encoder_jni.h"
#include "sdk/android/src/jni/jni_helpers.h"

namespace webrtc {
namespace jni {

static jlong JNI_LibvpxH264Encoder_CreateEncoder(JNIEnv* jni) {
  return jlongFromPointer(H264Encoder::Create(cricket::VideoCodec(cricket::kH264CodecName)).release());
}

static jlong JNI_LibvpxH264Decoder_CreateDecoder(JNIEnv* jni) {
  return jlongFromPointer(H264Decoder::Create().release());
}

}  // namespace jni
}  // namespace webrtc

/*
// --- Not sure if we need `cricket::VideoCodec(96, "")` or not
#include <jni.h>

#include "modules/video_coding/codecs/h264/include/h264.h"
#include "sdk/android/generated_libvpx_h264_jni/jni/LibvpxH264Decoder_jni.h"
#include "sdk/android/generated_libvpx_h264_jni/jni/LibvpxH264Encoder_jni.h"
#include "sdk/android/src/jni/jni_helpers.h"

namespace webrtc {
namespace jni {

static jlong JNI_LibvpxH264Encoder_CreateEncoder(JNIEnv* jni) {
  return jlongFromPointer(H264Encoder::Create(cricket::VideoCodec(96, "")).release());
}

static jlong JNI_LibvpxH264Decoder_CreateDecoder(JNIEnv* jni) {
  return jlongFromPointer(H264Decoder::Create().release());
}

}  // namespace jni
}  // namespace webrtc
*/
