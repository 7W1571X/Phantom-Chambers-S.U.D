#include "../headerFiles/stdafx.h"

/* PRINTS */
short int currentFrame{};

// Title
void menuMainTitle(short int x, short int y)
{
	setConsoleCursorPos(x, y + currentFrame);
	switch (currentFrame) {
	case 0:
		std::cout << "__________.__                   __                   _________ .__                  ___.                        ";
		break;
	case 1:
		std::cout << "\\______   \\  |__ _____    _____/  |_  ____   _____   \\_   ___ \\|  |__ _____    _____\\_ |__   ___________  ______";
		break;
	case 2:
		std::cout << " |     ___/  |  \\\\__  \\  /    \\   __\\/  _ \\ /     \\  /    \\  \\/|  |  \\\\__  \\  /     \\| __ \\_/ __ \\_  __ \\/  ___/";
		break;
	case 3:
		std::cout << " |    |   |   Y  \\/ __ \\|   |  \\  | (  <_> )  Y Y  \\ \\     \\___|   Y  \\/ __ \\|  Y Y  \\ \\_\\ \\  ___/|  | \\/\\___ \\ ";
		break;
	case 4:
		std::cout << " |____|   |___|  (____  /___|  /__|  \\____/|__|_|  /  \\______  /___|  (____  /__|_|  /___  /\\___  >__|  /____  >";
		break;
	case 5:
		std::cout << "               \\/     \\/     \\/                  \\/          \\/     \\/     \\/      \\/    \\/     \\/           \\/ ";
		break;
	default:
		currentFrame = 0;
		return;
		break;
	}

	currentFrame++;
	return menuMainTitle(x, y);
}

// Continue
void menuMainContinue(short int x, short int y)
{
	setConsoleCursorPos(x, y + currentFrame);
	switch (currentFrame) {
	case 0:
		std::cout << " _____         _   _             ";
		break;
	case 1:
		std::cout << "|     |___ ___| |_|_|___ _ _ ___ ";
		break;
	case 2:
		std::cout << "|   --| . |   |  _| |   | | | -_|";
		break;
	case 3:
		std::cout << "|_____|___|_|_|_| |_|_|_|___|___|";
		break;
	default:
		currentFrame = 0;
		return;
		break;
	}

	currentFrame++;
	return menuMainContinue(x, y);
}

// New Game
void menuMainNewGame(short int x, short int y)
{
	setConsoleCursorPos(x, y + currentFrame);
	switch (currentFrame) {
	case 0:
		std::cout << " _____              _____               ";
		break;
	case 1:
		std::cout << "|   | |___ _ _ _   |   __|___ _____ ___ ";
		break;
	case 2:
		std::cout << "| | | | -_| | | |  |  |  | .'|     | -_|";
		break;
	case 3:
		std::cout << "|_|___|___|_____|  |_____|__,|_|_|_|___|";
		break;
	default:
		currentFrame = 0;
		return;
		break;
	}

	currentFrame++;
	return menuMainNewGame(x, y);
}

// Settings
void menuMainSettings(short int x, short int y)
{
	setConsoleCursorPos(x, y + currentFrame);
	switch (currentFrame) {
	case 0:
		std::cout << " _____     _   _   _             ";
		break;
	case 1:
		std::cout << "|   __|___| |_| |_|_|___ ___ ___ ";
		break;
	case 2:
		std::cout << "|__   | -_|  _|  _| |   | . |_ -|";
		break;
	case 3:
		std::cout << "|_____|___|_| |_| |_|_|_|_  |___|";
		break;
	case 4:
		std::cout << "                        |___|    ";
		break;
	default:
		currentFrame = 0;
		return;
		break;
	}

	currentFrame++;
	return menuMainSettings(x, y);
}

// Credits
void menuMainCredits(short int x, short int y)
{
	setConsoleCursorPos(x, y + currentFrame);
	switch (currentFrame) {
	case 0:
		std::cout << " _____           _ _ _       ";
		break;
	case 1:
		std::cout << "|     |___ ___ _| |_| |_ ___ ";
		break;
	case 2:
		std::cout << "|   --|  _| -_| . | |  _|_ -|";
		break;
	case 3:
		std::cout << "|_____|_| |___|___|_|_| |___|";
		break;
	default:
		currentFrame = 0;
		return;
		break;
	}

	currentFrame++;
	return menuMainCredits(x, y);
}

