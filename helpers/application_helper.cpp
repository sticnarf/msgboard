#include "application_helper.hpp"
#include <cctype>

std::string ApplicationHelper::escapeString(const std::string &str) {
    std::string result;
    for(auto c : str) {
        switch (c) {
            case '&':  result.append("&amp;");       break;
            case '\"': result.append("&quot;");      break;
            case '\'': result.append("&apos;");      break;
            case '<':  result.append("&lt;");        break;
            case '>':  result.append("&gt;");        break;
            case '\n': result.append("<br>");        break;
            default:
                if(!std::iscntrl(c))
                    result.push_back(c);
                break;
        }
    }
    return result;
}
