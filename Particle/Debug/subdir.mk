################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Animation.cpp \
../DrawScreen.cpp \
../Random.cpp \
../main.cpp 

OBJS += \
./Animation.o \
./DrawScreen.o \
./Random.o \
./main.o 

CPP_DEPS += \
./Animation.d \
./DrawScreen.d \
./Random.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/usr/include/SDL2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


