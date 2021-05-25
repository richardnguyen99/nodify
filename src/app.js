/**
 * Setup file for Express app.
 * This contains only configuration, environments
 * and middlewares for runnning and testing
 *
 * @author Richard Nguyen <richard.ng0616@gmail.com>
 */

const path = require("path");
const express = require("express");
const dotenv = require("dotenv");

const controllers = require("./controllers");

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

app.use("/ds", controllers.dsRouter);
app.use("/algorithm", controllers.algorithmRouter);

module.exports = app;
