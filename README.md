# UVSee

Ultra-violet Light Sensor (Arduino, Bluetooth, Serial)

A simple wireless and battery operated UV sensor module.  One possible use is to detect the presence of UV light (including UV-C) inside a disinfection chamber (ie, a light-sealed opaque box).  The UV-C radiation is harmful to skin, eyes and so it must be inside a sealed enclosure.  Exposure is set via a timer, typically a few minutes to an hour.  During that interval, it is useful to know if the UV-C light *actually* operational during that (light) soak time.  Since you are not allowed to look inside the box when the light is turned on, the UV dector is needed to confirm correct operation for the duration of the exposure.


## Parts Needed

Implemented using easily-available parts:
- **Arduino Nano**
- **guva-s12sd** UV sensor (analog voltage-based)
- **hc-05** or **hm-10** bluetooth serial modules
- **lipo battery** 4.2v rechargeable (hobby quadcopter, etc)


## Application

The arduino nano module, two of the guva-s12sd sensors and the bluetooth module are all mounted on a single general-purpose perf board, with wire-wrap wires used for a one-off prototype build.

Power is supplied by a 3.7-4.2v lithium poly battery.  These are commonly used for "hobby drones"; they are cheap and charges are easily available.  To keep the sensor board smaller, no charging circuit was included.


## Serial Data Stream

The bluetooth modules (hc-05 for bluetooth classic, or hm-10 for BLE) allow and easy and OS-independant way to have a "wireless serial connection" between 2 systems.  The arduino sensor module and its BT transmitter is the data sender, while a matching BT receiver is connected to a USB/serial cable such as FTDI, pl2303, cp2102 or equiv.  Speed is not critical as the data payload is very short (timestamp, sensor1_value, sensor2_value).  Simple ASCII is used to allow ease of viewing (even on android/apple phones using a BT terminal app).


# Sensor Redundancy

Two vendor modules were purchased, just to have variety and some redundancy.  As it turns out, the two modules have different gains or sensitivities and we can use that for some diversity averaging.  Modules were sourced from Amazon; here are sample links:

- https://www.amazon.com/gp/product/B07VX6DTJT
- https://www.amazon.com/gp/product/B00LEVTOB0
