/**
 * Express controller for handling /algorithm router
 *
 * @author Richard Nguyen <richard.ng0616@gmail.com>
 */

const express = require("express");

const { stringConverter } = require("../util");
const addon = require("../../build/Release/nodify.node");

const algorithmRouter = express.Router();

algorithmRouter.get("/", (_req, res) => {
  res.render("algorithm");
});

algorithmRouter.get("/:algorithmType/:algorithm", (req, res) => {
  const { params } = req;

  res.render(`algorithm/${params.algorithmType}/${params.algorithm}`, {
    title: stringConverter.hyphenToTitle(params.algorithm),
  });
});

algorithmRouter.post("/sorting/:sortingType", (req, res) => {
  const { params } = req;

  res.send({
    sortedArray: addon[stringConverter.hyphenToCamel(params.sortingType)](
      // eslint-disable-next-line comma-dangle
      req.body.array,
    ),
    animation: addon[
      `get${stringConverter.hyphenToPascal(params.sortingType)}Animation`
    ](req.body.array),
  });
});

module.exports = algorithmRouter;
