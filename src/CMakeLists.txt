set(HEADER_LIST "${PeanutVk_SOURCE_DIR}/include/Framework/Application.hpp"
	"${PeanutVk_SOURCE_DIR}/include/Framework/EntryPoint.hpp" 
	"${PeanutVk_SOURCE_DIR}/include/Framework/Image.hpp" 
	"${PeanutVk_SOURCE_DIR}/include/Framework/Layer.hpp" 
	"${PeanutVk_SOURCE_DIR}/include/Framework/Random.hpp" 
	"${PeanutVk_SOURCE_DIR}/include/Framework/Timer.hpp" 
)

add_library(Framework Application.cpp Image.cpp Random.cpp ${HEADER_LIST})

target_compile_options(Framework PUBLIC
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

target_include_directories(Framework PUBLIC ../include)

target_link_libraries(Framework PRIVATE imgui fmt::fmt Vulkan::Vulkan glfw glm::glm stb_image)

target_compile_features(Framework PUBLIC cxx_std_23)
