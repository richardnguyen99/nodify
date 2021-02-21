const express = require("express");
const expressLayouts = require("express-ejs-layouts");

const app = express();

app.use(express.static("views/static"));
app.use(expressLayouts);
app.set("layout", "./layouts/layout");
app.set("view engine", "ejs");

app.get("/", function (req, res) {
  res.render("index", {
    title: "Home page",
    pageName: "home"
  });
});

app.get("/about", function (req, res) {
  res.render("about", {
    title: "About page",
    pageName: "about"
  });
});

app.get("/algorithm", function (req, res) {
  res.render("algorithm", {
    title: "Algorithm page",
    pageName: "algorithm"
  });
});

app.listen(3000, function() {
  console.log("App is listening on port 3000");
});
