const x = 30;
const y = 50;

// gcd = greatest common divisor
function gcdIterative(a: number, b: number): number {
  while (b !== 0) {
    let temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

function gcdRecursive(a: number, b: number): number {
  if (b === 0) {
    return a;
  }
  return gcdRecursive(b, a % b);
}

// When to use which gcd function?
// - Iterative: straight forward, no risk of stack overflow (it doesn't add new layers to the call stack)
// - Recursive: elegant, more closer to mathematical definition, but risk of stack overflow (it adds new layers to the call stack)
console.log(
  "gcdIterative(x, y):",
  gcdIterative(x, y),
  "Time consume:",
  performance.now()
);
console.log(
  "gcdRecursive(x, y):",
  gcdRecursive(x, y),
  "Time consume:",
  performance.now()
);

// lcm = least common multiple
// lcm formula: lcm(a, b) = (a * b) / gcd(a, b)
function lcm(a: number, b: number): number {
  return (a * b) / gcdIterative(a, b);
}

console.log("lcm(x, y):", lcm(x, y));

console.log("Product of x and y:", x * y);

// There is a relationship between gcd and lcm
// lcm(a, b) = (a * b) / gcd(a, b)
// lcm(a, b) * gcd(a, b) = a * b
// lcm * gcd = a * b

// So, lcm * gcd = a * b
