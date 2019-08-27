$(function(){
  $(".error-pwd, .error-email").hide();
  $(".overlay").hide();
  $(".confirmation").hide();
})

function checkEmail(email){
	var emailReg = /^[a-zA-Z0-9.!#$%&’*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/;
  	// test方法: 如果字符串 email 中含有与 emailReg 匹配的文本,返回一个boolean值
  	return emailReg.test(email);
}

function checkInfo(){
	var email=$("input[type=email]");
	var count=0;
	var pwd=$("input[type=password]");
	if(!checkEmail($(email).val())){
		$(".error-email").fadeIn();
		$(".email-msg").html("请输入正确的邮箱");
		$(email).addClass("warning");
		count++;
	}else{
		$(email).removeClass("warning");
	}
	if ($(pwd).val().length< 5) {
		$(".error-pwd").fadeIn();
		$(".pwd-msg").html("请输入正确的密码");
		$(pwd).addClass("warning");
		count++;
	}else{
		$(pwd).removeClass("warning");
	}
	setTimeout(function showErrorMsg() {
       $(".error-email, .error-pwd").fadeOut();
	   }, 2000)

	  if(count === 0) {
	    $(".overlay").show();
	    $(".confirmation").show();
	  }
}