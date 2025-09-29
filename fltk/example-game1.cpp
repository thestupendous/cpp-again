#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main() {
    Fl_Window *window = new Fl_Window(800, 600, "FLTK Game Window");
    window->end();
    window->show();
    return Fl::run();
}
