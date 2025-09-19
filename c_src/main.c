#include "video_processor.h"
#include "encoder_gst.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Include file video_processor.c đã viết ở trên

int main(int argc, char *argv[]) {
    // Chọn backend qua tham số dòng lệnh
    EncoderBackend backend = ENCODER_BACKEND_GSTREAMER;
    if (argc > 1 && strcmp(argv[1], "ffmpeg") == 0) {
        backend = ENCODER_BACKEND_FFMPEG;
    }

    int width = 1280, height = 720, use_hw = 1;
    VideoProcessorContext vp_ctx;

    if (video_processor_init(&vp_ctx, backend, width, height, use_hw) != 0) {
        printf("Init failed\n");
        return -1;
    }

    // Giả lập frame dữ liệu (YUV420P)
    int frame_size = width * height * 3 / 2;
    uint8_t *frame_data = calloc(1, frame_size);

    // Encode thử 1 frame
    video_processor_process_frame(&vp_ctx, frame_data, frame_size);

    // Lấy packet kết quả (giả lập)
    uint8_t *packet = NULL;
    int packet_size = 0;
    video_processor_get_packet(&vp_ctx, &packet, &packet_size);

    printf("Packet size: %d\n", packet_size);

    free(frame_data);
    video_processor_release(&vp_ctx);
    return 0;
}