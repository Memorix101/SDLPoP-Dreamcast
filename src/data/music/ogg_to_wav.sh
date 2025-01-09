#!/bin/bash

# Directory containing OGG files (default to current directory if not specified)
INPUT_DIR=${1:-.}
OUTPUT_DIR=${2:-wav_output}

# Create the output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

echo "Converting OGG files from $INPUT_DIR to WAV format in $OUTPUT_DIR..."

# Loop through all .ogg files in the input directory
for file in "$INPUT_DIR"/*.ogg; do
    if [[ -f "$file" ]]; then
        # Extract the filename without the directory and extension
        filename=$(basename "$file" .ogg)
        
        # Construct the output file path with .wav extension
        output_file="$OUTPUT_DIR/$filename.wav"
        
        # Convert the OGG file to WAV format
        ffmpeg -i "$file" -vn -c:a pcm_s16le -ar 44100 -ac 2 "$output_file"
        
        if [[ $? -eq 0 ]]; then
            echo "Converted: $file -> $output_file"
        else
            echo "Failed to convert: $file"
        fi
    else
        echo "No OGG files found in $INPUT_DIR."
    fi
done

echo "Conversion complete."
