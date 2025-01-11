#!/bin/bash

# Directory containing OGG files (default to current directory if not specified)
INPUT_DIR=${1:-.}
OUTPUT_DIR=${2:-compressed}

# Desired audio bitrate
BITRATE=${3:-64k}

# Create the output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

echo "Compressing OGG files from $INPUT_DIR to $OUTPUT_DIR with bitrate $BITRATE..."

# Loop through all .ogg files in the input directory
for file in "$INPUT_DIR"/*.ogg; do
    if [[ -f "$file" ]]; then
        # Extract the filename without the directory
        filename=$(basename "$file")
        
        # Construct the output file path
        output_file="$OUTPUT_DIR/$filename"
        
        # Re-encode the file with the specified bitrate
        ffmpeg -i "$file" -c:a libvorbis -b:a "$BITRATE" "$output_file"
        
        if [[ $? -eq 0 ]]; then
            echo "Compressed: $file -> $output_file"
        else
            echo "Failed to compress: $file"
        fi
    else
        echo "No OGG files found in $INPUT_DIR."
    fi
done

echo "Compression complete."
