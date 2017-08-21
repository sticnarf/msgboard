#ifndef MSGBOARD_LIST_HTML_HPP
#define MSGBOARD_LIST_HTML_HPP

#include <hane/ecp/template.hpp>
#include <vector>

class UsersNewHtml : Template {
public:
    std::string render() override;
};

#endif
