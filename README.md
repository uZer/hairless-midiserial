# Hairless MIDI<->Serial Bridge

Hairless MIDI<->Serial Bridge is the easiest way to connect serial devices (like Arduinos) to send and receive MIDI signals. This is a fork of the [original project](http://projectgus.github.com/hairless-midiserial/) which adds additional functionality.

**This fork has only been tested with macOS Mojave!**

## Things added by this fork

### Command-line support

- Command-line options to set debug mode, serial device and MIDI ports.
- Output messages to console.
- Ability to hide the GUI.

#### Command-line options

```sh
$ ./hairless-midiserial -h
Usage: ./hairless-midiserial [options]
Sends and receives MIDI events over a serial device.

Options:
  -h, --help                 Displays help on commandline options.
  --help-all                 Displays help including Qt specific options.
  -v, --version              Displays version information.
  -d, --debug                Show debug MIDI messages
  -c, --console-output       Output messages to the console
  -w, --hide-window          Hides the GUI
  -s, --serial <serial>      Specify the name of the serial device to use
  -i, --midi-in <midi-in>    Specify the name of MIDI in device to use
  -o, --midi-out <midi-out>  Specify the name of MIDI out device to use
```

For example:

```
$ ./hairless-midiserial -w -c -d \
    -s /dev/cu.usbserial-A105J2JO \
    -o "IAC Driver IAC Bus 1" \
    -i "IAC Driver IAC Bus 2"
Opening serial port '/dev/cu.usbserial-A105J2JO'...
Opening MIDI Out port #0
Opening MIDI In port #1
```

### Compiled with newer Qt

- Dark theme support on macOS, higher resolution window

## Building Hairless Bridge from source

Hairless uses git submodules for library dependencies, so you should use `git clone --recursive URL` when cloning from Github. Alternatively, you can run `git submodule update --init` in order to fetch the submodules to an already-cloned directory.

Hairless Midiserial Bridge release 0.5 was built with Qt 5.14.

The Qt package should contain all dependencies, the graphical IDE "Qt Creator" or the program "qmake" can be used to compile the project hairless-midiserial.pro.

On Windows I recommend building with the [MingGW compiler](http://www.mingw.org/), Visual Studio has not been tested. Neither the MinGW site nor Qt's new owners Digia still distribute older MinGW builds, and MinGW 4.7 is too new for precompiled Qt 4.7.x, so it can be a bit hard to find a prebuilt combination that work. Recently I downloaded `mingw-static-4.4.5-all.7z` from [this Google Code project](https://code.google.com/p/qp-gcc/downloads/list), and can confirm that works.

(For the Windows release builds I actually [cross-build under Linux using wine, as described here](http://projectgus.com/2011/09/developing-qt-apps-for-windows-using-linux-wine/).)

# Libraries

- [qextserialport](https://code.google.com/p/qextserialport/) is hosted on Github and is linked into the source tree as a git submodule.
- [The RtMidi library](https://github.com/thestk/rtmidi) is hosted on Github and is linked into the source tree as a git submodule.

Both libraries are small so they compiled as source files directly into Hairless Bridge, not linked as libraries.

# Release builds

The official releases are static linked, so they've actually been built against Qt versions that were compiled from source, configured with `-static` for static linking.
