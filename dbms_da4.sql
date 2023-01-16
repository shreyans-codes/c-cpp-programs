create or replace PROCEDURE classify_students
IS 
class_val varchar2(15);
CURSOR c1 IS (select * from students);
begin 
for c_row in c1 
loop 
    c_row.total := calc_stud_total(c_row.stud_reg_no);
    if (c_row.total >= 360) then 
        class_val := 'First';
    elsif ( c_row.total < 360 and c_row.total >= 320) then
        class_val := 'Second';
    elsif ( c_row.total < 320 and c_row.total >= 270) then
        class_val := 'Third';
    elsif ( c_row.total < 270 and c_row.total > 160) then
        class_val := 'PASS';
    else 
        class_val := 'FAIL';
    end if;
    update students set total = c_row.total where stud_reg_no = c_row.stud_reg_no;
    update students set class = class_val where stud_reg_no = c_row.stud_reg_no;
end loop;
end;
/ 

create table students(
    stud_reg_no number,
    name varchar2(30),
    physics number,
    chemistry number,
    maths number,
    L1 number,
    L2 number,
    total number,
    class varchar2(15)
);

insert into students values(1001, 'Jayant', 58, 61, 70, 66, 61, NULL, NULL);
insert into students values(1002, 'Riya', 71, 66, 54, 72, 69, NULL, NULL);
insert into students values(1003, 'Rudra', 64, 73, 71, 73, 72, NULL, NULL);
insert into students values(1004, 'Shakeel', 31, 16, 22, 41, 36, NULL, NULL);
insert into students values(1005, 'Devika', 61, 56, 62, 71, 66, NULL, NULL);
insert into students values(1006, 'Ishaan', 71, 72, 73, 71, 66, NULL, NULL);
insert into students values(1007, 'Pramita', 49, 46, 62, 51, 54, NULL, NULL);


create or replace PROCEDURE calc_total 
IS 
newTotal number;
CURSOR c1 IS (select * from students);
begin 
for c_row in c1 
loop 
    newTotal := c_row.physics + c_row.chemistry + c_row.maths + c_row.L1 + c_row.L2;
    update students set total = newTotal where stud_reg_no = c_row.stud_reg_no;
end loop;
end;
/


create or replace FUNCTION calc_stud_total 
    (stud_reg IN number)
RETURN number 
IS 
newTotal number;
begin
select physics + chemistry + maths + L1 + L2 into newTotal from students
where stud_reg_no = stud_reg;
return(newTotal);
end;
/

--Q2:

create or replace FUNCTION fibonacci
    (num IN number)
RETURN number
IS
temp number;
firstNum number := 0;
second number := 1;
i number;
begin
for i in 2..num
loop
	temp:=firstNum+second;
	firstNum := second;
	second := temp;
end loop;
return temp;
end;
/

create or replace FUNCTION fibonnaci
    (num in number)
RETURN number
IS 
fibo number:=0;
num1 number:=0;
num2 number:=1;
temp number;
begin
    temp:=num1+num2;
    for i in 2..num-1
    loop
        num1:=num2;
        num2:=temp;
        temp:=num1+num2;
    end loop;
    return temp;
end;
/

-- Q3
create or replace PROCEDURE printEmpRecords
IS
id employee.emp_num%type;
fname employee.emp_fname%type;
lname employee.emp_lname%type;
not_found_exp EXCEPTION;
cursor c1 is (select emp_num, emp_fname, emp_lname from employee);
begin
open c1;
if(c1%NOTFOUND) then
    raise not_found_exp;
end if;
loop
    fetch c1 into id,fname,lname;
    dbms_output.put_line('Emp_ID : '||id||' Emp_name : '||fname||' '||lname);
    exit when c1%NOTFOUND;
end loop; 
EXCEPTION
when not_found_exp then
    dbms_output.put_line('We did not find any data!');
end;
/

create or replace PROCEDURE checkMarks
AS
cursor c1 is (select * from students);
rec c1%rowtype;
moreMarks exception;
begin
open c1;
loop
    fetch c1 into rec;
    exit when c1%notfound;
    if rec.physics>70 then
    raise moreMarks;
    else
        dbms_output.put_line('Valid Marks');
    end if;
end loop;
close c1;
exception
when moreMarks then
dbms_output.put_line('Marks cannot be greater than 70');
end;
/