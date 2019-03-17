#define V_TEXT_HEIGHT 25
#define V_TEXT_WIDTH 80

unsigned short* _vmemLocation = (unsigned short*) 0xb8000;
unsigned short char_bg = 0x0f00;
int _vCurrentLine = 0;

void set_char(char ch, int location)
{
	_vmemLocation[location] = char_bg | ch;
}

void print_string(char* string)
{
	for (int i = 0; string[i] != '\0'; i++)
		set_char(string[i], (V_TEXT_WIDTH * _vCurrentLine) + i);
	
	_vCurrentLine++;
}

void clearScreen()
{
	for (int i = 0; i < V_TEXT_WIDTH; ++i)
		for (int j = 0; j < V_TEXT_HEIGHT; ++j)
			_vmemLocation[i + j * V_TEXT_WIDTH] = char_bg;
}

void kmain()
{
	clearScreen();
	print_string("Hello world!!!!"); // Print hello world to terminal
	print_string("What's good");

	while (1); // Kill thread
}
