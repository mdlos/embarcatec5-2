# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# compile ASM with /home/mdlos/.pico-sdk/toolchain/13_3_Rel1/bin/arm-none-eabi-gcc
ASM_DEFINES = -DLIB_BOOT_STAGE2_HEADERS=1 -DPICO_32BIT=1 -DPICO_BOARD=\"pico_w\" -DPICO_BUILD=1 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_RP2040=1

ASM_INCLUDES = -I/home/mdlos/.pico-sdk/sdk/2.1.0/src/rp2040/boot_stage2/asminclude -isystem /home/mdlos/.pico-sdk/sdk/2.1.0/src/rp2040/hardware_regs/include -isystem /home/mdlos/.pico-sdk/sdk/2.1.0/src/rp2_common/hardware_base/include -isystem /home/mdlos/.pico-sdk/sdk/2.1.0/src/common/pico_base_headers/include -isystem /home/mdlos/Documentos/Embarcatec/projeto/Atividade-temp/build/generated/pico_base -isystem /home/mdlos/.pico-sdk/sdk/2.1.0/src/boards/include -isystem /home/mdlos/.pico-sdk/sdk/2.1.0/src/rp2040/pico_platform/include -isystem /home/mdlos/.pico-sdk/sdk/2.1.0/src/rp2_common/pico_platform_compiler/include -isystem /home/mdlos/.pico-sdk/sdk/2.1.0/src/rp2_common/pico_platform_panic/include -isystem /home/mdlos/.pico-sdk/sdk/2.1.0/src/rp2_common/pico_platform_sections/include -isystem /home/mdlos/.pico-sdk/sdk/2.1.0/src/rp2040/boot_stage2/include

ASM_FLAGS = -mcpu=cortex-m0plus -mthumb -g -O3 -DNDEBUG

