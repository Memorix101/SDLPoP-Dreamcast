#include <kos.h>
#include "util.h"
#include <chrono>

// SDL_GetPerformanceCounter
long long get_performance_counter() {
    return std::chrono::high_resolution_clock::now().time_since_epoch().count() / 1000; // SDL speed
}
