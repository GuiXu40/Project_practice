package org.student.servlet;

import org.student.service.StudentService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "Servlet")
public class DeleteStudentServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //接收前端传来的学号
        int no=Integer.parseInt(request.getParameter("sno"));
        StudentService studentService=new StudentService();
        boolean result=studentService.deleteStudentBySno(no);
        response.setContentType("text/html;charset=UTF-8");
        response.setCharacterEncoding("utf-8");
        if(result){
         //   response.getWriter().print("删除成功!");
            response.sendRedirect("QueryAllstudentServlet");
        }else{
            response.getWriter().print("删除失败!");
        }
    }
}
