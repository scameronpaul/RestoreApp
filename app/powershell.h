#pragma once
#include <string>
#include <vector>
#include <map>

namespace ps
{
	inline std::vector<std::string> WINGET = {
		"Set-PSRepository -Name 'PSGallery' -InstallationPolicy Trusted",
		"Install-Script -Name winget-install -Force",
		"winget-install.ps1"
	};

	inline std::map<std::string, std::string> appFiles = {
		{ "Git", "Git.Git" },
		{ "Zoom", "Zoom.Zoom" },
		{ "Viber" ,"Viber.Viber" },
		{ "Jami", "SFLinux.Jami" },
		{ "Putty", "PuTTY.PuTTY" },
		{ "Brave", "Brave.Brave" },
		{ "Tabby", "Eugeny.Tabby" },
		{ "Edge", "Microsoft.Edge" },
		{ "Chrome", "Google.Chrome" },
		{ "NodeJS", "OpenJS.NodeJS" },
		{ "WinSCP", "WinSCP.WinSCP" },
		{ "Skype", "Microsoft.Skype" },
		{ "Teams", "Microsoft.Teams" },
		{ "Matrix", "Element.Element" },
		{ "Hexchat", "HexChat.HexChat" },
		{ "Firefox", "Mozilla.Firefox" },
		{ "Rust", "Rustlang.Rust.MSVC" },
		{ "Python3", "Python.Python.3" },
		{ "Discord", "Discord.Discord"  },
		{ "Waterfox", "Waterfox.Waterfox" },
		{ "Obsidian", "Obsidian.Obsidian" },
		{ "WinMerge", "WinMerge.WinMerge" },
		{ "Foxit PDF", "Foxit.PhantomPDF" },
		{ "NodeJS LTS", "OpenJS.NodeJS.LTS" },
		{ "Slack", "SlackTechnologies.Slack" },
		{ "mRemoteNG", "mRemoteNG.mRemoteNG" },
		{ "LibreWolf", "LibreWolf.LibreWolf" },
		{ "Notepad++", "Notepad++.Notepad++" },
		{ "Signal", "OpenWhisperSystems.Signal" },
		{ "Tor Browser", "TorProject.TorBrowser" },
		{ "Telegram", "Telegram.TelegramDesktop" },
		{ "Joplin (FOXX Notes)", "Joplin.Joplin" },
		{ "Chromium", "eloston.ungoogled-chromium" },
		{ "Vivaldi", "VivaldiTechnologies.Vivaldi" },
		{ "VS Codium", "Git.Git;VSCodium.VSCodium" },
		{ "Jetbrains Toolbox", "JetBrains.Toolbox" },
		{ "Rust Remote Desktop", "RustDesk.RustDesk" }, 
		{ "WireShark", "WiresharkFoundation.Wireshark" },
		{ "OpenJDK Java 16", "AdoptOpenJDK.OpenJDK.16" },
		{ "VS Code", "Git.Git;Microsoft.VisualStudioCode" },
		{ "GitHub Desktop", "Git.Git;GitHub.GitHubDesktop" },
		{ "Adobe Reader DC", "Adobe.Acrobat.Reader.64-bit" },
		{ "OpenJDK Java 8", "EclipseAdoptium.Temurin.8.JRE" },
		{ "ONLYOffice Desktop", "ONLYOFFICE.DesktopEditors" },
		{ "Oracle Java 18", "EclipseAdoptium.Temurin.18.JRE" },
		{ "Advanced IP Scanner", "Famatech.AdvancedIPScanner" },
		{ "Visual Studio 2022", "Microsoft.VisualStudio.2022.Community" }, 
	};
	
	void Powershell(std::vector<std::string> file, std::string filename, std::string completeMessage);
	bool SaveScript(std::vector<std::string> commands, std::string filename, std::string ext, std::string path);
	bool CheckForWinget();
	void InstallApps(std::vector<std::string> apps);
}