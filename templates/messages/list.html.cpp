#include "list.html.hpp"
std::string MessagesListHtml::render() {
std::string result;
result += R"ialKG5iX(<!DOCTYPE HTML>
<html>
<head>
    <link rel="stylesheet" href="/assets/style.css">
    <link rel="stylesheet" href="https://cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
    <script src="https://cdn.bootcss.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
</head>
<body>
<div class="container">
    <div class="row">
        <div class="col-xs-12 col-md-4 col-md-offset-4">
            <h1>Message board</h1>
            <table class="table table-bordered table-striped main-table">
                )ialKG5iX";
 for (auto message : messages) { 
result += R"xQepISKl(
                <tr><td>
                <div class="author-name">)xQepISKl";
result += fmt::format("{}", message->getAuthor()->getUsername() );
result += R"51HRI9Xc(:</div>
                <div class="message-content">
                    )51HRI9Xc";
result += fmt::format("{}", message->getContent() );
result += R"gGGvsmqE(
                </div>
                <small class="message-time text-right">)gGGvsmqE";
result += fmt::format("{}", message->getFriendlyCreatedAt() );
result += R"IzQAl2Ir(</small>
                </td></tr>
                )IzQAl2Ir";
 } 
result += R"a6ujb3j9(
            </table>
            )a6ujb3j9";
 if (currentUser) { 
result += R"AEIU0xuJ(
            <p>
                Hello, )AEIU0xuJ";
result += fmt::format("{}", currentUser->getUsername() );
result += R"7x3lDqVu(!
                <a href="/logout">Logout</a>
            </p>
            <a href="/messages/new" class="btn btn-primary">New message</a>
            )7x3lDqVu";
 } else { 
result += R"CpEPRLX9(
            <p>
                You are not logged in.
                <a href="/login">Login</a>
            </p>
            )CpEPRLX9";
 } 
result += R"N2BxU28F(
        </div>
    </div>
</div>
</body>
</html>)N2BxU28F";
return result;
}

