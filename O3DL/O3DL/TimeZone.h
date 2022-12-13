#pragma once
#include <chrono>
#include <time.h>
#include <iostream>
#include <chrono>

using namespace std::chrono;

class TimeZone
{
    const auto& timeZoneDatabase = get_tzdb();
    const auto& currentZone = timeZoneDatabase.current_zone();
    local_time<system_clock::duration> lt = currentZone->to_local(system_clock::now());

    std::cout << "local_time: " << lt << "\n";

};

