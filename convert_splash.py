#!/usr/bin/env python3
"""
Convert jolteon_splash.png to C array in RGB565 format
"""

from PIL import Image
import os

def rgb888_to_rgb565(r, g, b):
    """Convert RGB888 to RGB565"""
    r = (r >> 3) & 0x1F
    g = (g >> 2) & 0x3F  
    b = (b >> 3) & 0x1F
    return (r << 11) | (g << 5) | b

def convert_image_to_c_array(image_path, output_path):
    """Convert PNG image to C array"""
    
    # Open and convert image
    img = Image.open(image_path)
    
    # Convert RGBA to RGB if needed
    if img.mode == 'RGBA':
        # Create white background
        background = Image.new('RGB', img.size, (255, 255, 255))
        background.paste(img, mask=img.split()[-1])  # Use alpha channel as mask
        img = background
    elif img.mode != 'RGB':
        img = img.convert('RGB')
    
    width, height = img.size
    print(f"Converting {image_path}: {width}x{height}")
    
    # Get pixel data
    pixels = list(img.getdata())
    
    # Convert to RGB565
    rgb565_data = []
    for r, g, b in pixels:
        rgb565 = rgb888_to_rgb565(r, g, b)
        rgb565_data.append(rgb565)
    
    # Generate C array
    with open(output_path, 'w') as f:
        f.write(f"// Auto-generated from {os.path.basename(image_path)}\n")
        f.write(f"// Image dimensions: {width}x{height}\n\n")
        f.write(f"#ifndef JOLTEON_SPLASH_H\n")
        f.write(f"#define JOLTEON_SPLASH_H\n\n")
        f.write(f"#include <Arduino.h>\n\n")
        f.write(f"#define JOLTEON_SPLASH_WIDTH {width}\n")
        f.write(f"#define JOLTEON_SPLASH_HEIGHT {height}\n\n")
        f.write(f"// RGB565 format splash screen data\n")
        f.write(f"static const uint16_t jolteon_splash_data[{len(rgb565_data)}] PROGMEM = {{\n")
        
        # Write data in rows of 16 values for readability
        for i in range(0, len(rgb565_data), 16):
            row = rgb565_data[i:i+16]
            f.write("    ")
            f.write(", ".join([f"0x{val:04X}" for val in row]))
            if i + 16 < len(rgb565_data):
                f.write(",")
            f.write("\n")
        
        f.write("};\n\n")
        f.write(f"#endif // JOLTEON_SPLASH_H\n")
    
    print(f"Generated {output_path} with {len(rgb565_data)} pixels")

if __name__ == "__main__":
    convert_image_to_c_array("logo/jolteon_splash.png", "src/jolteon_splash.h")
