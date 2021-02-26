const express = require("express");
const expressLayouts = require("express-ejs-layouts");
const bodyParser = require("body-parser");
const addon = require("../build/Release/addon");
const router = require("./routes");

const app = express();

app.use(express.static("views/static"));
app.use(expressLayouts);
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
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
    pageName: "about",
  });
});

app.use("/algorithm", router.algorithmRouter);

app.listen(3000, function() {
  console.log("App is listening on port 3000");
});
