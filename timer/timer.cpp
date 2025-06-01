#include "timer.hpp"

Timer::Timer() : start_time(std::chrono::high_resolution_clock::now()), end_time(start_time) {}

void Timer::reset() {
    start_time = std::chrono::high_resolution_clock::now();
    end_time = start_time;
}
void Timer::stop() {
    end_time = std::chrono::high_resolution_clock::now();
}
double Timer::measurement_stop(TimeUnit unit) {
    end_time = std::chrono::high_resolution_clock::now();
    switch (unit)
    {
    case TimeUnit::Seconds:
        return measurement_seconds();
        break;
    case TimeUnit::Milliseconds:
        return measurement_millis();
        break;
    case TimeUnit::Microseconds:
        return measurement_micro();
        break;
    default:
        return 0.0;
        break;
    }
}
double Timer::measurement_millis() const {
    return std::chrono::duration_cast< std::chrono::milliseconds>(end_time - start_time).count();
}
double Timer::measurement_micro() const {
    return std::chrono::duration_cast< std::chrono::microseconds>(end_time - start_time).count();
}
double Timer::measurement_seconds() const {
    return std::chrono::duration_cast< std::chrono::seconds>(end_time - start_time).count();
}