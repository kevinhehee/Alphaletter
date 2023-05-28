
#include "raylib.h"
#include "time.h"

#include "raylib.h"
#include "raymath.h"
#include "ctype.h"
#include "string.h"


#define COLS 26
#define ROWS 1

#define MAX_INPUT_CHARS 15


const int screenWidth = 1200;
const int screenHeight = 800;

const int cellWidth = (screenWidth - 100) / COLS;
const int cellHeight = (screenHeight - 755) / ROWS;
int framescounter = 0;

char name[MAX_INPUT_CHARS + 1] = "\0";
char player1[30] = "\0";
char player2[30] = "\0";
char player1name[30] = "\0";
char player2name[30] = "\0";
char player1nameturn[30] = "\0";
char player2nameturn[30] = "\0";

char genre[MAX_INPUT_CHARS + 1] = "\0";

char notused[30] = "";
char used[30] = "Letter taken";
char notusedagain[30] = "";


char playerscoredisplay1[50] = "";
char playerscoredisplay2[50] = "";



int letterCount = 0; 


int boolloop;
int frames = 0;
int timee = 0;

bool titlescreen = true;
bool menuP1shown = false;
bool menuP2shown = false;
bool menuGenreshown = false;
bool counter3 = false;
bool counter2 = false;
bool counter1 = false;
bool countergo = false;
bool game = false;
bool gameend = false;


bool player1turn = true;
bool player2turn = false;

int player1score = 0;
int player2score = 0;
int turncounter = 0;

char wins[30] = " WINS!!!";
char turns[30] = "'s Turn";

bool A = true;
bool B = true;
bool C = true;
bool D = true;
bool E = true;
bool F = true;
bool G = true;
bool H = true;
bool I = true;
bool J = true;
bool K = true;
bool L = true;
bool M = true;
bool N = true;
bool O = true;
bool P = true;
bool Q = true;
bool R = true;
bool S = true;
bool T = true;
bool U = true;
bool V = true;
bool W = true;
bool X = true;
bool Y = true;
bool Z = true;

//FUNCTIONS =============================================================================

void pturns() 
{
    if (player1turn)
    {
        player2turn = true;
        player1score = player1score + strlen(name) - 2;
        player1turn = false;
        timee = 0;
    }
    else
    {
        player1turn = true;
        player2score = player2score + strlen(name) - 2;
        player2turn = false;
        timee = 0;
    }
}

void usedbefore()
{
    for (int takenloop = 0; takenloop < strlen(used); takenloop++)
    {
        notused[takenloop] = used[takenloop];
    }
}






typedef struct Cell
{
    int i;
    int j;
    bool containsLetter;
    bool used;
    
} Cell;


Cell grid[COLS][ROWS];

void CellDraw(Cell);


