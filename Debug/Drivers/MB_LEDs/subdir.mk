################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MB_LEDs/MB_LEDs.c 

OBJS += \
./Drivers/MB_LEDs/MB_LEDs.o 

C_DEPS += \
./Drivers/MB_LEDs/MB_LEDs.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MB_LEDs/%.o Drivers/MB_LEDs/%.su: ../Drivers/MB_LEDs/%.c Drivers/MB_LEDs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/SerialLogging" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/MachineSensors" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/MachineErrors" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/SysObserver" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/userButtons" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/DriveDataRequest" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/MotorComms" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/MachineSettings" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/FDCAN/MotherBoard" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/FDCAN" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/Eeprom" -I"/home/harsha/STM32CubeIDE/workspace_1.11.0/MainBoard_DF_v7/Drivers/MCP23017" -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-MB_LEDs

clean-Drivers-2f-MB_LEDs:
	-$(RM) ./Drivers/MB_LEDs/MB_LEDs.d ./Drivers/MB_LEDs/MB_LEDs.o ./Drivers/MB_LEDs/MB_LEDs.su

.PHONY: clean-Drivers-2f-MB_LEDs