// Exit
void menuMainExit(short int x, short int y)
{
	setConsoleCursorPos(x, y + currentFrame);
	switch (currentFrame) {
	case 0:
		std::cout << " _____     _ _   ";
		break;
	case 1:
		std::cout << "|   __|_ _|_| |_ ";
		break;
	case 2:
		std::cout << "|   __|_'_| |  _|";
		break;
	case 3:
		std::cout << "|_____|_,_|_|_|  ";
		break;
	default:
		currentFrame = 0;
		return;
		break;
	}

	currentFrame++;
	return menuMainExit(x, y);
}

// Back
void menuAllBack(short int x, short int y)
{
	setConsoleCursorPos(x, y + currentFrame);
	switch (currentFrame) {
	case 0:
		std::cout << " _____         _   ";
		break;
	case 1:
		std::cout << "| __  |___ ___| |_ ";
		break;
	case 2:
		std::cout << "| __ -| .'|  _| '_|";
		break;
	case 3:
		std::cout << "|_____|__,|___|_,_|";
		break;
	default:
		currentFrame = 0;
		return;
		break;
	}

	currentFrame++;
	return menuAllBack(x, y);
}

// Tab Outline
void menuAllTabOutline(short int x, short int y, int width, int height)
{
	setConsoleCursorPos(x + 1, y);
	// Top
	for (int t{}; t < width - 1; t++) {
		std::cout << "_";
	}

	// Middle
	for (int m{}; m < height - 3; m++) {
		currentFrame++;
		setConsoleCursorPos(x, y + currentFrame);
		std::cout << "|";

		for (int m{}; m < width - 1; m++) {
			std::cout << " ";
		}

		std::cout << "|";
	}

	// Bottom
	setConsoleCursorPos(x, y + currentFrame);
	std::cout << "|";
	for (int b{}; b < width - 1; b++) {
		std::cout << "_";
	}
}

// Audio
void menuSettingsAudio(short int x, short int y)
{
	setConsoleCursorPos(x, y + currentFrame);
	switch (currentFrame) {
	case 0:
		std::cout << " _____       _ _     ";
		break;
	case 1:
		std::cout << "|  _  |_ _ _| |_|___ ";
		break;
	case 2:
		std::cout << "|     | | | . | | . |";
		break;
	case 3:
		std::cout << "|__|__|___|___|_|___|";
		break;
	default:
		currentFrame = 0;
		return;
		break;
	}

	currentFrame++;
	return menuSettingsAudio(x, y);
}

/* MAIN */
Audio audioManager;
unsigned short int currentTab{}, currentOptCursor{};
const std::array<int, 2> consoleSize{ getConsoleSize() };

// Init Opt Cursor (different from console cursor)
void initOptCursor(unsigned short int opts)
{
	viewConsoleCursor(false);
	if (upInputPressed) {
		currentOptCursor--;
		audioManager.Play("menuSelect.wav", 0.7f, false);
		if (currentOptCursor > opts + 1) {
			currentOptCursor = opts;
		}
	}

	if (downInputPressed && currentOptCursor < opts + 1) {
		currentOptCursor++;
		audioManager.Play("menuSelect.wav", 0.7f, false);
		if (currentOptCursor == opts + 1) {
			currentOptCursor = 0;
		}
	}

	return;
}

