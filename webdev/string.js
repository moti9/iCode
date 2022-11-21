let str="Hello world";
console.log(str);
console.log(str[2]);
console.log(typeof(str));

//Length of the string
console.log(str.length);

//charAt(i)-Returns the character at index i
console.log(str.charAt(2));

//charCodeAt()-Return the unicode of the character
let res=str.charCodeAt(1);
console.log(res);

//concat()-join two or more strings
let a="Alice";
let bob="Bob";
let b=' ';
let albob=a.concat(b,bob);
console.log(albob);
console.log(a);
console.log(bob);

//Template literal
console.log(`${a} is friend\'s  ${bob}`);

console.log(a.toUpperCase());
console.log(a);
console.log(albob.toUpperCase());
console.log(albob.toLowerCase());

//Slice 
console.log(albob.slice(1,8));

//Replace
console.log(albob.replace('Alice','Alone'));
console.log(albob.replace('Bob','Boy'));

//Include-check
console.log(albob.includes('e B'));

//endswith-last check
console.log(albob.endsWith('Bob'));

//parseInt
let number="963";
let num=Number.parseInt(number);
console.log(number,typeof number);
console.log(num,typeof num);