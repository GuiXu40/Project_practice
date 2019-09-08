package org.student.servlet;

import org.student.org.student.entity.Student;
import org.student.service.StudentService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "Servlet3")
public class QueryStudentBySnoServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //查询人的学号
        int no=Integer.parseInt(request.getParameter("sno"));
        //调用业务逻辑层
        StudentService service=new StudentService();
        Student student= service.queryStudentBySno(no);
        System.out.println(student);
        //通过请求转发
        request.setAttribute("student",student);
        request.getRequestDispatcher("studentInfo.jsp").forward(request,response);
    }
}
