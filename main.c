#include <stdio.h> 
#include<conio.h>
#define rows 12
#define cols 104


int size =0 ;
char pos_map[rows][cols] ;

char character(){
    
    printf("o\n");
    printf(" /|\\ \n");
    printf(" / \\ ");
}
int menu(){
    int select ; 
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
char get_key(){
    int key = getch(); 
    
    switch(key){
        
        case 'w':movement(0,-1); break;
        case 's':movement(0,1); break;
        case 'a':movement(-1,0); break;
        case 'd':movement(1,0); break;
        
    }
   
    return key;

}
int playerX = 5;
int playerY = 5;
int x,y;
void draw_player(){
   
    pos_map[x][y] = 'X';
    
    
    printf("%d %d \n",x,y);
              
}

void movement(int deltaY , int deltaX){
    y += deltaY;
    x += deltaX;
    
}



char Board_game(){

    for(int col = 0;col < cols+2;++col){
        printf("@");
    }
    printf("\n");
    //In_board game 
    for(int i= 0;i<rows;++i){
        printf("@@");
        
        for(int j = 0;j < cols-2;++j){
            printf("%c", pos_map[i][j]);
            

        }
        
        printf("@@");
        printf("\n");
    }
    //cols down 
    for(int col = 0 ;col < cols+2;++col){
        printf("@");
    }
}
    

int main(){
     
    //Variables
    char player = character();
    int True = 0,r=0;
    int test ;

    system("cls");
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
        if(x<=rows || y<=cols){
            while(True == 1){
                get_key();
                draw_player();
                Board_game();
                
            }
            system("cls");
        }        
        

    } 

    else{
        system("cls");
    }
    return 0;
}

