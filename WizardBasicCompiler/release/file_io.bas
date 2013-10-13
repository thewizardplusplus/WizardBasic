10  REM File input-output.
20
30  DIM filename1 = "test.txt"
40  DIM filename2 = "new.txt"
50
60  LET file1 = OPEN(filename1, 0)
70  LET file2 = OPEN(filename2, 1)
80  REM Read loop:
90      LET symbol = INPUT(file1)
100     IF symbol = 0 - 1 THEN 140
110
120     PRINTNF(file2, symbol)
130     GOTO 80
140
150 CLOSE(file1)
160 CLOSE(file2)
170
180 DIM test_string = "Test!"
190 LET file3 = OPEN(filename2, 2)
200 PRINTSF(file3, test_string)
210 CLOSE(file3)