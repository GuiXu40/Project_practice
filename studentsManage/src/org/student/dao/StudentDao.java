package org.student.dao;

import org.student.org.student.entity.Student;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

//原子性的操作--增删改查
public class StudentDao {
    private final String URL="jdbc:mysql://localhost:3306/text?useSSL=false&serverTimezone=UTC";
    private final String USER="root";
    private final String PASS="root";

    //判断学生是否存在
    public boolean isExist(int sno){
        return queryStudentBySno(sno)==null? false:true;
    }

    //增加学生
    public boolean addStudent(Student student){
        Connection connection=null;
        PreparedStatement pstmt=null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection= DriverManager.getConnection(URL,USER,PASS);
            String sql="insert into student1 values(?,?,?,?)";
            pstmt=connection.prepareStatement(sql);
            pstmt.setInt(1,student.getSno());
            pstmt.setString(2,student.getSname());
            pstmt.setInt(3,student.getSage());
            pstmt.setString(4,student.getSaddress());
            int count=pstmt.executeUpdate();
            if(count >0){
                return true;
            }else {
                return false;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return  false;
        }finally {
            try {
                if(pstmt!=null)pstmt.close();
                if(connection!=null)connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    //根据学号删除学生
    public boolean deleteStudentBySno(int sno){
        Connection connection=null;
        PreparedStatement pstmt=null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection= DriverManager.getConnection(URL,USER,PASS);
            String sql="delete from student1 where sno=?";
            pstmt=connection.prepareStatement(sql);
            pstmt.setInt(1,sno);
            int count=pstmt.executeUpdate();
            if(count >0){
                return true;
            }else {
                return false;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return  false;
        }finally {
            try {
                if(pstmt!=null)pstmt.close();
                if(connection!=null)connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    //查询全部学生
    public List<Student> queryAllstudent(){
        List<Student> students=new ArrayList<Student>();
        Connection connection=null;
        PreparedStatement pstmt=null;
        ResultSet rs=null;
        Student student=null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection= DriverManager.getConnection(URL,USER,PASS);
            String sql="select * from student1";
            pstmt=connection.prepareStatement(sql);
            rs=pstmt.executeQuery();
            while(rs.next()){
                int no=rs.getInt("sno");
                String name=rs.getString("sname");
                int age=rs.getInt("sage");
                String address=rs.getString("saddress");
                student=new Student(no,name,age,address);
                //将查询的结果依次添加到集合中
                students.add(student);
            }
            return students;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }finally {
            try {
                if(rs!=null)rs.close();
                if(pstmt!=null)pstmt.close();
                if(connection!=null)connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    //根据学号修改学生
    public boolean updateStudentBySno(int sno,Student student){
        Connection connection=null;
        PreparedStatement pstmt=null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection= DriverManager.getConnection(URL,USER,PASS);
            String sql="update student1 SET sname=?,sage=? ,saddress=? where sno=?";
            pstmt=connection.prepareStatement(sql);
            //修改的内容
            pstmt.setString(1,student.getSname());
            pstmt.setInt(2,student.getSage());
            pstmt.setString(3,student.getSaddress());
            //修改的那个人
            pstmt.setInt(4,sno);
            int count=pstmt.executeUpdate();
            if(count >0){
                return true;
            }else {
                return false;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return  false;
        }finally {
            try {
                if(pstmt!=null)pstmt.close();
                if(connection!=null)connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    //根据学号,查询学生
    public Student queryStudentBySno(int sno){
        Connection connection=null;
        PreparedStatement pstmt=null;
        ResultSet rs=null;
        Student student=null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            connection= DriverManager.getConnection(URL,USER,PASS);
            String sql="select * from student1 where sno=?";
            pstmt=connection.prepareStatement(sql);
            pstmt.setInt(1,sno);
            rs=pstmt.executeQuery();
            if(rs.next()){
                int no=rs.getInt("sno");
                String name=rs.getString("sname");
                int age=rs.getInt("sage");
                String address=rs.getString("saddress");
                student=new Student(no,name,age,address);
            }
            return student;
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }finally {
            try {
                if(rs!=null)rs.close();
                if(pstmt!=null)pstmt.close();
                if(connection!=null)connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
