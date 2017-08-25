#include "list.html.hpp"
std::string MessagesListHtml::render() {
std::string result;
result += R"OVcw1Hgc(<!DOCTYPE HTML>
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
                )OVcw1Hgc";
 for (auto message : messages) { 
result += R"szTcSuEt(
                <tr><td>
                <div class="author-name">)szTcSuEt";
result += fmt::format("{}", ApplicationHelper::escapeString(message->getAuthor()->getUsername()) );
result += R"fhT2A9Fg(:</div>
                <p class="message-content">
                    )fhT2A9Fg";
result += fmt::format("{}", ApplicationHelper::escapeString(message->getContent()) );
result += R"6VSnVm8K(
                </p>
                <small class="message-time text-right">)6VSnVm8K";
result += fmt::format("{}", message->getFriendlyCreatedAt() );
result += R"zCsrx1eg(</small>
                </td></tr>
                )zCsrx1eg";
 } 
result += R"09qz1w5Q(
            </table>
            )09qz1w5Q";
 if (currentUser) { 
result += R"POZPMDhA(
            <p>
                Hello, )POZPMDhA";
result += fmt::format("{}", ApplicationHelper::escapeString(currentUser->getUsername()) );
result += R"q5JYH5yr(!
                <a href="/logout">Logout</a>
            </p>
            <a href="/messages/new" class="btn btn-primary">New message</a>
            )q5JYH5yr";
 } else { 
result += R"6XiGfT6l(
            <p>
                You are not logged in.
                <a href="/login">Login</a>
            </p>
            )6XiGfT6l";
 } 
result += R"ZK3vcorE(
        </div>
    </div>
</div>
</body>
</html>)ZK3vcorE";
return result;
}

