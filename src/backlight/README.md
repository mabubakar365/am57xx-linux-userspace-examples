Here’s a clean, professional **README.md** you can place inside your
`user_programs/backlight/` folder (works great for GitHub):

---

## 🌓 Backlight Control — AM572x EVM Userspace Demo

### 📘 Overview

This program demonstrates how to **control the LCD backlight** from **userspace** on the **TI AM572x EVM** (Sitara) board running Linux.

It interfaces with the kernel’s **backlight sysfs driver** located under `/sys/class/backlight/`, allowing user-level programs to read and set brightness safely — no kernel rebuild or driver modification required.

---

### 🧩 Features

* Reads the current and maximum backlight brightness values
* Dynamically toggles brightness between two levels
* Uses standard Linux file I/O (`fopen`, `fscanf`, `fprintf`)
* Compatible with any backlight device exposed via `/sys/class/backlight/`

---

### 🗂️ File Structure

```
user_programs/
└── backlight/
    ├── backlight_control.c     # C source code
    ├── README.md               # This documentation
    └── Makefile                # (optional) build automation file
```

---

### ⚙️ Build Instructions

Make sure you have `gcc` installed on your AM572x EVM (or cross-compiler if building on host):

```bash
gcc -o backlight_control backlight_control.c
```

---

### ▶️ Run Instructions

Execute the binary as root (required to access sysfs backlight control):

```bash
sudo ./backlight_control
```

Expected output:

```
/sys/class/backlight/backlight/max_brightness
/sys/class/backlight/backlight/brightness
Current brightness: 32 / 255
Setting brightness to 255
Brightness updated successfully
```

You should see the LCD screen brightness **change immediately**.

---

### 📁 Sysfs Interface Used

| Sysfs Path                                      | Description                       |
| ----------------------------------------------- | --------------------------------- |
| `/sys/class/backlight/backlight/max_brightness` | Maximum possible brightness value |
| `/sys/class/backlight/backlight/brightness`     | Current brightness (read/write)   |

---

### 🧠 Code Explanation (Key Sections)

* **`fscanf`**: Reads integer brightness values from sysfs files
* **`fprintf`**: Writes the new brightness value back
* **Logic**: If current brightness < half of max, set to max; else reduce to ¼

This keeps toggling between high and medium brightness each run.

---

### 🧰 Tested On

* **Board:** TI AM572x EVM (Sitara)
* **Kernel:** Default Linux SDK kernel (as shipped with TI Processor SDK)
* **Backlight Driver:** `/sys/class/backlight/backlight`

---

### 💡 Next Steps

* Implement smooth brightness fading using PWM write loops
* Expose brightness control via a simple CLI (e.g., `./backlight_control 128`)
* Integrate with GUI or remote shell scripts for automated display management

---
