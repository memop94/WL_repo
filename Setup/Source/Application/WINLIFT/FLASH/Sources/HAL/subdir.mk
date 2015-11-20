################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/HAL/GPIO_APP.c" \
"../Sources/HAL/Global_Init.c" \

C_SRCS += \
../Sources/HAL/GPIO_APP.c \
../Sources/HAL/Global_Init.c \

OBJS += \
./Sources/HAL/GPIO_APP_c.obj \
./Sources/HAL/Global_Init_c.obj \

OBJS_QUOTED += \
"./Sources/HAL/GPIO_APP_c.obj" \
"./Sources/HAL/Global_Init_c.obj" \

C_DEPS += \
./Sources/HAL/GPIO_APP_c.d \
./Sources/HAL/Global_Init_c.d \

OBJS_OS_FORMAT += \
./Sources/HAL/GPIO_APP_c.obj \
./Sources/HAL/Global_Init_c.obj \

C_DEPS_QUOTED += \
"./Sources/HAL/GPIO_APP_c.d" \
"./Sources/HAL/Global_Init_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/HAL/GPIO_APP_c.obj: ../Sources/HAL/GPIO_APP.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/HAL/GPIO_APP.args" -o "Sources/HAL/GPIO_APP_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/HAL/%.d: ../Sources/HAL/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/HAL/Global_Init_c.obj: ../Sources/HAL/Global_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/HAL/Global_Init.args" -o "Sources/HAL/Global_Init_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


