#include "powershell.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <vector>

bool ps::SaveScript(std::vector<std::string> commands, std::string filename, std::string ext, std::string path)
{
	std::ofstream file;
	file.open(path + filename + ext);

	std::string execution;
	for (int i = 0; i < commands.size(); i++)
	{
		execution += commands[i] + "\n";
	}

	file << execution << std::endl;
	file.close();
	return true;
}

void ps::ExecuteScript(std::string command, std::string finishedMessage)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	
	// Create a new powershell process
	if (CreateProcess(NULL, (LPSTR)command.c_str(),
		NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		// Wait until child process exits.
		WaitForSingleObject(pi.hProcess, INFINITE);

		MessageBox(NULL, finishedMessage.c_str(), "RestoreApp", MB_OK);

		// Close process and thread handles.
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else {
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}

void ps::Powershell(std::vector<std::string> file, std::string filename, std::string completeMessage)
{
	if (!SaveScript(file, filename, ".ps1", "")) return;

	std::string command = "powershell.exe -ExecutionPolicy Bypass -File " + filename + ".ps1";
	
	ExecuteScript(command, completeMessage);
	
	remove((filename + ".ps1").c_str());
}

bool ps::CheckForWinget()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	bool installed = false;

	// Create a new powershell process
	if (CreateProcess("Winget Installation", (LPSTR)"winget --info",
		NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi))
	{
		// Wait until child process exits.
		WaitForSingleObject(pi.hProcess, INFINITE);
		installed = true;
	}
	
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	if (!installed)
	{
		const int result = MessageBox(NULL, "Winget is not installed. Please install.", "RestoreApp", MB_OKCANCEL);
		if (result == IDOK)
		{
			std::thread winget (Powershell, WINGET, "winget", "Finished installing winget. Restart your pc.");
			winget.detach();
		}
	}
	
	return installed;
}

void ps::InstallApps(std::vector<std::string> apps)
{
	std::string commands;
	for (const auto& app : apps) {
		commands += "winget install " + ps::appFiles[app] + "\n";
	}

	std::thread install (ExecuteScript, commands, "Finished installing apps.");
	install.detach();
}

void ps::Debloater(std::vector<std::vector<std::string>> commands)
{
	std::vector<std::string> execute = ps::DEBLOAT;
	for (const auto& cmd : commands) {
		execute.insert(execute.end(), cmd.begin(), cmd.end());
	}

	SaveScript(execute, "debloat", ".ps1", "");

	//std::thread debloat(Powershell, commands, "debloat", "Finished debloating.");
	//debloat.detach();
}