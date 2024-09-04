#include <chrono>
#include <random>
#include <string>
#include <vector>

std::vector<std::string> rand_str() {
    const std::vector<char> chars = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        ',', '<', '>', '.', '?', '/', '"', ';', ':', '+', '=', '-', '_',
        ')', '(', '*', '&', '^', '%', '$', '#', '@', '!', '~', '`', '\'',
        '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    std::random_device rd;
    std::mt19937 gen(
        rd() ^
        static_cast<unsigned>(
            std::chrono::system_clock::now().time_since_epoch().count()));

    std::uniform_int_distribution<> t_dist(1, 25);
    std::uniform_int_distribution<> length_dist(1, 25);
    std::uniform_int_distribution<> char_dist(0, chars.size() - 1);

    int t = t_dist(gen);

    std::vector<std::string> random_strings;

    for (int i = 0; i < t; ++i) {
        int length = length_dist(gen);
        std::string random_string;

        for (int j = 0; j < length; ++j) {
            random_string += chars[char_dist(gen)];
        }

        random_strings.push_back(random_string);
    }

    return random_strings;
}
