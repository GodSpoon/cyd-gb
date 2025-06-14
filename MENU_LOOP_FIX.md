# Menu Loop Fix - Performance Optimization

## Problem Identified
The menu was continuously redrawing every frame, causing a "looping" effect that made ROM selection difficult. The terminal output showed constant TFT drawing commands, indicating excessive screen updates.

## Root Cause
- Menu redraw logic was running every frame without conditions
- No throttling mechanism for menu updates
- Instructions and hints were being redrawn constantly
- ROM list was being cleared and redrawn every update cycle

## Solution Implemented

### 1. **Conditional Redrawing**
```cpp
// Only redraw when selection or scroll changes
static int last_selected_index = -1;
static int last_scroll_offset = -1;
static bool need_redraw = true;

if (selected_index != last_selected_index || scroll_offset != last_scroll_offset || need_redraw) {
    // Redraw ROM list only when needed
}
```

### 2. **Update Throttling**
```cpp
const unsigned long UPDATE_THROTTLE_MS = 50; // 20 FPS limit
static unsigned long last_update_time = 0;

if (millis() - last_update_time < UPDATE_THROTTLE_MS) {
    return Result<void>::ok(); // Skip update
}
```

### 3. **Smart Instruction Updates**
```cpp
// Only redraw instructions when hint state changes
static bool instructions_drawn = false;
static bool last_hint_state = false;

if (!instructions_drawn || (show_selection_hint != last_hint_state) || hint_was_showing) {
    // Redraw instructions area
}
```

### 4. **Static Error Message Drawing**
```cpp
// Draw "No ROMs found" message only once
static bool no_roms_drawn = false;
if (!no_roms_drawn) {
    // Draw error message once
    no_roms_drawn = true;
}
```

## Performance Improvements

### Before Fix:
- Menu updated every frame (~60 FPS)
- Constant screen clearing and redrawing
- Excessive TFT commands in terminal output
- Difficult to select ROMs due to constant updates

### After Fix:
- Menu updates throttled to 20 FPS maximum
- Conditional redrawing based on actual changes
- Smooth selection experience
- Minimal TFT commands in terminal output

## Benefits

1. **Improved Responsiveness**: ROM selection now works smoothly
2. **Better Performance**: Reduced CPU and display overhead
3. **Lower Power Consumption**: Less frequent display updates
4. **Cleaner Debug Output**: Terminal shows only necessary TFT commands
5. **Better User Experience**: Stable menu without visual jitter

## Technical Details

### Update Conditions
The menu now only redraws when:
- Selection index changes (user touches different ROM)
- Scroll offset changes (user scrolls up/down)
- Hint state changes (selection hint appears/disappears)
- Initial display setup

### Frame Rate Control
- **Menu Updates**: Limited to 20 FPS (50ms intervals)
- **Touch Processing**: Still responsive with 200ms debounce
- **Hint Timeout**: 2-second selection hint duration

### Memory Efficiency
- Static variables track state changes
- Minimal memory overhead for optimization
- No additional heap allocations

## Testing Results

After the fix:
- ROM selection works smoothly on first touch
- No more continuous redrawing in terminal output
- Selection hints appear and disappear cleanly
- Scrolling works without visual artifacts
- Overall menu feels responsive and stable

The menu system now provides the professional user experience intended while maintaining all the enhanced features like alphabetical sorting, selection hints, and visual feedback.
