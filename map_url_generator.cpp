#include "map_url_generator.h"

// Function to generate a Google Maps URL based on latitude and longitude
std::string generateMapURL(double latitude, double longitude) {
    // Generate a Google Maps URL with the provided coordinates
    return "https://www.google.com/maps?q=" + std::to_string(latitude) + "," + std::to_string(longitude);
}
