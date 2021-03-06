################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Exceptions.c" \
"../Sources/GPIO_State.c" \
"../Sources/IntcInterrupts.c" \
"../Sources/Time_counter.c" \
"../Sources/WL_EIRQ.c" \
"../Sources/WL_FUNCTIONS.c" \
"../Sources/WL_GPIO.c" \
"../Sources/WL_STM.c" \
"../Sources/WL_SYS_INIT.c" \
"../Sources/WL_WinProcessing.c" \
"../Sources/external_interrupts.c" \
"../Sources/ivor_branch_table.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/Exceptions.c \
../Sources/GPIO_State.c \
../Sources/IntcInterrupts.c \
../Sources/Time_counter.c \
../Sources/WL_EIRQ.c \
../Sources/WL_FUNCTIONS.c \
../Sources/WL_GPIO.c \
../Sources/WL_STM.c \
../Sources/WL_SYS_INIT.c \
../Sources/WL_WinProcessing.c \
../Sources/external_interrupts.c \
../Sources/ivor_branch_table.c \
../Sources/main.c \

OBJS += \
./Sources/Exceptions_c.obj \
./Sources/GPIO_State_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/Time_counter_c.obj \
./Sources/WL_EIRQ_c.obj \
./Sources/WL_FUNCTIONS_c.obj \
./Sources/WL_GPIO_c.obj \
./Sources/WL_STM_c.obj \
./Sources/WL_SYS_INIT_c.obj \
./Sources/WL_WinProcessing_c.obj \
./Sources/external_interrupts_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/Exceptions_c.obj" \
"./Sources/GPIO_State_c.obj" \
"./Sources/IntcInterrupts_c.obj" \
"./Sources/Time_counter_c.obj" \
"./Sources/WL_EIRQ_c.obj" \
"./Sources/WL_FUNCTIONS_c.obj" \
"./Sources/WL_GPIO_c.obj" \
"./Sources/WL_STM_c.obj" \
"./Sources/WL_SYS_INIT_c.obj" \
"./Sources/WL_WinProcessing_c.obj" \
"./Sources/external_interrupts_c.obj" \
"./Sources/ivor_branch_table_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/Exceptions_c.d \
./Sources/GPIO_State_c.d \
./Sources/IntcInterrupts_c.d \
./Sources/Time_counter_c.d \
./Sources/WL_EIRQ_c.d \
./Sources/WL_FUNCTIONS_c.d \
./Sources/WL_GPIO_c.d \
./Sources/WL_STM_c.d \
./Sources/WL_SYS_INIT_c.d \
./Sources/WL_WinProcessing_c.d \
./Sources/external_interrupts_c.d \
./Sources/ivor_branch_table_c.d \
./Sources/main_c.d \

OBJS_OS_FORMAT += \
./Sources/Exceptions_c.obj \
./Sources/GPIO_State_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/Time_counter_c.obj \
./Sources/WL_EIRQ_c.obj \
./Sources/WL_FUNCTIONS_c.obj \
./Sources/WL_GPIO_c.obj \
./Sources/WL_STM_c.obj \
./Sources/WL_SYS_INIT_c.obj \
./Sources/WL_WinProcessing_c.obj \
./Sources/external_interrupts_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \

C_DEPS_QUOTED += \
"./Sources/Exceptions_c.d" \
"./Sources/GPIO_State_c.d" \
"./Sources/IntcInterrupts_c.d" \
"./Sources/Time_counter_c.d" \
"./Sources/WL_EIRQ_c.d" \
"./Sources/WL_FUNCTIONS_c.d" \
"./Sources/WL_GPIO_c.d" \
"./Sources/WL_STM_c.d" \
"./Sources/WL_SYS_INIT_c.d" \
"./Sources/WL_WinProcessing_c.d" \
"./Sources/external_interrupts_c.d" \
"./Sources/ivor_branch_table_c.d" \
"./Sources/main_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Exceptions_c.obj: ../Sources/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Exceptions.args" -o "Sources/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/GPIO_State_c.obj: ../Sources/GPIO_State.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/GPIO_State.args" -o "Sources/GPIO_State_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/IntcInterrupts_c.obj: ../Sources/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/IntcInterrupts.args" -o "Sources/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Time_counter_c.obj: ../Sources/Time_counter.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Time_counter.args" -o "Sources/Time_counter_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/WL_EIRQ_c.obj: ../Sources/WL_EIRQ.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/WL_EIRQ.args" -o "Sources/WL_EIRQ_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/WL_FUNCTIONS_c.obj: ../Sources/WL_FUNCTIONS.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/WL_FUNCTIONS.args" -o "Sources/WL_FUNCTIONS_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/WL_GPIO_c.obj: ../Sources/WL_GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/WL_GPIO.args" -o "Sources/WL_GPIO_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/WL_STM_c.obj: ../Sources/WL_STM.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/WL_STM.args" -o "Sources/WL_STM_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/WL_SYS_INIT_c.obj: ../Sources/WL_SYS_INIT.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/WL_SYS_INIT.args" -o "Sources/WL_SYS_INIT_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/WL_WinProcessing_c.obj: ../Sources/WL_WinProcessing.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/WL_WinProcessing.args" -o "Sources/WL_WinProcessing_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/external_interrupts_c.obj: ../Sources/external_interrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/external_interrupts.args" -o "Sources/external_interrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ivor_branch_table_c.obj: ../Sources/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ivor_branch_table.args" -o "Sources/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


