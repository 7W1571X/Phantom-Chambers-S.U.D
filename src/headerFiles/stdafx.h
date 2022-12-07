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

	std::array<int, 2> vec2{ conInfo.srWindow.Right - conInfo.srWindow.Left + 1, conInfo.srWindow.Bottom - conInfo.srWindow.Top + 1 };
	return vec2;
}

inline // Set Visibility Of Console Cursor
void viewConsoleCursor(bool showFlag)
{
	// Console Obj's
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	cursorInfo.dwSize = 1;

	SetConsoleCursorInfo(out, &cursorInfo);
	return;
}

inline // Sets Console Cursor Position
void setConsoleCursorPos(short int x, short int y)
{
	// Console Obj's
	COORD pos{ x, y };
	HANDLE output{ GetStdHandle(STD_OUTPUT_HANDLE) };

	SetConsoleCursorPosition(output, pos);
	return;
}

inline // Emptys Desenated Space In Console
void clearSpace(short int x, short int y, int width, int length)
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