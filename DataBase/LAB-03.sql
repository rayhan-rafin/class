CREATE:
CREATE DATABASE RAYHAN;


CREATE TABLE EMPLOYEE_TABLE(
    ID INT(10) PRIMARY KEY AUTO_INCREMENT,
    NAME VARCHAR (50),
    CITY VARCHAR (50),
    COUNTRY VARCHAR (50),
    AGE INT (10),
    SALARY INT (10),
    EXPERIENCE INT (10),
    DEPARTMENT VARCHAR (50),
    DESIGNATION VARCHAR (50)
    );

INSERT:

INSERT INTO EMPLOYEE_TABLE (NAME,CITY,COUNTRY,AGE,SALARY,EXPERIENCE,DEPARTMENT,DESIGNATION)
VALUES ('JANE','BROOKLYN','USA',25,6000,5,'CSE','LECTURER'),
('JACK','LONDON','ENGLAND',32,5000,7,'EEE','AP'),
('PENNY','YALE','CANADA',26,6000,5,'ETE','AP'),
('PAIGE','NEVADA','USA',32,3000,5,'CSE','PROF'),
('MISSY','BROOKLYN','USA',25,3000,5,'CSE','LECTURER'),
('LINDA','YORK','CANADA',24,3000,5,'CSE','AP'),
('LINDA','TOTRONTO','CANADA',26,4000,5,'EEE','AP'),
('MISSY','BERLIN','GERMANY',24,4000,5,'ETE','PROF'),
('PAIGE','HAMBURG','GERMANY',32,6000,5,'ETE','AP'),
('MISSY','BERLIN','GERMANY',41,9000,5,'CSE','PROF');

DISTINCT:
SELECT DISTINCT COUNTRY FROM EMPLOYEE_TABLE;
SELECT DISTINCT COUNTRY AS 'NEW COUNTRY' FROM EMPLOYEE_TABLE;
SELECT DISTINCT CITY AS 'NEW CITY' FROM EMPLOYEE_TABLE;

AGGREGATE FUNCTION:
SELECT MAX(SALARY) AS 'MAX_SALARY' FROM EMPLOYEE_TABLE;
SELECT MIN(SALARY) AS 'MIN_SALARY' FROM EMPLOYEE_TABLE;
SELECT AVG(SALARY) AS 'AVG_SALARY' FROM EMPLOYEE_TABLE;
SELECT SUM(SALARY) AS 'SUM_SALARY' FROM EMPLOYEE_TABLE;
SELECT COUNT(SALARY) AS 'COUNT_SALARY' FROM EMPLOYEE_TABLE;

SELECT MAX(SALARY) AS 'MAX_SALARY',MIN(SALARY) AS 'MIN_SALARY' FROM EMPLOYEE_TABLE;

SELECT COUNT(DISTINCT NAME),COUNT(DISTINCT CITY),COUNT(DISTINCT COUNTRY)FROM EMPLOYEE_TABLE;

SCALAR:

SELECT UCASE(NAME) AS 'UPPER_NAME',LCASE(NAME) AS 'LOWER_NAME' FROM EMPLOYEE_TABLE;
SELECT MID(NAME,1,2) FROM EMPLOYEE_TABLE;

OR/IN:
SELECT NAME FROM EMPLOYEE_TABLE WHERE CITY = 'BROOKLYN' OR CITY = 'BERLIN' OR CITY = 'HAMBURG';
SELECT NAME FROM EMPLOYEE_TABLE WHERE CITY IN ('BROOKLYN','BERLIN','HAMBURG');
SELECT NAME, AGE FROM EMPLOYEE_TABLE WHERE AGE IN (SELECT MIN(AGE) FROM EMPLOYEE_TABLE);
