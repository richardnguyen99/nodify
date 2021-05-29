/**
 * Export all controllers under "controller" package
 *
 * @author Richard Nguyen <richard.ng0616@gmail.com>
 */

const dsRouter = require("./data-structure");
const algorithmRouter = require("./algorithm");
const generateRouter = require("./generate");

module.exports = {
  dsRouter,
  algorithmRouter,
  generateRouter,
};
