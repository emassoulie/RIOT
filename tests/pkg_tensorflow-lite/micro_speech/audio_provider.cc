/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

/*periph_pdm deals with the pdm microphone as follows:
while (1) {
        msg_t msg;
        msg_receive(&msg);
        int16_t *buf = (int16_t *)msg.content.ptr;
#if PDM_DATA_PRINT_BINARY
        stdio_write((uint8_t *)buf, PDM_BUF_SIZE >> 2);
#else
        for (unsigned idx = 0; idx < PDM_BUF_SIZE; ++idx) {
            printf("%i\n", buf[idx]);
        }
#endif
    }

    return 0;
*/

#include "tensorflow/lite/micro/examples/micro_speech/audio_provider.h"

#include "tensorflow/lite/micro/examples/micro_speech/micro_features/micro_model_settings.h"

namespace {
int16_t g_dummy_audio_data[kMaxAudioSampleSize];
int32_t g_latest_audio_timestamp = 0;
}  // namespace

TfLiteStatus GetAudioSamples(tflite::ErrorReporter* error_reporter,
                             int start_ms, int duration_ms,
                             int* audio_samples_size, int16_t** audio_samples) {
  for (int i = 0; i < kMaxAudioSampleSize; ++i) {
    g_dummy_audio_data[i] = 0;
  }
  *audio_samples_size = kMaxAudioSampleSize;
  *audio_samples = g_dummy_audio_data;
  return kTfLiteOk;
}

int32_t LatestAudioTimestamp() {
  g_latest_audio_timestamp += 100;
  return g_latest_audio_timestamp;
}
