#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string>
#include <time.h>
#include <Windows.h>

typedef struct tagInfo
{
	int HP;
	int MP;

	int EXP;

	float Att;
	float Def;

	int Level;
}INFO;

typedef struct tagObject
{

	char* Name;
	INFO Info;

}OBJECT;

const int PLAYER = 0;
const int ENEMY = 1;
const int MAX = 2;

const int LOGO_Scene = 0;
const int CLASS_Scene = 1;
const int Wizard_Scene = 2;
const int Druid_Scene = 3;
const int Paladin_Scene = 4;
const int Warrior_Scene = 5;
const int EXIT_Scene = 6;

int Scene = 0;


void CLASS();
void WIZARD();
void DRUID();
void PALADIN();
void WARRIOR();


void InitializePlayer(OBJECT* Player);
void InitializeEnemy(OBJECT* Monster);

void SceneManager(OBJECT* _Player, OBJECT* _Enemy);
char* SetName();
void LogoScene();


void SetPosition(int _x, int _y, char* _str, int _Color = 15);
void SetColor(int _Color);
void HideCursor();



int main(void)
{

	system("mode con:cols=120 lines=30");

	system("title 김민근 Framework v0.6");

	OBJECT* Player = (OBJECT*)malloc(sizeof(OBJECT));
	InitializePlayer(Player);
	OBJECT* Monster = (OBJECT*)malloc(sizeof(OBJECT));
	InitializeEnemy(Monster);
	
	DWORD dwTime = GetTickCount();
	int Delay = 1000;

	int UpCount = 0;

	while (true)
	{
		if (dwTime + Delay < GetTickCount())
		{
			dwTime = GetTickCount();

			system("cls");

			printf_s("%s\n", Player->Name);

			SceneManager(Player, Monster);
		}
	}

	return 0;
}

void SceneManager(OBJECT* _Player, OBJECT* _Enemy)
{
	switch (Scene)
	{
	case LOGO_Scene():
		LogoScene();
		break;
	case CLASS_Scene:
		CLASS();
		break;
	case Wizard_Scene:
		WIZARD();
		break;
	case Druid_Scene:
		DRUID();
		break;
	case Paladin_Scene:
		PALADIN();
		break;
	case Warrior_Scene:
		WARRIOR();
		break;
	case EXIT_Scene:

		exit(NULL);
		break;
	}
}

	char* SetName()
{
	char Buffer[128] = "";

	printf_s("닉네임을 입력하세요 : ");

	scanf("%s", Buffer);

	Sleep(2000);

	printf_s("\n\n\n시작하는중...\n\n");

	printf_s("\n닉네임은 %s 입니다.\n", Buffer);

	Sleep(2000);

	system("cls");
	
	char* pName = (char*)malloc(strlen(Buffer) + 1);
	
	strcpy(pName, Buffer);
	
	return pName;
}

void LogoScene()
{
	int Width = (120 / 2) - (strlen("  ________ _____ __   _________   _____  _____   _____ "));
	int Height = 10;

	SetPosition(Width, Height + 1, (char*)"  ________ _____ __   _________   _____  _____   _____ ");
	SetPosition(Width, Height + 2, (char*)"	| __   __| ____|\ \ / /__   __| |  __ \| __  \ / ____|");
	SetPosition(Width, Height + 3, (char*)"		| |  | |__   \ V /   | |    | |__) | |__) | |  __ ");
	SetPosition(Width, Height + 4, (char*)"		| |  |  __|   > <    | |    |  _  /|  ___/| | |_ |");
	SetPosition(Width, Height + 5, (char*)"		| |  | |____ / . \   | |    | | \ \| |    | |__| |");
	SetPosition(Width, Height + 6, (char*)"		|_|  |______/_/ \_\  |_|    |_|  \_\_|    \_____ |");

	Sleep(5000);

	Scene++;
}




void CLASS()
{
	printf_s("직업 선택\n");
	printf_s("1.마법사\n2.드루이드\n3.성기사\n4.전사\n5.종료\n입력 : ");

	int i = 0;
	scanf("%d", &i);

	if (i == 1)
		Scene = Wizard_Scene;
	else if (i == 2)
		Scene = Druid_Scene;
	else if (i == 3)
		Scene = Paladin_Scene;
	else if (i == 4)
		Scene = Warrior_Scene;
	else if (i == 5)
		Scene = EXIT_Scene;
	Scene++;
}

void WIZARD()
{
	printf("");
}

void DRUID()
{

}

void PALADIN()
{

}

void WARRIOR()
{

}



void SetPosition(int _x, int _y, char* _str, int _Color)
{
	COORD Pos = { _x, _y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	SetColor(_Color);

	printf_s("%s", _str);
}

void SetColor(int _Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
}



void HideCursor()
{
	CONSOLE_CURSOR_INFO Info;

	Info.dwSize = 1;
	Info.bVisible = false;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}