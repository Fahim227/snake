#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#define fast  ios_base::sync_with_stdio(false)
#define ll long long int
using namespace std;
bool gameover;
const int width=30;
const int height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int nTail;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
//functions
void Setup(){
    gameover = false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;


}
void Draw(){
    system("cls"); //linux system("clear");
    for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<"#\n";
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0){
                cout<<"#";
            }
            if(i==y && j==x){
                cout<<"F";
            }
            else if(i==fruitY && j==fruitX){
                cout<<"*";
            }
            else{
                     bool print = false;
                for(int k=0;k<nTail;k++){

                    if(tailX[k] == j && tailY[k] == i){
                        cout<<"o";
                        print= true;
                    }



                }
                 if(!print){
                           cout<<" ";
                }



            }
            if(j==width-1){
                cout<<"#";
            }

        }
        cout<<"\n";
    }
    for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<"#\n";
    cout<<"Score:: "<<score<<"\n";

}
void Input(){
    if(_kbhit()){
        switch(_getch()){

            case 'a':
                dir=LEFT;
                break;
            case 'w':
                dir=UP;
                break;
            case 's':
                dir=DOWN;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 'x':
                gameover=true;
                break;
        }
    }


}
void Logic(){

    int prevX= tailX[0];
    int prevY = tailY[0];
    int prev2X,prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i=1;i<nTail;i++){

        prev2X = tailX[i];
        prev2Y=tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;

    }

    switch(dir){
     case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    /*if(x>width || x<0 || y<0 || y>height){
        gameover=true;
    }*/
    if(x>=width) x=0;else if(x<0) x=width-1;
    if(y>=height) y=0;else if(y<0) y=height-1;
    for(int i=0;i < nTail; i++){
        if(tailX[i]== x && tailY[i] == y){
            gameover=true;
        }
    }
    if(x==fruitX && y==fruitY){

        score+=10;
        fruitX=rand()%width;
        fruitY=rand()%height;
        nTail++;
    }


}

int main(){
    //fast;
    Setup();
    while(!gameover){
        Draw();
        Input();
        Logic();
        Sleep(10);
    }

    return 0;
}
