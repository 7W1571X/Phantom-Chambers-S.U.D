#pragma once

/* LIBS */
#include <iostream>
#include <fstream>
#include <string>
#include <array>

/* WINDOWS */
#include <windows.h>
#include <xaudio2.h>

/* QOL */
#define upInputPressed     GetAsyncKeyState(VK_UP) & 1 || GetAsyncKeyState(0x57) & 1
#define downInputPressed   GetAsyncKeyState(VK_DOWN) & 1 || GetAsyncKeyState(0x41) & 1

// FUNCS
inline // Return Console Size
std::array<int, 2> getConsoleSize(void)
{
	// Console Objs
	CONSOLE_SCREEN_BUFFER_INFO conInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &conInfo);

	const std::array<int, 2> vec2{ conInfo.srWindow.Right - conInfo.srWindow.Left + 1, conInfo.srWindow.Bottom - conInfo.srWindow.Top + 1 };
	return vec2;
}

inline // Set Visibility Of Console Cursor
void viewConsoleCursor(const bool showFlag)
{
	// Console Obj's
	const HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	cursorInfo.dwSize = 1;

	SetConsoleCursorInfo(out, &cursorInfo);
	return;
}

inline // Sets Console Cursor Position
void setConsoleCursorPos(const short x, const short y)
{
	// Console Obj's
	const COORD pos{ x, y };
	const HANDLE output{ GetStdHandle(STD_OUTPUT_HANDLE) };

	SetConsoleCursorPosition(output, pos);
	return;
}

inline // Empty's Designated Space In Console
void clearSpace(const short x, const short y, const int width, const int length)
{
	// Length
	for (int l{}; l < length; l++) {
		setConsoleCursorPos(x, y + l);

		// Width
		for (int w{}; w < width; w++) {
			std::cout << " ";
		}
	}
}

/* FILES */
#include "audio.hpp"
#include "game.hpp"
