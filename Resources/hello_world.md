# Hello World example:
---
- **App_main**- is the first function called by FreeRTOS application startup  flow. we have to add our code in it. Allows the main function to return at any given point.

 - **freertos/FreeRTOS.h** : Inclusion of this sets configuration required to run freeRTOS on ESP32

- **freertos/task.h**: The tasks as you can guess provide the multitasking functionality, which we will explore in the blinky with hello world example in some time.
---
## What is RTOS: 
IT is a type pf OS  that allows user to perform multiple tasks at the same time.It has a schedular which divides the processing time for different tasks based on priority, FreeRTOS is a just a type of RTOS.

---
- **sdkconfig.h** : Files get saved in sdkconfig root directory after updating using menuconfig.
- **esp_system.h** : This inclusion configures the peripherals in the ESP system. Think of it as system initialization. It's like setting up all the components of your bike, before you could fire the engine!
-  **esp_chip_info**:Fill an esp_chip_info_t structure with information about the chip. 

Parameters 
out_info – [out] structure to be filled 

- **struct esp_chip_info_t** : The structure represents information about the chip. esp_chip_info() function fills esp_chip_info_t structure with information about the chip. This includes the chip revision, number of CPU cores, and a bit mask of features enabled in the chip. 

**Parameters**
out_info – [out] structure to be filled 

Public Members:

1. esp_chip_model_t model:

chip model, one of esp_chip_model_t 

2. uint32_t features:

bit mask of CHIP_FEATURE_x feature flags 

3. uint16_t revision:

chip revision number (in format MXX; where M - wafer major version, XX - wafer minor version) 

4. uint8_t cores

number of CPU cores 

-  **esp_get_minimum_free_heap_size()** : returns the minimum size of free heap memory that has ever been available (i.e., the smallest size of free heap memory in the applications lifetime).
- **esp_err_t esp_flash_get_size** : Detect flash size based on flash ID. Returns ESP_OK on success or a flash error code if operation is failed.
---
## What is Flash Memory:

Flash memory is a non-volatile memory chip used for storage and for transfering data between a personal computer (PC) and digital devices. It has the ability to be electronically reprogrammed and erased. It is often found in USB flash drives, MP3 players, digital cameras and solid-state drives.

## What is SPI:

Serial Peripheral Interface or SPI is a synchronous serial communication protocol that provides full – duplex communication at very high speeds. Serial Peripheral Interface (SPI) is a master – slave type protocol that provides a simple and low cost interface between a microcontroller and its peripherals.When we say short distance communication, it often means communication with in a device or between the devices on the same board (PCB).

## Link for What is SPI in Hindi:

[ click here for the link ]( https://youtu.be/kwmteqdmfNU )  

---
- **spi_flash_get_chip_size** : 
Get flash chip size, as set in binary image header. Returns
    size of flash chip, in bytes .

- **spi_flash_init()** : Initialize SPI flash access driver.
 This function must be called exactly once, before any other spi_flash_* functions are called. Currently this function is called from startup code. There is no need to call it from application code.

- **Uint32_t** : unsigned integer.
- **VtaskDelay**: Delay a task for a given number of ticks. The actual time that the task remains blocked depends on the tick rate. The constant portTICK_PERIOD_MS can be used to calculate real time from the tick rate - with the resolution of one tick period.

portTICK_PERIOD_MS = 10

1000 / portTICK_PERIOD_MS = 100 ticks

100 * 10ms = 1 sec

- **Fflush(stdout)** : The C library function int fflush(FILE *stream) flushes the output buffer of a stream .You would use fflush(stdout) to ensure that whatever you just wrote to a file/the console is indeed written out on disk/the console. The reason is that actually writing, whether to disk, to the terminal,    • or pretty much anywhere else, is pretty slow. Further, writing 1 byte takes roughly the same time as writing, say, a few hundred bytes[1]. Because of this, data you write to a stream is actually stored in a buffer which is flushed when it is full or when you call fflush. Calling fflush means you are accepting that your function call will take a bit of time but that you are 100% sure that you want this out right away.

 


    
    


