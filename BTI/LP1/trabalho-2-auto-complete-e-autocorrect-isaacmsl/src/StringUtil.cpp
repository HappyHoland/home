#include "StringUtil.hpp"

std::vector<std::string> StringUtil::split_str(std::string &str, char delimiter, bool trim) {
    std::vector<std::string> result{};
    std::string substring{""};
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == delimiter)
        {
            if (trim)
            {
                trim_str(substring);
            }
            result.push_back(substring);
            substring = "";
        }
        else if (str[i] != '\r')
        { // evita adicionar \r
            substring += str[i];
        }
    }
    if (substring.length() > 0)
    {
        if (trim)
        {
            trim_str(substring);
        }
        result.push_back(substring);
    }
    return result;
}

std::string StringUtil::join_str(std::vector<std::string> &strs, char c) {
    std::string result{""};
    result += strs[0];
    for (int i = 1; i < (int)strs.size(); i++)
    {
        result += c + strs[i];
    }
    return result;
}


void StringUtil::trim_left_str(std::string &str) {
    while (
        (
            str.find('\n') == 0 ||
            str.find('\r') == 0 ||
            str.find(' ') == 0) &&
        str.length() > 0
    ) {
        str.erase(0, 1);
    }
}

void StringUtil::trim_right_str(std::string &str) {
    int last_index = str.size() - 1;
    while (
        (
            str.find('\n') == last_index ||
            str.find('\r') == last_index ||
            str.find(' ') == last_index) &&
        str.length() > 0
    ) {
        str.erase(last_index, 1);
        --last_index;
    }
}

void StringUtil::trim_str(std::string &str) {
    trim_left_str(str);
    trim_right_str(str);
}
