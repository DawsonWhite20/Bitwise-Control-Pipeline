#include <stdio.h>
#include "esp_log.h"
#include "driver/spi_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h";

#include "_74HC595.h"

#define PIN_MOSI 23
#define PIN_MISO -1
#define PIN_CLK 18

// Tag for testing with ESP
static const char *TAG = "MAIN";

void app_main(void) {   
    // ESP32 is the host device
    // SPI2 and SPI3 for general external use
    spi_host_device_t host_device = SPI2_HOST;

    spi_bus_config_t bus_config = {
        .mosi_io_num = PIN_MOSI,
        .miso_io_num = PIN_MISO,
        .sclk_io_num = PIN_CLK,
        .quadwp_io_num = -1, // 4-bit transactions not being utilized
        .quadhd_io_num = -1,
        .max_transfer_sz = 4092,
    };

    ESP_ERROR_CHECK(spi_bus_initialize(host_device, &bus_config, SPI_DMA_CH_AUTO));
    ESP_ERROR_CHECK(_74HC595_init(host_device));

    uint8_t pipeline_data = 0x00; // 0b00000000

    while(1) {
        // Bit shifting to the left by 1
        pipeline_data = pipeline_data << 1; 

        // Shifts a 1 into the pipeline
        pipeline_data |= 0x01;

        // 0x%02X prints the currents state in hex form with a minimum width of 2
        ESP_LOGI(TAG, "Writing pipeline state: 0x%02X", pipeline_data);

        _74HC595_write_byte(pipeline_data);

        vTaskDelay(pdMS_TO_TICKS(400));

        if(pipeline_data == 0xFF) {
            vTaskDelay(pdMS_TO_TICKS(1000));
            pipeline_data = 0x00;
            _74HC595_write_byte(pipeline_data); // Turns off all LEDs
            vTaskDelay(pdMS_TO_TICKS(400));
        }
    }
}
