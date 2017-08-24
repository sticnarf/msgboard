#include "list.html.hpp"
std::string MessagesListHtml::render() {
std::string result;
result += R"opwKlUOh(<!DOCTYPE HTML>
<html>
<head>
    <meta charset="utf-8">
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
                )opwKlUOh";
 for (auto message : messages) { 
result += R"ozs9YcUd(
                <tr><td>
                <div class="author-name">)ozs9YcUd";
result += fmt::format("{}", message->getAuthor()->getUsername() );
result += R"TCBGTjbT(:</div>
                <p class="message-content">
                    )TCBGTjbT";
result += fmt::format("{}", message->getContent() );
result += R"JqIDMg2e(
                </p>
                <small class="message-time text-right">)JqIDMg2e";
result += fmt::format("{}", message->getFriendlyCreatedAt() );
result += R"3fSSNyYm(</small>
                </td></tr>
                )3fSSNyYm";
 } 
result += R"yc8AhRjR(
            </table>
            )yc8AhRjR";
 if (currentUser) { 
result += R"xmr3OHiZ(
            <p>
                Hello, )xmr3OHiZ";
result += fmt::format("{}", currentUser->getUsername() );
result += R"mYaFhBuD(!
                <a href="/logout">Logout</a>
            </p>
            <a href="/messages/new" class="btn btn-primary">New message</a>
            )mYaFhBuD";
 } else { 
result += R"bGh2wHyn(
            <p>
                You are not logged in.
                <a href="/login">Login</a>
            </p>
            )bGh2wHyn";
 } 
result += R"fEVHh0xe(
        </div>
    </div>
</div>
</body>
</html>)fEVHh0xe";
return result;
}

