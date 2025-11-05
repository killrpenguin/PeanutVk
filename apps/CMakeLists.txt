add_executable(app app.cpp)

target_compile_options(app PUBLIC
    $<$<CONFIG:Debug>:-g -O0>
    $<$<CONFIG:Release>:-O3 -DNDEBUG>
    $<$<CXX_COMPILER_ID:Clang>: -Wall
				-Wdeprecated
				-Wextra
				-Wcast-align
				-Wdouble-promotion
				-Wimplicit-fallthrough
				-Wmisleading-indentation
				-Wnon-virtual-dtor
				-Wnull-dereference
				-Wold-style-cast
				-Woverloaded-virtual
				-Wpedantic
				-Wshadow
				-Wundef
				-Wuninitialized
				-std=c++2b>
)

target_compile_features(app PRIVATE cxx_std_23)

target_link_libraries(app PRIVATE Framework imgui fmt::fmt glfw Vulkan::Vulkan)
