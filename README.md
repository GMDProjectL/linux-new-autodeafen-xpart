# Linux Autodeafen X11 Part

Just clicks the 'Scroll Lock' button when started from Wine. Will be fixed in the future.


## Build

**Prerequesites:**

- `cmake`
- `gcc`
- `make`
- `libx11-dev`
- `libxext-dev`
- `libxtst-dev`
- `wine`


Set configure flags to:

-DCMAKE_CXX_COMPILER=wineg++ 
-DCMAKE_C_COMPILER=winegcc


Build in Release mode.