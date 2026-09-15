[working-principle.md](https://github.com/user-attachments/files/32230566/working-principle.md)
# Working Principle

1. The ESP8266 NodeMCU powers up and connects to the configured Wi-Fi network.
2. Blynk provides the remote-control interface.
3. Commands are processed by the firmware and routed to motor, servo, cutter, and pump outputs.
4. The motor driver controls the DC motors used for movement.
5. The servo motors operate the mechanical attachment mechanism.
6. The soil-moisture sensor is read through `A0` and sent to Blynk on `V1`.
7. Temperature and humidity are read from the DHT sensor and sent on `V2` and `V3`.
