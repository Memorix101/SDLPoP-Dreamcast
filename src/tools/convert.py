from PIL import Image

def convert_icon_to_vmu_format(input_bmp, output_header):
    img = Image.open(input_bmp).convert("P")  # Ensure it's a palette-based image

    # Get the palette (16 colors, 48 bytes)
    palette = img.getpalette()[:48]
    if len(palette) < 48:
        palette += [0] * (48 - len(palette))  # Pad if less than 16 colors

    # Get pixel data
    pixel_data = list(img.getdata())
    pixel_bytes = []
    for i in range(0, len(pixel_data), 2):
        pixel_bytes.append((pixel_data[i] << 4) | (pixel_data[i + 1]))

    # Write the data to a header file
    with open(output_header, "w") as f:
        f.write("uint8_t icon_palette[48] = {\n")
        f.write(", ".join(f"0x{color:02X}" for color in palette))
        f.write("\n};\n\n")

        f.write("uint8_t icon_data[32 * 32 / 2] = {\n")
        f.write(", ".join(f"0x{byte:02X}" for byte in pixel_bytes))
        f.write("\n};\n")

    print(f"Converted {input_bmp} to {output_header}")

# Example usage
convert_icon_to_vmu_format("savegame.bmp", "vmu_icon.h")
