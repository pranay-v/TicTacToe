#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char displayingBoard(char * pnumbers,char * p1name, char * p2name);
int checkForWinner(char * pnumbers);
int checkMoveValidity(char * pnumbers,char x);

int main(void)
{

char * p1name = malloc(20);
char * p2name = malloc(20);

//creating a character array of possible inputs (basically a string)
char numbers[11]={'0','1','2','3','4','5','6','7','8','9'};
char * pnumbers = numbers; // assigning address of numbers(i.e address of first element of numbers) to pointer

printf("Player 1 - Enter Name:");
scanf("%s",p1name);
printf("Player 2 - Enter Name:");
scanf("%s",p2name);

int gameExtension = 0;

char p1 = 0;//input variable for player 1
char p2 = 0;//input variable for player 2

//creating an unmarked board initially
displayingBoard(pnumbers,p1name,p2name);

int moves=0;//maximum moves-9
while(moves<9)
{
printf("\n\n%s - Enter A Position:",p1name);
scanf(" ");
scanf("%c",&p1);

// if move by player 1 is valid
if(checkMoveValidity(pnumbers,p1)==1) 
{
    moves+=1;
    numbers[p1 - '0']='X';// assigning X to the required spot
    displayingBoard(pnumbers,p1name,p2name);//updated board
    
    //checking if Player 1 has won or not
    if(checkForWinner(pnumbers)==1)
    {
        printf("\n\n\a%s wins!\nGame Over\n",p1name);
        free(p1name);
        free(p2name);
        break;
    }
    
    if(moves==9)// incase 9 moves have been made and neither player has won
    {
        printf("\n\n\n\aGame Drawn!\n");
        free(p1name);
        free(p2name);
        break;
    }
    
    int p=0;//control variable checking for player 2's move validity
    while(p!=1)
       {
          printf("\n\n%s - Enter A Position:",p2name);
          scanf(" ");
          scanf("%c",&p2);
          
          // if move is valid
          if(checkMoveValidity(pnumbers,p2)==1)
             {
                numbers[p2 - '0']='O';// assigning O to required spot
                moves+=1;
                displayingBoard(pnumbers,p1name,p2name);
                if(checkForWinner(pnumbers)==1)//checking if Player 2 has won
                {
                    printf("\n\n\a%s wins!\nGame Over\n",p2name);
                    free(p1name);
                    free(p2name);
                    return 0;
                }
                p=1;
             }
          
          else
             {
                printf("\nInvalid move!\n");
             }
        }
}

else
{
    printf("\nInvalid move!");// in Case Player 1's move is invalid
}

}
  
return 0; 
}

/*******************************************************************
 FUNCTION TO DISPLAY THE BOARD AT THE START/AFTER EACH MOVE
 *******************************************************************/

char displayingBoard(char * pnumbers,char * p1name,char * p2name)
{
   //clears the screen completely,allowing the updated baord to be shown
   system("clear");
   printf("\tTic Tac Toe\t\n\n%s(X)\t%s(O)\n\n",p1name,p2name);

    //printing out the board by accessing values stored in addresses of the array.
    {
        printf("\n       |       |        ");
        printf("\n   %c   |   %c   |   %c      ",*(pnumbers+1),*(pnumbers +2),*(pnumbers +3));
        printf("\n_______|_______|________");
        printf("\n       |       |        ");
        printf("\n   %c   |   %c   |   %c      ",*(pnumbers + 4),*(pnumbers + 5),*(pnumbers + 6));
        printf("\n_______|_______|________");
        printf("\n       |       |        ");
        printf("\n   %c   |   %c   |   %c      ",*(pnumbers + 7),*(pnumbers + 8),*(pnumbers + 9));
        printf("\n       |       |        ");   
    }
    
}

/******************************************************************************
 FUNCTION TO CHECK WHETHER A MOVE HAS ALREADY BEEN MADE/ IS BETWEEN 1-9
*****************************************************************************/

int checkMoveValidity(char * pnumbers,char l)
{
    if(!isdigit(l))
    {printf("NO!");
    return 0;
    }
    else
    {
       int k = l - '0';
    
        if(*(pnumbers + k) =='X' || *(pnumbers + k)=='O' || !(k>0 && k<10))
        {
            return 0;
        }
         
         else
        {
            return 1;
        } 
    }
            
}

/******************************************************************
FUNCTION CHECKING IF A PLAYER HAS ACHIEVED 3 CONSECUTIVE SYMBOLS EITHER DIAGONALLY,
VERTICALLY OR HORIZONTALLY
*****************************************************************/
int checkForWinner(char * pnumbers)
{
    if(
       *(pnumbers + 1)== *(pnumbers + 2) && *(pnumbers + 2)== *(pnumbers + 3)
       || *(pnumbers + 2)== *(pnumbers + 5) && *(pnumbers + 5)== *(pnumbers + 8)
       ||*(pnumbers + 1)== *(pnumbers + 4) && *(pnumbers + 4)== *(pnumbers + 7)
       || *(pnumbers + 3)== *(pnumbers + 6) && *(pnumbers + 6)==*(pnumbers + 9)
       ||*(pnumbers + 4)==*(pnumbers + 5) && *(pnumbers + 5)== *(pnumbers + 6)
       ||*(pnumbers + 7)==*(pnumbers + 8) && *(pnumbers + 8)== *(pnumbers + 9)
       ||*(pnumbers + 1)==*(pnumbers + 5) && *(pnumbers + 5)== *(pnumbers + 9)
       ||*(pnumbers + 3)== *(pnumbers + 5) && *(pnumbers + 5)== *(pnumbers + 7)
      )
       {
           return 1;
       }
    else
    {
        return 0;
    }
      
}
