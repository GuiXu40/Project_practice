//用于生成0~8的随机数

function RandomNumBoth(Min,Max){
    var Range = Max - Min;
    var Rand = Math.random();
    var num = Min + Math.round(Rand * Range); //四舍五入
    return num;
}

var set1;

 function randomHexColor() { //随机生成十六进制颜色
    var hex = Math.floor(Math.random() * 16777216).toString(16); //生成ffffff以内16进制数
    while(hex.toLowerCase()=="F1C40F".toLowerCase()){
        var hex = Math.floor(Math.random() * 16777216).toString(16);
    }
    while (hex.length < 6) { //while循环判断hex位数，少于6位前面加0凑够6位
        hex = '0' + hex;
    }
    return '#' + hex; //返回‘#’开头16进制颜色
}

 function changeColor(divs){
    var num1=RandomNumBoth(0,8);
    var num2=RandomNumBoth(0,8);
    var num3=RandomNumBoth(0,8);
    while(num1==num3){
        num3=RandomNumBoth(0,8);
    }
    while(num3==num2 || num2==num1){
        num2=RandomNumBoth(0,8);
    }
    var colors=new Array();
    colors[0]=randomHexColor();
    colors[1]=randomHexColor();
    colors[2]=randomHexColor();
    while(colors[0].toLowerCase()==colors[2].toLowerCase()){
        colors[2]=randomHexColor();
    }
    while(colors[0].toLowerCase()==colors[1].toLowerCase() || colors[1].toLowerCase()==colors[2].toLowerCase()){
        colors[1]=randomHexColor();
    }
    console.log(num1+","+num2+","+num3);
    console.log(colors[1]+","+colors[0]+","+colors[2]);
    for(var i=0;i<divs.length;i++){
        divs[i].style.backgroundColor="orange";
    }
    divs[num1].style.backgroundColor=colors[0];
    divs[num2].style.backgroundColor=colors[1];
    divs[num3].style.backgroundColor=colors[2];
 }
 var divs=document.getElementsByClassName("box");
 var btn1=document.getElementById("#btn1");
 var btn2=document.getElementById("#btn2");
function begin(){
    window.clearInterval(set1);
    set1=window.setInterval("changeColor(divs)",1000);
}
function stop(){
    window.clearInterval(set1);
    for(var i=0;i<divs.length;i++){
        divs[i].style.backgroundColor="orange";
    }
}
