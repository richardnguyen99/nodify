const path = require("path");
const express = require("express");
const dotenv = require("dotenv");

dotenv.config();

const app = express();

// App configuration
app.set("PORT", process.env.PORT || 4000);
app.set("view engine", "pug");
app.use(express.static(path.join(__dirname, "public")));

app.get("/", (_req, res) => {
  res.render("home", {
    title: "Home",
    content: "testing",
  });
});

module.exports = app;
