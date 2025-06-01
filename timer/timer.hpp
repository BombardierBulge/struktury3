#ifndef TIMER_H
#define TIMER_H

#include <chrono>
// Class to measure elapsed time using chono high_resolution_clock
class Timer {
public:
    enum class TimeUnit { Seconds, Milliseconds, Microseconds };
    Timer();// Constructor starts the timer
    void reset(); // Starts the timer again
    void stop(); // Stops the timer
    double measurement_stop(TimeUnit unit); // Stops the timer and returns elapsed time with the specified unit
    double measurement_millis() const; // Returns elapsed time in milliseconds
    double measurement_micro() const; // Returns elapsed time in microseconds
    double measurement_seconds() const; // Returns elapsed time in seconds
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;//start time 
    
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;// end time 
};

#endif // TIMER_H