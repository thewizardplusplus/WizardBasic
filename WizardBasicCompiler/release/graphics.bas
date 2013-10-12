10  REM Test 3D application.
20
30  DIM filename = "test.ao"
40  LET object = OBJLD(filename)
50  OBJPOS(object, 0.0, 2.5, 0.0)
60  OBJROT(object, 0.0, 0.0, 90.0)
70  OBJPL(object, 1, 100, 1)
80
90  REM Main loop:
100 IF ISKEY(1) = 1 THEN 130
110     UPDATE()
120     GOTO 100
130
140 REM Dummy line:
150 RND()