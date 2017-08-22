#include "list.html.hpp"
std::string MessagesListHtml::render() {
std::string result;
result += R"xFrdBdRc(<!DOCTYPE HTML>
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
            <a href="/new" class="btn btn-primary">New message</a>
        </div>
    </div>
</div>
</body>
</html>)xFrdBdRc";
return result;
}

