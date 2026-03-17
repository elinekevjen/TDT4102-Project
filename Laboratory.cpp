#include "Laboratory.h"
#include "LabWindow.h"

void Lab::run() {
    LabWindow win;
    
    while (!win.should_close()){
        win.drawLab();

        if (win.is_left_mouse_button_down()) {
            TDT4102::Point mousePos = win.get_mouse_coordinates();
            win.click(mousePos);
        }
        win.next_frame();
    }
}