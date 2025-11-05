#pragma once

//
// Adapted from StudioCherno's Walnut Framework.
//

#include "Layer.hpp"

#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <fmt/core.h>
#include <vulkan/vk_enum_string_helper.h>
#include <vulkan/vulkan.h>

constexpr auto check_vk_result( VkResult err ) noexcept -> void {
    if ( err == 0 ) {
        return;
    }
    fmt::println( stderr, "[vulkan] Error: VkResult = {}", string_VkResult( err ) );
    if ( err < 0 ) {
        abort();
    }
}
struct GLFWwindow;

namespace Peanut {

    struct ApplicationSpecification {
        std::string Name = "Peanut App";
        uint32_t Width   = 1600;
        uint32_t Height  = 900;
    };

    class Application {
      public:
        explicit Application(
            const ApplicationSpecification& applicationSpecification = ApplicationSpecification() ) noexcept;
        ~Application() noexcept;

        constexpr static auto Get() noexcept -> Application&;

        auto Run() -> void;
        auto SetMenubarCallback( const std::function< void() >& menubarCallback ) -> void {
            m_MenubarCallback = menubarCallback;
        }

        template < typename T > constexpr auto PushLayer() -> void {
            static_assert( std::is_base_of< Layer, T >::value, "Pushed type is not subclass of Layer!" );
            m_LayerStack.emplace_back( std::make_shared< T >() )->OnAttach();
        }

        constexpr auto PushLayer( const std::shared_ptr< Layer >& layer ) -> void {
            m_LayerStack.emplace_back( layer );
            layer->OnAttach();
        }

        auto Close() noexcept -> void;

        auto GetTime() const noexcept -> float;
        constexpr auto GetWindowHandle() const noexcept -> GLFWwindow* {
            return m_WindowHandle;
        }

        static auto GetInstance() noexcept -> VkInstance;
        static auto GetPhysicalDevice() noexcept -> VkPhysicalDevice;
        static auto GetDevice() noexcept -> VkDevice;

        static auto GetCommandBuffer( bool begin ) noexcept -> VkCommandBuffer;
        static auto FlushCommandBuffer( VkCommandBuffer commandBuffer ) noexcept -> void;

        static auto SubmitResourceFree( std::function< void() >&& func ) noexcept -> void;

      private:
        auto Init() noexcept -> void;
        auto Shutdown() noexcept -> void;

      private:
        ApplicationSpecification m_Specification{};
        GLFWwindow* m_WindowHandle{ nullptr };
        bool m_Running{ false };

        float m_TimeStep{ 0.0F };
        float m_FrameTime{ 0.0F };
        float m_LastFrameTime{ 0.0F };

        std::vector< std::shared_ptr< Layer > > m_LayerStack{};
        std::function< void() > m_MenubarCallback{};
    };

    auto CreateApplication( int argc, char** argv ) -> Application*;
} // namespace Peanut
