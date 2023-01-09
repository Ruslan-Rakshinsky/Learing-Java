#include <cstdlib>
#include <exception>
#include <iostream>
#include "Window.h"

int main(int, char **) {
    try {
        Window* window = new Window(800, 600, "Test-1");
        return EXIT_SUCCESS;
    } catch (std::exception const & e) {
        std::cerr << e.what();
        return EXIT_FAILURE;
    }
}
