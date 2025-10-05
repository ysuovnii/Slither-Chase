#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <conio.h>
using namespace std;

int width = 100, height = 20; 
int fruit_x = 20, fruit_y = 15;
bool game_over = false; 

enum direction {STOP = 0, UP, DOWN, LEFT, RIGHT};
direction snake_dir, rat_dir;

class player{
    public: 
        int x, y; 
        bool ability_active; 
        DWORD ability_start_time;
        player(int x, int y){
            this->x = x;
            this->y = y; 
            ability_active = false;
            ability_start_time = 0;  
        }
        player(){}
}; 
player snake(20, 10); 
player rat(20, 5); 

bool fruit_visible = true;             
DWORD fruit_eaten_time = 0;            


void draw(){
    cout << "\033[H"; 
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || i == height-1){
                cout << "-"; 
            }
            else if(j == 0 || j == width-1){
                cout << "|"; 
            }
            else if(i == snake.y && j == snake.x){
                cout << "\033[32mS\033[0m"; 
            }
            else if(i == rat.y && j == rat.x){
                cout << "\033[31mR\033[0m"; 
            }
            
            else if(fruit_visible && i == fruit_y && j == fruit_x){
                cout << "\033[33mf\033[0m"; 
            }
            
            else{
                cout << " ";
            }
        }
        cout << endl; 
    }

    cout << "Snake Ability: " << (snake.ability_active ? "ONN" : "OFF") << endl;
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'w' : snake_dir = UP; break; 
            case 'a' : snake_dir = LEFT; break;
            case 's' : snake_dir = DOWN; break;
            case 'd' : snake_dir = RIGHT; break; 
            case 'x' : game_over = true; break;  
            case 72 : rat_dir = UP; break; 
            case 75 : rat_dir = LEFT; break;
            case 80 : rat_dir = DOWN; break; 
            case 77 : rat_dir = RIGHT; break;   
        }
    }
}

void logic(){
   
    if(snake.x == fruit_x && snake.y == fruit_y && fruit_visible){
        snake.ability_active = true; 
        snake.ability_start_time = GetTickCount(); 

        fruit_visible = false;             
        fruit_eaten_time = GetTickCount(); 
    }

    if(!fruit_visible && (GetTickCount() - fruit_eaten_time >= 30000)){
        fruit_x = rand() % (width - 2) + 1;
        fruit_y = rand() % (height - 2) + 1;
        fruit_visible = true;              
    }

    if(snake.ability_active && (GetTickCount() - snake.ability_start_time >= 5000)){
        snake.ability_active = false; 
    }

    if(!snake.ability_active){
        if(snake.x < 0 || snake.x >= width || snake.y < 0 || snake.y >= height){
            game_over = true; 
        }
    }
    else{
        if(snake.x < 0){
            snake.x = width-1; 
        }
        if(snake.x >= width){
            snake.x = 1; 
        }
        if(snake.y < 0){
            snake.y = height-1; 
        }
        if(snake.y >= height){
            snake.y = 1;
        }
    }

    if(rat.x < 0){
        rat.x = width-1; 
    }
    if(rat.x >= width){
        rat.x = 1; 
    }
    if(rat.y < 0){
        rat.y = height-1; 
    }
    if(rat.y >= height){
        rat.y = 1;
    }

    if(rat.x == snake.x && rat.y == snake.y){
        game_over = true; 
        cout << "Snake Wins"; 
    }

    switch(snake_dir){
        case UP : snake.y--; break; 
        case DOWN : snake.y++; break; 
        case LEFT : snake.x--; break; 
        case RIGHT : snake.x++; break; 
    }
    switch(rat_dir){
        case UP : rat.y--; break;
        case DOWN : rat.y++; break; 
        case LEFT : rat.x-=2; break; 
        case RIGHT : rat.x+=2; break; 
    }
}

int main(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOut, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hOut, &cursorInfo);

    cout << "\033[2J";

    while(!game_over){
        draw(); 
        input(); 
        logic(); 
        Sleep(100); 
    } 
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hOut, &cursorInfo);
}
