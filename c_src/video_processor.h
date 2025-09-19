#ifndef VIDEO_PROCESSOR_H
#define VIDEO_PROCESSOR_H

#include <stdint.h>

// ==== Định nghĩa cho backend encoder ====
typedef enum {
    ENCODER_BACKEND_FFMPEG,
    ENCODER_BACKEND_GSTREAMER
} EncoderBackend;

typedef struct {
    EncoderBackend backend;
    void *encoder_ctx;
} EncoderContext;

typedef struct {
    EncoderContext encoder;
    // Thêm các trường khác nếu cần
} VideoProcessorContext;

int video_processor_init(VideoProcessorContext *ctx, EncoderBackend backend, int width, int height, int use_hw_accel);
int video_processor_process_frame(VideoProcessorContext *ctx, const uint8_t *frame_data, int frame_size);
int video_processor_get_packet(VideoProcessorContext *ctx, uint8_t **packet, int *packet_size);
void video_processor_release(VideoProcessorContext *ctx);

#endif // VIDEO_PROCESSOR_H