#include "driver/spi_master.h"
#include <string.h>

#include "_74HC595.h"

#define PIN_SPICS 5

static spi_device_handle_t _74HC595_handle;

esp_err_t _74HC595_init(spi_host_device_t host_device) {
    spi_device_interface_config_t dev_config = {
        .clock_speed_hz = 1000000, // 1MHz
        .mode = 0, // (CPOL, CPHA) = (0, 0); Device idles at logical low and sampled at logical high
        .queue_size = 1,
        .spics_io_num = PIN_SPICS, // GPIO pin connected to ST_CP
        .flags = SPI_DEVICE_POSITIVE_CS,
    };

    ESP_ERROR_CHECK(spi_bus_add_device(host_device, &dev_config, &_74HC595_handle));

    return ESP_OK;
}

esp_err_t _74HC595_write_byte(uint8_t data) {
    spi_transaction_t transaction;

    // Use memset to clear previous memory in the register
    memset(&transaction, 0, sizeof(transaction));

    transaction.length = 8; // Transmitting 8 bits (1 byte)
    transaction.tx_buffer = &data; // Address of the byte being sent in from main.c
    transaction.rx_buffer = NULL; // No MISO

    ESP_ERROR_CHECK(spi_device_transmit(_74HC595_handle, &transaction));

    return ESP_OK;
}
