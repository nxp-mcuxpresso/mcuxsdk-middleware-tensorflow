# Supported Operator List

## Supported Operator List by Tensorflow Lite for Microcontrollers

The TensorFlow Lite library since version 2.3 provides an alternative implementation optimized for microcontrollers with low memory capacity called TensorFlow Lite for Microcontrollers \(or TensorFlow Lite Micro\). In comparison to TensorFlow Lite, the Micro version uses static memory allocation, has no dependencies on standard C or C++ libraries and contains implementations of operation kernels optimized for Arm Cortex-M architecture using Arm’s CMSIS-NN library. The following table contains a comparison of supported operations by both libraries.

| TensorFlow Lite operations     | Supported by TensorFlow Lite for Microcontrollers |
| ------------------------------ | ------------------------------------------------- |
| ABS                            | Yes                                               |
| ADD                            | Yes                                               |
| ADD\_N                         | Yes                                               |
| ARG\_MAX                       | Yes                                               |
| ARG\_MIN                       | Yes                                               |
| ASSIGN\_VARIABLE               | Yes                                               |
| ATAN2                          | No                                                |
| AVERAGE\_POOL\_2D              | Yes                                               |
| BATCH\_MATMUL                  | Yes                                               |
| BATCH\_TO\_SPACE\_ND           | Yes                                               |
| BIDIRECTIONAL\_SEQUENCE\_LSTM  | No                                                |
| BIDIRECTIONAL\_SEQUENCE\_RNN   | No                                                |
| BROADCAST\_ARGS                | Yes                                               |
| BROADCAST\_TO                  | Yes                                               |
| BUCKETIZE                      | No                                                |
| CALL\_ONCE                     | No                                                |
| CAST                           | Yes                                               |
| CEIL                           | Yes                                               |
| COMPLEX\_ABS                   | No                                                |
| CONCATENATION                  | Yes                                               |
| CONV\_2D                       | Yes                                               |
| CONV\_3D                       | No                                                |
| CONV\_3D\_TRANSPOSE            | No                                                |
| COS                            | Yes                                               |
| CUMSUM                         | Yes                                               |
| DELAY                          | Yes                                               |
| DENSIFY                        | No                                                |
| DEPTH\_TO\_SPACE               | Yes                                               |
| DEPTHWISE\_CONV\_2D            | Yes                                               |
| DEQUANTIZE                     | Yes                                               |
| DETECTION\_POSTPROCESS         | Yes                                               |
| DIV                            | Yes                                               |
| DYNAMIC\_UPDATE\_SLICE         | No                                                |
| ELU                            | Yes                                               |
| EMBEDDING\_LOOKUP              | Yes                                               |
| EMBEDDING\_LOOKUP\_SPARSE      | No                                                |
| EQUAL                          | Yes                                               |
| EXP                            | Yes                                               |
| EXPAND\_DIMS                   | Yes                                               |
| FAKE\_QUANT                    | No                                                |
| FILL                           | Yes                                               |
| FLOOR                          | Yes                                               |
| FLOOR\_DIV                     | Yes                                               |
| FLOOR\_MOD                     | Yes                                               |
| FULLY\_CONNECTED               | Yes                                               |
| GATHER                         | Yes                                               |
| GELU                           | No                                                |
| GATHER\_ND                     | Yes                                               |
| GREATER                        | Yes                                               |
| GREATER\_EQUAL                 | Yes                                               |
| HARD\_SWISH                    | Yes                                               |
| HASHTABLE                      | No                                                |
| HASHTABLE\_FIND                | No                                                |
| HASHTABLE\_IMPORT              | No                                                |
| HASHTABLE\_LOOKUP              | No                                                |
| HASHTABLE\_SIZE                | No                                                |
| IF                             | Yes                                               |
| IMAG                           | No                                                |
| L2\_NORMALIZATION              | Yes                                               |
| L2\_POOL\_2D                   | Yes                                               |
| LEAKY\_RELU                    | Yes                                               |
| LESS                           | Yes                                               |
| LESS\_EQUAL                    | Yes                                               |
| LOCAL\_RESPONSE\_NORMALIZATION | No                                                |
| LOG                            | Yes                                               |
| LOG\_SOFTMAX                   | Yes                                                |
| LOGICAL\_AND                   | Yes                                               |
| LOGICAL\_NOT                   | Yes                                               |
| LOGICAL\_OR                    | Yes                                               |
| LOGISTIC                       | Yes                                               |
| LSH\_PROJECTION                | No                                                |
| LSTM                           | No                                                |
| MATRIX\_DIAG                   | No                                                |
| MATRIX\_SET\_DIAG              | No                                                |
| MAX\_POOL\_2D                  | Yes                                               |
| MAXIMUM                        | Yes                                               |
| MEAN                           | Yes                                               |
| MINIMUM                        | Yes                                               |
| MIRROR\_PAD                    | Yes                                               |
| MUL                            | Yes                                               |
| MULTINOMIAL                    | No                                                |
| NEG                            | Yes                                               |
| NON\_MAX\_SUPPRESSION\_V4      | No                                                |
| NON\_MAX\_SUPPRESSION\_V5      | No                                                |
| NOT\_EQUAL                     | Yes                                               |
| ONE\_HOT                       | No                                                |
| PACK                           | Yes                                               |
| PAD                            | Yes                                               |
| PADV2                          | Yes                                               |
| POW                            | No                                                |
| PRELU                          | Yes                                               |
| QUANTIZE                       | Yes                                               |
| RANDOM\_STANDARD\_NORMAL       | No                                                |
| RANDOM\_UNIFORM                | No                                                |
| RANGE                          | No                                                |
| RANK                           | No                                                |
| READ\_VARIABLE                 | No                                                |
| REAL                           | No                                                |
| REDUCE\_ALL                    | No                                                |
| REDUCE\_ANY                    | No                                                |
| REDUCE\_MAX                    | Yes                                               |
| REDUCE\_MIN                    | No                                                |
| REDUCE\_PROD                   | No                                                |
| RELU                           | Yes                                               |
| RELU\_N1\_TO\_1                | No                                                |
| RELU6                          | Yes                                               |
| RFFT2D                         | No                                                |
| RESHAPE                        | Yes                                               |
| RESIZE\_BILINEAR               | Yes                                               |
| RESIZE\_NEAREST\_NEIGHBOR      | Yes                                               |
| REVERSE\_SEQUENCE              | No                                                |
| REVERSE\_V2                    | No                                                |
| RNN                            | No                                                |
| ROUND                          | Yes                                               |
| RSQRT                          | Yes                                               |
| SCATTER\_ND                    | No                                                |
| SEGMENT\_SUM                   | No                                                |
| SELECT                         | No                                                |
| SELECT\_V2                     | Yes                                               |
| SHAPE                          | Yes                                               |
| SIN                            | Yes                                               |
| SKIP\_GRAM                     | No                                                |
| SLICE                          | Yes                                               |
| SOFTMAX                        | Yes                                               |
| SPACE\_TO\_BATCH\_ND           | Yes                                               |
| SPACE\_TO\_DEPTH               | Yes                                               |
| SPARSE\_TO\_DENSE              | No                                                |
| SPLIT                          | Yes                                               |
| SPLIT\_V                       | Yes                                               |
| SQRT                           | Yes                                               |
| SQUARE                         | Yes                                               |
| SQUARED\_DIFFERENCE            | Yes                                               |
| SQUEEZE                        | Yes                                               |
| STRIDED\_SLICE                 | Yes                                               |
| SUB                            | Yes                                               |
| SUM                            | Yes                                               |
| SVDF                           | Yes                                               |
| TANH                           | Yes                                               |
| TILE                           | No                                                |
| TOPK\_V2                       | No                                                |
| TRANSPOSE                      | Yes                                               |
| TRANSPOSE\_CONV                | Yes                                               |
| UNIDIRECTIONAL\_SEQUENCE\_LSTM | Yes \(on Xtensa cores\)                           |
| UNIDIRECTIONAL\_SEQUENCE\_RNN  | No                                                |
| UNIQUE                         | No                                                |
| UNPACK                         | Yes                                               |
| WHERE                          | No                                                |
| WHILE                          | Yes                                               |
| UNSORTED\_SEGMENT\_MAX         | No                                                |
| UNSORTED\_SEGMENT\_PROD        | No                                                |
| UNSORTED\_SEGMENT\_SUM         | No                                                |
| VAR\_HANDLE                    | No                                                |
| ZEROS\_LIKE                    | Yes                                               |

