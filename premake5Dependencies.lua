

IncludeDir = {}


-- IncludeDir["yaml_cpp"] = "%{wks.location}/EuropaEngine/vendor/yaml-cpp/include"
-- IncludeDir["Box2D"] = "%{wks.location}/EuropaEngine/vendor/Box2D/include"
-- IncludeDir["filewatch"] = "%{wks.location}/EuropaEngine/vendor/filewatch"
-- IncludeDir["ImGuizmo"] = "%{wks.location}/EuropaEngine/vendor/ImGuizmo"
-- IncludeDir["entt"] = "%{wks.location}/EuropaEngine/vendor/entt/include"
-- IncludeDir["mono"] = "%{wks.location}/EuropaEngine/vendor/mono/include"
-- IncludeDir["shaderc"] = "%{wks.location}/EuropaEngine/vendor/shaderc/include"
-- IncludeDir["SPIRV_Cross"] = "%{wks.location}/EuropaEngine/vendor/SPIRV-Cross"
-- IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

IncludeDir["GLFW"] =        "%{wks.location}/EuropaEngine/vendor/GLFW/include"
IncludeDir["glad"] =        "%{wks.location}/EuropaEngine/vendor/glad/include"
IncludeDir["stb_image"] =   "%{wks.location}/EuropaEngine/vendor/stb_image"
IncludeDir["spdlog"] =      "%{wks.location}/EuropaEngine/vendor/spdlog/include"
IncludeDir["imgui"] =       "%{wks.location}/EuropaEngine/vendor/imgui"
IncludeDir["glm"] =         "%{wks.location}/EuropaEngine/vendor/glm"
IncludeDir["stb"] =         "%{wks.location}/EuropaEngine/vendor/stb/include"


GlobalDefines = {}
GlobalDefines["stb_image"] = "STB_IMAGE_IMPLEMENTATION"