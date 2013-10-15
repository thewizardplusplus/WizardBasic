10  REM Test 3D application.
20
30  DIM filename = "resources\\test.ao"
40  LET object = LOAD_OBJECT(filename)
50  POSITION_OBJECT(object, 0.0, 2.5, 0.0)
60  ROTATION_OBJECT(object, 0.0, 0.0, 90.0)
70  PLAY_OBJECT(object, 1, 100, 1)
80
90  REM Main loop:
100 IF KEYSTATE(1) = 1 THEN 130
110     SYNC()
120     GOTO 100
130
140 REM Dummy line:
150 RND()