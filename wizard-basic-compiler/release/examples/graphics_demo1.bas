10  REM Test 3D application. Demo 1.
20
21  LET PLAYER_ROTATE_SPEED =    0.25
22  LET PLAYER_MOVE_SPEED =      0.05
23  LET PLAYER_POSITION_Z =      2.5
24  LET SCENE_RADIUS_IN_SQUARE = 5 * 5
25
30  FOG(1)
31  FOG_COLOR(0, 0, 0)
32  FOG_DEPTH(5)
40
50  DIM filename = "resources/plateau.ao"
60  LOAD_OBJECT(filename)
70
80  LET camera_angle_x = 0
81  LET camera_angle_z = 0
82  LET camera_position_x = 0
83  LET camera_position_y = 0
84  REM Main loop:
90  IF KEYSTATE(1) = 1 THEN 140
91      REM rotating camera:
92      LET center_x = SCREEN_WIDTH() / 2
93      LET center_y = SCREEN_HEIGHT() / 2
94      LET new_position_x = MOUSEX()
95      LET new_position_y = MOUSEY()
96      POSITION_MOUSE(center_x, center_y)
97      LET camera_angle_x = camera_angle_x + PLAYER_ROTATE_SPEED * (new_position_y - center_y)
98      LET camera_angle_z = camera_angle_z + PLAYER_ROTATE_SPEED * (new_position_x - center_x)
99      IF camera_angle_x < 90 THEN 101
100         LET camera_angle_x = 90
101     IF camera_angle_x > 0 - 90 THEN 103
102         LET camera_angle_x = 0 - 90
103     ROTATION_CAMERA(camera_angle_x, 0, camera_angle_z)
104
105     REM moving camera:
106     LET direction_x = 0
107     LET direction_y = 0
108     IF KEYSTATE(63) = 0 THEN 112
109         LET direction_x = direction_x + COS((camera_angle_z - 90) * 3.14 / 180)
110         LET direction_y = direction_y + SIN((camera_angle_z - 90) * 3.14 / 180)
111         GOTO 115
112     IF KEYSTATE(59) = 0 THEN 115
113         LET direction_x = direction_x - COS((camera_angle_z - 90) * 3.14 / 180)
114         LET direction_y = direction_y - SIN((camera_angle_z - 90) * 3.14 / 180)
115     IF KEYSTATE(41) = 0 THEN 119
116         LET direction_x = direction_x - COS(camera_angle_z * 3.14 / 180)
117         LET direction_y = direction_y - SIN(camera_angle_z * 3.14 / 180)
118         GOTO 122
119     IF KEYSTATE(44) = 0 THEN 122
120         LET direction_x = direction_x + COS(camera_angle_z * 3.14 / 180)
121         LET direction_y = direction_y + SIN(camera_angle_z * 3.14 / 180)
122     LET direction_length = SQR(direction_x * direction_x + direction_y * direction_y)
123     IF direction_length = 0 THEN 126
124         LET direction_x = direction_x / direction_length
125         LET direction_y = direction_y / direction_length
126     LET new_camera_position_x = camera_position_x + PLAYER_MOVE_SPEED * direction_x
127     LET new_camera_position_y = camera_position_y + PLAYER_MOVE_SPEED * direction_y
128     IF new_camera_position_x * new_camera_position_x + camera_position_y * camera_position_y < SCENE_RADIUS_IN_SQUARE THEN 130
129         LET new_camera_position_x = camera_position_x
130     IF camera_position_x * camera_position_x + new_camera_position_y * new_camera_position_y < SCENE_RADIUS_IN_SQUARE THEN 132
131         LET new_camera_position_y = camera_position_y
132     LET camera_position_x = new_camera_position_x
133     LET camera_position_y = new_camera_position_y
134     POSITION_CAMERA(camera_position_x, camera_position_y, PLAYER_POSITION_Z)
135
136     SYNC()
137     GOTO 90
140
141 REM Dummy line:
142 RND()