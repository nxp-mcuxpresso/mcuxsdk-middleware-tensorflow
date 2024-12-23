# Prepare CM33 Core for the examples

1.  The `tflm_cifar10_hifi4` and `tflm_label_image_hifi4` examples consist of two separate applications that run on the CM33 core0 and DSP core. The CM33 core0 application initializes the DSP core and starts it.

    To debug the application:

    1.  Set up and execute the CM33 application using an environment of your choice.

    2.  Build and execute the examples located in:

        `<SDK_ROOT>/boards/mimxrt700evk/eiq_examples/tflm_cifar10_hifi4/cm33/`

        `<SDK_ROOT>/ boards/mimxrt700evk/eiq_examples/tflm_label_image_hifi4/cm33/`

2.  The `tflm_cifar10_hifi1` example consists of three separate applications that run on the CM33 core0, CM33 core1, and DSP core. The CM33 core0 application initializes the CM33 core1 core and starts it. The CM33 core1 application initializes the DSP core and starts it.

    To debug the application:

    1.  Set up and build the CM33 core1 application using an environment of your choice.
    2.  Set up and execute the CM33 core0 application using an environment of your choice.
    3.  Build and execute the example located in:

        `<SDK_ROOT>/boards/mimxrt700evk/eiq_examples/tflm_cifar10_hifi1/cm33_core1/`

        `<SDK_ROOT>/boards/mimxrt700evk/eiq_examples/tflm_cifar10_hifi1/cm33_core0/`

        **Note:** ARMGCC toolchain and IAR Embedded Workbench are both supported. To enable compatibility with RT700, IAR Embedded Workbench may require a patch. There are default DSP core images in the SDK. For details on how to build the examples, refer to [Prepare DSP core for the examples](prepare_dsp_core_for_the_examples.md).


**Parent topic:**[Run and debug eIQ HiFi4 and HiFi1 DSP examples using Xplorer IDE](../topics/run_and_debug_eiq_hifi4_and_hifi1_dsp_examples_usi.md)

