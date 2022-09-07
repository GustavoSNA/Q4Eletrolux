################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Calculator.c \
../CalculatorService.c \
../ProtocolParser.c \
../Request.c \
../Response.c \
../UARTHALSimulator.c \
../UserManual.c \
../main.c 

OBJS += \
./Calculator.o \
./CalculatorService.o \
./ProtocolParser.o \
./Request.o \
./Response.o \
./UARTHALSimulator.o \
./UserManual.o \
./main.o 

C_DEPS += \
./Calculator.d \
./CalculatorService.d \
./ProtocolParser.d \
./Request.d \
./Response.d \
./UARTHALSimulator.d \
./UserManual.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


