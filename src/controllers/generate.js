/**
 * Express controller for handling /generate router
 *
 * @author Richard Nguyen <richard.ng0616@gmail.com>
 */

const express = require("express");

const addon = require("../../build/Release/nodify.node");

const generateRouter = express.Router();

generateRouter.post("/array", (req, res) => {
  res.send({
    success: true,
    message: "generated array",
    array: addon.randomIntegers(Number.parseInt(req.body.arrayRange, 10)),
  });
});

module.exports = generateRouter;
