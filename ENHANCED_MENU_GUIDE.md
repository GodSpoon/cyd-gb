# Enhanced ROM Selection Menu - User Guide

## Overview

The CYD Game Boy emulator now features a completely revamped ROM selection menu with enhanced user experience, better visual feedback, and more intuitive controls.

## Key Features

### 🎮 **Intuitive Touch Interface**
- **Single Tap**: Select a ROM (highlighted with yellow text and blue background)
- **Double Tap**: Launch the selected ROM
- **Visual Feedback**: Selected ROMs show a clear selection hint for 2 seconds
- **Improved Debouncing**: Reduced from 300ms to 200ms for better responsiveness

### 📱 **Professional Visual Design**
- **Centered Layout**: All text properly centered for better visual balance
- **Color Coding**: 
  - Cyan title for "CYD Game Boy"
  - Purple subtitle for instructions
  - Yellow highlighting for selected ROMs
  - Green scroll indicators
  - Gray informational text
- **Clean ROM Display**: .gb extension removed for cleaner look
- **Enhanced Selection**: Blue background with border for selected items

### 📋 **Smart ROM Management**
- **Alphabetical Sorting**: ROMs automatically sorted for easy navigation
- **Intelligent Truncation**: Long filenames shortened with "..." indicator
- **ROM Counter**: Shows total number of ROMs found
- **Extension Handling**: Displays clean names without .gb extension

### 🔄 **Advanced Scrolling**
- **Page Indicators**: Shows "Page X/Y" when scrolling is needed
- **Large Touch Areas**: Bigger scroll buttons for easier use
- **Auto-scroll**: Automatically scrolls to keep selected ROM visible
- **Visual Scroll Indicators**: Clear up/down arrows

### ⚡ **Enhanced Loading Experience**
- **Animated Progress Bar**: 10-step loading animation
- **Detailed Status**: Shows ROM file name and initialization steps
- **Success Confirmation**: Clear feedback when ROM loads successfully
- **Error Handling**: Comprehensive error messages with recovery options

### 🎯 **Improved Error Handling**
- **Visual Error Background**: Dark red background for error messages
- **Specific Instructions**: Clear guidance for different error types
- **File Validation**: Checks ROM file existence before loading
- **Graceful Cleanup**: Proper cleanup on loading failures

## Usage Instructions

### Starting the Emulator
1. **Power On**: Device shows splash screen for 2 seconds
2. **Auto-Menu**: Automatically transitions to ROM selection menu

### Selecting and Playing ROMs
1. **Browse**: Touch any ROM to select it (yellow highlight appears)
2. **Selection Hint**: Yellow text shows "ROM selected - touch again to launch!"
3. **Launch**: Touch the selected ROM again to start emulation
4. **Loading**: Watch the progress bar as the ROM loads
5. **Play**: Game starts automatically when loading completes

### Navigation Controls
- **Scroll Up**: Touch the "^" arrow at top-right
- **Scroll Down**: Touch the "v" arrow at bottom-right  
- **Page Info**: Check "Page X/Y" indicator to see position
- **Auto-scroll**: Selected items automatically stay visible

### During Gameplay
- **Return to Menu**: Hold touch anywhere for 2 seconds
- **Progress Bar**: Yellow progress bar shows hold duration
- **Automatic Return**: Returns to menu when progress completes

### Error Recovery
1. **Read Error**: Check the detailed error message
2. **Follow Instructions**: Follow the suggested solution
3. **Touch to Retry**: Touch screen to attempt hardware recovery
4. **Power Cycle**: If retry fails, restart the device

## Technical Improvements

### Memory Efficiency
- **ROM Streaming**: ROMs read from SD card as needed (not loaded into RAM)
- **Efficient Rendering**: Optimized drawing routines for smooth UI
- **Smart Caching**: Intelligent memory management for large ROM collections

### Performance Optimizations
- **Reduced Debounce**: Faster touch response (200ms vs 300ms)
- **Optimized Scrolling**: Smooth scroll experience with larger touch areas
- **Efficient Redraw**: Only redraws changed portions of the screen

### Compatibility
- **All Game Boy ROMs**: Supports any .gb ROM file
- **Large Collections**: Handles hundreds of ROMs with smooth scrolling
- **SD Card Support**: Works with any FAT32 formatted SD card

## File Organization

### ROM Storage
- Place .gb ROM files in the root directory of your SD card
- ROMs will be automatically sorted alphabetically
- Subdirectories are not currently supported

### Supported File Types
- **.gb**: Original Game Boy ROMs
- **File Size**: Up to 8MB ROMs supported via streaming
- **Format**: Standard Game Boy ROM format

## Troubleshooting

### No ROMs Found
- Ensure .gb files are in SD card root directory
- Check SD card is FAT32 formatted
- Verify SD card is properly inserted
- Restart device after adding ROMs

### Touch Not Responsive
- Clean the screen surface
- Ensure proper calibration
- Try holding touches longer
- Check for hardware issues in error screen

### ROM Won't Load
- Verify ROM file is not corrupted
- Check file has .gb extension
- Ensure sufficient storage space
- Try different ROM file

## Development Notes

The enhanced menu system is built on top of the EmulatorContext state machine, providing:
- Clean separation of concerns
- Robust error handling
- Efficient memory usage
- Modern C++ practices
- Hardware abstraction

This implementation replaces the legacy menu.cpp system with a more integrated and sophisticated approach.
