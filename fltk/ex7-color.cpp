#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <string>
using namespace std;

int counter = 1;  // global counter

// Callback function for button press
void change_label_cb(Fl_Widget* w, void* data) {
    Fl_Box* box = (Fl_Box*)data;       // Get the label widget
    string text = "naya naam " + to_string(counter++);
		Fl_Color c = fl_rgb_color(255 - (counter*10), 0, 0);
		box->color(c);
    box->label(text.c_str());          // Update label text
    box->redraw();                     // Redraw so changes appear
}

int main(int argc, char **argv) {
    Fl_Window *win = new Fl_Window(400, 200, "Dynamic Label Update");

    Fl_Box *box = new Fl_Box(50, 40, 300, 40, "Original Label");
    box->box(FL_UP_BOX);
    box->labelsize(18);
		box->color(FL_RED);

    Fl_Button *btn = new Fl_Button(150, 120, 100, 30, "Press Me!");
    btn->callback(change_label_cb, (void*)box);

    win->end();
    win->show(argc, argv);
    return Fl::run();
}

