/**
 * Express controller for handling /ds router
 *
 * @author Richard Nguyen <richard.ng0616@gmail.com>
 */

const express = require("express");

const dsRouter = express.Router();

dsRouter.get("/", (_req, res) => {
  res.render("data-structure");
});

module.exports = dsRouter;
