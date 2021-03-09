const express = require("express");
const addon = require("../../build/Release/addon");

const router = express.Router();

router.get("/", function (req, res) {
  res.render("algorithm", {
    title: "Algorithm page",
    pageName: "algorithm",
  });
});

router.get("/sorting", function (req, res) {
  res.send("Sorting page");
});

router.post("/sorting", function (req, res) {
  let body = req.body;

  res.send({ success: true, sortedArray: addon.bubbleSort(body.array) });
})

router.post("/sorting/generate", function (req, res) {
  let body = req.body;

  res.send({ success: true, array: addon.randomIntegers(Number.parseInt(body.arrayRange)) });
})

module.exports = router;
