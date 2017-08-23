#include "list.html.hpp"
std::string MessagesListHtml::render() {
std::string result;
result += R"TAmnqbJB(<!DOCTYPE HTML>
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
                )TAmnqbJB";
 for (auto message : messages) { 
result += R"cnIKDl36(
                <tr><td>
                <div class="author-name">)cnIKDl36";
result += fmt::format("{}", message->getAuthor()->getUsername() );
result += R"Se9TteQ4(:</div>
                <p class="message-content">
                    )Se9TteQ4";
result += fmt::format("{}", message->getContent() );
result += R"UXQjqCiU(
                </p>
                <small class="message-time text-right">)UXQjqCiU";
result += fmt::format("{}", message->getFriendlyCreatedAt() );
result += R"4tCcZU8B(</small>
                </td></tr>
                )4tCcZU8B";
 } 
result += R"T2OjizFH(
            </table>
            )T2OjizFH";
 if (currentUser) { 
result += R"4EiCQ1yy(
            <p>
                Hello, )4EiCQ1yy";
result += fmt::format("{}", currentUser->getUsername() );
result += R"vMBgiItb(!
                <a href="/logout">Logout</a>
            </p>
            <a href="/messages/new" class="btn btn-primary">New message</a>
            )vMBgiItb";
 } else { 
result += R"EEXVJyEl(
            <p>
                You are not logged in.
                <a href="/login">Login</a>
            </p>
            )EEXVJyEl";
 } 
result += R"Ub3uwnHJ(
        </div>
    </div>
</div>
</body>
</html>)Ub3uwnHJ";
return result;
}

