/*
 * (c) daviapps 2019
 *
 * White LED Digital Clock
 *       Prototype
 *
 * description: This is a prototype to make easy to work with the display content
 * author: github.com/daviinacio
 * site: daviinacio.com.br
 * date: 12/09/2019
 *
 */

// To run this on terminal type: ./run

// Abstraction from the real code
#define DISP_LENGTH 4

#include <iostream>
#include <windows.h>
#include <math.h>

/*
// Seven Segments Display Abstraction

|--- a ---|
|         |
f         b
|         |
|--- g ---|
|         |
e         c
|         |
|--- d ---| (.)

0b [a], [b], [c], [d], [e], [f], [g], [.]
    0    1    2    3    4    5    6    7

*/

// ASCII map for seven Segments
// TODO: This will will replaced for binary content
byte seven_seg_asciis [((int) 'Z' - '*') + 1] = {
    '*',
    // Especial characters
    0x00, 0x00,
    '-',
    // Especial characters
    0x00, 0x00,

    // Numbers
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    
    // Especial characters
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    // Alfabetic characters
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};
int seven_seg_ascii_init = '*'; // First mapped ascci position

// Content
byte disp_content [DISP_LENGTH];
// Cursor
int disp_content_cursor = 0;

// Debug
void debug_disp_content(){
    //printf("disp_content_cursor = %i\n", disp_content_cursor);
    for(int i = 0; i < DISP_LENGTH; i++)
        printf("[%c]", disp_content[i]);
    
    printf("\n\n");
}

// Prototype
void disp_setCursor(int col){
    disp_content_cursor = col % DISP_LENGTH;
}

void disp_clear(){
    for(int i = 0; i < DISP_LENGTH; i++)
        disp_content[i] = 0x00;
}

void disp_print(char c){
    disp_content[disp_content_cursor] = seven_seg_asciis[((int) c) - seven_seg_ascii_init]; //content[i];
    disp_content_cursor++;
}

void disp_print(char content []){
    for(int i = 0; i < strlen(content) && disp_content_cursor < DISP_LENGTH; i++)
        disp_print(content[i]);
}

void disp_print(int num){
    char _num [11] = "";

    itoa(num, _num, 10);
    
    disp_print(_num);
}

// Print on the end
void disp_printEnd(char content []){
    disp_setCursor(DISP_LENGTH - strlen(content));
    disp_print(content);
}

void disp_printEnd(char c){ 
    disp_setCursor(DISP_LENGTH - 1);
    disp_print(c);
}

void disp_printEnd(int num){
    char _num [11] = "";
    itoa(num, _num, 10);

    disp_printEnd(_num);
}


int main(){
    printf("Print string\n");
    disp_clear();
    disp_setCursor(0);
    disp_print((char*) "DAVI INACIO");

    debug_disp_content();

    printf("Print per character\n");
    disp_clear();
    disp_setCursor(0);
    
    disp_print('I');
    disp_print('V');
    disp_print('A');
    disp_print('D');

    debug_disp_content();

    printf("Print integer\n");
    disp_clear();
    disp_setCursor(0);
    disp_print(42);

    debug_disp_content();

    printf("Print negative integer\n");
    disp_clear();
    disp_setCursor(0);
    disp_print(-42);

    debug_disp_content();

    printf("******* PRINT ON THE END *******\n\n");

    printf("Print string on the end\n");
    disp_clear();
    disp_printEnd((char*) "DI");

    debug_disp_content();

    printf("Print character on the end\n");
    disp_clear();
    disp_printEnd('D');

    debug_disp_content();

    printf("Print integer on the end\n");
    disp_clear();
    disp_printEnd(42);

    debug_disp_content();

    printf("Print negative integer on the end\n");
    disp_clear();
    disp_printEnd(-42);

    debug_disp_content();

    printf("Print diferent Types\n");
    disp_clear();
    disp_setCursor(0);
    disp_print((char*)"HUMD");

    disp_printEnd(-42);
    
    debug_disp_content();

    system("PAUSE");
}
