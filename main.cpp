#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <string>

int main(int argc, char** argv){
    int keycode = std::stoi(argv[argc -1]);

    Display *display = XOpenDisplay(NULL);
    XTestFakeKeyEvent(display, keycode, True, 0);
    XFlush(display);
    XTestFakeKeyEvent(display, keycode, False, 0);
    XFlush(display);
    XCloseDisplay(display);
}
