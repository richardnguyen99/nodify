const express = require("express");
const addon = require("../../build/Release/addon");

const router = express.Router();

router.get("/", function (req, res) {
  res.render("algorithm", {
    title: "Algorithm page",
    pageName: "algorithm",
    hello: addon.hello(),
    array: addon.randomIntegers(),
  });
});

router.get("/sorting", function (req, res) {
  res.send("Sorting page");
});

router.post("/sorting", function (req, res) {
  let body = req.body;
  console.log(body);

  res.send({ sortedArray: addon.bubbleSort(body.array)});
})

module.exports = router;
