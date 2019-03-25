#include"wav.h"

int main()
{
		int ch;
		
		printf("\nEnter a choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("\nReading the audio-file...\n");
					readfile();
					break;
			case 2: printf("\nPlaying audio-file...\n");
					playAudio();
					break;
			default: printf("\nInvalid input.\n");
					break;		
		}
	return 0;
}

