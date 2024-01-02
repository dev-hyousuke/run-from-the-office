#include <chrono>
#include "raylib.h"

class Timer 
{
    public:
        Timer(int duration);
        int GetRemainingTime();
        void DisableTimer() { isTimerEnabled = false; }
    private:
        std::chrono::_V2::system_clock::time_point startTime{};
        std::chrono::_V2::system_clock::time_point currentTime{};
        double elapsedSeconds{0.0};
        int countdownDuration{};
        bool isTimerEnabled{};
};