#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

namespace sft
{
	// Define categories and apps
	inline map<string, map<string, bool>> software = {
		{ "Communication", {
			{ "Discord", false },
			{ "Telegram", false },
			{ "Signal", false },
			{ "Slack", false },
			{ "Hexchat", false},
			{ "Jami", false },
			{ "Matrix", false },
			{ "Skype", false },
			{ "Teams", false },
			{ "Viber", false },
			{ "Zoom", false },
		} },
		{ "Browsers", {
			{ "Brave", false },
			{ "Chrome", false },
			{ "Chromium", false },
			{ "Firefox", false },
			{ "LibreWolf", false },
			{ "Tor Browser", false },
			{ "Vivaldi", false },
			{ "Waterfox", false },
			{ "Edge", false },
		} },
		{ "Development", {
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
		} },
		{ "Document", {
			{ "Notepad++", false },
			{ "Obsidian", false },
			{ "ONLYOffice Desktop", false },
			{ "Adobe Reader DC", false },
			{ "Foxit PDF", false },
			{ "Joplin (FOXX Notes)", false },
			{ "WinMerge", false },
		} },
		{ "Pro Tools", {
			{ "Advanced IP Scanner", false },
			{ "Tabby", false },
			{ "WinSCP", false },
			{ "Putty", false },
			{ "WireShark", false },
			{ "Rust Remote Desktop", false },
			{ "mRemoteNG", false },
		} }
	};

	void UncheckAll();
}