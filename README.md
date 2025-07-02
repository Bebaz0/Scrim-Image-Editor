# 📸 Scrim Image Editor

A lightweight, command-driven image editor built in **C++**, capable of interpreting text-based instruction files to perform image manipulations like creating blank images, adding images, applying effects, and saving the results.

---

## 📖 Overview

This project was initially developed as part of an academic assignment at **Faculdade de Engenharia da Universidade do Porto (FEUP)**.

The **baseline code and structure were provided by FEUP**, and subsequently extended by our team:

- **Afonso Lima**  
- **Daniel Rama**  
- **Diogo Coelho**

We expanded the functionality by implementing:
- New **commands**
- The **Image** class  
- The **Color** class  
- The **ScrimParser** class  

This allowed the program to interpret more advanced image editing instructions and manage image data internally with more control.

---

## 📂 Project Structure

```
.
├── build/                # Build output
├── cmake-build-debug/    # CMake debug build
├── expected/             # Expected output images for validation
├── include/              # Header files
├── input/                # Input images
├── main/                 # Main program file
├── output/               # Generated images from commands
├── scrims/               # Command script files (.txt)
├── src/                  # Source code (.cpp)
├── CMakeLists.txt        # CMake build file
└── test_log.txt          # Log file from tests
```

---

## ⚙️ How to Build and Run

1. **Build the project (if not already built)**

Using **CMake**:
```bash
cmake .
make
```

Or via your preferred C++ IDE (CLion / Visual Studio / VSCode C++ plugin)

---

2. **Run the program via the tester executable**

The project includes a `tester.exe` (on Windows builds) to run and validate command sequences.

**Example (on terminal / command prompt):**
```bash
./tester.exe scrims/add1.txt
```

This will process the commands in `scrims/add1.txt` and output images to the `/output/` directory.

---

## 📑 Example Command Script

A `.txt` file with commands might look like:

```
Blank w:400 h:400 fill:255:0:0
Add
Save filename:output/add1.png
```

**Available commands include:**
- `Blank` — Creates a new image of specified width, height and fill color  
- `Open` — Opens an existing image  
- `Add` — Adds an image to the canvas  
- `Save` — Saves the image to a file  

…and more depending on your custom implementation.

---

## 📌 Features

- Text-based command interpretation for image editing
- Load, save and combine images
- Color management via the `Color` class
- Image manipulation through the `Image` class
- Custom parser for reading command scripts
- Easy to test and debug via `tester.exe`

---

## 👨‍💻 Authors

- **Afonso Lima**
- **Daniel Rama**
- **Diogo Coelho**

---

## 📜 Acknowledgments

**Base structure and original implementation by [Faculdade de Engenharia da Universidade do Porto (FEUP)](https://sigarra.up.pt/feup/en/web_page.inicial).**
