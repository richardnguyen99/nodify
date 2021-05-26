const request = require("supertest");

const app = require("../app");

describe("Getting app...", () => {
  it("responds to /", (done) => {
    request(app).get("/").expect(200, done);
  });
  it("responds to /ds", (done) => {
    request(app).get("/ds").expect(200, done);
  });
  it("responds to /algorithm", (done) => {
    request(app).get("/algorithm").expect(200, done);
  });

  it("responds to /ping", (done) => {
    request(app).get("/ping").expect(200, done);
  });

  it("responsed to /invalid_url", (done) => {
    request(app).get("/invalid_url").expect(404, done);
  });
});
