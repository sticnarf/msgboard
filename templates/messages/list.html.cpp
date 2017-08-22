#include "list.html.hpp"
std::string MessagesListHtml::render() {
std::string result;
result += R"1pI7s6Xq(<!DOCTYPE HTML>
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
                <tr>
                    <td>Row 1</td>
                </tr>
                <tr>
                    <td>Row 2</td>
                </tr>
                <tr>
                    <td>Row 3</td>
                </tr>
                <tr>
                    <td>Row 4</td>
                </tr>
            </table>
            )1pI7s6Xq";
 if (currentUser) { 
result += R"yYfxBGAx(
            <p>
                Hello, )yYfxBGAx";
result += fmt::format("{}", currentUser->getUsername() );
result += R"spo3YOu3(!
                <a href="/logout">Logout</a>
            </p>
            <a href="/new" class="btn btn-primary">New message</a>
            )spo3YOu3";
 } else { 
result += R"oKtudDSY(
            <p>
                You are not logged in.
                <a href="/login">Login</a>
            </p>
            )oKtudDSY";
 } 
result += R"MnoMzIaD(
        </div>
    </div>
</div>
</body>
</html>)MnoMzIaD";
return result;
}

