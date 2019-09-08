<%@ page import="org.student.org.student.entity.Student" %>
<%@ page import="java.util.List" %><%--
  Created by IntelliJ IDEA.
  User: 桂旭
  Date: 2019/9/7
  Time: 16:19
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>学生信息</title>
</head>
<body>
        <table border="1px">
            <tr>
                <th>学号</th>
                <th>姓名</th>
                <th>年龄</th>
                <th>操作</th>
            </tr>
            <%
                //获取request域中的数据
                List<Student> students=(List<Student>)request.getAttribute("students");
                for(Student student:students){
             %>
                    <tr>
                        <td><a href="QueryStudentBySnoServlet?sno=<%= student.getSno()%>"><%= student.getSno()%></a></td>
                        <td><%= student.getSname()%></td>
                        <td><%= student.getSage()%></td>
                        <td><a href="DeleteStudentServlet?sno=<%= student.getSno()%>">删除</a></td>
                    </tr>
             <%
            }
            %>
        </table>
        <a href="AddStudentServlet">新增</a>
</body>
</html>
