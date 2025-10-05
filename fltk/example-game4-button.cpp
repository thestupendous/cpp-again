#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <string>
using std::string,std::to_string;

int i=1;
// Callback to change label
void change_label_cb(Fl_Widget* w, void* data) {
    Fl_Box* box = (Fl_Box*)data;        // The label widget
		string c = string("naya naam ") + (to_string(i++));
		// const char *a = c.c_str();
    box->label(c.c_str());      // Update label
    box->redraw();                      // Force redraw to see the change
}

int main(int argc, char **argv) {
    Fl_Window *win = new Fl_Window(400, 200, "FLTK Label Update");

    Fl_Box *box = new Fl_Box(50, 40, 300, 40, "Original Label");
    box->box(FL_UP_BOX);
    box->labelsize(18);

    Fl_Button *btn = new Fl_Button(150, 120, 100, 30, "Change Label");
    btn->callback(change_label_cb, (void*)box );

    win->end();
    win->show(argc, argv);
    return Fl::run();
}
