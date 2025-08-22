# 🅿️ Smart Parking System – Arduino IoT Prototype

A **rotating circular smart parking system** controlled with Arduino, RFID authentication, and automated barriers.  
The project simulates a **scalable modular parking solution**, where cars are authenticated via RFID cards, the platform rotates to the nearest free spot, and fees are calculated based on parking time.

---

## 📹 Demo

👉 [Watch the video demonstration](./media/video.mp4)

---

## 👥 Team

- Dumitrașcu Andrei-Mihnea – Documentation, assembly, testing
- Milu Cătălin-Constantin – Hardware & assembly
- Vlăduțu Vlad-Cristian – Control code

---

## 🚀 Features

- **Rotating Parking Platform**

  - Stepper motor (28BYJ-48) rotates to the nearest slot.
  - Entrance is always aligned with slot `0`.

- **RFID Authentication**

  - RC522 RFID reader verifies user access.
  - Each card UID is linked to a parking space.

- **Automated Barrier Gate**

  - Servo motor barrier opens/closes smoothly when a car enters/exits.

- **Dynamic Slot Allocation**

  - Finds the **nearest free space** when a new car arrives.
  - Frees the slot and **computes parking fee** when the car leaves.

- **Pricing System**

  - Calculates parking price per minute (`pricePerMinute` configurable).

- **Modular Architecture**
  - Easily extendable for more spaces or wireless communication between boards.

---

## 🛠️ Hardware Used

- **3x Arduino UNO** (distributed control: RFID, Motor, LCD/barrier)
- **RFID Module MFRC522** + RFID cards
- **Stepper Motor 28BYJ-48** + ULN2003 driver board
- **Servo Motor (SG90)** for barrier gate
- **16x2 LCD Display** (optional for real-time feedback)
- Jumper wires, resistors, breadboards, power supply

---

## 📂 Repository Structure

```
📁 SmartParkingSystem
 ┣ 📜 README.md
 ┣ 📜 SmartParking.ino        # Main code (platform, barrier, parking logic)
 ┣ 📜 RFIDReader.ino          # RFID module sketch
 ┣ 📜 Smart Parking System.docx # Word document project report
 ┣ 📜 video.mp4               # Demo video
```

---

## ⚙️ Setup & Usage

### 1. Clone the Repository

```bash
git clone https://github.com/Dumi17/Smart-Parking-System.git
cd Smart-Parking-System
```

### 2. Upload Code

- Flash `SmartParking.ino` to the Arduino controlling **stepper + servo**.
- Flash `RFIDReader.ino` to the Arduino connected to **RC522**.

### 3. Connect Hardware

- Wire stepper to pins `8, 9, 10, 11`.
- Wire servo to pin `6`.
- Wire RFID RC522 to SPI:
  - `SDA → 10`, `SCK → 13`, `MOSI → 11`, `MISO → 12`, `RST → 9`.

### 4. Run the System

- Open Serial Monitor (`9600 baud`).
- Scan an RFID card to **enter** → platform rotates to free space.
- Scan the same card to **exit** → platform rotates to car → fee is calculated.

---

## 📜 Code Overview

### SmartParking.ino

- `Barrier` class → handles servo barrier.
- `ParkingSpace` class → tracks occupancy, entry time, and fee calculation.
- `ParkingLot` class → manages spaces, card assignments, and platform rotation.
- Optimized rotation using **minimal angular distance**.

### RFIDReader.ino

- Uses **MFRC522 library** to read card UID.
- Sends UID to Serial for processing by main parking controller.

---

## 📈 Future Improvements

- Wireless communication between boards (ESP32 Wi-Fi / Bluetooth).
- Database logging of parking sessions.
- Mobile app integration for slot reservation.
- LCD or OLED display for slot availability & pricing.
