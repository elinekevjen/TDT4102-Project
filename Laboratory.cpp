#include "Laboratory.h"
#include "LabWindow.h"

void Lab::run() {
    LabWindow win;
    
    bool wasMouseDown = false;
    while (!win.should_close()){
        win.drawLab();

        bool isDown = win.is_left_mouse_button_down();

        if (isDown && !wasMouseDown) {
            TDT4102::Point mousePos = win.get_mouse_coordinates();
            win.click(mousePos);
        }
        wasMouseDown = isDown;
        win.next_frame();
}
}