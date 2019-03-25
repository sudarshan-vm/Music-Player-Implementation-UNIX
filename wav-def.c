#include"wav.h"

void readfile()
{
    int16_t *samples = NULL;
    
    wavread("sound.wav",&samples);
    printf("No. of channels: %d\n",header->num_channels);
    printf("Sample rate:     %d\n",header->sample_rate);
    printf("Bit rate:        %dkbps\n",header->byte_rate*8 / 1000);
    printf("Bits per sample: %d\n\n",header->bps);
    printf("Sample 0:        %d\n",samples[0]);
    printf("Sample 1:        %d\n",samples[1]);
   // Modify the header values & samples before writing the new file
    wavwrite("sound.wav",samples);
    free(header);
    free(samples);

}

void playAudio()
{


}

void wavread(char *file_name, int16_t **samples)
    {
        int fd;
        if (!file_name)
            errx(1, "Filename not specified");
        if ((fd = open(file_name, O_RDONLY)) < 1)
            errx(1, "Error opening file");
        if (!header)
            header = (WavHeader*)malloc(sizeof(WavHeader));
        if (read(fd, header, sizeof(WavHeader)) < sizeof(WavHeader))
            errx(1, "File broken: header");
        if (strncmp(header->chunk_id, "RIFF", 4) ||
            strncmp(header->format, "WAVE", 4))
            errx(1, "Not a wav file");
        if (header->audio_format != 1)
            errx(1, "Only PCM encoding supported");
        if (*samples) free(*samples);
        *samples = (int16_t*)malloc(header->datachunk_size);
        if (!*samples)
            errx(1, "Error allocating memory");
        if (read(fd, *samples, header->datachunk_size) < header->datachunk_size)
            errx(1, "File broken: samples");
        close(fd);
    }
    
   
void wavwrite(char *file_name, int16_t *samples)
    {
        int fd;
        if (!file_name)
            errx(1, "Filename not specified");
        if (!samples)
            errx(1, "Samples buffer not specified");
        if ((fd = creat(file_name, 0666)) < 1)
            errx(1, "Error creating file");
        if (write(fd, header, sizeof(WavHeader)) < sizeof(WavHeader))
            errx(1, "Error writing header");
        if (write(fd, samples, header->datachunk_size) < header->datachunk_size)
            errx(1, "Error writing samples");
        close(fd);
    }
    

