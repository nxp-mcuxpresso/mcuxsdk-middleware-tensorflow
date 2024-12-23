# Running an inference

After converting the model to the TensorFlow Lite format, it is converted into a C language array to include it in the application source code. The *xxd* utility can be used for this purpose \(distributed with the *Vim* editor for many platforms on [https://www.vim.org/](https://www.vim.org/)\) as shown in [Converting a model to a C language header file](running_an_inference.md#EXAMPLE_4). The utility converts a TensorFlow Lite model into a C header file with an array definition containing the binary image of the model and a variable containing the data size.

## Converting a model to a C language header file {#EXAMPLE_4 .section}

```
xxd -i mobilenet_v1_0.25_128_quant.tflite > mobilenet_v1_0.25_128_quant_model.h
```

After the header file is generated, the type of the array is changed from `unsigned char` to `const char` to match the library API input parameters and the default array name can be changed to a more convenient one. The user must align the buffer to at least 64-bit boundary \(the size of a double-precision floating-point number\) to avoid misaligned memory access. The alignment can be achieved by using the `__ALIGNED(16)` macro from the `cmsis_compiler.h` header file \(available in the MCUXpresso SDK\) in the array declaration before the data assignment.

The easiest way to create an application with the proper configuration is to copy and modify an existing example application. To learn where to find the example applications and how to build them, see the [Example applications](example_applications.md).

Running an inference using TensorFlow Lite for Microcontrollers involves several steps \(shown for quantized model with signed 8-bit values as input and 32-floating point values as output\):

1.  Include the necessary eIQ TensorFlow Lite Micro library header files and the converted model.

    **Including header files**

    ```
    #include "tensorflow/lite/micro/micro_error_reporter.h"
    #include "tensorflow/lite/micro/micro_interpreter.h"
    #include "tensorflow/lite/micro/all_ops_resolver.h"
    #include "mobilenet_v1_0.25_128_quant_model.h"
    ```

2.  Allocate a static memory buffer for input and output tensors and intermediate arrays. Load the FlatBuffer model image \(assuming the `mobilenet_v1_0.25_128_quant_model.h` file generated in [Converting a model to a C language header file](running_an_inference.md#EXAMPLE_4) defines an array named mobilenet\_model and a size variable named mobilenet\_model\_len\), build the interpreter object and allocate memory for tensors.

    **Loading the FlatBuffer model**

    ```
    constexpr int kTensorArenaSize = 1024 * 1024;
    static uint8_t tensorArena[kTensorArenaSize];
    const tflite::Model* model = tflite::GetModel(mobilenet_model);
    // TODO: Report an error if model->version() != TFLITE_SCHEMA_VERSION
    static tflite::AllOpsResolver microOpResolver;
    static tflite::MicroErrorReporter microErrorReporter;
    static tflite::MicroInterpreter interpreter(model,
      microOpResolver, tensorArena, kTensorArenaSize,
      microErrorReporter);
    interpreter->AllocateTensors();
    // TODO: Check return value for kTfLiteOk
    ```

3.  Fillhe input data into the input tensor. For example, if a speech recognition model, image data from a camera or audio data from a microphone. The dimensions of the input data must be the same as the dimensions of the input tensor. These dimensions were specified when the model was created.

    **Fill-in input data**

    ```
    // Get access to the input tensor data
    TfLiteTensor* inputTensor = interpreter->input(0);
    // Copy the input tensor data from an application buffer
    for (int i = 0; i < inputTensor->bytes; i++)
      inputTensor->data.int8[i] = input_data[i];
    ```

4.  Run the inference and read the output data from the output tensor. The dimensions of the output data must be the same as the dimensions of the output tensor. These dimensions were specified when the model was created.

    **Running inference and reading output data**

    ```
    // Run the inference
    interpreter->Invoke();
    // TODO: Check the return value for TfLiteOk
    // Get access to the output tensor data
    TfLiteTensor* outputTensor = interpreter->output(0);
    // Copy the output tensor data to an application buffer
    for (int i = 0; i < outputTensor->bytes / sizeof(float32); i++)
      output_data[i] = outputTensor->data.f[i];
    ```


## NPU inference {#npu_infer .section}

Running an inference using a model converted for the NPU requires registration of a custom operator implementation. First the header file with the custom operator implementation interface must be included.

```
#include "tensorflow/lite/micro/kernels/micro_ops.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/kernels/neutron/neutron.h"				
```

Next, the specialized implemetation has to be registered in the operator resolver object.

```
static tflite::AllOpsResolver microOpResolver;
microOpResolver.AddCustom(tflite::GetString_NEUTRON_GRAPH(),  
	tflite::Register_NEUTRON_GRAPH());			
```

The specialized NPU nodes from the converted model are the executed using this newly registered implementation.

## Adjusting the tensor arena size {#adjust_arena .section}

The tensor arena is a static memory buffer used for intermediate tensor and scratch buffer allocation. The size of the tensor arena buffer is set by the `kTensorArenaSize` constant in the example above. The value depends on the tensor sizes used in the model and on the hardware-specific implementations of kernels, which may require various sizes of scratch buffers for intermediate computations. The value can be determined experimentally by running an inference with a small value, so the library fails with an insufficient tensor memory error and prints the missing amount. Continue adjusting the size until the error stops being reported. If the target hardware changes, readjust the value.