int main(void)
{
	audioManager.BasePath = "resources//sounds";

	// Styles
	const unsigned short int padding{ 4 }, selectedPadding{ 6 };
	const char* selectArrow{ "      \n      \n  --> \n      \n      " };

	bool isMenu{ true };
	while (isMenu) {
		// MAIN MENU
		if (currentTab == 0) {
			// Tab Title
			menuMainTitle(padding, 1);
			setConsoleCursorPos(113 + padding, 6);
			std::cout << "0.0.2"; // Version

			while (currentTab == 0) {
				initOptCursor(4);

				// Opt. Continue
				if (currentOptCursor == 0) {
					setConsoleCursorPos(0, consoleSize[1] - 25);
					std::cout << selectArrow;
					menuMainContinue(selectedPadding, consoleSize[1] - 25);

					if (GetAsyncKeyState(VK_RETURN) & 1) {
						currentTab = 1;
						break;
					}
				}
				else {
					clearSpace(2, consoleSize[1] - 25, 2, 5);
					clearSpace(34 + (padding - 1), consoleSize[1] - 25, 5, 4);
					menuMainContinue(padding, consoleSize[1] - 25);
				}

				// Opt. New Game
				if (currentOptCursor == 1) {
					setConsoleCursorPos(0, consoleSize[1] - 20);
					std::cout << selectArrow;
					menuMainNewGame(selectedPadding, consoleSize[1] - 20);

					if (GetAsyncKeyState(VK_RETURN) & 1) {
						currentTab = 2;
						break;
					}
				}
				else {
					clearSpace(2, consoleSize[1] - 20, 2, 5);
					clearSpace(41 + (padding - 1), consoleSize[1] - 20, 5, 4);
					menuMainNewGame(padding, consoleSize[1] - 20);
				}

				// Opt. Settings
				if (currentOptCursor == 2) {
					setConsoleCursorPos(0, consoleSize[1] - 15);
					std::cout << selectArrow;
					menuMainSettings(selectedPadding, consoleSize[1] - 15);

					if (GetAsyncKeyState(VK_RETURN) & 1) {
						currentTab = 3;
						break;
					}
				}
				else {
					clearSpace(2, consoleSize[1] - 15, 2, 5);
					clearSpace(34 + (padding - 1), consoleSize[1] - 15, 5, 4);
					menuMainSettings(padding, consoleSize[1] - 15);
				}

				// Opt. Credits
				if (currentOptCursor == 3) {
					setConsoleCursorPos(0, consoleSize[1] - 10);
					std::cout << selectArrow;
					menuMainCredits(selectedPadding, consoleSize[1] - 10);

					if (GetAsyncKeyState(VK_RETURN) & 1) {
						currentTab = 4;
						break;
					}
				}
				else {
					clearSpace(2, consoleSize[1] - 10, 2, 5);
					clearSpace(30 + (padding - 1), consoleSize[1] - 10, 5, 4);
					menuMainCredits(padding, consoleSize[1] - 10);
				}

				// Opt. Exit
				if (currentOptCursor == 4) {
					setConsoleCursorPos(0, consoleSize[1] - 5);
					std::cout << selectArrow;
					menuMainExit(selectedPadding, consoleSize[1] - 5);

					if (GetAsyncKeyState(VK_RETURN) & 1) {
						currentTab = 99;
						break;
					}
				}
				else {
					clearSpace(2, consoleSize[1] - 5, 2, 5);
					clearSpace(18 + (padding - 1), consoleSize[1] - 5, 5, 4);
					menuMainExit(padding, consoleSize[1] - 5);
				}

				Sleep(10);
			}
		}

		// Reset x1
		currentOptCursor = 0;
		system("cls");

		// Exit Check
		if (currentTab == 99) {
			break;
		}

		// CONTINUE && NEW GAME TAB
		if (currentTab == 1 || currentTab == 2) {
			isMenu = false;
			game();
		}

		// SETTINGS TAB
		if (currentTab == 3) {
			// Tab Title
			menuMainSettings(padding, 1);

			while (currentTab == 3) {
				initOptCursor(1);

				// Opt. Audio
				if (currentOptCursor == 0) {
					setConsoleCursorPos(0, consoleSize[1] - 10);
					std::cout << selectArrow;
					menuSettingsAudio(selectedPadding, consoleSize[1] - 10);

					if (GetAsyncKeyState(VK_RETURN) & 1) {
						const char* selectSubArrow{ "*" };
						unsigned short int volume{};
						bool isSubMenu{ true };

						// Sub Title
						menuAllTabOutline((consoleSize[0] / 2) - 25, (consoleSize[1] / 4), 50, 10);
						setConsoleCursorPos((consoleSize[0] / 2) - 23, consoleSize[1] / 4);
						std::cout << "Audio";

						// Sub Menu
						while (isSubMenu) {
							initOptCursor(1);

							// Opt. Volume
							if (currentOptCursor == 0) {
								setConsoleCursorPos((consoleSize[0] / 2) - 24, (consoleSize[1] / 4) + 2);
								std::cout << selectSubArrow;
								std::cout << " Volume";

								if (GetAsyncKeyState(VK_RIGHT) & 1 && volume < 99) {
									volume++;
								}

								if (GetAsyncKeyState(VK_LEFT) & 1 && volume > 0) {
									volume--;
								}

								setConsoleCursorPos((consoleSize[0] / 2) + 22, (consoleSize[1] / 4) + 2);
								std::cout << volume;
							}
							else {
								setConsoleCursorPos((consoleSize[0] / 2) - 24, (consoleSize[1] / 4) + 2);
								std::cout << "  Volume";
							}

							// Opt. Back
							if (currentOptCursor == 1) {
								setConsoleCursorPos((consoleSize[0] / 2) - 24, (consoleSize[1] / 4) + 6);
								std::cout << selectSubArrow;
								std::cout << " Back";

								if (GetAsyncKeyState(VK_RETURN) & 1) {
									clearSpace((consoleSize[0] / 2) - 25, consoleSize[1] / 4, 51, 10);
									currentOptCursor = 0;
									break;
								}
							}
							else {
								setConsoleCursorPos((consoleSize[0] / 2) - 24, (consoleSize[1] / 4) + 6);
								std::cout << "  Back";
							}

							Sleep(10);
						}
					}
				}
				else {
					clearSpace(2, consoleSize[1] - 10, 2, 5);
					clearSpace(22 + (padding - 1), consoleSize[1] - 10, 5, 4);
					menuSettingsAudio(padding, consoleSize[1] - 10);
				}

				// Opt. Back
				if (currentOptCursor == 1) {
					setConsoleCursorPos(0, consoleSize[1] - 5);
					std::cout << selectArrow;
					menuAllBack(selectedPadding, consoleSize[1] - 5);

					if (GetAsyncKeyState(VK_RETURN) & 1) {
						currentTab = 0;
					}
				}
				else {
					clearSpace(2, consoleSize[1] - 5, 2, 5);
					clearSpace(20 + (padding - 1), consoleSize[1] - 5, 5, 4);
					menuAllBack(padding, consoleSize[1] - 5);
				}

				Sleep(10);
			}
		}

		/* CREDIST TAB */
		if (currentTab == 4) {
			// Tab Title
			menuMainCredits(padding, 1);

			// Credits Info
			menuAllTabOutline((consoleSize[0] / 2) - 25, (consoleSize[1] / 4), 50, 10);
			setConsoleCursorPos((consoleSize[0] / 2) - 23, consoleSize[1] / 4);
			std::cout << "Info";

			setConsoleCursorPos((consoleSize[0] / 2) - 23, (consoleSize[1] / 4) + 2);
			std::cout << "Artist:                                 Twistix";
			setConsoleCursorPos((consoleSize[0] / 2) - 23, (consoleSize[1] / 4) + 3);
			std::cout << "Programmer:                             Twistix";
			setConsoleCursorPos((consoleSize[0] / 2) - 23, (consoleSize[1] / 4) + 4);
			std::cout << "Sound:                                  Twistix";

			// Opt. Back
			while (currentTab == 4) {
				setConsoleCursorPos(0, consoleSize[1] - 5);
				std::cout << selectArrow;
				menuAllBack(selectedPadding, consoleSize[1] - 5);

				if (GetAsyncKeyState(VK_RETURN) & 1) {
					currentTab = 0;
				}

				Sleep(10);
			}
		}

		// Reset x2
		currentOptCursor = 0;
		system("cls");
		Sleep(10);
	}

	return 0;
}

// PS: Always Sleep In While Loops, To Avoid CPU Usage
