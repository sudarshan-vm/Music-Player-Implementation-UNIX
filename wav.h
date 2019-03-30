#ifndef WAV_H
#define WAV_H
//#include<bits/stdc++.h>

#include <iostream>
#include <inttypes.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <dirent.h> 
#include <malloc.h>
#include <cstring>
#include <fstream>
#include <signal.h>	
using namespace std;

struct Node 
{ 
    string file_name; 
    struct Node *next; 
    struct Node *prev; 
}; 

typedef struct 
	{
        char     chunk_id[4];
        uint32_t chunk_size;
        char     format[4];
        char     fmtchunk_id[4];
        uint32_t fmtchunk_size;
        uint16_t audio_format;
        uint16_t num_channels;
        uint32_t sample_rate;
        uint32_t byte_rate;
        uint16_t block_align;
        uint16_t bps;
        char     datachunk_id[4];
        uint32_t datachunk_size;
    }WavHeader;

 //WavHeader *header;

void insertEnd(struct Node** start, string file) ;

void printList(struct Node* node) ;

void wavread(char const*file_name, int16_t **samples);
 
void wavwrite(char const*file_name, int16_t *samples);

void readfile(const char* file);

int playAudio(string file);


#endif
