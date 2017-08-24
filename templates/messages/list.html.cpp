#include "list.html.hpp"
std::string MessagesListHtml::render() {
std::string result;
result += R"DWeYGEWC(<!DOCTYPE HTML>
<html>
<head>
    <meta charset="utf-8">
    <title>Message board</title>
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
                )DWeYGEWC";
 for (auto message : messages) { 
result += R"5L8Ytj2U(
                <tr><td>
                <div class="author-name">)5L8Ytj2U";
result += fmt::format("{}", ApplicationHelper::escapeString(message->getAuthor()->getUsername()) );
result += R"AlMcJVC8(:</div>
                <p class="message-content">
                    )AlMcJVC8";
result += fmt::format("{}", ApplicationHelper::escapeString(message->getContent()) );
result += R"OyKn988N(
                </p>
                <small class="message-time text-right">)OyKn988N";
result += fmt::format("{}", message->getFriendlyCreatedAt() );
result += R"K9r504Hi(</small>
                </td></tr>
                )K9r504Hi";
 } 
result += R"vLuvmxEM(
            </table>
            )vLuvmxEM";
 if (currentUser) { 
result += R"7Q8MfUNt(
            <p>
                Hello, )7Q8MfUNt";
result += fmt::format("{}", ApplicationHelper::escapeString(currentUser->getUsername()) );
result += R"p3hK4dQE(!
                <a href="/logout">Logout</a>
            </p>
            <a href="/messages/new" class="btn btn-primary">New message</a>
            )p3hK4dQE";
 } else { 
result += R"LfUYElIt(
            <p>
                You are not logged in.
                <a href="/login">Login</a>
            </p>
            )LfUYElIt";
 } 
result += R"jXTuFMW2(
        </div>
    </div>
</div>
</body>
</html>)jXTuFMW2";
return result;
}

