/*
 * Copyright 2022-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NEUTRON_DRIVER_H
#define NEUTRON_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "NeutronErrors.h"

/* Neutron Driver error category codes */
typedef enum ERROR_CATEGORY_DRIVER {
    ERROR_CATEGORY_DRIVER_GENERIC,        /* Generic error category */
    ERROR_CATEGORY_DRIVER_UNSUPPORTED,    /* Unsupported function */
    ERROR_CATEGORY_DRIVER_UCODE,          /* Microcode bad magic or version incompatible. */
    ERROR_CATEGORY_DRIVER_INVALID,        /* Invalid arguments */
    ERROR_CATEGORY_DRIVER_BAD_HANDLE,     /* Bad inference handle */
    ERROR_CATEGORY_DRIVER_NO_MEMORY,      /* Not enough memory */
    ERROR_CATEGORY_DRIVER_INTERNAL_FAULT, /* Internal error */
    ERROR_CATEGORY_DRIVER_UNKNOWN_ARCH,   /* Unknown architecture */
    ERROR_CATEGORY_DRIVER_TRACE_NOT_RUN,  /* Tracing did not run, but trace buffer was requested. */
    ERROR_CATEGORY_DRIVER_TIMEOUT         /* Timeout error. */
} ERROR_CATEGORY_DRIVER;

/// Trace configuration to enable kernel level tracing.
#define TRACE_CONFIG_KERNEL_LEVEL (1U << 0)

/// Trace confinguration to enable job level tracing.
#define TRACE_CONFIG_JOB_LEVEL (1U << 1)

// Macro to define where to allocate memory for NeutronCtx
#ifndef NO_HEAP_USAGE
#define NO_HEAP_USAGE 0
#endif

/* Neutron Driver errors */
#define GEN_NEUTRON_DRIVER_ERROR(category, code) GEN_NEUTRON_ERROR(ERROR_COMPONENT_DRIVER, category, code)
#define GEN_NEUTRON_DRIVER_GENERIC_ERROR()       GEN_NEUTRON_DRIVER_ERROR(ERROR_CATEGORY_DRIVER_GENERIC, __LINE__)

/// Type definition for a Neutron model handle. This is an identifier used to uniquely identify a model.
/// The convention is that the value NEUTRON_INVALID_HANDLE handle corresponds to an invalid handle.
typedef void *NeutronModelHandle;

typedef struct {
    /// Neutron microcode buffer address.
    /// The Neutron microcode is generated by the Neutron converter tool.
    /// The microcode buffer, 16 bytes aligned, is allocated and initialized by the application or ML framework.
    /// The microcode buffer is passed by reference to the Neutron firmware.
    /// The microcode buffer is specific for a given ML model.
    const void *microcode;

    /// Neutron weights buffer address.
    /// The Neutron weights is generated by the Neutron converter tool.
    /// The weights buffer, 16 bytes aligned, is allocated and initialized by the application or ML framework.
    /// The weights buffer address is passed by reference to the Neutron-firmware.
    /// The weights buffer is specific for a given ML model.
    const void *weights;

    /// Neutron kernels buffer address.
    /// The Neutron kernels are generated by the Neutron converter tool.
    /// The kernels buffer, 16 bytes aligned, is allocated and initialized by the application or ML framework.
    /// The kernels buffer address is passed by reference to the Neutron-firmware.
    /// The kernels buffer is specific for a given ML model.
    const void *kernels;

    /// Timeout seconds for the microcode running.
    /// This timeout is the uplimit seconds that a user expect to complete, default 60.
    uint32_t timeoutSeconds;

} NeutronModelConfig;

typedef struct {
    /// The input buffers of the model.
    /// The input buffers are allocated and initialized by the application or ML framework.
    /// The input buffers are passed by reference to the Neutron firmware.
    const void **inputs;

    /// The output buffers of the model.
    /// The output buffers are allocated by the application or ML framework.
    /// The output buffers are passed by reference to the Neutron firmware.
    void **outputs;

    /// Scratch buffer required for computing model intermediate results.
    /// If NULL, this buffer has to be allocated by the driver.
    void *scratch;

    /// Scratch buffer required for prefetching model weights from FLASH to SRAM.
    /// This buffer is used only for Neutron-C targets when the weight prefetch option was explicitly used.
    /// If NULL, this buffer has to be allocated by the driver.
    void *scratchWeights;

} NeutronDataConfig;

