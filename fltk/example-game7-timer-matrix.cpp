#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <sstream>
using namespace std;

const int rows = 5, cols = 5;
Fl_Box* matrix[rows][cols];   // global matrix of boxes
int currentRow = 0, currentCol = 0;

// Timer callback
void update_matrix_cb(void*) {
    // Update current cell with a new value
    string text = "1";  // or to_string(someCounter)
    matrix[currentRow][currentCol]->copy_label(text.c_str());
    matrix[currentRow][currentCol]->redraw();

    // Move to next cell
    currentCol++;
    if (currentCol >= cols) {
        currentCol = 0;
        currentRow++;
    }

    // If we still have cells left, set another timer
    if (currentRow < rows) {
        Fl::repeat_timeout(1.0, update_matrix_cb);  // 1 second delay
    }
}

int main(int argc, char **argv) {
    Fl_Window *win = new Fl_Window(400, 400, "Matrix Updater");

    const int cellSize = 50;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int x = 50 + j * cellSize;
            int y = 50 + i * cellSize;
            matrix[i][j] = new Fl_Box(x, y, cellSize, cellSize, "0");
            matrix[i][j]->box(FL_UP_BOX);
            matrix[i][j]->labelfont(FL_HELVETICA_BOLD);
            matrix[i][j]->labelsize(16);
            matrix[i][j]->align(FL_ALIGN_CENTER);
        }
    }

    win->end();
    win->show(argc, argv);

    // Start the update loop after 1s
    Fl::add_timeout(1.0, update_matrix_cb);

    return Fl::run();
}

