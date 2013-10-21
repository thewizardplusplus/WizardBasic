10  REM Test 3D application. Demo 2.
20
30  LET LEGS_ROTATION_SPEED = 10
40
50  DIM filename = "resources/legs.ao"
60  LET legs = LOAD_OBJECT(filename)
70  POSITION_OBJECT(legs, 0, 2.5, 0.5)
80  SCALE_OBJECT(legs, 0.25, 0.25, 0.25)
90  PLAY_OBJECT(legs, 1, 200, 1)
100
110 REM Main loop:
120 IF KEYSTATE(1) = 1 THEN 170
130     ROTATION_OBJECT(legs, 0, 0, LEGS_ROTATION_SPEED * TIMER())
140
150     SYNC()
160     GOTO 110
170
180 REM Dummy line:
190 RND()