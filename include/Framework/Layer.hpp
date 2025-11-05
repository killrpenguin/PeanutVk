#pragma once

//
// Adapted from StudioCherno's Walnut Framework.
//

namespace Peanut {

    class Layer {
      public:
        virtual ~Layer() = default;

        virtual auto OnAttach() -> void {
        }
        virtual auto OnDetach() -> void {
        }

        virtual auto OnUpdate( [[maybe_unused]] float ts ) -> void {
        }
        virtual auto OnUIRender() -> void {
        }
    };
} // namespace Peanut
