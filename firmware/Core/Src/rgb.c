#include "rgb.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// @brief Converts HEX color code value to RGB values.
/// @param hex_color_code
/// - Arg 0: The Hex color code to be parsed (string)
/// @return 0 on success, > 0 on error
uint8_t RGB_convert_hex_to_rgb(char *hex_color_code, LED_RGB_t *rgb_result) {

    // The string, hex_color_code, should be in the form of #FFAABB

    // Check if the string is empty
    if (hex_color_code == NULL || hex_color_code[0] == '\0'){

        // Empty or NULL string, return error
        return 1;
    }

    // Check if the string starts with "#"

    //Finding the "#" character in the hex_color_code string
    const char *sync_char = strchr(hex_color_code,'#');

    if(!sync_char || hex_color_code[0] != '#'){
        // Error: Missing sync_char and incorrect index of the sync_char
        return 2;
    }

    // Check if the string contains all RGB values ie check length of the char passed
    const uint8_t hex_code_length = strlen(hex_color_code);

    if(hex_code_length != 7){
        // Error: Invalide length- missing hex values for the RGB
        return 3;
    }

    // Parse the string and pass the values into the struct holding the RBG Values

    // Extracting the string RGB values from hex_color_code
    char red[3] = { hex_color_code[1], hex_color_code[2], '\0' };
    char green[3] = { hex_color_code[3], hex_color_code[4], '\0' };
    char blue[3] = { hex_color_code[5], hex_color_code[6], '\0' };

    // Converting the string values into decimals and passing them into the struct

    char *endptr;
    rgb_result->RGB_red = (uint8_t) strtol(red,&endptr,10);
    rgb_result->RGB_green = (uint8_t) strtol(green,&endptr,10);
    rgb_result->RGB_blue = (uint8_t) strtol(blue,&endptr,10);

    return 0;
}