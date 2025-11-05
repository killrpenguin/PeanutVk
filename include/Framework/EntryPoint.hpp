#pragma once

//
// Adapted from StudioCherno's Walnut Framework.
//

#include "Application.hpp"

// NOLINTBEGIN(misc-definitions-in-headers)

//  #ifdef WL_PLATFORM_WINDOWS

extern Peanut::Application* Peanut::CreateApplication( int argc, char** argv );
bool g_ApplicationRunning = true;

namespace Peanut {
    auto Main( int argc, char** argv ) -> int {
        while ( g_ApplicationRunning ) {
            Peanut::Application* app = Peanut::CreateApplication( argc, argv );
            app->Run();
            delete app;
        }

        return 0;
    }

} // namespace Peanut

// #ifdef WL_DIST
//
// #include <Windows.h>
//
// int APIENTRY WinMain( HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow ) {
//     return Walnut::Main( __argc, __argv );
// }
//
// #else

int main( int argc, char** argv ) {
    return Peanut::Main( argc, argv );
}

//  #endif // wl_dist
// #endif // wl_platform_windows

// NOLINTEND(misc-definitions-in-headers)
