#include <stdio.h>
#include "../General_Functions/generalfunctions.h"
#include "../Appearance_Functions/appearance.h"

int main()
{
	char input;
	while(1)
	{
		printMainMenu();
		scanf("%hhd",&input);
		clearBuffer();
		switch(input)
		{
			case 1: chooseMode(); break;
			case 2: aboutMenu(); break;
			case 3: return 0;
		}
	}
}

