# Agri_Bot NodeMCU 🌱🤖

**An open-source IoT-enabled agricultural robot for easier and more comfortable farming.**

Agri_Bot NodeMCU is a prototype agricultural robot designed to assist farmers through remote operation and selected semi-automatic farming functions. The system uses an **ESP8266 NodeMCU** as its main controller and communicates over Wi-Fi with the **Blynk Android application**.

## Features

- ESP8266 NodeMCU-based control system
- Wi-Fi-enabled remote operation through Blynk
- DC motor-based robot movement
- Motor-driver interface
- Servo-motor actuation
- Relay-controlled auxiliary loads
- DC water-pump operation
- Soil-moisture sensing
- DHT-based temperature and humidity monitoring
- Semi-automatic agricultural tasker attachment concept
- Open-source development workflow

## Hardware

| Component | Function |
|---|---|
| ESP8266 NodeMCU | Main controller and Wi-Fi connectivity |
| DC motors | Robot movement |
| Motor driver | DC motor control |
| Relay module | Switching auxiliary loads |
| DC water pump | Water pumping |
| Mini motor | Auxiliary mechanical operation |
| Servo motors | Angular/mechanical actuation |
| Soil moisture sensor | Soil moisture measurement |
| DHT sensor | Temperature and humidity measurement |
| 12V DC adapter | Motor/pump power source in the prototype |
| 5V DC adapter | Controller power source in the prototype |

## Software and technologies

- Arduino IDE
- ESP8266 Arduino core
- C/C++ using the Arduino framework
- Blynk IoT Android application
- Wi-Fi communication

> Arduino sketches are generally compiled as C++ with Arduino APIs, although the project may be described informally as C-based embedded programming.

## Repository structure

```text
Agri_Bot-NodeMCU/
├── README.md
├── LICENSE
├── .gitignore
├── src/
│   └── esp8266/
│       └── Agri_Bot_NodeMCU.ino
├── hardware/
│   ├── circuit-diagrams/
│   │   └── circuit-diagram.jpg
│   └── components.md
├── software/
│   ├── blynk-setup.md
│   └── libraries.md
├── docs/
│   ├── system-architecture.md
│   ├── working-principle.md
│   ├── power-distribution.md
│   └── testing.md
└── images/
```

## Blynk virtual pins

| Virtual pin | Function |
|---|---|
| V1 | Soil-moisture value |
| V2 | Temperature |
| V3 | Humidity |
| V4 | Servo-angle control |

## Serial movement and actuator commands

| Command | Action |
|---|---|
| `F` | Forward |
| `B` | Backward |
| `L` | Left |
| `R` | Right |
| `S` | Stop |
| `X` | Cutter ON |
| `Y` | Cutter OFF |
| `M` | Pump ON |
| `N` | Pump OFF |

## Setup

1. Install Arduino IDE.
2. Install the ESP8266 board package.
3. Install the required libraries:
   - Blynk
   - DHT sensor library
   - Servo library compatible with ESP8266
4. Open `src/esp8266/Agri_Bot_NodeMCU.ino`.
5. Replace the credential placeholders locally:
   - `YOUR_BLYNK_AUTH_TOKEN`
   - `YOUR_WIFI_NAME`
   - `YOUR_WIFI_PASSWORD`
6. Select the correct ESP8266 NodeMCU board and port.
7. Verify the actual wiring before uploading.

## Safety and verification notes

- Never publish real Wi-Fi credentials or Blynk authentication tokens.
- The original report uses `GPIO10` for the pump output. Verify this connection carefully because GPIO10 may be connected to flash memory on common ESP8266 boards.
- Confirm whether the installed DHT sensor is DHT11 or DHT22 before final deployment.
- Confirm relay active-HIGH/active-LOW behavior.
- Use a suitable motor driver and separate power path for motors and the pump.
- Ensure a common ground where required by the circuit design.

## Future scope

- Improve and refine the mechanical structure for more precise testing.
- Fully automate the currently semi-automatic tasker attachment.
- Add ploughing functionality.
- Add plant-growth monitoring.
- Support additional traditional farming practices.
- Introduce modular agricultural attachments and improved sensing.

## License

This project is intended for open-source educational and development use. Add the final license text after deciding whether to use MIT, Apache-2.0, or another license.

## Author

**Abhijith Sudhakaran**
