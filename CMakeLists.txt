cmake_minimum_required(VERSION 3.10)
project(video_processor_demo C)

set(CMAKE_C_STANDARD 99)

# Tìm GStreamer qua pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GST REQUIRED gstreamer-1.0 gstreamer-app-1.0 gstreamer-video-1.0)

include_directories(
    ${GST_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/c_src
)

add_executable(main
    c_src/main.c
    c_src/video_processor.c
    c_src/encoder_gst.c
)

target_link_libraries(main
    ${GST_LIBRARIES}
)

target_compile_options(main PRIVATE ${GST_CFLAGS_OTHER})