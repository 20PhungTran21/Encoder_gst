
#include "video_processor.h"
#include "encoder_gst.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int video_processor_init(VideoProcessorContext *ctx, EncoderBackend backend, int width, int height, int use_hw_accel) {
    memset(ctx, 0, sizeof(VideoProcessorContext));
    return encoder_init(&ctx->encoder, backend, width, height, use_hw_accel);
}

int video_processor_process_frame(VideoProcessorContext *ctx, const uint8_t *frame_data, int frame_size) {
    // Xử lý frame (decode, filter, ...) nếu cần
    // Ở đây chỉ encode luôn
    return encoder_encode_frame(&ctx->encoder, frame_data, frame_size);
}

int video_processor_get_packet(VideoProcessorContext *ctx, uint8_t **packet, int *packet_size) {
    return encoder_get_packet(&ctx->encoder, packet, packet_size);
}

void video_processor_release(VideoProcessorContext *ctx) {
    encoder_release(&ctx->encoder);
    // Giải phóng các thành phần khác nếu có
}