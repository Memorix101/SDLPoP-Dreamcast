#include <stdio.h>
#include <stdlib.h>
#define STB_VORBIS_HEADER_ONLY
#include "stb_vorbis_ac.c"

/*
int main() {
    const char* filename = "/rd/won.ogg";
 // Open the Ogg Vorbis file
    int error = 0;
    stb_vorbis* decoder = stb_vorbis_open_filename(filename, &error, NULL);
    if (!decoder) {
        fprintf(stderr, "Failed to open file: %s (error=%d)\n", filename, error);
        return 1;
    }

    // Print audio information
    stb_vorbis_info info = stb_vorbis_get_info(decoder);
    printf("Sample rate: %d Hz\n", info.sample_rate);
    printf("Channels: %d\n", info.channels);

    // Decode the audio data
    int channels = info.channels;
    int sample_rate = info.sample_rate;
    short* output = NULL;
    int samples_decoded = 0;
    int total_samples = 0;

    // Decode samples in chunks
    while ((samples_decoded = stb_vorbis_get_frame_short_interleaved(decoder, channels, NULL, 0)) > 0) {
        total_samples += samples_decoded;
        printf("Decoded %d samples\n", samples_decoded);
    }

    printf("Total samples decoded: %d\n", total_samples);

    // Close the decoder
    stb_vorbis_close(decoder);

    return 0;
}
*/

void* custom_malloc(size_t size, void* user) {
    return malloc(size);
}

void custom_free(void* ptr, void* user) {
    free(ptr);
}

int main() {
    const char* filename = "/cd/data/music/ogg/won.ogg"; // Replace with your file path
    stb_vorbis_alloc alloc;
    alloc.alloc_buffer = NULL;
    alloc.alloc_buffer_length_in_bytes = 0;

    // Open file with custom allocator
    int error = 0;
    stb_vorbis* decoder = stb_vorbis_open_filename(filename, NULL, NULL);
    if (!decoder) {
        fprintf(stderr, "Failed to open file: %s (error=%d)\n", filename, error);
        return 1;
    }

    // Print audio information
    stb_vorbis_info info = stb_vorbis_get_info(decoder);
    printf("Sample rate: %d Hz\n", info.sample_rate);
    printf("Channels: %d\n", info.channels);

    // Close the decoder
    stb_vorbis_close(decoder);
    return 0;
}