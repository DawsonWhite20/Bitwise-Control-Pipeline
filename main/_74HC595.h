#ifndef _74HC595_H
#define _74HC595_H

#include "driver/spi_master.h"

/**
 * @brief Initializes the 74HC595 device and adds it to the bus
 * @param host_device Host device (ESP32) of this system
 * @return ESP_OK if successful, otherwise an error code
 */

esp_err_t _74HC595_init(spi_host_device_t host_device);

/**
 * @brief Reads in a byte of data and transmits it to be latched onto the outputs
 * @param data Byte of data to be read and transmitted
 * @return ESP_OK if successful, otherwise an error code
 */

esp_err_t _74HC595_write_byte(uint8_t data);

#endif