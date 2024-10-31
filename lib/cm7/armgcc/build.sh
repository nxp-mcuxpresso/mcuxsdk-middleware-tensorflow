git clone https://github.com/tensorflow/tflite-micro.git tflite-micro-2024-08-07-d3475aa
cd tflite-micro-2024-08-07-d3475aa
git checkout d3475aa
make -f tensorflow/lite/micro/tools/make/Makefile BUILD_TYPE=release_with_logs TARGET=cortex_m_generic TARGET_ARCH=cortex-m7+fp OPTIMIZED_KERNEL_DIR=cmsis_nn microlite
cp gen/cortex_m_generic_cortex-m7+fp_release_with_logs/lib/libtensorflow-microlite.a ../libtflm.a
cd ..