[Table 2](#table_ygd_z34_3wb) contains an overview of hardware optimized TensorFlow Lite Micro operators on supported devices. Operators not listed in the table are reference C++ implementations only. Optimized operators for ARM Cortex-M cores leverage the ARM CMSIS-NN library. For details, see the `middleware/eiq/tensorflow-lite/third_party/cmsis/CMSIS/NN/README.md` file. Optimized operators for Cadence Xtensa cores \(HiFi4 and FusionF1\) leverage the Xtensa HiFi4 NN library.

## Supported Operator List by eIQ Neutron NPU Library and HiFi 4 NN Library

| Operator                       | Operator input type                   | i.MX RT700 <br> \(HiFi4 NN\)   | MCXN947 \(Cortex-M33 core\)<br> MCXN547 \(Cortex-M33 core\) <br> i.MX RT700\(Cortex-M33 core\) | MCXN947 \(eIQ Neutron NPU\) <br> MCXN547 \(eIQ Neutron NPU\) <br> i.MX RT700 \(eIQ Neutron NPU\) |
| ------------------------------ | ------------------------------------- | ------------------------------ | ---------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------ |
| ABS                            | float <br> uint8 <br> int8 <br> int16 | No <br> No <br> No <br> No | No <br> No <br> No <br> No                                                                 | No <br> No <br> Yes <br> Yes                                                                     |
| ADD                            | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> No                                                                 | No <br> No <br> Yes <br> Yes                                                                     |
| AVERAGE\_POOL\_2D              | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> No                                                                    |
| BATCHMATMUL                    | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                               | No <br> No <br> Yes <br> No                                                                     |
| CONCAT                         | float <br> uint8 <br> int8 <br> int16 | No <br> No <br> Yes <br> No | Yes <br> No <br> Yes <br> No                                                                 | No <br> No <br> Yes <br> No                                                                     |
| CONV\_2D                       | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> Yes                                                                     |
| DEPTHWISE\_CONV\_2D            | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> Yes                                                                     |
| FULLY\_CONNECTED               | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> Yes                                                                     |
| RELU6                          | float <br> uint8 <br> int8 <br> int16 | No <br> No <br> No <br> No | Yes <br> No <br> Yes <br> No                                                                 | No <br> No <br> Yes <br> Yes                                                                     |
| RELU                           | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> Yes                                                                     |
| LEAKY\_RELU                    | float <br> uint8 <br> int8 <br> int16 | No <br> Yes <br> No <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> Yes                                                                     |
| MAX\_POOL\_2D                  | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> No                                                                     |
| MIRRORPAD                      | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> No                                                                     |
| MUL                            | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> Yes                                                                     |
| PAD                            | float <br> uint8 <br> int8 <br> int16 | Yes <br> No <br> Yes <br> Yes | Yes <br> No <br> Yes <br> No                                                                 | No <br> No <br> Yes <br> No                                                                     |
| RESIZE\_NEAREST\_NEIGHBOR      | float <br> uint8 <br> int8 <br> int16 | No <br> No <br> Yes <br> No | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> No                                                                     |
| SLICE                          | float <br> uint8 <br> int8 <br> int16 | No <br> No <br> No <br> No | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> No                                                                     |
| STRIDED\_SLICE                 | float <br> uint8 <br> int8 <br> int16 | Yes <br> No <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> No                                                                     |
| SOFTMAX                        | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> Yes <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> No                                                                     |
| TANH                           | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | No <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> No                                                                     |
| TRANSPOSE                      | float <br> uint8 <br> int8 <br> int16 | No <br> No <br> Yes <br> Yes | Yes <br> No <br> Yes <br> No                                                                 | No <br> No <br> Yes <br> No                                                                     |
| TRANSPOSE\_CONV                | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> No                                                                 | No <br> No <br> Yes <br> No                                                                     |
| UNIDIRECTIONAL\_SEQUENCE\_LSTM | float <br> uint8 <br> int8 <br> int16 | No <br> No <br> No <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> Ye*
| LOGISTIC                       | float <br> uint8 <br> int8 <br> int16 | Yes <br> Yes <br> Yes <br> Yes | Yes <br> No <br> Yes <br> Yes                                                                 | No <br> No <br> Yes <br> No


**Note:**

-   PTQ — Per-tensor quantized \(asymmetric 8-bit quantization\).
-   PCQ — Per-channel quantized \(symmetric 8-bit quantization\).

