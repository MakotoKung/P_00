#include<stdio.h> 
#include<conio.h>
#include<windows.h>
#include<time.h>
#define rows 12
#define cols 104

int size =0 ;
char pos_map[rows][cols] ;

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
int x = 3, y = 5, y_mon = -1,y_new =90;
void movement(int deltaY , int deltaX){
    y += deltaY;
    x += deltaX;
    y_mon += 1;
    y_new -= 1;
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
    }
    return key;
}

int random(int num){
    
    int random = rand()%num +1;
    return random;
}
void draw_player(){
   
    pos_map[x][y] = 'X';
    printf("\n%d %d \n",x,y);
              
}

void draw_monster(){
    
    if(y>=4){
        for(int i=0;i<=rows;++i){
            pos_map[i][y_mon] = '$';
        }
    }
    
    if(y>= 44){
        for(int i=0;i<=rows;++i){
            pos_map[i][y_new] = 'l';
        }
    }
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
            printf("%c",pos_map[i][j]);
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
    int True = 0;
    int test ;
    srand(time(NULL));
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
        //movement player // start [3][5] 
        int space_m ;
        int space_n;
        if(y>= 4){
            space_m = random(rows-1);
        }
        else if(y<5){
            space_m = space_m;
        }
      
        if (y>= 44){
            space_n = random(rows-1);
        }
        else if (y<44){
            space_n = space_n;
        }
        while(True = 1 ){
            
            if(((x>= 0 ) && (x < rows)) && ((y>=0)&&(y < cols-2))){
                get_key();
                draw_monster();
                pos_map[space_m][y_mon] = ' ';
                pos_map[space_n][y_new] = ' ';
                draw_player();
                Board_game();
                
                //fix 
                //if monster exit the frame delete monster and make new
                
                //Check position to Game over 
                if((x != space_m && y == y_mon )|| (x != space_n && y == y_new)){
                    printf("\nGame Over\n");
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
                True = 0;
                printf("\nGame Over\n");
                break;

            }
        }
    } 
    else{
        system("cls");
    }
    return 0;
}

