#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <string>
using namespace std;

int main(int argc, char **argv) {
    const int rows = 5, cols = 5;
    const int cell_w = 60, cell_h = 40;   // size of each cell
    const int start_x = 20, start_y = 20; // margin

    Fl_Window *win = new Fl_Window(400, 300, "5x5 Matrix");

    Fl_Box* matrix[rows][cols];  // 2D array of pointers to labels

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Create a unique label name like "l00", "l01", ..., "l44"
            string name = "l" + to_string(i) + to_string(j);

            // Place each box at calculated position
            matrix[i][j] = new Fl_Box(
                start_x + j * cell_w,   // x
                start_y + i * cell_h,   // y
                cell_w - 5,             // width
                cell_h - 5,             // height
                name.c_str()
            );

            // Set appearance
            matrix[i][j]->box(FL_UP_BOX);
            matrix[i][j]->labelsize(14);
						matrix[i][j]->copy_label(name.c_str());
        }
    }

    win->end();
    win->show(argc, argv);
    return Fl::run();
}
#if 0
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <string>
using namespace std;

int main(int argc, char **argv) {
    Fl_Window *win = new Fl_Window(400, 400, "5x5 Matrix");

    const int rows = 5, cols = 5;
    const int cellSize = 50;  // size of each cell
    Fl_Box* matrix[rows][cols];  // store pointers for later access

    // Create 5x5 grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int x = 50 + j * cellSize;   // column position
            int y = 50 + i * cellSize;   // row position
            matrix[i][j] = new Fl_Box(x, y, cellSize, cellSize, "0");
            matrix[i][j]->box(FL_UP_BOX);
            matrix[i][j]->labelfont(FL_HELVETICA_BOLD);
            matrix[i][j]->labelsize(16);
            matrix[i][j]->align(FL_ALIGN_CENTER);
        }
    }

    win->end();
    win->show(argc, argv);
    return Fl::run();
}
#endif
