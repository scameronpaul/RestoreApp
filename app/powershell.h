#pragma once
#include <string>
#include <vector>

namespace ps
{
	inline std::vector<std::string> WINGET = {
		"Set-PSRepository -Name 'PSGallery' -InstallationPolicy Trusted",
		"Install-Script -Name winget-install -Force",
		"winget-install.ps1"
	};
	
	void Powershell(std::vector<std::string> file, std::string filename, std::string completeMessage);
	bool SaveScript(std::vector<std::string> commands, std::string filename, std::string ext, std::string path);
	bool CheckForWinget();
}