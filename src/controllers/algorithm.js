/**
 * Express controller for handling /algorithm router
 *
 * @author Richard Nguyen <richard.ng0616@gmail.com>
 */

const express = require("express");

const utility = require("../util");
const addon = require("../../build/Release/nodify.node");

const algorithmRouter = express.Router();

algorithmRouter.get("/", (_req, res) => {
  res.render("algorithm");
});

algorithmRouter.get("/:algorithmType/:algorithm", (req, res) => {
  const { params } = req;

  res.render(`algorithm/${params.algorithmType}/${params.algorithm}`, {
    title: utility.stringConverter.hyphenToTitle(params.algorithm),
  });
});

// To keep it simple, we only use this router to get animations
algorithmRouter.post("/:algorithmType/:algorithm", (req, res) => {
  const { params } = req;

  res.send({
    animation: addon[
      `get${utility.stringConverter.hyphenToPascal(
        // eslint-disable-next-line comma-dangle
        params.algorithm
      )}Animation`
    ](req.body.array),
  });
});

module.exports = algorithmRouter;
