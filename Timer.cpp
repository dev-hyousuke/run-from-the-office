#include "Timer.h"

int Timer::GetRemainingTime()
{
    currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = currentTime - startTime;
    elapsedSeconds = elapsed.count();

    return static_cast<int>(countdownDuration - elapsedSeconds);
}