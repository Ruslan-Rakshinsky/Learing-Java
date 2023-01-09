#include <exception>
#include <iostream>
#include "Window.h"

int main(int, char **) {
    try {
        Window* window = new Window(800, 600, "Test-1");
    } catch (std::exception const & e) {
        std::cerr << e.what();
    }
}
