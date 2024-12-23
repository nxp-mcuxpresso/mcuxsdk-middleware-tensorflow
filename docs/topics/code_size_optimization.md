# Code size optimization

Typically, models do not use all the operators that are available in TensorFlow Lite. However, because of the default operator registration mechanism used in the library, the toolchain linker is not able to remove the code of unused operators. In order to reduce code size, it is possible to only register the specific operators used by a model. To determine which operators are used by a particular model, a model visualizer tool like Netron can be used. Then a mutable operator resolver object can be created that only registers the operators that are used by the model being inferenced.

Use the `tflite::MicroMutableOpResolver` object template, which is later passed to the `tflite::MicroInterpreter` object. Depending on the list of used operators, the result should be similar to the following code snippet. Make sure to update the MicroMutableOpResolver template parameter to reflect the number of operators that need to be registered.

## Register only used operators in TensorFlow Lite Micro {#SECTION_SS1_DJQ_QPB .section}

```
#include "tensorflow/lite/micro/kernels/micro_ops.h"
          #include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
          tflite::MicroMutableOpResolver<6> microOpResolver;
          microOpResolver.AddAveragePool2D();
          microOpResolver.AddConv2D();
          microOpResolver.AddDepthwiseConv2D();
          microOpResolver.AddDequantize();
          microOpResolver.AddReshape();
          microOpResolver.AddSoftmax();
          static tflite::MicroInterpreter interpreter(
          model, microOpResolver, tensorArena, kTensorArenaSize, microErrorReporter);
```



