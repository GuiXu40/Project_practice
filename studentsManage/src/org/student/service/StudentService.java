package org.student.service;

import org.student.dao.StudentDao;
import org.student.org.student.entity.Student;

import java.util.List;

//业务逻辑层,逻辑性的增删改查
public class StudentService {
    StudentDao studentDao=new StudentDao();
    //增加学生
    public boolean addStudent(Student student){
        if(!studentDao.isExist(student.getSno())){
            studentDao.addStudent(student);
            return true;
        }else{
            System.out.println("此人已存在!");
            return false;
        }
    }

    //根据学号删除学生
    public boolean deleteStudentBySno(int sno){
        if(studentDao.isExist(sno)){
            return studentDao.deleteStudentBySno(sno);
        }
        return false;
    }

    //根据学号更改学生
    public boolean updateStudentBySno(int sno,Student student){
        if(studentDao.isExist(sno)){
            return studentDao.updateStudentBySno(sno,student);
        }
        return false;
    }

    //根据学号查询一个学生
    public Student queryStudentBySno(int sno){
        return studentDao.queryStudentBySno(sno);
    }

    //查询全部学生
    public List<Student> queryAllstudent(){
        return studentDao.queryAllstudent();
    }
}
