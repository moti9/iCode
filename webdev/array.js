let marks = [96, 63, 85];
// console.log(marks);
// console.log(typeof (marks));

marks[1] = 963;

//Push in array

// console.log(marks.push(12));
// console.log(marks);

//Change to string
let str = marks.toString();
// console.log(str, typeof (str));

// console.log(marks.pop());
// console.log(marks.push(96));
// console.log(marks.push(63));

//join
let s = marks.join(" ");
// console.log(s);

//shift
// console.log(marks.shift());
// console.log(marks);

//unshift
// console.log(marks.unshift());
// console.log(marks);

//delete
delete marks[0];
// console.log(marks.length);
// console.log(marks);
// console.log(marks.length);

//Array concat
let num1=[1,2,3,4,5,6,7,8,9];
let num2=[1,2,3,4,5,6,7,8,9];
let num3=[1,2,3,4,5,6,7,8,9];
let num4=[1,2,3,4,5,6,7,8,9];

let num=num1.concat(num2,num3,num4);
// console.log(num);

//Sort
num.sort(); //sorting alphabetically

let arr=[9,8,2,6,11,36,12];
arr.sort();
// console.log(arr);

const compare=(a,b)=>{
    return a-b;
}

arr.sort(compare);
// console.log(arr);

//reverse
arr.reverse();
// console.log(arr);

//Splice-pos,no_num,num1,num2,..

arr.splice(2,3,1011,1022,963);
// console.log(arr);

//slice-stIdx,LIdx-1
let newarr=arr.slice(2,6);
// console.log(newarr);

//For loop in array
// for (let index = 0; index < arr.length; index++) {
//     const element = arr[index];
//     console.log(element*2," ");
// }

//Foreach 
// arr.forEach((element )=> {
//     console.log(element*10);
// });

//Array from

let name="Javascript";
let nm=Array.from(name);
// console.log(nm);

//for..of

// for (const itr of arr) {
//     console.log(itr);
// }

//Map-create a new array

// let ar=arr.map((ele)=>{
//     return ele*2;
// });
// console.log(arr);
// console.log(ar);

//Array filter

// let fa=arr.filter((ele)=>{
//     return ele>9;
// })
// console.log(fa);



// let ra=arr.reduce((e,f)=>{
//     return e+f;
// })
// console.log(ra);

