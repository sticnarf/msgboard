#include "new.html.hpp"
std::string UsersNewHtml::render() {
std::string result;
result += R"nVc68T8b(<!DOCTYPE HTML>
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
            )nVc68T8b";
 for (auto &message : errorMessages) { 
result += R"TqFBnebw(
            <div class="alert alert-danger" role="alert">
                <span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>
                <span class="sr-only">Error:</span>
                )TqFBnebw";
result += fmt::format("{}", message );
result += R"Z0A5Qv3V(
            </div>
            )Z0A5Qv3V";
 } 
result += R"pLSPVNij(
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
</html>)pLSPVNij";
return result;
}

