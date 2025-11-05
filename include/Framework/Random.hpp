#pragma once

//
// Adapted from StudioCherno's Walnut Framework.
//

#include <cstdint>
#include <random>

#include <glm/glm.hpp>

namespace Peanut {

    class Random {
      public:
        static auto Init() -> void {
            s_RandomEngine.seed( std::random_device()() );
        }

        static auto UInt() -> std::uint32_t {
            return s_Distribution( s_RandomEngine );
        }

        static auto UInt( uint32_t min, uint32_t max ) -> std::uint32_t {
            return min + ( s_Distribution( s_RandomEngine ) % ( max - min + 1 ) );
        }

        static auto Float() -> float {
            return static_cast< float >(
                s_Distribution( s_RandomEngine ) / static_cast< float >( std::numeric_limits< uint32_t >::max() ) );
        }

        static auto Vec3() -> glm::vec3 {
            return glm::vec3( Float(), Float(), Float() );
        }

        static auto Vec3( float min, float max ) -> glm::vec3 {
            return glm::vec3(
                Float() * ( max - min ) + min, Float() * ( max - min ) + min, Float() * ( max - min ) + min );
        }

        static auto InUnitSphere() -> glm::vec3 {
            return glm::normalize( Vec3( -1.0f, 1.0f ) );
        }

      private:
        static std::mt19937 s_RandomEngine;
        static std::uniform_int_distribution< std::mt19937::result_type > s_Distribution;
    };

} // namespace Peanut
