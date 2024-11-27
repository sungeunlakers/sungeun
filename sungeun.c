#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

#define WIDTH 62
#define HEIGHT 48
#define UX 30 
#define UY 45  

void removeCursor(void) {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = 0; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void gamestart() {
    system("cls");
    printf("게임을 시작합니다...\n");
    Sleep(1000);
    system("cls");
}


void help() {
    system("cls");
    printf("도움말: 방향키로 *를 움직입니다.\n");
    printf("w: 위로 이동, a: 왼쪽 이동, s: 아래로 이동, d: 오른쪽 이동\n");
    printf("메뉴로 돌아가려면 아무 키나 누르세요...\n");
    getch();
    system("cls");
}


void gameLoop() {
    char xyChoice = 0;
    int x = 10, y = 10;  
    removeCursor();

    while (1) {
        gotoxy(x, y);
        printf("\033[0;33m * \033[0;33m");
        if (kbhit()) {  
            xyChoice = getch();
            switch (xyChoice) {
            case 'w':  
                y = (y > 0) ? y - 1 : y;  
                break;
            case 'a':  
                x = (x > 0) ? x - 1 : x;
                break;
            case 's':
                y++;
                break;
            case 'd':  
                x++;
                break;
            }
        }
        Sleep(50);  
        system("cls");
    }
}


void StartMenu() {
    int choice;

    while (1) {
        printf("번호를 입력하여 게임을 시작하세요");
        printf("===== 게임 메뉴 =====\n");
        printf("1. 게임 시작\n");
        printf("2. 도움말\n");
        printf("3. 종료\n");
        printf("=====================\n");
        printf("번호를 입력하시오: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:  
            gamestart();
            gameLoop();
            break;
        case 2:  
            help();
            break;
        case 3:  
            printf("게임을 종료합니다.\n");
            return;
        default:  
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            Sleep(1000);
            system("cls");
            break;
        }
    }
}

int main() {
    StartMenu();
    return 0;
}
