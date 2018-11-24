const bcryptjs = require("bcryptjs");
const bcrypt = require("./index.js");

describe("create a bcrypt hash", () => {
  it("should create the right hash", async () => {
    const plain = "this-is-a-hash";
    const hash = await bcrypt.Encrypt(plain);

    expect(bcryptjs.compareSync(plain, hash)).toBe(true);
  });
});

describe("comparing hash should work", () => {
  it("should compare the hash with the plain", async () => {
    const plain = "this-is-a-hash";
    const hash = await bcryptjs.hashSync(plain);

    expect(await bcrypt.Compare(hash, plain)).toBe(true);
  });
});
