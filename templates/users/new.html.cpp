#include "new.html.hpp"
std::string UsersNewHtml::render() {
std::string result;
result += R"BrUYgyjE(<!DOCTYPE HTML>
<html>
<head>
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
            <h1>Register</h1>
            )BrUYgyjE";
 for (auto &message : errorMessages) { 
result += R"8Yz1AFXv(
            <div class="alert alert-danger" role="alert">
                <span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>
                <span class="sr-only">Error:</span>
                )8Yz1AFXv";
result += fmt::format("{}", message );
result += R"ogOwuAh7(
            </div>
            )ogOwuAh7";
 } 
result += R"64gZfI2Z(
            <form class="main-table" action="/users" method="post">
                <div class="form-group">
                    <label for="username">Username</label>
                    <input class="form-control" id="username" name="username">
                </div>
                <div class="form-group">
                    <label for="password">Password</label>
                    <input type="password" class="form-control" id="password" name="password">
                </div>
                <div class="form-group">
                    <label for="password_confirmation">Password Confirmation</label>
                    <input type="password" class="form-control" id="password_confirmation" name="password_confirmation">
                </div>
                <button type="submit" class="btn btn-primary">Submit</button>
                <a href="/login">Already have an account?</a>
            </form>
            <p><a href="/">Back to home</a></p>
        </div>
    </div>
</div>
</body>
</html>)64gZfI2Z";
return result;
}

