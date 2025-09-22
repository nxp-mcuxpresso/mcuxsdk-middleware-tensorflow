export XTENSA_BASE="/opt/xtensa/XtDevTools/install"
export XTENSA_SYSTEM="/opt/xtensa/XtDevTools/install/builds/RI-2023.11-linux/rt700_hifi1_RI23_11_nlib/config"
export XTENSA_TOOLS_VERSION="RI-2023.11-linux"
export XTENSA_CORE="rt700_hifi1_RI23_11_nlib"

git clone https://github.com/cad-audio/tflite-micro.git tflite-micro
cd tflite-micro
git checkout 54331e9fe42af1dcc8221d693ae85890fb399944
git apply ../tflm.patch
make -j8 -f tensorflow/lite/micro/tools/make/Makefile BUILD_TYPE=release_with_logs TARGET=xtensa TARGET_ARCH=hifi4 XTENSA_USE_LIBC=true OPTIMIZED_KERNEL_DIR=xtensa microlite
cp gen/xtensa_hifi4_release_with_logs_xtensa_gcc/lib/libtensorflow-microlite.a ../libtflm.a
cd ..

