//用于生成随机的三种颜色
var getRandomColor = function(){    
    return  '#' + (function(color){    
         return (color +=  '0123456789abcdef'[Math.floor(Math.random()*16)])    
         && (color.length == 6) ?  color : arguments.callee(color);    
    })('');    
 } 

 function changeColor(divs){
    var num1=Math.floor(Math.random()*10);
    var num2=Math.floor(Math.random()*10);
    var num3=Math.floor(Math.random()*10);
    console.log(num1+","+num2+","+num3);
    while(num1==num2){
        num2=Math.floor(Math.random()*10);
    }
    while(num3==num2){
        num3=Math.floor(Math.random()*10);
    }
    for(var i=0;i<divs.length;i++){
        divs[i].style.backgroundColor="orange";
        if(i==num1 || i==num2 || i==num3){
            divs[i].style.backgroundColor=getRandomColor();
        }
    }
 }
 var divs=document.getElementsByClassName("box");
 var btn1=document.getElementById("#btn1");
 var btn2=document.getElementById("#btn2");
function begin(){
    set1=window.setInterval("changeColor(divs)",1000);
}
function stop(){
    window.clearInterval(set1);
    for(var i=0;i<divs.length;i++){
        divs[i].style.backgroundColor="orange";
    }
}