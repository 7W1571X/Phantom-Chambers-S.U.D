#include "../headerFiles/stdafx.h"

/* ASCII ART */

// Title
void menuMainTitle(short int x, short int y)
{
	std::array<std::string, 6> textTitle{
		R"(__________.__                   __                   _________ .__                  ___.                        )",
		R"(\______   \  |__ _____    _____/  |_  ____   _____   \_   ___ \|  |__ _____    _____\_ |__   ___________  ______)",
		R"( |     ___/  |  \\__  \  /    \   __\/  _ \ /     \  /    \  \/|  |  \\__  \  /     \| __ \_/ __ \_  __ \/  ___/)",
		R"( |    |   |   Y  \/ __ \|   |  \  | (  <_> )  Y Y  \ \     \___|   Y  \/ __ \|  Y Y  \ \_\ \  ___/|  | \/\___ \ )",
		R"( |____|   |___|  (____  /___|  /__|  \____/|__|_|  /  \______  /___|  (____  /__|_|  /___  /\___  >__|  /____  >)",
		R"(               \/     \/     \/                  \/          \/     \/     \/      \/    \/     \/           \/ )"
	};
	
	for (int i{}; i < textTitle.size(); i++) {
		setConsoleCursorPos(x, y + i);
		std::cout << textTitle[i];
	}

	return;
}

// Continue
void menuMainContinue(short int x, short int y)
{
	std::array<std::string, 4> textContinue{
		" _____         _   _             ",
		"|     |___ ___| |_|_|___ _ _ ___ ",
		"|   --| . |   |  _| |   | | | -_|",
		"|_____|___|_|_|_| |_|_|_|___|___|"
	};
	
	for (int i{}; i < textContinue.size(); i++) {
		setConsoleCursorPos(x, y + i);
		std::cout << textContinue[i];
	}
	
	return;
}

// New Game
void menuMainNewGame(short int x, short int y)
{
	std::array<std::string, 4> textNewGame{
		" _____              _____               ",
		"|   | |___ _ _ _   |   __|___ _____ ___ ",
		"| | | | -_| | | |  |  |  | .'|     | -_|",
		"|_|___|___|_____|  |_____|__,|_|_|_|___|"
	};
	
	for (int i{}; i < textNewGame.size(); i++) {
		setConsoleCursorPos(x, y + i);
		std::cout << textNewGame[i];
	}
	
	return;
}

// Settings
void menuMainSettings(short int x, short int y)
{
	std::array<std::string, 5> textSettings{
		" _____     _   _   _             ",
		"|   __|___| |_| |_|_|___ ___ ___ ",
		"|__   | -_|  _|  _| |   | . |_ -|",
		"|_____|___|_| |_| |_|_|_|_  |___|",
		"                        |___|    "
	};

	for (int i{}; i < textSettings.size(); i++) {
		setConsoleCursorPos(x, y + i);
		std::cout << textSettings[i];
	}
	
	return;
}

// Credits
void menuMainCredits(short int x, short int y)
{
	std::array<std::string, 4> textCredits{
		" _____           _ _ _       ",
		"|     |___ ___ _| |_| |_ ___ ",
		"|   --|  _| -_| . | |  _|_ -|",
		"|_____|_| |___|___|_|_| |___|"
	};

	for (int i{}; i < textCredits.size(); i++) {
		setConsoleCursorPos(x, y + i);
		std::cout << textCredits[i];
	}

	return;
}

// Exit
void menuMainExit(short int x, short int y)
{
	std::array<std::string, 4> textExit{
		" _____     _ _   ",
		"|   __|_ _|_| |_ ",
		"|   __|_'_| |  _|",
		"|_____|_,_|_|_|  "
	};
	
	for (int i{}; i < textExit.size(); i++) {
		setConsoleCursorPos(x, y + i);
		std::cout << textExit[i];
	}

	return;
}

// Back
void menuAllBack(short int x, short int y)
{
	std::array<std::string, 4> textBack{
		" _____         _   ",
		"| __  |___ ___| |_ ",
		"| __ -| .'|  _| '_|",
		"|_____|__,|___|_,_|"
	};

	for (int i{}; i < textBack.size(); i++) {
		setConsoleCursorPos(x, y + i);
		std::cout << textBack[i];
	}

	return;
}

// Audio
void menuSettingsAudio(short int x, short int y)
{
	std::array<std::string, 4> textAudio{
		" _____       _ _     ",
		"|  _  |_ _ _| |_|___ ",
		"|     | | | . | | . |",
		"|__|__|___|___|_|___|"
	};

	for (int i{}; i < textAudio.size(); i++) {
		setConsoleCursorPos(x, y + i);
		std::cout << textAudio[i];
	}

	return;
}

// Tab Outline
void menuAllTabOutline(short int x, short int y, int width, int height)
{
	int count{};
	setConsoleCursorPos(x + 1, y);
	// Top
	for (int t{}; t < width - 1; t++) {
		std::cout << "_";
	}

	// Middle
	for (int m{}; m < height - 3; m++) {
		count++;
		setConsoleCursorPos(x, y + count);
		std::cout << "|";

		for (int m{}; m < width - 1; m++) {
			std::cout << " ";
		}

		std::cout << "|";
	}

	// Bottom
	setConsoleCursorPos(x, y + count);
	std::cout << "|";
	for (int b{}; b < width - 1; b++) {
		std::cout << "_";
	}
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
			startGame();
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

		/* CREDITS TAB */
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
