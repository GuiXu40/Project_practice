<%--
  Created by IntelliJ IDEA.
  User: 桂旭
  Date: 2019/9/7
  Time: 17:32
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="org.student.org.student.entity.Student" %>
<html>
<head>
    <title>学生个人详细信息</title>
</head>
<body>
        <%
            Student student=(Student)request.getAttribute("student");
        %>
        <form action="updateStudentServlet">
            学号:<input name="sno" value="<%= student.getSno()%>" type="text" readonly="readonly"><br>
            姓名:<input name="sname" value="<%= student.getSname()%>" type="text"><br>
            学号:<input name="sage" value="<%= student.getSage()%>" type="text"><br>
            学号:<input name="saddress" value="<%= student.getSaddress()%>" type="text"><br>
            <input type="submit" value="修改">
            <a href="QueryAllstudentServlet">返回</a>
        </form>
</body>
</html>
