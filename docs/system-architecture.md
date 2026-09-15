# System Architecture

```text
Blynk Android App
        │
        │ Wi-Fi / Internet
        ▼
ESP8266 NodeMCU
   ┌────┼───────────────┬─────────────┐
   ▼    ▼               ▼             ▼
Motor  Servo         Relay         Sensors
Driver Motors        Module        ├─ Soil moisture
   │                    │           └─ DHT sensor
   ▼                    ▼
DC motors             Water pump /
                      auxiliary load
```

The ESP8266 receives commands from Blynk, controls actuators, and publishes sensor values to the configured virtual pins.
