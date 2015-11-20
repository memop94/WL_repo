################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/API/State_Machine.c" \
"../Sources/API/WL_AppLayer.c" \

C_SRCS += \
../Sources/API/State_Machine.c \
../Sources/API/WL_AppLayer.c \

OBJS += \
./Sources/API/State_Machine_c.obj \
./Sources/API/WL_AppLayer_c.obj \

OBJS_QUOTED += \
"./Sources/API/State_Machine_c.obj" \
"./Sources/API/WL_AppLayer_c.obj" \

C_DEPS += \
./Sources/API/State_Machine_c.d \
./Sources/API/WL_AppLayer_c.d \

OBJS_OS_FORMAT += \
./Sources/API/State_Machine_c.obj \
./Sources/API/WL_AppLayer_c.obj \

C_DEPS_QUOTED += \
"./Sources/API/State_Machine_c.d" \
"./Sources/API/WL_AppLayer_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/API/State_Machine_c.obj: ../Sources/API/State_Machine.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/API/State_Machine.args" -o "Sources/API/State_Machine_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/API/%.d: ../Sources/API/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/API/WL_AppLayer_c.obj: ../Sources/API/WL_AppLayer.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/API/WL_AppLayer.args" -o "Sources/API/WL_AppLayer_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


