#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <map>

#include "gui.h"
#include "powershell.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_dx9.h"
#include "../imgui/imgui_impl_win32.h"


using namespace ps;
using namespace std;

ImVec4 windowColor = ImVec4(0.25f, 0.25f, 0.25f, 1.0f);
ImVec4 borderColor = ImVec4(0.5f, 0.05f, 0.374f, 1.0f);
float rounding = 6.0f;

int currentTab = 1;
bool wingetInstalled;

std::map<std::string, bool> softwareCommunication = {
	{ "discord", false },
	{ "Telegram", false },
	{ "Signal", false },
	{ "Slack", false },
	{ "hexchat", false},
	{ "Jami", false },
	{ "Matrix", false },
	{ "Skype", false },
	{ "Teams", false },
	{ "Viber", false },
	{ "Zoom", false },
};

std::map<std::string, bool> softwareBrowsers = {
	{ "Brave", false },
	{ "Chrome", false },
	{ "Chromium", false },
	{ "Firefox", false },
	{ "LibreWolf", false },
	{ "Tor Browser", false },
	{ "Vivaldi", false },
	{ "Waterfox", false },
	{ "Edge", false },
};

std::map<std::string, bool> softwareDevelopment = {
	{ "Git", false },
	{ "GitHub Desktop", false },
	{ "Python3", false },
	{ "VS Code", false },
	{ "VS Codium", false },
	{ "Visual Studio 2022", false },
	{ "NodeJS", false },
	{ "NodeJS LTS", false },
	{ "OpenJDK Java 8", false },
	{ "OpenJDK Java 16", false },
	{ "Oracle Java 18", false },
	{ "Jetbrains Toolbox", false },
	{ "Rust", false },
};

std::map<std::string, bool> softwareDocument = {
	{ "Notepad++", false },
	{ "Obsidian", false },
	{ "ONLYOffice Desktop", false },
	{ "Adobe Reader DC", false },
	{ "Foxit PDF", false },
	{ "Joplin (FOXX Notes)", false },
	{ "WinMerge", false },
};

std::map<std::string, bool> softwareProTools = {
	{ "Advanced IP Scanner", false },
	{ "Tabby", false },
	{ "WinSCP", false },
	{ "Putty", false },
	{ "WireShark", false },
	{ "Rust Remote Desktop", false },
	{ "mRemoteNG", false },
};

//std::map<std::string, bool> software = {
//	{ "", false },
//};

