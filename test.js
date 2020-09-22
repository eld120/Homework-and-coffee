let startNum;
let endNum;

function rangeOfNumbers(startNum, endNum) {
  let x = startNum;
  let y = endNum;
  let z = [startNum];
    

  if (x == y){
    return z;
  } else{
    x++;
    z = z.push(x);
    
    return rangeOfNumbers(x, y);

  }
};
