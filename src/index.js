"use strict";

const express = require("express");

const app = express();

// App configuration
app.set("view engine", "pug");

app.get("/", function (req, res) {
  res.render("home", {
    title: "Home",
    content: "testing"
  })
});

app.listen(4000, function () {
    console.log(`App is listening ...`);
});
