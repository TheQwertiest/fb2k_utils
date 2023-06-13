#pragma once

#include <thread>

namespace qwr
{

void SetThreadName( std::thread& thread, const std::string& threadName );
void SetThreadName( std::jthread& thread, const std::string& threadName );

}
