10  REM Test sound application.
20
30  LET PI = 3.14
40  LET USE_LISTENER = 1
50  LET RADIUS = 2
60  LET SPEED = 0.001
70
80  IF USE_LISTENER = 0 THEN 100
90      POSITION_LISTENER(0, RADIUS, 0)
100
110 DIM wind_filename = "data/wind.wav"
120 LET wind = LOAD_SOUND(wind_filename)
130 PLAY_SOUND(wind, 1)
140
150 DIM fire_filename = "data/fire.wav"
160 LET fire = LOAD_SOUND(fire_filename)
170 PLAY_SOUND(fire, 1)
180
190 LET time = 0
200 REM Loop:
210     LET x = RADIUS * COS(SPEED * time)
220     LET y = RADIUS * SIN(SPEED * time)
230     IF USE_LISTENER = 1 THEN 260
240        	POSITION_SOUND(fire, x, y, 0)
250         GOTO 280
260         LET angle = SPEED * time * 180 / PI
270         ROTATION_LISTENER(0, 0, angle)
280
290     LET time = time + 1
300     GOTO 200
