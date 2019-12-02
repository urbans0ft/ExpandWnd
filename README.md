# ExpandWnd
Expands a Window to fit the screen's work area without maximizing it.

## Usage

Add `expandwnd.exe` to a directory which is contained in your `PATH` evnironment variable.
Then use the run command `<win> + r` or type into a CMD:

    expandwnd "<window title>"
    
`<window title>` is case sensitive and will match the first window whose title contains `<window title>`.

If used in a console environment the ouput indicates success or failure:

**Success example**

    > expandwnd "<window title>"
    Searching: "<window title>"
    Found: "A caption containing <window title> somewhere."
    Repositioning window.
    x:      1920
    width:  1920
    y:      0
    height: 1040

**Error example**

    > expandwnd "<window title>"
    Searching: "<window title>"
    Could not find: "<window title>"


## Compiling

### Cygwin

g++ -o expandwnd expandwnd.cpp

### GCC&mdash;32bit

i686-w64-mingw32-g++ -s -o expandwnd -static expandwnd.cpp

### GCC&mdash;64bit

x86_64-w64-mingw32-g++ -s -o expandwnd -static expandwnd.cpp
