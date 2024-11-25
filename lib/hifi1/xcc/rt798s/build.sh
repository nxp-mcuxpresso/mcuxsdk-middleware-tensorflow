export PATH="$PATH:/opt/xtensa/XtDevTools/install/tools/RI-2023.11-linux/XtensaTools/bin"
export XTENSA_BASE="opt/xtensa/XtDevTools/install"
export XTENSA_SYSTEM="/opt/xtensa/XtDevTools/install/builds/RI-2023.11-linux/rt700_hifi1_RI23_11_nlib/config"
export XTENSA_TOOLS_VERSION="RI-2023.11-linux"
export XTENSA_CORE="rt700_hifi1_RI23_11_nlib"

git clone https://github.com/tensorflow/tflite-micro.git tflite-micro-2024-08-07-d3475aa
cd tflite-micro-2024-08-07-d3475aa
git checkout d3475aa
git apply ../tflm.patch
make -j8 -f tensorflow/lite/micro/tools/make/Makefile BUILD_TYPE=release_with_logs TARGET=xtensa TARGET_ARCH=hifi4 XTENSA_USE_LIBC=true OPTIMIZED_KERNEL_DIR=xtensa microlite
cp gen/xtensa_hifi4_release_with_logs_xtensa_gcc/lib/libtensorflow-microlite.a ../libtflm.a
cd ..

