const k = 100;

function sieveOfEratosthenes(k: number): number[] {
  let prime: boolean[] = new Array(k + 1).fill(true);
  let primeNumbers: number[] = [];

  for (let p = 2; p <= k; p++) {
    if (prime[p]) {
      primeNumbers.push(p);
      // Mark all multiples of p as false
      for (let i = p * p; i <= k; i += p) {
        prime[i] = false;
      }
    }
  }
  return primeNumbers;
}

console.log("Prime numbers from 1 to", k, ":", sieveOfEratosthenes(k));
console.log(
  "Total prime numbers from 1 to",
  k,
  ":",
  sieveOfEratosthenes(k).length
);

// performance in milliseconds
console.log("From 1 to 100000", sieveOfEratosthenes(100000), performance.now());