int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE previousInstance,
	PWSTR arguments,
	int commandShow)
{
	//FILE* fDummy;
	//AllocConsole();
	//freopen_s(&fDummy, "CONOUT$", "w", stdout);
	
	// Dependencies
	wingetInstalled = CheckForWinget();
	
	// Initialize the window class.
	gui::CreateHWindow("RestoreApp", "RestoreApp # 2 idfk stfu");
	gui::CreateDevice();
	gui::CreateImGui();

	std::string message = "";

	// Main loop
	while (gui::exit)
	{
		// Initialize IMGUI frame
		gui::BeginRender();
		ImGui::SetNextWindowPos({ 0, 0 });
		ImGui::SetNextWindowSize(ImVec2(gui::width, gui::height));
		ImGui::Begin(
			"RestoreApp",
			&gui::exit,
			ImGuiWindowFlags_NoResize |
			ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoTitleBar 
		);

		//gui::width = ImGui::GetWindowWidth();
		//gui::height = ImGui::GetWindowHeight();
		
		// Colors
		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_WindowBg] = windowColor;
		colors[ImGuiCol_Border] = borderColor;
		
		colors[ImGuiCol_Button] = ImVec4(0.8f, 0.27f, 0.47f, 1.0f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.49f, 0.16f, 0.29f, 1.0f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.8f, 0.32f, 0.6f, 1.0f);

		colors[ImGuiCol_SliderGrab] = ImVec4(0.8f, 0.27f, 0.47f, 1.0f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.8f, 0.32f, 0.6f, 1.0f);

		colors[ImGuiCol_FrameBg] = ImVec4(0.8f, 0.27f, 0.47f, 1.0f);

		ImVec4 defaultText = colors[ImGuiCol_Text];

		// Stylizing
		ImGui::GetStyle().FrameRounding = rounding;
		ImGui::GetStyle().TabRounding = rounding;
		
		// IMGUI frame elements
		// Window title bar
		ImGui::SetCursorPos(ImVec2(7, 7));
		ImGui::Text("Restore App", ImVec2(50, 50));
		ImGui::SameLine(0, 0);
		ImGui::SetCursorPos(ImVec2(ImGui::GetContentRegionAvail().x + 47, 5));
		if (ImGui::Button("Exit", ImVec2(40, 20))) gui::exit = false;
		ImGui::Separator();

		// Window tabs
		std::vector <std::string> tabs = { "Debloating", "Software", "Games", "Settings", "About" };
		ImGui::GetStyle().FrameRounding = 2.0f;
		float spanWidth = gui::width - 10;
		float padding = gui::width - spanWidth;
		ImGui::SetCursorPosX(padding / 2);
		float tabWidth = (spanWidth - (3 * (tabs.size() - 1))) / tabs.size();
		for (int i = 0; i < tabs.size(); i++)
		{
			colors[ImGuiCol_Button] = ImVec4(0.8f, 0.27f, 0.47f, 1.0f);
			if (currentTab == i) colors[ImGuiCol_Button] = ImVec4(0.2f, 0.4f, 0.6f, 1.0f);
			if (ImGui::Button(tabs[i].c_str(), ImVec2(tabWidth, 25))) currentTab = i;
			colors[ImGuiCol_Button] = ImVec4(0.8f, 0.27f, 0.47f, 1.0f);
			if (i < tabs.size()-1) ImGui::SameLine(0, 3);
		}
		ImGui::GetStyle().FrameRounding = rounding;
		
		// Window body
		switch (currentTab)
		{
		case 0: {
			gui::resize = true;
			if (ImGui::Button("Debloat All", ImVec2(ImGui::GetContentRegionAvail().x, 40)))
			{
				CheckForWinget();
				//std::thread psThread ( Execute, WINGET );
				//psThread.detach();
			}
		} break;
		case 1: {
			// Define categories and apps
			std::map<std::string, std::map<std::string, bool>> software = {
				{ "Communication", softwareCommunication },
				{ "Browsers", softwareBrowsers },
				{ "Development", softwareDevelopment },
				{ "Document", softwareDocument },
				{ "ProTools1", softwareProTools },
				{ "ProTools2", softwareProTools },
				{ "ProTools3", softwareProTools },
			};
			
			// Scaling behaviour
			float posX = ImGui::GetCursorPosX();
			float posY = ImGui::GetCursorPosY();
			float xPadding = 3;
			float yPadding = 16;
			float sizeY = 230;
			float gridXWidth = gui::width - (posX * 2);
			int columns = software.size();
			while (gridXWidth / columns > 260) 
				columns++;
			while (gridXWidth / columns < 200)
				columns--;
			if (gridXWidth / columns < 175)
				if (columns > 4) columns = 4;
			float boxWidth = (gridXWidth - (xPadding * columns) + columns) / columns;
			
			// Create category boxes
			int i = 0;
			for (auto& category : software)
			{
				colors[ImGuiCol_Text] = ImVec4(0.0f, 0.8f, 0.98f, 1.0f);
				ImGui::SetCursorPos(ImVec2((posX + ((boxWidth + xPadding) * i)) + (boxWidth / 2) - (ImGui::CalcTextSize(category.first.c_str()).x / 2), posY));
				ImGui::Text(category.first.c_str());
				colors[ImGuiCol_Text] = defaultText;
				ImGui::SetCursorPos(ImVec2(posX + ((boxWidth + xPadding) * i), posY + yPadding));
				std::string frameName = "Software#" + category.first;
				ImGui::BeginChild(frameName.c_str(), ImVec2(boxWidth, sizeY), true); {
					for (auto& application : category.second)
					{
						ImGui::Checkbox(application.first.c_str(), &application.second);
					}
				} ImGui::EndChild();
				ImGui::SameLine(0, 0);
				i++;
				if (i >= columns) {
					i = 0;
					posY += sizeY + yPadding;
				}
			}
			
		} break;
		case 2: {
			ImGui::Text("Games");
		} break;
		case 3: {
			ImGui::Text("Settings");
			ImGui::ColorEdit4("Backround", (float*)&windowColor);
			ImGui::ColorEdit4("Border", (float*)&borderColor);
			ImGui::SliderFloat("Rounding", &rounding, 0.0f, 10.0f);
		} break;
		case 4: {
			ImGui::Text("About");
			ImGui::Button("amogus");
		} break;
		}
		// Window footer

		// End IMGUI frame
		//ImGui::PopStyleColor();
		ImGui::End();
		gui::EndRender();
		// Throttle the loop
		//std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	// Cleanup
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}