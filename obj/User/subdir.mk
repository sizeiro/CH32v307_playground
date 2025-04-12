################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v30x_it.c \
../User/gpio.c \
../User/main.c \
../User/system_ch32v30x.c \
../User/tim.c 

OBJS += \
./User/ch32v30x_it.o \
./User/gpio.o \
./User/main.o \
./User/system_ch32v30x.o \
./User/tim.o 

C_DEPS += \
./User/ch32v30x_it.d \
./User/gpio.d \
./User/main.d \
./User/system_ch32v30x.d \
./User/tim.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\MRS_DATA\workspace\CH32v307_playground\Debug" -I"C:\MRS_DATA\workspace\CH32v307_playground\Core" -I"C:\MRS_DATA\workspace\CH32v307_playground\User" -I"C:\MRS_DATA\workspace\CH32v307_playground\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

