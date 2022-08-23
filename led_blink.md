# Led_Blink
## Header files used

1 `freertos/FreeRTOS.h`this is a header file which helps us work with freertos on esp32.Sets configuration required to run freeRTOS on ESP32

2 `freertos/task.h`Provides multitasking functionality.thus helps in reducing lagg and allows smooth execution of tasks to be performed

3 `driver/gpio.h` Headerfile to help configure GPIO pins.This header file helps carry out various functions involving GPIO pins like setting up the direction of flow of instructions, setting up the output and input value.

4 `sdkconfig.h` Helps in saving the project in sdkconfig root directory.

### use of #define

`#define BLINK_GPIO CONFIG_BLINK_GPIO` is used to setup a string macros for command config_blink_gpio

#### various functions used

`gpio_pad_select_gpio()` This function is used to manually conrtol the pins of Esp32 and use them as scource for input or output.Thus this command helps in puttting the pins into GPIO mode.

`gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT)` This function helps in setting up the mode of a pin as either input only or output only.

**parameters**

1 gpio_num - this is the GPIO number of the pin in question.

2 mode: This simply means the GPIO direction that is either output or input.

**return value**

ESP_OK Success if the process is succesfull

ESP_ERR_INVALID_ARG GPIO error if the process fails

`gpio_set_level(BLINK_GPIO, 0)` This function helps set the output of a pin . 

0 - corresponds to low output

1 - corresponds to high output

**parameters**

1 gpio_num - this is the GPIO number of the pin in question.

2 level - this defines the level of output

**return value**

ESP_OK Success if the process is succesfull

ESP_ERR_INVALID_ARG GPIO error if the process fails.Can occur if the number of GPIO given is wrong.

`vTaskDelay(1000 / portTICK_PERIOD_MS)` This function helps us delay a task by a specified amount of time.The actual time that the task remains blocked depends on the tick rate.The constant portTICK_PERIOD_MS can be used to calculate real time from the tick rate - with the resolution of one tick period.

portTICK_PERIOD_MS = 10ms

1000 / portTICK_PERIOD_MS = 100 ticks

100 * 10ms = 1 sec




