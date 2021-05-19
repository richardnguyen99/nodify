const express = require("express");
const dotenv = require("dotenv");

dotenv.config();

const app = express();

// App configuration
app.set("PORT", process.env.PORT || 4000);
app.set("view engine", "pug");

app.get("/", (_req, res) => {
  res.render("home", {
    title: "Home",
    content: "testing",
  });
});

app.listen(app.get("PORT"), () => {
  console.log("App is listening ...");
});
