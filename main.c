
#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#define NUM_PEOPLE 2

/* self-referential structure */

typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

/* prototypes */
void initialize_people (person people[NUM_PEOPLE]); //function prototype
void print_people (person people[NUM_PEOPLE]); //function prototype
void instructions( void );
void insert( ListNodePtr *sPtr, char value );
char delete( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void update_board(char myboard[ROWS][COLUMNS], int a, int b,int c);
void printboard();

struct Board myboard; //declare board
ListNodePtr startPtr = NULL;



int main( ) {
    person people[NUM_PEOPLE];

    initialize_people(people); // creates 2 players for the game

    print_people(people);//prints players to screen

    printf("\n");

    instructions(); // instructions for game



    char item; // char entered by user


    int turn = 100; // the number of turns
    char myboard[ROWS][COLUMNS];

    printboard(myboard); /* display the menu */
    int m,n,choice;
    for (int i = 1; i < turn; i++) {

        printf("select a piece player %s \n ", people[i].name);
        // ask for position of piece you want to movie
        printf(" enter the Row and column of the piece you want to move\n");

        //player select which option they want
        printf("move up 1: move down 2: move left 3: move right 4:\n");
        scanf("%d %d %d", &m, &n,&choice);




        /* loop while user does not choose 3 */
        while (choice != 6) {
            switch (choice) {

                    // 4 cases represent the four moves you can make
                    case 1:
                        printf(" move up\n");
                    myboard[m][n] = myboard[m + 1][n];
                    if (myboard[m + 1][n] == '0') {
                        break;
                    } else//creates link list for game piece when it takes another piece
                        update_board(myboard, n, m, choice);
                        printf("Enter a character of taken piece\n");
                    scanf("\n%c", &item);
                    insert(&startPtr, item); /* insert item in list */
                    printList(startPtr);

                    break;
                    case 2:
                        printf(" move down\n");
                    myboard[m][n] = myboard[m - 1][n];
                    if (myboard[m - 1][n] == '0') {
                        break;
                    } else//creates link list for game piece when it takes another piece
                        printf("Enter a character of taken piece \n");
                    scanf("\n%c", &item);
                    insert(&startPtr, item); /* insert item in list */
                    printList(startPtr);
                    update_board(myboard, n, m, choice);
                    break;
                    case 3:
                        printf(" move left\n");
                    myboard[m][n] = myboard[m][n - 1];
                    if (myboard[m][n - 1] == '0') {
                        break;
                    } else//creates link list for game piece when it takes another piece
                        printf("Enter a character of taken piece \n");
                    scanf("\n%c", &item);
                    insert(&startPtr, item); /* insert item in list */
                    printList(startPtr);
                    update_board(myboard, n, m, choice);
                    break;
                    case 4:
                        printf(" move right\n");
                    myboard[m][n] = myboard[m][n + 1];
                    if (myboard[m][n + 1] == '0') {
                        break;
                    } else//creates link list for game piece when it takes another piece
                        printf("Enter a character of taken piece\n");
                    scanf("\n%c", &item);
                    insert(&startPtr, item); /* insert item in list */
                    printList(startPtr);
                    update_board(myboard, n, m, choice);
                    break;


                    case 5: /* delete an element */
                        // if list is not empty
                        if (!isEmpty(startPtr)) { //

                            printf("enter the letters of the bottom stack to remove them: ");
                            printf("Enter character to be deleted: ");
                            scanf("\n%c", &item);
                            /* if character is found, remove it*/
                            if (delete(&startPtr, item)) { /* remove item */
                                printf("%c deleted.\n", item);
                                printList(startPtr);
                            } /* end if */
                            else {
                                printf("%c not found.\n\n", item);
                            } /* end else */
                        } /* end if */
                        else {
                            printf("List is empty.\n\n");
                        } /* end else */

                    break;


                    default:
                        printf("Invalid choice.\n\n");
                    printboard();
                    break;
                }

                printf("move up 1: move down 2: move left 3: move right 4:\n ");
                scanf("%d", &choice);
            } /* end while */

            printf("End of run.\n");

        if(myboard[m][n] == '*') {
            printf("not a valid not space on the board");
        }
            return 0;
        }
}














/* prints the game board to the screen */

void printboard( char a[ROWS][COLUMNS] ) {

char myboard[ROWS][COLUMNS] ={
        "**0000**",
        "*RRGGRR*",
        "0GGRRGG0",
        "0RRGGRR0",
        "0GGRRGG0",
        "0RRGGRR0",
        "*GGRRGG*",
        "**0000**"
};

    printf("start game\n");
    int j;
    printf("    0.1.2.3.4.5.6.7. \n");
    for (int i = 0; i < 8; ++i)
    {
        printf("%d. ",i);
        for ( j = 0; j < 8; ++j)

            printf(" %c", myboard[i][j]);
        printf("\n");
    }

    a[ROWS][COLUMNS] = myboard[ROWS][COLUMNS];

}



/* Insert a new value into the list that represents a piece on the board */
void insert( ListNodePtr *sPtr, char value )
{
    ListNodePtr newPtr = malloc( sizeof( ListNode ) ); //create node
    if ( newPtr != NULL ) { // is space available
        newPtr->data = value; // place value in node
        newPtr->nextPtr = NULL; // node does not link to another node

        ListNodePtr previousPtr = NULL;  /* pointer to previous node in list */
        ListNodePtr currentPtr = *sPtr; /* pointer to current node in list */


        /* insert new node at beginning of list */
        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else { //insert new node between previousPtr and currentPtr

            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }

    }
    else {
        printf( "%c not inserted. No memory available.\n", value );
    }
}

// delete a elements in the link list
char delete( ListNodePtr *sPtr, char value )
{
    /* delete first node */
    if ( value == ( *sPtr )->data ) {
        ListNodePtr tempPtr = *sPtr; /* hold onto node being removed */
        *sPtr = ( *sPtr )->nextPtr; /* de-thread the node */
        free( tempPtr ); /* free the de-threaded node */
        return value;
    }

    else {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = ( *sPtr )->nextPtr;

        /* loop to find the correct location in the list */
        while ( currentPtr != NULL && currentPtr->data != value ) {
            previousPtr = currentPtr; /* walk to ... */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        }

        /* delete node at currentPtr */
        if ( currentPtr != NULL ) {
            ListNodePtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            return value;
        }
    }

    return '\0';
}



/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
}

// Print the list
void printList( ListNodePtr currentPtr )
{
    // if list is empty
    if ( currentPtr == NULL ) {
        printf( "List is empty.\n\n" );
    }
    else {
        printf( "The list is:\n" );
        printf( "head -> " );


        // while not the end of the list
        while ( currentPtr != NULL ) {
            printf( "%c --> ", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
        }

        printf( "NULL\n\n" );

    }
}



