#include <chrono>
#include "raylib.h"

class Timer 
{
    public:
        int GetRemainingTime();
    private:
        std::chrono::_V2::system_clock::time_point startTime{std::chrono::high_resolution_clock::now()};
        std::chrono::_V2::system_clock::time_point currentTime{};
        double elapsedSeconds{0.0};
        int countdownDuration{120};
};