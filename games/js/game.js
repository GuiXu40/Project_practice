var w = window;
requestAnimationFrame = w.requestAnimationFrame || w.webkitRequestAnimationFrame || w.msRequestAnimationFrame || w.mozRequestAnimationFrame;

//创建一个canvas画布
var canvas = document.createElement("canvas")
var ctx = canvas.getContext("2d")  //用于获取画布中的上下文
canvas.width = 512
canvas.height = 480
document.body.appendChild(canvas)

//导入图片
var bgReady = false;
var bgImage = new Image();
bgImage.onload = function () {
    bgReady = true;
};
bgImage.src = "images/background.png";

var heroReady = false;
var heroImage = new Image();
heroImage.onload = function () {
    heroReady = true;
};
heroImage.src = "images/hero.png"

var monsterReady = false;
var monsterImage = new Image();
monsterImage.onload = function () {
    monsterReady = true;
}
monsterImage.src = "images/monster.png"

//游戏中的挤出对象
var hero = {
    speed: 256
};
var monster = {};
var monsterCaught = 0;

//监听键盘事件
var keysDown = {};
addEventListener("keydown", function (e) {
    keysDown[e.keyCode] = true;
}, false)

addEventListener("keyup", function (e) {
    delete keysDown[e.keyCode];
}, false)

//重置游戏
var reset = function () {
    hero.x = canvas.width / 2;
    hero.y = canvas.height / 2;

    monster.x = 32 + (Math.random() * (canvas.width - 64));
    monster.y = 32 + (Math.random() * (canvas.height - 64));
}

//更新状态,  modifier变量用于控制速度
var update = function (modifier) {
    if (38 in keysDown) {
        hero.y -= hero.speed * modifier;
    }
    if (40 in keysDown) {
        hero.y += hero.speed * modifier;
    }
    if (37 in keysDown) {
        hero.x -= hero.speed * modifier;
    }
    if (39 in keysDown) {
        hero.x += hero.speed * modifier;
    }
    //判断是否相遇--32是指图片的大小
    if (hero.x <= (monster.x + 32) && monster.x <= (hero.x + 32) &&
     hero.y <= (monster.y + 32) && hero.y <= (hero.y + 32)) {
         ++monsterCaught;
         reset();
     }
}

//渲染
var render = function () {
    if (bgReady) {
        ctx.drawImage(bgImage, 0, 0);
    }

    if (heroReady) {
        ctx.drawImage(heroImage, hero.x, hero.y);
    }

    if (monsterReady) {
        ctx.drawImage(monsterImage, monster.x, monster.y)
    }

    ctx.fillStyle = "rgb(250, 250, 250)";
    ctx.font = "24px Helvetica";
    ctx.textAlign = "left";
    ctx.textBaseline = "top";
    ctx.fillText("Goblins caught" + monsterCaught, 32, 32);
};

//主函数
// window.requestAnimationFrame() 
// 告诉浏览器——你希望执行一个动画，并且要求浏览器在下次重绘之前调用指定的回调函数更新动画。
// 该方法需要传入一个回调函数作为参数，该回调函数会在浏览器下一次重绘之前执行
var main = function () {
    var now = Date.now();

    var delta = now - then;
    update(delta / 1000);
    render();

    then = now;
    requestAnimationFrame(main)
}

var then = Date.now();
reset();
main();