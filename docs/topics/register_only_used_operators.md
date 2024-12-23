# Register only used operators

Use the `tflite::MicroMutableOpResolver` object template, which is later passed to the `tflite::MicroInterpreter` object. Depending on the list of used operators, the result should be similar to [Register only used operators in TensorFlow Lite Micro](register_only_used_operators.md#SECTION_SS1_DJQ_QPB). Make sure to update the MicroMutableOpResolver template parameter to reflect the number of operators that need to be registered.

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



