const { PerformanceObserver, performance } = require("perf_hooks");
let mod;
try {
  mod = require("./build/Release/addon.node");
} catch (err) {
  mod = require("./build/Debug/addon.node");
}

(() => {
  let obs = 1000;
  let old = new Date();

  for (let i = 0; i < obs; i++) {
    mod.encrypt("plain-text");
  }

  let newt = new Date();

  console.log(
    `For ${obs} it took ${newt - old}. Avg time ${(newt - old) / obs} ms`
  );
})();
