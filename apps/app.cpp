#include <Framework/Application.hpp>
#include <Framework/EntryPoint.hpp>
#include <Framework/Image.hpp>

#include <imgui.h>
#include <vulkan/vulkan.h>

class ExampleLayer : public Peanut::Layer {
  public:
    virtual void OnUIRender() override {
        ImGui::Begin( "Hello world!" );
        ImGui::Button( "My Button!" );
        ImGui::End();

        ImGui::ShowDemoWindow();
    }
};

Peanut::Application* Peanut::CreateApplication( [[maybe_unused]] int argc, [[maybe_unused]] char** argv ) {
    Peanut::ApplicationSpecification spec{};
    spec.Name = "Peanut Example";

    Peanut::Application* app = new Peanut::Application( spec );

    app->PushLayer< ExampleLayer >();
    app->SetMenubarCallback( [app]() {
        if ( ImGui::BeginMenu( "File" ) ) {
            if ( ImGui::MenuItem( "Exit" ) ) {
                app->Close();
            }
            ImGui::EndMenu();
        }
    } );

    return app;
}
