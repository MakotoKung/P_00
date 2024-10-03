#include<stdio.h> 
#include<conio.h>
#include<windows.h>
#include<time.h>
#define rows 12
#define cols 104

int size =0 ;
char pos_map[rows][cols] ; 


int menu(){
    int select; 
    printf(" pew pew monsters \n------------\n");
    printf(" 1.Start Game\n");
    printf(" 2.Exit\n");
    printf("Enter you select (1-2):");
    scanf("%d",&select);
    switch (select)
    {
    case 1:
        system("cls");
        break;
    
    case 2: 
        return 0 ;
        break;

    default:
        break;
    }
    return select;
}
int x = 3, y = 5, y_mon = -1,y_new =56;
void movement(int deltaY , int deltaX){
    y += deltaY;
    x += deltaX;
    y_mon += 1;
    if(y>44){
        y_new -= 1;
    }
}
char get_key(){
    int key = getch(); 
    
    switch(key){
        
        case 'w':
            movement(0,-1);
            break;
        case 's':
            movement(0,1);
            break;
        case 'a':
            movement(-2,0); 
            break;
        case 'd':
            movement(2,0);
            break;
        default:
            break;
    }
    return key;
}

int random(int num){
    
    int random = rand()%num +1;
    return random;
}
void draw_player(){
    pos_map[x][y] = 'X';
    printf("\n\n%d %d\n",x,y);
              
}

void draw_monster(){
    
    for(int i=0;i<=rows;++i){
        pos_map[i][y_mon] = '$';
    }
    if(y>= 44){
        for(int i=0;i<=rows;++i){
            pos_map[i][y_new] = 'l';
        }
    }
    
}
char Board_game(){
    printf("\033[0;34m");//change font color 
    for(int col = 0;col < cols+2;++col){
        printf("@");
    }
    printf("\n");
    //In_board game 
    for(int i= 0;i<rows;++i){
        printf("@@");
        printf("\033[0m"); // set defult
        for(int j = 0;j < cols-2;++j){
            printf("%c",pos_map[i][j]);
        }
        printf("\033[0;34m"); //set color 
        printf("@@");
        printf("\n");
    }
    //cols down 
    for(int col = 0 ;col < cols+2;++col){
        printf("@");
    }
    printf("\033[0m");//set defult 
}

int main(){
     
    //Variables
    int True = 0;
    int test ;
    srand(time(NULL));
    system("cls");
    
    //everthing in game should in if menu() ==1 ;
    if(menu() == 1){
        True = 1;
        char space = ' ';
        
        //Show Board game 
        for(int col = 0;col < cols+2;++col){
            printf("@");
        }
        printf("\n");
        //In_board game 
        for(int i= 0;i<rows;++i){
            printf("@@");
            for(int j = 0;j < cols-2;++j){
                pos_map[i][j] = space; 
                printf("%c",pos_map[i][j]);
            }
            printf("@@");
            printf("\n");
        }
        //cols down 
        for(int col = 0 ;col < cols+2;++col){
            printf("@");
        }
        //last show board game 
        printf("\n");
        //movement player // start [3][5] 
        int space_m = random(rows-1);
        int space_n,n=0;
        int score=0;

        while(True = 1 ){
            
            if(((x>= 0 ) && (x < rows)) && ((y>=0)&&(y < cols-2))){
                get_key(); 
                score += 1;
                draw_monster();
                pos_map[space_m][y_mon] = ' ';
                pos_map[space_n][y_new] = ' ';
                draw_player();
                printf("\033[0;33m"); // change font color
                printf("SCORE : %d\n",score);
                printf("\033[0m"); // set defult color code 
                Board_game();
                //printf("\nspace_m :%d space_n :%d x: %d y: %d\n",space_m,space_n,x,y);
                //printf("%d %d",y_mon,y_new);
                
                //if monster exit the frame delete monster and make new
                //random new spawn
                if(y_mon>=cols-2){
                   int new = y;
                   y_mon = new-random(7);
                }
                else if(y_new <0){
                    y_new = random(17)+y;
                }
                //Check position to Game over 
                if((x != space_m && y == y_mon ) || (x != space_n && y == y_new)){
                    printf("\033[0;33m"); // change font color
                    printf("\nSCORE : %d \n",score);
                    printf("\033[0m"); // set defult color code 
                    
                    printf("\033[3;31m"); // set red color 
                    printf("GAME OVER \n  ");
                    printf("\033[0m"); // set defult
                    True = 0;
                    break;
                }
                //deleta player and monster 
                pos_map[x][y] = space ;
                for(int row=0;row<=rows;++row){
                    pos_map[row][y_mon] = space;
                }
                for(int row=0;row<=rows;++row){
                    pos_map[row][y_new] = space;
                }
            }
            //if player move exit a frame
            else{ 
               printf("\033[0;33m"); // change font color
                printf("\nSCORE : %d \n",score);
                printf("\033[0m"); // set defult color code 
                
                printf("\033[3;31m"); // set red color 
                printf("GAME OVER \n  ");
                printf("\033[0m"); // set defult
                True = 0;
                break;

            }
            //random when spawn new_monster    
            if(n!=1){
                if (y> 44){
                    n=1 ;
                    space_n = random(rows-1);
                }
            }
            else if (n=1){
                if(y<44){
                    n=0;
                    space_n = random(rows-1);
                }
            }
        }
    } 
    else{
        system("cls");
    }
    return 0;
}

