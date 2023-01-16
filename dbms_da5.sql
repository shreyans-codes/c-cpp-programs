CREATE TABLE STUDENT (
    S_REG_NO NUMBER NOT NULL,
    NAME VARCHAR2(30),
    PHYSICS NUMBER,
    CHEMISTRY NUMBER,
    MATHS NUMBER,
    L1 NUMBER,
    L2 NUMBER,
    TOTAL NUMBER,
    CLASS VARCHAR2(20)
);

insert into STUDENT values(1, 'Max', 56, 62, 65, 71, 68, NULL, NULL);
insert into STUDENT values(2, 'Kumar', 74, 72, 75, 71, 68, NULL, NULL);

create or replace FUNCTION calcTotal
    (s_reg IN NUMBER)
RETURN NUMBER
IS
newTotal NUMBER;
BEGIN
select physics+CHEMISTRY+maths+l1+l2 into newTotal from STUDENT where s_reg_no = s_reg;
return newTotal;
end;
/

create or replace PROCEDURE classify_Studs
IS
c_val STUDENT.CLASS%TYPE;
CURSOR c1 is (select * from student);
BEGIN
    for c_row in c1
    LOOP
        c_row.TOTAL := calcTotal(c_row.s_reg_no);
        if(C_ROW.TOTAL > 300) then
            c_val:='PASS';
        ELSE
            C_VAL:='FAIL';
        end if;
        update student set class = c_val where S_REG_NO = c_row.s_reg_no;
        update student set total = c_row.total where S_REG_NO = C_ROW.S_REG_NO;
    end loop;
end;
/

CREATE TABLE STUDENTS_AUDIT (
    s_reg_no NUMBER,
    OPERATION varchar2(20),
    op_date DATE,
    BY_USER VARCHAR2(100),
    NAME VARCHAR2(30),
    PHYSICS NUMBER,
    CHEMISTRY NUMBER,
    MATHS NUMBER,
    L1 NUMBER,
    L2 NUMBER,
    TOTAL NUMBER,
    CLASS VARCHAR2(20)
);

create or replace trigger students_bef_dml_ops
before insert or update or delete on STUDENT
for each row
BEGIN
    if inserting then
        insert into STUDENTS_AUDIT values(:new.S_REG_NO, 'Inserting', SYSDATE(), 'ADMIN', :new.NAME, :new.physics, :NEW.CHEMISTRY, :NEW.MATHS, 
        :NEW.L1, :NEW.L2, :NEW.total, :NEW.class);
    elsif updating then
        insert into STUDENTS_AUDIT values(:old.S_REG_NO, 'Updating', SYSDATE(), 'ADMIN', :old.NAME, :old.physics, :old.CHEMISTRY, :old.MATHS, 
        :old.L1, :old.L2, :old.total, :old.class);
    ELSE
        insert into STUDENTS_AUDIT values(:old.S_REG_NO, 'Deleting', SYSDATE(), 'ADMIN', :old.NAME, :old.physics, :old.CHEMISTRY, :old.MATHS, 
        :old.L1, :old.L2, :old.total, :old.class);
    end if;
end;
/

insert into STUDENT values(3, 'Kirti', 74, 72, 75, 71, 68, NULL, NULL);
