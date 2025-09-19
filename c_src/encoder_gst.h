#ifndef ENCODER_H
#define ENCODER_H

#include "video_processor.h"

int encoder_init(EncoderContext *ctx, EncoderBackend backend, int width, int height, int use_hw_accel);
int encoder_encode_frame(EncoderContext *ctx, const uint8_t *frame_data, int frame_size);
int encoder_get_packet(EncoderContext *ctx, uint8_t **packet, int *packet_size);
void encoder_release(EncoderContext *ctx);

#endif // ENCODER_H