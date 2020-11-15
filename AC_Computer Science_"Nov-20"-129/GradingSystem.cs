using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GradingSystem
{
    class GradingSystem
    {
        public class Student{
            private char grade;// grade variable
            private double marks;//marks variable
            public string name;//name variable
            //function to set name
            public void setName(string studentName)
            {   
                name = studentName;
            }
            //function to return name
            public string getName()
            {
                return name;
            }
            //function to set marks
            public void setMarks(double studentMarks)
            {
                marks = studentMarks;
            }
            //function to get marks
            public double getMarks()
            {
                return marks;
            }
            //function to get grade from marks.
            public char getGrade()
            {
                // grade.Add(val);
                if(marks >= 80)
                {
                    grade = 'A';// A grade
                }
                else if( (marks >=65) && (marks < 80) )
                {
                    grade = 'B';// B grade
                }
                else if( (marks >= 50) && (marks <65) )
                {
                    grade = 'C';// C grade
                }
                else if( (marks >= 40) && (marks  <50) )
                {
                    grade = 'D';// D grade 
                }
                else{
                    grade = 'F';// F grade
                }
            return grade;
            }
        }

        //Main method for running the code.
        static void Main(string[] args)
        {
            int numberOfStudents;
            string studentName;
            double studentMarks;
            //enter number of students.
            Console.WriteLine("Enter Number of Students : ");
            numberOfStudents = int.Parse(Console.ReadLine());
            //create array of objects
            Student[] students = new Student[numberOfStudents];
            for(int i=0;i<numberOfStudents;i++)
            {
                students[i] = new Student();//create student object
                Console.WriteLine("\nEnter the name for student #"+i+": "); 
                studentName = Console.ReadLine();
                students[i].setName(studentName);
                Console.WriteLine("\nEnter the marks for student #"+i+": ");
                studentMarks = double.Parse(Console.ReadLine()); 
                students[i].setMarks(studentMarks);
            } 
            
            //Print the student information.
            for(int i=0;i<numberOfStudents;i++)
            {
                Console.WriteLine("\n"+students[i].getName() +" mark is "+students[i].getMarks() +" and grade is "+ students[i].getGrade());
            }

        }
    }
}
