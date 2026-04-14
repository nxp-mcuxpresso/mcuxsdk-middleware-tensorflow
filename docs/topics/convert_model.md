# Model Conversion to TensorFlow Lite Format
The `eIQ® Toolkit <https://www.nxp.com/design/design-center/software/eiq-ai-development-environment/eiq-toolkit-for-end-to-end-model-development-and-deployment:EIQ-TOOLKIT#downloads>`_ provides a comprehensive end-to-end environment for machine learning (ML) model development and deployment. Designed for NXP EdgeVerse processors, the toolkit includes both an intuitive GUI-based tool (eIQ Portal) and command-line utilities for advanced workflows.

One key component, the Optimize & Convert, enables seamless conversion of ML models from popular formats such as TensorFlow, PyTorch, and ONNX into the TensorFlow Lite (TFLite) format. These converted models can be further optimized and deployed on NXP platforms for inference acceleration.

# Model Conversion for NXP eIQ Neutron NPU
To leverage the NXP eIQ Neutron NPU for hardware acceleration, models must undergo additional processing using the Neutron Converter Tool. This tool transforms standard quantized TensorFlow Lite models into a format optimized for execution on the Neutron NPU.

The key steps involved in this process are as follows:

1. Convert to Quantized TensorFlow Lite Model:
Ensure the model is in a quantized TFLite format before running the Neutron Converter.

2. Run the Neutron Converter Tool:
The Neutron Converter analyzes the TFLite model, identifies supported operators, and replaces them with specialized NPU-compatible nodes. Unsupported operations are executed using fallback mechanisms, such as:

- CMSIS-NN for optimized CPU execution
- Reference Operators for unsupported cases

3. Execute on Target Platform:
The converted model runs efficiently on the Neutron NPU using a custom TFLite Micro-operator implementation.

# Example: Converting a Quantized TensorFlow Lite Model for Neutron NPU
The following is a sample command-line invocation for the Neutron Converter tool:
```
neutron-converter --input mobilenet_v1_0.25_128_quant.tflite \
                  --output mobilenet_v1_0.25_128_quant_npu.tflite \
                  --target imxrt700 \
                  --dump-header-file-output
```
Note: This will convert the source tflite model to neutron compatable model, meanwhile, it will dump the model as one headfile name as "mobilenet_v1_0.25_128_quant_npu.h". 

For RT700, the Neutron Sequencer mode allows users to generate Neutron bytecode, enabling faster model inference. 
# Example: Converting a Quantized TensorFlow Lite Model for Neutron NPU with Neutron Sequencer mode.
The following is a sample command-line invocation for the Neutron Converter tool:
```
neutron-converter --input mobilenet_v1_0.25_128_quant.tflite \
                  --output mobilenet_v1_0.25_128_quant_npu.tflite \
                  --use-sequencer \
                  --target imxrt700 \
                  --dump-header-file-output
```

For RT700, Neutron customer operator in TFlite-micro support weight prefetching. This enable user to use larger model which can only save in external flash. 
# Example: Converting a Quantized TensorFlow Lite Model for Neutron NPU with weight prefetching.
The following is a sample command-line invocation for the Neutron Converter tool:
```
neutron-converter --input mobilenet_v1_1.0_224_int8.tflite \
                  --output mobilenet_v1_1.0_224_int8_npu.tflite \
                  --fetch-constants-to-sram \
                  --target imxrt700
```
Note: The weight prefetching feature can't work together with Neutron Sequencer mode. 
