#pragma once

//
// Adapted from StudioCherno's Walnut Framework.
//

#include "vulkan/vulkan.h"

#include <cstdint>
#include <string>
#include <string_view>

namespace Peanut {
    // TODO: Convert to std::variant;
    enum class ImageFormat {
        None = 0,
        RGBA,
        RGBA32F
    };

    class Image {
      public:
        explicit Image( std::string_view path ) noexcept;
        explicit Image(
            std::uint32_t width, std::uint32_t height, ImageFormat format, const void* data = nullptr ) noexcept;

        ~Image() noexcept;

        auto SetData( const void* data ) noexcept -> void;

        constexpr auto GetDescriptorSet() const noexcept -> VkDescriptorSet {
            return m_DescriptorSet;
        }

        auto Resize( std::uint32_t width, std::uint32_t height ) noexcept -> void;

        constexpr auto GetWidth() const noexcept -> std::uint32_t {
            return m_Width;
        }
        constexpr auto GetHeight() const noexcept -> std::uint32_t {
            return m_Height;
        }

      private:
        auto AllocateMemory( uint64_t size ) noexcept -> void;
        auto Release() noexcept -> void;

      private:
        std::uint32_t m_Width{ 0 };
        std::uint32_t m_Height{ 0 };

        VkImage m_Image{ nullptr };
        VkImageView m_ImageView{ nullptr };
        VkDeviceMemory m_Memory{ nullptr };
        VkSampler m_Sampler{ nullptr };

        ImageFormat m_Format{ ImageFormat::None };

        VkBuffer m_StagingBuffer{ nullptr };
        VkDeviceMemory m_StagingBufferMemory{ nullptr };

        std::size_t m_AlignedSize{ 0 };

        VkDescriptorSet m_DescriptorSet{ nullptr };

        std::string m_Filepath{};
    };
} // namespace Peanut
