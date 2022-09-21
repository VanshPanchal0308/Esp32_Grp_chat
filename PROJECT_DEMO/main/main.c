#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/param.h>
#include "esp_log.h"
#include "esp_console.h"
#include "esp_system.h"
#include "linenoise/linenoise.h"
#include "argtable3/argtable3.h"
#include "sys/queue.h"
#include "data_transfer.h"
#include "mesh_new.h"
#include "nvs_flash.h"


static const char *TAG = "conslole_main";
#define PROMPT_STR "Sent: "
const char *prompt = LOG_COLOR_I PROMPT_STR "> "LOG_RESET_COLOR;

static void initialize_nvs(void)
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);
}

static void initialize_console(void)
{
    /* Drain stdout before reconfiguring it */
    fflush(stdout);
    fsync(fileno(stdout));

    /* Disable buffering on stdin */
    setvbuf(stdin, NULL, _IONBF, 0);

    /* Minicom, screen, idf_monitor send CR when ENTER key is pressed */
    esp_vfs_dev_uart_port_set_rx_line_endings(CONFIG_ESP_CONSOLE_UART_NUM, ESP_LINE_ENDINGS_CR);
    /* Move the caret to the beginning of the next line on '\n' */
    esp_vfs_dev_uart_port_set_tx_line_endings(CONFIG_ESP_CONSOLE_UART_NUM, ESP_LINE_ENDINGS_CRLF);

    /* Configure UART. Note that REF_TICK is used so that the baud rate remains
     * correct while APB frequency is changing in light sleep mode.
     */
    const uart_config_t uart_config = {
        .baud_rate = CONFIG_ESP_CONSOLE_UART_BAUDRATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .source_clk = UART_SCLK_REF_TICK,
    };
    /* Install UART driver for interrupt-driven reads and writes */
    ESP_ERROR_CHECK(uart_driver_install(CONFIG_ESP_CONSOLE_UART_NUM,
                                        256, 0, 0, NULL, 0));
    ESP_ERROR_CHECK(uart_param_config(CONFIG_ESP_CONSOLE_UART_NUM, &uart_config));

    /* Tell VFS to use UART driver */
    esp_vfs_dev_uart_use_driver(CONFIG_ESP_CONSOLE_UART_NUM);

    /* Initialize the console */
    esp_console_config_t console_config = {.max_cmdline_args = 8,
                                           .max_cmdline_length = 256,
#if CONFIG_LOG_COLORS
                                           .hint_color = atoi(LOG_COLOR_CYAN)
#endif
    };
    ESP_ERROR_CHECK(esp_console_init(&console_config));

    /* Configure linenoise line completion library */
    /* Enable multiline editing. If not set, long commands will scroll within
     * single line.
     */
    linenoiseSetMultiLine(1);

    /* Tell linenoise where to get command completions and hints */
    linenoiseSetCompletionCallback(&esp_console_get_completion);
    linenoiseSetHintsCallback((linenoiseHintsCallback *)&esp_console_get_hint);

    /* Set command history size */
    linenoiseHistorySetMaxLen(100);

    /* Don't return empty lines */
    linenoiseAllowEmpty(false);
 /*message the prompt again for message
         */
        /*take user input typed at the prompt*/
        char *line = linenoise(prompt);
        /*prompt again if the string is empty*/
        while (line == NULL) { /* Break on EOF or error */
            ESP_LOGW(TAG, "Enter a message!!");
            line = linenoise(prompt);
        }
        /* Add the command to the history if not empty*/
        if (strlen(line) > 0)
        {
            linenoiseHistoryAdd(line);

        }
}
void task_console()
{
    console_to_espmesh_send = xQueueCreate(10, 250 * sizeof(char));
    while (1)
    {
        /* Get a line using linenoise.
         * The line is returned when ENTER is pressed.
         *if the user enters a null message the prompt again for message
         */
        /*take user input typed at the prompt*/
        char *line = linenoise(prompt);
        /*prompt again if the string is empty*/
        while (line == NULL) { /* Break on EOF or error */
            ESP_LOGW(TAG, "Enter a message!!");
            line = linenoise(prompt);
        }
        /* Add the command to the history if not empty*/
        if (strlen(line) > 0)
        {
            linenoiseHistoryAdd(line);
#if CONFIG_STORE_HISTORY
            /* Save command history to filesystem */
            linenoiseHistorySave(HISTORY_PATH);
#endif
            if (xQueueSend(console_to_espmesh_send, &line, portMAX_DELAY) != pdTRUE)
            {
                ESP_LOGW(TAG, "Send data to esp now failed.........");
            }
            espmesh_start();
        }
        /* linenoise allocates line buffer on the heap, so need to free it */
        linenoiseFree(line);
        vTaskSuspend(console);
    }

}

void app_main(void)
{
     initialize_console();
    /*setup espnow interconnection*/
    esp_main(void);//

    ESP_LOGI("\nChat Communication\n");
    xTaskCreate(task_console, "task_console", 3000, NULL, 3, &console);

}


