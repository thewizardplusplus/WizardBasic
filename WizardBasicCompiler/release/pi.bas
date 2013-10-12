10 REM PI
20
30 DIM MESSAGE_BEGIN = "Pi = "
40 DIM MESSAGE_END = ".\n"
50 LET ERROR = 0.000001
60
70 LET a = 1
80 LET b = 1 / SQR(2)
90 LET t = 1 / 4
100 LET p = 1
110
120 LET new_a = (a + b) / 2
130 LET new_b = SQR(a * b)
140 LET new_t = t - p * (a - new_a) * (a - new_a)
150 LET new_p = 2 * p
160
170 LET a = new_a
180 LET b = new_b
190 LET t = new_t
200 LET p = new_p
210 IF ABS(a - b) > ERROR THEN 120
220
230 LET pi = (a + b) * (a + b) / (4 * t)
240 TRACES(MESSAGE_BEGIN)
250 TRACEN(pi)
260 TRACES(MESSAGE_END)