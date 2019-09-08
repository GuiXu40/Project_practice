package org.student.servlet;

import org.student.org.student.entity.Student;
import org.student.service.StudentService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "Servlet2")
public class updateStudentServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        //获得修改人的学号
        int no=Integer.parseInt(request.getParameter("sno"));
        //获取修改的信息
        String name=request.getParameter("sname");
        int age=Integer.parseInt(request.getParameter("sage"));
        String address=request.getParameter("saddress");
        //将修改的信息封装到Javabean中
        Student student=new Student(name,age,address);
        //调用业务逻辑
        StudentService service=new StudentService();
        boolean result=service.updateStudentBySno(no,student);
        response.setContentType("text/html;charset=UTF-8");
        response.setCharacterEncoding("utf-8");
        if(result){
            //response.getWriter().print("修改成功!");
            //修改完之后,直接跳到查询
            response.sendRedirect("QueryAllstudentServlet");
        }else{
            response.getWriter().print("修改失败!");
        }
    }
}
