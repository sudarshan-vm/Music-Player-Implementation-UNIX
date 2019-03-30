#include "wav.h"

int main(int argc ,  char *argv[]) 
{ 
    int len,rv;
    char file_name[100];
    int choice;
    struct Node* start = NULL;
    struct Node* temp1=NULL;
    temp1=start;
    if(argc!=2)
    {
        printf("Directory name is not specified !!");
        exit(EXIT_FAILURE);
    }
    struct dirent *de;  
  
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir(argv[1]); 
  
    if (dr == NULL)  // opendir returns NULL if couldn't open directory 
    { 
        printf("Could not open current directory" ); 
        return 0; 
    } 
  
  	cout << "Music files in the selected directory : \n";
    while ((de = readdir(dr)) != NULL) 
    {

        len = strlen(de->d_name);
        if (len > 4                     &&
            de->d_name[len - 4] == '.' &&
            de->d_name[len - 3] == 'w' &&
            de->d_name[len - 2] == 'a' &&
            de->d_name[len - 1] == 'v')
        {
            printf ("\t%s\n", de->d_name);
            insertEnd(&start,de->d_name);
        }   
    }

   
    while(1)
    {
    	 cout << "\n1: Read/write audio 2: Play audio  ";
    	 cout << "Enter your choice : ";
        cin >> choice;
        switch(choice)
        {
            case 1: cout << "Enter file name : ";
                    cin >> file_name;
                    readfile(file_name);
                    cout << "\nNew audio file is written sound_new.wav" << endl;
                    break;

            case 2: cout << "Enter file name : ";
                    cin >> file_name;
                    rv = playAudio(file_name);
                    break;

          
            default : exit(EXIT_SUCCESS);
        }
   }
    closedir(dr);     
    return 0; 
} 
