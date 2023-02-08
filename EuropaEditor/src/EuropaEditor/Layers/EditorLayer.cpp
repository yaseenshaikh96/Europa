#include "EditorLayer.h"

#include <imgui.h>

#include <glm/gtc/type_ptr.hpp> 
#include <glm/gtc/matrix_transform.hpp>


namespace EuropaEngine
{
	EditorLayer::EditorLayer()
		:
		AppLayer("EditorLayer"),
		//m_Camera(glm::ortho(-1, 1, -1, 1)),
		m_OrthographicCameraController(1280.0f/720.0f, true),
		m_CameraTransform(0),
		m_ViewPortSize(1280, 720)
	{
	}

	void EditorLayer::OnAttach()
	{
		FrameBufferSpecification specs;
		specs.Width = static_cast<uint32_t>(1280.0f);
		specs.Height = static_cast<uint32_t>(720.0f);
		m_FrameBuffer = FrameBuffer::Create(specs);
	}
	void EditorLayer::OnDetach()
	{

	}
	void EditorLayer::OnImguiRender()
	{
		return;
		static bool dockspaceOpen = true;
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}

		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
		ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit")) Application::Get().Close();
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

		ImGui::Begin("Settings");

		ImGui::Text("Hello!");

		ImGui::End(); // settings

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("ViewPort");

		m_ViewPortFocused = ImGui::IsWindowFocused();
		Application::Get().GetImguiLayer()->SetBlockImGuiEvent(!m_ViewPortFocused);

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		m_ViewPortSize = { viewportPanelSize.x, viewportPanelSize.y };
		uint32_t frameBuffer = m_FrameBuffer->GetColorAttachmentID();
		ImGui::Image((void*)frameBuffer, ImVec2{ m_ViewPortSize.x, m_ViewPortSize.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });

		ImGui::End();
		ImGui::PopStyleVar(); // viewport


		ImGui::End(); // docking
	}

	void EditorLayer::OnUpdate()
	{
			//m_FrameBuffer->Bind();
		{
			Renderer2D::ResetStatistics();
			RenderCommand::SetClearColor({ 0.4f, 0.01f, 0.5f, 1.0f }); // good purple
			RenderCommand::Clear();
		}

		//m_CubeRotation += 90 * timeStep;
		{
			Renderer2D::BeginScene(m_OrthographicCameraController.GetCamera());
			Renderer2D::DrawAxisAlignedQuadFilled(
				glm::vec3(0.0f, 0.0f, 0.0f),
				glm::vec2(1.0f, 1.0f),
				glm::vec4(1.0f, 0.2f, 0.2f, 1.0f));
			
			Renderer2D::EndScene();
		}
			//m_FrameBuffer->UnBind();
	}

	void EditorLayer::OnEvent(Event& e)
	{
	}
}