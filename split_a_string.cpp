#include <iostream>
#include <string>
#include <vector>

struct TokenPosition
{
    size_t start;
    size_t end;
};

static std::vector<TokenPosition>
SplitString(const std::string& input_string, const std::string& delimiters)
{
    std::vector<TokenPosition> tokens;
    size_t start = 0, end = input_string.find_first_of(delimiters);

    while (end != std::string::npos)
    {
        if (end > start)
        {
            tokens.push_back({ start, end });
        }
        
        start = end + 1;
        end = input_string.find_first_of(delimiters, start);
    }

    if (start < input_string.length())
    {
        tokens.push_back({ start, input_string.length() });
    }

    return tokens;
}

int main()
{
    std::string input, delimiters;
    std::cout << "Enter the string: ";
    std::getline(std::cin, input);
    std::cout << "Enter the delimiter characters: ";
    std::getline(std::cin, delimiters);

    auto tokens = SplitString(input, delimiters);

    for (const auto& tokenPos : tokens)
    {
        std::cout << input.substr(tokenPos.start, tokenPos.end - tokenPos.start) << std::endl;
    }

    return 0;
}
