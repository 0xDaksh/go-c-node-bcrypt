let mod;
try {
  mod = require("./build/Release/addon.node");
} catch (err) {
  mod = require("./build/Debug/addon.node");
}

module.exports = {
  Encrypt: async plain => {
    return mod.encrypt(plain);
  },
  Compare: async (hash, plain) => {
    let res = await mod.compare(hash, plain);

    if (res === "false") {
      return false;
    } else {
      return true;
    }
  }
};
