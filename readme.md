# encoder_gst - GStreamer Encoder cho RK3566

## Mục tiêu
- Hỗ trợ encode H.264 bằng GStreamer, sử dụng CPU hoặc HW accel (RK3566).
- API tương thích với encoder cũ.

## Sử dụng
```c
EncoderGstContext ctx;
encoder_gst_init(&ctx, 1280, 720, 30, 1); // 1: dùng HW, 0: dùng CPU
encoder_gst_encode(&ctx, frame, frame_size, &out_packet, &out_size);
// Xử lý out_packet
encoder_gst_release(&ctx);