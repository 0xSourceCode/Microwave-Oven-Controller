#define CLEAR_SCREEN 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define CURSOR_ON 0x0E
#define CURSOR_OFF 0x0C
#define DISPLAY_ON 0x0F
#define MODE_8BITS 0x38
#define DATA_PORT 'B'
#define CTRL_PORT 'A'
#define E 5
#define RS 6
#define RW 7

void LCD_vInit(void);
void LCD_cmd(char cmd);
void LCD_sendChar(char chr);
void LCD_sendString(char *string);
void LCD_clearScreen(void);
void LCD_moveCursor(char row, char col);
