#pragma once

//
// Adapted from StudioCherno's Walnut Framework.
//

// clang-format off
#include <fmt/core.h>
#include <chrono>
#include <string>
// clang-format on

namespace Peanut {

    class Timer {
      public:
        Timer() {
            Reset();
        }

        auto Reset() noexcept -> void {
            m_Start = std::chrono::high_resolution_clock::now();
        }

        auto Elapsed() noexcept -> float {
            return std::chrono::duration_cast< std::chrono::nanoseconds >(
                       std::chrono::high_resolution_clock::now() - m_Start )
                       .count() *
                   0.001f * 0.001f * 0.001f;
        }

        auto ElapsedMillis() -> float {
            return Elapsed() * 1000.0f;
        }

      private:
        std::chrono::time_point< std::chrono::high_resolution_clock > m_Start{};
    };

    class ScopedTimer {
      public:
        ScopedTimer( const std::string& name )
            : m_Name( name ) {
        }
        ~ScopedTimer() {
            float time = m_Timer.ElapsedMillis();
            fmt::println( "[TIMER] {} - {}ms", m_Name, time );
        }

      private:
        std::string m_Name;
        Timer m_Timer;
    };
} // namespace Peanut
