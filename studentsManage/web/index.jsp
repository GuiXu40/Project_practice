<%--
  Created by IntelliJ IDEA.
  User: 桂旭
  Date: 2019/9/5
  Time: 14:25
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>首页</title>
  </head>
  <body>
        <form action="AddStudentServlet" method="post">
            学号:<input type="text" name="sno"><br>
            姓名:<input type="text" name="sname"><br>
            年龄:<input type="text" name="sage"><br>
            地址:<input type="text" name="saddress"><br>
            <input type="submit" value="增加">
        </form>
  </body>
</html>
