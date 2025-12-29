#include <stdio.h>
#include <stdlib.h>

typedef struct Gamesettings {
	float volume;
	int resolution_x;
	int resolution_y;
	int difficulty;
} Gamesettings;

void save_game_settings(const Gamesettings *settings, const char *filename) {
	FILE *file;
	errno_t err = fopen_s(&file, filename, "wb");

	if (err != 0 || file == NULL) {
		perror("无法写");
		return;
	}

	fwrite(settings, sizeof(Gamesettings), 1, file);

	fclose(file);
}

void load_game_settings(Gamesettings *settings, const char *filename) {
	FILE *file;
	errno_t err = fopen_s(&file, filename, "rb");

	if (err != 0 || file == NULL) {
		perror("无法读");
		return;
	}

	fread(settings, sizeof(Gamesettings), 1, file);

	fclose(file);
}

int main() {

	Gamesettings settings = {0.75, 1920, 1080, 2};

	save_game_settings(&settings, "C:\\Users\\Administrator\\Desktop\\game_settings.bin");

	return 0;
}