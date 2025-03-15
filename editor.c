#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<conio.h>


int main(){
    const char *CLEAR_RIGHT = "\033[K"; // clean to the right of the cursor
    const char *PREV_LINE = "\033[F";
    const char *HOME = "\033[0G";
    char present_line[1000] = "";
    int cursor_position = strlen(present_line);
    char cursor_pointer = '_';
    char ch='1';
    FILE *fp = fopen("text_file", "w+");
    fscanf(fp, "%s", present_line);

    while(1){
        printf("%s%s%s%c", HOME, CLEAR_RIGHT, present_line, cursor_pointer);
        ch = getch();
        if(ch == 4) {
            fprintf(fp, "%s", present_line);
            break;
        }
        else if(ch == 8){
            if(cursor_position>0){
                present_line[--cursor_position] = '\0';
            }
        }
        else{
            present_line[cursor_position] = ch;
            present_line[++cursor_position] = '\0';
        }
        // else if(ch == 8)
    }

    // printf("Hello world\n");
    // sleep(3);
    // printf("%sHello newworld%s\n", PREV_LINE, CLEAR_RIGHT);
    return 0;
}