################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/MCXN947_Project_pwm_1.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/MCXN947_Project_pwm_1.d \
./source/semihost_hardfault.d 

OBJS += \
./source/MCXN947_Project_pwm_1.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MCXN947VDF -DCPU_MCXN947VDF_cm33 -DCPU_MCXN947VDF_cm33_core0 -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\board" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\source" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\drivers" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\device" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\utilities\debug_console" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\component\uart" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\utilities\debug_console\config" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\component\serial_manager" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\component\lists" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\device\periph" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\utilities" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\CMSIS" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\CMSIS\m-profile" -I"C:\Users\Lenovo\Documents\MCUXpressoIDE_25.6.136\workspace\MCXN947_Project_pwm_1\utilities\str" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/MCXN947_Project_pwm_1.d ./source/MCXN947_Project_pwm_1.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

