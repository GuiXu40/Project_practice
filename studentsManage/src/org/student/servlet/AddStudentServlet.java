package org.student.servlet;

import org.student.org.student.entity.Student;
import org.student.service.StudentService;

import java.io.IOException;
import java.io.PrintWriter;

//@javax.servlet.annotation.WebServlet(name = "Servlet")
public class AddStudentServlet extends javax.servlet.http.HttpServlet {
    protected void doPost(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        request.setCharacterEncoding("UTF-8");
        int sno=Integer.parseInt(request.getParameter("sno"));
        String sname=request.getParameter("sname");
        int sage=Integer.parseInt(request.getParameter("sage"));
        String saddress=request.getParameter("saddress");
        //封装到一个Javabean中
        Student student=new Student(sno,sname,sage,saddress);
        StudentService studentService=new StudentService();
        boolean result=studentService.addStudent(student);
        //如果不处理响应的编码,会出现乱码
        response.setContentType("text/html;charset=UTF-8");
        response.setCharacterEncoding("UTF-8");
        //response中的内置对象,可以返回一个out对象,可用于输出
        PrintWriter out=response.getWriter();
        if (result){
            //out.print("增加成功!");
            response.sendRedirect("QueryAllstudentServlet");
        }else{
            out.print("增加失败!");
        }
    }
}
