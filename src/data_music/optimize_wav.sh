#!/bin/bash

# Check if ffmpeg is installed
if ! command -v ffmpeg &> /dev/null; then
    echo "ffmpeg could not be found. Please install ffmpeg first."
    exit 1
fi

# Directory containing WAV files
INPUT_DIR="./"
OUTPUT_DIR="./optimized"

# Create output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Optimization parameters
SAMPLE_RATE=8000  # Standard rate for compatibility
BIT_DEPTH="s16le"     # Signed 16-bit PCM (widely supported)
CHANNELS=1          # Convert to mono

# Process each WAV file
for file in "$INPUT_DIR"/*.wav; do
    if [[ -f "$file" ]]; then
        BASENAME=$(basename "$file")
        OUTPUT_FILE="$OUTPUT_DIR/$BASENAME"

        echo "Optimizing $file -> $OUTPUT_FILE"

        ffmpeg -i "$file" -ar $SAMPLE_RATE -acodec pcm_$BIT_DEPTH -ac $CHANNELS "$OUTPUT_FILE"
    fi
done

echo "Optimization completed. Files saved in $OUTPUT_DIR"