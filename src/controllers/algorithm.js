/**
 * Express controller for handling /algorithm router
 *
 * @author Richard Nguyen <richard.ng0616@gmail.com>
 */

const express = require("express");

const algorithmRouter = express.Router();

algorithmRouter.get("/", (_req, res) => {
  res.render("algorithm");
});

algorithmRouter.get("/:algorithmType/:algorithm", (req, res) => {
  const { params } = req;

  res.render(`algorithm/${params.algorithmType}/${params.algorithm}`, {
    title: params.algorithm,
  });
});

module.exports = algorithmRouter;
