#include "pch.h"
#include "config.h"
#include <shlwapi.h>

FILE* cptr;
errno_t cfgerr;
char configPath[MAX_PATH];

void saveConfig(void) {
	GetModuleFileNameA(NULL, configPath, sizeof(configPath));
	PathRemoveFileSpecA(configPath);
	PathCombineA(configPath, configPath, "Config"); //Creates config folder, required for PJ64 1.6
	CreateDirectoryA(configPath, NULL);
	PathCombineA(configPath, configPath, "Lunaconfig.bin"); //Creates or opens config file
	cfgerr = fopen_s(&cptr, configPath, "wb");

	if (cptr != 0) {
		fwrite(&config, sizeof(config), 1, cptr);
		fflush(cptr);
		fclose(cptr);
	}
}

void loadConfig(void) {
	GetModuleFileNameA(NULL, configPath, sizeof(configPath));
	PathRemoveFileSpecA(configPath);
	PathCombineA(configPath, configPath, "Config"); //Creates config folder, required for PJ64 1.6
	CreateDirectoryA(configPath, NULL);
	PathCombineA(configPath, configPath, "Lunaconfig.bin"); //Opens config file to read
	cfgerr = fopen_s(&cptr, configPath, "rb");

	if (cfgerr) {
		restoreDefaults();
	}
	else {
		fread(&config, sizeof(config), 1, cptr);
		fclose(cptr);
	}

	if (config.configVersion != 0x0100) {
		restoreDefaults();
	}
}

void restoreDefaults(void) {
	config = defaultConfig;
}