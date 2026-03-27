#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#define BOARDSIZE 100
#define MAX 100

void snake_ladder();
int postGameMenu();
int login();
void signup();
int authenticate(const char *user, const char *pass);
void number_guessing();
void word_guessing();
void snake__ladder();
void display_();
int nahianlevel();
int nahianleve2();
int nahianleve3();
int nahianleve4();
int nahianleve5();
int nahian();
void rockpaper();

void signup() {
    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("Error opening users file.\n");
        return;
    }

    char username[MAX], password[MAX];

    printf("\033[1;35mChoose a username: \033[0m");
    scanf("%s", username);
    printf("\033[1;33mChoose a password: \033[0m");
    scanf("%s", password);

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);
    printf("Signup successful! You can now log in.\n");
}

int authenticate(const char *user, const char *pass) {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error opening users file.\n");
        return 0;
    }

    char fileUser[MAX], filePass[MAX];
    while (fscanf(fp, "%s %s", fileUser, filePass) != EOF) {
        if (strcmp(user, fileUser) == 0 && strcmp(pass, filePass) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int login() {
    char username[MAX], password[MAX];
    int tries = 3;

    while (tries--) {
            sleep(2);
            system("cls");
                 printf("\033[45m\033[97m");


    printf("\033[2J\033[H");

        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
         int i = 0;
    char ch;



    while (1) {
        ch = getch();  // take input without showing

        if (ch == 13) {  // Enter key
            break;
        }
        else if (ch == 8) {  // Backspace
            if (i > 0) {
                i--;
                printf("\b \b"); // erase last *
            }
        }
        else {
            password[i++] = ch;
            printf("*"); // show *
        }
    }

    password[i] = '\0';

        if (authenticate(username, password)) {
            printf("Login successful! Welcome %s.\n", username);
            return 1;
        } else {
            printf("Invalid credentials. %d attempt(s) left.\n", tries);
        }

    }
    printf("Too many failed attempts. Exiting...\n");
    return 0;
}

int postGameMenu() {
    int choice;
    printf("\n\033[1;34mWhat would you like to do next?\033[0m\n");
    printf("\033[1;35m1. Play again\033[0m\n");
    printf("\033[1;36m2. Return to main menu\033[0m\n");
    printf("\033[1;33m3. Exit\033[0m\n");
    printf("\033[1;32mEnter choice: \033[0m");
    scanf("%d", &choice);
Sleep(1);
system("cls");
    if (choice == 3) {
        printf("Exiting...\n");
        exit(0);
    } else if (choice == 1 || choice == 2) {
        return choice;
    } else {
        printf("Invalid Input\n");
        return 0;
    }
}

int rollDice() {
    return rand() % 6 + 1;
}

int SnakesAndLadders(int position) {
    int ladders[BOARDSIZE + 1] = {0};
    int snakes[BOARDSIZE + 1] = {0};

    ladders[2] = 38; ladders[7] = 14; ladders[8] = 31;
    ladders[15] = 60; ladders[21] = 42; ladders[28] = 84;
    ladders[36] = 44; ladders[51] = 67; ladders[71] = 91;
    ladders[78] = 98;

    snakes[16] = 6; snakes[46] = 25; snakes[49] = 11;
    snakes[62] = 19; snakes[64] = 60; snakes[74] = 53;
    snakes[89] = 68; snakes[92] = 88; snakes[95] = 75;
    snakes[99] = 80;

    if (ladders[position] != 0) {
        printf("\033[1;36mLadder!\033[0m \033[1;33mMoving from %d to %d\033[0m\n", position, ladders[position]);
        return ladders[position];
    }
    if (snakes[position] != 0) {
        printf("\033[1;35mSnake!\033[0m \033[1;33mMoving from %d to %d\033[0m\n", position, snakes[position]);
        return snakes[position];
    }
    return position;
}

void movePlayer(int *player, char *name) {
    int dice = rollDice();
    printf("\033[1;33m%s rolled: %d\033[0m\n", name, dice);
    *player += dice;
    if (*player > BOARDSIZE) {
        *player -= dice;
        printf("\033[1;35mYou need an exact roll to win!\033[0m\n");
    } else {
        *player = SnakesAndLadders(*player);
    }
    printf("\033[1;34m%s's new position: %d\033[0m\n", name, *player);
}

void snake_ladder() {
    do {
        srand(time(0));
        int start;
        char name1[20], name2[20];
        printf("\033[1;33mWelcome to Snakes and Ladders!\033[0m\n");
        printf("\033[1;34mEnter Player 1's Name: \033[0m");
        scanf("%s", name1);
        printf("\033[1;35mEnter Player 2's Name: \033[0m");
        scanf("%s", name2);

        while (1) {
            printf("\n\033[1;32m1. Start\033[0m\n");
            printf("\033[1;35m2. How To Play\033[0m\n");
            printf("\033[1;36m3. Exit\033[0m\n");
            scanf("%d", &start);

            if (start == 2) {
                snake__ladder();
                display_();
                continue;
            } else if (start == 3) {
                return;
            } else if (start == 1) {
                break;
            } else {
                printf("Invalid input.\n");
            }
        }

        int player1 = 0, player2 = 0, turn = 1;
        char choice;
        while (player1 < BOARDSIZE && player2 < BOARDSIZE) {
            if (turn == 1) {
                printf("\n\033[1;36m%s's turn (Press 'r' to roll, 'q' to quit): \033[0m", name1);
            } else {
                printf("\n\033[1;33m%s's turn (Press 'r' to roll, 'q' to quit): \033[0m", name2);
            }
            scanf(" %c", &choice);

            if (choice == 'q') {
                printf("\033[1;31mGame exited.\033[0m\n");
                break;
            } else if (choice != 'r') {
                printf("\033[1;31mInvalid input!\033[0m\n");
                continue;
            }

            if (turn == 1) {
                movePlayer(&player1, name1);
                if (player1 == BOARDSIZE) {
                    printf("\n\033[1;36m%s wins!\033[0m\n", name1);
                    break;
                }
                turn = 2;
            } else {
                movePlayer(&player2, name2);
                if (player2 == BOARDSIZE) {
                    printf("\n\033[1;36m%s wins!\033[0m\n", name2);
                    break;
                }
                turn = 1;
            }
        }
    } while (postGameMenu() == 1);
}

void snake__ladder(){
    FILE* fp=fopen("howtoplay.txt", "a");
    if(fp==NULL){
        printf("No files\n");
        return;
    }
    printf("\033[1;33mThe \033[1;31mSnake\033[0m \033[1;33mand\033[0m \033[1;34mLadder\033[0m \033[1;33mgame is a classic board game played on a 100 square grid, where players move based on dice rolls. The objective is to reach square 100 first. The game features ladders, which help players move ahead, and snakes, which bring them down.\033[0m");
    printf("\n");
    printf("\033[1;34mLadder Positions: \033[0m\n");
    printf("\033[1;32m2 jumps to 38\n");
    printf("7 jumps to 14\n");
    printf("8 jumps to 31\n");
    printf("15 jumps to 60\n");
    printf("21 jumps to 42\n");
    printf("28 jumps to 84\n");
    printf("36 jumps to 44\n");
    printf("51 jumps to 67\n");
    printf("71 jumps to 91\n");
    printf("78 jumps to 98\033[0m\n");
    printf("\n");
    printf("\033[1;31mSnake Positions: \033[0m\n");
    printf("\033[1;32m16 goes down to 6\n");
    printf("46 goes down to 25\n");
    printf("49 goes down to 11\n");
    printf("62 goes down to 19\n");
    printf("64 goes down to 60\n");
    printf("74 goes down to 53\n");
    printf("89 goes down to 68\n");
    printf("92 goes down to 88\n");
    printf("95 goes down to 75\n");
    printf("99 goes down to 80\033[0m\n");
    printf("\n");
    printf("\033[1;33mPlayers start at square 1, roll a dice (1 to 6), and move accordingly.Landing on a ladder's base moves the player up, while landing on a snake's head drops them down. The game continues until a player reaches exactly 100 to win.\033[0m\n");
    fclose(fp);
}

void word_guessing() {
    // Start with the difficulty selection menu
    nahian();
}

int nahianlevel(){
    srand(time(NULL));
    int c=rand()%5+1;
    char *word;
    switch (c){
        case 1:word="cat";break;
        case 2:word="dog";break;
        case 3: word="sun";break;
        case 4: word="hat";break;
        case 5: word="fish"; break;
    }
    int len=strlen(word),correct=0;
    char display[len+1];
    for(int i=0;i<len;i++){
        display[i]='_';
    }
    display[len]='\0';
    int flag=0;
    while(correct<len){
        printf("\033[1;31m%s\033[0m\n",display);
        printf("\033[1;32mEnter your guess (multiple letters allowed):\033[0m\n");
        char Guess[20];
        if (flag==0)printf("\033[1;41mFor Hint Enter 1.\033[0m\n");
        scanf(" %s",Guess);

        if (flag==0){if(Guess[0]=='1'){
                flag=1;
            switch(c){
                case 1:printf("\033[1;33mA small, domesticated, carnivorous mammal, often kept as a pet.\033[0m\n");break;
                case 2:printf("\033[1;33mI have four legs, a wagging tail, and I'm known as man's best friend. Who am I?\033[0m\n");break;
                case 3:printf("\033[1;33mI shine brightly in the sky and give light and warmth to the world.\033[0m\n");break;
                case 4:printf("\033[1;33mYou wear me on your head to protect yourself from the sun or cold.\033[0m\n");break;
                case 5:printf("\033[1;33mI swim in water, have scales, and breathe through gills.\033[0m\n");break;
            }
        }}
        else if(flag==1 && Guess[0]=='1')printf("\033[1;36mYou have already used your guess.\033[1;36m\n");
        int m=correct;
        for(int i=0;Guess[i]!='\0';i++){
            for(int j=0;j<len;j++){
                if(Guess[i]==word[j] && Guess[i]!=display[j]){
                    display[j]=Guess[i];
                    correct++;
                }
            }
        }
        if (correct==m && Guess[0]!='1')printf("\033[1;31mWrong Guess.\033[0m\n");
    }
    printf("\033[1;32mCongratulatuions you guessed right.\nThe word is '%s'.\033[0m\n",word);
    int a;
    printf("\033[1;33mEnter '1' to Return to Main Menu.\033[0m\n\033[1;34mEnter '2' to Return to Menu.\033[0m\n\033[1;38mEnter '3' to Play again.\033[0m\n\033[1;31mEnter '4' to Exit.\033[0m\n");

    scanf("%d",&a);
    while(a!=1 && a!=2 && a!=3 && a!=4){    printf("\033[1;32mPlease choose between (1-4)\033[0m\n");scanf("%d",&a);}
    switch(a){
        case 2:
            nahian();
            break;

        case 3:
            nahianlevel();
            break;

        case 4:
            return 0;
            break;
    }
    return 0;
}

int nahianleve2(){
    srand(time(NULL));
    int c=rand()%5+1;
    char *word;
    switch (c){
        case 1:word="journal";break;
        case 2:word="tunnel";break;
        case 3: word="fossil";break;
        case 4: word="whisper";break;
        case 5: word="lantern"; break;
    }
    int len=strlen(word),correct=0;
    char display[len+1];
    for(int i=0;i<len;i++){
        display[i]='_';
    }
    display[len]='\0';
    int flag=0,life=10;
    while(correct<len && life>0){
        printf("\033[1;31m%s\033[0m\n",display);
        printf("\033[1;32mEnter your guess (multiple letters allowed):\033[0m\n");
        char Guess[20];
        if (flag==0)printf("\033[1;41mFor Hint Enter 1.\033[0m\n");
        scanf(" %s",Guess);

        if (flag==0){if(Guess[0]=='1'){
                flag=1;
            switch(c){
                case 1:printf("\033[1;33mPeople write their thoughts in it.\033[0m\n");break;
                case 2:printf("\033[1;33mA passage through a mountain.\033[0m\n");break;
                case 3:printf("\033[1;33mRemains of ancient creatures.\033[0m\n");break;
                case 4:printf("\033[1;33mSpeaking very softly.\033[0m\n");break;
                case 5:printf("\033[1;33mA light source for camping.\033[0m\n");break;
            }
        }}
        else if (flag==1 && Guess[0]=='1')printf("\033[1;31mYou have already used your guess.\033[0m\n");
        int m=correct;
        for(int i=0;Guess[i]!='\0';i++){
            for(int j=0;j<len;j++){
                if(Guess[i]==word[j] && Guess[i]!=display[j]){
                    display[j]=Guess[i];
                    correct++;
                }
            }
        }
        if (correct==m && Guess[0]!='1'){
            printf("\033[1;31mWrong Guess.\033[0m\n");
            life--;
            printf("\033[1;35mRemaining life %d\033[0m\n",life);
        }
    }
    if(life!=0)printf("\033[1;36mCongratulatuions you guessed right.\nThe word is '%s'.\033[0m\n",word);
    else printf("\033[1;31mYou lost the game.\nThe word is '%s'.\033[0m\n",word);

    int a;
    printf("\033[1;33mEnter '1' to Return to Main Menu.\033[0m\n\033[1;34mEnter '2' to Return to Menu.\033[0m\n\033[1;38mEnter '3' to Play again.\033[0m\n\033[1;31mEnter '4' to Exit.\033[0m\n");

    scanf("%d",&a);
    while(a!=1 && a!=2 && a!=3 && a!=4){    printf("\033[1;32mPlease choose between (1-4)\033[0m\n");scanf("%d",&a);}
    switch(a){
        case 2:
            nahian();
            break;

        case 3:
            nahianleve2();
            break;

        case 4:
            return 0;
            break;
    }
    return 0;
}

int nahianleve3(){
    srand(time(NULL));
    int c=rand()%5+1;
    char *word;
    switch (c){
        case 1:word="obfuscate";break;
        case 2:word="zephyr";break;
        case 3: word="quixotic";break;
        case 4: word="chiaroscuro";break;
        case 5: word="mnemonics"; break;
    }
    int len=strlen(word),correct=0;
    char display[len+1];
    for(int i=0;i<len;i++){
        display[i]='_';
    }
    display[len]='\0';
    int flag=0,life=10;
    for(int i=0;i<len;i+=3){
        display[i]=word[i];
        correct++;
    }
    while(correct<len && life>0){
        printf("\033[1;31m%s\033[0m\n",display);
        printf("\033[1;32mEnter your guess (multiple letters allowed):\033[0m\n");
        char Guess[20];
        if (flag==0)printf("\033[1;41mFor Hint Enter 1.\033[0m\n");
        scanf(" %s",Guess);

        if (flag==0){if(Guess[0]=='1'){
                flag=1;
            switch(c){
                case 1:printf("\033[1;33mTo make something unclear or confusing.\033[0m\n");break;
                case 2:printf("\033[1;33mA gentle breeze, often from the west.\033[0m\n");break;
                case 3:printf("\033[1;33mExtremely idealistic but impractical, like Don Quixote.\033[0m\n");break;
                case 4:printf("\033[1;33mAn art technique using strong contrasts of light and dark.\033[0m\n");break;
                case 5:printf("\033[1;33mMemory aids or techniques for remembering information.\033[0m\n");break;
            }
        }}
        else if (flag==1 && Guess[0]=='1')printf("\033[1;36mYou have already used your guess.\033[0m\n");
        int m=correct;

        for(int i=0;Guess[i]!='\0';i++){
            for(int j=0;j<len;j++){
                if(Guess[i]==word[j] && Guess[i]!=display[j]){
                    display[j]=Guess[i];
                    correct++;
                }
            }
        }
        if (correct==m && Guess[0]!='1'){
            printf("\033[1;31mWrong Guess.\033[0m\n");
            life--;
            printf("\033[1;35mRemaining life %d\033[0m\n",life);
        }

        if(life!=0)printf("\033[1;36mCongratulatuions you guessed right.\nThe word is '%s'.\033[0m\n",word);
        else printf("\033[1;31mYou lost the game.\033[0m\n");

        int a;
        printf("\033[1;33mEnter '1' to Return to Main Menu.\033[0m\n\033[1;34mEnter '2' to Return to Menu.\033[0m\n\033[1;38mEnter '3' to Play again.\033[0m\n\033[1;31mEnter '4' to Exit.\033[0m\n");

        scanf("%d",&a);
        while(a!=1 && a!=2 && a!=3 && a!=4){    printf("\033[1;32mPlease choose between (1-4)\033[0m\n");scanf("%d",&a);}
        switch(a){
            case 2:
                nahian();
                break;

            case 3:
                nahianleve3();
                break;

            case 4:
                return 0;
                break;
        }
    }
    return 0;
}

int nahianleve4(){
    srand(time(NULL));
    int c=rand()%5+1;
    char *word;
    switch (c){
        case 1:word="floccinaucinihilipilification";break;
        case 2:word="pneumonoultramicroscopicsilicovolcanoconiosis";break;
        case 3: word="antidisestablishmentarianism";break;
        case 4: word="hippopotomonstrosesquipedaliophobia";break;
        case 5: word="supercalifragilisticexpialidocious"; break;
    }
    int len=strlen(word),correct=0;
    char display[len+1];
    for(int i=0;i<len;i++){
        display[i]='_';
    }
    display[len]='\0';
    int flag=0,life=5;
    while(correct<len && life>0){
        printf("\033[1;31m%s\033[0m\n",display);
        printf("\033[1;32mEnter your guess (multiple letters allowed):\033[0m\n");
        char Guess[20];
        if (flag==0)printf("\033[1;41mFor Hint Enter 1.\033[0m\n");
        scanf(" %s",Guess);

        if (flag==0){if(Guess[0]=='1'){
                flag=1;
            switch(c){
                case 1:printf("\033[1;33mThe act of regarding something as worthless.\033[0m\n");break;
                case 2:printf("\033[1;33mA lung disease caused by inhaling very fine silica dust; often cited as the longest word in English.\033[0m\n");break;
                case 3:printf("\033[1;33mOpposition to the disestablishment of a state church (historically in England).\033[0m\n");break;
                case 4:printf("\033[1;33mIronically, the fear of long words.\n");break;
                case 5:printf("\033[1;33mA fanciful word popularized by the 1964 movie Mary Poppins, meaning 'fantastic' or 'extraordinary'.\033[0m\n");break;
            }
        }}
        else if (flag==1 && Guess[0]=='1')printf("\033[1;36mYou have already used your guess.\033[0m\n");
        int m=correct;

        for(int i=0;Guess[i]!='\0';i++){
            for(int j=0;j<len;j++){
                if(Guess[i]==word[j] && Guess[i]!=display[j]){
                    display[j]=Guess[i];
                    correct++;
                }
            }
        }

        if (correct==m && Guess[0]!='1'){
            printf("\033[1;31mWrong Guess.\033[0m\n");
            life--;
            printf("\033[1;35mRemaining life %d\033[0m\n",life);
        }
        if(life!=0)printf("\033[1;36mCongratulatuions you guessed right.\nThe word is '%s'.\033[0m\n",word);
        else printf("\033[1;31mYou lost the game.\033[0m\n");

        int a;
        printf("\033[1;33mEnter '1' to Return to Main Menu.\033[0m\n\033[1;34mEnter '2' to Return to Menu.\033[0m\n\033[1;38mEnter '3' to Play again.\033[0m\n\033[1;31mEnter '4' to Exit.\033[0m\n");

        scanf("%d",&a);
        while(a!=1 && a!=2 && a!=3 && a!=4){    printf("\033[1;32mPlease choose between (1-4)\033[0m\n");scanf("%d",&a);}
        switch(a){
            case 2:
                nahian();
                break;

            case 3:
                nahianleve4();
                break;

            case 4:
                return 0;
                break;
        }
    }
    return 0;
}

int nahianleve5(){
    time_t start = time(NULL);
    int duration = 300;
    srand(time(NULL));
    int c = rand() % 15 + 1;
    char *word;

    switch (c) {
        case 1: word = "glacier"; break;
        case 2: word = "meadow"; break;
        case 3: word = "harvest"; break;
        case 4: word = "compass"; break;
        case 5: word = "thunder"; break;
        case 6: word = "orbit"; break;
        case 7: word = "quartz"; break;
        case 8: word = "voyage"; break;
        case 9: word = "dagger"; break;
        case 10: word = "beacon"; break;
        case 11: word = "ember"; break;
        case 12: word = "rift"; break;
        case 13: word = "spectrum"; break;
        case 14: word = "rubble"; break;
        case 15: word = "anchor"; break;
    }

    int len = strlen(word), correct = 0, life = 10, flag = 0;
    char display[len + 1];
    for (int i = 0; i < len; i++) display[i] = '_';
    display[len] = '\0';

    while ((int)difftime(time(NULL), start) < duration && correct < len && life > 0) {
        int remainingTime = duration - (int)difftime(time(NULL), start);
        printf("Time left: %3d seconds\n", remainingTime);
        printf("\033[1;31m%s\033[0m\n", display);
        printf("\033[1;32mEnter your guess (multiple letters allowed):\033[0m\n");

        if (flag == 0)
            printf("\033[1;41mFor Hint Enter 1.\033[0m\n");

        char Guess[20];
        scanf(" %s", Guess);

        if (flag == 0 && Guess[0] == '1') {
            flag = 1;
            switch (c) {
                case 1: printf("\033[1;33mA large mass of ice that moves slowly.\033[0m\n"); break;
                case 2: printf("\033[1;33mA grassy field, often found in the countryside.\033[0m\n"); break;
                case 3: printf("\033[1;33mThe season or act of gathering crops.\033[0m\n"); break;
                case 4: printf("\033[1;33mA tool used for navigation.\033[0m\n"); break;
                case 5: printf("\033[1;33mA loud noise during a storm.\033[0m\n"); break;
                case 6: printf("\033[1;33mThe path of a planet around a star.\033[0m\n"); break;
                case 7: printf("\033[1;33mA shiny crystal often found in rocks.\033[0m\n"); break;
                case 8: printf("\033[1;33mA long journey, especially by sea.\033[0m\n"); break;
                case 9: printf("\033[1;33mA small, sharp knife used as a weapon.\033[0m\n"); break;
                case 10: printf("\033[1;33mA guiding light, often found in lighthouses.\033[0m\n"); break;
                case 11: printf("\033[1;33mA small glowing piece of coal or wood.\033[0m\n"); break;
                case 12: printf("\033[1;33mA crack or split in something solid.\033[0m\n"); break;
                case 13: printf("\033[1;33mA band of colors formed by light.\033[0m\n"); break;
                case 14: printf("\033[1;33mBroken pieces of stone or brick after destruction.\033[0m\n"); break;
                case 15: printf("\033[1;33mA heavy object used to keep a ship in place.\033[0m\n"); break;
            }
        } else if (flag == 1 && Guess[0] == '1') {
            printf("\033[1;31mYou have already used your guess.\033[0m\n");
        } else {
            int matched = correct;
            for (int i = 0; Guess[i] != '\0'; i++) {
                for (int j = 0; j < len; j++) {
                    if (Guess[i] == word[j] && display[j] != word[j]) {
                        display[j] = Guess[i];
                        correct++;
                    }
                }
            }
            if (matched == correct) {
                printf("\033[1;31mWrong Guess.\033[0m\n");
                life--;
                printf("\033[1;35mRemaining life: %d\033[0m\n", life);
            }
        }
    }

    if (correct == len) {
        printf("\033[1;36mCongratulations! You guessed right.\nThe word is '%s'.\033[0m\n", word);
    } else if (life == 0) {
        printf("\033[1;31mYou lost the game.\nThe word is '%s'.\033[0m\n", word);
    } else {
        printf("Sorry.\nYour time is over.\nThe word is '%s'.\n", word);
    }

    int a;
    printf("\033[1;33mEnter '1' to Return to Main Menu.\033[0m\n");
    printf("\033[1;34mEnter '2' to Return to Menu.\033[0m\n");
    printf("\033[1;38mEnter '3' to Play again.\033[0m\n");
    printf("\033[1;31mEnter '4' to Exit.\033[0m\n");

    scanf("%d", &a);
    while (a < 1 || a > 4) {
        printf("\033[1;32mPlease choose between (1-4)\033[0m\n");
        scanf("%d", &a);
    }

    switch (a) {
        case 2: nahian(); break;
        case 3: nahianleve5(); break;
        case 4: return 0;
    }
    return 0;
}

int nahian(){
    printf("\033[38;5;208mWelcome to Word Guessing Game.\033[0m\n");
    printf("\033[1;34mPlease choose difficulty Level.\033[0m\n");
    printf("\033[1;32m1.Easy.\033[0m\n");
    printf("\033[1;36m2.Normal.\033[0m\n");
    printf("\033[1;33m3.Hard.\033[0m\n");
    printf("\033[1;31m4.Impossible.\033[0m\n");
    printf("\033[0;33m5.Time mode.\033[0m\n");
    printf("\033[1;35m6.Return to Main Menu.\033[0m\n");
    printf("\033[0;32m7.Exit\033[1m\n");

    int level;
    scanf("%d",&level);
    if (level==1){
        nahianlevel();
    }
    else if (level==2){
        nahianleve2();
    }
    else if (level==3){
        nahianleve3();
    }
    else if (level==4){
        nahianleve4();
    }
    else if(level==5){
        nahianleve5();
    }
    else if(level==6){
        return 1;
    }
    else if(level==7){
        return 0;
    }
    else {
        printf("Please choose between 1-7\n");
        getchar();
        nahian();
    }
    return 0;
}

void display_(){
    FILE* fp=fopen("howtoplay.txt", "r");
    if(fp==NULL){
        printf("No files\n");
        return;
    }
    char ch;
    while ((ch=fgetc(fp))!=EOF){
        putchar(ch);
    }
    fclose(fp);
}

void number_guessing(){
    do{
        srand(time(NULL));
        printf("\033[1;33mSelect Difficulty Level:\033[0m\n");
        printf("\033[1;32m1. Easy (1-10)\n\033[0m");
        printf("\033[1;35m2. Medium (10-100)\033[0m\n");
        printf("\033[31m3. Hard (100-1000)\033[0m\n");
        printf("\033[1;37m4. Return to Menu\033[0m\n");
        printf("\033[1;34mEnter your choice:\033[0m ");
        int mynum, usernum, lower, upper, choicex, chances = 10;
        scanf("%d", &choicex);
        switch (choicex) {
            case 1:
                lower = 1;
                upper = 10;
                break;
            case 2:
                lower = 10;
                upper = 100;
                break;
            case 3:
                lower = 100;
                upper = 1000;
                break;
            default:
                printf("\033[1;31mInvalid choice! Defaulting to Easy mode (1-10).\033[0m\n");
                lower = 1;
                upper = 10;
        }
        mynum = (rand() % (upper - lower + 1)) + lower;

        printf("\n\033[1;36mI have a number in my mind (%d-%d). Can you guess it? You have %d chances.\033[0m\n\n", lower, upper, chances);

        while (chances > 0) {
            printf("\033[1;33mEnter your guess: \033[0m");
            scanf("%d", &usernum);

            if (mynum == usernum) {
                printf("\033[1;36mYes, you got it!\033[0m\n");
                return;
            } else if (mynum > usernum) {
                printf("\033[1;34mMy number is greater than %d. Try again!\033[0m\n\n", usernum);
            } else {
                printf("\033[1;34mMy number is smaller than %d. Try again!\033[0m\n\n", usernum);
            }

            chances--;
            if (chances > 0) {
                printf("\033[1;35mYou have %d chances left.\n\n\033[0m", chances);
            }
        }

        printf("\033[1;31mSorry, you've used all your chances. The correct number was %d. Better luck next time!\033[0m\n", mynum);

    } while(postGameMenu()==1);
}
void rockpaper() {
    do {
        printf("\033[1;33mWelcome to ROCK PAPER SCISSOR\033[0m\n");
        int level, player, computer, computer1, computer2, win = 0, lose = 0, tie = 0;
        char player_name[10];
        srand(time(0));

        printf("\033[1;32mEnter your name:\033[0m");
        scanf("%s", player_name);
        while (1) {
            printf("\033[1;33mSelect a level\033[0m\n\033[1;34m1.Easy\033[0m\n\033[1;31m2.Hard\033[0m\n\033[1;35m3.Return to Main Menu\033[0m\n\033[1;37m0.Exit\033[0m\n");
            scanf("%d", &level);
            if (level != 1 && level != 2 && level != 0 && level != 3) {
                printf("\033[1;36mSelect between (0-3)\033[0m\n");
            }
            else if (level == 3) {
                return;
            }
            else if (level == 0) {
                return;
            }

            switch (level) {
                case 1:
                    while (1) {
                        srand(time(0));
                        printf("\033[1;33mEnter your choice:\033[0m\n\033[1;35m1.ROCK\033[0m\n\033[1;37m2.PAPER\033[0m\n\033[1;36m3.SCISSOR\033[0m\n\033[1;32m4.Check score\033[0m\n\033[1;33m5.Menu\033[0m\n\033[1;34m6.Main Menu\033[0m\n\033[1;37m0.Exit\033[0m\n");
                        scanf("%d", &player);
                        if (player == 6) {
                            return;
                        }
                        computer = rand() % 3 + 1;
                        if (player == 1) printf("\033[1;33mYou chose ROCK\033[0m\n");
                        if (player == 2) printf("\033[1;33mYou chose PAPER\033[0m\n");
                        if (player == 3) printf("\033[1;33mYou chose SCISSOR\033[0m\n");
                        if (player == 1 || player == 2 || player == 3) {
                            if (computer == 1) printf("\033[1;36mComputer chose ROCK\033[0m\n");
                            if (computer == 2) printf("\033[1;36mComputer chose PAPER\033[0m\n");
                            if (computer == 3) printf("\033[1;36mComputer chose SCISSOR\033[0m\n");
                        }
                        if (player == computer) {
                            tie++;
                            printf("\033[1;37mSorry!It's tie\033[0m\n");
                        }
                        else if ((player != 0 && player != 4) && ((player == 1 && computer == 3) || (player == 2 && computer == 1) || (player == 3 && computer == 2))) {
                            printf("\033[1;32mCongratulations!You won.\033[0m\n");
                            win++;
                        }
                        else if ((player != 0 && player != 4) && ((player == 3 && computer == 1) || (player == 1 && computer == 2) || (player == 2 && computer == 3))) {
                            lose++;
                            printf("\033[1;31mSorry!You lost.\033[0m\n");
                        }
                        if (player == 4) {
                            printf("\033[1;32mWon = %d\033[0m\n\033[1;31mLost = %d\n\033[1;37mTie = %d\033[0m\n", win, lose, tie);
                        }
                        else if (player == 0) {
                            return;
                        }
                        else if (player != 0 && player != 1 && player != 2 && player != 3 && player != 4 && player != 5 && player != 6) {
                            printf("\033[1;34mPlease choose between (0-6)\033[0m\n");
                        }
                        else if (player == 5) {
                            break;
                        }
                    }
                    break;

                case 2:
                    while (1) {
                        srand(time(0));
                        printf("\033[1;33mEnter your choice:\033[0m\n\033[1;35m1.ROCK\033[0m\n\033[1;37m2.PAPER\033[0m\n\033[1;36m3.SCISSOR\033[0m\n\033[1;32m4.Check score\033[0m\n\033[1;33m5.Menu\033[0m\n\033[1;34m6.Main Menu\033[0m\n\033[1;37m0.Exit\033[0m\n");
                        scanf("%d", &player);
                        if (player == 6) {
                            return;
                        }
                        computer1 = rand() % 3 + 1;
                        computer2 = rand() % 3 + 1;
                        if (player == 1) printf("\033[1;33mYou chose ROCK\033[0m\n");
                        if (player == 2) printf("\033[1;33mYou chose PAPER\033[0m\n");
                        if (player == 3) printf("\033[1;33mYou chose SCISSOR\033[0m\n");

                        if (player == 1 || player == 2 || player == 3) {
                            if (computer1 == 1) printf("\033[1;36mComputer1 chose ROCK\033[0m\n");
                            if (computer1 == 2) printf("\033[1;36mComputer1 chose PAPER\033[0m\n");
                            if (computer1 == 3) printf("\033[1;36mComputer1 chose SCISSOR\033[0m\n");
                        }

                        if (player == 1 || player == 2 || player == 3) {
                            if (computer2 == 1) printf("\033[1;34mComputer2 chose ROCK\033[0m\n");
                            if (computer2 == 2) printf("\033[1;34mComputer2 chose PAPER\033[0m\n");
                            if (computer2 == 3) printf("\033[1;34mComputer2 chose SCISSOR\033[0m\n");
                        }

                        if (player == computer1 && player == computer2) {
                            tie++;
                            printf("\033[1;37mSorry!It's tie\033[0m\n");
                        }
                        else if ((player == 1 && computer1 != 2 && computer2 != 2) ||
                                (player == 2 && computer1 != 3 && computer2 != 3) ||
                                (player == 3 && computer1 != 1 && computer2 != 1)) {
                            printf("\033[1;32mCongratulations!You won.\033[0m\n");
                            win++;
                        }
                        else if (player == 1 || player == 2 || player == 3) {
                            lose++;
                            printf("\033[1;31mSorry!You lost.\033[0m\n");
                        }

                        if (player == 4) {
                            printf("\033[1;32mWon = %d\033[0m\n\033[1;31mLost = %d\n\033[1;37mTie = %d\033[0m\n", win, lose, tie);
                        }
                        else if (player == 0) {
                            return;
                        }
                        else if (player != 0 && player != 1 && player != 2 && player != 3 && player != 4 && player != 5 && player != 6) {
                            printf("\033[1;34mPlease choose between (0-6)\033[0m\n");
                        }
                        else if (player == 5) {
                            break;
                        }
                    }
                    break;
            }
        }
    } while (postGameMenu() == 1);
}
int main() {
    int choice, n;
    printf("\033[1;35mWelcome to the Game Center!\033[0m\n");

    while (1) {
        printf("\n\033[1;31m1. Login\033[0m\n\033[1;33m2. Signup\033[0m\n\033[1;34m3. Exit\033[0m\n\033[1;32mChoose an option: \033[0m");
        scanf("%d", &choice);

        if (choice == 1) {
            if (login()) break;
        } else if (choice == 2) {
            signup();
        } else if (choice == 3) {
            printf("Exiting...\n");
            return 0;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }
     printf("\033[45m\033[97m");
printf("\033[2J\033[H");

    printf("Loading...\n");

    for (int i = 0; i <= 100; i++) {
        printf("\r[");

        for (int j = 0; j < i; j++) {
            printf("#");
        }
        for (int j = i; j < 100; j++) {
            printf(" ");
        }

        printf("] %d%%", i);
        Sleep(40);
    }

    printf("\nDone!\n");
            sleep(1);
system("cls");

    while (1) {
            sleep(1);
system("cls");
    char username[30];

     printf("\n\n\n\n\t\t\t\t\n");
     printf("\033[1;34m\033[0m");
    printf("\t\t\t\t\033[1;34m==================================================\n");
    printf("\t\t\t\t|              MAIN MENU                          |\n");
    printf("\t\t\t\t\033[1;34m==================================================|\n");
    printf("\t\t\t\t\033[1;34m| [1] \033[1;36m1.Snake Ladder.\033[0m                             \033[1;34m|\n");
    printf("\t\t\t\t\033[1;34m| [2] \033[1;32m2.Number Guessing.\033[0m                         \033[1;34m |\n");
    printf("\t\t\t\t\033[1;34m| [3] \033[1;34m3.word Guessing.\033[0m                            \033[1;34m|\n");
    printf("\t\t\t\t\033[1;34m| [4] \033[1;35m4.Rock paper scissor\033[0m                       \033[1;34m |\n");
    printf("\t\t\t\t\033[1;34m| [5] \033[1;33m5.Exit.\033[0m                                     \033[1;34m|\n");
    printf("\t\t\t\t\033[1;34m==================================================\033[0m\n");
    printf("\t\t\t\t\033[1;34m>> Enter Your Choice:\033[0m ");
    scanf("%d", &n);
sleep(1);
system("cls");
        switch (n) {
            case 1:
                snake_ladder();
                break;
            case 2:
                number_guessing();
                break;
            case 3:
                word_guessing();
                break;
            case 4:
                rockpaper();
                break;
            case 5:
                printf("Thanks for playing! Goodbye.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
