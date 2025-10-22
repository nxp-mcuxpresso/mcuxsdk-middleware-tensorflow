set(ETHOSU_STUB Y)

if (CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro)
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES tensorflow/compiler/mlir/lite/kernels/internal/*.h
    tensorflow/compiler/mlir/lite/schema/*.h
    tensorflow/lite/kernels/*.h
    tensorflow/lite/kernels/internal/*.h
    tensorflow/lite/kernels/internal/reference/*.h
    tensorflow/lite/kernels/internal/reference/integer_ops/*.h
    tensorflow/lite/kernels/internal/optimized/*.h
    tensorflow/lite/experimental/microfrontend/lib/*.h
    tensorflow/lite/schema/*.h
    tensorflow/lite/*.h
    tensorflow/lite/core/api/*.h
    tensorflow/lite/core/*.h
    tensorflow/lite/core/c/*.h
    tensorflow/lite/micro/*.h
    tensorflow/lite/micro/kernels/*.h
    tensorflow/lite/micro/kernels/xtensa/*.h
    tensorflow/lite/micro/compression/*.h
    tensorflow/lite/micro/memory_planner/*.h
    tensorflow/lite/micro/arena_allocator/*.h
    tensorflow/lite/micro/tflite_bridge/*.h
    tensorflow/lite/c/*.h
    tensorflow/compiler/mlir/lite/core/api/*.h
    tensorflow/compiler/mlir/lite/core/c/*.h
    tensorflow/lite/micro/kernels/xtensa/hifimini/*.h
    signal/micro/kernels/*.h
    signal/src/*.h
    signal/src/kiss_fft_wrappers/*.h
    )
  mcux_add_include(
    INCLUDES ./
    third_party/flatbuffers/include
    third_party/gemmlowp
    third_party/kissfft
    third_party/ruy
    third_party/cmsis_nn
    third_party/cmsis_nn/Include
    )
  mcux_add_source(
    SOURCES third_party/cmsis_nn/Include/*.h
    third_party/cmsis_nn/Include/Internal/*.h
    third_party/fft2d/*.h
    third_party/flatbuffers/include/flatbuffers/*.h
    third_party/flatbuffers/include/flatbuffers/pch/*.h
    third_party/gemmlowp/fixedpoint/*.h
    third_party/gemmlowp/internal/detect_platform.h
    third_party/ruy/ruy/profiler/instrumentation.h
    third_party/kissfft/*.h
    third_party/kissfft/tools/*.h
    )
  mcux_add_macro(
    CC "-DTF_LITE_STATIC_MEMORY -DKERNELS_OPTIMIZED_FOR_SPEED"
    CX "-DTF_LITE_STATIC_MEMORY -DKERNELS_OPTIMIZED_FOR_SPEED"
    )
  mcux_remove_mdk_configuration(
    CC "-fshort-wchar"
    CX "-fshort-wchar"
    )
  mcux_add_iar_configuration(
    CC "--diag_suppress=Pa082,Pa050,Pe188,Pe069,Go003,Pa050,Pa082,Pa183,Pa084,Pa093,Pe069,Pe111,Pe161,Pe174,Pe177,Pe186,Pe188,Pe550,Pe611,Pe997,Pe1444,Pe1675,Pe830,Pe1097"
    CX "--diag_suppress=Pa082,Pa050,Pe188,Pe069,Go003,Pa050,Pa082,Pa084,Pa093,Pe069,Pe111,Pe161,Pe174,Pe177,Pe186,Pe188,Pe550,Pe611,Pe997,Pe1444,Pe1675,Pe830"
    )
  mcux_remove_configuration(
    CC "-fno-builtin"
    CX "-fno-builtin"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.debug_log)
  mcux_add_source(
    SOURCES tensorflow/lite/micro/debug_log.cpp
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.source)
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES tensorflow/lite/kernels/kernel_util.cpp
    tensorflow/compiler/mlir/lite/schema/schema_utils.cpp
    tensorflow/lite/kernels/internal/portable_tensor_utils.cpp
    tensorflow/lite/kernels/internal/quantization_util.cpp
    tensorflow/lite/kernels/internal/common.cpp
    tensorflow/lite/kernels/internal/tensor_utils.cpp
    tensorflow/lite/kernels/internal/reference/portable_tensor_utils.cpp
    tensorflow/lite/kernels/internal/reference/comparisons.cpp
    tensorflow/lite/kernels/internal/tensor_ctypes.cpp
    tensorflow/lite/core/api/tensor_utils.cpp
    tensorflow/lite/core/api/flatbuffer_conversions.cpp
    tensorflow/lite/core/c/common.cpp
    tensorflow/lite/micro/micro_context.cpp
    tensorflow/lite/micro/kernels/if.cpp
    tensorflow/lite/micro/kernels/logical_common.cpp
    tensorflow/lite/micro/kernels/squeeze.cpp
    tensorflow/lite/micro/kernels/assign_variable.cpp
    tensorflow/lite/micro/kernels/read_variable.cpp
    tensorflow/lite/micro/kernels/unpack.cpp
    tensorflow/lite/micro/kernels/reshape_common.cpp
    tensorflow/lite/micro/kernels/logistic_common.cpp
    tensorflow/lite/micro/kernels/quantize_common.cpp
    tensorflow/lite/micro/kernels/dequantize.cpp
    tensorflow/lite/micro/kernels/zeros_like.cpp
    tensorflow/lite/micro/kernels/depth_to_space.cpp
    tensorflow/lite/micro/kernels/concatenation.cpp
    tensorflow/lite/micro/kernels/slice.cpp
    tensorflow/lite/micro/kernels/shape.cpp
    tensorflow/lite/micro/kernels/space_to_batch_nd.cpp
    tensorflow/lite/micro/kernels/strided_slice_common.cpp
    tensorflow/lite/micro/kernels/batch_to_space_nd.cpp
    tensorflow/lite/micro/kernels/round.cpp
    tensorflow/lite/micro/kernels/micro_tensor_utils.cpp
    tensorflow/lite/micro/kernels/squared_difference.cpp
    tensorflow/lite/micro/kernels/split_v.cpp
    tensorflow/lite/micro/kernels/split.cpp
    tensorflow/lite/micro/kernels/ceil.cpp
    tensorflow/lite/micro/kernels/mul_common.cpp
    tensorflow/lite/micro/kernels/select.cpp
    tensorflow/lite/micro/kernels/log_softmax.cpp
    tensorflow/lite/micro/kernels/add_n.cpp
    tensorflow/lite/micro/kernels/arg_min_max.cpp
    tensorflow/lite/micro/kernels/activations.cpp
    tensorflow/lite/micro/kernels/broadcast_to.cpp
    tensorflow/lite/micro/kernels/pack.cpp
    tensorflow/lite/micro/kernels/while.cpp
    tensorflow/lite/micro/kernels/fully_connected_common.cpp
    tensorflow/lite/micro/kernels/resize_nearest_neighbor.cpp
    tensorflow/lite/micro/kernels/floor_mod.cpp
    tensorflow/lite/micro/kernels/gather_nd.cpp
    tensorflow/lite/micro/kernels/embedding_lookup.cpp
    tensorflow/lite/micro/kernels/expand_dims.cpp
    tensorflow/lite/micro/kernels/pooling_common.cpp
    tensorflow/lite/micro/kernels/fill.cpp
    tensorflow/lite/micro/kernels/conv_common.cpp
    tensorflow/lite/micro/kernels/l2_pool_2d.cpp
    tensorflow/lite/micro/kernels/space_to_depth.cpp
    tensorflow/lite/micro/kernels/elu.cpp
    tensorflow/lite/micro/kernels/depthwise_conv_common.cpp
    tensorflow/lite/micro/kernels/logical.cpp
    tensorflow/lite/micro/kernels/kernel_util.cpp
    tensorflow/lite/micro/kernels/dequantize_common.cpp
    tensorflow/lite/micro/kernels/gather.cpp
    tensorflow/lite/micro/kernels/tanh.cpp
    tensorflow/lite/micro/kernels/softmax_common.cpp
    tensorflow/lite/micro/kernels/call_once.cpp
    tensorflow/lite/micro/kernels/hard_swish.cpp
    tensorflow/lite/micro/kernels/comparisons.cpp
    tensorflow/lite/micro/kernels/svdf_common.cpp
    tensorflow/lite/micro/kernels/hard_swish_common.cpp
    tensorflow/lite/micro/kernels/var_handle.cpp
    tensorflow/lite/micro/kernels/circular_buffer.cpp
    tensorflow/lite/micro/kernels/circular_buffer_common.cpp
    tensorflow/lite/micro/kernels/broadcast_args.cpp
    tensorflow/lite/micro/kernels/floor_div.cpp
    tensorflow/lite/micro/kernels/elementwise.cpp
    tensorflow/lite/micro/kernels/prelu.cpp
    tensorflow/lite/micro/kernels/detection_postprocess.cpp
    tensorflow/lite/micro/kernels/kernel_runner.cpp
    tensorflow/lite/micro/kernels/add_common.cpp
    tensorflow/lite/micro/kernels/mirror_pad.cpp
    tensorflow/lite/micro/kernels/reduce_common.cpp
    tensorflow/lite/micro/kernels/prelu_common.cpp
    tensorflow/lite/micro/kernels/lstm_eval_common.cpp
    tensorflow/lite/micro/kernels/floor.cpp
    tensorflow/lite/micro/kernels/cumsum.cpp
    tensorflow/lite/micro/kernels/leaky_relu_common.cpp
    tensorflow/lite/micro/kernels/div.cpp
    tensorflow/lite/micro/kernels/activations_common.cpp
    tensorflow/lite/micro/kernels/sub_common.cpp
    tensorflow/lite/micro/kernels/exp.cpp
    tensorflow/lite/micro/kernels/neg.cpp
    tensorflow/lite/micro/kernels/cast.cpp
    tensorflow/lite/micro/kernels/resize_bilinear.cpp
    tensorflow/lite/micro/kernels/l2norm.cpp
    tensorflow/lite/micro/micro_resource_variable.cpp
    tensorflow/lite/micro/mock_micro_graph.cpp
    tensorflow/lite/micro/micro_profiler.cpp
    tensorflow/lite/micro/memory_planner/linear_memory_planner.cpp
    tensorflow/lite/micro/memory_planner/greedy_memory_planner.cpp
    tensorflow/lite/micro/memory_planner/non_persistent_buffer_planner_shim.cpp
    tensorflow/lite/micro/memory_helpers.cpp
    tensorflow/lite/micro/micro_log.cpp
    tensorflow/lite/micro/micro_interpreter_context.cpp
    tensorflow/lite/micro/micro_interpreter_graph.cpp
    tensorflow/lite/micro/test_helper_custom_ops.cpp
    tensorflow/lite/micro/micro_time.cpp
    tensorflow/lite/micro/test_helpers.cpp
    tensorflow/lite/micro/recording_micro_allocator.cpp
    tensorflow/lite/micro/micro_interpreter.cpp
    tensorflow/lite/micro/micro_allocator.cpp
    tensorflow/lite/micro/micro_allocation_info.cpp
    tensorflow/lite/micro/flatbuffer_utils.cpp
    tensorflow/lite/micro/micro_op_resolver.cpp
    tensorflow/lite/micro/fake_micro_context.cpp
    tensorflow/lite/micro/micro_utils.cpp
    tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.cpp
    tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.cpp
    tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.cpp
    tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.cpp
    tensorflow/lite/micro/tflite_bridge/flatbuffer_conversions_bridge.cpp
    tensorflow/lite/micro/tflite_bridge/micro_error_reporter.cpp
    tensorflow/compiler/mlir/lite/core/api/error_reporter.cpp
    tensorflow/lite/kernels/internal/runtime_shape.cpp
    tensorflow/lite/micro/kernels/batch_matmul_common.cpp
    tensorflow/lite/micro/kernels/circular_buffer_flexbuffers_generated_data.cpp
    tensorflow/lite/micro/kernels/decompress.cpp
    tensorflow/lite/micro/kernels/decompress_common.cpp
    tensorflow/lite/micro/kernels/pad_common.cpp
    tensorflow/lite/micro/kernels/transpose_common.cpp
    )
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES signal/micro/kernels/delay.cpp
    signal/micro/kernels/energy.cpp
    signal/micro/kernels/fft_auto_scale_kernel.cpp
    signal/micro/kernels/fft_auto_scale_common.cpp
    signal/micro/kernels/filter_bank.cpp
    signal/micro/kernels/filter_bank_log.cpp
    signal/micro/kernels/filter_bank_square_root.cpp
    signal/micro/kernels/filter_bank_square_root_common.cpp
    signal/micro/kernels/filter_bank_spectral_subtraction.cpp
    signal/micro/kernels/stacker.cpp
    signal/micro/kernels/pcan.cpp
    signal/micro/kernels/framer.cpp
    signal/micro/kernels/irfft.cpp
    signal/micro/kernels/overlap_add.cpp
    signal/micro/kernels/rfft.cpp
    signal/micro/kernels/window.cpp
    signal/src/circular_buffer.cpp
    signal/src/energy.cpp
    signal/src/fft_auto_scale.cpp
    signal/src/filter_bank.cpp
    signal/src/filter_bank_log.cpp
    signal/src/filter_bank_spectral_subtraction.cpp
    signal/src/filter_bank_square_root.cpp
    signal/src/irfft_float.cpp
    signal/src/irfft_int16.cpp
    signal/src/irfft_int32.cpp
    signal/src/kiss_fft_wrappers/kiss_fft_float.cpp
    signal/src/kiss_fft_wrappers/kiss_fft_int16.cpp
    signal/src/kiss_fft_wrappers/kiss_fft_int32.cpp
    signal/src/log.cpp
    signal/src/max_abs.cpp
    signal/src/msb_32.cpp
    signal/src/msb_64.cpp
    signal/src/overlap_add.cpp
    signal/src/pcan_argc_fixed.cpp
    signal/src/rfft_float.cpp
    signal/src/rfft_int16.cpp
    signal/src/rfft_int32.cpp
    signal/src/square_root_32.cpp
    signal/src/square_root_64.cpp
    signal/src/window.cpp
    third_party/kissfft/*.c
    third_party/kissfft/tools/*.c
    )

  if (CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.ethosu)
    mcux_add_source(
      BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
      SOURCES 
      tensorflow/lite/micro/kernels/ethos_u/ethosu.cpp
      )
    unset(ETHOSU_STUB)
  endif()
  
  if(ETHOSU_STUB)
    mcux_add_source(
      BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
      SOURCES tensorflow/lite/micro/kernels/ethosu.cpp
      )
  endif()
  
  mcux_add_mdk_configuration(
    CC "-std=c99"
    CX "-std=c++17"
    LD "--library_type=standardlib"
    )
  mcux_add_armgcc_configuration(
    CC "-std=c17 -funsigned-char"
    CX "-std=gnu++17"
    )
  mcux_add_iar_configuration(CC "--dlib_config full")
endif()

if (CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.refenerce)
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES tensorflow/lite/micro/kernels/pooling.cpp
    tensorflow/lite/micro/kernels/depthwise_conv.cpp
    tensorflow/lite/micro/kernels/fully_connected.cpp
    tensorflow/lite/micro/kernels/add.cpp
    tensorflow/lite/micro/kernels/mul.cpp
    tensorflow/lite/micro/kernels/conv.cpp
    tensorflow/lite/micro/kernels/softmax.cpp
    tensorflow/lite/micro/kernels/unidirectional_sequence_lstm.cpp
    tensorflow/lite/micro/kernels/svdf.cpp
    tensorflow/lite/micro/kernels/sub.cpp
    tensorflow/lite/micro/kernels/batch_matmul.cpp
    tensorflow/lite/micro/kernels/logistic.cpp
    tensorflow/lite/micro/kernels/reduce.cpp
    tensorflow/lite/micro/kernels/strided_slice.cpp
    tensorflow/lite/micro/kernels/quantize.cpp
    tensorflow/lite/micro/kernels/lstm_eval.cpp
    tensorflow/lite/micro/kernels/reshape.cpp
    tensorflow/lite/micro/kernels/leaky_relu.cpp
    tensorflow/lite/micro/kernels/transpose_conv.cpp
    tensorflow/lite/micro/kernels/transpose.cpp
    tensorflow/lite/micro/kernels/pad.cpp
    tensorflow/lite/micro/kernels/maximum_minimum.cpp
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.cmsis_nn)
  mcux_add_macro(
    CC "-DCMSIS_NN"
    CX "-DCMSIS_NN"
    )
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES tensorflow/lite/micro/kernels/cmsis_nn/depthwise_conv.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/pooling.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/fully_connected.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/add.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/mul.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/conv.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/softmax.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/unidirectional_sequence_lstm.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/svdf.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/batch_matmul.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/maximum_minimum.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/pad.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/transpose.cpp
    tensorflow/lite/micro/kernels/cmsis_nn/transpose_conv.cpp
    tensorflow/lite/micro/kernels/sub.cpp
    tensorflow/lite/micro/kernels/logistic.cpp
    tensorflow/lite/micro/kernels/reduce.cpp
    tensorflow/lite/micro/kernels/strided_slice.cpp
    tensorflow/lite/micro/kernels/quantize.cpp
    tensorflow/lite/micro/kernels/lstm_eval.cpp
    tensorflow/lite/micro/kernels/reshape.cpp
    tensorflow/lite/micro/kernels/leaky_relu.cpp
    )
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s16.c
    third_party/cmsis_nn/Source/LSTMFunctions/arm_lstm_unidirectional_s8.c
    third_party/cmsis_nn/Source/BasicMathFunctions/arm_elementwise_mul_acc_s16.c
    third_party/cmsis_nn/Source/BasicMathFunctions/arm_elementwise_add_s16.c
    third_party/cmsis_nn/Source/BasicMathFunctions/arm_elementwise_mul_s16_batch_offset.c
    third_party/cmsis_nn/Source/BasicMathFunctions/arm_elementwise_add_s8.c
    third_party/cmsis_nn/Source/BasicMathFunctions/arm_elementwise_mul_s16_s8.c
    third_party/cmsis_nn/Source/BasicMathFunctions/arm_elementwise_mul_s8.c
    third_party/cmsis_nn/Source/BasicMathFunctions/arm_elementwise_mul_s16.c
    third_party/cmsis_nn/Source/BasicMathFunctions/arm_minimum_s8.c
    third_party/cmsis_nn/Source/BasicMathFunctions/arm_maximum_s8.c
    third_party/cmsis_nn/Source/SVDFunctions/arm_svdf_get_buffer_sizes_s8.c
    third_party/cmsis_nn/Source/SVDFunctions/arm_svdf_s8.c
    third_party/cmsis_nn/Source/SVDFunctions/arm_svdf_state_s16_s8.c
    third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.c
    third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.c
    third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.c
    third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.c
    third_party/cmsis_nn/Source/ReshapeFunctions/arm_reshape_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_wrapper_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s4.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_row_offset_s8_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s4.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_even_s4.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_wrapper_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s4.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_fast_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s4_fast.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_3x3_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s8_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_get_buffer_sizes_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_mat_mult_kernel_s4_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s4.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1_x_n_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_nn_depthwise_conv_s8_core.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s8_opt.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s4_opt.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s4.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_1x1_s8_fast.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_wrapper_s4.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_s16.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_transpose_conv_get_buffer_sizes_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_depthwise_conv_get_buffer_sizes_s8.c
    third_party/cmsis_nn/Source/ConvolutionFunctions/arm_convolve_s8.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s16.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_wrapper_s8.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_per_channel_s8.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s16.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_batch_matmul_s8.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8_s64.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s8.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s4.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_s8.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_vector_sum_s8.c
    third_party/cmsis_nn/Source/FullyConnectedFunctions/arm_fully_connected_get_buffer_sizes_s16.c
    third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q7.c
    third_party/cmsis_nn/Source/ActivationFunctions/arm_relu_q15.c
    third_party/cmsis_nn/Source/ActivationFunctions/arm_nn_activation_s16.c
    third_party/cmsis_nn/Source/ActivationFunctions/arm_relu6_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_interleaved_t_even_s4.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_per_ch_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s16.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_q7_to_q15_with_offset.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_s8_to_s16_unordered_with_offset.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8_s32.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s8_s16.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_padded_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s16.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_4x_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mul_core_1x_s4.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_svdf_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s16.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nntables.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_mat_mult_nt_t_s4.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_step_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s16.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s8.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_lstm_calculate_gate_s16.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_depthwise_conv_nt_t_s4.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mul_result_acc_s8_s16.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s4.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_transpose_conv_row_s8_s32.c
    third_party/cmsis_nn/Source/NNSupportFunctions/arm_nn_vec_mat_mult_t_s16_s16.c
    third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_u8.c
    third_party/cmsis_nn/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.c
    third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8.c
    third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s16.c
    third_party/cmsis_nn/Source/SoftmaxFunctions/arm_softmax_s8_s16.c
    third_party/cmsis_nn/Source/PoolingFunctions/arm_max_pool_s16.c
    third_party/cmsis_nn/Source/PoolingFunctions/arm_avgpool_s16.c
    third_party/cmsis_nn/Source/PoolingFunctions/arm_avgpool_s8.c
    third_party/cmsis_nn/Source/PoolingFunctions/arm_avgpool_get_buffer_sizes_s8.c
    third_party/cmsis_nn/Source/PoolingFunctions/arm_avgpool_get_buffer_sizes_s16.c
    third_party/cmsis_nn/Source/PoolingFunctions/arm_max_pool_s8.c
    third_party/cmsis_nn/Source/PadFunctions/arm_pad_s8.c
    third_party/cmsis_nn/Source/TransposeFunctions/arm_transpose_s8.c
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.xtensa)
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES tensorflow/lite/micro/kernels/xtensa/fully_connected_vision.cpp
    tensorflow/lite/micro/kernels/xtensa/pooling_int8.cpp
    tensorflow/lite/micro/kernels/xtensa/depthwise_conv.cpp
    tensorflow/lite/micro/kernels/xtensa/sub.cpp
    tensorflow/lite/micro/kernels/xtensa/conv_hifi.cpp
    tensorflow/lite/micro/kernels/xtensa/conv_int16_reference.cpp
    tensorflow/lite/micro/kernels/xtensa/softmax_vision.cpp
    tensorflow/lite/micro/kernels/xtensa/pooling.cpp
    tensorflow/lite/micro/kernels/xtensa/logistic.cpp
    tensorflow/lite/micro/kernels/xtensa/reduce.cpp
    tensorflow/lite/micro/kernels/xtensa/fully_connected.cpp
    tensorflow/lite/micro/kernels/xtensa/pad_vision.cpp
    tensorflow/lite/micro/kernels/xtensa/pooling_vision.cpp
    tensorflow/lite/micro/kernels/xtensa/add.cpp
    tensorflow/lite/micro/kernels/xtensa/conv_int8_int16.cpp
    tensorflow/lite/micro/kernels/xtensa/conv.cpp
    tensorflow/lite/micro/kernels/xtensa/fully_connected_common_xtensa.cpp
    tensorflow/lite/micro/kernels/xtensa/strided_slice.cpp
    tensorflow/lite/micro/kernels/xtensa/add_vision.cpp
    tensorflow/lite/micro/kernels/xtensa/softmax.cpp
    tensorflow/lite/micro/kernels/xtensa/unidirectional_sequence_lstm.cpp
    tensorflow/lite/micro/kernels/xtensa/conv_int8_reference.cpp
    tensorflow/lite/micro/kernels/xtensa/depthwise_conv_vision.cpp
    tensorflow/lite/micro/kernels/xtensa/quantize.cpp
    tensorflow/lite/micro/kernels/xtensa/lstm_eval.cpp
    tensorflow/lite/micro/kernels/xtensa/depthwise_conv_hifi.cpp
    tensorflow/lite/micro/kernels/xtensa/svdf.cpp
    tensorflow/lite/micro/kernels/xtensa/conv_vision.cpp
    tensorflow/lite/micro/kernels/xtensa/fully_connected_int8.cpp
    tensorflow/lite/micro/kernels/xtensa/softmax_int8_int16.cpp
    tensorflow/lite/micro/kernels/xtensa/conv_common_xtensa.cpp
    tensorflow/lite/micro/kernels/xtensa/reduce_vision.cpp
    tensorflow/lite/micro/kernels/xtensa/reshape.cpp
    tensorflow/lite/micro/kernels/xtensa/reshape_vision.cpp
    tensorflow/lite/micro/kernels/xtensa/leaky_relu.cpp
    tensorflow/lite/micro/kernels/xtensa/transpose_conv.cpp
    tensorflow/lite/micro/kernels/xtensa/pad.cpp
    tensorflow/lite/micro/kernels/xtensa/lstm_eval_hifi.cpp
    tensorflow/lite/micro/kernels/xtensa/decompress.cpp
    tensorflow/lite/micro/kernels/xtensa/dequantize.cpp
    tensorflow/lite/micro/kernels/xtensa/hifimini/fully_connected.cpp
    tensorflow/lite/micro/kernels/xtensa/hifimini/svdf.cpp
    signal/micro/kernels/xtensa/fft_auto_scale_kernel.cpp
    signal/micro/kernels/xtensa/filter_bank_square_root.cpp
    )
  mcux_add_macro(
    CC "-DXTENSA -DNNLIB_V2 -DHIFI4"
    CX "-DXTENSA -DNNLIB_V2 -DHIFI4"
    )
  mcux_add_xtensa_configuration(
    CC "-std=c99"
    CX "-stdlib=libc++ \
    -std=c++17"
    )

endif()

if(CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.neutron)
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES tensorflow/lite/micro/kernels/neutron/neutron.cpp
    tensorflow/lite/micro/kernels/neutron/neutron.h
    third_party/neutron/common/include/*.h
    third_party/neutron/driver/include/*.h
    )

  mcux_add_include(
    INCLUDES tensorflow/lite/micro/kernels/neutron/
    third_party/neutron/common/include
    third_party/neutron/driver/include
    )
  mcux_add_library(
    LIBS third_party/neutron/mcxn/libNeutronDriver.a third_party/neutron/mcxn/libNeutronFirmware.a
    TOOLCHAINS armgcc mcux mdk iar
    DEVICE_IDS MCXN947 MCXN547
    )
  mcux_add_library(
    LIBS third_party/neutron/rt700/libNeutronDriver.a third_party/neutron/rt700/libNeutronFirmware.a
    TOOLCHAINS armgcc mcux mdk iar
    DEVICE_IDS MIMXRT798S
    )
  mcux_add_library(
    LIBS third_party/neutron/rt2660/libNeutronDriver.a
    TOOLCHAINS armgcc mcux mdk iar
    DEVICE_IDS MIMXRT2662xxxxx
    )
  mcux_add_iar_configuration(
    LD "--diag_suppress Li026,Lt069"
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.library)
  mcux_add_iar_configuration(CC "--dlib_config full")
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES third_party/kissfft/tools/*.c
    third_party/kissfft/*.c
    third_party/fft2d/*.c
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.binary)
  mcux_add_library(
    LIBS lib/cm4/iar/tflm.a
    TOOLCHAINS iar
    CORES cm4 cm4f
    )
  mcux_add_library(
    LIBS lib/cm4/mdk/tflm.lib
    TOOLCHAINS mdk
    CORES cm4 cm4f
    )
  mcux_add_library(
    LIBS lib/cm4/armgcc/libtflm.a
    TOOLCHAINS armgcc mcux
    CORES cm4 cm4f
    )

  mcux_add_library(
    LIBS lib/cm7/mdk/tflm.lib
    TOOLCHAINS mdk
    CORES cm7 cm7f
    )
  mcux_add_library(
    LIBS lib/cm7/armgcc/libtflm.a
    TOOLCHAINS armgcc mcux
    CORES cm7 cm7f
    )
  mcux_add_library(
    LIBS lib/cm7/iar/tflm.a
    TOOLCHAINS iar
    CORES cm7 cm7f
    )

  mcux_add_library(
    LIBS lib/cm33/mdk/tflm.lib
    TOOLCHAINS mdk
    CORES cm33 cm33f
    )
  mcux_add_library(
    LIBS lib/cm33/iar/tflm.a
    TOOLCHAINS iar
    CORES cm33 cm33f
    )
  mcux_add_library(
    LIBS lib/cm33/armgcc/libtflm.a
    TOOLCHAINS armgcc mcux
    CORES cm33 cm33f
    )
  mcux_add_library(
    LIBS lib/cm85/armgcc/libtflm.a
    TOOLCHAINS armgcc mcux
    CORES cm85
    )
  mcux_add_library(
    LIBS lib/hifi1/xcc/rt798s/libtflm.a
    TOOLCHAINS xcc xtensa
    CORE_IDS hifi1
    DEVICE_IDS MIMXRT798S
    )
  mcux_add_library(
    LIBS lib/hifi4/xcc/rt798s/libtflm.a
    TOOLCHAINS xcc xtensa
    CORE_IDS hifi4
    DEVICE_IDS MIMXRT798S
    )
  mcux_add_library(
    LIBS lib/hifi4/xcc/rt685s/libtflm.a
    TOOLCHAINS xcc xtensa
    CORE_IDS hifi4
    DEVICE_IDS MIMXRT685S
    )
  mcux_add_library(
    LIBS lib/fusionf1/xcc/rt595s/libtflm.a
    TOOLCHAINS xcc xtensa
    CORE_IDS fusionf1
    DEVICE_IDS MIMXRT595S
    )

if (CONFIG_MCUX_COMPONENT_middleware.eiq.tensorflow_lite_micro.third_party.fft2d)
  mcux_add_source(
    BASE_PATH ${CMAKE_CURRENT_LIST_DIR}
    SOURCES third_party/fft2d/*.c
    third_party/fft2d/*.h
    )
  mcux_add_include(
    INCLUDES third_party/fft2d/
    )
endif()

endif()
