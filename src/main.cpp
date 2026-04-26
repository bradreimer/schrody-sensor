/**
 * @file    main.cpp
 * @brief   DHT22 monitor for Seeed Studio XIAO ESP32-C6
 *
 * Reads humidity and temperature from a DHT22 sensor on GPIO18 every
 * 10 seconds and prints the values over serial in metric units.
 */

#include <Arduino.h>
#include <DHT.h>

static constexpr uint8_t DHT_PIN = 18;
static constexpr uint8_t DHT_TYPE = DHT22;
static constexpr uint32_t SAMPLE_INTERVAL_MS = 10000;

DHT dht(DHT_PIN, DHT_TYPE);
uint32_t lastSampleAtMs = 0;

void setup() {
    Serial.begin(115200);
    dht.begin();

    Serial.println("XIAO ESP32-C6 DHT22 monitor - ready");
    Serial.println("Sampling every 10 seconds (Celsius, %RH)");
}

void loop() {
    const uint32_t now = millis();
    if (now - lastSampleAtMs < SAMPLE_INTERVAL_MS) {
        return;
    }

    lastSampleAtMs = now;

    const float humidity = dht.readHumidity();
    const float temperatureC = dht.readTemperature(false);

    if (isnan(humidity) || isnan(temperatureC)) {
        Serial.println("DHT22 read failed");
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperatureC, 1);
    Serial.print(" C, Humidity: ");
    Serial.print(humidity, 1);
    Serial.println(" %");
}