int main()
{
    
    
    SetTargetFPS(60);
    

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            grid[i][j] = (Cell) 
            {
                .i = i,
                .j = j
            };
        }
    }

    
    Rectangle textBox = { 200, 550, 810, 200 };
    Rectangle nameBox = { 382, 550, 435, 100};
   
    char notsame[30] = "";
    char notsameworks[] = "Doesn't Work";
    char notsameagain[30] = "";
    
    
    
    char crossA[30] = ""; //A
    char crossed[] = "/";
    
    char crossB[30] = ""; //B
    
    char crossC[30] = ""; //C

    char crossD[30] = ""; //D

    char crossE[30] = ""; //E
    
    char crossF[30] = ""; //F
    
    char crossG[30] = ""; //G
    
    char crossH[30] = ""; //H
    
    char crossI[30] = ""; //I
    
    char crossJ[30] = ""; //J
    
    char crossK[30] = ""; //K
    
    char crossL[30] = ""; //L
    
    char crossM[30] = ""; //M
    
    char crossN[30] = ""; //N
    
    char crossO[30] = ""; //O
    
    char crossP[30] = ""; //P
    
    char crossQ[30] = ""; //Q
    
    char crossR[30] = ""; //R
    
    char crossS[30] = ""; //S
    
    char crossT[30] = ""; //T
    
    char crossU[30] = ""; //U
    
    char crossV[30] = ""; //V
    
    char crossW[30] = ""; //W
    
    char crossX[30] = ""; //X
    
    char crossY[30] = ""; //Y
    
    char crossZ[30] = ""; //Z



    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (titlescreen)
        {
            if(IsKeyPressed(KEY_ENTER))
            {
                titlescreen = false;
                menuP1shown = true;
            }
        }
        
        
        if (menuP1shown) // PLAYER ONE'S NAME ENTRY
        {
            int p1key = GetCharPressed();
            while (p1key > 0)
            {
                if ((p1key >= 32 || p1key <= 122) && (letterCount < MAX_INPUT_CHARS))
                {
                    player1[letterCount] = (char)p1key;
                    player1[letterCount+1] = '\0';
                    player1name[letterCount] = (char)p1key;
                    player1name[letterCount+1] = '\0';
                    player1nameturn[letterCount] = (char)p1key;
                    player1nameturn[letterCount+1] = '\0';
                    

                    letterCount++;
                }
                p1key = GetCharPressed();
            }
            
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                {
                    player1[letterCount] = '\0';
                }
            }
            
            
            if (IsKeyPressed(KEY_ENTER))
            {
                letterCount = 0;
                if (letterCount < 0) letterCount = 0;
                {
                    for (int p1letter = 0; p1letter < sizeof(player1); p1letter++)
                    {
                        player1[p1letter] = player1[p1letter];
                    }
                    
                }
                if (strlen(player1) > 0)
                {
                    menuP1shown = false;
                    menuP2shown = true;
                }
            }
        }
        
        if (menuP2shown) // PLAYER TWO'S NAME ENTRY
        {
            int p2key = GetCharPressed();
            while (p2key > 0)
            {
                if ((p2key >= 32 || p2key <= 122) && (letterCount < MAX_INPUT_CHARS))
                {
                    player2[letterCount] = (char)p2key;
                    player2[letterCount+1] = '\0';
                    player2name[letterCount] = (char)p2key;
                    player2name[letterCount+1] = '\0';
                    player2nameturn[letterCount] = (char)p2key;
                    player2nameturn[letterCount+1] = '\0';
                    
                    
                    
                    letterCount++;
                }
                p2key = GetCharPressed();
                
            }

            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                {
                    player2[letterCount] = '\0';
                }
            }
            
            if (IsKeyPressed(KEY_ENTER))
            {
                letterCount = 0;
                if (letterCount < 0) letterCount = 0;
                {
                    for (int p2letter = 0; p2letter < sizeof(player1); p2letter++)
                    {
                        player2[p2letter] = player2[p2letter];
                    }
                }
                if (strlen(player2) > 0)
                {
                    menuP2shown = false;
                    menuGenreshown = true;
                }
            }            

        }
        
        if (menuGenreshown) // PLAYER TWO'S NAME ENTRY
        {
            int genrekey = GetCharPressed();
            while (genrekey > 0)
            {
                if ((genrekey >= 32 || genrekey <= 122) && (letterCount < MAX_INPUT_CHARS))
                {
                    genre[letterCount] = (char)genrekey;
                    genre[letterCount+1] = '\0';
                    letterCount++;
                }
                genrekey = GetCharPressed();
            }
            
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                {
                    genre[letterCount] = '\0';
                }
            }
            
            if (IsKeyPressed(KEY_ENTER))
            {
                letterCount = 0;
                if (letterCount < 0) letterCount = 0;
                {
                    for (int genreletter = 0; genreletter < sizeof(player1); genreletter++)
                    {
                        genre[genreletter] = genre[genreletter];
                    }

                }
                if (strlen(genre) > 0)
                {
                    menuGenreshown = false;
                    counter3 = true;
                }
            }
        }
        
        if (counter3)
        {
            
            frames++;    //increase the frames int by 1 every frame
            if (frames==60) 
            { 
                strcat(player1name, wins); //NAMES WINNING AT THE END
                strcat(player2name, wins);
                
                strcat(player1nameturn, turns);
                strcat(player2nameturn, turns);
                
                frames = 0;  //increase time every 60 frames, so each time this goes up by one, a second has passed
                counter3 = false;
                counter2 = true;
            }
        }
        
        if (counter2)
        {
            frames++;    //increase the frames int by 1 every frame
            if (frames==60) 
            {
                frames = 0;  //increase time every 60 frames, so each time this goes up by one, a second has passed
                counter2 = false;
                counter1= true;
            }
        }
        
        if (counter1)
        {
            frames++;    //increase the frames int by 1 every frame
            if (frames==60) 
            { 
                frames = 0;  //increase time every 60 frames, so each time this goes up by one, a second has passed
                counter1 = false;
                countergo = true;
            }
        }
        
        if (countergo)
        {
            frames++;    //increase the frames int by 1 every frame
            if (frames==60) 
            { 
                frames = 0;  //increase time every 60 frames, so each time this goes up by one, a second has passed
                countergo = false;
                game = true;

            }
        }
        
        
        
        if (game)
        {
            frames++;    //increase the frames int by 1 every frame
            if (frames==60) 
            {
                timee++;    
                frames = 0;  //increase time every 60 frames, so each time this goes up by one, a second has passed
            }
            
            if (timee == 8)
            {
                game = false;
                gameend = true;
            }
        }
        
        
        
        if (game)
        {
            
            int key = GetCharPressed();
            while (key > 0)
            {
                if ((key >= 32 || key <= 122) && (letterCount < MAX_INPUT_CHARS))
                {
                    name[letterCount] = (char)key;
                    name[letterCount+1] = '\0';
                    letterCount++;
                }
                key = GetCharPressed();
            }
            
            if (IsKeyPressed(KEY_BACKSPACE))
            {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                {
                    name[letterCount] = '\0';
                }
            }


            if (IsKeyPressed(KEY_ENTER))
            {
                
                if (notused[0] == used[0])
                {
                    for (int notagaincounter = 0; notagaincounter < strlen(notused); notagaincounter++)
                    {
                        notused[notagaincounter] = notusedagain[notagaincounter];
                    }
                }
                if (name[0] != name[2])
                {
                    int loop1;
                    for (loop1 = 0; loop1 <= sizeof(notsameworks); loop1++)
                    {
                        notsame[loop1] = notsameworks[loop1];
                    }
                }
                
                if (name[0] == name[2] && isalpha(name[0]))
                {
                    turncounter = turncounter + 1;
                }
                
                if (!A && !B && !C && !D && !E && !F && !G && !H && !I && !J && !K && !L && !M && !N && !O && !P && !Q && !R && !S && !T && !U && !V && !W && !X && !Y && !Z)
                {
                    game = false;
                    gameend = true;
                }
                
                
                if (name[0] == name[2] && name [0] == 'a')
                {
                    crossA[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (A == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    A = false;
                    
                }
                else if (name[0] == name[2] && name [0] == 'b')
                {
                    crossB[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (B == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    B = false;
                    
                }
                else if (name[0] == name[2] && name [0] == 'c')
                {
                    crossC[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (C == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    C = false;
                }
                else if (name[0] == name[2] && name [0] == 'd')
                {
                    crossD[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (D == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    D = false;
                }
                else if (name[0] == name[2] && name [0] == 'e')
                {
                    crossE[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (E == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    E = false;
                }
                else if (name[0] == name[2] && name [0] == 'f')
                {
                    crossF[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (F == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    F = false;
                }
                else if (name[0] == name[2] && name [0] == 'g')
                {
                    crossG[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (G == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    G = false;
                }
                else if (name[0] == name[2] && name [0] == 'h')
                {
                    crossH[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (H == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    H = false;
                }
                else if (name[0] == name[2] && name [0] == 'i')
                {
                    crossI[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (I == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    I = false;
                }
                else if (name[0] == name[2] && name [0] == 'j')
                {
                    crossJ[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (J == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    J = false;
                }
                else if (name[0] == name[2] && name [0] == 'k')
                {
                    crossK[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (K == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    K = false;
                }
                else if (name[0] == name[2] && name [0] == 'l')
                {
                    crossL[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (L == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    L = false;
                }
                else if (name[0] == name[2] && name [0] == 'm')
                {
                    crossM[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (M == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    M = false;
                }
                else if (name[0] == name[2] && name [0] == 'n')
                {
                    crossN[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (N == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    N = false;
                }
                else if (name[0] == name[2] && name [0] == 'o')
                {
                    crossO[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (O == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    O = false;
                }
                else if (name[0] == name[2] && name [0] == 'p')
                {
                    crossP[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (P == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    P = false;
                }
                else if (name[0] == name[2] && name [0] == 'q')
                {
                    crossQ[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (Q == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    Q = false;
                }
                else if (name[0] == name[2] && name [0] == 'r')
                {
                    crossR[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (R == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    R = false;
                }
                else if (name[0] == name[2] && name [0] == 's')
                {
                    crossS[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (S == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    S = false;
                }
                else if (name[0] == name[2] && name [0] == 't')
                {
                    crossT[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (T == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    T = false;
                }
                else if (name[0] == name[2] && name [0] == 'u')
                {
                    crossU[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (U == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    U = false;
                }
                else if (name[0] == name[2] && name [0] == 'v')
                {
                    crossV[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (V == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    V = false;
                }
                else if (name[0] == name[2] && name [0] == 'w')
                {
                    crossW[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (W == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    W = false;
                }
                else if (name[0] == name[2] && name [0] == 'x')
                {
                    crossX[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (X == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    X = false;
                }
                else if (name[0] == name[2] && name [0] == 'y')
                {
                    if (Y == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    Y = false;
                }
                else if (name[0] == name[2] && name [0] == 'z')
                {
                    crossZ[0] = crossed[0];
                    notsame[0] = notsameagain[0];
                    if (Z == true)
                    {
                        pturns();
                    }
                    else
                    {
                        usedbefore();
                    }
                    Z = false;
                }

            }

            if (IsKeyPressed(KEY_ENTER))
            {
                letterCount = 0;
                if (letterCount < 0) letterCount = 0;
                {
                    name[letterCount] = '\0';
                }
                
            }
            
        }
        if (gameend)
        {
            if (IsKeyPressed(KEY_ENTER))
            {
                return 1;
            }
        }
        
        
        
        
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(10, 10);
            
            if (titlescreen)
            {
                DrawText("Alphaletter", 165, 225, 150, MAROON);
                DrawText("Press Enter to start", 370, 500, 40, BLACK);
                DrawText("Created and Developed by Kevin He", 10, 770, 25, BLACK);
            }
            
            
            
            
            if (menuP1shown)
            {
                DrawText("Enter Player One's Name:", (int)nameBox.x - 42, (int)nameBox.y - 50, 40, MAROON);
                
                DrawRectangleRec(nameBox, LIGHTGRAY);

                DrawRectangleLines((int)nameBox.x, (int)nameBox.y, (int)nameBox.width, (int)nameBox.height, RED);
                
                
                DrawText(player1, (int)nameBox.x + 5, (int)nameBox.y + 30, 60, MAROON);
                DrawText("____________", (int)nameBox.x + 5, (int)nameBox.y + 40, 60, MAROON);
            }
            
            
            if (menuP2shown)
            {
                DrawText("Enter Player Two's Name:", (int)nameBox.x - 42, (int)nameBox.y - 50, 40, MAROON);
                DrawRectangleRec(nameBox, LIGHTGRAY);

                DrawRectangleLines((int)nameBox.x, (int)nameBox.y, (int)nameBox.width, (int)nameBox.height, RED);
                
                
                DrawText(player2, (int)nameBox.x + 5, (int)nameBox.y + 30, 60, MAROON);
                DrawText("____________", (int)nameBox.x + 5, (int)nameBox.y + 40, 60, MAROON);
            }
            
            
            if (menuGenreshown)
            {
                DrawText("Enter Genre: ", (int)nameBox.x + 85, (int)nameBox.y - 50, 40, MAROON);
                DrawRectangleRec(nameBox, LIGHTGRAY);

                DrawRectangleLines((int)nameBox.x, (int)nameBox.y, (int)nameBox.width, (int)nameBox.height, RED);
                
                
                DrawText(genre, (int)nameBox.x + 5, (int)nameBox.y + 30, 60, MAROON);
                DrawText("____________", (int)nameBox.x - 80 + MeasureText("text", 40), (int)nameBox.y + 40, 60, MAROON);
            }

            if (counter3)
            {
                DrawText("3...", 450, 225, 350, MAROON);
            }
            
            if (counter2)
            {
                DrawText("2...", 450, 225, 350, MAROON);
            }
            
            if (counter1)
            {
                DrawText("1...", 450, 225, 350, MAROON);
            }
            
            if (countergo)
            {
                DrawText("GO!!!", 300, 225, 350, MAROON);
            }




            if (game)
            {
                DrawText(TextFormat("%d", timee), 50, 250, 30, BLACK);
                int lettersplaced = 26;
                int horizontal = 9;
                for (int i = 0; i < COLS; i++)
                {
                    for (int j = 0; j < ROWS; j++)
                    {
                        DrawRectangleLines(i * cellWidth + 50, j * cellHeight + 100, cellWidth, cellHeight, BLACK);
                    }
                    DrawText(TextFormat("%c", i + 97), horizontal + 50, 105, 40, BLACK);
                    horizontal += 42;
                }
                
                if (player1turn)
                {
                    DrawText(player1nameturn, 475, 50, 35, MAROON);
                }
                else
                {
                    DrawText(player2nameturn, 475, 50, 35, MAROON);
                }
                
                
                strcpy(playerscoredisplay1, player1);
                strcpy(playerscoredisplay2, player2);
                
                
                
                char playerscoreshown[50] = "'s score: ";
                
                char genredisplay[50] = "Genre: ";
                
                strcat(genredisplay, genre);
                
                strcat(playerscoredisplay1, playerscoreshown);
                strcat(playerscoredisplay2, playerscoreshown);
                
                

                
                char p1score[10];
                char p2score[10];
                DrawText(TextFormat("%i", player1score), 325, 150, 35,BLACK);
                DrawText(TextFormat("%i", player2score), 325, 180, 35,BLACK);
                //sprintf(p1score, "%i", player1score);
                //sprintf(p2score, "%i", player2score);

                strcat(playerscoredisplay1, p1score);
                strcat(playerscoredisplay2, p2score);
                
                
                DrawRectangleRec(textBox, LIGHTGRAY);

                DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
                
                DrawText("_____________________", (int)textBox.x - 79 + MeasureText("text", 40), (int)textBox.y + 100, 65, MAROON); // UNDERSCORES FOR TEXT
                
                
                DrawText(playerscoredisplay1, 50, 150, 30, MAROON);
                DrawText(playerscoredisplay2, 50, 180, 30, MAROON);
                DrawText(genredisplay, 50, 210, 30, MAROON);
                

                
                //435, 550, 325, 50
                
                DrawText(name, (int)textBox.x + 5, (int)textBox.y + 75, 71, MAROON);

                DrawText(notsame, (int)textBox.x + 200, (int)textBox.y - 60, 60, MAROON);
                
                DrawText(notused, (int)textBox.x + 200, (int)textBox.y - 60, 60, MAROON);
                
                DrawText(crossA, cellWidth + 11, cellHeight + 54, 52, RED);

                DrawText(crossB, cellWidth + 52, cellHeight + 54, 52, RED);
                
                DrawText(crossC, cellWidth + 95, cellHeight + 54, 52, RED);
                
                DrawText(crossD, cellWidth + 137, cellHeight + 54, 52, RED);
                
                DrawText(crossE, cellWidth + 178, cellHeight + 54, 52, RED);
                
                DrawText(crossF, cellWidth + 221, cellHeight + 54, 52, RED);
                
                DrawText(crossG, cellWidth + 263, cellHeight + 54, 52, RED);
                
                DrawText(crossH, cellWidth + 305, cellHeight + 54, 52, RED);
                
                DrawText(crossI, cellWidth + 346, cellHeight + 54, 52, RED);
                
                DrawText(crossJ, cellWidth + 388, cellHeight + 54, 52, RED);
                
                DrawText(crossK, cellWidth + 430, cellHeight + 54, 52, RED);
                
                DrawText(crossL, cellWidth + 473, cellHeight + 54, 52, RED);
                
                DrawText(crossM, cellWidth + 515, cellHeight + 54, 52, RED);
                DrawText(crossN, cellWidth + 557, cellHeight + 54, 52, RED);
                DrawText(crossO, cellWidth + 599, cellHeight + 54, 52, RED);
                DrawText(crossP, cellWidth + 641, cellHeight + 54, 52, RED);
                DrawText(crossQ, cellWidth + 682, cellHeight + 54, 52, RED);
                DrawText(crossR, cellWidth + 725, cellHeight + 54, 52, RED);
                DrawText(crossS, cellWidth + 767, cellHeight + 54, 52, RED);
                DrawText(crossT, cellWidth + 809, cellHeight + 54, 52, RED);
                DrawText(crossU, cellWidth + 851, cellHeight + 54, 52, RED);
                DrawText(crossV, cellWidth + 893, cellHeight + 54, 52, RED);
                DrawText(crossW, cellWidth + 935, cellHeight + 54, 52, RED);
                DrawText(crossX, cellWidth + 977, cellHeight + 54, 52, RED);
                DrawText(crossY, cellWidth + 1019, cellHeight + 54, 52, RED);
                DrawText(crossZ, cellWidth + 1061, cellHeight + 54, 52, RED);
                
                
            }
            

            if (gameend)
            {
                DrawText(playerscoredisplay1, 325, 550, 60, MAROON);
                DrawText(playerscoredisplay2, 325, 600, 60, MAROON);
                DrawText(TextFormat("%i", player1score), 800, 560, 50,BLACK);
                DrawText(TextFormat("%i", player2score), 800, 610, 50,BLACK);
                DrawText("Press Enter to quit", 300, 700, 60, MAROON);
                if (player1turn)
                {
                    DrawText(player2name, 250, 225, 120, BLACK);
                }
                else
                {
                    DrawText(player1name, 250, 225, 120, BLACK);
                }
                
            }
            
            
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void CellDraw(Cell cell)
{
    DrawRectangleLines(cell.i * cellWidth, cell.j * cellHeight, cellWidth, cellHeight, BLACK);
}

