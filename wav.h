#include <inttypes.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <err.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

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

    WavHeader *header;


void wavread(char *file_name, int16_t **samples);
 
void wavwrite(char *file_name, int16_t *samples);

void readfile();

void playAudio();
