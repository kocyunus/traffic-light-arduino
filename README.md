Modular 3D-printed Arduino traffic light • red-yellow-green-yellow loop • zero screws/glue

# 3D-Printed Arduino Traffic Light

> Red → Yellow → Green → **Yellow** → back to Red  
> Press-fit only — no screws or glue.

![Assembled unit](images/assembled_front.png)
📹 [Demo Videosunu Buradan İzleyin](https://youtu.be/r__On8B-lRI)


## Features
- **Modular design** — STL set comes in two flavours  
  *one-shot build plate* **and** *separate STLs* (now **3 files**)
- **Non-blocking firmware** (`millis()` timing)
- **Safe LED drive** — 220 Ω series resistors
- Base and pole are a **single print** for extra rigidity

---

## Bill of Materials

| Qty | Item                               | Notes                |
|----:|------------------------------------|----------------------|
| 1   | Arduino Uno *(or Nano)*            | 5 V board            |
| 3   | LED 5 mm (red / yellow / green)    | Diffused or clear    |
| 3   | 220 Ω resistor, ¼ W                | One per LED          |
| —   | Jumper wires                       | Male–male            |
| 1 set | 3D-printed parts                 | Choose:<br>• `all-in-one_plate.stl`<br>• `base_pole.stl`, `body.stl`, `front_panel.stl`, `rear_cover.stl` |

---

## Printing

- **Quick print:** slice `all-in-one_plate.stl` with your usual PLA profile.  
- **Custom print:** use the individual files if you want multi-colour or different orientations.  
  *Note:* `base_pole.stl` is already oriented flat in the plate; no supports needed.

---

## Wiring & Pinout


LED Red → D0 ─┐
LED Yellow → D1 ┼─ 220 Ω → GND
LED Green → D2 ┘


> **Using Serial?**  
> Pins 0-1 share the USB RX/TX lines. If you need `Serial.print()`, move LEDs to Pins 8-9-10 and update `LED_PINS[]` in `firmware/traffic_light.ino`.



## Uploading the Firmware

```bash
# Arduino IDE
Tools ▸ Board  : “Arduino Uno”
Tools ▸ Port   : COMx / /dev/ttyUSBx
Upload (Ctrl+U)
