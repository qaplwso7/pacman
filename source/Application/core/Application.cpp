#include "Application.h"

int Application::run() {
    try {
        while(m_ptr_state_current->do_step())
            apply_deffer_state_change();
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cout << "Unknown exception" << std::endl;
        return 2;
    }
    return 0;
}
