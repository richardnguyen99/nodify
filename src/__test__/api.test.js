/**
 * Jest testing file for loading pages
 *
 * @author Richard Nguyen <richard.ng0616@gmail.com>
 */

const request = require("supertest");

const app = require("../app");

describe("Testing API endpoints", () => {
  it("Testing /generate/array endpoint", (done) => {
    request(app)
      .post("/generate/array")
      .send({ arrayRange: 8 })
      .expect("Content-Type", "application/json; charset=utf-8")
      .expect(200)
      .end((error, response) => {
        if (error) {
          return done(error);
        }

        expect(response.body.success).toBeTruthy();
        expect(response.body.array).toHaveLength(8);
        return done();
      });
  });
});
