const request = require("supertest");

const app = require("../app");

describe("Getting app...", () => {
  it("responds to /", (done) => {
    request(app).get("/").expect(200, done);
  });
});