typedef struct {
    /// Sets whether tracing should be executed during firmware run or not.
    /// If set to 0, tracing will not run.
    /// If set to 1 - kernel level tracing.
    /// If set to 2 - job level tracing.
    /// If set to 3 - mixed level tracing
    uint32_t traceConfig;

    /// Buffer to store collected trace data.
    /// If it is NULLPTR, driver will allocate the memory, otherwise, application can.
    char *traceBuffer;

    /// What is the allocated memory for buffer. Needed to check if appending string will be out of bounds.
    /// Application should set this, if the buffer is allocated by application, otherwise driver will set the value.
    size_t traceBufferSize;
} NeutronTraceConfig;

/// This structure contains the prototypes for functions that have a custom implementation.
/// Any new functions or variables must be added at the end.
typedef struct {
    /// This function performs the copying from FLASH to SRAM.
    void (*copy)(void *dst, void *src, uint32_t size, uint32_t channel);
    /// This is a blocking function that checks if the current copy has finished.
    void (*wait)(uint32_t channel);
} NeutronConfig;

/* Invalid handle, returned by neutronModelPrepare() if an error occurred. */
#define NEUTRON_INVALID_HANDLE NULL

/// - Initialize the Neutron Driver library, setting initial values, do memory allocation
///   for internal data structures, do memory mapping.
NeutronError neutronInit();

/// - Deinitialize the Neutron Driver library, releasing any resources aquired by neutronInit
NeutronError neutronDeinit();

/// - Prepare Neutron execution for a model with custom firmware.
/// - This function is only available for Neutron-S.
NeutronError neutronCustomPrepare(uint32_t *inputSize, int32_t numInputs, uint32_t *outputSize, int32_t numOutputs,
                                  const void *firmware, size_t firmwareSize, NeutronModelHandle *hdl);

/// - Run Neutron custom firmware and get the results.
/// - This function is only available for Neutron-S.
NeutronError neutronCustomExec(NeutronModelHandle hdl, const NeutronDataConfig *neutron_dcfg);

/// - Prepare Neutron execution for a model with the given configuration.
/// - This function only prepares the execution by transferring the parameters to the firmware.
/// - This function allows caching a model and then running the same model but with different
///   input data (assuming the new input data replaces the old input data by reusing the same buffers).
/// - In case external allocated memory shall be used for the ModelHandle, e.g. from the Tensorflow
///   tensor arena, hdl shall be a pointer to the start of the allocated memory block.
//    If a pointer to NULL is passed, memory will be allocated by the driver
///   from HEAP. If no HEAP is available, an error will be thrown.
NeutronError neutronModelPrepare(const NeutronModelConfig *mcfg, NeutronModelHandle *hdl);

/// - Unprepare Neutron execution handle.
/// - This function releases the internal context data structures and the reserved handle.
NeutronError neutronModelUnprepare(NeutronModelHandle hdl);

/// - Perform Neutron execution in blocking mode.
NeutronError neutronRunBlocking(NeutronModelHandle hdl, const NeutronDataConfig *dcfg);

/// - Perform Neutron execution in non-blocking mode.
/// - This functionality is only available for Neutron-S.
NeutronError neutronRunNonBlocking(NeutronModelHandle hdl, const NeutronDataConfig *dcfg);

/// - Wait (block) for Neutron completion.
/// - This functionality is only available for Neutron-S.
NeutronError neutronWait(NeutronModelHandle hdl, const NeutronDataConfig *dcfg);

/// - Query if the job is done by Neutron.
/// - This functionality is only available for neutronRunNonBlocking.
NeutronError neutronIsReady(NeutronModelHandle hdl, bool *isReady);

#ifndef NDEBUG
/// - Set tracing information.
void neutronSetTrace(NeutronModelHandle hdl, NeutronTraceConfig *tcfg);

/// - Get tracing result to buffer.
NeutronError neutronGetTrace(NeutronModelHandle hdl, char **buffer, size_t *size);
#endif

/// - Perform power management to suspend Neutron hardware.
//  - This function disables the clock for Neutron.
NeutronError neutronSuspend();

/// - Perform power management to resume Neutron hardware.
//  - This function enables the clock for Neutron.
NeutronError neutronResume();

/// - Used to initialize custom API's or variables implemented by external application.
NeutronError neutronSetConfig(NeutronConfig *config);

/// - Used to get NeutronContext size.
size_t neutronGetModelContextSize();

/// - Allocates size bytes and returns a pointer to the allocated memory.
///   The returned pointer address will be a multiple of the alignment.
///   Returns NULL on failure.
/// - alignment: Set to 0 if unsure of alignment requirements.
/// - This function is only available for Neutron-S in the Linux environment.
void *neutronMemAlloc(size_t alignment, size_t size);

/// - Frees the memory buffer pointed to by ptr.
/// - This function is only available for Neutron-S in the Linux environment.
void neutronMemFree(void *ptr);

/// Other functions to control the state of driver/firmware.
#ifdef __cplusplus
}
#endif
#endif // NEUTRON_DRIVER_H
