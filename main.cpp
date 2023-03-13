#include <iostream>
#include <string>
#include <vector>

std::vector<int> make_lps(const std::string& pattern)
{
    std::vector<int> lps = {0, 0, 0, 1, 2, 1};
    return lps;
}

int kmp(const std::string& text, const std::string& pattern)
{
    std::vector<int> lps = make_lps(pattern);

    int i = 0; // indeks u text

    int j = 0; // indeks u pattern

    while (i < text.size() && j < pattern.size())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j-1];
            }
        }
    }

    if (j == pattern.size())
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    std::string pattern = "ABCABA";

    std::string text = "AABCABCABABBA";

    std::cout << kmp(text, pattern);

    return 0;
}