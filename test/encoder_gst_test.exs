defmodule EncoderGstTest do
  use ExUnit.Case

  @tag :gstreamer
  test "encode raw frame với backend :gstreamer (CPU)" do
    # Giả lập raw frame YUV420P (ví dụ: 1280x720)
    width = 1280
    height = 720
    raw_frame = <<0::size(width*height*3 div 2)>> # Dummy data

    opts = [
      backend: :gstreamer,
      hw_accel: false, # CPU encode
      width: width,
      height: height,
      format: :yuv420p,
      codec: :h264
    ]

    # Gọi encode
    {:ok, packet} = Encoder.encode(raw_frame, opts, :h264)

    # Kiểm tra kết quả trả về là packet H264
    assert is_binary(packet)
    assert byte_size(packet) > 0
  end
end