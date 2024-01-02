#include "Timer.h"

Timer::Timer(int duration) : countdownDuration(duration), isTimerEnabled(true) {
    startTime = std::chrono::high_resolution_clock::now();
}

int Timer::GetRemainingTime()
{
    if (!isTimerEnabled) return 0;

    currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = currentTime - startTime;
    elapsedSeconds = elapsed.count();

    return static_cast<int>(countdownDuration - elapsedSeconds);
}