--Q1 :
declare
first number : = 0;
second number : = 1;
temp number;
n number : = 10;
i number;

begin
    dbms_output.put_line('Series:');
dbms_output.put_line(first);
dbms_output.put_line(second);
for
    i in 2..n loop
        temp : = first + second;
first : = second;
second : = temp;
dbms_output.put_line(temp);
end loop;
end;
/

--Q2 : 
declare
sname student.name%TYPE;
m1 number;
m2 number;
m3 number;
begin
for cnt_val in (select * from student)
loop
    sname:=cnt_val.name;
    m1 : = cnt_val.DCN;
    m2 : = cnt_val.DBMS;
    m3 : = cnt_val.DSA;
    dbms_output.put_line(sname || ' Marks: ');
    if (m1 > 90)
        then
            dbms_output.put_line('DCN: S ');
    elsif(m1 > 80 and m1 < 90) then
        dbms_output.put_line('DCN:  A ');
    elsif(m1 > 70 and m1 < 80) then
        dbms_output.put_line('DCN:  B ');
    elsif(m1 > 60 and m1 < 70) then
        dbms_output.put_line('DCN:  C ');
    elsif(m1 > 50 and m1 < 60) then
        dbms_output.put_line('DCN:  D ');
    else dbms_output.put_line('DCN:  FAIL ');
    end if;
    if (m2 > 90)
        then
            dbms_output.put_line('DBMS: S ');
    elsif(m2 > 80 and m2 < 90) then
        dbms_output.put_line('DBMS:  A ');
    elsif(m2 > 70 and m2 < 80) then
        dbms_output.put_line('DBMS:  B ');
    elsif(m2 > 60 and m2 < 70) then
        dbms_output.put_line('DBMS:  C ');
    elsif(m2 > 50 and m2 < 60) then
        dbms_output.put_line('DBMS:  D ');
    else dbms_output.put_line('DBMS:  FAIL ');
    end if;
    if (m3 > 90)
        then
            dbms_output.put_line('DSA: S ');
    elsif(m3 > 80 and m3 < 90) then
        dbms_output.put_line('DSA:  A ');
    elsif(m3 > 70 and m3 < 80) then
        dbms_output.put_line('DSA:  B ');
    elsif(m3 > 60 and m3 < 70) then
        dbms_output.put_line('DSA:  C ');
    elsif(m3 > 50 and m3 < 60) then
        dbms_output.put_line('DSA:  D ');
    else dbms_output.put_line('DSA:  FAIL ');
    end if;
end loop;
end;
/

--Q3 :
declare
n number;			
i number;		
temp number;
begin
n:=&n;				
i := 2;
temp := 1;
for i in 2..n/2
loop
    if mod(n, i) = 0
	then
		temp := 0;
		exit;
	end if;
end loop;

if temp = 1
then
	dbms_output.put_line(n||' is a prime number');
else
	dbms_output.put_line(n||' is not a prime number');
end if;
end;		
/

--Q4 :
declare
sname student.name%TYPE;
m1 number;
m2 number;
m3 number;
begin
for cnt_val in (select * from student)
dbms_output.put_line('Name | DCN | DBMS | DSA')
loop
    sname:=cnt_val.name;
    m1 : = cnt_val.DCN;
    m2 : = cnt_val.DBMS;
    m3 : = cnt_val.DSA;
    dbms_output.put_line(sname||' '||m1||' '||m2||' '||m3||' '||);
end loop;
end;
/