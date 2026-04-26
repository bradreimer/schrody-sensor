// DHT22 monitor for ESP32-C3.
// Reads humidity and temperature from GPIO18 every 10 seconds and
// prints values in metric units (Celsius and %RH).

#include <Arduino.h>
#include <DHT.h>

static constexpr uint8_t DHT_PIN = 18;
static constexpr uint8_t DHT_TYPE = DHT22;
static constexpr uint32_t SAMPLE_INTERVAL_MS = 10000;

// Global DHT22 sensor instance on GPIO18.
DHT dht(DHT_PIN, DHT_TYPE);
// Timestamp of the last successful sampling window check.
uint32_t lastSampleAtMs = 0;

// Initializes serial output and the DHT22 driver.
void setup() {
	Serial.begin(115200);
	dht.begin();

	Serial.println("ESP32-C3 DHT22 monitor - ready");
	Serial.println("Sampling every 10 seconds (Celsius, %RH)");
}

// Samples the sensor every 10 seconds and prints temperature/humidity.
void loop() {
	const uint32_t now = millis();
	// Unsigned subtraction keeps interval checks safe across millis() rollover.
	if (now - lastSampleAtMs < SAMPLE_INTERVAL_MS)
	{
		return;
	}

	lastSampleAtMs = now;

	const float humidity = dht.readHumidity();
	const float temperatureC = dht.readTemperature(false);

	if (isnan(humidity) || isnan(temperatureC))
	{
		Serial.println("DHT22 read failed");
		return;
	}

	Serial.print("Temperature: ");
	Serial.print(temperatureC, 1);
	Serial.print(" C, Humidity: ");
	Serial.print(humidity, 1);
	Serial.println(" %");
}
