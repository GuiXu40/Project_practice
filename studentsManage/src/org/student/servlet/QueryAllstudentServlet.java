package org.student.servlet;

import org.student.org.student.entity.Student;
import org.student.service.StudentService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet(name = "Servlet4")
public class QueryAllstudentServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        StudentService service=new StudentService();
        List<Student> students=service.queryAllstudent();

        //通过请求转发将学生信息传过去
        request.setAttribute("students",students);
        //使用范围越小越好
        request.getRequestDispatcher("souye.jsp").forward(request,response);
    }
}
