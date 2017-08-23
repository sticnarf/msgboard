#include "new.html.hpp"
std::string SessionsNewHtml::render() {
std::string result;
result += R"fDYAslim(<!DOCTYPE HTML>
<html>
<head>
    <meta charset="utf-8">
    <link rel="stylesheet" href="/assets/style.css">
    <link rel="stylesheet" href="https://cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap.min.css"
          integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
    <script src="https://cdn.bootcss.com/bootstrap/3.3.7/js/bootstrap.min.js"
            integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa"
            crossorigin="anonymous"></script>
</head>
<body>
<div class="container">
    <div class="row">
        <div class="col-xs-12 col-md-4 col-md-offset-4">
            <h1>Login</h1>
            )fDYAslim";
 for (auto &message : errorMessages) { 
result += R"2FzLNsYQ(
            <div class="alert alert-danger" role="alert">
                <span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>
                <span class="sr-only">Error:</span>
                )2FzLNsYQ";
result += fmt::format("{}", message );
result += R"VnmFnW6r(
            </div>
            )VnmFnW6r";
 } 
result += R"NEx4MN41(
            <form class="main-table" action="/login" method="post">
                <div class="form-group">
                    <label for="username">Username</label>
                    <input class="form-control" id="username" name="username">
                </div>
                <div class="form-group">
                    <label for="password">Password</label>
                    <input type="password" class="form-control" id="password" name="password">
                </div>
                <button type="submit" class="btn btn-primary">Submit</button>
                <a href="/users/new">No account?</a>
            </form>
            <p><a href="/">Back to home</a></p>
        </div>
    </div>
</div>
</body>
</html>)NEx4MN41";
return result;
}

