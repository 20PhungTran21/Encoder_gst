#include "encoder_gst.h"
#include <stdio.h>
#include <stdlib.h>

int encoder_init(EncoderContext *ctx, EncoderBackend backend, int width, int height, int use_hw_accel) {
    // Dummy implementation
    printf("encoder_init called\n");
    return 0;
}

int encoder_encode_frame(EncoderContext *ctx, const uint8_t *frame_data, int frame_size) {
    // Dummy implementation
    printf("encoder_encode_frame called\n");
    return 0;
}

int encoder_get_packet(EncoderContext *ctx, uint8_t **packet, int *packet_size) {
    // Dummy implementation
    printf("encoder_get_packet called\n");
    *packet = NULL;
    *packet_size = 0;
    return 0;
}

void encoder_release(EncoderContext *ctx) {
    // Dummy implementation
    printf("encoder_release called\n");
}