10  REM Test 3D application. Demo 0.
20
30  DIM filename = "data/gate.ao"
40  LET gate = LOAD_OBJECT(filename)
50  POSITION_OBJECT(gate, 0, 2.5, 0)
60  ROTATION_OBJECT(gate, 90, 0, 0)
70  PLAY_OBJECT(gate, 1, 100, 1)
80
90  REM Main loop:
100 IF KEYSTATE(1) = 1 THEN 130
110     SYNC()
120     GOTO 100
130
140 REM Dummy line:
150 RND()
