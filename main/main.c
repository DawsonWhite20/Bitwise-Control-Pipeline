#include <stdio.h>
#include "esp_log.h"
#include "driver/spi_master.h"

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

    while(1) {
        
    }
}
