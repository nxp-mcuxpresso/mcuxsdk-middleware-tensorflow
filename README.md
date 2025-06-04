# MCUXpresso SDK : mcuxsdk-middleware-tensorflow

## Overview
This repository is for MCUXpresso SDK TensorFlow-Lite for Microcontroller middleware delivery and it contains the components officially provided in NXP MCUXpresso SDK. This repository is part of the MCUXpresso SDK overall delivery which is composed of several sub-repositories/projects. Navigate to the top/parent repository (mcuxsdk-manifests) for the complete delivery of MCUXpresso SDK.

## Documentation
Overall details can be reviewed here: [MCUXpresso SDK Online Documentation](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/introduction/README.html)  

Visit [eIQ Tensorflow Lite for Micro - Documentation](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/middleware/eiq/tensorflow-lite/docs/ugindex.html) to review details on the contents in this sub-repo.  

## Setup
Instructions on how to install the MCUXpresso SDK provided from GitHub via west manifest [Getting Started with SDK - Detailed Installation Instructions](https://mcuxpresso.nxp.com/mcuxsdk/latest/html/gsd/installation.html#installation)

## Contribution
Contributions are not currently accepted. Guidelines to contribute will be posted in the future.

---------------------------------
## Directory Structure

* **lib** - Prebuilt library of TensorFlow-Lite for NXP MCU (Cortex-M33, Cortex-M4, Cortex-M7, Fusion1 DSP, HiFi1 DSP, HiF4 DSP) to allow easily develop ML applications based on prebuilt library.

* **tensorflow** - Folder contains source code for Tensorflow-Lite for Microcontroller to allow user to build and debug TFLM library.

* **third_party** - Folder contains source code for optimized kernels for Cortex-M(cmsis_nn) and NXP eIQ Neutron NPU(neutron).

* **docs** - Folder contains eIQ TFLM Library User Guide.
