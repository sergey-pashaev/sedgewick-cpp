#ifndef CLI_GRAPH_H
#define CLI_GRAPH_H

#include <algorithm>
#include <iomanip>
#include <iostream>

namespace psv {

template <typename Func>
void DrawCLIGraph(int x_min, int x_max, Func f, int y_min, int y_max, int rows,
                  int cols, const char* x_label, const char* y_label,
                  std::ostream& out = std::cout) {
    const int x_step = (x_max - x_min) / rows;
    const int x_tail = (x_max - x_min) % rows;
    const int y_step = y_max / cols;

    out << "     +" << std::setfill('-') << std::setw(cols - 1) << ""
        << "> Y, " << y_label << '\n'
        << std::setfill(' ');

    for (int i = 0; i < rows + (x_tail ? 2 : 1); ++i) {
        const int x = std::min(x_min + i * x_step, x_max);
        std::cout << std::setfill(' ') << std::setw(4) << x << " |";
        const int y = y_min + f(x);
        std::cout << std::setfill('*') << std::setw(y / y_step) << "" << ' '
                  << y << '\n';
    }
    std::cout << std::setfill(' ');
    std::cout << "     V\n";
    std::cout << "     X, " << x_label << '\n';
}

}  // namespace psv

#endif /* CLI_GRAPH_H */
